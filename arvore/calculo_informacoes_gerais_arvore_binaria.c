/* Arquivo que contém as funções que calculam as informações gerais da árvore binária, em relação a sua altura e etc */

#include <stdio.h>
#include "arvore_binaria.h"

// Valores globais usados nas funções:



int obterAlturaDeArvore(ArvoreBinaria* arvore_passada){
    /* Função que retorna a altura de determinada árvore buscando a folha mais distante a partir da raiz */ 
    
    if (arvore_passada == NULL){
        return  -1; // Nós vazios tem altura -1!
    }

    // Calculando as alturas das sub-árvores da esquerda e direita:
    int altura_da_arvore_esquerda = obterAlturaDeArvore(arvore_passada->esquerda);
    int altura_da_arvore_direita = obterAlturaDeArvore(arvore_passada->direita);

    // Comparando as alturas e retornando a maior:
    if (altura_da_arvore_esquerda > altura_da_arvore_direita){
        return altura_da_arvore_esquerda + 1;
    }
    else{
        return altura_da_arvore_direita + 1;
    }

}

int obterNumeroDeNosArvore();

int obterProfundidadeDeNo();


int obterNumeroDeNosDeAcordoComAltura();
