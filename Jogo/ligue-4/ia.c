#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "include/funcoes.h"

//Funções Nível do Computador

int comp_nivel_facil(char nomeMatriz[6][7]){
    srand(time(NULL));
    int numComp;
    numComp = rand() % 7; //Imprime 7 números 0 1 2 3 4 5 6

    if(nomeMatriz[0][numComp] != '*'){
        while(nomeMatriz[0][numComp] != '*'){
            numComp = rand() % 7;
        }
    }

    return numComp;
}

//Funções Auxiliares para Médio/Difícil

int coluna_valida(char tabuleiro[6][7], int coluna) {
    return tabuleiro[0][coluna] == '*'; 
}

// Testa a posiçaõ da peça de baixo para cima
void simular_jogada(char tabuleiro[6][7], int coluna, char peca) {
    for (int i = 5; i >= 0; i--) {
        if (tabuleiro[i][coluna] == '*') {
            tabuleiro[i][coluna] = peca;
            break;
        }
    }
}

// "Apaga" a peça que acabou de ser colocada na simulação
void limpar_simulacao(char tabuleiro[6][7], int coluna) {
    for (int i = 0; i < 6; i++) {
        if (tabuleiro[i][coluna] != '*') {
            tabuleiro[i][coluna] = '*';
            break;
        }
    }
}

int comp_nivel_medio(char tabuleiro[6][7], char pecaPlayer) {
    for (int coluna = 0; coluna < 7; coluna++) {
        if (coluna_valida(tabuleiro, coluna)) {
            simular_jogada(tabuleiro, coluna, pecaPlayer); 
            
            if (verificar_vitoria(pecaPlayer, tabuleiro)) {
                limpar_simulacao(tabuleiro, coluna);
                return coluna; 
            }
            limpar_simulacao(tabuleiro, coluna); 
        }
    }

    int coluna_aleatoria;
    do {
        coluna_aleatoria = rand() % 7; // Sorteia de 0 a 6
    } while (!coluna_valida(tabuleiro, coluna_aleatoria)); // Repete se a coluna estiver cheia

    return coluna_aleatoria;
}

int comp_nivel_alto(int tabuleiro[6][7], int pecaIA, int pecaPlayer) {
    
    
    for (int col = 0; col < 7; col++) {
        if (coluna_valida(tabuleiro, col)) {
            simular_jogada(tabuleiro, col, pecaIA);
            if (verificar_vitoria(tabuleiro, pecaIA)) {
                limpar_simulacao(tabuleiro, col);
                return col; 
            }
            limpar_simulacao(tabuleiro, col);
        }
    }

    for (int col = 0; col < 7; col++) {
        if (coluna_valida(tabuleiro, col)) {
            simular_jogada(tabuleiro, col, pecaPlayer);
            if (verificar_vitoria(tabuleiro, pecaPlayer)) {
                limpar_simulacao(tabuleiro, col);
                return col; 
            }
            limpar_simulacao(tabuleiro, col);
        }
    }
    //ESTRATÉGIA (Embaralhamento de Preferência)
    // Dividimos as colunas por grupos de importância
    int grupoCentro[] = {2, 3, 4}; 
    int grupoAlas[] = {1, 5};      
    int grupoBordas[] = {0, 6};    

    for (int i = 0; i < 3; i++) {
        int r = rand() % 3;
        int temp = grupoCentro[i];
        grupoCentro[i] = grupoCentro[r];
        grupoCentro[r] = temp;
    }
    for (int i = 0; i < 3; i++) {
        if (coluna_valida(tabuleiro, grupoCentro[i])) return grupoCentro[i];
    }

    int rAla = rand() % 2;
    if (coluna_valida(tabuleiro, grupoAlas[rAla])) return grupoAlas[rAla];
    if (coluna_valida(tabuleiro, grupoAlas[1 - rAla])) return grupoAlas[1 - rAla];

    int rBorda = rand() % 2;
    if (coluna_valida(tabuleiro, grupoBordas[rBorda])) return grupoBordas[rBorda];
    
    return grupoBordas[1 - rBorda]; 
}

void rodada_humano_computador(char jogador[50], char simbolo, char nomeMatriz[6][7], int nivel){
    char charColuna[50];
    int coluna = 0;

    if(simbolo == 'X'){
        printf("Sua rodada (\033[0;33m%c\x1b[0m)\n", simbolo);

        printf("Escolha uma coluna(1 a 7): ");
        fgets(charColuna, 50, stdin);
        charColuna[strcspn(charColuna, "\n")] = '\0';
        coluna = verificar_coluna_existencia(charColuna);
        coluna = verificar_coluna_cheia(coluna, nomeMatriz);
    }
    else{
        if(nivel == 1){
            coluna = comp_nivel_facil(nomeMatriz);
        }
        if(nivel == 2){
            coluna = comp_nivel_medio(nomeMatriz, 'X');
        }
        if(nivel == 3){
            coluna = comp_nivel_alto(nomeMatriz, 'O', 'X');
        }
    }

    alocarJogada(coluna, simbolo, nomeMatriz);

    system("cls");
    printf("\n  -------- Ligue 4 --------\n");
    printf("\n");
    printMatriz(nomeMatriz);
}