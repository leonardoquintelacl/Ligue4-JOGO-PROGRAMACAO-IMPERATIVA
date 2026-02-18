#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
    char buttonPower[50];
    system("cls");
    
    printf("\n  --- Ligue 4 ---\n\n");
    printf("-> Jogar = 1\n-> Sair = 0\n");
    printf("\nDigite aqui (1 ou 0): ");
    fgets(buttonPower, 50, stdin);
    buttonPower[strcspn(buttonPower, "\n")] = '\0';

    while((strcmp(buttonPower, "0") != 0) && (strcmp(buttonPower, "1") != 0)){
        printf("COMANMDO DESCONHECIDO!! Digite novamente: ");
        fgets(buttonPower, 50, stdin);
        buttonPower[strcspn(buttonPower, "\n")] = '\0';
    }

    if(strcmp(buttonPower, "0") == 0){
        printf("\nEncerrando jogo...");
        return 0;
    }

    else{ 
        system("cls");

        int selection = modo_de_jogo();

        system("cls");

        if(selection == 1){
            char playerOne[50];
            char playerTwo[50];
            char ligue4[6][7] = {{'*', '*', '*', '*', '*', '*', '*'},
                                 {'*', '*', '*', '*', '*', '*', '*'},
                                 {'*', '*', '*', '*', '*', '*', '*'},
                                 {'*', '*', '*', '*', '*', '*', '*'},
                                 {'*', '*', '*', '*', '*', '*', '*'},
                                 {'*', '*', '*', '*', '*', '*', '*'}};

            printf("\n  --- Jogadores ---\n");
            printf("\nJogador 1: ");
            fgets(playerOne, 50, stdin);
            playerOne[strcspn(playerOne, "\n")] = '\0';

            printf("Jogador 2: ");
            fgets(playerTwo, 50, stdin);
            playerTwo[strcspn(playerTwo, "\n")] = '\0';

            system("cls");

            printf("\n --- Iniciando Partida --- \n\n"); 
            printMatriz(ligue4);

            for(int i = 1; i < 43; i++){
                char jogador[50];
                char simbolo;
                
                if(i % 2 != 0){ 
                    strcpy(jogador, playerOne);
                    simbolo = 'X';
                }
                else{
                    strcpy(jogador, playerTwo);
                    simbolo = 'O';
                }
               
                rodada(jogador, simbolo, ligue4);

                if(verificar_vitoria(simbolo, ligue4) == 1){
                    printf("-----------------------------------------------------");
                    printf("\n|                  FIM DE JOGO!                     |\n");
                    printf("|  O JOGADOR %s Eh O GRANDE CAMPEAO DO LIGUE4!!!   |\n", jogador);
                    printf("-----------------------------------------------------");
                    return 0;
                }
            }

            printf("---------------------------------------------------");
            printf("\n|                 FIM DE JOGO!                 |\n");
            printf("|         AMBOS OS JOGADORES EMPATARAM         |\n");
            printf("---------------------------------------------------");
            return 0;
        }


    }
}
