#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    //Função para reconhecer carcteres acentuados em portugês
    setlocale(LC_ALL, "Portuguese_Brazil"); 
    
    //Jogar ou encerrar jogo
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

    else{ //Modo de jogo
    
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

        else{ // Criando Jogadores
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
                    
                printf("Rodada de %s (%c)\n", jogador, simbolo);
                printf("Digite a coluna desejada (1 a 7): ");
                scanf("%d", &coluna);
                getchar();

                if((coluna-1) < 0 || (coluna-1) > 6){
                    while((coluna-1) < 0 || (coluna-1) > 6){
                        printf("Coluna inexistente, selecione outra coluna: ");
                        scanf("%d", &coluna);
                        getchar();
                    }
                }

                if(ligue4[0][coluna-1] == 'x' || ligue4[0][coluna-1] == 'o'){
                    while(ligue4[0][coluna-1] == 'x' || ligue4[0][coluna-1] == 'o'){
                        printf("Coluna preenchida!! Selecione outra coluna: ");
                        scanf("%d", &coluna);
                        getchar();
                    }
                }
                    
                int linha = 6-1;
                while(linha >= 0){
                    if(ligue4[linha][coluna-1] != 'x' && ligue4[linha][coluna-1] != 'o'){
                        ligue4[linha][coluna-1] = simbolo;
                        break;
                    }
                    else{
                        linha--;
                    }
                }

                printf("\n");
                    
                for(int i = 0; i < 6; i++){
                    for(int j = 0; j < 7; j++){
                        printf(" %c  ", ligue4[i][j]);
                    }
                    printf("\n\n");
                }
            }
        }
    }
}