#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa uma fila:
typedef struct fila_de_listas_duplamente_encadeadas{
    ListaDuplamenteEncadeada* inicio;
    ListaDuplamenteEncadeada* fim;
} Fila;

// Estrutura que implementa uma lista duplamente encadeada:
typedef struct lista_duplamente_encadeada{
    int informacao;
    struct lista_duplamente_encadeada* anterior;
    struct lista_duplamente_encadeada* proxima;
} ListaDuplamenteEncadeada;

Fila* criarFila(){
    /**** Função que aloca memória para uma nova fila e retorna-a: **/
    
    // Alocando memória:
    Fila* nova_fila = (Fila*) malloc(sizeof(Fila));
    if (nova_fila == NULL){
        printf("Erro ao alocar memória para a nova fila!\n");
        exit(1);
    }

    // Inicializando ponteiros:
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;

    // Retornando estrutura:
    return nova_fila;
}

static ListaDuplamenteEncadeada* inserirElementoInicioFila(Fila* fila_passada , int informacao_passada){
    // Função que insere um novo elemento no início da fila:

    // Verificando se a fila que foi passada ainda não teve memória alocada:
    if(fila_passada == NULL){
        printf("A fila passada é nula!\n");
        return NULL;
    }

    // Alocando memória:
    ListaDuplamenteEncadeada* novo_elemento = (ListaDuplamenteEncadeada*) malloc(sizeof(ListaDuplamenteEncadeada));
    if(novo_elemento == NULL){
        printf("Erro ao alocar memória para o novo elemento!\n");  
        return NULL;
    }

    // Atribuindo valores(Os ponteiros para o anterior e para o próximo são definidos como NULL inicialmente):
    novo_elemento->informacao = informacao_passada;
    novo_elemento->anterior = NULL;
    novo_elemento->proxima = NULL;

    if(fila_passada->inicio != NULL){
        // Atualização de ponteiros em casos onde a fila não estiver vazia:
        novo_elemento->proxima = fila_passada->inicio;
        fila_passada->inicio->anterior = novo_elemento;
    }
    else{
        // Se a fila estiver vazia, o fim da fila é definido como o novo elemento:
        fila_passada->fim = novo_elemento;
    }
    
    // A fila sempre assume que o novo elemento vai ser o início da fila:
    fila_passada->inicio = novo_elemento;

    // Retornando o novo elemento inserido:
    return novo_elemento;
}

// Função que insere no fim:
static ListaDuplamenteEncadeada* inserirElementoFimFila(ListaDuplamenteEncadeada* lista_fim, int informacao_passada){
    ListaDuplamenteEncadeada* novo_elemento = (ListaDuplamenteEncadeada*) malloc(sizeof(ListaDuplamenteEncadeada));
    novo_elemento->informacao = informacao_passada;
    novo_elemento->anterior = lista_fim;
    novo_elemento->proxima = NULL;
    if(lista_fim != NULL){
        lista_fim->proxima = novo_elemento;
    }
    return novo_elemento;
}

// Função que remove o elemento do início da lista:
static ListaDuplamenteEncadeada* removerElementoInicioFila(ListaDuplamenteEncadeada* lista_inicio){
    ListaDuplamenteEncadeada* ponteiro_de_acesso = lista_inicio->proxima;
    if(ponteiro_de_acesso != NULL){
        ponteiro_de_acesso->anterior = NULL;
    }
    free(lista_inicio);
    return ponteiro_de_acesso;
}

// Função que remove o elemento do fim da lista:
static ListaDuplamenteEncadeada* removerElementoFimFila(ListaDuplamenteEncadeada* lista_fim){
    ListaDuplamenteEncadeada* ponteiro_de_acesso = lista_fim->anterior;
    if(ponteiro_de_acesso != NULL){
        ponteiro_de_acesso->proxima = NULL;
    }
    free(lista_fim);
    return ponteiro_de_acesso;
}

// Função que insere um elemento no inicio da fila:
void inserirElementoInicioFilaRecursivamente(Fila* fila_passada, int informacao_passada){
    // Implementar...
}

// Função que insere um elemento no fim da fila:
void  inserirElementoFimFila(Fila* fila_passada, int informacao_passada){
    fila_passada->fim = inserirElementoFimFila(fila_passada->fim, informacao_passada);
    if(fila_passada->inicio == NULL){
        fila_passada->inicio = fila_passada->fim;
    }
}

// Função que remove elemento do início da fila:
void retirarElementoInicioFila(Fila* fila_passada){
    fila_passada->inicio = removerElementoInicioFila(fila_passada->inicio);
    if(fila_passada->inicio == NULL){
        fila_passada->fim = NULL;
    }
}

// Função que remove elemento do fim da fila:
void retirarElementoFimFila(Fila* fila_passada){
    fila_passada->fim = removerElementoFimFila(fila_passada->fim);
    if(fila_passada->fim == NULL){
        fila_passada->inicio = NULL;
    }
}  

