#include <stdio.h>
#include <string.h>
#include "include/funcoes.h"

void printMatriz(char nomeMatriz[6][7]){
    int coluna[7] = {1, 2, 3, 4, 5, 6, 7};

    for(int i = 0; i < 7; i++){
        printf("| %d ", coluna[i]);
    }
    printf("|");

    printf("\n");

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(nomeMatriz[i][j] == 'X'){
                printf("|\033[0;33m %c \x1b[0m", nomeMatriz[i][j]);
            }
            else if(nomeMatriz[i][j] == 'O'){
                printf("|\033[0;31m %c \x1b[0m", nomeMatriz[i][j]);
            }
            else{
                printf("| %c ", nomeMatriz[i][j]);
            }
        }
        printf("|");
        printf("\n");
    }
    printf("\n");
}
void printVitoria(char jogador[50]){
    
    printf("FIM DE JOGO!!!\n");
    printf("O JOGADOR %s EH O GRANDE CAMPEAO DO LIGUE4!!!\n", jogador);
   
}

void printEmpate(){
    printf("FIM DE JOGO!!!");
    printf("AMBOS OS JOGADORES EMPATARAM\n!!");
}

// Escolher modos

int modo_de_jogo(){
    char aux[50];

    printf("\n  --- Selecione um modo de jogo --- \n\n");
    printf("-> HUMANO VS HUMANO = 1\n");
    printf("-> HUMANO VS COMPUTADOR = 2\n");
    printf("-> COMPUTADOR VS COMPUTADOR = 3\n");
    printf("\nDigite aqui (1-3): ");
    fgets(aux, 50, stdin);
    aux[strcspn(aux, "\n")] = '\0';

    if((strcmp(aux, "1") != 0) && (strcmp(aux, "2") != 0) && (strcmp(aux, "3") != 0)){
        while((strcmp(aux, "1") != 0) && (strcmp(aux, "2") != 0) && (strcmp(aux, "3") != 0)){
        printf("COMANDO DESCONHECIDO!!\nDigite novamente: ");
        fgets(aux, 50, stdin);
        aux[strcspn(aux, "\n")] = '\0';
        }
    }

    if(strcmp(aux, "1") == 0){
        return 1;
    }
    else if(strcmp(aux, "2") == 0){
        return 2;
    }
    if(strcmp(aux, "3") == 0){
        return 3;
    }
}

int modo_nivel_comp(){
    char aux[50];

    printf("\n  --- Selecione o nivel do Computador --- \n\n");
    printf("-> Facil = 1\n");
    printf("-> Medio = 2\n");
    printf("-> Dificil = 3\n");
    printf("\nDigite aqui (1-3): ");
    fgets(aux, 50, stdin);
    aux[strcspn(aux, "\n")] = '\0';

    if((strcmp(aux, "1") != 0) && (strcmp(aux, "2") != 0) && (strcmp(aux, "3") != 0)){
        while((strcmp(aux, "1") != 0) && (strcmp(aux, "2") != 0) && (strcmp(aux, "3") != 0)){
        printf("COMANDO DESCONHECIDO!!\nDigite novamente: ");
        fgets(aux, 50, stdin);
        aux[strcspn(aux, "\n")] = '\0';
        }
    }

    if(strcmp(aux, "1") == 0){
        return 1;
    }
    else if(strcmp(aux, "2") == 0){
        return 2;
    }
    if(strcmp(aux, "3") == 0){
        return 3;
    }
}