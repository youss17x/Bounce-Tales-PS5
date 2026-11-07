/*
 * Bounce Tales PS5 port: start-up, display, input and the user-supplied game files.
 * PS5 port contributions: Youss Riaal, 2026. SPDX-License-Identifier: GPL-3.0-only
 */
#include "platform.hpp"
#include "game.hpp"
#include "stb_image.h"
#include <dirent.h>
#include <sys/stat.h>

// ---------------- reading the original .jar ----------------
static uint32_t rd16(const uint8_t* p) { return p[0] | (p[1] << 8); }
static uint32_t rd32(const uint8_t* p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((uint32_t)p[3] << 24); }
bool load_jar(const std::string& path, std::map<std::string, std::vector<uint8_t>>& files) {
    FILE* f = fopen(path.c_str(), "rb"); if (!f) return false;
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    if (size < 22 || size > 64L * 1024 * 1024) { fclose(f); return false; }
    std::vector<uint8_t> z(size); bool ok = fread(z.data(), 1, size, f) == (size_t)size; fclose(f); if (!ok) return false;
    long eocd = -1; for (long i = size - 22; i >= 0 && i >= size - 22 - 65535; i--) if (rd32(&z[i]) == 0x06054b50) { eocd = i; break; }
    if (eocd < 0) return false;
    uint32_t count = rd16(&z[eocd + 10]), cd = rd32(&z[eocd + 16]);
    for (uint32_t n = 0, p = cd; n < count; n++) {
        if (p + 46 > (uint32_t)size || rd32(&z[p]) != 0x02014b50) break;
        uint32_t method = rd16(&z[p + 10]), csize = rd32(&z[p + 20]), usize = rd32(&z[p + 24]), nlen = rd16(&z[p + 28]), xlen = rd16(&z[p + 30]), clen = rd16(&z[p + 32]), local = rd32(&z[p + 42]);
        if (p + 46 + nlen > (uint32_t)size) break;
        std::string name((const char*)&z[p + 46], nlen); p += 46 + nlen + xlen + clen;
        if (name.empty() || name.back() == '/' || name.size() > 6 && name.compare(name.size() - 6, 6, ".class") == 0) continue;
        if (local + 30 > (uint32_t)size || rd32(&z[local]) != 0x04034b50) continue;
        uint32_t data = local + 30 + rd16(&z[local + 26]) + rd16(&z[local + 28]);
        if (data + csize > (uint32_t)size || usize > 16u * 1024 * 1024) continue;
        std::vector<uint8_t> out;
        if (method == 0) out.assign(&z[data], &z[data] + csize);
        else if (method == 8) { out.resize(usize ? usize : 1); int got = stbi_zlib_decode_noheader_buffer((char*)out.data(), (int)out.size(), (const char*)&z[data], (int)csize); if (got < 0 || (uint32_t)got != usize) continue; out.resize(got); }
        else continue;
        files[name] = std::move(out);
    }
    return files.count("a") && files.count("lang.xx");
}

