#ifndef CLI_HEADER
#define CLI_HEADER

#ifdef __EMSCRIPTEN__
#include "emscripten-async-stdio/stdio_async.h"
#else
#include <stdio.h>
#endif

#include <time.h>
#include <string.h>

#include "grid.h"
#include "golutil.h"

#define INPUT_BUFFER_LEN 10
#define ROWS 10
#define COLS 10

/* Read a line of up to n-1 characters into char[] s.
 * Clears the remainder of the input buffer if input is longer than the array.
 * Automaitically strips the trailing newline if present.
 * Returns 0 on EOF or error, else returns 1.
 */
int read_line(char *s, int n);

/* Attemt to toggle the cell given in the string input.
 * If input does not contain a valid cell location, returns 0.
 * Otherwise, toggles the cell and returns 1.
 */
int try_toggle(Grid *grid, char *input);

/* Prints the grid with coordinates. Size is hardcoded. */
void print_grid_formatted(Grid *grid);

void main_loop(Grid *grid);
#endif
