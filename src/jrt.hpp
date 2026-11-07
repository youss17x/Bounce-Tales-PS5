/*
 * Bounce Tales PS5 port: Java/J2ME runtime for the translated game code.
 * PS5 port contributions: Youss Riaal, 2026. SPDX-License-Identifier: GPL-3.0-only
 *
 * Implements the small part of Java, MIDP 2.0 and the Nokia UI API that the game
 * uses, with Java semantics where they matter (wrapping integer arithmetic,
 * masked shifts, bounds-checked arrays, java.util.Random).
 */
#pragma once
#include <cstdint>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <typeinfo>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>

// ---------------- arithmetic ----------------
inline int64_t jwint(int64_t v) { return v; }
inline uint64_t jwlong(int64_t v) { return (uint64_t)v; }
inline int32_t jwrap32(int64_t v) { return (int32_t)(uint32_t)(uint64_t)v; }
inline int64_t jwrap64(uint64_t v) { return (int64_t)v; }
inline int32_t jshl(int32_t a, int64_t n) { return (int32_t)((uint32_t)a << (n & 31)); }
inline int32_t jshr(int32_t a, int64_t n) { return a >> (n & 31); }
inline int32_t jushr(int32_t a, int64_t n) { return (int32_t)((uint32_t)a >> (n & 31)); }
inline int64_t jshl(int64_t a, int64_t n) { return (int64_t)((uint64_t)a << (n & 63)); }
inline int64_t jshr(int64_t a, int64_t n) { return a >> (n & 63); }
inline int64_t jushr(int64_t a, int64_t n) { return (int64_t)((uint64_t)a >> (n & 63)); }
inline int32_t jf2i(double d) { if (d != d) return 0; if (d >= 2147483647.0) return INT32_MAX; if (d <= -2147483648.0) return INT32_MIN; return (int32_t)d; }
inline int64_t jf2l(double d) { if (d != d) return 0; if (d >= 9.2233720368547758e18) return INT64_MAX; if (d <= -9.2233720368547758e18) return INT64_MIN; return (int64_t)d; }
inline double jtoDegrees(double r) { return r * 180.0 / M_PI; }
template<class T> inline T jmath_abs(T v) { return v < 0 ? (T)(0 - v) : v; }
template<> inline int32_t jmath_abs<int32_t>(int32_t v) { return v < 0 ? jwrap32(-(int64_t)v) : v; }
template<class T, class A, class B> inline T jmath_max(A a, B b) { return (T)a > (T)b ? (T)a : (T)b; }
template<class T, class A, class B> inline T jmath_min(A a, B b) { return (T)a < (T)b ? (T)a : (T)b; }
template<class T> inline T jmath_abs(double v) { return (T)std::fabs(v); }

// ---------------- exceptions ----------------
struct JThrowable { virtual ~JThrowable() {} virtual const char* what() const { return "Throwable"; } JThrowable* operator->() { return this; } void printStackTrace() {} };
#define JEXC(N, B) struct J##N : J##B { static std::shared_ptr<J##N> make(...) { return std::make_shared<J##N>(); } const char* what() const override { return #N; } J##N* operator->() { return this; } };
JEXC(Exception, Throwable)
JEXC(RuntimeException, Exception)
JEXC(IOException, Exception)
JEXC(EOFException, IOException)
JEXC(RecordStoreException, Exception)
JEXC(RecordStoreNotFoundException, RecordStoreException)
JEXC(InterruptedException, Exception)
JEXC(MediaException, Exception)
JEXC(IllegalArgumentException, RuntimeException)
JEXC(NumberFormatException, IllegalArgumentException)
JEXC(IllegalStateException, RuntimeException)
JEXC(ArithmeticException, RuntimeException)
JEXC(ArrayIndexOutOfBoundsException, RuntimeException)
JEXC(NullPointerException, RuntimeException)
JEXC(ClassCastException, RuntimeException)
JEXC(NegativeArraySizeException, RuntimeException)
template<class E> [[noreturn]] inline void jthrow(const std::shared_ptr<E>& e) { throw *e; }
template<class E> [[noreturn]] inline void jthrow(E& e) { throw e; }

inline int32_t jdiv(int32_t a, int32_t b) { if (!b) throw JArithmeticException(); if (a == INT32_MIN && b == -1) return a; return a / b; }
inline int32_t jrem(int32_t a, int32_t b) { if (!b) throw JArithmeticException(); if (b == -1) return 0; return a % b; }
inline int64_t jdiv(int64_t a, int64_t b) { if (!b) throw JArithmeticException(); if (a == INT64_MIN && b == -1) return a; return a / b; }
inline int64_t jrem(int64_t a, int64_t b) { if (!b) throw JArithmeticException(); if (b == -1) return 0; return a % b; }

template<class F> struct JFinally { F f; ~JFinally() { f(); } };
template<class F> JFinally<F> jfinally(F f) { return JFinally<F>{f}; }

