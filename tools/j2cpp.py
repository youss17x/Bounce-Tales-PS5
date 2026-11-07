# Translates the decompiled Bounce Tales Java source (javac-verified) into C++.
# Supports exactly the Java subset this game uses; runtime support lives in jrt.hpp.
import javalang, glob, os, sys, re
from javalang import tree as T


# javalang drops the operators and selectors inside a parenthesised primary, e.g.
# "(byte)(-this.a[i])". Wrap parenthesised primaries in their own node instead.
import javalang.parser as _jp
from javalang.tokenizer import Operator as _Op
class Paren(T.Primary):
    attrs = ('expression',)
_orig_e3 = _jp.Parser.parse_expression_3
def _e3(self):
    prefix_operators = list()
    while self.tokens.look().value in _Op.PREFIX:
        prefix_operators.append(self.tokens.next().value)
    if self.would_accept('('):
        try:
            with self.tokens:
                self.accept('(')
                cast_target = self.parse_type()
                self.accept(')')
                expression = self.parse_expression_3()
                c = T.Cast(type=cast_target, expression=expression)
                if prefix_operators:
                    w = Paren(expression=c); w.prefix_operators = prefix_operators; w.selectors = []; w.postfix_operators = []
                    return w
                return c
        except _jp.JavaSyntaxError:
            pass
    paren = self.would_accept('(')
    primary = self.parse_primary()
    if paren:
        primary = Paren(expression=primary)
    primary.prefix_operators = prefix_operators
    primary.selectors = list()
    primary.postfix_operators = list()
    token = self.tokens.look()
    while token.value in '[.':
        selector = self.parse_selector()
        primary.selectors.append(selector)
        token = self.tokens.look()
    while token.value in _Op.POSTFIX:
        primary.postfix_operators.append(self.tokens.next().value)
        token = self.tokens.look()
    return primary
_jp.Parser.parse_expression_3 = _e3

# javalang forgets "default" when it shares a group with case labels.
def _sbsg(self):
    labels = list(); statements = list()
    while True:
        case_type = self.tokens.next().value
        if case_type == 'case':
            labels.append(self.parse_expression())
        elif case_type == 'default':
            labels.append('default')
        else:
            self.illegal("Expected switch case")
        self.accept(':')
        if self.tokens.look().value not in ('case', 'default'):
            break
    while self.tokens.look().value not in ('case', 'default', '}'):
        statements.append(self.parse_block_statement())
    return T.SwitchStatementCase(case=labels, statements=statements)
_jp.Parser.parse_switch_block_statement_group = _sbsg

SRC, OUT = sys.argv[1], sys.argv[2]
PRIM = {'int': 'int32_t', 'byte': 'int8_t', 'short': 'int16_t', 'char': 'char16_t', 'long': 'int64_t',
        'float': 'float', 'double': 'double', 'boolean': 'bool', 'void': 'void'}
NUMRANK = {'byte': 1, 'short': 2, 'char': 2, 'int': 3, 'long': 4, 'float': 5, 'double': 6}
VALUE_REFS = {'String'}  # handled with '.' access

# Port changes to the game, applied to the source before translation.
PATCHES = {
    # Widescreen: book pages (instructions, high scores, chapter texts) keep the page's
    # 240-pixel text width and sit on the centred page instead of spanning the screen.
    'm.java': [('this.b_h.b_ii_v(11, o.b_i - (u_i << 1) + 4);', 'this.b_h.b_ii_v(11, Math.min(o.b_i, 240) - (u_i << 1) + 4);'),
               ('this.b_h.b_ii_v(9, u_i - 2);', 'this.b_h.b_ii_v(9, (o.b_i - Math.min(o.b_i, 240) >> 1) + u_i - 2);')],
}
classes = {}
for f in sorted(glob.glob(os.path.join(SRC, '*.java'))):
    text = open(f, encoding='utf-8').read()
    for old, new in PATCHES.get(os.path.basename(f), []):
        if old not in text: raise Exception('patch does not apply: ' + old)
        text = text.replace(old, new)
    cu = javalang.parse.parse(text)
    for c in cu.types:
        classes[c.name] = c

def tstr(t):
    if t is None: return 'void'
    dims = len(t.dimensions or [])
    n = t.name
    if isinstance(t, T.ReferenceType) and t.sub_type: n = t.sub_type.name
    return n + '[]' * dims

def is_arr(t): return t.endswith('[]')
def elem(t): return t[:-2]
def is_game(t): return t in classes
def is_prim(t): return t in PRIM and t != 'void'
def is_num(t): return t in NUMRANK

def ct(t):
    if is_arr(t): return 'Arr<%s>' % ct(elem(t))
    if t in PRIM: return PRIM[t]
    if is_game(t): return t + '*'
    if t == 'Object': return 'Obj'
    return 'J' + t  # library handle types (JString, JVector, JImage, ...)

# ---------- class table ----------
info = {}
for name, c in classes.items():
    sup = c.extends.name if c.extends else None
    fields, methods, ctors, clinit = {}, {}, [], []
    for m in c.body:
        if isinstance(m, T.FieldDeclaration):
            for d in m.declarators:
                fields[d.name] = dict(type=tstr(m.type) + '[]' * len(d.dimensions or []), static='static' in m.modifiers,
                                      init=d.initializer, mods=m.modifiers)
        elif isinstance(m, T.MethodDeclaration):
            methods.setdefault(m.name, []).append(m)
        elif isinstance(m, T.ConstructorDeclaration):
            ctors.append(m)
        elif isinstance(m, list) or isinstance(m, T.BlockStatement) or type(m).__name__ == 'list':
            clinit.append(m)
        else:
            # javalang represents static initializers as a list of statements in body
            clinit.append(m)
    info[name] = dict(sup=sup, fields=fields, methods=methods, ctors=ctors, clinit=clinit, node=c)

def chain(c):
    while c in info:
        yield c
        c = info[c]['sup']

