/*
 * Bounce Tales PS5 port: SDL implementation of the J2ME runtime (graphics, text,
 * MIDI audio, record stores, input and the game thread).
 * PS5 port contributions: Youss Riaal, 2026. SPDX-License-Identifier: GPL-3.0-only
 */
#include "platform.hpp"
#include "game.hpp"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include "stb_image.h"
#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"
#define TSF_IMPLEMENTATION
#include "tsf.h"
#define TML_IMPLEMENTATION
#include "tml.h"
#include <chrono>
#include <map>
#include <mutex>

Platform P;
void platform_text_touch_all(JImageImpl* img);

// ---------------- resources ----------------
bool jrt_read_resource(const std::string& name, std::vector<uint8_t>& out) {
    auto it = P.files.find(name);
    if (it != P.files.end()) { out = it->second; return true; }
    FILE* f = fopen((P.asset_dir + "/" + name).c_str(), "rb");
    if (!f) return false;
    fseek(f, 0, SEEK_END); long n = ftell(f); fseek(f, 0, SEEK_SET);
    out.resize(n > 0 ? n : 0); bool ok = n <= 0 || fread(out.data(), 1, n, f) == (size_t)n; fclose(f); return ok;
}

// ---------------- game text ----------------
// The English instructions name phone keys; name the DualSense buttons instead.
JString jrt_patch_text(std::u16string s) {
    static const std::pair<const char16_t*, const char16_t*> repl[] = {
        {u"Press '4' and '6' (or the left and right navigation key) to move Bounce. Number keys '2' and '5' (or the up navigation key and middle softkey) both make Bounce jump.",
         u"Move Bounce with the left stick or the directional buttons. Press Cross (or up) to make Bounce jump."},
        {u"it can be selected using the '*' key.", u"it can be selected with the Square button."},
        {u"To change form, press the '*' key.", u"To change form, press Square."},
        {u"A cannon which you have entered can be directed with the number keys '2' and '8' (or the up and down navigation keys). Pressing '5' (or the middle softkey) fires the cannon.",
         u"A cannon which you have entered can be aimed with up and down. Press Cross to fire the cannon."},
    };
    for (auto& r : repl) { size_t p = s.find(r.first); if (p != std::u16string::npos) s.replace(p, std::char_traits<char16_t>::length(r.first), r.second); }
    return JString(std::move(s));
}

// ---------------- images ----------------
static std::shared_ptr<JImageImpl> new_image(int w, int h, uint32_t fill) {
    auto im = std::make_shared<JImageImpl>(); im->w = w; im->h = h; im->px.assign((size_t)w * h, fill); return im;
}
JImage JImage::createImage(int32_t w, int32_t h) {
    if (w <= 0 || h <= 0) throw JIllegalArgumentException();
    auto im = new_image(w, h, 0xffffffff); im->mut = true; return JImage(im);
}
static JImage decode_png(const uint8_t* d, int n) {
    int w, h, c; unsigned char* px = stbi_load_from_memory(d, n, &w, &h, &c, 4);
    if (!px) throw JIllegalArgumentException();
    auto im = new_image(w, h, 0);
    for (int i = 0; i < w * h; i++) im->px[i] = ((uint32_t)px[i * 4 + 3] << 24) | ((uint32_t)px[i * 4] << 16) | ((uint32_t)px[i * 4 + 1] << 8) | px[i * 4 + 2];
    stbi_image_free(px); return JImage(im);
}
JImage JImage::createImage(Arr<int8_t> data, int32_t off, int32_t len) {
    if (off < 0 || len < 0 || off + len > data.length()) throw JArrayIndexOutOfBoundsException();
    return decode_png((const uint8_t*)data.data() + off, len);
}
JImage JImage::createImage(const JString& name) {
    std::vector<uint8_t> d; std::string n = name.utf8(); while (!n.empty() && n[0] == '/') n.erase(0, 1);
    if (!jrt_read_resource(n, d)) throw JIOException();
    return decode_png(d.data(), (int)d.size());
}
JImage JImage::createImage(const JImage& src) {
    if (!src) throw JNullPointerException();
    if (!src.get()->mut) return src;
    auto im = std::make_shared<JImageImpl>(*src.get()); im->mut = false; return JImage(im);
}
JImage JImage::createRGBImage(Arr<int32_t> rgb, int32_t w, int32_t h, bool alpha) {
    auto im = new_image(w, h, 0);
    for (int i = 0; i < w * h; i++) { uint32_t v = (uint32_t)rgb[i]; im->px[i] = alpha ? v : (v | 0xff000000u); }
    return JImage(im);
}
void JImage::getRGB(Arr<int32_t> out, int32_t off, int32_t scan, int32_t x, int32_t y, int32_t w, int32_t h) const {
    auto* im = get(); platform_text_touch_all(im);
    if (x < 0 || y < 0 || x + w > im->w || y + h > im->h) throw JIllegalArgumentException();
    for (int j = 0; j < h; j++) for (int i = 0; i < w; i++) out[off + j * scan + i] = (int32_t)im->px[(size_t)(y + j) * im->w + x + i];
}
JImage JDirectUtils::createImage(int32_t w, int32_t h, int32_t argb) { auto im = new_image(w, h, (uint32_t)argb); im->mut = true; return JImage(im); }

