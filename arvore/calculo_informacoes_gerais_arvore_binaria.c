/* Arquivo que contém as funções que calculam as informações gerais da árvore binária, em relação a sua altura e etc */

#include <stdio.h>
#include "arvore_binaria.h"
#include <math.h>

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

int obterNumeroDeNosArvore(ArvoreBinaria* arvore_passada){  
    /* Função que retorna o número de nó da árvore binária: */

    if (arvore_passada == NULL){
        return 0; // Nós vazios tem valor zerado.
    }

    return obterNumeroDeNosArvore(arvore_passada->esquerda) + obterNumeroDeNosArvore(arvore_passada->direita) + 1;
}

int obterNumeroDeNosDeAcordoComAltura(ArvoreBinaria* arvore_passada){

    // Obtendo a altura da árvore com função auxiliar:
    int altura_arvore = obterAlturaDeArvore(arvore_passada);

    if (altura_arvore == -1){
        printf("Não foi possivel obter a altura da arvore!\n");
        return 0;
    }

    int numero = pow(2, altura_arvore + 1) - 1;

    return numero;
}


int obterProfundidadeDeNo();

