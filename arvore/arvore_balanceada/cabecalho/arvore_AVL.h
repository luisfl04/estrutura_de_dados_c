#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H


// Estrutura de uma árvore AVL:
typedef struct arvore_avl{
    int informacao;
    struct arvore_avl* esquerda;
    struct arvore_avl* direita;
    int altura; 
} ArvoreAVL;

// Funções de manipulação da estrutura:
void imprimirArvoreAVL(ArvoreAVL* arvore_passada);
void liberarArvoreAVL(ArvoreAVL* arvore_passada);
ArvoreAVL* criarArvoreAVL(int informacao);
ArvoreAVL* inserirElementoNaArvoreAVL(ArvoreAVL* arvore_passada, int informacao);
ArvoreAVL* removerElementoDaArvoreAVL(ArvoreAVL* arvore_passada, int informacao);
ArvoreAVL* buscarElementoNaArvoreAVL(ArvoreAVL* arvore_passada, int informacao);
int obterBalancoDeArvore(ArvoreAVL* arvore_passada);
ArvoreAVL* rotacionarEsquerda(ArvoreAVL* arvore_passada);
ArvoreAVL* rotacionarDireita(ArvoreAVL* arvore_passada);

#endif