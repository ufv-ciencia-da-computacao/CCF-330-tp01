#include <string.h>
#include "leitura.h"

int read_file(int ***matrix, int *lin, int *col, int *keys, char *name) {
    FILE *file;
    char path[100];
    strcpy(path, "./data/");
    strcat(path, name);
    strcat(path, ".txt");

    file = fopen(path, "r");

    if (file == NULL) {
        perror("\nArquivo nao pode ser lido!");
        fclose(file);
        return 0;
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
    return 1;
}