#ifndef FILA_DE_LISTA_DUPLAMENTE_ENCADEADA_H
#define FILA_DE_LISTA_DUPLAMENTE_ENCADEADA_H

// Estrutura que implementa uma lista duplamente encadeada:
typedef struct lista_duplamente_encadeada{
    int informacao;
    struct lista_duplamente_encadeada* anterior;
    struct lista_duplamente_encadeada* proxima;
} ListaDuplamenteEncadeada;

// Estrutura que representa uma fila:
typedef struct fila_de_listas_duplamente_encadeadas{
    ListaDuplamenteEncadeada* inicio;
    ListaDuplamenteEncadeada* fim;
} Fila;


// Assinatura das funções implementadas:
Fila* criarFila();
ListaDuplamenteEncadeada* inserirElementoInicioFila(Fila* fila_passada , int informacao_passada);
ListaDuplamenteEncadeada* inserirElementoFimFila(Fila* fila_passada, int informacao_passada);
int removerElementoInicioFila(Fila* fila_passada);
int removerElementoFimFila(Fila* fila_passada);
ListaDuplamenteEncadeada* buscarElementoFila(Fila* fila_passada, int informacao_buscada);
void imprimirValoresFila(Fila* fila_passada);
void liberarMemoriaFila(Fila* fila_passada);

#endif