// ---------------- graphics ----------------
static inline void text_touch(JImageImpl* img, int x0, int y0, int x1, int y1);
void JGraphicsImpl::setClip(int32_t x, int32_t y, int32_t w, int32_t h) {
    x += tx; y += ty;
    int x0 = std::max(0, x), y0 = std::max(0, y), x1 = std::min(img->w, x + std::max(0, w)), y1 = std::min(img->h, y + std::max(0, h));
    cx = x0; cy = y0; cw = std::max(0, x1 - x0); ch = std::max(0, y1 - y0);
}
void JGraphicsImpl::clipRect(int32_t x, int32_t y, int32_t w, int32_t h) {
    x += tx; y += ty;
    int x0 = std::max(cx, x), y0 = std::max(cy, y), x1 = std::min(cx + cw, x + std::max(0, w)), y1 = std::min(cy + ch, y + std::max(0, h));
    cx = x0; cy = y0; cw = std::max(0, x1 - x0); ch = std::max(0, y1 - y0);
}
static inline uint32_t blend_px(uint32_t dst, uint32_t src) {
    uint32_t a = src >> 24;
    if (a == 255) return src;
    if (a == 0) return dst;
    uint32_t da = dst >> 24, ia = 255 - a;
    uint32_t r = (((src >> 16) & 255) * a + ((dst >> 16) & 255) * ia) / 255;
    uint32_t g = (((src >> 8) & 255) * a + ((dst >> 8) & 255) * ia) / 255;
    uint32_t b = ((src & 255) * a + (dst & 255) * ia) / 255;
    uint32_t oa = a + da * ia / 255;
    return (oa << 24) | (r << 16) | (g << 8) | b;
}
void JGraphicsImpl::blend(int x, int y, uint32_t argb) {
    if (x < cx || y < cy || x >= cx + cw || y >= cy + ch) return;
    uint32_t& d = img->px[(size_t)y * img->w + x]; d = blend_px(d, argb);
}
void JGraphicsImpl::span(int x0, int x1, int y, uint32_t argb) {
    if (y < cy || y >= cy + ch) return;
    x0 = std::max(x0, cx); x1 = std::min(x1, cx + cw);
    uint32_t* row = &img->px[(size_t)y * img->w];
    if ((argb >> 24) == 255) for (int x = x0; x < x1; x++) row[x] = argb;
    else for (int x = x0; x < x1; x++) row[x] = blend_px(row[x], argb);
}
void JGraphicsImpl::fillRect(int32_t x, int32_t y, int32_t w, int32_t h) {
    if (w <= 0 || h <= 0) return; x += tx; y += ty;
    text_touch(img.get(), x, y, x + w, y + h);
    for (int j = std::max(y, cy); j < std::min(y + h, cy + ch); j++) span(x, x + w, j, color);
}
void JGraphicsImpl::drawRect(int32_t x, int32_t y, int32_t w, int32_t h) {
    if (w < 0 || h < 0) return;
    fillRect(x, y, w + 1, 1); fillRect(x, y + h, w + 1, 1); fillRect(x, y, 1, h + 1); fillRect(x + w, y, 1, h + 1);
}
void JGraphicsImpl::drawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    x1 += tx; y1 += ty; x2 += tx; y2 += ty;
    text_touch(img.get(), std::min(x1, x2), std::min(y1, y2), std::max(x1, x2) + 1, std::max(y1, y2) + 1);
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1, dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1, e = dx + dy;
    for (;;) { blend(x1, y1, color); if (x1 == x2 && y1 == y2) break; int e2 = 2 * e; if (e2 >= dy) { e += dy; x1 += sx; } if (e2 <= dx) { e += dx; y1 += sy; } }
}
void JGraphicsImpl::fillArc(int32_t x, int32_t y, int32_t w, int32_t h, int32_t start, int32_t arc) {
    if (w <= 0 || h <= 0 || arc == 0) return; x += tx; y += ty;
    text_touch(img.get(), x, y, x + w, y + h);
    double rx = w / 2.0, ry = h / 2.0, ox = x + rx, oy = y + ry;
    bool full = arc >= 360 || arc <= -360;
    double a0 = start, a1 = start + arc; if (a1 < a0) std::swap(a0, a1);
    for (int j = std::max(y, cy); j < std::min(y + h, cy + ch); j++) {
        double py = (j + 0.5 - oy) / ry;
        for (int i = std::max(x, cx); i < std::min(x + w, cx + cw); i++) {
            double px = (i + 0.5 - ox) / rx;
            if (px * px + py * py > 1.0) continue;
            if (!full) {
                double ang = atan2(-py * ry, px * rx) * 180.0 / M_PI; // counter-clockwise from 3 o'clock
                double t = fmod(ang - a0, 360.0); if (t < 0) t += 360.0;
                if (t > a1 - a0) continue;
            }
            blend(i, j, color);
        }
    }
}
void JGraphicsImpl::polygon(const int* xs, const int* ys, int n, uint32_t argb) {
    if (n < 3) return;
    int miny = INT_MAX, maxy = INT_MIN;
    int minx = INT_MAX, maxx = INT_MIN;
    for (int i = 0; i < n; i++) { miny = std::min(miny, ys[i]); maxy = std::max(maxy, ys[i]); minx = std::min(minx, xs[i]); maxx = std::max(maxx, xs[i]); }
    text_touch(img.get(), minx, miny, maxx + 1, maxy + 1);
    std::vector<double> xsx;
    for (int y = std::max(miny, cy); y <= std::min(maxy, cy + ch - 1); y++) {
        double sy = y + 0.5; xsx.clear();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n; double y0 = ys[i], y1 = ys[j];
            if ((sy >= y0 && sy < y1) || (sy >= y1 && sy < y0)) xsx.push_back(xs[i] + (sy - y0) * (xs[j] - xs[i]) / (y1 - y0));
        }
        std::sort(xsx.begin(), xsx.end());
        for (size_t k = 0; k + 1 < xsx.size(); k += 2) span((int)ceil(xsx[k] - 0.5), (int)ceil(xsx[k + 1] - 0.5), y, argb);
    }
}
void JGraphicsImpl::fillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3) {
    int xs[3] = {x1 + tx, x2 + tx, x3 + tx}, ys[3] = {y1 + ty, y2 + ty, y3 + ty}; polygon(xs, ys, 3, color);
}
static void anchor_pos(int& x, int& y, int w, int h, int anchor) {
    if (anchor & 1) x -= w / 2; else if (anchor & 8) x -= w;
    if (anchor & 2) y -= h / 2; else if (anchor & 32) y -= h;
}
void JGraphicsImpl::drawImage(const JImage& im, int32_t x, int32_t y, int32_t anchor) {
    if (!im) throw JNullPointerException();
    drawRegion(im, 0, 0, im.get()->w, im.get()->h, 0, x, y, anchor);
}
void JGraphicsImpl::drawRegion(const JImage& imh, int32_t sx, int32_t sy, int32_t w, int32_t h, int32_t tr, int32_t x, int32_t y, int32_t anchor) {
    if (!imh) throw JNullPointerException();
    auto* im = imh.get();
    if (sx < 0 || sy < 0 || w < 0 || h < 0 || sx + w > im->w || sy + h > im->h) throw JIllegalArgumentException();
    bool swap = tr >= 4; int dw = swap ? h : w, dh = swap ? w : h;
    x += tx; y += ty; anchor_pos(x, y, dw, dh, anchor);
    text_touch(img.get(), x, y, x + dw, y + dh);
    if (im == P.back.get()) platform_text_touch_all(im);
    int x0 = std::max(x, cx), y0 = std::max(y, cy), x1 = std::min(x + dw, cx + cw), y1 = std::min(y + dh, cy + ch);
    const bool same = im == img.get();
    std::vector<uint32_t> copy; const uint32_t* src = im->px.data();
    if (same) { copy = im->px; src = copy.data(); }
    for (int j = y0; j < y1; j++) {
        uint32_t* row = &img->px[(size_t)j * img->w];
        for (int i = x0; i < x1; i++) {
            int u = i - x, v = j - y, s, t; // u,v in destination space
            switch (tr) {
                case 0: s = u; t = v; break;                       // NONE
                case 1: s = u; t = h - 1 - v; break;               // MIRROR_ROT180
                case 2: s = w - 1 - u; t = v; break;               // MIRROR
                case 3: s = w - 1 - u; t = h - 1 - v; break;       // ROT180
                case 4: s = v; t = u; break;                       // MIRROR_ROT270
                case 5: s = v; t = h - 1 - u; break;               // ROT90
                case 6: s = w - 1 - v; t = u; break;               // ROT270
                default: s = w - 1 - v; t = h - 1 - u; break;      // MIRROR_ROT90
            }
            uint32_t p = src[(size_t)(sy + t) * im->w + sx + s];
            row[i] = blend_px(row[i], p);
        }
    }
}
void JGraphicsImpl::drawRGB(Arr<int32_t> rgb, int32_t off, int32_t scan, int32_t x, int32_t y, int32_t w, int32_t h, bool alpha) {
    x += tx; y += ty;
    text_touch(img.get(), x, y, x + w, y + h);
    for (int j = std::max(y, cy); j < std::min(y + h, cy + ch); j++)
        for (int i = std::max(x, cx); i < std::min(x + w, cx + cw); i++) {
            uint32_t p = (uint32_t)rgb[off + (j - y) * scan + (i - x)]; if (!alpha) p |= 0xff000000u;
            uint32_t& d = img->px[(size_t)j * img->w + i]; d = blend_px(d, p);
        }
}
void JDirectGraphicsImpl::fillPolygon(Arr<int32_t> xs, int32_t xo, Arr<int32_t> ys, int32_t yo, int32_t n, int32_t argb) {
    std::vector<int> X(n), Y(n); for (int i = 0; i < n; i++) { X[i] = xs[xo + i] + g->tx; Y[i] = ys[yo + i] + g->ty; }
    g->polygon(X.data(), Y.data(), n, (uint32_t)argb);
}
void JDirectGraphicsImpl::fillTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t argb) {
    int xs[3] = {x1 + g->tx, x2 + g->tx, x3 + g->tx}, ys[3] = {y1 + g->ty, y2 + g->ty, y3 + g->ty}; g->polygon(xs, ys, 3, (uint32_t)argb);
}
void JDirectGraphicsImpl::drawImage(const JImage& im, int32_t x, int32_t y, int32_t anchor, int32_t manip) {
    int tr = 0; bool fh = manip & 0x2000, fv = manip & 0x4000; int rot = manip & 0x1ff;
    if (rot == 0) tr = fh && fv ? 3 : fh ? 2 : fv ? 1 : 0;
    else if (rot == 180) tr = fh && fv ? 0 : fh ? 1 : fv ? 2 : 3;
    else if (rot == 90) tr = fh ? 4 : 6;
    else tr = fh ? 7 : 5;
    g->drawRegion(im, 0, 0, im.get()->w, im.get()->h, tr, x, y, anchor);
}

