#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int main () {

    menu();

    //If you want to test directly with the input.txt just use the code below
    
    /*
    int **matrix, lin, col, keys;
    int **visited;

    read_file(&matrix, &lin, &col, &keys, "input");

    visited = (int**) malloc(lin*sizeof(int*));
    for (int i = 0; i < lin; i++) visited[i] = (int*) malloc (col*sizeof(int)); 

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            visited[i][j] = 0;
        }
    }
    
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", visited[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    tuple_t pos_ini = find_initial_position(matrix, lin, col);
    printf("%d %d\n", pos_ini.x, pos_ini.y);

    Required Analise Mode and Normal Mode
    #ifdef ANALISE
        printf ("Analise mode\n");
        solve(&visited, matrix, lin, col, keys, 1);
    #else
        printf("Normal Mode\n");
        solve(&visited, matrix, lin, col, keys, 0);
    #endif
     */

    return 0;
}