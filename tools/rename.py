# Gives every field and method of the game classes a unique, readable name so the
# decompiled source is valid Java (the obfuscator reused names like "a" for many members).
import sys, struct, zipfile
LIB_KEEP={'startApp','pauseApp','destroyApp','run','paint','keyPressed','keyReleased','keyRepeated','showNotify','hideNotify','sizeChanged','commandAction','pointerPressed','pointerReleased','pointerDragged','<init>','<clinit>'}
class CF:
    def __init__(s,data):
        s.d=data; p=8; n=struct.unpack('>H',data[p:p+2])[0]; p+=2
        s.cp=[None]; i=1
        while i<n:
            t=data[p]
            if t==1:
                l=struct.unpack('>H',data[p+1:p+3])[0]; s.cp.append((1,data[p+3:p+3+l].decode('utf8','surrogatepass'))); p+=3+l
            elif t in (3,4): s.cp.append((t,data[p+1:p+5])); p+=5
            elif t in (5,6): s.cp.append((t,data[p+1:p+9])); s.cp.append(None); p+=9; i+=1
            elif t in (7,8,16): s.cp.append((t,struct.unpack('>H',data[p+1:p+3])[0])); p+=3
            elif t in (9,10,11,12,18): a,b=struct.unpack('>HH',data[p+1:p+5]); s.cp.append((t,a,b)); p+=5
            elif t==15: s.cp.append((t,data[p+1],struct.unpack('>H',data[p+2:p+4])[0])); p+=4
            else: raise Exception('tag %d'%t)
            i+=1
        s.rest_start=p
        s.access,s.this,s.sup=struct.unpack('>HHH',data[p:p+6]); p+=6
        ic=struct.unpack('>H',data[p:p+2])[0]; p+=2+2*ic
        s.members=[]  # (kind, offset_of_name_index, name, desc)
        for kind in ('F','M'):
            c=struct.unpack('>H',data[p:p+2])[0]; p+=2
            for _ in range(c):
                acc,ni,di,ac=struct.unpack('>HHHH',data[p:p+8])
                s.members.append((kind,p+2,s.u(ni),s.u(di),acc)); p+=8
                for _ in range(ac):
                    l=struct.unpack('>I',data[p+2:p+6])[0]; p+=6+l
    def u(s,i): return s.cp[i][1]
    def cls(s,i): return s.u(s.cp[i][1])
    def name(s): return s.cls(s.this)
    def super(s): return s.cls(s.sup) if s.sup else None
def short(desc):
    m={'I':'i','B':'b','S':'s','Z':'z','C':'c','J':'l','F':'f','D':'d','V':'v'}
    out='';i=0
    while i<len(desc):
        ch=desc[i]
        if ch=='[': out+='A'; i+=1
        elif ch=='L': j=desc.index(';',i); out+=desc[i+1:j].split('/')[-1]; i=j+1
        elif ch in '()': out+='_' if ch==')' else ''; i+=1
        else: out+=m[ch]; i+=1
    return out
def main(src,dst):
    zin=zipfile.ZipFile(src); classes={}
    for n in zin.namelist():
        if n.endswith('.class'): classes[n[:-6]]=CF(zin.read(n))
    decl={}  # class -> set of (kind,name,desc)
    for c,cf in classes.items(): decl[c]={(k,nm,ds) for k,_,nm,ds,_ in cf.members}
    def chain(c):
        while c in classes: yield c; c=classes[c].super()
    def resolve(kind,owner,nm,ds):
        if nm in LIB_KEEP: return None
        root=None
        for c in chain(owner):
            if (kind,nm,ds) in decl[c]: root=c
            if kind=='F' and root: break
        if root is None: return None
        if kind=='F': return '%s_%s'%(nm,short(ds))
        return '%s_%s'%(nm,short(ds))
    zout=zipfile.ZipFile(dst,'w',zipfile.ZIP_DEFLATED)
    for n in zin.namelist():
        data=zin.read(n)
        if n.endswith('.class'):
            cf=classes[n[:-6]]; d=bytearray(data); newcp=[]; base=len(cf.cp)
            utf={}
            def addutf(sv):
                if sv in utf: return utf[sv]
                idx=base+len(newcp); b=sv.encode('utf8'); newcp.append(b'\x01'+struct.pack('>H',len(b))+b); utf[sv]=idx; return idx
            nat={}
            def addnat(ni,di):
                key=(ni,di)
                if key in nat: return nat[key]
                idx=base+len(newcp); newcp.append(b'\x0c'+struct.pack('>HH',ni,di)); nat[key]=idx; return idx
            # rewrite refs: locate entries in the original byte stream
            p=10; i=1
            while i<len(cf.cp):
                e=cf.cp[i]; t=data[p]
                if t==1: l=struct.unpack('>H',data[p+1:p+3])[0]; p+=3+l
                elif t in (3,4): p+=5
                elif t in (5,6): p+=9; i+=1
                elif t in (7,8,16): p+=3
                elif t in (9,10,11):
                    owner=cf.cls(e[1]); _,ni,di=cf.cp[e[2]]; nm=cf.u(ni); ds=cf.u(di)
                    new=resolve('F' if t==9 else 'M',owner,nm,ds)
                    if new: d[p+3:p+5]=struct.pack('>H',addnat(addutf(new),di))
                    p+=5
                elif t in (12,18): p+=5
                elif t==15: p+=4
                i+=1
            for k,off,nm,ds,acc in cf.members:
                new=resolve(k,cf.name(),nm,ds)
                if new: d[off:off+2]=struct.pack('>H',addutf(new))
            # splice new constants
            total=base+len(newcp)
            d[8:10]=struct.pack('>H',total)
            d=d[:cf.rest_start]+b''.join(newcp)+d[cf.rest_start:]
            data=bytes(d)
        zi=zipfile.ZipInfo(n,date_time=(2008,12,4,17,30,0)); zout.writestr(zi,data,zipfile.ZIP_DEFLATED)
    zout.close()
main(sys.argv[1],sys.argv[2])
