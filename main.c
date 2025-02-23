#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvore/arvore_binaria.h"
#include "arvore/calculo_informacoes_gerais_arvore_binaria.h"

int main() {

    ArvoreBinaria* arvore = criarArvoreBinaria(1);

    inserirElementoNaArvoreBinaria(arvore, 10);
    inserirElementoNaArvoreBinaria(arvore, 20);
    inserirElementoNaArvoreBinaria(arvore, 30);

    removerElementoDaArvoreBinaria(arvore, 30);

    imprimirArvoreBinaria(arvore);
}