/* Arquivo que contém as funções que calculam as informações gerais da árvore binária, em relação a sua altura e etc */

#include <stdio.h>
#include "arvore_binaria.h"

int array_de_folhas[100];
int contagem_de_nos = 0;
int contagem_de_achagem_de_folhas = 0;

int obterAlturaDeArvore(ArvoreBinaria* arvore_passada){
    /* Função que retorna a altura de determinada árvore buscando a folha mais distante a partir da raiz */ 

    if(arvore_passada != NULL){
        contagem_de_nos++;
        obterAlturaDeArvore(arvore_passada->esquerda);
        obterAlturaDeArvore(arvore_passada->direita);
        printf("Numero de arestas para achar a folha -> %d", contagem_de_nos);
        array_de_folhas[contagem_de_achagem_de_folhas] = contagem_de_nos;
        contagem_de_achagem_de_folhas++;
        contagem_de_nos = 0;
    }

}

int obterNumeroDeNosArvore();

int obterProfundidadeDeNo();


int obterNumeroDeNosDeAcordoComAltura();
