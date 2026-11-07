# Copyright and license scope

PS5 port: **Youss Riaal**, 2026.

The original contributions to this PS5 port are offered under the GNU General Public License,
version 3 only (`GPL-3.0-only`), to the extent the contributor holds the relevant rights.
The complete license text is in [LICENSE](LICENSE).

## Covered port code

- `src/main.cpp`: start-up, display, controls, loading the user's own `.jar` and the setup screen.
- `src/jrt.hpp`, `src/platform.hpp`, `src/platform.cpp`: the Java/MIDP/Nokia UI runtime on SDL2.
- `tools/j2cpp.py`, `tools/rename.py`: the Java-to-C++ translator and member renamer.
- `native_shims.cpp` and `build-title.py`: integration and build.

## Material outside this grant

- The original Bounce Tales game, its artwork, levels, text, music and game logic, including the
  translated `src/game.cpp` and `src/game.hpp`, are not relicensed by this notice.
- `vendor/`, third-party headers, fonts and the soundfont remain under their own licenses; see
  [NOTICE.md](NOTICE.md).
- The cover icon `sce_sys/icon0.png` is original artwork made for this port.
