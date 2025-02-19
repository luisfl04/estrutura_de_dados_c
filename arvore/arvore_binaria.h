#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

// Estrutura que representa a arvore binaria:
typedef struct arvore_binaria {
    int informacao;
    struct arvore_binaria* esquerda;
    struct arvore_binaria* direita;
} ArvoreBinaria;

// Assinatura de funções implementadas em arvore_binaria.c:
ArvoreBinaria* criarArvoreBinaria();
ArvoreBinaria* inserirElementoNaArvoreBinaria(ArvoreBinaria* arvore_passada, int elemento_inserido);
ArvoreBinaria* buscarElementoNaArvoreBinaria(ArvoreBinaria* arvore_passada, int elemento_buscado);
void imprimirArvoreBinaria(ArvoreBinaria* arvore_passada);
void liberarArvoreBinaria(ArvoreBinaria* arvore_passada);

#endif 





