#include "menu.h"
#include "leitura.h"
#include "solver.h"

void menu() {
    int op = -1;

    #ifdef ANALISE
        printf ("\nAnalise mode");
    #else
        printf("\nNormal Mode");
    #endif
    
    while(op != 0) {
        printf("\n\nMenu Escapar do Labiritinto\n");
        printf("1. Executar por arquivo\n");
        printf("0. Sair\n");
        printf("Opcao Escolhida: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                execute();
                break;
            case 0:
                stop();
                break;
            default:
                invalid();
                break;
        }
    }

}

void execute() {
    int **matrix, lin, col, keys;
    int **visited;
    char name[50];

    printf("Nome do arquivo (sem extensao): ");
    scanf(" %[^\n]s", name);

    if(read_file(&matrix, &lin, &col, &keys, name)==0) return;

    visited = (int**) malloc(lin*sizeof(int*));
    for (int i = 0; i < lin; i++) visited[i] = (int*) malloc (col*sizeof(int)); 

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            visited[i][j] = 0;
        }
    }

    //Required Analise Mode and Normal Mode
    #ifdef ANALISE
        solve(&visited, matrix, lin, col, keys, 1);
    #else
        solve(&visited, matrix, lin, col, keys, 0);
    #endif
}

void stop() {
    printf("\nSair!\n\n");
}

void invalid() {
    printf("Opcao Invalida!\n");
}