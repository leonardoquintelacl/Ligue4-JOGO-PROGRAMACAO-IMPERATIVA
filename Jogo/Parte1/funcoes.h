#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

void printMatriz(char nomeMatriz[6][7]);
void printVitoria(char jogador[50]);
void printEmpate();
int modo_de_jogo();
int modo_nivel_comp();
int verificar_coluna_existencia(char charColuna[50]);
int verificar_coluna_cheia(int numColuna, char nomeMatriz[6][7]);
void alocarJogada(int coluna, int simbolo, char nomeMatriz[6][7]);
void rodada_humano(char jogador[50], char simbolo, char nomeMatriz[6][7]);
int verificar_coluna(char simbolo, char nomeMatriz[6][7]);
int verificar_linha(char simbolo, char nomeMatriz[6][7]);
int verificar_diagonal(char simbolo, char nomeMatriz[6][7]);
int verificar_vitoria(char simbolo, char nomeMatriz[6][7]);


#endif