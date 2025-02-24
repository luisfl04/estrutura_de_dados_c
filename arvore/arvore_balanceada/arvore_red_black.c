// libs:
#include <stdio.h>
#include <stdlib.h>
#include "arvore_red_black.h"


ArvoreRedBlack* criarArvoreRedBlack(int informacao){
    ArvoreRedBlack* arvore = (ArvoreRedBlack*)malloc(sizeof(ArvoreRedBlack));
    
    if (arvore == NULL){
        printf("\nErro ao alocar memória!\n");
        exit(EXIT_FAILURE);
    }

    arvore->informacao = informacao;
    arvore->esquerda = NULL;
    arvore->direita = NULL;
    arvore->pai = NULL;
    arvore->cor = 'B';
    return arvore;
}

void inserirArvoreRedBlack(ArvoreRedBlack** arvore_passada, int informacao){
    // Implementar
}

void removerArvoreRedBlack(ArvoreRedBlack** arvore_passada, int informacao){
    // Implementar
}

ArvoreRedBlack* buscarArvoreRedBlack(ArvoreRedBlack* arvore_passada, int informacao){
    // Implementar
}


