#include <stdio.h>
#include "funcoes.h"

void printMatriz(char nomeMatriz[6][7]){

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            printf(" %c ", nomeMatriz[i][j]);
        }
        printf("\n\n");
    }
}

char jogar_ou_sair(){
    char aux; 
    printf("\n  --- Ligue 4 ---\n\n");
    printf("1. Jogar\n0. Sair\n");
    printf("\nDigite o número correspondente a sua escolha: ");
    scanf("%c", &aux);
    getchar();

    while((aux != '0') && (aux != '1')){
        printf("COMANMDO DESCONHECIDO!! Digite uma seleção existente: ");
        scanf("%c", &aux);
        getchar();
    }

    return aux;
}

char modo_de_jogo(){
    char aux;
    printf("\n  --- Selecione o modo de jogo --- \n\n");
    printf("1. HUMANO VS HUMANO\n");
    printf("\nDigite o número correpondente a sua escolha: ");
    scanf("%c", &aux);
    getchar();

    if(aux != '1'){
        while(aux!= '1'){
        printf("COMANDO DESCONHECIDO!! Digite um modo existente: ");
        scanf("%c", &aux);
        getchar();
        }
    }

    return aux;
}

void rodada(char jogador[50], char simbolo, char nomeMatriz[6][7]){
    char charColuna;

    printf("Rodada de %s (%c)\n", jogador, simbolo);
    printf("Digite a coluna desejada (1 a 7): ");
    scanf("%c", &charColuna);
    getchar();

    while(charColuna != '1' && charColuna != '2' && charColuna != '3' && charColuna != '4' && 
          charColuna != '5' && charColuna != '6' && charColuna != '7'){
            printf("COMANDO INVÁLIDO!! Digite uma coluna existente: ");
            scanf("%c", &charColuna);
            getchar();
          }

    //Na tabela ASCII a subtração de um char 'algarismo' pelo char '0' resulta em um número inteiro (int) igual a representação do algorismo
    int coluna = charColuna - '0'; 

    if((coluna-1) < 0 || (coluna-1) > 6){ // Coluna - 1 poque a coluna vai de  0 a 6 -> 0 1 2 3 4 5 6 
        while((coluna-1) < 0 || (coluna-1) > 6){
            printf("Coluna inexistente, selecione outra coluna: ");
            scanf("%d", &coluna);
            getchar();
        }
    }

    if(nomeMatriz[0][coluna-1] == 'x' || nomeMatriz[0][coluna-1] == 'o'){
        while(nomeMatriz[0][coluna-1] == 'x' || nomeMatriz[0][coluna-1] == 'o'){
            printf("Coluna preenchida!! Selecione outra coluna: ");
            scanf("%d", &coluna);
            getchar();
        }
    }
                    
    int linha = 5; // A linha vai de 0 a 5 -> 0 1 2 3 4 5
    while(linha >= 0){
        if(nomeMatriz[linha][coluna-1] != 'x' && nomeMatriz[linha][coluna-1] != 'o'){
            nomeMatriz[linha][coluna-1] = simbolo;
            break;
        }
        else{
            linha--;
        }
    }
}

int verificar_coluna(char simbolo, char nomeMatriz[6][7]){
    
    for(int j = 0; j < 7; j++){
        for(int i = 0; i < 4; i++){
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

    for(int i = 3; i < 6; i++){ // Diagonal Indo
        for(int j = 0; j < 4; j++){
            if(nomeMatriz[i][j] == simbolo && nomeMatriz[i][j] == nomeMatriz[i-1][j+1] && nomeMatriz[i-1][j+1] == nomeMatriz[i-2][j+2] && nomeMatriz[i-2][j+2] == nomeMatriz[i-3][j+3]){
                return 1;
            }
        }
    }

    for(int i = 3; i < 6; i++){ // Diagonal Voltando
        for(int j = 6; j > 3; j--){
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