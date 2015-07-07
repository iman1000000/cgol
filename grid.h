#ifndef GRID_HEADER
#define GRID_HEADER

#include <stdlib.h>
#include <string.h>

/* Grid memory layout:
 *  | struct gridSize | Cell[rows][cols] |
 * Cells begin with each cell in the first row and follow with the next rows.
 */

struct gridSize {
    int rows;
    int cols;
};

/* Pointer accepted by grid manipulation funcitons.
 * Row and column count are directly accessible by Grid->rows and Grid->cols */
typedef struct gridSize Grid;

typedef char Cell;


/* Returns the amount of memory needed to store a grid of this size. */
size_t grid_calc_size(unsigned rows, unsigned cols);

/* Initializes a grid at the given memory address. */
void grid_init(Grid *grid, unsigned rows, unsigned cols);

/* Allocates and initializes a grid of given dimensions.
 * Remember to delete when not needed.
 */
Grid *grid_create(unsigned rows, unsigned cols);

/* Deallocates memory used by a grid */
void grid_delete(Grid *grid);

/* Allocates a new grid with identical contents to the given grid.
 * Remember to delete when not needed.
 */
Grid *grid_clone(Grid *grid);

/* Copies the memory of one grid to another. Only works if both grids are the
 * same size.
 */
void grid_copy(Grid *src, Grid *dest);

/* Returns grid->rows */
unsigned grid_get_rows(Grid *grid);

/* Returns grid->cols */
unsigned grid_get_cols(Grid *grid);

/* Returns a pointer to a given cell in a grid */
Cell *grid_locate(Grid *grid, int row, int col);

/* Returns the value of a given cell in a grid */
Cell grid_get_at(Grid *grid, int row, int col);

/* Sets the value of a given cell in a grid */
void grid_set_at(Grid *grid, int row, int col, Cell cell);

/* Sets the value of all cells in a grid to 0. Does not modify gridSize */
void grid_clear(Grid *grid);

#endif

