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

int comp_nivel_facil(char nomeMatriz[6][7]);
int coluna_valida(char tabuleiro[6][7], int coluna);
void simular_jogada(char tabuleiro[6][7], int coluna, char peca);
void limpar_simulacao(char tabuleiro[6][7], int coluna);
int comp_nivel_medio(char tabuleiro[6][7], char pecaPlayer);
int comp_nivel_alto(char tabuleiro[6][7], char pecaIA, char pecaPlayer);

void rodada_humano(char jogador[50], char simbolo, char nomeMatriz[6][7]);
void rodada_humano_computador(char jogador[50], char simbolo, char nomeMatriz[6][7], int nivel);

int verificar_coluna(char simbolo, char nomeMatriz[6][7]);
int verificar_linha(char simbolo, char nomeMatriz[6][7]);
int verificar_diagonal(char simbolo, char nomeMatriz[6][7]);
int verificar_vitoria(char simbolo, char nomeMatriz[6][7]);


#endif