// ---------------- display ----------------
// Edge-aware 2x enlargement (from Forgotten Warrior Remastered): keeps flat colours
// and rounds diagonal steps, then the renderer scales smoothly to the screen.
static void enlarge2x(const uint32_t* src, int w, int h, std::vector<uint32_t>& dst) {
    dst.resize((size_t)w * h * 4); const int ow = w * 2;
    for (int y = 0; y < h; y++) for (int x = 0; x < w; x++) {
        const uint32_t e = src[y * w + x], b = src[(y ? y - 1 : y) * w + x], d = src[y * w + (x ? x - 1 : x)], f = src[y * w + (x + 1 < w ? x + 1 : x)], hh = src[(y + 1 < h ? y + 1 : y) * w + x];
        uint32_t a = e, c = e, g = e, i = e;
        if (b != hh && d != f) { a = d == b ? d : e; c = b == f ? f : e; g = d == hh ? d : e; i = hh == f ? f : e; }
        const size_t p = (size_t)y * 2 * ow + x * 2; dst[p] = a; dst[p + 1] = c; dst[p + ow] = g; dst[p + ow + 1] = i;
    }
}
static SDL_Rect game_rect(int ow, int oh) { int h = oh, w = h * P.sw / P.sh; if (w > ow) { w = ow; h = w * P.sh / P.sw; } return SDL_Rect{(ow - w) / 2, (oh - h) / 2, w, h}; }
void platform_render_text(uint32_t* frame, int fw, int fh, int mult);
std::vector<uint32_t> platform_screen_copy();
extern bool platform_hires_text;
// The frame shown on screen: the game screen enlarged 4x (480x270 -> 1920x1080) with
// two edge-aware 2x passes, then the game's text drawn sharp at full resolution.
static std::vector<uint32_t> big, frame;
static void build_frame() {
    enlarge2x(P.back.get()->px.data(), P.sw, P.sh, big);
    enlarge2x(big.data(), P.sw * 2, P.sh * 2, frame);
    platform_render_text(frame.data(), P.sw * 4, P.sh * 4, 4);
}
static uint64_t last_present = 0;
void platform_present_frame() {
    if (P.headless) { if (platform_hires_text) build_frame(); return; }
    build_frame();
    const int fw = P.sw * 4, fh = P.sh * 4;
#ifdef BT_PS5
    // Written straight into the 1080p window surface (ABGR); the video driver waits
    // for the display's next refresh, which paces the game at 60 frames per second.
    SDL_Surface* s = SDL_GetWindowSurface(P.window);
    if (!s) return;
    const int ox = (s->w - fw) / 2, oy = (s->h - fh) / 2;
    for (int y = 0; y < fh; y++) {
        if (y + oy < 0 || y + oy >= s->h) continue;
        uint32_t* d = (uint32_t*)((uint8_t*)s->pixels + (size_t)(y + oy) * s->pitch) + std::max(0, ox);
        const uint32_t* sp = &frame[(size_t)y * fw] + std::max(0, -ox);
        for (int x = 0, n = std::min(fw, s->w); x < n; x++) { uint32_t v = sp[x]; d[x] = 0xff000000u | ((v & 0xff) << 16) | (v & 0xff00) | ((v >> 16) & 0xff); }
    }
    SDL_UpdateWindowSurface(P.window);
#else
    SDL_UpdateTexture(P.texture, nullptr, frame.data(), fw * 4);
    SDL_SetRenderDrawColor(P.renderer, 0, 0, 0, 255); SDL_RenderClear(P.renderer);
    int ow, oh; SDL_RenderGetLogicalSize(P.renderer, &ow, &oh); if (!ow) SDL_GetRendererOutputSize(P.renderer, &ow, &oh);
    SDL_Rect r = game_rect(ow, oh); SDL_RenderCopy(P.renderer, P.texture, nullptr, &r);
    SDL_RenderPresent(P.renderer);
#endif
}

// ---------------- scripted runs (host self-test) ----------------
struct ScriptCmd { std::string op; int arg; std::string name; };
static std::vector<ScriptCmd> script; static size_t script_pos = 0; static uint64_t script_until = 0; static std::string shot_dir;
static void save_bmp(const uint32_t* px, int w, int h, const std::string& name) {
    SDL_Surface* s = SDL_CreateRGBSurfaceWithFormatFrom((void*)px, w, h, 32, w * 4, SDL_PIXELFORMAT_ARGB8888);
    SDL_SaveBMP(s, (shot_dir + "/" + name + ".bmp").c_str()); SDL_FreeSurface(s);
}
static void save_shot(const std::string& name) { auto px = platform_screen_copy(); save_bmp(px.data(), P.sw, P.sh, name); }
// The enlarged frame with sharp text, as shown on the console.
static void save_big_shot(const std::string& name) { if (!frame.empty()) save_bmp(frame.data(), P.sw * 4, P.sh * 4, name); }

