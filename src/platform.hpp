/*
 * Bounce Tales PS5 port: platform state shared by the runtime and main loop.
 * PS5 port contributions: Youss Riaal, 2026. SPDX-License-Identifier: GPL-3.0-only
 */
#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "jrt.hpp"
#include <map>
#include <string>
#include <vector>

struct PlatformQuit {};
struct Platform {
    std::map<std::string, std::vector<uint8_t>> files;  // files of the user's original game
    std::string asset_dir = "data", save_dir = "save", bundled_dir = "assets", locale = "en";
    JImage back;                                          // game screen
    int sw = 480, sh = 270;                               // game screen size (16:9; the game adapts its layout)
    JObjectBase* main_runnable = nullptr;
    JGameCanvasBase* canvas = nullptr;
    JMIDletBase* midlet = nullptr;
    bool fake_clock = false; int64_t fake_ms = 0;
    float music_volume = 0.8f;
    SDL_Window* window = nullptr; SDL_Renderer* renderer = nullptr; SDL_Texture* texture = nullptr;
    SDL_GameController* pad = nullptr;
    bool headless = false, quit = false;
};
extern Platform P;
void platform_present();
void platform_wait(int64_t ms);
void platform_rumble(int ms);
void platform_load_fonts(const std::string& dir);
void platform_init_audio(const std::string& sf2);
