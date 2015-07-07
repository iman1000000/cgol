# cgol
Game of life implemented in C, running in browsers through Emscripten

## Text mode commands
   * `<blank line>` --- cycle to the next generation
   * `<letter><number>` --- toggle the value of a cell
   * `random` or `r` --- randomize
   * `clear` or `c` --- clear all cells on the grid
   * `quit` or `q` --- exit program

## Building console mode
Requires gcc, but any other decent C compiler should also work.
```
make
```
Run `cgol`

## Building web text mode
Requires npm and emcc

Make sure the submodule is initialized
```
git submodule init && git submodule update
```
Grab the npm dependencies
```
npm install
```
Compile the javascript components
```
make webcli
```
Open `cgol-cli.html`
