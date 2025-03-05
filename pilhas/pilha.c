// libs:
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


// Constantes:
#define TAMANHO_PILHA(array) (sizeof(array) / sizeof((array)[0])) // Obtém o tamanho de determinado array definido.


Pilha* criarPilha(){
    // Função que cria uma nova estrutura 'pilha':

    Pilha* nova_pilha = (Pilha*) malloc(sizeof(Pilha));
    if (nova_pilha == NULL){
        printf("Ocorreu um erro ao criar a pilha");
        return NULL;
    }

    nova_pilha->topo = -1;
}

int obterTamanhoPilha(Pilha* pilha_passada){
    return TAMANHO_PILHA(pilha_passada->elementos);
}

int verificarPilhaVazia(Pilha* pilha_passada){
    if(pilha_passada->topo == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int verificarPilhaCheia(Pilha* pilha_passada){
    if(pilha_passada->topo == (TAMANHO_PILHA(pilha_passada->elementos) -1 ) ){
        return 1;
    }
    else{
        return 0;
    }
}

Pilha* inserirElemento(Pilha* pilha_passada, int valor_inserido){
    // Insere valor no topo da pilha.

    // Verificando se pilha está cheia:
    if(verificarPilhaCheia(pilha_passada) == 1){
        printf("Nao eh possivel adicionar valores, a pilha ja esta cheia!");
        return NULL;
    } 

    // inserindo valor:
    pilha_passada->elementos[++pilha_passada->topo] = valor_inserido;

    return pilha_passada;
}

int removerElemento(Pilha* pilha_passada){
    // remove elemento do topo da estrutura e o retorna.

    // Verificando se pilha vazia:
    if( verificarPilhaVazia(pilha_passada) == 1 ){
        printf("A pilha esta vazia.");
        return -1;
    }   

    // Removendo valor:
    return pilha_passada->elementos[pilha_passada->topo--];
};

int retornarElemento(Pilha* pilha_passada){
    // Apenas retorna o elemento do topo da fila.

    // Verificando se pilha vazia:
    if( verificarPilhaVazia(pilha_passada) == 1 ){
        printf("A pilha esta vazia.");
        return -1;
    }   

    // Retornando valor:
    return pilha_passada->elementos[pilha_passada->topo];
}


void imprimirPilha(Pilha* pilha_passada){
    // Printa os elementos contidos na pilha

    // Verificando estado:
    if( verificarPilhaVazia(pilha_passada) == 1){
        printf(" A pilha esta vazia!");
        return;
    }

    // Imprimindo elementos:
    for(int i = 0; i <= pilha_passada->topo; i++){
        printf("-> %d\n", pilha_passada->elementos[i]);
    }
}




