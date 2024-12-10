#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa uma fila:
typedef struct fila_de_listas_duplamente_encadeadas{
    ListaDuplamenteEncadeada* inicio;
    ListaDuplamenteEncadeada* fim;
} FilaDeListasDuplamenteEncadeadas;

// Estrutura que implementa uma lista duplamente encadeada:
typedef struct lista_duplamente_encadeada{
    int informacao;
    struct lista_duplamente_encadeada* lista_anterior;
    struct lista_duplamente_encadeada* lista_proxima;
} ListaDuplamenteEncadeada;

// Função que cria uma fila:
FilaDeListasDuplamenteEncadeadas* criarFila(){
    FilaDeListasDuplamenteEncadeadas* nova_fila = (FilaDeListasDuplamenteEncadeadas*) malloc(sizeof(FilaDeListasDuplamenteEncadeadas));
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    return nova_fila;
}

// Função que insere um novo elemento no início da lista:
static ListaDuplamenteEncadeada* inserirElementoInicioFila(ListaDuplamenteEncadeada* lista_inicio , int informacao_passada){
    ListaDuplamenteEncadeada* novo_elemento = (ListaDuplamenteEncadeada*) malloc(sizeof(ListaDuplamenteEncadeada));
    novo_elemento->informacao = informacao_passada;
    novo_elemento->lista_anterior = NULL;
    novo_elemento->lista_proxima = lista_inicio;
    if(lista_inicio != NULL){
        lista_inicio->lista_anterior = novo_elemento;
    }

    return novo_elemento;
}

// Função que insere no fim:
static ListaDuplamenteEncadeada* inserirElementoFimFila(ListaDuplamenteEncadeada* lista_fim, int informacao_passada){
    ListaDuplamenteEncadeada* novo_elemento = (ListaDuplamenteEncadeada*) malloc(sizeof(ListaDuplamenteEncadeada));
    novo_elemento->informacao = informacao_passada;
    novo_elemento->lista_anterior = lista_fim;
    novo_elemento->lista_proxima = NULL;
    if(lista_fim != NULL){
        lista_fim->lista_proxima = novo_elemento;
    }
    return novo_elemento;
}

// Função que remove o elemento do início da lista:
static ListaDuplamenteEncadeada* removerElementoInicioFila(ListaDuplamenteEncadeada* lista_inicio){
    ListaDuplamenteEncadeada* ponteiro_de_acesso = lista_inicio->lista_proxima;
    if(ponteiro_de_acesso != NULL){
        ponteiro_de_acesso->lista_anterior = NULL;
    }
    free(lista_inicio);
    return ponteiro_de_acesso;
}

// Função que remove o elemento do fim da lista:
static ListaDuplamenteEncadeada* removerElementoFimFila(ListaDuplamenteEncadeada* lista_fim){
    ListaDuplamenteEncadeada* ponteiro_de_acesso = lista_fim->lista_anterior;
    if(ponteiro_de_acesso != NULL){
        ponteiro_de_acesso->lista_proxima = NULL;
    }
    free(lista_fim);
    return ponteiro_de_acesso;
}

// Função que insere um elemento no inicio da fila:
void  inserirElementoInicioFila(FilaDeListasDuplamenteEncadeadas* fila_passada, int informacao_passada){
    fila_passada->inicio = inserirElementoInicioFila(fila_passada->inicio, informacao_passada);
    if(fila_passada->fim == NULL){
        fila_passada->fim = fila_passada->inicio;
    }
}

// Função que insere um elemento no fim da fila:
void  inserirElementoFimFila(FilaDeListasDuplamenteEncadeadas* fila_passada, int informacao_passada){
    fila_passada->fim = inserirElementoFimFila(fila_passada->fim, informacao_passada);
    if(fila_passada->inicio == NULL){
        fila_passada->inicio = fila_passada->fim;
    }
}

// Função que remove elemento do início da fila:
void retirarElementoInicioFila(FilaDeListasDuplamenteEncadeadas* fila_passada){
    fila_passada->inicio = removerElementoInicioFila(fila_passada->inicio);
    if(fila_passada->inicio == NULL){
        fila_passada->fim = NULL;
    }
}

// Função que remove elemento do fim da fila:
void retirarElementoFimFila(FilaDeListasDuplamenteEncadeadas* fila_passada){
    fila_passada->fim = removerElementoFimFila(fila_passada->fim);
    if(fila_passada->fim == NULL){
        fila_passada->inicio = NULL;
    }
}  

