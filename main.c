#include <stdio.h>
#include <stdlib.h>
#include "arvore/arvore_binaria.h"

int main() {

    ArvoreBinaria* arvore = criarArvoreBinaria();

    inserirElementoNaArvoreBinaria(arvore, 10);
    inserirElementoNaArvoreBinaria(arvore, 20);
    inserirElementoNaArvoreBinaria(arvore, 30);
    inserirElementoNaArvoreBinaria(arvore, 40);
    inserirElementoNaArvoreBinaria(arvore, 50);
    inserirElementoNaArvoreBinaria(arvore, 60);
    inserirElementoNaArvoreBinaria(arvore, 70);
    inserirElementoNaArvoreBinaria(arvore, 80);
    inserirElementoNaArvoreBinaria(arvore, 90);
    inserirElementoNaArvoreBinaria(arvore, 100);    

    imprimirArvoreBinaria(arvore);

}