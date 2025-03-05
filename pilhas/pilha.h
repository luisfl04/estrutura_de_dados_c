#ifndef PILHA_H
#define PILHA_H

// Estrutura que representa a pilha
typedef struct pilha
{
    int elementos[20];
    int topo;
}Pilha;

// Funções de manipulação:
Pilha* criarPilha();
int obterTamanhoPilha();
int verificarPilhaVazia();
int verificarPilhaCheia();
Pilha* inserirElemento();
int removerElemento();
int retornarElemento();
void imprimirPilha();


#endif
