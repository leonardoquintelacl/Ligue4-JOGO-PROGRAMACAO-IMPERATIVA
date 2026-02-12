#include <stdio.h>
#include <locale.h>
#include "funcoes.h"

int main(){
    char ligue4[6][7] = {{'@', '@', '@', '@', '@', 'x', '@'},
                         {'@', '@', '@', '@', '@', '@', '@'},
                         {'@', '@', '@', '@', '@', 'x', '@'},
                         {'@', '@', '@', '@', '@', '@', 'x'},
                         {'@', '@', '@', '@', '@', '@', '@'},
                         {'@', '@', '@', '@', '@', '@', '@'}};
    char simbolo = 'x';

    int aux = verificar_diagonal(simbolo, ligue4);

    printf("%d", aux);

    return 0;
}