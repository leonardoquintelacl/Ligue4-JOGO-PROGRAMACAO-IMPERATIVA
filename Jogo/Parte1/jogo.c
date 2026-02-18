#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
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

        char playerOne[50];
        char ligue4[6][7] = {{'*', '*', '*', '*', '*', '*', '*'},
                             {'*', '*', '*', '*', '*', '*', '*'},
                             {'*', '*', '*', '*', '*', '*', '*'},
                             {'*', '*', '*', '*', '*', '*', '*'},
                             {'*', '*', '*', '*', '*', '*', '*'},
                             {'*', '*', '*', '*', '*', '*', '*'}};

        int selection = modo_de_jogo();

        system("cls");

        if(selection == 1){

            char playerTwo[50];
            
            printf("\n  --- Nomeando Jogadores ---\n");
            printf("\nDigite um nome para o Jogador 1: ");
            fgets(playerOne, 50, stdin);
            playerOne[strcspn(playerOne, "\n")] = '\0';

            printf("Digite um nome para o Jogador 2: ");
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
               
                rodada_humano(jogador, simbolo, ligue4);

                if(verificar_vitoria(simbolo, ligue4) == 1){
                    printVitoria(jogador);
                    return 0;
                }
            }

            printEmpate();
            return 0;
        }

        else if(selection == 2){
            char playerComp[50] = {"COMPUTADOR"};

            selection = modo_nivel_comp();

            system("cls");

            printf("\n  --- Nomeando Jogador ---\n");
    
            printf("\nDigite um nome para o Jogador: ");
            fgets(playerOne, 50, stdin);
            playerOne[strcspn(playerOne, "\n")] = '\0';
            
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
                    strcpy(jogador, playerComp);
                    simbolo = 'O';
                }
               
                rodada_humano_computador(jogador, simbolo, ligue4, selection);

                if(verificar_vitoria(simbolo, ligue4) == 1){
                    printVitoria(jogador);
                    return 0;
                }
            }

            printEmpate();
            return 0;
        }

        else if(selection == 3){
            char playerComp1[50];
            char playerComp2[50];

            printf("\n  --- Nomeando Jogadores ---\n");

            printf("\nDigite um nome para o COMPUTADOR 1: ");
            fgets(playerComp1, 50, stdin);
            playerComp1[strcspn(playerComp1, "\n")] = '\0';

            printf("Digite um nome para o COMPUTADOR 2: ");
            fgets(playerComp2, 50, stdin);
            playerComp2[strcspn(playerComp2, "\n")] = '\0';

            printf("Teste modo 3");
            return 0;
        }
    }
}
