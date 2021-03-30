#include "solver.h"

int move_student_util(tuple_t pos, int ***visited, int **matrix, int *keys, int max_lin, int max_col, int iter, int *fim) {
    if (pos.x == 0) {
        (*visited)[pos.x][pos.y]=iter;
        *fim = 1;
        printf("\nKEYS: %d\n\n", *keys);
        return 1;
    }

    if(*fim == 1) return 1;
    
    if (matrix[pos.x][pos.y] == 2 || matrix[pos.x][pos.y] == 3 && *keys <= 0) {
        return 0;
    } else if (matrix[pos.x][pos.y] == 3) {
        (*keys)--; //mudar esse requisito do keys
    }

    if ((*visited)[pos.x][pos.y]!=0) {
        return 0;
    } else {
        (*visited)[pos.x][pos.y] = iter;
    
        if (pos.x - 1 >= 0) {
            tuple_t new_pos;
            new_pos.x = pos.x-1;
            new_pos.y = pos.y;
            move_student_util(new_pos, visited, matrix, keys, max_lin, max_col, iter+1, fim);
        }

        if (pos.y - 1 >= 0) {
            tuple_t new_pos;
            new_pos.x = pos.x;
            new_pos.y = pos.y-1;
            move_student_util(new_pos, visited, matrix, keys, max_lin, max_col, iter+1, fim);
        }

        if (pos.y + 1 <= max_col) {
            tuple_t new_pos;
            new_pos.x = pos.x;
            new_pos.y = pos.y+1;
            move_student_util(new_pos, visited, matrix, keys, max_lin, max_col, iter+1, fim);
        }

        if (pos.x + 1 <= max_lin) {
            tuple_t new_pos;
            new_pos.x = pos.x+1;
            new_pos.y = pos.y;
            move_student_util(new_pos, visited, matrix, keys, max_lin, max_col, iter+1, fim);
        }
          
    }
}

void solve(int ***visited, int **matrix, int lin, int col, int keys) {
    tuple_t pos = find_initial_position(matrix, lin, col);
    int fim = 0;
    
    if (move_student_util(pos, visited, matrix, &keys, lin-1, col-1, 1, &fim)) {
        for (int i = 0; i < lin; i++) {
            for (int j = 0; j < col; j++) {
                if((*visited)[i][j]>9) printf("%d ", (*visited)[i][j]);
                else                   printf("%d  ", (*visited)[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Sem solução!");
    }
    
    
}

tuple_t find_initial_position(int **matrix, int lin, int col) {
    tuple_t initial_position;
    for (int i = lin-1; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                initial_position.x = i;
                initial_position.y = j;   
            }
        }
    }
    return initial_position;
}