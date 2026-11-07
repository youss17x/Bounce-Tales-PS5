# Credits and component licensing

Port: **Youss Riaal**.

Bounce Tales is the original game; the supplied J2ME edition identifies Nokia as its vendor.
The original artwork, levels, text, music and game logic, including the translated
`src/game.cpp` and `src/game.hpp`, retain their original ownership. This project does not claim
ownership of that content or grant a new license for it. Neither this repository nor its release
archives contain the original game's files; users load them from their own copy of the game.

- Native application tooling and clean-room companion runtime: BlackBearReloaded native-app
  boilerplate tooling vendored from [darkxex/ProsperoStore](https://github.com/darkxex/ProsperoStore/tree/22d5a44a053b4dad4f3a5867fe39d262a80a1b8c/tooling),
  GPL-3.0. Source, runtime manifests and license are under `vendor/ps5-native-tool`. The bundled
  `runtime/libc.prx` is the generated clean-room companion runtime.
- PS5 compatibility layer: [kvaps/syobon-action-ps5](https://github.com/kvaps/syobon-action-ps5), GPL-3.0; see `vendor/ps5_compat.cpp`.
- SDL2: zlib license, `vendor/SDL2-LICENSE.txt`. PS5 backend: [ps5-payload-dev/SDL](https://github.com/ps5-payload-dev/SDL).
  `vendor/sdl-ps5video/SDL_ps5video.c` is a modified copy of its PS5 video driver (commit 160954c),
  changed for 4K output; it is marked as modified in the file.
- stb_image, stb_truetype: public domain / MIT, license text at the end of each header.
- TinySoundFont / TinyMidiLoader: MIT license, `src/TinySoundFont-LICENSE`. Soundfont data
  (`assets/soundfont.sf2`) is `florestan-subset.sf2` from the TinySoundFont examples, a subset of
  Nando Florestan's public-domain soundfonts.
- DejaVu Sans fonts (`assets/font-*.ttf`): Bitstream Vera / DejaVu license, `vendor/dejavu/LICENSE.txt`.
- Build dependencies include the PS5 Payload SDK, pacbrew libraries, LLVM and zlib; their respective licenses apply.

This is an unofficial fan port. It does not imply an official release or endorsement by Nokia,
the original developers or Sony.