// ---------------- arrays ----------------
template<class T> struct ArrBox { int n; std::unique_ptr<T[]> d; explicit ArrBox(int n) : n(n), d(new T[n > 0 ? n : 1]()) {} };
template<class T> struct Arr {
    std::shared_ptr<ArrBox<T>> p;
    Arr() {}
    Arr(std::nullptr_t) {}
    explicit Arr(int n) { if (n < 0) throw JNegativeArraySizeException(); p = std::make_shared<ArrBox<T>>(n); }
    Arr(std::initializer_list<T> l) : p(std::make_shared<ArrBox<T>>((int)l.size())) { int i = 0; for (auto& v : l) p->d[i++] = v; }
    T& operator[](int64_t i) const { if (!p) throw JNullPointerException(); if (i < 0 || i >= p->n) throw JArrayIndexOutOfBoundsException(); return p->d[(size_t)i]; }
    int32_t length() const { if (!p) throw JNullPointerException(); return p->n; }
    T* data() const { return p ? p->d.get() : nullptr; }
    bool operator==(const Arr& o) const { return p == o.p; }
    bool operator!=(const Arr& o) const { return p != o.p; }
    bool operator==(std::nullptr_t) const { return !p; }
    bool operator!=(std::nullptr_t) const { return !!p; }
    Arr clone() const { Arr r(length()); for (int i = 0; i < p->n; i++) r.p->d[i] = p->d[i]; return r; }
};
template<class T> Arr<T> newArr(int64_t n) { return Arr<T>((int)n); }
template<class T> Arr<Arr<T>> newArr2(int64_t a, int64_t b) { Arr<Arr<T>> r((int)a); for (int i = 0; i < a; i++) r[i] = Arr<T>((int)b); return r; }

// ---------------- strings ----------------
struct JString {
    std::shared_ptr<const std::u16string> s;
    JString() {}
    JString(std::nullptr_t) {}
    JString(const char16_t* v) : s(std::make_shared<const std::u16string>(v)) {}
    JString(std::u16string v) : s(std::make_shared<const std::u16string>(std::move(v))) {}
    static JString make(const JString& v) { return v; }
    static JString make(Arr<char16_t> a) { return std::u16string(a.data(), a.length()); }
    static JString make(Arr<int8_t> a);
    const std::u16string& str() const { if (!s) throw JNullPointerException(); return *s; }
    int32_t length() const { return (int32_t)str().size(); }
    char16_t charAt(int64_t i) const { auto& v = str(); if (i < 0 || i >= (int64_t)v.size()) throw JArrayIndexOutOfBoundsException(); return v[(size_t)i]; }
    JString substring(int64_t a) const { return substring(a, length()); }
    JString substring(int64_t a, int64_t b) const { auto& v = str(); if (a < 0 || b > (int64_t)v.size() || a > b) throw JArrayIndexOutOfBoundsException(); return v.substr((size_t)a, (size_t)(b - a)); }
    int32_t indexOf(const JString& o, int64_t from = 0) const { auto& v = str(); if (from < 0) from = 0; if (from > (int64_t)v.size()) return o.str().empty() ? (int)v.size() : -1; auto r = v.find(o.str(), (size_t)from); return r == std::u16string::npos ? -1 : (int32_t)r; }
    int32_t indexOf(char16_t c, int64_t from = 0) const { auto& v = str(); if (from < 0) from = 0; if (from >= (int64_t)v.size()) return -1; auto r = v.find(c, (size_t)from); return r == std::u16string::npos ? -1 : (int32_t)r; }
    int32_t indexOf(int32_t c, int64_t from = 0) const { return indexOf((char16_t)c, from); }
    int32_t lastIndexOf(char16_t c) const { auto r = str().rfind(c); return r == std::u16string::npos ? -1 : (int32_t)r; }
    bool equals(const JString& o) const { if (!o.s) return false; return str() == *o.s; }
    bool startsWith(const JString& o) const { auto& v = str(); auto& w = o.str(); return v.size() >= w.size() && v.compare(0, w.size(), w) == 0; }
    bool endsWith(const JString& o) const { auto& v = str(); auto& w = o.str(); return v.size() >= w.size() && v.compare(v.size() - w.size(), w.size(), w) == 0; }
    JString trim() const { auto& v = str(); size_t a = 0, b = v.size(); while (a < b && v[a] <= ' ') a++; while (b > a && v[b - 1] <= ' ') b--; if (a == 0 && b == v.size()) return *this; return v.substr(a, b - a); }
    Arr<char16_t> toCharArray() const { auto& v = str(); Arr<char16_t> a((int)v.size()); for (size_t i = 0; i < v.size(); i++) a[(int)i] = v[i]; return a; }
    JString toString() const { return *this; }
    JString toUpperCase() const { auto v = str(); for (auto& c : v) if (c >= 'a' && c <= 'z') c -= 32; return v; }
    JString toLowerCase() const { auto v = str(); for (auto& c : v) if (c >= 'A' && c <= 'Z') c += 32; return v; }
    bool operator==(const JString& o) const { return s == o.s; }
    bool operator!=(const JString& o) const { return s != o.s; }
    bool operator==(std::nullptr_t) const { return !s; }
    bool operator!=(std::nullptr_t) const { return !!s; }
    std::string utf8() const;
};
// Adjusts game text when it is loaded (e.g. phone keys -> DualSense buttons).
JString jrt_patch_text(std::u16string s);
#define JS(lit) ([]() -> const JString& { static const JString v(lit); return v; }())
inline std::u16string jnum(int64_t v) { std::string s = std::to_string(v); return std::u16string(s.begin(), s.end()); }
inline std::u16string jdbl(double v) { char b[64]; snprintf(b, sizeof b, "%g", v); std::string s = b; if (s.find('.') == std::string::npos && s.find('e') == std::string::npos) s += ".0"; return std::u16string(s.begin(), s.end()); }
inline const std::u16string& jsv(const JString& s) { static const std::u16string n = u"null"; return s.s ? *s.s : n; }
struct jchar { char16_t c; explicit jchar(char16_t c) : c(c) {} };
inline JString jcat(const JString& a, const JString& b) { return jsv(a) + jsv(b); }
inline JString jcat(const JString& a, int32_t b) { return jsv(a) + jnum(b); }
inline JString jcat(const JString& a, int64_t b) { return jsv(a) + jnum(b); }
inline JString jcat(const JString& a, bool b) { return jsv(a) + (b ? u"true" : u"false"); }
inline JString jcat(const JString& a, double b) { return jsv(a) + jdbl(b); }
inline JString jcat(const JString& a, float b) { return jsv(a) + jdbl(b); }
inline JString jcat(const JString& a, jchar b) { return jsv(a) + std::u16string(1, b.c); }
inline JString jcat(int32_t a, const JString& b) { return jnum(a) + jsv(b); }
inline JString jcat(int64_t a, const JString& b) { return jnum(a) + jsv(b); }
inline JString jcat(jchar a, const JString& b) { return std::u16string(1, a.c) + jsv(b); }
inline std::string JString::utf8() const {
    std::string o; for (char16_t c : jsv(*this)) { if (c < 0x80) o += (char)c; else if (c < 0x800) { o += (char)(0xC0 | (c >> 6)); o += (char)(0x80 | (c & 63)); } else { o += (char)(0xE0 | (c >> 12)); o += (char)(0x80 | ((c >> 6) & 63)); o += (char)(0x80 | (c & 63)); } }
    return o;
}
inline JString JString::make(Arr<int8_t> a) { std::u16string s; for (int i = 0; i < a.length(); i++) s += (char16_t)(uint8_t)a[i]; return s; }

