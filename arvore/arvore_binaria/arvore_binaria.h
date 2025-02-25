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
ArvoreBinaria* inserirElementoNaArvoreBinaria();
ArvoreBinaria* buscarElementoNaArvoreBinaria();
void imprimirArvoreBinaria();
void liberarArvoreBinaria();
ArvoreBinaria* removerElementoDaArvoreBinaria();
ArvoreBinaria* obterMaiorValorDaArvore();
void percorrerArvorePreOrdem();
void percorrerArvoreEmOrdem();
void percorrerArvorePosOrdem();


#endif 





