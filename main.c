#include <stdio.h>
#include <stdlib.h>
#include "arvore/arvore_binaria.h"
#include "arvore/calculo_informacoes_gerais_arvore_binaria.c"

int main() {

    ArvoreBinaria* arvore = criarArvoreBinaria();

    inserirElementoNaArvoreBinaria(arvore, 10);
    inserirElementoNaArvoreBinaria(arvore, 20);
    inserirElementoNaArvoreBinaria(arvore, 30);
    
    obterAlturaDeArvore(arvore);

}