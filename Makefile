default:
	gcc -o cgol *.c
web:
	emcc -O2 -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1  -s EXPORTED_FUNCTIONS='["_main", "_grid_create", "_grid_get_at", "_grid_set_at", "_grid_clear", "_golutil_randomize", "_golutil_cycle", "_golutil_toggle"]' *.c emscripten-async-stdio/stdio_async.c -o cgol.js
dist: web
	cp -f cgol-cli.html cgol-gui.html cgol-gui.js cgol.js cgol.js.mem dist/
	cp -f node_modules/terminal.js/LICENSE dist/node_modules/terminal.js/
	cp -f node_modules/terminal.js/dist/terminal.min.js dist/node_modules/terminal.js/dist/
	cp -f emscripten-async-stdio/LICENSE emscripten-async-stdio/stdio_async.js dist/emscripten-async-stdio/
