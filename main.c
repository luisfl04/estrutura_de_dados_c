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

    int altura = obterAlturaDeArvore(arvore);
    printf("Altura da arvore: %d\n", altura);
    int numero_de_nos = obterNumeroDeNosArvore(arvore);
    printf("Numero de nos da arvore: %d\n", numero_de_nos);
    int numero_maximo_de_nos_arvore = obterNumeroMaximoDeNosDeAcordoComAltura(arvore);
    printf("Numero maximo de nos que a arvore passada pode ter: %d\n", numero_maximo_de_nos_arvore);
    int numero_minimo_de_nos_arvore = obterNumeroMinimoDeNosDeAcordoComAltura(arvore);
    printf("Numero minimo de nos que a arvore passada pode ter: %d\n", numero_minimo_de_nos_arvore);
    int quantidade_de_nos_por_altura = obterQuantidadeDeNosDeUmaAltura(altura);
    printf("Uma árvore na altura %d, pode possuir %d nos\n", altura, quantidade_de_nos_por_altura);
    obterAlturaMinimaDaArvoreComBaseNoNumeroDeNos(7);
    obterProfundidadeDeNo(arvore, 20);
}