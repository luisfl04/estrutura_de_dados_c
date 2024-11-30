#include <stdio.h>
#include <stdlib.h>

// Estrutura 'retangulo', que é a informação que guardo na lista:
typedef struct retangulo {
    float base;
    float altura;
} Retangulo;

// Estrutura que armazena a lista:
typedef struct lista {
    Retangulo* informacao;
    struct lista* proximo;
} ListaEstruturada;

/* Função auxliar aloca um nó na lista. É nescessária alocar memória tanto para a lista, quanto para a informação
que ela armazena. */
static ListaEstruturada* alocarValor(float base, float altura){
    // Definindo ponteiros para os valores:
    Retangulo* novo_retangulo = (Retangulo*) malloc(sizeof(Retangulo));
    ListaEstruturada* nova_lista = (ListaEstruturada*) malloc(sizeof(ListaEstruturada));

    // Atribuindo valores:
    novo_retangulo->base = base;
    novo_retangulo->altura = altura;
    nova_lista->informacao = novo_retangulo;
    nova_lista->proximo = NULL;

    return nova_lista;
}



