#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

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
    printf("-----------------------------------------------------");
    printf("\n                  FIM DE JOGO!                     \n");
    printf("   O JOGADOR %s Eh O GRANDE CAMPEAO DO LIGUE4!!!   \n", jogador);
    printf("-----------------------------------------------------");
}

void printEmpate(){
    printf("---------------------------------------------------");
    printf("\n                  FIM DE JOGO!                 \n");
    printf("          AMBOS OS JOGADORES EMPATARAM         \n");
    printf("---------------------------------------------------");
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


// Funções para vitória

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
    }

    alocarJogada(coluna, simbolo, nomeMatriz);

    system("cls");
    printf("\n  -------- Ligue 4 --------\n");
    printf("\n");
    printMatriz(nomeMatriz);
}