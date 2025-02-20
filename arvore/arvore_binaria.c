#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h" 


ArvoreBinaria* criarArvoreBinaria(int valor_do_no) {
    // Função que cria a árvore binária inicialmente com o valor passado e os filhos nulos:
    
    // Alocando memória e verificando falhas:
    ArvoreBinaria* nova_arvore = (ArvoreBinaria*) malloc(sizeof(ArvoreBinaria));
    if (!nova_arvore) {
        printf("\nErro ao alocar memória!\n");
        exit(EXIT_FAILURE);
    }

    // Atribuindo valores:
    nova_arvore->informacao = valor_do_no;
    nova_arvore->esquerda = NULL;
    nova_arvore->direita = NULL;
    return nova_arvore;
}

ArvoreBinaria* inserirElementoNaArvoreBinaria(ArvoreBinaria* arvore_passada, int elemento_inserido){
    // Função que insere um elemento na arvore binária de acordo com o valor passado:
    
    // Se árvore é nula, crio o nó raiz:
    if(arvore_passada == NULL){
        return criarArvoreBinaria(elemento_inserido);
    }
    
    // Criação com base no valor passado:
    if(elemento_inserido < arvore_passada->informacao){
        arvore_passada->esquerda = inserirElementoNaArvoreBinaria(arvore_passada->esquerda, elemento_inserido);
    }
    else { 
        arvore_passada->direita = inserirElementoNaArvoreBinaria(arvore_passada->direita, elemento_inserido);
    }
    
    // Retorno da arvore com o novo valor inserido:
    return arvore_passada;
}

ArvoreBinaria* buscarElementoNaArvoreBinaria(ArvoreBinaria* arvore_passada, int elemento_buscado){
    /* Função que busca um elemento na árvore binária de acordo com o valor passado: */
    
    // Caso chegue em um nó nulo, o elemento não está presente na árvore.
    if(arvore_passada == NULL){
        printf("A árvore não contém o elemento!\n");
        return NULL;
    }
    
    // Fazendo a busca:
    if(arvore_passada->informacao == elemento_buscado){
        // Quando o elemento for encontrado, imprime e retorna o nó:
        printf("Elemento encontrado!\n-> %d\n", arvore_passada->informacao);
        return arvore_passada;
    }
    // Implementação da busca recursivamente de acordo com o valor buscado:
    else if(elemento_buscado < arvore_passada->informacao){
        return buscarElementoNaArvoreBinaria(arvore_passada->esquerda, elemento_buscado);
    }
    else{
        return buscarElementoNaArvoreBinaria(arvore_passada->direita, elemento_buscado);
    }
    
}

//Imprime os elementos da árvore binária:
void imprimirArvoreBinaria(ArvoreBinaria* arvore_passada){
    if(arvore_passada != NULL){
        imprimirArvoreBinaria(arvore_passada->esquerda);
        printf("%d\n", arvore_passada->informacao);
        imprimirArvoreBinaria(arvore_passada->direita);
    }
}

// Liberando todos os elementos da árvore:
void liberarArvoreBinaria(ArvoreBinaria* arvore_passada){
    if(arvore_passada != NULL){
        liberarArvoreBinaria(arvore_passada->esquerda);
        liberarArvoreBinaria(arvore_passada->direita);
        free(arvore_passada);
        printf("elemento %d liberado!\n", arvore_passada->informacao);
    }
} 






