#include "lista_encadeada.h"
#include <stdlib.h>
#include <stdio.h>


// Estrutura de uma lista circular:
typedef struct lista_circular{
    int informacao;
    struct lista_circular* proxima_lista;
} ListaCircular;



// Função que insere elementos na lista circular:
Lista* inserirElementoListaCircular(Lista* lista_passada, int informacao_passada){

    // Os elementos inseridos ficam na primeira posição. Implemente a lógica a partir disso!
    
}

// Função que imprime a lista circularmente:
void imprimirListaCircular(Lista* lista_passada){
    // Ponteiro de acesso que aponta para o elemento inicial:
    Lista* ponteiro_de_acesso = lista_passada;

    // Percorrendo lista:
    if(!verificarListaVazia(ponteiro_de_acesso)){
        do{
            printf("Informacao -> %d", ponteiro_de_acesso->informacao);
            ponteiro_de_acesso = ponteiro_de_acesso->proximo;
        }
        while(ponteiro_de_acesso != lista_passada);
    }
    
}
