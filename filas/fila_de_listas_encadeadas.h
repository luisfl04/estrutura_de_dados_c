#include <stdlib.h>
#include <stdio.h>

// Estrutura que representa a lista encadeada:
typedef struct lista{
    int informacao;
    struct lista* proximo;
} Lista;

// Estrutura que representa a fila de listas encadeadas:
typedef struct fila_de_listas_encadeadas{
    Lista* inicio;
    Lista* fim;
} FilaDeListasEncadeadas;

// Função que cria fila inicialmente nula:
FilaDeListasEncadeadas* criarFila(){
    FilaDeListasEncadeadas* nova_fila = (FilaDeListasEncadeadas*) malloc(sizeof(FilaDeListasEncadeadas));
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    return nova_fila;
}

// Função que verifica se a lista está vazia:
int verificarFilaVazia(FilaDeListasEncadeadas* fila_passada){
    if(fila_passada->inicio == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// Função que insere um novo elemento na lista:
void inserirElementoFila(FilaDeListasEncadeadas* fila_passada, int informacao_passada){
    Lista* novo_elemento = (Lista*) malloc(sizeof(Lista));
    novo_elemento->informacao = informacao_passada;
    novo_elemento->proximo = NULL;
    if(fila_passada->fim != NULL){
        fila_passada->fim->proximo = novo_elemento;
    }
    else{
        fila_passada->inicio = novo_elemento;
    }
    fila_passada->fim = novo_elemento;
}

// Função que imprime os valores da lista:
void imprimirValores(FilaDeListasEncadeadas* lista){
    Lista* lista_temporaria = (Lista*) malloc(sizeof(Lista));
    lista_temporaria = lista->inicio;

    while (lista_temporaria != NULL)
    {
        printf("Info -> %d\n", lista_temporaria->informacao);
        lista_temporaria = lista_temporaria->proximo;
    }
    
    free(lista_temporaria);
}

// Função que retira elemento do inicio da lista:
int retirarElementoInicio(FilaDeListasEncadeadas* fila_passada){
    Lista* lista_temporaria;
    int numero_retirado;

    if(verificarFilaVazia(fila_passada)){
        printf("A fila está vazia!\n");
        exit(1);
    }

    lista_temporaria = fila_passada->inicio;
    numero_retirado = lista_temporaria->informacao;
    fila_passada->inicio = lista_temporaria->proximo;

    if(fila_passada->inicio == NULL){
        fila_passada->fim = NULL;
    }

    free(lista_temporaria);
    return numero_retirado;
}

// Função que libera todos os elementos da fila, para esvaziá-la:
void liberarFila(FilaDeListasEncadeadas* fila_passada){
    Lista* lista_incial = fila_passada->inicio;
    while (lista_incial != NULL)
    {
        Lista* lista_temporaria = lista_incial->proximo;
        free(lista_incial);
        lista_incial = lista_temporaria;
    }
    free(fila_passada);
}



