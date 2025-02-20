#include <stdio.h>
#include <stdlib.h>
#include "arvore/arvore_binaria.h"

int main() {

    ArvoreBinaria* arvore = criarArvoreBinaria();

    inserirElementoNaArvoreBinaria(arvore, 10);
    inserirElementoNaArvoreBinaria(arvore, 20);
    inserirElementoNaArvoreBinaria(arvore, 30);
    
    buscarElementoNaArvoreBinaria(arvore, 11);

    imprimirArvoreBinaria(arvore);

    liberarArvoreBinaria(arvore);

}