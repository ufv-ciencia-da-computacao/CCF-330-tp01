#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tuple_t {
    int x, y;
} tuple_t;

void solve(int ***visited, int **matrix, int keys, int max_lin, int max_col, int analise);

#endif