#ifndef GOLUTIL_HEADER
#define GOLUTIL_HEADER

#include <stdio.h>
#include "grid.h"

/* Print all the cells in the grid as pairs of hex digits. Assumes cells are
 * bytes.
 */
void golutil_print(Grid *grid);

/* Sets each cell in the grid to either 1 or 0 */
void golutil_randomize(Grid *grid);

/* Calculates the next iteration of Conway's Game of Life inplace */
void golutil_cycle(Grid *grid);

/* Toggles the value of the cell at given coordinates between 0 and 1 */
void golutil_toggle(Grid *grid, int row, int col);

#endif
