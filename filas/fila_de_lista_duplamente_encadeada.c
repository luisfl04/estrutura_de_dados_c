#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

ListaDuplamenteEncadeada* inserirElementoInicioFila(Fila* fila_passada , int informacao_passada){
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

static ListaDuplamenteEncadeada* inserirElementoFimFila(Fila* fila_passada, int informacao_passada){
    // Função que insere um novo elemento no fim da fila.

    // Verificando se a fila que foi passada ainda não teve memória alocada:
    if(fila_passada == NULL){
        printf("A fila passada é nula!\n");
        return NULL;
    }

    // Alocando memória do novo elemento:
    ListaDuplamenteEncadeada* novo_elemento = (ListaDuplamenteEncadeada*) malloc(sizeof(ListaDuplamenteEncadeada));
    if(novo_elemento == NULL){
        printf("Erro ao alocar memória para o novo elemento!\n");
        return NULL;
    }
    
    // Atribuindo valores do elemento:
    novo_elemento->informacao = informacao_passada;
    novo_elemento->anterior = fila_passada->fim;
    novo_elemento->proxima = NULL;
    
    if(fila_passada->fim != NULL){
        fila_passada->fim->proxima = novo_elemento;
    }
    else{
        // Se a fila estiver vazia, o início da fila é definido como o novo elemento:
        fila_passada->inicio = novo_elemento;
    }

    // A fila sempre assume que o novo elemento vai ser o fim da fila:
    fila_passada->fim = novo_elemento;

    return novo_elemento;
}

static int removerElementoInicioFila(Fila* fila_passada){
    // Função que remove o elemento do início da lista e retorna a informação que o elemento guardava

    // Verificando alocações:
    if (fila_passada == NULL || fila_passada->inicio == NULL){
        printf("A fila passada é nula!\n");
        return INT_MIN;
    }

    // Criando ponteiro auxiliar para o elemento a ser removido:
    ListaDuplamenteEncadeada* lista_inicio = fila_passada->inicio;
    int informacao_removida = lista_inicio->informacao;

    // Atualizando ponteiros com base no estado atual da fila:
    if(lista_inicio->proxima == NULL){
        fila_passada->inicio = NULL;
        fila_passada->fim = NULL;
    }
    else{
        fila_passada->inicio = lista_inicio->proxima;
        lista_inicio->proxima->anterior = NULL;
    }

    // Liberando valor:
    free(lista_inicio);
    lista_inicio = NULL;
    
    return informacao_removida;
}

static int removerElementoFimFila(Fila* fila_passada){
    /* Função que recebe uma estrutura fila por parâmetro e remove o elemento que o ponteiro 'fim' armazena.
    Após remover, o valor da informação que esse elemento armazena é retornado. */

    // Verificando alocações:
    if(fila_passada == NULL || fila_passada->inicio == NULL){
        printf("A fila está vazia!\n");
        return INT_MIN;
    }

    // Obtendo o valor que irá ser removido:
    ListaDuplamenteEncadeada* lista_fim = fila_passada->fim;
    int valor_elemento_removido = lista_fim->informacao; // Valor que irá ser retornado.   

    // Verificando se a fila só possui um elemento:
    if(lista_fim->anterior == NULL){
        fila_passada->inicio = NULL;
        fila_passada->fim = NULL;
    }
    else{
        // Se possui valores, atualizo os ponteiros:
        lista_fim->anterior->proxima = NULL;
        fila_passada->fim = lista_fim->anterior;
    }

    // Liberando memória:
    free(lista_fim);
    lista_fim = NULL;    

    // Retorno informação:
    return valor_elemento_removido;
}

static ListaDuplamenteEncadeada* buscarElementoFila(Fila* fila_passada, int informacao_buscada){
    /*Função que percorre os elementos da fila buscando pelo valor passado por parâmetro. Se o valor for achado, o mesmo   
    é retornado. */

    // Verificando ista



}

void imprimirValoresFila(Fila* fila_passada);
void liberarMemoriaFila(Fila* fila_passada);


// Função que insere um elemento no inicio da fila:
// void inserirElementoInicioFilaRecursivamente(Fila* fila_passada, int informacao_passada){
//     // Implementar...
// }

// // Função que insere um elemento no fim da fila:
// void  inserirElementoFimFila(Fila* fila_passada, int informacao_passada){
//     fila_passada->fim = inserirElementoFimFila(fila_passada->fim, informacao_passada);
//     if(fila_passada->inicio == NULL){
//         fila_passada->inicio = fila_passada->fim;
//     }
// }

// // Função que remove elemento do início da fila:
// void retirarElementoInicioFila(Fila* fila_passada){
//     fila_passada->inicio = removerElementoInicioFila(fila_passada->inicio);
//     if(fila_passada->inicio == NULL){
//         fila_passada->fim = NULL;
//     }
// }

// // Função que remove elemento do fim da fila:
// void retirarElementoFimFila(Fila* fila_passada){
//     fila_passada->fim = removerElementoFimFila(fila_passada->fim);
//     if(fila_passada->fim == NULL){
//         fila_passada->inicio = NULL;
//     }
// }  

