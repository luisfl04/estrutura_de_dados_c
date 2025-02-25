#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvore/arvore_binaria/arvore_binaria.h"

int main() {

    ArvoreBinaria* arvore = criarArvoreBinaria(1);

    inserirElementoNaArvoreBinaria(arvore, 10);
    inserirElementoNaArvoreBinaria(arvore, 20);
    inserirElementoNaArvoreBinaria(arvore, 30);

    percorrerArvorePreOrdem(arvore);
    printf("\n");
    percorrerArvoreEmOrdem(arvore);
    printf("\n");
    percorrerArvorePosOrdem(arvore);
    printf("\n");
    imprimirArvoreBinaria(arvore);
    printf("\n");
    liberarArvoreBinaria(arvore);

    return 0;
}