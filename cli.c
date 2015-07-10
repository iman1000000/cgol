#include "cli.h"

int read_line(char *s, int n) {
    if (fgets(s, n, stdin) == NULL) {
        return 0;
    }

    // check we read a whole line
    if (s[strlen(s)-1] != '\n') {
        // we didn't, so clear the stdin buffer
        int ch = getc(stdin);
        while (ch != '\n') {
            ch = getc(stdin);
            if (ch == EOF) {
                return 0;
            }
        }
    } else {
        // read a whole line, so strip the newline
        s[strlen(s)-1] = '\0';
    }
    return 1;
}

void print_grid_formatted(Grid *grid) {
    puts("   a b c d e f g h i j");
    for (int i = 0; i < grid->rows; ++i) {
        printf("%d ", i);
        for (int j = 0; j < grid->cols; j++) {
            printf("%2x", grid_get_at(grid, i, j));
        }
        putchar('\n');
    }
}

int try_toggle(Grid *grid, char *input) {
    int row, col;
    // input[0] must be a letter and input [1] must be a number
    if (input[0] >= 'a' && input [0] <= 'j') {
        col = input[0] - 'a';
    } else if (input[0] >= 'A' && input [0] <= 'J') {
        col = input[0] - 'A';
    } else return 0;

    if (input[1] >= '0' && input[1] <= '9') {
        row = input[1] - '0';
    } else return 0;

    golutil_toggle(grid, row, col);
    return 1;
}

void main_loop(Grid *grid) {
    char input[INPUT_BUFFER_LEN];
    print_grid_formatted(grid);
    while (read_line(input, INPUT_BUFFER_LEN)) {
        if (strlen(input) == 0) {
            golutil_cycle(grid);
        } else if (!strcmp(input, "random") || !strcmp(input, "r")) {
            golutil_randomize(grid);
        } else if (!strcmp(input, "quit") || !strcmp(input, "q")) {
            exit(0);
        } else if (!strcmp(input, "clear") || !strcmp(input, "c")) {
            grid_clear(grid);
        } else if (strlen(input) == 2 && try_toggle(grid, input)) {
        } else {
            puts("unknown command");
            continue;
        }
        print_grid_formatted(grid);
    }
}

int main(int argc, char *argv []) {
    Grid *grid = grid_create(ROWS, COLS);
    main_loop(grid);
}