LIB_SUPER = {'o': 'GameCanvas', 'RMIDlet': 'MIDlet'}

def find_field(c, name):
    for k in chain(c):
        if name in info[k]['fields']: return k, info[k]['fields'][name]
    return None, None

def find_method(c, name):
    for k in chain(c):
        if name in info[k]['methods']: return k, info[k]['methods'][name]
    return None, None

LIB_FIELDS = {('Integer', 'MAX_VALUE'): 'int', ('Integer', 'MIN_VALUE'): 'int', ('Long', 'MAX_VALUE'): 'long', ('System', 'out'): 'PrintStream'}
LIB_RET = {
    'String': dict(length='int', charAt='char', substring='String', indexOf='int', lastIndexOf='int', equals='boolean',
                   trim='String', startsWith='boolean', endsWith='boolean', toCharArray='char[]', toString='String',
                   getBytes='byte[]', toUpperCase='String', toLowerCase='String', hashCode='int', valueOf='String', concat='String'),
    'StringBuffer': dict(append='StringBuffer', toString='String', length='int', delete='StringBuffer', insert='StringBuffer',
                         setLength='void', charAt='char', deleteCharAt='StringBuffer', setCharAt='void'),
    'Vector': dict(size='int', elementAt='Object', addElement='void', removeElement='boolean', removeAllElements='void',
                   insertElementAt='void', isEmpty='boolean', removeElementAt='void', contains='boolean', indexOf='int',
                   setElementAt='void', firstElement='Object', lastElement='Object', copyInto='void'),
    'Image': dict(getWidth='int', getHeight='int', getGraphics='Graphics', getRGB='void', createImage='Image', createRGBImage='Image', isMutable='boolean'),
    'Graphics': dict(getClipX='int', getClipY='int', getClipWidth='int', getClipHeight='int', getColor='int', getFont='Font',
                     getTranslateX='int', getTranslateY='int'),
    'DirectGraphics': dict(getAlphaComponent='int', getNativePixelFormat='int'),
    'DirectUtils': dict(getDirectGraphics='DirectGraphics', createImage='Image'),
    'Font': dict(getFont='Font', getHeight='int', stringWidth='int', charWidth='int', substringWidth='int',
                 getBaselinePosition='int', charsWidth='int', getDefaultFont='Font', getSize='int', getStyle='int', getFace='int'),
    'DataInputStream': dict(readShort='short', readInt='int', readByte='byte', readUTF='String', readUnsignedByte='int',
                            read='int', skipBytes='int', readBoolean='boolean', readLong='long', readChar='char',
                            readUnsignedShort='int', available='int', skip='long'),
    'InputStream': dict(read='int', skip='long', available='int'),
    'ByteArrayOutputStream': dict(toByteArray='byte[]', size='int'),
    'RecordStore': dict(openRecordStore='RecordStore', getNumRecords='int', getRecord='byte[]', addRecord='int'),
    'Player': dict(getState='int', getControl='VolumeControl', setLoopCount='void', getMediaTime='long', getDuration='long'),
    'Manager': dict(createPlayer='Player', playTone='void'),
    'VolumeControl': dict(setLevel='int', getLevel='int'),
    'Display': dict(getDisplay='Display', vibrate='boolean', flashBacklight='boolean', getCurrent='GameCanvas'),
    'MIDlet': dict(getAppProperty='String', platformRequest='boolean'),
    'GameCanvas': dict(getGraphics='Graphics', getWidth='int', getHeight='int', getKeyStates='int', isShown='boolean',
                       getGameAction='int', hasPointerEvents='boolean'),
    'Random': dict(nextInt='int', nextLong='long'),
    'Integer': dict(parseInt='int', toString='String', valueOf='Integer', intValue='int'),
    'System': dict(currentTimeMillis='long', getProperty='String', arraycopy='void', gc='void', exit='void'),
    'Thread': dict(sleep='void', start='void', currentThread='Thread', yield_='void'),
    'Object': dict(getClass='Class', hashCode='int', equals='boolean', toString='String', wait='void', notify='void', notifyAll='void'),
    'Class': dict(getResourceAsStream='InputStream', getName='String'),
    'Float': dict(intBitsToFloat='float', floatToIntBits='int'),
    'Command': dict(getLabel='String', getCommandType='int'),
}
LIB_INHERIT = {'DataInputStream': 'InputStream', 'ByteArrayInputStream': 'InputStream', 'GameCanvas': 'Object'}

def lib_ret(t, name, argtypes):
    if t in ('Math',):
        if name in ('abs', 'max', 'min'):
            return binary_numeric(*argtypes) if len(argtypes) == 2 else unary_numeric(argtypes[0])
        return 'double'
    if t in classes:
        for k in chain(t): pass
        t2 = LIB_SUPER.get(k)
        if t2: return lib_ret(t2, name, argtypes)
    tt = t
    while tt:
        if tt in LIB_RET and name in LIB_RET[tt]: return LIB_RET[tt][name]
        tt = LIB_INHERIT.get(tt, 'Object' if tt != 'Object' else None)
    return 'void'

def unary_numeric(t):
    return 'int' if NUMRANK.get(t, 3) < 3 else t

def binary_numeric(a, b):
    ra, rb = NUMRANK.get(a, 3), NUMRANK.get(b, 3)
    r = max(ra, rb, 3)
    return {3: 'int', 4: 'long', 5: 'float', 6: 'double'}[r]

LIB_CLASSES = set(LIB_RET) | {'Math', 'ByteArrayInputStream', 'DataOutputStream', 'DeviceControl', 'Long', 'Character', 'Exception',
                              'IOException', 'RecordStoreException', 'Throwable', 'InterruptedException', 'IllegalArgumentException',
                              'RuntimeException', 'Runnable', 'Canvas'}