// ---------------- input ----------------
static int key_for(SDL_Keycode k) {
    switch (k) {
        case SDLK_UP: return -1; case SDLK_DOWN: return -2; case SDLK_LEFT: return -3; case SDLK_RIGHT: return -4;
        case SDLK_RETURN: case SDLK_SPACE: return -5; case SDLK_F1: return -6; case SDLK_F2: case SDLK_ESCAPE: return -7;
        default: if (k >= SDLK_0 && k <= SDLK_9) return '0' + (k - SDLK_0); if (k == SDLK_KP_MULTIPLY) return '*'; if (k == SDLK_HASH) return '#'; return 0;
    }
}
static int key_for_button(int b) {
    switch (b) {
        case SDL_CONTROLLER_BUTTON_DPAD_UP: return -1; case SDL_CONTROLLER_BUTTON_DPAD_DOWN: return -2;
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT: return -3; case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: return -4;
        case SDL_CONTROLLER_BUTTON_A: return -5;             // Cross: jump, select, OK
        case SDL_CONTROLLER_BUTTON_B: return -7;             // Circle: back, pause menu
        case SDL_CONTROLLER_BUTTON_X: return '*';            // Square: change ball form
        case SDL_CONTROLLER_BUTTON_Y: return -6;             // Triangle: left soft key (Select / Yes)
        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER: case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER: return '*';
#ifdef BT_PS5
        // PS5 SDL reports the physical Options button as BACK and the touchpad as START.
        case SDL_CONTROLLER_BUTTON_BACK: return -7; case SDL_CONTROLLER_BUTTON_START: case SDL_CONTROLLER_BUTTON_TOUCHPAD: return -7;
#else
        case SDL_CONTROLLER_BUTTON_START: return -7; case SDL_CONTROLLER_BUTTON_BACK: return -6;
#endif
        default: return 0;
    }
}
static void press(int k) { if (k && P.canvas) P.canvas->keyPressed(k); }
static void release(int k) { if (k && P.canvas) P.canvas->keyReleased(k); }
static void pump() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT: throw PlatformQuit();
            case SDL_KEYDOWN: if (!e.key.repeat) press(key_for(e.key.keysym.sym)); break;
            case SDL_KEYUP: release(key_for(e.key.keysym.sym)); break;
            case SDL_CONTROLLERBUTTONDOWN: press(key_for_button(e.cbutton.button)); break;
            case SDL_CONTROLLERBUTTONUP: release(key_for_button(e.cbutton.button)); break;
            case SDL_CONTROLLERDEVICEADDED: if (!P.pad) P.pad = SDL_GameControllerOpen(e.cdevice.which); break;
            case SDL_CONTROLLERDEVICEREMOVED:
                if (P.pad && SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(P.pad)) == e.cdevice.which) { SDL_GameControllerClose(P.pad); P.pad = nullptr; }
                break;
            case SDL_WINDOWEVENT:
                if (e.window.event == SDL_WINDOWEVENT_FOCUS_LOST && P.midlet) P.midlet->pauseApp();
                else if (e.window.event == SDL_WINDOWEVENT_FOCUS_GAINED && P.midlet) P.midlet->startApp();
                break;
            case SDL_CONTROLLERAXISMOTION:
                if (e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX || e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY) {
                    static int ax = 0, ay = 0; int v = e.caxis.value < -16000 ? -1 : e.caxis.value > 16000 ? 1 : 0;
                    int& old = e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX ? ax : ay; bool x = e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX;
                    if (v != old) { if (old) release(x ? (old < 0 ? -3 : -4) : (old < 0 ? -1 : -2)); if (v) press(x ? (v < 0 ? -3 : -4) : (v < 0 ? -1 : -2)); old = v; }
                }
                break;
        }
    }
    // scripted input for host self-tests
    while (script_pos < script.size() && SDL_GetTicks64() >= script_until) {
        auto& c = script[script_pos++];
        if (c.op == "wait") script_until = SDL_GetTicks64() + c.arg;
        else if (c.op == "press") press(c.arg);
        else if (c.op == "release") release(c.arg);
        else if (c.op == "tap") { press(c.arg); script.insert(script.begin() + script_pos, {"release", c.arg, ""}); script.insert(script.begin() + script_pos, {"wait", 120, ""}); }
        else if (c.op == "shot") { save_shot(c.name); fprintf(stdout, "shot %s\n", c.name.c_str()); }
        else if (c.op == "bigshot") { save_big_shot(c.name); fprintf(stdout, "bigshot %s\n", c.name.c_str()); }
        else if (c.op == "quit") throw PlatformQuit();
    }
    if (!script.empty() && script_pos >= script.size()) throw PlatformQuit();
}
// The game redraws as fast as it can. Pace it to about 60 frames per second, which also
// gives its physics a steady time step, then show the frame.
// Frame statistics in the log, to check the frame rate on the console.
static uint64_t stat_start = 0, stat_frames = 0, stat_build = 0, stat_flip = 0, stat_prev = 0, stat_game = 0;
void platform_present() {
    uint64_t t0 = SDL_GetPerformanceCounter();
    if (stat_prev) stat_game += t0 - stat_prev;
#ifndef BT_PS5
    uint64_t now = SDL_GetTicks64();
    while (now - last_present < 16) { pump(); SDL_Delay(1); now = SDL_GetTicks64(); }
    last_present = now;
#endif
    uint64_t t1 = SDL_GetPerformanceCounter();
    platform_present_frame(); pump();
    uint64_t t2 = SDL_GetPerformanceCounter(); stat_prev = t2;
    stat_build += t2 - t1; stat_frames++;
    uint64_t now_ms = SDL_GetTicks64(); if (!stat_start) stat_start = now_ms;
    if (now_ms - stat_start >= 10000) {
        double f = (double)SDL_GetPerformanceFrequency() / 1000.0;
        fprintf(stdout, "fps %.1f | game+draw %.1f ms | scale+present %.1f ms per frame\n", stat_frames * 1000.0 / (now_ms - stat_start), stat_game / f / stat_frames, stat_build / f / stat_frames);
        stat_start = now_ms; stat_frames = stat_build = stat_game = 0;
    }
}
void platform_wait(int64_t ms) {
    uint64_t end = SDL_GetTicks64() + (ms > 0 ? ms : 0);
    do { pump(); uint64_t now = SDL_GetTicks64(); if (now >= end) break; SDL_Delay((Uint32)std::min<uint64_t>(end - now, 5)); } while (true);
}
void platform_rumble(int ms) { if (P.pad) SDL_GameControllerRumble(P.pad, ms ? 0x6000 : 0, ms ? 0x6000 : 0, (Uint32)ms); }

