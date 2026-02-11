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
    int aux = 0;
    int j = 0;

    while(j < 7){
        if(nomeMatriz[1][j] == simbolo && nomeMatriz[2][j] == simbolo && nomeMatriz[3][j] == simbolo && nomeMatriz[4][j] == simbolo){    
           aux++;
            break;
        }
        else if(nomeMatriz[2][j] == simbolo && nomeMatriz[3][j] == simbolo && nomeMatriz[4][j] == simbolo && nomeMatriz[5][j] == simbolo){
            aux++;
            break;
        }
        else if(nomeMatriz[3][j] == simbolo && nomeMatriz[4][j] == simbolo && nomeMatriz[5][j] == simbolo && nomeMatriz[6][j] == simbolo){
            aux++;
            break;
        }

        j++;
    }

    return aux;
}

int verificar_linha(char simbolo, char nomeMatriz[6][7]){
    int aux = 0;
    int i = 0;

    while(i < 6){
        if(nomeMatriz[i][1] == simbolo && nomeMatriz[i][2] == simbolo && nomeMatriz[i][3] == simbolo && nomeMatriz[i][4] == simbolo){    
            aux++;
            break;
        }
        else if(nomeMatriz[i][2] == simbolo && nomeMatriz[i][3] == simbolo && nomeMatriz[i][4] == simbolo && nomeMatriz[i][5] == simbolo){    
            aux++;
            break;
        }
        else if(nomeMatriz[i][3] == simbolo && nomeMatriz[i][4] == simbolo && nomeMatriz[i][5] == simbolo && nomeMatriz[i][6] == simbolo){    
            aux++;
            break;
        }
        else if(nomeMatriz[i][4] == simbolo && nomeMatriz[i][5] == simbolo && nomeMatriz[i][6] == simbolo && nomeMatriz[i][7] == simbolo){    
            aux++;
            break;
        }

        i++;
    }

    return aux;
}

int verificar_diagonal(char simbolo, char nomeMatriz[6][7]){
    
}