# ---------- emitter ----------
class Ctx:
    def __init__(s, cls, static):
        s.cls = cls; s.static = static; s.scopes = [{}]; s.labels = {}; s.lblcount = 0; s.ret = None
    def push(s): s.scopes.append({})
    def pop(s): s.scopes.pop()
    def declare(s, n, t): s.scopes[-1][n] = t
    def lookup(s, n):
        for sc in reversed(s.scopes):
            if n in sc: return sc[n]
        return None

def L(n): return 'L_' + n

def lit(node):
    v = node.value
    if v in ('true', 'false'): return v, 'boolean'
    if v == 'null': return 'nullptr', 'null'
    if v.startswith('"'):
        return 'JS(u%s)' % cpp_str(v), 'String'
    if v.startswith("'"):
        return "char16_t(u%s)" % cpp_char(v), 'char'
    lv = v.lower()
    if lv.endswith('l'):
        return '(int64_t)%sLL' % v[:-1], 'long'
    if lv.endswith('f') and not lv.startswith('0x'):
        x = v[:-1]
        if '.' not in x and 'e' not in x.lower(): x += '.0'
        return x + 'f', 'float'
    if lv.endswith('d') and not lv.startswith('0x'):
        return v[:-1], 'double'
    if '.' in v or ('e' in lv and not lv.startswith('0x')):
        return v, 'double'
    if lv.startswith('0x') and len(v) > 2:
        val = int(v, 16)
        if val > 0x7fffffff: return '(int32_t)%sU' % v, 'int'
        return v, 'int'
    if len(v) > 1 and v.startswith('0') and v.isdigit():
        return str(int(v, 8)), 'int'
    if v == '2147483648': return '(int32_t)0x80000000U', 'int'
    return v, 'int'

def cpp_str(v):
    body = v[1:-1]
    out = ''
    i = 0
    while i < len(body):
        ch = body[i]
        if ch == '\\':
            n = body[i + 1]
            if n == 'u':
                out += '\\x%s""' % body[i + 2:i + 6] if False else '\\u' + body[i + 2:i + 6]; i += 6; continue
            out += '\\' + n; i += 2; continue
        out += ch; i += 1
    return '"' + out + '"'

def cpp_char(v):
    body = v[1:-1]
    if body.startswith('\\u'): return "'\\u%s'" % body[2:]
    return "'" + body + "'"

def has_se(n):
    if n is None or isinstance(n, str): return False
    if isinstance(n, list): return any(has_se(x) for x in n)
    if isinstance(n, (T.Assignment, T.MethodInvocation, T.SuperMethodInvocation, T.ClassCreator)): return True
    for op in (getattr(n, 'prefix_operators', None) or []) + (getattr(n, 'postfix_operators', None) or []):
        if op in ('++', '--'): return True
    if isinstance(n, javalang.ast.Node):
        for a in n.attrs:
            v = getattr(n, a, None)
            if isinstance(v, (javalang.ast.Node, list)) and has_se(v): return True
    return False

def is_const(n):
    while isinstance(n, Paren): n = n.expression
    return isinstance(n, T.Literal)

def plain_name(n):
    return isinstance(n, T.MemberReference) and not (n.selectors or []) and not (n.prefix_operators or []) and not (n.postfix_operators or [])

SEQ = [0]
def seqname(p):
    SEQ[0] += 1
    return '__%s%d' % (p, SEQ[0])

def needs_arg_seq(nodes):
    if not any(has_se(x) for x in nodes): return False
    return sum(1 for x in nodes if not is_const(x)) >= 2