// ---------------- fonts ----------------
struct FontFile { std::vector<uint8_t> data; stbtt_fontinfo info; bool ok = false; };
static FontFile font_files[4];
static FontFile& font_for(int style) {
    FontFile& f = font_files[(style & 1 ? 1 : 0) | (style & 2 ? 2 : 0)];
    if (!f.ok) { FontFile& r = font_files[0]; return r; }
    return f;
}
void platform_load_fonts(const std::string& dir) {
    const char* names[4] = {"font-regular.ttf", "font-bold.ttf", "font-italic.ttf", "font-bolditalic.ttf"};
    for (int i = 0; i < 4; i++) {
        FILE* fp = fopen((dir + "/" + names[i]).c_str(), "rb"); if (!fp) continue;
        fseek(fp, 0, SEEK_END); long n = ftell(fp); fseek(fp, 0, SEEK_SET);
        font_files[i].data.resize(n); if (fread(font_files[i].data.data(), 1, n, fp) != (size_t)n) { fclose(fp); continue; } fclose(fp);
        font_files[i].ok = stbtt_InitFont(&font_files[i].info, font_files[i].data.data(), 0) != 0;
    }
    if (!font_files[0].ok) fprintf(stderr, "Font: %s/font-regular.ttf missing; text will not be drawn\n", dir.c_str());
}
static int font_px(int size) { return size == 8 ? 13 : size == 16 ? 17 : 15; }
struct FontMetrics { float scale; int ascent, descent, height; };
static FontMetrics metrics(int style, int size) {
    FontFile& f = font_for(style); FontMetrics m{};
    if (!f.ok) { m.ascent = 12; m.descent = 3; m.height = 16; m.scale = 1; return m; }
    m.scale = stbtt_ScaleForMappingEmToPixels(&f.info, (float)font_px(size));
    int a, d, l; stbtt_GetFontVMetrics(&f.info, &a, &d, &l);
    m.ascent = (int)ceil(a * m.scale); m.descent = (int)ceil(-d * m.scale); m.height = m.ascent + m.descent + (int)ceil(l * m.scale);
    return m;
}
JFont JFontImpl::getFont(int32_t face, int32_t style, int32_t size) { auto f = std::make_shared<JFontImpl>(); f->face = face; f->style = style; f->size = size; return f; }
int32_t JFontImpl::getHeight() { return metrics(style, size).height; }
int32_t JFontImpl::getBaselinePosition() { return metrics(style, size).ascent; }
static float advance(int style, int size, char16_t c) {
    FontFile& f = font_for(style); if (!f.ok) return 7;
    int adv, lsb; stbtt_GetCodepointHMetrics(&f.info, c, &adv, &lsb); return adv * metrics(style, size).scale;
}
static int text_width(int style, int size, const char16_t* s, int n) {
    float w = 0; for (int i = 0; i < n; i++) w += advance(style, size, s[i]); return (int)lroundf(w);
}
int32_t JFontImpl::charWidth(char16_t c) { return text_width(style, size, &c, 1); }
int32_t JFontImpl::stringWidth(const JString& s) { auto& v = s.str(); return text_width(style, size, v.data(), (int)v.size()); }
int32_t JFontImpl::substringWidth(const JString& s, int32_t off, int32_t len) { auto& v = s.str(); if (off < 0 || len < 0 || off + len > (int)v.size()) throw JArrayIndexOutOfBoundsException(); return text_width(style, size, v.data() + off, len); }
int32_t JFontImpl::charsWidth(Arr<char16_t> c, int32_t off, int32_t len) { return text_width(style, size, c.data() + off, len); }
// Glyph bitmaps are cached: the game redraws its text every frame.
struct Glyph { int x0 = 0, y0 = 0, w = 0, h = 0; std::vector<uint8_t> a; };
static std::map<uint64_t, Glyph> glyph_cache;
static const Glyph& glyph(int style, int px, int sub, char16_t c) {
    uint64_t key = ((uint64_t)(style & 3) << 40) | ((uint64_t)px << 24) | ((uint64_t)sub << 16) | c;
    auto it = glyph_cache.find(key); if (it != glyph_cache.end()) return it->second;
    if (glyph_cache.size() > 20000) glyph_cache.clear();
    Glyph& g = glyph_cache[key]; FontFile& f = font_for(style);
    float sc = stbtt_ScaleForMappingEmToPixels(&f.info, (float)px), sxf = sub / 4.f; int x1, y1;
    stbtt_GetCodepointBitmapBoxSubpixel(&f.info, c, sc, sc, sxf, 0, &g.x0, &g.y0, &x1, &y1);
    g.w = std::max(0, x1 - g.x0); g.h = std::max(0, y1 - g.y0);
    if (g.w && g.h) { g.a.resize((size_t)g.w * g.h); stbtt_MakeCodepointBitmapSubpixel(&f.info, g.a.data(), g.w, g.h, g.w, sc, sc, sxf, 0, c); }
    return g;
}
// Draws text with the layout of the game's font size, magnified mult times.
// x and base are in target pixels; put(x, y, alpha) writes one pixel.
template<class Put> static void raster_text(int style, int size, int mult, const char16_t* s, int n, float x, int base, Put put) {
    FontFile& f = font_for(style); if (!f.ok) return;
    int px = font_px(size) * mult; float pen = x;
    for (int i = 0; i < n; i++) {
        float fl = floorf(pen); int sub = (int)((pen - fl) * 4) & 3;
        const Glyph& g = glyph(style, px, sub, s[i]);
        int gx = (int)fl + g.x0, gy = base + g.y0;
        for (int j = 0; j < g.h; j++) for (int k = 0; k < g.w; k++) { unsigned a = g.a[(size_t)j * g.w + k]; if (a) put(gx + k, gy + j, a); }
        pen += advance(style, size, s[i]) * mult;
    }
}

