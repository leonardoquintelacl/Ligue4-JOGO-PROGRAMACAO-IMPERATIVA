#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include/funcoes.h"

//Funções para Colunas

int verificar_coluna_existencia(char charColuna[50]){
     while((strcmp(charColuna, "1") != 0) && (strcmp(charColuna, "2") != 0) && (strcmp(charColuna, "3") != 0) && (strcmp(charColuna, "4") != 0) && 
          (strcmp(charColuna, "5") != 0) && (strcmp(charColuna, "6") != 0) && (strcmp(charColuna, "7") != 0)){
            printf("Coluna inexistente!\nSelecione outra coluna: ");
            fgets(charColuna, 50, stdin);
            charColuna[strcspn(charColuna, "\n")] = '\0';
          }

    int coluna = 0;

    if(strcmp(charColuna, "1") == 0){
        return coluna = 0;
    }
    else if(strcmp(charColuna, "2") == 0){
        return coluna = 1;
    }
    else if(strcmp(charColuna, "3") == 0){
        return coluna = 2;
    }
    else if(strcmp(charColuna, "4") == 0){
        return coluna = 3;
    }
    else if(strcmp(charColuna, "5") == 0){
        return coluna = 4;
    }
    else if(strcmp(charColuna, "6") == 0){
        return coluna = 5;
    }
    else if(strcmp(charColuna, "7") == 0){
        return coluna = 6;
    }
}

int verificar_coluna_cheia(int numColuna, char nomeMatriz[6][7]){

    //Verifica se a coluna já está totalmente preenchida
    int aux = numColuna;
    char charAux[50];

    if(nomeMatriz[0][aux] != '*'){
        while(nomeMatriz[0][aux] != '*'){
            printf("Coluna preenchida!\nSelecione outra coluna: ");
            fgets(charAux, 50, stdin);
            charAux[strcspn(charAux, "\n")] = '\0';
            aux = verificar_coluna_existencia(charAux);
        }
    }

    return aux;
}

void alocarJogada(int coluna, int simbolo, char nomeMatriz[6][7]){

    //Analisa qual posição está livre para alocar a jogada do jogador
    // A linha vai de 0 a 5 -> 0 1 2 3 4 5 -> começa de baixo para cima
    int linha = 5; 
    while(linha >= 0){
        if(nomeMatriz[linha][coluna] == '*'){
            nomeMatriz[linha][coluna] = simbolo;
            break;
        }
        else{
            linha--;
        }
    }
}

 
//Funções Modos de Jogo
void rodada_humano(char jogador[50], char simbolo, char nomeMatriz[6][7]){
    char charColuna[50];
    
    if(simbolo == 'X'){
        printf("Rodada de %s (\033[0;33m%c\x1b[0m)\n", jogador, simbolo);
    }
    else{
        printf("Rodada de %s (\033[0;31m%c\x1b[0m)\n", jogador, simbolo);
    }
    printf("Escolha uma coluna(1 a 7): ");
    fgets(charColuna, 50, stdin);
    charColuna[strcspn(charColuna, "\n")] = '\0';

    int coluna = verificar_coluna_existencia(charColuna);
    int auxColuna = verificar_coluna_cheia(coluna, nomeMatriz);
    alocarJogada(auxColuna, simbolo, nomeMatriz);

    system("cls");
    printf("\n  -------- Ligue 4 --------\n");
    printf("\n");
    printMatriz(nomeMatriz);
}

// Funções para Vitória

int verificar_coluna(char simbolo, char nomeMatriz[6][7]){
    
    for(int j = 0; j < 7; j++){
        for(int i = 0; i < 3; i++){
            if(nomeMatriz[i][j] == simbolo && nomeMatriz[i][j] == nomeMatriz[i+1][j] && nomeMatriz[i+1][j] == nomeMatriz[i+2][j] && nomeMatriz[i+2][j] == nomeMatriz[i+3][j]){
                return 1;
            }
        }
    }

    return 0;
}

int verificar_linha(char simbolo, char nomeMatriz[6][7]){
    
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++){
            if(nomeMatriz[i][j] == simbolo && nomeMatriz[i][j] == nomeMatriz[i][j+1] && nomeMatriz[i][j+1] == nomeMatriz[i][j+2] && nomeMatriz[i][j+2] == nomeMatriz[i][j+3]){
                return 1;
            }
        }
    }

    return 0;
}

int verificar_diagonal(char simbolo, char nomeMatriz[6][7]){

    // Diagonal Indo
    for(int i = 3; i < 6; i++){ 
        for(int j = 0; j < 4; j++){
            if(nomeMatriz[i][j] == simbolo && nomeMatriz[i][j] == nomeMatriz[i-1][j+1] && nomeMatriz[i-1][j+1] == nomeMatriz[i-2][j+2] && nomeMatriz[i-2][j+2] == nomeMatriz[i-3][j+3]){
                return 1;
            }
        }
    }

    // Diagonal Voltando
    for(int i = 3; i < 6; i++){
        for(int j = 6; j > 2; j--){
            if(nomeMatriz[i][j] == simbolo && nomeMatriz[i][j] == nomeMatriz[i-1][j-1] && nomeMatriz[i-1][j-1] == nomeMatriz[i-2][j-2] && nomeMatriz[i-2][j-2] == nomeMatriz[i-3][j-3]){
                return 1;
            }
        }
    }  

    return 0;
}


int verificar_vitoria(char simbolo, char nomeMatriz[6][7]){
    if(verificar_coluna(simbolo, nomeMatriz) == 1 || verificar_linha(simbolo, nomeMatriz) == 1 || verificar_diagonal(simbolo, nomeMatriz) == 1){
        return 1;
    }

    return 0;
}