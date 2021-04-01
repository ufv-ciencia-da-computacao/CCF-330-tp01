#include "solver.h"

int move_student_util(tuple_t pos, int ***visited, int **matrix, int keys, int max_lin, int max_col, int iter, int *fim, int *mov, int *recursive, int *maxLevel) {

    //Counting recursive calls
    (*recursive)++;

    //Returning when goal is already reached
    if(*fim == 1) return 1;

    //Saving max level of recursive calls
    if(iter > *maxLevel) *maxLevel = iter;
    
    //Reach goal
    if (pos.x == 0 && (matrix[pos.x][pos.y] == 1 || matrix[pos.x][pos.y] == 3 && keys > 0)) {
        (*visited)[pos.x][pos.y]=iter;
        *fim = 1;
        return 1;
    }
    
    //Door without key or wall (return)
    if (matrix[pos.x][pos.y] == 2 || matrix[pos.x][pos.y] == 3 && keys <= 0) {
        return 0;
    //Door with key
    } else if (matrix[pos.x][pos.y] == 3) {
        keys--;
    }

    //Print sugerido, porém pode levar uma eternidade
    //printf("Linha %d Coluna %d\n", pos.x, pos.y);

    //Counting movements
    (*mov)++;

    //Already visited (return)
    if((*visited)[pos.x][pos.y] != 0) {
        return 0;
    }

    //Marking visited place
    (*visited)[pos.x][pos.y] = iter;

    //Up
    if (pos.x - 1 >= 0) {
        tuple_t new_pos;
        new_pos.x = pos.x-1;
        new_pos.y = pos.y;
        move_student_util(new_pos, visited, matrix, keys, max_lin, max_col, iter+1, fim, mov, recursive, maxLevel);
    }

    //Left
    if (pos.y - 1 >= 0) {
        tuple_t new_pos;
        new_pos.x = pos.x;
        new_pos.y = pos.y-1;
        move_student_util(new_pos, visited, matrix, keys, max_lin, max_col, iter+1, fim, mov, recursive, maxLevel);
    }

    //Right
    if (pos.y + 1 <= max_col) {
        tuple_t new_pos;
        new_pos.x = pos.x;
        new_pos.y = pos.y+1;
        move_student_util(new_pos, visited, matrix, keys, max_lin, max_col, iter+1, fim, mov, recursive, maxLevel);
    }

    //Down
    if (pos.x + 1 <= max_lin) {
        tuple_t new_pos;
        new_pos.x = pos.x+1;
        new_pos.y = pos.y;
        move_student_util(new_pos, visited, matrix, keys, max_lin, max_col, iter+1, fim, mov, recursive, maxLevel);
    }
    
    //Returning, so setting visited back to zero
    if(*fim == 0) (*visited)[pos.x][pos.y] = 0;

}

void solve(int ***visited, int **matrix, int lin, int col, int keys, int analise) {
    tuple_t pos = find_initial_position(matrix, lin, col);
    int fim = 0, sum = 0, res = 1, mov=0, end=0, recursive=0, maxLevel=0;

    res = move_student_util(pos, visited, matrix, keys, lin-1, col-1, 1, &fim, &mov, &recursive, &maxLevel);

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            sum += (*visited)[i][j];
        }
    }
    
    if (res == 1 && sum != 0) {
        printf("\nCaminho Final Percorrido com Sucesso: \n\n");
        for (int i = 0; i < lin; i++) {
            for (int j = 0; j < col; j++) {
                if((*visited)[i][j]>9) printf("%d ",  (*visited)[i][j]);
                else                   printf("%d  ", (*visited)[i][j]);
                if((*visited)[0][j]!=0) end = j;
            }
            printf("\n");
        }
        printf("\nO estudante se movimentou %d vezes e chegou na coluna %d da primeira linha.\n", mov, end);
    } else {
        printf("\nO estudante se movimentou %d vezes e percebeu que o labirinto nao tem saida.\n", mov);
    }

    //Required Analise Mode
    if(analise) {
        printf("Total de chamadas recursivas: %d\n", recursive);
        printf("Nivel maximo de recursividade: %d\n", maxLevel);
    }
    
    
}

tuple_t find_initial_position(int **matrix, int lin, int col) {
    tuple_t initial_position;
    for (int i = lin-1; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                initial_position.x = i;
                initial_position.y = j;
                break;
            }
        }
    }
    return initial_position;
}