#include <stdio.h>
#include <stdlib.h>

// Estrutura que implementa uma lista duplamente encadeada:
typedef struct lista_duplamente_encadeada{
    int informacao;
    struct lista_duplamente_encadeada* lista_anterior;
    struct lista_duplamente_encadeada* lista_proxima;
} ListaDuplamenteEncadeada;


// Função que insere um elemento na lista encadeada:
ListaDuplamenteEncadeada* inserirElemento(ListaDuplamenteEncadeada* lista_passada, int elemento_inserido){

    ListaDuplamenteEncadeada* novo_elemento = (ListaDuplamenteEncadeada*) malloc(sizeof(ListaDuplamenteEncadeada));

    novo_elemento->informacao = elemento_inserido;
    novo_elemento->lista_proxima = lista_passada;
    novo_elemento->lista_anterior = NULL;

    /* Verifica se a lista não está vazia para atribuir o novo elemento que está sendo inserido como sendo o elemento
    anterior que ela aponta: */

    if(lista_passada != NULL){
        lista_passada->lista_anterior = novo_elemento;
    }

    return novo_elemento;
}

// Função que busca elemento:
ListaDuplamenteEncadeada* buscarElementoNaLista(ListaDuplamenteEncadeada* lista_passada, int elemento_buscado){
    ListaDuplamenteEncadeada* ponteiro_de_busca = lista_passada;
    for(ponteiro_de_busca; ponteiro_de_busca != NULL; ponteiro_de_busca = ponteiro_de_busca->lista_proxima){
        if(ponteiro_de_busca->informacao == elemento_buscado){
            return ponteiro_de_busca;
        }
    }

    return NULL;
}

// Função que remove um elemento da lista:
ListaDuplamenteEncadeada* retirarElementoLista(ListaDuplamenteEncadeada* lista_passada, int valor_para_retirar){
    // Crio um ponteiro já com o valor que é para ser retirado com o auxilio da função de busca.
    ListaDuplamenteEncadeada* ponteiro_de_acesso = buscarElementoNaLista(lista_passada, valor_para_retirar);

    // Caso não ache o elemento:
    if(ponteiro_de_acesso == NULL){
        printf("O elemento passado nao esta contido na lista.");
        return ponteiro_de_acesso;
    }

    // Retirando o elemento:
    if(ponteiro_de_acesso == lista_passada){
        lista_passada = ponteiro_de_acesso->lista_proxima; // Retira o primeiro, caso seja.
    }
    else{
        ponteiro_de_acesso->lista_anterior->lista_proxima = ponteiro_de_acesso->lista_proxima;
    }

    // Verificando se o ultimo elemento é nulo. Se for, não é possível acessar o proximo elemento.
    if(ponteiro_de_acesso->lista_proxima != NULL){
        ponteiro_de_acesso->lista_proxima->lista_anterior = ponteiro_de_acesso->lista_anterior;
    }

    // Liberando memória:
    free(ponteiro_de_acesso);

    return lista_passada;
}