// Text drawn on the game screen is kept aside and drawn after the screen has been
// enlarged, at full resolution, so it stays sharp. If the game later draws over it,
// it is drawn at the game's resolution at that moment instead, keeping the order.
struct TextOp { std::u16string s; int style, size; float x; int base; uint32_t color; int cx, cy, cw, ch; int bx0, by0, bx1, by1; };
static std::vector<TextOp> pending_text, shown_text;
bool platform_hires_text = true;
static void raster_lowres(JImageImpl* img, const TextOp& t) {
    raster_text(t.style, t.size, 1, t.s.data(), (int)t.s.size(), t.x, t.base, [&](int x, int y, unsigned a) {
        if (x < t.cx || y < t.cy || x >= t.cx + t.cw || y >= t.cy + t.ch) return;
        uint32_t& d = img->px[(size_t)y * img->w + x]; d = blend_px(d, (t.color & 0xffffff) | (a << 24));
    });
}
static void flush_text(JImageImpl* img) { for (auto& t : pending_text) raster_lowres(img, t); pending_text.clear(); }
static inline void text_touch(JImageImpl* img, int x0, int y0, int x1, int y1) {
    if (pending_text.empty() || img != P.back.get()) return;
    for (auto& t : pending_text) if (x0 < t.bx1 && x1 > t.bx0 && y0 < t.by1 && y1 > t.by0) { flush_text(img); return; }
}
void platform_text_touch_all(JImageImpl* img) { if (img == P.back.get()) flush_text(img); }
// Draws the pending text onto the enlarged frame (ARGB, mult times the game screen).
void platform_render_text(uint32_t* frame, int fw, int fh, int mult) {
    for (auto& t : pending_text) {
        int cx0 = t.cx * mult, cy0 = t.cy * mult, cx1 = std::min(fw, (t.cx + t.cw) * mult), cy1 = std::min(fh, (t.cy + t.ch) * mult);
        raster_text(t.style, t.size, mult, t.s.data(), (int)t.s.size(), t.x * mult, t.base * mult, [&](int x, int y, unsigned a) {
            if (x < cx0 || y < cy0 || x >= cx1 || y >= cy1) return;
            uint32_t& d = frame[(size_t)y * fw + x]; d = blend_px(d, (t.color & 0xffffff) | (a << 24));
        });
    }
    shown_text.swap(pending_text); pending_text.clear();
}
// A copy of the last shown game screen with its text drawn in (for screenshots).
std::vector<uint32_t> platform_screen_copy() {
    JImageImpl copy = *P.back.get(); for (auto& t : shown_text) raster_lowres(&copy, t); for (auto& t : pending_text) raster_lowres(&copy, t); return copy.px;
}
void JGraphicsImpl::drawSubstring(const JString& s, int32_t off, int32_t len, int32_t x, int32_t y, int32_t anchor) {
    auto& v = s.str(); if (off < 0 || len < 0 || off + len > (int)v.size()) throw JArrayIndexOutOfBoundsException();
    int style = font ? font->style : 0, size = font ? font->size : 0;
    FontFile& f = font_for(style); if (!f.ok || len == 0) return;
    FontMetrics m = metrics(style, size);
    int w = text_width(style, size, v.data() + off, len);
    x += tx; y += ty;
    if (anchor & 1) x -= w / 2; else if (anchor & 8) x -= w;
    int base = y + m.ascent; if (anchor & 64) base = y; else if (anchor & 32) base = y + m.ascent - m.height;
    TextOp t{v.substr(off, len), style, size, (float)x, base, color, cx, cy, cw, ch, x - 2, base - m.ascent - 2, x + w + 3, base + m.descent + 3};
    t.bx0 = std::max(t.bx0, cx); t.by0 = std::max(t.by0, cy); t.bx1 = std::min(t.bx1, cx + cw); t.by1 = std::min(t.by1, cy + ch);
    if (t.bx0 >= t.bx1 || t.by0 >= t.by1) return;
    if (platform_hires_text && img.get() == P.back.get()) { pending_text.push_back(std::move(t)); return; }
    text_touch(img.get(), t.bx0, t.by0, t.bx1, t.by1);
    raster_lowres(img.get(), t);
}

