#include "grid.h"

size_t grid_calc_size(unsigned rows, unsigned cols) {
    return sizeof(struct gridSize) + (sizeof(Cell) * rows * cols);
}

void grid_init(Grid *grid, unsigned rows, unsigned cols) {
    grid->rows = rows;
    grid->cols = cols;
}

Grid *grid_create(unsigned rows, unsigned cols) {
    Grid *grid = malloc(grid_calc_size(rows, cols));
    grid_init(grid, rows, cols);
    return grid;
}

void grid_delete(Grid *grid) {
    free(grid);
}

Grid *grid_clone(Grid *grid) {
    Grid *new = malloc(grid_calc_size(grid->rows, grid->cols));
    grid_copy(grid, new);
    return new;
}

void grid_copy(Grid *src, Grid *dest) {
    memcpy(dest, src, grid_calc_size(src->rows, src->cols));
}

unsigned grid_get_rows(Grid *grid) {
    return grid->rows;
}

unsigned grid_get_cols(Grid *grid) {
    return grid->cols;
}

Cell *grid_locate(Grid *grid, int row, int col) {
    Cell *cells = (Cell *)(grid + 1);

    // wrap the coords if out of bounds
    while (row >= grid->rows) row -= grid->rows;
    while (row < 0) row += grid->rows;
    while (col >= grid->cols) col -= grid->cols;
    while (col < 0) col += grid->cols;

    row *= grid->cols;
    size_t offset = sizeof(Cell) * (row + col);
    return cells + offset;
}

Cell grid_get_at(Grid *grid, int row, int col) {
    return *grid_locate(grid, row, col);
}

void grid_set_at(Grid *grid, int row, int col, Cell cell) {
    *grid_locate(grid, row, col) = cell;
}

void grid_clear(Grid *grid) {
    size_t grid_mem_size = grid_calc_size(grid->rows, grid->cols)
        - sizeof(struct gridSize);
    memset(grid+1, 0, grid_mem_size);
}