class Em:
    def __init__(s, cls):
        s.cls = cls

    # ----- expressions -----
    def expr(s, e, cx, want=None):
        code, t = s.expr0(e, cx)
        code, t = s.apply_selectors(code, t, getattr(e, 'selectors', None) or [], cx, e)
        post = getattr(e, 'postfix_operators', None) or []
        for p in post: code = '(%s%s)' % (code, p)
        pre = getattr(e, 'prefix_operators', None) or []
        for p in reversed(pre):
            if p in ('-', '~') and t in ('byte', 'short', 'char'): t = 'int'
            if p in ('++', '--'):
                code = '(%s%s)' % (p, code)
            else:
                code = '(%s%s)' % (p, code)
                if p in ('-', '~'): t = unary_numeric(t)
        return code, t

    def apply_selectors(s, code, t, sels, cx, e):
        for sel in sels:
            if isinstance(sel, T.ArraySelector):
                ic, it = s.expr(sel.index, cx)
                code = '%s[%s]' % (code, ic); t = elem(t)
            elif isinstance(sel, T.MemberReference):
                code, t = s.member_of(code, t, sel.member, cx)
            elif isinstance(sel, T.MethodInvocation):
                code, t = s.call_on(code, t, sel, cx)
                code, t = s.apply_selectors(code, t, sel.selectors or [], cx, sel)
            else:
                raise Exception('selector %r' % sel)
        return code, t

    def member_of(s, code, t, name, cx):
        if is_arr(t) and name == 'length': return '%s.length()' % code, 'int'
        if is_game(t):
            k, f = find_field(t, name)
            if f is None: raise Exception('no field %s.%s' % (t, name))
            if f['static']: return s.static_field(k, name, cx), f['type']
            return '%s->%s' % (code, name), f['type']
        raise Exception('member %s of %s' % (name, t))

    def static_field(s, k, name, cx):
        if k == cx.cls or k in chain(cx.cls) and False:
            return '%s::%s' % (k, name)
        if k in chain(cx.cls): return '%s::%s' % (k, name)
        return '(%s::__ci(),%s::%s)' % (k, k, name)

    def name_ref(s, n, cx):
        t = cx.lookup(n)
        if t: return L(n), t
        k, f = find_field(cx.cls, n)
        if f:
            if f['static']: return s.static_field(k, n, cx), f['type']
            return 'this->' + n, f['type']
        if n in classes or n in LIB_CLASSES: return None, '#class:' + n
        raise Exception('unknown name %s in %s' % (n, cx.cls))

    def qualified(s, q, cx):
        parts = q.split('.')
        code, t = s.name_ref(parts[0], cx)
        for p in parts[1:]:
            if t.startswith('#class:'):
                cn = t[7:]
                if cn in classes:
                    k, f = find_field(cn, p)
                    if f is None: raise Exception('no static %s.%s' % (cn, p))
                    code, t = s.static_field(k, p, cx), f['type']
                elif (cn, p) in LIB_FIELDS:
                    code, t = 'J_%s_%s' % (cn, p), LIB_FIELDS[(cn, p)]
                else:
                    raise Exception('lib field %s.%s' % (cn, p))
            else:
                code, t = s.member_of(code, t, p, cx)
        return code, t

    def expr0(s, e, cx):
        if isinstance(e, Paren):
            c, t = s.expr(e.expression, cx)
            return '(%s)' % c, t
        if isinstance(e, T.Literal): return lit(e)
        if isinstance(e, T.This):
            return 'this', cx.cls
        if isinstance(e, T.MemberReference):
            if e.qualifier:
                qc, qt = s.qualified(e.qualifier, cx)
                if qt.startswith('#class:'):
                    cn = qt[7:]
                    if cn in classes:
                        k, f = find_field(cn, e.member)
                        return s.static_field(k, e.member, cx), f['type']
                    if (cn, e.member) in LIB_FIELDS: return 'J_%s_%s' % (cn, e.member), LIB_FIELDS[(cn, e.member)]
                    raise Exception('lib static field %s.%s' % (cn, e.member))
                return s.member_of(qc, qt, e.member, cx)
            c, t = s.name_ref(e.member, cx)
            if t.startswith('#class:'): raise Exception('bare class ref ' + e.member)
            return c, t
        if isinstance(e, T.MethodInvocation):
            return s.invoke(e, cx)
        if isinstance(e, T.SuperMethodInvocation):
            args, decls = s.eval_args(e.arguments, cx)
            return s.wrapc(s.supercall(e, cx, args), decls)
        return s.expr2(e, cx)

    def supercall(s, e, cx, args):
        if True:
            sup = info[cx.cls]['sup']
            if sup not in info:
                return 'this->%s(%s)' % (e.member, ', '.join(c for c, _ in args)), lib_ret(cx.cls, e.member, [t for _, t in args])
            k, ms = find_method(sup, e.member)
            m = s.pick(ms, args)
            return '%s::%s(%s)' % (k, e.member, s.args(m, args)), tstr(m.return_type)

    def expr2(s, e, cx):
        if isinstance(e, T.Assignment):
            lc, lt = s.expr(e.expressionl, cx)
            rc, rt = s.expr(e.value, cx)
            op = e.type
            if not plain_name(e.expressionl) and (has_se(e.expressionl) or has_se(e.value)):
                ln, rn = seqname('a'), seqname('v')
                inner, it = s.assign_code(op, ln, lt, rn, rt)
                return '([&]() -> decltype(auto) { auto& %s = %s; auto %s = %s; return %s; }())' % (ln, lc, rn, rc, inner), it
            return s.assign_code(op, lc, lt, rc, rt)
        return s.expr1(e, cx)

    def assign_code(s, op, lc, lt, rc, rt):
        if True:
            if op == '>>>=':
                return '(%s = %s)' % (lc, s.shift('>>>', lc, lt, rc)), lt
            if op in ('<<=', '>>='):
                return '(%s = %s)' % (lc, s.shift(op[:-1], lc, lt, rc)), lt
            if op == '=':
                return '(%s = %s)' % (lc, s.conv(rc, rt, lt)), lt
            if op in ('+=',) and lt == 'String':
                return '(%s = jcat(%s,%s))' % (lc, lc, rc), lt
            if op in ('/=', '%=') and lt in ('int', 'long', 'short', 'byte', 'char'):
                fn = 'jdiv' if op == '/=' else 'jrem'
                return '(%s = (%s)%s(%s,%s))' % (lc, ct(lt), fn, lc, rc), lt
            if lt in ('byte', 'short', 'char') or (lt in ('int', 'long') and rt in ('float', 'double')):
                return '(%s = (%s)(%s %s %s))' % (lc, ct(lt), lc, op[:-1], rc), lt
            return '(%s %s %s)' % (lc, op, rc), lt

    def expr1(s, e, cx):
        if isinstance(e, T.BinaryOperation):
            return s.binop(e, cx)
        if isinstance(e, T.Cast):
            tt = tstr(e.type)
            c, t = s.expr(e.expression, cx)
            return s.cast(c, t, tt), tt
        if isinstance(e, T.TernaryExpression):
            cc, _ = s.expr(e.condition, cx)
            a, at = s.expr(e.if_true, cx)
            b, bt = s.expr(e.if_false, cx)
            if at == 'null': rt = bt
            elif bt == 'null': rt = at
            elif is_num(at) and is_num(bt) and at != bt: rt = binary_numeric(at, bt)
            else: rt = at
            return '(%s ? %s : %s)' % (cc, s.conv(a, at, rt, force=True), s.conv(b, bt, rt, force=True)), rt
        if isinstance(e, T.ClassCreator):
            tn = e.type.name
            args, decls = s.eval_args(e.arguments, cx)
            return s.wrapc(s.creator(e, cx, tn, args), decls)
        return s.expr3(e, cx)

    def creator(s, e, cx, tn, args):
        if True:
            if tn in classes:
                ctors = info[tn]['ctors']
                if ctors:
                    m = s.pick(ctors, args); a = s.args(m, args)
                else: a = ''
                return '(%s::__ci(), new %s(%s))' % (tn, tn, a), tn
            return 'J%s::make(%s)' % (tn, ', '.join(s.conv(c, t, None) for c, t in args)), tn

    def expr3(s, e, cx):
        if isinstance(e, T.ArrayCreator):
            tn = tstr(e.type)
            dims = e.dimensions
            if e.initializer:
                full = tn + '[]' * len(dims)
                return s.array_init(e.initializer, full, cx), full
            full = tn + '[]' * len(dims)
            sizes = [s.expr(d, cx)[0] for d in dims if d is not None]
            return 'newArr<%s>(%s)' % (ct(elem(full)) if len(sizes) == 1 else ct(elem(full)), ', '.join(sizes)) if len(sizes) == 1 else \
                   'newArr%d<%s>(%s)' % (len(sizes), s.base_ct(full), ', '.join(sizes)), full
        if isinstance(e, T.ArrayInitializer):
            raise Exception('bare array initializer')
        raise Exception('expr %s' % type(e).__name__)

    def base_ct(s, full):
        t = full
        while is_arr(t): t = elem(t)
        n = full.count('[]')
        return ct(t) if True else None

    def array_init(s, init, full, cx):
        et = elem(full)
        items = []
        for it in init.initializers:
            if isinstance(it, T.ArrayInitializer): items.append(s.array_init(it, et, cx))
            else:
                c, t = s.expr(it, cx); items.append(s.conv(c, t, et, force=True))
        return 'Arr<%s>({%s})' % (ct(et), ', '.join(items))

    def shift(s, op, lc, lt, rc):
        lt2 = unary_numeric(lt)
        fn = {'<<': 'jshl', '>>': 'jshr', '>>>': 'jushr'}[op]
        return '%s(%s(%s),%s)' % (fn, ct(lt2), lc, rc)

    def eval_args(s, nodes, cx):
        args = [s.expr(a, cx) for a in nodes]
        if needs_arg_seq(nodes):
            decls, new = [], []
            for c, t in args:
                n = seqname('p'); decls.append('auto %s = %s;' % (n, c)); new.append((n, t))
            return new, decls
        return args, []

    def wrapc(s, res, decls):
        if not decls: return res
        code, t = res
        return '([&]() -> decltype(auto) { %s return %s; }())' % (' '.join(decls), code), t

    def binop(s, e, cx):
        op = e.operator
        lc, lt = s.expr(e.operandl, cx)
        rc, rt = s.expr(e.operandr, cx)
        if op not in ('&&', '||') and ((has_se(e.operandl) and not is_const(e.operandr)) or (has_se(e.operandr) and not is_const(e.operandl))):
            ln, rn = seqname('l'), seqname('r')
            code, t = s.binop_code(op, ln, lt, rn, rt)
            return '([&]() { auto %s = %s; auto %s = %s; return %s; }())' % (ln, lc, rn, rc, code), t
        return s.binop_code(op, lc, lt, rc, rt)

    def binop_code(s, op, lc, lt, rc, rt):
        if op == 'instanceof':
            raise Exception('instanceof')
        if op in ('<<', '>>', '>>>'):
            return s.shift(op, lc, lt, rc), unary_numeric(lt)
        if op == '+' and (lt == 'String' or rt == 'String'):
            return 'jcat(%s,%s)' % (s.strarg(lc, lt), s.strarg(rc, rt)), 'String'
        if op in ('==', '!=', '<', '>', '<=', '>=', '&&', '||'):
            if op in ('==', '!=') and (lt == 'Object' or rt == 'Object'):
                return '(%sjsame(%s,%s))' % ('!' if op == '!=' else '', lc, rc), 'boolean'
            return '(%s %s %s)' % (lc, op, rc), 'boolean'
        if op in ('&', '|', '^') and lt == 'boolean':
            return '(bool)(%s %s %s)' % (lc, op, rc), 'boolean'
        rt2 = binary_numeric(lt, rt)
        if op in ('/', '%') and rt2 in ('int', 'long'):
            return '%s(%s(%s),%s(%s))' % ('jdiv' if op == '/' else 'jrem', ct(rt2), lc, ct(rt2), rc), rt2
        if op == '%' and rt2 in ('float', 'double'):
            return 'std::fmod(%s(%s),%s(%s))' % (ct(rt2), lc, ct(rt2), rc), rt2
        if rt2 in ('int', 'long') and op in ('+', '-', '*'):
            return '%s(%s(%s) %s %s(%s))' % ('jwrap32' if rt2 == 'int' else 'jwrap64', 'jw' + rt2, lc, op, 'jw' + rt2, rc), rt2
        return '(%s %s %s)' % (lc, op, rc), rt2

    def strarg(s, c, t):
        if t == 'char': return 'jchar(%s)' % c
        if t in ('byte', 'short'): return '(int32_t)(%s)' % c
        if t == 'Object': return 'jstrobj(%s)' % c
        return c

    def cast(s, c, t, tt):
        if tt == t: return c
        if is_num(tt) and is_num(t):
            if t in ('float', 'double') and tt in ('int', 'long', 'short', 'byte', 'char'):
                if tt == 'long': return 'jf2l(%s)' % c
                if tt == 'int': return 'jf2i(%s)' % c
                return '(%s)jf2i(%s)' % (ct(tt), c)
            return '((%s)(%s))' % (ct(tt), c)
        if t == 'Object':
            if tt == 'Integer': return 'jcast_int(%s)' % c
            return 'jcast<%s>(%s)' % (ct(tt), c)
        if is_game(tt) and is_game(t): return 'jdown<%s>(%s)' % (tt, c)
        if tt == 'Object': return 'Obj(%s)' % c
        if t == 'null': return '(%s)nullptr' % ct(tt)
        return '((%s)(%s))' % (ct(tt), c)

    def conv(s, c, t, tt, force=False):
        if tt is None: return c
        if t == 'null':
            return 'static_cast<%s>(nullptr)' % ct(tt) if force else 'nullptr'
        if tt == 'Object[]' and is_arr(t) and t != tt: return 'jarr_obj(%s)' % c
        if tt == 'Object' and t != 'Object': return 'Obj(%s)' % c
        if tt == 'Integer' and t == 'Object': return 'jcast_int(%s)' % c
        if is_num(tt) and is_num(t) and tt != t:
            return '((%s)(%s))' % (ct(tt), c)
        if is_game(tt) and is_game(t) and tt != t:
            return 'static_cast<%s*>(%s)' % (tt, c)
        if force and tt != t: return 'static_cast<%s>(%s)' % (ct(tt), c)
        return c

    def args(s, m, args):
        out = []
        for (c, t), p in zip(args, m.parameters):
            out.append(s.conv(c, t, tstr(p.type) + ('[]' if p.varargs else '')))
        return ', '.join(out)

    def pick(s, ms, args):
        cands = [m for m in ms if len(m.parameters) == len(args)]
        if len(cands) != 1: raise Exception('overload ambiguity %s %d' % (ms[0].name if ms else '?', len(cands)))
        return cands[0]

    def invoke(s, e, cx):
        args, decls = s.eval_args(e.arguments, cx)
        return s.wrapc(s.invoke2(e, cx, args), decls)

    def invoke2(s, e, cx, args):
        name = e.member
        q = e.qualifier
        if q:
            if q.split('.')[-1] == 'getClass' or False: pass
            qc, qt = s.qualified(q, cx)
            if qt.startswith('#class:'):
                cn = qt[7:]
                if cn in classes:
                    k, ms = find_method(cn, name)
                    m = s.pick(ms, args)
                    pre = '' if k in chain(cx.cls) else '%s::__ci(), ' % k
                    call = '%s::%s(%s)' % (k, name, s.args(m, args))
                    return ('(%s%s)' % (pre, call) if pre else call), tstr(m.return_type)
                return s.lib_static(cn, name, args)
            return s.call_on(qc, qt, e, cx, args)
        # unqualified
        k, ms = find_method(cx.cls, name)
        if ms:
            m = s.pick(ms, args)
            if 'static' in m.modifiers:
                return '%s::%s(%s)' % (k, name, s.args(m, args)), tstr(m.return_type)
            return 'this->%s(%s)' % (name, s.args(m, args)), tstr(m.return_type)
        # inherited library method (GameCanvas / MIDlet)
        rt = lib_ret(cx.cls, name, [t for _, t in args])
        return 'this->%s(%s)' % (name, ', '.join(c for c, _ in args)), rt

    def call_on(s, code, t, sel, cx, args=None):
        name = sel.member
        if args is None:
            args, decls = s.eval_args(sel.arguments, cx)
            return s.wrapc(s.call_on(code, t, sel, cx, args), decls)
        if is_game(t):
            k, ms = find_method(t, name)
            if ms:
                m = s.pick(ms, args)
                if 'static' in m.modifiers: return '%s::%s(%s)' % (k, name, s.args(m, args)), tstr(m.return_type)
                return '%s->%s(%s)' % (code, name, s.args(m, args)), tstr(m.return_type)
            if name == 'getClass': return 'jgetclass()', 'Class'
            rt = lib_ret(t, name, [x for _, x in args])
            return '%s->%s(%s)' % (code, name, ', '.join(c for c, _ in args)), rt
        if is_arr(t):
            if name == 'clone': return '%s.clone()' % code, t
            raise Exception('array method ' + name)
        if t == 'Object' and name == 'getClass': return 'jgetclass()', 'Class'
        rt = lib_ret(t, name, [x for _, x in args])
        acc = '.' if t in VALUE_REFS else '->'
        a = ', '.join(s.libarg(c, x) for c, x in args)
        if t == 'Object': return 'jobj_%s(%s%s)' % (name, code, (', ' + a) if a else ''), rt
        return '%s%s%s(%s)' % (code, acc, name if name != 'delete' else 'delete_', a), rt

    def libarg(s, c, t):
        if t == 'null': return 'nullptr'
        return c

    def lib_static(s, cn, name, args):
        a = ', '.join(s.libarg(c, t) for c, t in args)
        if cn == 'Math':
            rt = lib_ret('Math', name, [t for _, t in args])
            if name in ('abs', 'max', 'min'):
                return 'jmath_%s<%s>(%s)' % (name, ct(rt), a), rt
            return 'std::%s(%s)' % ({'toDegrees': 'jtoDegrees'}.get(name, name), a) if name != 'toDegrees' else 'jtoDegrees(%s)' % a, 'double'
        rt = lib_ret(cn, name, [t for _, t in args])
        return '%s::%s(%s)' % ({'Font': 'JFontImpl'}.get(cn, 'J' + cn), name, a), rt

    # ----- statements -----
    def block(s, stmts, cx, ind):
        out = []
        cx.push()
        for st in stmts: out += s.stmt(st, cx, ind)
        cx.pop()
        return out

    def stmt(s, st, cx, ind):
        p = '   ' * ind
        out = []
        label = getattr(st, 'label', None)
        if label:
            cx.labels[label] = True
        if isinstance(st, T.LocalVariableDeclaration) or isinstance(st, T.VariableDeclaration):
            t = tstr(st.type)
            for d in st.declarators:
                tt = t + '[]' * len(d.dimensions or [])
                if d.initializer is not None:
                    if isinstance(d.initializer, T.ArrayInitializer):
                        init = s.array_init(d.initializer, tt, cx)
                    else:
                        c, it = s.expr(d.initializer, cx); init = s.conv(c, it, tt)
                    cx.declare(d.name, tt)
                    out.append('%s%s %s = %s;' % (p, ct(tt), L(d.name), init))
                else:
                    cx.declare(d.name, tt)
                    out.append('%s%s %s{};' % (p, ct(tt), L(d.name)))
            return s.wrap_label(out, label, p, None)
        if isinstance(st, T.StatementExpression):
            c, _ = s.expr(st.expression, cx)
            return s.wrap_label([p + c + ';'], label, p, None)
        if isinstance(st, T.BlockStatement):
            body = s.block(st.statements or [], cx, ind + 1)
            return s.wrap_label([p + '{'] + body + [p + '}'], label, p, None)
        if isinstance(st, T.IfStatement):
            c, _ = s.expr(st.condition, cx)
            out.append(p + 'if (%s) {' % c)
            out += s.sub(st.then_statement, cx, ind + 1)
            if st.else_statement is not None:
                out.append(p + '} else {')
                out += s.sub(st.else_statement, cx, ind + 1)
            out.append(p + '}')
            return s.wrap_label(out, label, p, None)
        if isinstance(st, T.WhileStatement):
            c, _ = s.expr(st.condition, cx)
            out.append(p + 'while (%s) {' % c)
            out += s.loop_body(st.body, cx, ind, label)
            out.append(p + '}')
            return s.wrap_label(out, label, p, True)
        if isinstance(st, T.DoStatement):
            out.append(p + 'do {')
            out += s.loop_body(st.body, cx, ind, label)
            c, _ = s.expr(st.condition, cx)
            out.append(p + '} while (%s);' % c)
            return s.wrap_label(out, label, p, True)
        if isinstance(st, T.ForStatement):
            fc = st.control
            cx.push()
            init = ''
            if fc.init is not None:
                if isinstance(fc.init, T.VariableDeclaration):
                    t = tstr(fc.init.type); parts = []
                    for d in fc.init.declarators:
                        cx.declare(d.name, t)
                        c, it = s.expr(d.initializer, cx) if d.initializer is not None else ('{}', t)
                        parts.append('%s = %s' % (L(d.name), s.conv(c, it, t)) if d.initializer is not None else L(d.name) + '{}')
                    init = '%s %s' % (ct(t), ', '.join(parts))
                else:
                    init = ', '.join(s.expr(x, cx)[0] for x in (fc.init if isinstance(fc.init, list) else [fc.init]))
            cond = s.expr(fc.condition, cx)[0] if fc.condition is not None else ''
            upd = ', '.join(s.expr(x, cx)[0] for x in (fc.update or []))
            out.append(p + 'for (%s; %s; %s) {' % (init, cond, upd))
            out += s.loop_body(st.body, cx, ind, label)
            out.append(p + '}')
            cx.pop()
            return s.wrap_label(out, label, p, True)
        if isinstance(st, T.ReturnStatement):
            if st.expression is None: return [p + 'return;']
            c, t = s.expr(st.expression, cx)
            return [p + 'return %s;' % s.conv(c, t, cx.ret, force=(t == 'null'))]
        if isinstance(st, T.BreakStatement):
            if st.goto: return [p + 'goto %s_brk;' % st.goto]
            return [p + 'break;']
        if isinstance(st, T.ContinueStatement):
            if st.goto: return [p + 'goto %s_cont;' % st.goto]
            return [p + 'continue;']
        if isinstance(st, T.ThrowStatement):
            c, t = s.expr(st.expression, cx)
            return [p + 'jthrow(%s);' % c]
        if isinstance(st, T.SynchronizedStatement):
            return s.wrap_label([p + '{'] + s.block(st.block, cx, ind + 1) + [p + '}'], label, p, None)
        if isinstance(st, T.SwitchStatement):
            c, _ = s.expr(st.expression, cx)
            # hoist declarations made directly in case bodies
            hoist = []
            cx.push()
            for case in st.cases:
                for x in case.statements:
                    if isinstance(x, T.LocalVariableDeclaration):
                        t = tstr(x.type)
                        for d in x.declarators:
                            tt = t + '[]' * len(d.dimensions or [])
                            if cx.scopes[-1].get(d.name) not in (None, tt): raise Exception('switch hoist type clash')
                            if d.name not in cx.scopes[-1]: hoist.append('%s   %s %s{};' % (p, ct(tt), L(d.name)))
                            cx.declare(d.name, tt)
            out.append(p + '{')
            out += hoist
            out.append(p + '   switch (%s) {' % c)
            for case in st.cases:
                for cv in case.case:
                    if cv == 'default': out.append(p + '   default:'); continue
                    vc, _ = s.expr(cv, cx)
                    out.append(p + '   case %s:' % vc)
                out.append(p + '   {')
                for x in case.statements:
                    if isinstance(x, T.LocalVariableDeclaration):
                        t = tstr(x.type)
                        for d in x.declarators:
                            if d.initializer is not None:
                                tt = t + '[]' * len(d.dimensions or [])
                                if isinstance(d.initializer, T.ArrayInitializer): init = s.array_init(d.initializer, tt, cx)
                                else:
                                    ic, it = s.expr(d.initializer, cx); init = s.conv(ic, it, tt)
                                out.append(p + '      %s = %s;' % (L(d.name), init))
                    else:
                        out += s.stmt(x, cx, ind + 2)
                out.append(p + '   }')
            out.append(p + '   }')
            out.append(p + '}')
            cx.pop()
            return s.wrap_label(out, label, p, None)
        if isinstance(st, T.TryStatement):
            if st.resources: raise Exception('try-with-resources')
            if st.finally_block:
                out.append(p + '{')
                out.append(p + '   auto __fin%d = jfinally([&]() {' % (id(st) % 100000))
                out += s.block(st.finally_block, cx, ind + 2)
                out.append(p + '   });')
                ind2 = ind + 1
            else: ind2 = ind
            p2 = '   ' * ind2
            out.append(p2 + 'try {')
            out += s.block(st.block or [], cx, ind2 + 1)
            out.append(p2 + '}')
            for cc in st.catches or []:
                types = cc.parameter.types
                tn = types[0]
                cx.push(); cx.declare(cc.parameter.name, tn)
                out.append(p2 + 'catch (J%s& %s) {' % (tn, L(cc.parameter.name)))
                out += s.block(cc.block or [], cx, ind2 + 1)
                out.append(p2 + '}')
                cx.pop()
            if st.finally_block: out.append(p + '}')
            return s.wrap_label(out, label, p, None)
        if isinstance(st, T.Statement) and type(st).__name__ == 'Statement':
            return [p + ';']
        raise Exception('stmt %s' % type(st).__name__)

    def sub(s, st, cx, ind):
        if isinstance(st, T.BlockStatement):
            return s.block(st.statements or [], cx, ind)
        cx.push(); r = s.stmt(st, cx, ind); cx.pop(); return r

    def loop_body(s, body, cx, ind, label):
        p = '   ' * (ind + 1)
        inner = s.sub(body, cx, ind + 2)
        out = [p + '{'] + inner + [p + '}']
        if label: out.append(p + '%s_cont:;' % label)
        return out

    def wrap_label(s, out, label, p, loop):
        if not label: return out
        return [p + '{'] + out + [p + '}', p + '%s_brk:;' % label]

