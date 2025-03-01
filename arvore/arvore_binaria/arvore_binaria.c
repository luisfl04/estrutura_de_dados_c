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
    
    // Se árvore é nula, crio o nó:
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

void imprimirArvoreBinaria(ArvoreBinaria* arvore_passada){
    /* Função que imprime os elementos da árvore binária de forma recursiva, usando a pilha de chamadas das funções: */

    if(arvore_passada != NULL){
        imprimirArvoreBinaria(arvore_passada->esquerda);
        printf("Informação do nó -> %d\n", arvore_passada->informacao);
        imprimirArvoreBinaria(arvore_passada->direita);
    }
}

void liberarArvoreBinaria(ArvoreBinaria* arvore_passada){
    /* Libera todos os elementos da árvore binária usando a pilha de chamadas das funções: */
    
    if(arvore_passada != NULL){
        liberarArvoreBinaria(arvore_passada->esquerda);
        liberarArvoreBinaria(arvore_passada->direita);
        free(arvore_passada);
        printf("elemento %d liberado!\n", arvore_passada->informacao);
    }
} 

ArvoreBinaria* removerElementoDaArvoreBinaria(ArvoreBinaria* arvore_passada, int elemento_para_remover){
    /* Função que faz a remoção de determinado elemento na árvore binária. */

    // Se a árvore é nula, ou seka, quando não encontro o elemento, retorno a mesma:
    if (arvore_passada == NULL){
        return arvore_passada;
    }

    // Fazendo a busca do elemento para removê-lo:
    if(elemento_para_remover < arvore_passada->informacao){
        arvore_passada->esquerda = removerElementoDaArvoreBinaria(arvore_passada->esquerda, elemento_para_remover);
    }
    else if(elemento_para_remover > arvore_passada->informacao){
        arvore_passada->direita = removerElementoDaArvoreBinaria(arvore_passada->direita, elemento_para_remover);
    }
    // Quando encontro elemento árvore, verifico a quantidade de filhos que o mesmo tem(se possúi 1 ou nenhum):
    else{
        if (arvore_passada->esquerda == NULL){
            return arvore_passada->direita;
        }  
        else if(arvore_passada->direita == NULL){
            return arvore_passada->esquerda;
        }
        
        // Em casos onde o nó possúi dois filhos, substituirei pelo maior filho à esquerda:
        ArvoreBinaria* maior_filho_a_esquerda = obterMaiorValorDaArvore(arvore_passada->esquerda);
        arvore_passada->informacao = maior_filho_a_esquerda->informacao;    
        arvore_passada->esquerda = removerElementoDaArvoreBinaria(arvore_passada->esquerda, maior_filho_a_esquerda->informacao);
    }

} 

ArvoreBinaria* obterMaiorValorDaArvore(ArvoreBinaria* arvore_passada){
    /* função que busca pela máxima sub-árvore à direita de determinada árvore para obter o maior valor da mesma.. */

    ArvoreBinaria* arvore_de_maior_valor = arvore_passada;

    while (arvore_de_maior_valor->direita != NULL){
        arvore_de_maior_valor = arvore_de_maior_valor->direita;
    }

    return arvore_de_maior_valor;
}

void percorrerArvorePreOrdem(ArvoreBinaria* arvore_passada){
    /* Percurso em raiz -> esquerda -> direita */
    if (arvore_passada != NULL) {
        printf("%d ", arvore_passada->informacao);
        percorrerArvorePreOrdem(arvore_passada->esquerda);  
        percorrerArvorePreOrdem(arvore_passada->direita);   
    }
}

void percorrerArvoreEmOrdem(ArvoreBinaria *arvore_passada){
    /* Percurso em esquerda -> raiz -> direita */
    if (arvore_passada != NULL) {
        percorrerArvoreEmOrdem(arvore_passada->esquerda);  
        printf("%d ", arvore_passada->informacao);
        percorrerArvoreEmOrdem(arvore_passada->direita);   
    }
}

void percorrerArvorePosOrdem(ArvoreBinaria* arvore_passada){
    /* Percurso em esquerda -> direita -> raiz */
    if (arvore_passada != NULL) {
        percorrerArvorePosOrdem(arvore_passada->esquerda);  
        percorrerArvorePosOrdem(arvore_passada->direita);   
        printf("%d ", arvore_passada->informacao);
    }
};


