// ---------------- objects ----------------
struct JClass;
struct JObjectBase {
    virtual ~JObjectBase() {}
    bool equals(const void* o) const { return this == o; }
    std::shared_ptr<JClass> getClass();
};
struct JInteger {
    int32_t v = 0; bool present = false;
    JInteger() {}
    JInteger(std::nullptr_t) {}
    JInteger(int32_t v) : v(v), present(true) {}
    static JInteger make(int32_t v) { return JInteger(v); }
    static JInteger valueOf(int32_t v) { return JInteger(v); }
    static JInteger valueOf(const JString& s) { return JInteger(parseInt(s)); }
    static JString toString(int32_t v) { return jnum(v); }
    static int32_t parseInt(const JString& s);
    int32_t intValue() const { return v; }
    operator int32_t() const { return v; }
};
struct Obj {
    std::shared_ptr<void> keep; const void* raw = nullptr; const std::type_info* ti = nullptr; int32_t ival = 0;
    Obj() {}
    Obj(std::nullptr_t) {}
    template<class T> Obj(const Arr<T>& a) : keep(a.p), raw(a.p.get()), ti(a.p ? &typeid(Arr<T>) : nullptr) {}
    Obj(const JString& s) : keep(s.s ? std::const_pointer_cast<std::u16string>(s.s) : nullptr), raw(s.s.get()), ti(s.s ? &typeid(JString) : nullptr) {}
    Obj(JObjectBase* p) : raw(p), ti(p ? &typeid(JObjectBase) : nullptr) {}
    Obj(int32_t v) : keep(std::make_shared<int32_t>(v)), ti(&typeid(JInteger)), ival(v) { raw = keep.get(); }
    Obj(const JInteger& v) : Obj(v.v) {}
    template<class T> Obj(const std::shared_ptr<T>& p) : keep(p), raw(p.get()), ti(p ? &typeid(std::shared_ptr<T>) : nullptr) {}
    bool operator==(std::nullptr_t) const { return !raw; }
    bool operator!=(std::nullptr_t) const { return !!raw; }
    static Obj make() { Obj o; o.keep = std::make_shared<int>(0); o.raw = o.keep.get(); o.ti = &typeid(Obj); return o; }
};
using JObject = Obj;
inline bool jsame(const Obj& a, const Obj& b) { return a.raw == b.raw; }
template<class T> inline bool jsame(const Obj& a, const T& b) { return a.raw == Obj(b).raw; }
template<class T> inline bool jsame(const T& a, const Obj& b) { return Obj(a).raw == b.raw; }
inline bool jequals(const Obj& a, const Obj& b) {
    if (a.raw == b.raw) return true;
    if (!a.ti || !b.ti || *a.ti != *b.ti) return false;
    if (*a.ti == typeid(JInteger)) return a.ival == b.ival;
    if (*a.ti == typeid(JString)) return *(const std::u16string*)a.raw == *(const std::u16string*)b.raw;
    return false;
}
template<class T> struct JCast {
    static T get(const Obj& o) {
        if (!o.raw) return T();
        if (*o.ti != typeid(T)) throw JClassCastException();
        T r; r.p = std::static_pointer_cast<typename decltype(T::p)::element_type>(o.keep); return r;
    }
};
template<> struct JCast<JString> { static JString get(const Obj& o) { if (!o.raw) return nullptr; if (*o.ti != typeid(JString)) throw JClassCastException(); JString s; s.s = std::static_pointer_cast<const std::u16string>(o.keep); return s; } };
template<class T> struct JCast<T*> { static T* get(const Obj& o) { if (!o.raw) return nullptr; if (*o.ti != typeid(JObjectBase)) throw JClassCastException(); T* r = dynamic_cast<T*>((JObjectBase*)o.raw); if (!r) throw JClassCastException(); return r; } };
template<class T> inline T jcast(const Obj& o) { return JCast<T>::get(o); }
inline int32_t jcast_int(const Obj& o) { if (!o.raw) throw JNullPointerException(); if (*o.ti != typeid(JInteger)) throw JClassCastException(); return o.ival; }
template<class T, class U> inline T* jdown(U* p) { if (!p) return nullptr; T* r = dynamic_cast<T*>(p); if (!r) throw JClassCastException(); return r; }
void platform_wait(int64_t ms);
inline void jobj_wait(const Obj&, int64_t ms = 0) { platform_wait(ms > 0 && ms < 20 ? ms : 20); }
inline void jobj_notify(const Obj&) {}
inline void jobj_notifyAll(const Obj&) {}
inline JString jstrobj(const Obj& o) { if (!o.raw) return JS(u"null"); if (*o.ti == typeid(JString)) return jcast<JString>(o); if (*o.ti == typeid(JInteger)) return jnum(o.ival); return JS(u"Object"); }