// The FTP server runs as a different user than the game, so make the folder writable for everyone.
static void make_dir(const std::string& p) { mkdir(p.c_str(), 0777); chmod(p.c_str(), 0777); }
static std::vector<std::string> find_jars(const std::string& dir) {
    std::vector<std::string> jars;
    if (DIR* d = opendir(dir.c_str())) {
        while (auto* e = readdir(d)) { std::string n = e->d_name; if (n.size() > 4) { std::string x = n.substr(n.size() - 4); for (auto& c : x) c = (char)tolower(c); if (x == ".jar") jars.push_back(dir + "/" + n); } }
        closedir(d); std::sort(jars.begin(), jars.end());
    } else fprintf(stdout, "Cannot list %s; trying fixed .jar names\n", dir.c_str());
    for (const char* n : {"game.jar", "Game.jar", "BounceTales.jar", "Bounce Tales.jar"}) { std::string p = dir + "/" + n; if (std::find(jars.begin(), jars.end(), p) == jars.end()) if (FILE* f = fopen(p.c_str(), "rb")) { fclose(f); jars.push_back(p); } }
    return jars;
}
// Picks the user's .jar: prefers one with the requested language, then English.
static std::vector<std::string> jar_dirs(const std::string& dir) {
    std::vector<std::string> d{dir};
#ifdef BT_PS5
    for (const char* x : {"/data", "/data/homebrew/BounceTales", "/mnt/usb0/BounceTales", "/mnt/usb1/BounceTales", "/mnt/usb0", "/mnt/usb1"}) d.push_back(x);
#endif
    return d;
}
static bool load_user_game(const std::string& dir, std::string& used) {
    std::string best; int best_score = -1;
    std::vector<std::string> all; for (auto& d : jar_dirs(dir)) for (auto& j : find_jars(d)) all.push_back(j);
    for (auto& j : all) {
        std::map<std::string, std::vector<uint8_t>> f;
        if (!load_jar(j, f)) { fprintf(stdout, "Not a Bounce Tales .jar: %s\n", j.c_str()); continue; }
        int score = 1 + (f.count("lang." + P.locale) ? 2 : 0);
        if (score > best_score) { best_score = score; best = j; }
    }
    if (best.empty()) return false;
    P.files.clear(); load_jar(best, P.files); used = best; return true;
}

