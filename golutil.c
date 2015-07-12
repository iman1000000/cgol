#include "golutil.h"

void golutil_print(Grid *grid) {
    for (int i = 0; i < grid->rows; ++i) {
        for (int j = 0; j < grid->cols; j++) {
            printf("%2x", grid_get_at(grid, i, j));
        }
        putchar('\n');
    }
}

void golutil_randomize(Grid *grid) {
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }

    for (int i = 0; i < grid->rows; ++i) {
        for (int j = 0; j < grid->cols; j++) {
            grid_set_at(grid, i, j, !(rand() & 0b11));
        }
    }
}

void golutil_cycle(Grid *grid) {
    Grid *prev = grid_clone(grid);
    for (int i = 0; i < grid->rows; ++i) {
        for (int j = 0; j < grid->cols; j++) {
            int neighbours = 0;
            neighbours += grid_get_at(prev, i-1, j-1);
            neighbours += grid_get_at(prev, i, j-1);
            neighbours += grid_get_at(prev, i+1, j-1);
            neighbours += grid_get_at(prev, i-1, j);
            neighbours += grid_get_at(prev, i+1, j);
            neighbours += grid_get_at(prev, i-1, j+1);
            neighbours += grid_get_at(prev, i, j+1);
            neighbours += grid_get_at(prev, i+1, j+1);
            if (grid_get_at(prev, i, j) &&
                    (neighbours < 2 || neighbours > 3)) {
                grid_set_at(grid, i, j, 0);
            } else if (!grid_get_at(prev, i, j) && neighbours == 3) {
                grid_set_at(grid, i, j, 1);
            }
        }
    }

    grid_delete(prev);
}

void golutil_toggle(Grid *grid, int row, int col) {
    *grid_locate(grid, row, col) ^= 1;
}
