#ifndef ARVORE_RED_BLACK_H
#define ARVORE_RED_BLACK_H


// Estrutura de uma árvore red-black:
typedef struct arvore_red_black{
    int informacao;
    struct arvore_red_black* esquerda;
    struct arvore_red_black* direita;
    struct arvore_red_black* pai;
    char cor;
} ArvoreRedBlack;

// Funções de manipulação:
ArvoreRedBlack* criarArvoreRedBlack();
void inserirArvoreRedBlack(ArvoreRedBlack* arvore_passada, int informacao);
void removerArvoreRedBlack(ArvoreRedBlack* arvore_passada, int informacao);
ArvoreRedBlack* buscarArvoreRedBlack(ArvoreRedBlack* arvore_passada, int informacao);


#endif 