// ---------------- audio ----------------
static tsf* synth_base = nullptr;
static SDL_AudioDeviceID audio_dev = 0;
struct Voice { JPlayerImpl* owner = nullptr; tsf* synth = nullptr; tml_message* midi = nullptr; tml_message* next = nullptr; double ms = 0; int loops = 1; float gain = 1; bool active = false; };
static Voice voices[2];
static void audio_cb(void*, Uint8* stream, int bytes) {
    float* out = (float*)stream; int frames = bytes / 8; memset(stream, 0, bytes);
    static std::vector<float> tmp; tmp.resize((size_t)frames * 2);
    for (auto& v : voices) {
        if (!v.active || !v.synth) continue;
        float* o = tmp.data(); int left = frames;
        while (left > 0) {
            int cnt = std::min(left, 64);
            while (v.next && v.next->time <= v.ms) {
                auto* m = v.next;
                if (m->type == TML_PROGRAM_CHANGE) tsf_channel_set_presetnumber(v.synth, m->channel, m->program, m->channel == 9);
                else if (m->type == TML_NOTE_ON) tsf_channel_note_on(v.synth, m->channel, m->key, m->velocity / 127.f);
                else if (m->type == TML_NOTE_OFF) tsf_channel_note_off(v.synth, m->channel, m->key);
                else if (m->type == TML_PITCH_BEND) tsf_channel_set_pitchwheel(v.synth, m->channel, m->pitch_bend);
                else if (m->type == TML_CONTROL_CHANGE) tsf_channel_midi_control(v.synth, m->channel, m->control, m->control_value);
                v.next = m->next;
            }
            if (!v.next) {
                if (v.loops == -1 || --v.loops > 0) { v.next = v.midi; v.ms = 0; }
                else if (v.ms > 0) { v.active = false; tsf_note_off_all(v.synth); if (v.owner) v.owner->state = 300; }
            }
            tsf_render_float(v.synth, o, cnt, 0);
            v.ms += cnt * 1000.0 / 44100.0; o += cnt * 2; left -= cnt;
        }
        float g = v.gain * P.music_volume;
        for (int i = 0; i < frames * 2; i++) out[i] += tmp[i] * g;
    }
}
void platform_init_audio(const std::string& sf2) {
    synth_base = tsf_load_filename(sf2.c_str());
    if (!synth_base) { fprintf(stderr, "Audio: soundfont %s missing\n", sf2.c_str()); return; }
    tsf_set_output(synth_base, TSF_STEREO_INTERLEAVED, 44100, 0);
    for (auto& v : voices) { v.synth = tsf_copy(synth_base); tsf_set_output(v.synth, TSF_STEREO_INTERLEAVED, 44100, 0); }
    SDL_AudioSpec want{}, have{}; want.freq = 44100; want.format = AUDIO_F32SYS; want.channels = 2; want.samples = 1024; want.callback = audio_cb;
    audio_dev = SDL_OpenAudioDevice(nullptr, 0, &want, &have, 0);
    if (audio_dev) SDL_PauseAudioDevice(audio_dev, 0);
}
void JPlayerImpl::start() {
    if (!audio_dev) { state = 400; return; }
    SDL_LockAudioDevice(audio_dev);
    Voice* slot = nullptr;
    for (auto& v : voices) if (v.owner == this) slot = &v;
    if (!slot) for (auto& v : voices) if (!v.active) { slot = &v; break; }
    if (!slot) slot = &voices[1];
    if (slot->owner && slot->owner != this) slot->owner->state = 300;
    if (slot->midi && slot->owner != this) { tml_free(slot->midi); slot->midi = nullptr; }
    if (!slot->midi) slot->midi = tml_load_memory(midi.data(), (int)midi.size());
    tsf_reset(slot->synth);
    slot->owner = this; slot->next = slot->midi; slot->ms = 0; slot->loops = loops; slot->gain = vol ? vol->level / 100.f : 1.f; slot->active = slot->midi != nullptr;
    state = 400;
    SDL_UnlockAudioDevice(audio_dev);
}
void JPlayerImpl::stop() {
    if (!audio_dev) return;
    SDL_LockAudioDevice(audio_dev);
    for (auto& v : voices) if (v.owner == this && v.active) { v.active = false; tsf_note_off_all(v.synth); }
    SDL_UnlockAudioDevice(audio_dev);
    if (state == 400) state = 300;
}
void JPlayerImpl::close() {
    if (audio_dev) SDL_LockAudioDevice(audio_dev);
    for (auto& v : voices) if (v.owner == this) { v.active = false; if (v.synth) tsf_note_off_all(v.synth); if (v.midi) tml_free(v.midi); v.midi = nullptr; v.next = nullptr; v.owner = nullptr; }
    if (audio_dev) SDL_UnlockAudioDevice(audio_dev);
    state = 0;
}
int32_t JVolumeControlImpl::setLevel(int32_t l) {
    level = std::clamp(l, 0, 100);
    if (audio_dev) { SDL_LockAudioDevice(audio_dev); for (auto& v : voices) if (v.owner && v.owner->vol.get() == this) v.gain = level / 100.f; SDL_UnlockAudioDevice(audio_dev); }
    return level;
}