static void setup_screen(const std::string& dir) {
    JImage canvas = JImage::createImage(640, 360); auto g = canvas.getGraphics();
    auto draw = [&](const char* t, int y, int col, int style) { g->setColor(col); g->setFont(JFontImpl::getFont(64, style, 0)); std::string s = t; g->drawString(JString(std::u16string(s.begin(), s.end())), 320, y, 17); };
    g->setColor(0x10141c); g->fillRect(0, 0, 640, 360);
    draw("BOUNCE TALES - SETUP", 40, 0xffb040, 1);
    draw("This port does not include the original game.", 90, 0xffffff, 0);
    draw("Copy your own Bounce Tales .jar (Nokia J2ME version) to one of:", 120, 0xffffff, 0);
    draw((dir + "/   or   /data/   or   a USB drive (/BounceTales or root)").c_str(), 150, 0x80d0ff, 1);
    draw("Any file name ending in .jar works. If it is not found, rename it game.jar.", 185, 0xffffff, 0);
    draw("Then press CROSS to check again.", 240, 0xffffff, 1);
    if (P.renderer) {
        SDL_Texture* t = SDL_CreateTexture(P.renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 360);
        SDL_UpdateTexture(t, nullptr, canvas.get()->px.data(), 640 * 4);
        SDL_SetRenderDrawColor(P.renderer, 0, 0, 0, 255); SDL_RenderClear(P.renderer); SDL_RenderCopy(P.renderer, t, nullptr, nullptr); SDL_RenderPresent(P.renderer); SDL_DestroyTexture(t);
    }
}
static bool wait_for_user_game(const std::string& dir, std::string& used) {
    while (!load_user_game(dir, used)) {
        if (P.headless) return false;
        setup_screen(dir); bool retry = false; SDL_Event e;
        while (!retry && SDL_WaitEventTimeout(&e, 500)) {
            if (e.type == SDL_QUIT) return false;
            if (e.type == SDL_CONTROLLERDEVICEADDED && !P.pad) P.pad = SDL_GameControllerOpen(e.cdevice.which);
            if ((e.type == SDL_CONTROLLERBUTTONDOWN && e.cbutton.button == SDL_CONTROLLER_BUTTON_A) || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)) retry = true;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    setvbuf(stdout, nullptr, _IONBF, 0); setvbuf(stderr, nullptr, _IONBF, 0);
    std::string jar, script_file;
#ifdef BT_PS5
    P.save_dir = "/data/BounceTales"; P.bundled_dir = "/app0/assets";
#endif
    for (int i = 1; i < argc; i++) {
        std::string a = argv[i];
        if (a == "--jar" && i + 1 < argc) jar = argv[++i];
        else if (a == "--save" && i + 1 < argc) P.save_dir = argv[++i];
        else if (a == "--bundled" && i + 1 < argc) P.bundled_dir = argv[++i];
        else if (a == "--script" && i + 1 < argc) script_file = argv[++i];
        else if (a == "--shots" && i + 1 < argc) shot_dir = argv[++i];
        else if (a == "--headless") P.headless = true;
        else if (a == "--locale" && i + 1 < argc) P.locale = argv[++i];
        else if (a == "--size" && i + 2 < argc) { P.sw = atoi(argv[++i]); P.sh = atoi(argv[++i]); }
    }
    make_dir(P.save_dir);
#ifdef BT_PS5
    freopen((P.save_dir + "/bouncetales.log").c_str(), "w", stdout); freopen((P.save_dir + "/bouncetales.log").c_str(), "a", stderr);
    setvbuf(stdout, nullptr, _IONBF, 0); setvbuf(stderr, nullptr, _IONBF, 0);
#endif
    fprintf(stdout, "Bounce Tales native PS5 port starting\n");
    if (!script_file.empty()) {
        if (FILE* in = fopen(script_file.c_str(), "r")) {
            char line[256], op[64], arg[128];
            while (fgets(line, sizeof line, in)) {
                int n = sscanf(line, "%63s %127s", op, arg); if (n < 1 || op[0] == '#') continue;
                ScriptCmd c; c.op = op; if (n > 1) { if (c.op == "shot" || c.op == "bigshot") c.name = arg; else c.arg = atoi(arg); } script.push_back(c);
            }
            fclose(in);
        }
    }
    if (P.headless) { SDL_setenv("SDL_VIDEODRIVER", "dummy", 1); SDL_setenv("SDL_AUDIODRIVER", "dummy", 1); if (!getenv("BT_HIRES_TEST")) platform_hires_text = false; }
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER)) { fprintf(stderr, "SDL: %s\n", SDL_GetError()); return 1; }
    platform_load_fonts(P.bundled_dir);
    if (!P.headless) {
#ifdef BT_PS5
        P.window = SDL_CreateWindow("Bounce Tales", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
        if (!P.window || !SDL_GetWindowSurface(P.window)) { fprintf(stderr, "Video: %s\n", SDL_GetError()); return 1; }
#else
        P.window = SDL_CreateWindow("Bounce Tales", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        P.renderer = P.window ? SDL_CreateRenderer(P.window, -1, 0) : nullptr;
        if (!P.renderer) { fprintf(stderr, "Video: %s\n", SDL_GetError()); return 1; }
        SDL_RenderSetLogicalSize(P.renderer, 1920, 1080);
        P.texture = SDL_CreateTexture(P.renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, P.sw * 4, P.sh * 4);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"); SDL_SetTextureScaleMode(P.texture, SDL_ScaleModeLinear);
#endif
        fprintf(stdout, "SDL video=%s audio=%s\n", SDL_GetCurrentVideoDriver(), SDL_GetCurrentAudioDriver());
    }
    for (int i = 0; i < SDL_NumJoysticks(); i++) if (SDL_IsGameController(i)) { P.pad = SDL_GameControllerOpen(i); if (P.pad) break; }
    if (!jar.empty()) { if (!load_jar(jar, P.files)) { fprintf(stderr, "Not a valid Bounce Tales .jar: %s\n", jar.c_str()); return 2; } }
    else if (!wait_for_user_game(P.save_dir, jar)) { fprintf(stderr, "No Bounce Tales .jar in %s\n", P.save_dir.c_str()); SDL_Quit(); return 2; }
    fprintf(stdout, "Game files: %s (%d files)\n", jar.c_str(), (int)P.files.size());
    if (!P.headless) platform_init_audio(P.bundled_dir + "/soundfont.sf2");
    P.back = JImage::createImage(P.sw, P.sh);
    int result = 0;
    try {
        RMIDlet::__ci();
        P.midlet = new RMIDlet();
        P.midlet->startApp();
        P.canvas = dynamic_cast<JGameCanvasBase*>(P.main_runnable);
        if (!P.canvas) throw std::runtime_error("game thread not started");
        P.canvas->run();
    } catch (PlatformQuit&) {
    } catch (JThrowable& e) { fprintf(stderr, "Uncaught Java exception: %s\n", e.what()); result = 3; }
    catch (std::exception& e) { fprintf(stderr, "Error: %s\n", e.what()); result = 3; }
    fprintf(stdout, "Exit %d\n", result);
    SDL_Quit();
    return result;
}
