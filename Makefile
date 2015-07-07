default:
	gcc -o cgol *.c
webcli:
	emcc -O2 -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1 *.c emscripten-async-stdio/stdio_async.c -o cgol.js
