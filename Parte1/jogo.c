#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){

    //Função para reconhecer carcteres acentuados em portugês
    setlocale(LC_ALL, "Portuguese_Brazil"); 
    
    char buttonPower;
    
    printf("\n  --- Ligue 4 ---\n\n");
    printf("1. Jogar\n0. Sair\n");
    printf("Digite um número correspondente a sua escolha: ");
    scanf("%c", &buttonPower);
    getchar();

    if((buttonPower != '0') && (buttonPower != '1')){

        while((buttonPower != '0') && (buttonPower != '1')){
            printf("\nCOMANMDO DESCONHECIDO, DIGITE NOVAMENTE: ");
            scanf("%c", &buttonPower);
            getchar();
        }
    }

    else if(buttonPower == '0'){
        printf("\nEncerrando jogo...");
        return 0;
    }

    else{
        char selection;

        printf("\n  --- Selecione o modo de jogo --- \n\n");
        printf("1. HUMANO VS HUMANO\n");
        printf("Digite o número correpondente a sua escolha: ");
        scanf("%c", &selection);
        getchar();

        if(selection != '1'){
            while(selection != '1'){
                printf("COMANDO DESCONHECIDO, DIGITE NOVAMENTE: ");
                scanf("%c", &selection);
                getchar();
            }
        }

        else{
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

            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 7; j++){
                    printf(" %c  ", ligue4[i][j]);
                }
                printf("\n\n");
            }

            for(int i = 1; i < 43; i++){
                int coluna;
                
                if(i % 2 != 0){ //Jogador 1
                    printf("Rodada de %s\n", playerOne);
                    printf("Digite a coluna desejada: ");
                    scanf("%c", &coluna);
                    getchar();

                    ligue4[linha][coluna] = 'x';
                    printf("\n");
                    
                    for(int i = 0; i < 6; i++){
                        for(int j = 0; j < 7; j++){
                            printf(" %c  ", ligue4[i][j]);
                        }
                        printf("\n\n");
                    }
                }

                else{ //Jogador 2
                }
            }


        }
    }
}