#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arvore/arvore_binaria.h"
#include "arvore/calculo_informacoes_gerais_arvore_binaria.h"

int main() {

    ArvoreBinaria* arvore = criarArvoreBinaria(1);

    inserirElementoNaArvoreBinaria(arvore, 20);
    inserirElementoNaArvoreBinaria(arvore, 30);

    int altura = obterAlturaDeArvore(arvore);
    printf("Altura da arvore: %d\n", altura);
    int numero_de_nos = obterNumeroDeNosArvore(arvore);
    printf("Numero de nos da arvore: %d\n", numero_de_nos);
    int numero_maximo_de_nos_arvore = obterNumeroDeNosDeAcordoComAltura(arvore);
    printf("Numero maximo de nos que a arvore passada pode ter: %d\n", numero_maximo_de_nos_arvore);
}