// ---------------- record stores ----------------
static std::string rms_path(const std::string& n) {
    std::string safe; for (char c : n) safe += (isalnum((unsigned char)c) || c == '-' || c == '_') ? c : '_';
    return P.save_dir + "/" + safe + ".rms";
}
JRecordStore JRecordStore::openRecordStore(const JString& name, bool create) {
    auto rs = std::make_shared<JRecordStoreImpl>(); rs->name = name.utf8();
    FILE* f = fopen(rms_path(rs->name).c_str(), "rb");
    if (!f) { if (!create) throw JRecordStoreNotFoundException(); rs->save(); return JRecordStore(rs); }
    uint32_t n = 0; if (fread(&n, 4, 1, f) == 1 && n < 10000)
        for (uint32_t i = 0; i < n; i++) { uint32_t len = 0; if (fread(&len, 4, 1, f) != 1 || len > (1u << 24)) break; std::vector<uint8_t> d(len); if (len && fread(d.data(), 1, len, f) != len) break; rs->recs.push_back(d); }
    fclose(f); return JRecordStore(rs);
}
void JRecordStoreImpl::save() {
    std::string p = rms_path(name), tmp = p + ".new"; FILE* f = fopen(tmp.c_str(), "wb"); if (!f) return;
    uint32_t n = (uint32_t)recs.size(); bool ok = fwrite(&n, 4, 1, f) == 1;
    for (auto& r : recs) { uint32_t len = (uint32_t)r.size(); ok = ok && fwrite(&len, 4, 1, f) == 1 && (r.empty() || fwrite(r.data(), 1, r.size(), f) == r.size()); }
    ok = fclose(f) == 0 && ok;
    if (ok) { remove(p.c_str()); rename(tmp.c_str(), p.c_str()); } else remove(tmp.c_str());
}
Arr<int8_t> JRecordStoreImpl::getRecord(int32_t id) {
    if (id < 1 || id > (int)recs.size()) throw JRecordStoreException();
    auto& r = recs[id - 1]; if (r.empty()) return nullptr;
    Arr<int8_t> a((int)r.size()); memcpy(a.data(), r.data(), r.size()); return a;
}
void JRecordStoreImpl::setRecord(int32_t id, Arr<int8_t> d, int32_t off, int32_t len) {
    if (id < 1 || id > (int)recs.size()) throw JRecordStoreException();
    recs[id - 1].assign((uint8_t*)d.data() + off, (uint8_t*)d.data() + off + len); save();
}
int32_t JRecordStoreImpl::addRecord(Arr<int8_t> d, int32_t off, int32_t len) {
    recs.emplace_back(); if (len > 0) recs.back().assign((uint8_t*)d.data() + off, (uint8_t*)d.data() + off + len); save(); return (int32_t)recs.size();
}