struct JStringBufferImpl {
    std::u16string s;
    std::shared_ptr<JStringBufferImpl> self() { return std::shared_ptr<JStringBufferImpl>(this, [](JStringBufferImpl*) {}); }
};
struct JStringBuffer : std::shared_ptr<JStringBufferImpl> {
    using std::shared_ptr<JStringBufferImpl>::shared_ptr;
    JStringBuffer(const std::shared_ptr<JStringBufferImpl>& p) : std::shared_ptr<JStringBufferImpl>(p) {}
    static JStringBuffer make() { return JStringBuffer(std::make_shared<JStringBufferImpl>()); }
    static JStringBuffer make(const JString& s) { auto r = make(); r.get()->s = jsv(s); return r; }
    JStringBuffer* operator->() { return this; }
    JStringBuffer& append(char16_t c) { get()->s += c; return *this; }
    JStringBuffer& append(const JString& v) { get()->s += jsv(v); return *this; }
    JStringBuffer& append(int32_t v) { get()->s += jnum(v); return *this; }
    JStringBuffer& append(const JStringBuffer& v) { get()->s += v.get()->s; return *this; }
    JStringBuffer& delete_(int32_t a, int32_t b) { auto& s = get()->s; if (b > (int)s.size()) b = (int)s.size(); s.erase(a, b - a); return *this; }
    int32_t length() const { return (int32_t)get()->s.size(); }
    JString toString() const { return get()->s; }
};

// ---------------- collections / utilities ----------------
struct JVectorImpl { std::vector<Obj> v; };
struct JVector : std::shared_ptr<JVectorImpl> {
    using std::shared_ptr<JVectorImpl>::shared_ptr;
    JVector(const std::shared_ptr<JVectorImpl>& p) : std::shared_ptr<JVectorImpl>(p) {}
    static JVector make(...) { return JVector(std::make_shared<JVectorImpl>()); }
    const JVector* operator->() const { if (!get()) throw JNullPointerException(); return this; }
    std::vector<Obj>& v() const { return get()->v; }
    int32_t size() const { return (int32_t)v().size(); }
    bool isEmpty() const { return v().empty(); }
    Obj elementAt(int32_t i) const { if (i < 0 || i >= size()) throw JArrayIndexOutOfBoundsException(); return v()[i]; }
    Obj lastElement() const { if (v().empty()) throw JArrayIndexOutOfBoundsException(); return v().back(); }
    Obj firstElement() const { if (v().empty()) throw JArrayIndexOutOfBoundsException(); return v().front(); }
    void addElement(const Obj& o) const { v().push_back(o); }
    void insertElementAt(const Obj& o, int32_t i) const { if (i < 0 || i > size()) throw JArrayIndexOutOfBoundsException(); v().insert(v().begin() + i, o); }
    void removeElementAt(int32_t i) const { if (i < 0 || i >= size()) throw JArrayIndexOutOfBoundsException(); v().erase(v().begin() + i); }
    void setElementAt(const Obj& o, int32_t i) const { if (i < 0 || i >= size()) throw JArrayIndexOutOfBoundsException(); v()[i] = o; }
    int32_t indexOf(const Obj& o) const { for (size_t i = 0; i < v().size(); i++) if (jequals(v()[i], o)) return (int32_t)i; return -1; }
    bool contains(const Obj& o) const { return indexOf(o) >= 0; }
    bool removeElement(const Obj& o) const { int i = indexOf(o); if (i < 0) return false; v().erase(v().begin() + i); return true; }
    void removeAllElements() const { v().clear(); }
};

struct JRandomImpl {
    int64_t seed = 0;
    void setSeed(int64_t s) { seed = (s ^ 0x5DEECE66DLL) & ((1LL << 48) - 1); }
    int32_t next(int bits) { seed = (int64_t)(((uint64_t)seed * 0x5DEECE66DULL + 0xBULL) & ((1ULL << 48) - 1)); return (int32_t)(seed >> (48 - bits)); }
    int32_t nextInt() { return next(32); }
    int32_t nextInt(int32_t n) { if ((n & -n) == n) return (int32_t)(((int64_t)n * (int64_t)next(31)) >> 31); int32_t bits, val; do { bits = next(31); val = bits % n; } while (bits - val + (n - 1) < 0); return val; }
};
struct JRandom : std::shared_ptr<JRandomImpl> {
    using std::shared_ptr<JRandomImpl>::shared_ptr;
    JRandom(const std::shared_ptr<JRandomImpl>& p) : std::shared_ptr<JRandomImpl>(p) {}
    static JRandom make(int64_t seed) { auto r = JRandom(std::make_shared<JRandomImpl>()); r->setSeed(seed); return r; }
};

