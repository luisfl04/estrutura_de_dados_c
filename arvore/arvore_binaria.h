#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa a arvore binaria:
typedef struct arvore_binaria{
    int informacao;
    struct arvore_binaria* esquerda;
    struct arvore_binaria* direita;
} ArvoreBinaria;

// Função que cria a árvore binária inicialmente vazia:
ArvoreBinaria* criarArvoreBinaria() {
    ArvoreBinaria* nova_arvore = (ArvoreBinaria*) malloc(sizeof(ArvoreBinaria));
    if (!nova_arvore) {
        printf("\nErro ao alocar memória!\n");
        exit(EXIT_FAILURE);
    }
    nova_arvore->informacao = 0;
    nova_arvore->esquerda = NULL;
    nova_arvore->direita = NULL;
    return nova_arvore;
}

// Função que insere um elemento na arvore binária:
ArvoreBinaria* inserirElementoNaArvoreBinaria(ArvoreBinaria* arvore_passada, int elemento_inserido){
    if(arvore_passada == NULL){
        arvore_passada = criarArvoreBinaria();
        arvore_passada->informacao = elemento_inserido;
    }
    else{
        if(elemento_inserido < arvore_passada->informacao){
            arvore_passada->esquerda = inserirElementoNaArvoreBinaria(arvore_passada->esquerda, elemento_inserido);
        }
        else{
            arvore_passada->direita = inserirElementoNaArvoreBinaria(arvore_passada->direita, elemento_inserido);
        }
    }
    return arvore_passada;
}

// Busca por uma informação na arvore binária:
ArvoreBinaria* buscarElementoNaArvoreBinaria(ArvoreBinaria* arvore_passada, int elemento_buscado){
    if(arvore_passada == NULL){
        return NULL;
    }
    else{
        if(arvore_passada->informacao == elemento_buscado){
            return arvore_passada;
        }
        else if(elemento_buscado < arvore_passada->informacao){
            return buscarElementoNaArvoreBinaria(arvore_passada->esquerda, elemento_buscado);
        }
        else{
            return buscarElementoNaArvoreBinaria(arvore_passada->direita, elemento_buscado);
        }
    }
}

//Imprime os elementos da árvore binária:
void imprimirArvoreBinaria(ArvoreBinaria* arvore_passada){
    if(arvore_passada != NULL){
        imprimirArvoreBinaria(arvore_passada->esquerda);
        printf("%d\n", arvore_passada->informacao);
        imprimirArvoreBinaria(arvore_passada->direita);
    }
}

// Liberando todos os elementos da árvore:
void liberarArvoreBinaria(ArvoreBinaria* arvore_passada){
    if(arvore_passada != NULL){
        liberarArvoreBinaria(arvore_passada->esquerda);
        liberarArvoreBinaria(arvore_passada->direita);
        free(arvore_passada);
    }
} 






