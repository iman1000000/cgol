default:
	gcc -o cgol *.c
web:
	emcc -O2 -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1  -s EXPORTED_FUNCTIONS='["_main", "_grid_create", "_grid_get_at", "_grid_set_at", "_grid_clear", "_golutil_randomize", "_golutil_cycle", "_golutil_toggle"]' *.c emscripten-async-stdio/stdio_async.c -o cgol.js
