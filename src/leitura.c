#include "leitura.h"

void read_file(int ***matrix, int *lin, int *col, int *keys) {
    FILE *file;
    file = fopen("./data/input.txt", "r");

    if (file == NULL) {
        perror("Arquivo nao pode ser lido!");
        fclose(file);
    }

    while (!feof(file)) {
        fscanf(file, "%d %d %d", lin, col, keys);

        (*matrix) = (int**) malloc(*lin*sizeof(int*));
        for (int i = 0; i < *col; i++) (*matrix)[i] = (int*) malloc(*col*sizeof(int));

        char *line = (char*) malloc(*col*sizeof(char));
        for (int i = 0; i < *lin; i++) {
            fscanf(file, "%s", line);

            for (int j = 0; j < *col; j++) {
                (*matrix)[i][j] = (line[j] - '0');
            }
        }
    }

    fclose(file);
}