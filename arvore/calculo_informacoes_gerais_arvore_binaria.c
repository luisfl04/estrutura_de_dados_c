/* Arquivo que contém as funções que calculam as informações gerais da árvore binária, em relação a sua altura e etc */

#include <stdio.h>
#include "arvore_binaria.h"
#include <math.h>


int obterAlturaDeArvore(ArvoreBinaria* arvore_passada){
    /* Função que retorna a altura de determinada árvore buscando a folha mais distante a partir da raiz */ 
    
    if (arvore_passada == NULL){
        return  -1; // Nós vazios tem altura -1!
    }

    // Calculando as alturas das sub-árvores da esquerda e direita:
    int altura_da_arvore_esquerda = obterAlturaDeArvore(arvore_passada->esquerda);
    int altura_da_arvore_direita = obterAlturaDeArvore(arvore_passada->direita);

    // Comparando as alturas e retornando a maior:
    if (altura_da_arvore_esquerda > altura_da_arvore_direita){
        return altura_da_arvore_esquerda + 1;
    }
    else{
        return altura_da_arvore_direita + 1;
    }

}

int obterNumeroDeNosArvore(ArvoreBinaria* arvore_passada){  
    /* Função que retorna o número de nó da árvore binária: */

    if (arvore_passada == NULL){
        return 0; // Nós vazios tem valor zerado.
    }

    return obterNumeroDeNosArvore(arvore_passada->esquerda) + obterNumeroDeNosArvore(arvore_passada->direita) + 1;
}

int obterNumeroMaximoDeNosDeAcordoComAltura(ArvoreBinaria* arvore_passada){
    /* Função que obtém o número máximo de nó de acordo com a altura da árvore passada. */

    // Obtendo a altura da árvore com função auxiliar:
    int altura_arvore = obterAlturaDeArvore(arvore_passada);

    // Verificando se foi possivel obter a altura da arvore:
    if (altura_arvore == -1){
        printf("Não foi possivel obter a altura da arvore!\n");
        return 0;
    }

    // Retornando o número máximo de nós de acordo com a altura da arvore:
    return pow(2, altura_arvore + 1) - 1;
}

int obterNumeroMinimoDeNosDeAcordoComAltura(ArvoreBinaria* arvore_passada){
    /* Função que obtém o número mínimo de nó de acordo com a altura da árvore passada. */

    // Obtendo a altura da árvore com função auxiliar:
    int altura_arvore = obterAlturaDeArvore(arvore_passada);

    // Verificando se foi possivel obter a altura da arvore:
    if (altura_arvore == -1){
        printf("Não foi possivel obter a altura da arvore!\n");
        return 0;
    }   

    // Retornando o número mínimo de nós de acordo com a altura da arvore:
    return altura_arvore + 1;
}

int obterQuantidadeDeNosDeUmaAltura(int nivel_de_altura_passada){
    /* Função que obtém a quantidade de nó que determinado nível de uma árvore pode conter. */

    // Calculando valor:
    return pow(2, nivel_de_altura_passada);
}

int obterAlturaMinimaDaArvoreComBaseNoNumeroDeNos(int numero_de_nos_passados){
    /* Esta função calcula qual a altura mínima que uma arvore qualquer precisa ter 
    para armazena o numero de nos passados como argumento.
    */

    // Calculando:
    int altura_minima = ceil(log2(numero_de_nos_passados + 1)) - 1;
    printf("Uma arvore com %d nos, precisa ter minimamente a altura de %d\n", numero_de_nos_passados,altura_minima);
    return altura_minima;
}

int obterProfundidadeDeNo(ArvoreBinaria *arvore_passada, int valor_do_no_passado){
    /* Função que busca por um nó na árvore e retorna a profundidade dele. */    

    // Verificando se elemento passado existe na árvore:
    if(buscarElementoNaArvoreBinaria(arvore_passada, valor_do_no_passado) == NULL){
        printf("Elemento nao encontrado na arvore!\n");
        return -1;
    }

    // Obtendo a profundidade do nó buscado em relação a altura da árvore original:
    return obterAlturaDeArvore(arvore_passada) - obterAlturaDeArvore(buscarElementoNaArvoreBinaria(arvore_passada, valor_do_no_passado));;
}

