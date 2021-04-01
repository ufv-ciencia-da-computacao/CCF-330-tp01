#include <stdio.h>
#include <stdlib.h>

typedef struct tuple_t {
    int x, y;
} tuple_t;

void solve(int ***visited, int **matrix, int keys, int max_lin, int max_col, int analise);
tuple_t find_initial_position(int **matrix, int lin, int col);