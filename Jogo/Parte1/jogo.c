#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "funcoes.h"

int main(){
    //Função para reconhecer carcteres acentuados em portugês
    setlocale(LC_ALL, "Portuguese_Brazil"); 

    char buttonPower = jogar_ou_sair();

    if(buttonPower == '0'){
        printf("\nEncerrando jogo...");
        return 0;
    }

    else{ //Modo de jogo

        char selection = modo_de_jogo();

        if(selection == '1'){ // Criando Jogadores
            char playerOne[50];
            char playerTwo[50];
            char ligue4[6][7] = {{'@', '@', '@', '@', '@', '@', '@'},
                                 {'@', '@', '@', '@', '@', '@', '@'},
                                 {'@', '@', '@', '@', '@', '@', '@'},
                                 {'@', '@', '@', '@', '@', '@', '@'},
                                 {'@', '@', '@', '@', '@', '@', '@'},
                                 {'@', '@', '@', '@', '@', '@', '@'}};

            printf("\n  --- Jogadores ---\n");
            printf("\nJogador 1: ");
            fgets(playerOne, 50, stdin);
            playerOne[strcspn(playerOne, "\n")] = '\0';

            printf("Jogador 2: ");
            fgets(playerTwo, 50, stdin);
            playerTwo[strcspn(playerTwo, "\n")] = '\0';

            printf("\n --- Iniciando Partida --- \n\n");

            printMatriz(ligue4);

            for(int i = 1; i < 43; i++){ // Funcionamento da partida
                char jogador[50];
                char simbolo;
                
                if(i % 2 != 0){ 
                    strcpy(jogador, playerOne);
                    simbolo = 'x';
                }
                else{
                    strcpy(jogador, playerTwo);
                    simbolo = 'o';
                }
                    
               rodada(jogador, simbolo, ligue4);

                printf("\n");
                    
                printMatriz(ligue4);
            }
        }
    }
}