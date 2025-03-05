#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pilhas/pilha.h"

int main() {

    Pilha* minha_pilha = criarPilha();  

    inserirElemento(minha_pilha, 10);
    inserirElemento(minha_pilha, 9);
    inserirElemento(minha_pilha, 90);

    imprimirPilha(minha_pilha);


    return 0;
}