// ---------------- system / threads ----------------
int64_t JSystem::currentTimeMillis() {
    if (P.fake_clock) return P.fake_ms;
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
void JSystem::exit(int32_t) { throw PlatformQuit(); }
JString JSystem::getProperty(const JString& k) {
    std::string key = k.utf8();
    if (key == "microedition.platform") return JS(u"Nokia6300/07.21");
    if (key == "microedition.locale") return JString(std::u16string(P.locale.begin(), P.locale.end()));
    return nullptr;
}
void JThreadImpl::start() {
    if (!P.main_runnable) { P.main_runnable = r; return; }
    // The game also starts a short-lived thread that animates the loading screen.
    // Loading is fast here, so that animation is skipped.
}
void JThread::sleep(int64_t ms) { platform_wait(ms); }
void JMIDletBase::notifyDestroyed() { throw PlatformQuit(); }
bool JDisplayImpl::vibrate(int32_t ms) { platform_rumble(ms); return true; }
void JDeviceControl::startVibra(int32_t, int64_t ms) { platform_rumble((int)ms); }
void JDeviceControl::stopVibra() { platform_rumble(0); }
JGraphics JGameCanvasBase::getGraphics() { return P.back.getGraphics(); }
int32_t JGameCanvasBase::getWidth() { return P.sw; }
int32_t JGameCanvasBase::getHeight() { return P.sh; }
void JGameCanvasBase::flushGraphics() { platform_present(); }
int32_t JGameCanvasBase::getGameAction(int32_t k) {
    switch (k) { case -1: case '2': return 1; case -2: case '8': return 6; case -3: case '4': return 2; case -4: case '6': return 5; case -5: case '5': return 8; default: return 0; }
}