# ---------- class emission ----------
def order():
    done, res = set(), []
    def visit(c):
        if c in done: return
        sup = info[c]['sup']
        if sup in info: visit(sup)
        done.add(c); res.append(c)
    for c in sorted(classes): visit(c)
    return res

def sig(m, cls, qualified=False, isctor=False):
    ps = ', '.join('%s %s' % (ct(tstr(p.type)), L(p.name)) for p in m.parameters)
    if isctor: return '%s%s(%s)' % (cls + '::' if qualified else '', cls, ps)
    return '%s %s%s(%s)' % (ct(tstr(m.return_type)), cls + '::' if qualified else '', m.name, ps)

def main():
    hdr = ['// Generated by j2cpp.py from the decompiled game source. Do not edit by hand.', '#pragma once', '#include "jrt.hpp"']
    for c in sorted(classes): hdr.append('struct %s;' % c)
    body = ['#include "game.hpp"']
    for c in order():
        I = info[c]
        sup = I['sup']
        base = sup if sup in info else ('J' + sup + 'Base' if sup else 'JObjectBase')
        if c in LIB_SUPER: base = 'J' + LIB_SUPER[c] + 'Base'
        hdr.append('struct %s : %s {' % (c, base))
        hdr.append('   static inline bool __inited = false;')
        hdr.append('   static void __ci() { if (!__inited) __clinit(); }')
        hdr.append('   static void __clinit();')
        for n, f in I['fields'].items():
            hdr.append('   %s%s %s{};' % ('static inline ' if f['static'] else '', ct(f['type']), n))
        for ctor in I['ctors']:
            hdr.append('   ' + sig(ctor, c, isctor=True) + ';')
        if not I['ctors']: hdr.append('   %s();' % c)
        for n, ms in I['methods'].items():
            for m in ms:
                st = 'static' in m.modifiers
                virt = '' if st else 'virtual '
                hdr.append('   %s%s;' % ('static ' if st else virt, sig(m, c)))
        hdr.append('};')
        em = Em(c)
        # clinit
        cx = Ctx(c, True)
        body.append('void %s::__clinit() {' % c)
        body.append('   __inited = true;')
        if sup in info: body.append('   %s::__ci();' % sup)
        for n, f in I['fields'].items():
            if f['static'] and f['init'] is not None:
                if isinstance(f['init'], T.ArrayInitializer): v = em.array_init(f['init'], f['type'], cx)
                else:
                    vc, vt = em.expr(f['init'], cx); v = em.conv(vc, vt, f['type'])
                body.append('   %s = %s;' % (n, v))
        for blk in I['clinit']:
            stmts = blk if isinstance(blk, list) else [blk]
            body += em.block(stmts, cx, 1)
        body.append('}')
        # ctors
        ctors = I['ctors'] or [None]
        for ctor in ctors:
            cx = Ctx(c, False); cx.ret = 'void'
            stmts = list(ctor.body) if ctor else []
            init = ''
            if ctor:
                for p_ in ctor.parameters: cx.declare(p_.name, tstr(p_.type))
            if stmts and isinstance(stmts[0], T.StatementExpression) and isinstance(stmts[0].expression, T.SuperConstructorInvocation):
                sc = stmts.pop(0).expression
                args = [em.expr(a, cx) for a in sc.arguments]
                if sup in info:
                    m = em.pick(info[sup]['ctors'], args); init = ' : %s(%s)' % (sup, em.args(m, args))
                else:
                    init = ' : %s(%s)' % (base, ', '.join(a for a, _ in args))
            elif stmts and isinstance(stmts[0], T.SuperConstructorInvocation):
                sc = stmts.pop(0)
                args = [em.expr(a, cx) for a in sc.arguments]
                init = ' : %s(%s)' % (base if sup not in info else sup, ', '.join(a for a, _ in args))
            body.append('%s%s {' % (sig(ctor, c, True, True) if ctor else '%s::%s()' % (c, c), init))
            for n, f in I['fields'].items():
                if not f['static'] and f['init'] is not None:
                    if isinstance(f['init'], T.ArrayInitializer): v = em.array_init(f['init'], f['type'], cx)
                    else:
                        vc, vt = em.expr(f['init'], cx); v = em.conv(vc, vt, f['type'])
                    body.append('   this->%s = %s;' % (n, v))
            body += em.block(stmts, cx, 1)
            body.append('}')
        for n, ms in I['methods'].items():
            for m in ms:
                cx = Ctx(c, 'static' in m.modifiers); cx.ret = tstr(m.return_type)
                for p_ in m.parameters: cx.declare(p_.name, tstr(p_.type))
                body.append(sig(m, c, True) + ' {')
                try:
                    body += em.block(m.body or [], cx, 1)
                except Exception as ex:
                    raise Exception('%s.%s: %s' % (c, n, ex))
                body.append('}')
    open(os.path.join(OUT, 'game.hpp'), 'w').write('\n'.join(hdr) + '\n')
    open(os.path.join(OUT, 'game.cpp'), 'w').write('\n'.join(body) + '\n')

main()