struct JFloat {
    static float intBitsToFloat(int32_t v) { float f; memcpy(&f, &v, 4); return f; }
    static int32_t floatToIntBits(float f) { if (f != f) return 0x7fc00000; int32_t v; memcpy(&v, &f, 4); return v; }
};
constexpr int32_t J_Integer_MAX_VALUE = INT32_MAX, J_Integer_MIN_VALUE = INT32_MIN;
constexpr int64_t J_Long_MAX_VALUE = INT64_MAX;
inline int32_t JInteger::parseInt(const JString& s) {
    auto& v = s.str(); if (v.empty()) throw JNumberFormatException(); int64_t r = 0; size_t i = 0; bool neg = false;
    if (v[0] == '-' || v[0] == '+') { neg = v[0] == '-'; i = 1; if (v.size() == 1) throw JNumberFormatException(); }
    for (; i < v.size(); i++) { if (v[i] < '0' || v[i] > '9') throw JNumberFormatException(); r = r * 10 + (v[i] - '0'); if (r > 2147483648LL) throw JNumberFormatException(); }
    if (neg) r = -r; if (r > INT32_MAX || r < INT32_MIN) throw JNumberFormatException(); return (int32_t)r;
}
struct JPrintStreamImpl { void println(const JString& s) { fprintf(stdout, "%s\n", s.utf8().c_str()); } };
inline JPrintStreamImpl* const J_System_out = new JPrintStreamImpl();

