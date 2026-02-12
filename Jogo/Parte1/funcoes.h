#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

void printMatriz(char nomeMatriz[6][7]);
char jogar_ou_sair();
char modo_de_jogo();
void rodada(char jogador[50], char simbolo, char nomeMatriz[6][7]);
int verificar_coluna(char simbolo, char nomeMatriz[6][7]);
int verificar_linha(char simbolo, char nomeMatriz[6][7]);
int verificar_diagonal(char simbolo, char nomeMatriz[6][7]);
int verificar_vitoria(char simbolo, char nomeMatriz[6][7]);


#endif