// ---------------- streams ----------------
struct JInputStreamImpl {
    std::vector<uint8_t> buf; size_t pos = 0, markpos = 0;
    virtual ~JInputStreamImpl() {}
    virtual int32_t read() { return pos < buf.size() ? buf[pos++] : -1; }
    int32_t read(Arr<int8_t> b) { return read(b, 0, b.length()); }
    virtual int32_t read(Arr<int8_t> b, int32_t off, int32_t len) {
        if (len == 0) return 0; if (pos >= buf.size()) return -1;
        int32_t n = (int32_t)std::min<size_t>(len, buf.size() - pos); for (int i = 0; i < n; i++) b[off + i] = (int8_t)buf[pos++]; return n;
    }
    virtual int64_t skip(int64_t n) { size_t k = (size_t)std::max<int64_t>(0, std::min<int64_t>(n, (int64_t)(buf.size() - pos))); pos += k; return (int64_t)k; }
    virtual int32_t available() { return (int32_t)(buf.size() - pos); }
    virtual void close() {}
    virtual bool markSupported() { return true; }
    virtual void mark(int32_t) { markpos = pos; }
    virtual void reset() { pos = markpos; }
    // the bytes still to be read (used to hand MIDI data to the player)
    virtual std::vector<uint8_t> rest() { return std::vector<uint8_t>(buf.begin() + pos, buf.end()); }
};
struct JInputStream : std::shared_ptr<JInputStreamImpl> {
    using std::shared_ptr<JInputStreamImpl>::shared_ptr;
    JInputStream(const std::shared_ptr<JInputStreamImpl>& p) : std::shared_ptr<JInputStreamImpl>(p) {}
    JInputStreamImpl* operator->() const { if (!get()) throw JNullPointerException(); return get(); }
};
struct JByteArrayInputStream : JInputStream {
    using JInputStream::JInputStream;
    static JByteArrayInputStream make(Arr<int8_t> a) { auto p = std::make_shared<JInputStreamImpl>(); p->buf.assign((uint8_t*)a.data(), (uint8_t*)a.data() + a.length()); return JByteArrayInputStream(p); }
};
struct JDataInputStreamImpl : JInputStreamImpl {
    std::shared_ptr<JInputStreamImpl> in;
    int32_t read() override { return in->read(); }
    int32_t rd() { int v = in->read(); if (v < 0) throw JEOFException(); return v; }
    int8_t readByte() { return (int8_t)rd(); }
    int32_t readUnsignedByte() { return rd(); }
    bool readBoolean() { return rd() != 0; }
    int16_t readShort() { int a = rd(), b = rd(); return (int16_t)((a << 8) | b); }
    int32_t readUnsignedShort() { int a = rd(), b = rd(); return (a << 8) | b; }
    char16_t readChar() { return (char16_t)readUnsignedShort(); }
    int32_t readInt() { uint32_t a = rd(), b = rd(), c = rd(), d = rd(); return (int32_t)((a << 24) | (b << 16) | (c << 8) | d); }
    int64_t readLong() { uint64_t h = (uint32_t)readInt(), l = (uint32_t)readInt(); return (int64_t)((h << 32) | l); }
    int32_t skipBytes(int32_t n) { return (int32_t)in->skip(n); }
    int32_t read(Arr<int8_t> b, int32_t off, int32_t len) override { return in->read(b, off, len); }
    int32_t read(Arr<int8_t> b) { return in->read(b, 0, b.length()); }
    void readFully(Arr<int8_t> b) { for (int i = 0; i < b.length(); i++) b[i] = readByte(); }
    int64_t skip(int64_t n) override { return in->skip(n); }
    std::vector<uint8_t> rest() override { return in->rest(); }
    JString readUTF() {
        int n = readUnsignedShort(); std::u16string s; int i = 0;
        while (i < n) {
            int a = rd(); i++;
            if (a < 0x80) s += (char16_t)a;
            else if ((a & 0xE0) == 0xC0) { int b = rd(); i++; s += (char16_t)(((a & 0x1F) << 6) | (b & 0x3F)); }
            else { int b = rd(), c = rd(); i += 2; s += (char16_t)(((a & 0x0F) << 12) | ((b & 0x3F) << 6) | (c & 0x3F)); }
        }
        return jrt_patch_text(std::move(s));
    }
    void close() override { in->close(); }
    bool markSupported() override { return in->markSupported(); }
    void mark(int32_t l) override { in->mark(l); }
    void reset() override { in->reset(); }
    int32_t available() override { return in->available(); }
};
struct JDataInputStream : std::shared_ptr<JDataInputStreamImpl> {
    using std::shared_ptr<JDataInputStreamImpl>::shared_ptr;
    JDataInputStream(const std::shared_ptr<JDataInputStreamImpl>& p) : std::shared_ptr<JDataInputStreamImpl>(p) {}
    static JDataInputStream make(const JInputStream& in) { if (!in) throw JNullPointerException(); auto p = std::make_shared<JDataInputStreamImpl>(); p->in = in; return JDataInputStream(p); }
    JDataInputStreamImpl* operator->() const { if (!get()) throw JNullPointerException(); return get(); }
    operator JInputStream() const { return JInputStream(std::static_pointer_cast<JInputStreamImpl>(*this)); }
};
struct JByteArrayOutputStreamImpl {
    std::vector<uint8_t> buf;
    void write(int32_t b) { buf.push_back((uint8_t)b); }
    void write(Arr<int8_t> b, int32_t off, int32_t len) { for (int i = 0; i < len; i++) buf.push_back((uint8_t)b[off + i]); }
    void write(Arr<int8_t> b) { write(b, 0, b.length()); }
    Arr<int8_t> toByteArray() { Arr<int8_t> a((int)buf.size()); if (!buf.empty()) memcpy(a.data(), buf.data(), buf.size()); return a; }
    int32_t size() { return (int32_t)buf.size(); }
    void close() {}
};
struct JByteArrayOutputStream : std::shared_ptr<JByteArrayOutputStreamImpl> {
    using std::shared_ptr<JByteArrayOutputStreamImpl>::shared_ptr;
    JByteArrayOutputStream(const std::shared_ptr<JByteArrayOutputStreamImpl>& p) : std::shared_ptr<JByteArrayOutputStreamImpl>(p) {}
    static JByteArrayOutputStream make(int32_t = 32) { return JByteArrayOutputStream(std::make_shared<JByteArrayOutputStreamImpl>()); }
};
struct JDataOutputStreamImpl {
    std::shared_ptr<JByteArrayOutputStreamImpl> out;
    void writeByte(int32_t v) { out->write(v); }
    void writeShort(int32_t v) { out->write(v >> 8); out->write(v); }
    void writeInt(int32_t v) { out->write(v >> 24); out->write(v >> 16); out->write(v >> 8); out->write(v); }
    void write(Arr<int8_t> b, int32_t off, int32_t len) { out->write(b, off, len); }
    void write(int32_t b) { out->write(b); }
    void close() {}
};
struct JDataOutputStream : std::shared_ptr<JDataOutputStreamImpl> {
    using std::shared_ptr<JDataOutputStreamImpl>::shared_ptr;
    JDataOutputStream(const std::shared_ptr<JDataOutputStreamImpl>& p) : std::shared_ptr<JDataOutputStreamImpl>(p) {}
    static JDataOutputStream make(const JByteArrayOutputStream& o) { auto p = std::make_shared<JDataOutputStreamImpl>(); p->out = o; return JDataOutputStream(p); }
};
// Reads a file of the original game (provided by the user) from the data folder.
bool jrt_read_resource(const std::string& name, std::vector<uint8_t>& out);
struct JClass {
    JInputStream getResourceAsStream(const JString& name) {
        std::string n = name.utf8(); while (!n.empty() && n[0] == '/') n.erase(0, 1);
        auto p = std::make_shared<JInputStreamImpl>();
        if (!jrt_read_resource(n, p->buf)) return nullptr;
        return JInputStream(p);
    }
};
inline std::shared_ptr<JClass> JObjectBase::getClass() { static auto c = std::make_shared<JClass>(); return c; }
inline std::shared_ptr<JClass> jgetclass() { static auto c = std::make_shared<JClass>(); return c; }

// ---------------- graphics ----------------
struct JImageImpl { int w = 0, h = 0; bool mut = false; std::vector<uint32_t> px; };
struct JFontImpl;
using JFont = std::shared_ptr<JFontImpl>;
struct JGraphicsImpl;
struct JGraphics : std::shared_ptr<JGraphicsImpl> {
    using std::shared_ptr<JGraphicsImpl>::shared_ptr;
    JGraphics(const std::shared_ptr<JGraphicsImpl>& p) : std::shared_ptr<JGraphicsImpl>(p) {}
};
struct JImage : std::shared_ptr<JImageImpl> {
    using std::shared_ptr<JImageImpl>::shared_ptr;
    JImage(const std::shared_ptr<JImageImpl>& p) : std::shared_ptr<JImageImpl>(p) {}
    const JImage* operator->() const { if (!get()) throw JNullPointerException(); return this; }
    static JImage createImage(int32_t w, int32_t h);
    static JImage createImage(Arr<int8_t> data, int32_t off, int32_t len);
    static JImage createImage(const JString& name);
    static JImage createImage(const JImage& src);
    static JImage createRGBImage(Arr<int32_t> rgb, int32_t w, int32_t h, bool alpha);
    int32_t getWidth() const { return get()->w; }
    int32_t getHeight() const { return get()->h; }
    JGraphics getGraphics() const;
    void getRGB(Arr<int32_t> out, int32_t off, int32_t scan, int32_t x, int32_t y, int32_t w, int32_t h) const;
};
struct JFontImpl {
    int face, style, size;
    static JFont getFont(int32_t face, int32_t style, int32_t size);
    int32_t getHeight();
    int32_t getBaselinePosition();
    int32_t charWidth(char16_t c);
    int32_t stringWidth(const JString& s);
    int32_t substringWidth(const JString& s, int32_t off, int32_t len);
    int32_t charsWidth(Arr<char16_t> c, int32_t off, int32_t len);
};
struct JFontStatic { static JFont getFont(int32_t f, int32_t s, int32_t z) { return JFontImpl::getFont(f, s, z); } };
#define JFont_getFont JFontImpl::getFont
struct JGraphicsImpl {
    std::shared_ptr<JImageImpl> img; uint32_t color = 0xff000000; int cx = 0, cy = 0, cw = 0, ch = 0, tx = 0, ty = 0; JFont font;
    void setColor(int32_t c) { color = 0xff000000u | (uint32_t)(c & 0xffffff); }
    void setColor(int32_t r, int32_t g, int32_t b) { setColor(((r & 255) << 16) | ((g & 255) << 8) | (b & 255)); }
    int32_t getColor() { return (int32_t)(color & 0xffffff); }
    void setClip(int32_t x, int32_t y, int32_t w, int32_t h);
    void clipRect(int32_t x, int32_t y, int32_t w, int32_t h);
    int32_t getClipX() { return cx - tx; } int32_t getClipY() { return cy - ty; } int32_t getClipWidth() { return cw; } int32_t getClipHeight() { return ch; }
    void translate(int32_t x, int32_t y) { tx += x; ty += y; }
    int32_t getTranslateX() { return tx; } int32_t getTranslateY() { return ty; }
    void setFont(const JFont& f) { font = f; }
    JFont getFont() { return font; }
    void fillRect(int32_t x, int32_t y, int32_t w, int32_t h);
    void drawRect(int32_t x, int32_t y, int32_t w, int32_t h);
    void drawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
    void fillArc(int32_t x, int32_t y, int32_t w, int32_t h, int32_t start, int32_t arc);
    void fillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3);
    void drawImage(const JImage& im, int32_t x, int32_t y, int32_t anchor);
    void drawRegion(const JImage& im, int32_t sx, int32_t sy, int32_t w, int32_t h, int32_t transform, int32_t x, int32_t y, int32_t anchor);
    void drawRGB(Arr<int32_t> rgb, int32_t off, int32_t scan, int32_t x, int32_t y, int32_t w, int32_t h, bool alpha);
    void drawString(const JString& s, int32_t x, int32_t y, int32_t anchor) { drawSubstring(s, 0, s.length(), x, y, anchor); }
    void drawSubstring(const JString& s, int32_t off, int32_t len, int32_t x, int32_t y, int32_t anchor);
    void drawChar(char16_t c, int32_t x, int32_t y, int32_t anchor) { drawString(std::u16string(1, c), x, y, anchor); }
    // pixel helpers
    void blend(int x, int y, uint32_t argb);
    void span(int x0, int x1, int y, uint32_t argb);
    void polygon(const int* xs, const int* ys, int n, uint32_t argb);
};
inline JGraphics JImage::getGraphics() const {
    auto g = std::make_shared<JGraphicsImpl>(); g->img = *this; g->cw = get()->w; g->ch = get()->h; g->font = JFontImpl::getFont(0, 0, 0); return JGraphics(g);
}
struct JDirectGraphicsImpl {
    JGraphics g;
    void fillPolygon(Arr<int32_t> xs, int32_t xo, Arr<int32_t> ys, int32_t yo, int32_t n, int32_t argb);
    void fillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t argb);
    void drawImage(const JImage& im, int32_t x, int32_t y, int32_t anchor, int32_t manip);
    int32_t getAlphaComponent() { return 255; }
    int32_t getNativePixelFormat() { return 8888; }
};
using JDirectGraphics = std::shared_ptr<JDirectGraphicsImpl>;
struct JDirectUtils {
    static JDirectGraphics getDirectGraphics(const JGraphics& g) { auto d = std::make_shared<JDirectGraphicsImpl>(); d->g = g; return d; }
    static JImage createImage(int32_t w, int32_t h, int32_t argb);
};

// ---------------- media / storage / platform ----------------
struct JVolumeControlImpl { int level = 100; int32_t setLevel(int32_t l); int32_t getLevel() { return level; } };
using JVolumeControl = std::shared_ptr<JVolumeControlImpl>;
struct JPlayerImpl {
    // MIDP Player states: CLOSED 0, UNREALIZED 100, REALIZED 200, PREFETCHED 300, STARTED 400
    std::vector<uint8_t> midi; int loops = 1; int state = 100; JVolumeControl vol;
    void realize() { if (state < 200) state = 200; }
    void prefetch() { if (state < 300) state = 300; }
    void start(); void stop(); void close(); void deallocate() { stop(); state = 200; }
    void setLoopCount(int32_t n) { loops = n; }
    int32_t getState() { return state; }
    JVolumeControl getControl(const JString&) { if (!vol) vol = std::make_shared<JVolumeControlImpl>(); return vol; }
    int64_t getMediaTime() { return 0; }
};
using JPlayer = std::shared_ptr<JPlayerImpl>;
struct JManager {
    static JPlayer createPlayer(const JInputStream& in, const JString& type) {
        auto p = std::make_shared<JPlayerImpl>(); p->midi = in->rest(); (void)type; return p;
    }
};
struct JRecordStoreImpl {
    std::string name; std::vector<std::vector<uint8_t>> recs;
    int32_t getNumRecords() { return (int32_t)recs.size(); }
    Arr<int8_t> getRecord(int32_t id);
    void setRecord(int32_t id, Arr<int8_t> d, int32_t off, int32_t len);
    int32_t addRecord(Arr<int8_t> d, int32_t off, int32_t len);
    void closeRecordStore() {}
    void save();
};
struct JRecordStore : std::shared_ptr<JRecordStoreImpl> {
    using std::shared_ptr<JRecordStoreImpl>::shared_ptr;
    JRecordStore(const std::shared_ptr<JRecordStoreImpl>& p) : std::shared_ptr<JRecordStoreImpl>(p) {}
    static JRecordStore openRecordStore(const JString& name, bool create);
};
struct JSystem {
    static int64_t currentTimeMillis();
    static void arraycopy(const Obj& src, int32_t so, const Obj& dst, int32_t d, int32_t n);
    template<class T> static void arraycopy(const Arr<T>& s, int32_t so, const Arr<T>& d, int32_t dof, int32_t n) {
        if (!s.p || !d.p) throw JNullPointerException();
        if (n < 0 || so < 0 || dof < 0 || so + n > s.length() || dof + n > d.length()) throw JArrayIndexOutOfBoundsException();
        if (s.p == d.p && so < dof) { for (int i = n - 1; i >= 0; i--) d.p->d[dof + i] = s.p->d[so + i]; }
        else for (int i = 0; i < n; i++) d.p->d[dof + i] = s.p->d[so + i];
    }
    static void gc() {}
    static void exit(int32_t);
    static JString getProperty(const JString& k);
};
struct JThreadImpl { JObjectBase* r = nullptr; void start(); };
struct JThread : std::shared_ptr<JThreadImpl> {
    using std::shared_ptr<JThreadImpl>::shared_ptr;
    JThread(const std::shared_ptr<JThreadImpl>& p) : std::shared_ptr<JThreadImpl>(p) {}
    static JThread make(JObjectBase* r) { auto t = std::make_shared<JThreadImpl>(); t->r = r; return JThread(t); }
    static void sleep(int64_t ms);
};
struct JDeviceControl { static void setLights(int32_t, int32_t) {} static void startVibra(int32_t, int64_t); static void stopVibra(); };

struct JMIDletBase : JObjectBase {
    virtual void startApp() {} virtual void pauseApp() {} virtual void destroyApp(bool) {}
    JString getAppProperty(const JString& k) { if (getenv("BT_CHEATS") && k.equals(JS(u"Cheats"))) return JS(u"On"); return nullptr; }
    void notifyDestroyed(); void notifyPaused() {}
    bool platformRequest(const JString&) { return false; }
};
using JMIDlet = JMIDletBase*;
struct JGameCanvasBase : JObjectBase {
    explicit JGameCanvasBase(bool suppress = false) { (void)suppress; }
    virtual void run() {}
    virtual void keyPressed(int32_t) {} virtual void keyReleased(int32_t) {} virtual void keyRepeated(int32_t) {}
    virtual void showNotify() {} virtual void hideNotify() {}
    virtual void paint(JGraphics) {}
    virtual void sizeChanged(int32_t, int32_t) {}
    JGraphics getGraphics();
    void flushGraphics();
    int32_t getWidth(); int32_t getHeight();
    void setFullScreenMode(bool) {}
    void repaint() {} void serviceRepaints() {}
    int32_t getKeyStates() { return 0; }
    bool isShown() { return true; }
    int32_t getGameAction(int32_t key);
    bool hasPointerEvents() { return false; }
};
using JGameCanvas = JGameCanvasBase*;
struct JDisplayImpl { void setCurrent(JGameCanvasBase*) {} bool vibrate(int32_t ms); bool flashBacklight(int32_t) { return true; } };
using JDisplay_ = std::shared_ptr<JDisplayImpl>;
struct JDisplay { static JDisplay_ getDisplay(JMIDletBase*) { static auto d = std::make_shared<JDisplayImpl>(); return d; } };
struct JCommandImpl {};
using JCommand = std::shared_ptr<JCommandImpl>;
struct JObjectBase;
using JRunnable = JObjectBase*;
using JDisplayable = JObjectBase*;
template<class T> Arr<Obj> jarr_obj(const Arr<T>& a) { if (a == nullptr) return nullptr; Arr<Obj> r(a.length()); for (int i = 0; i < a.length(); i++) r[i] = Obj(a[i]); return r; }
