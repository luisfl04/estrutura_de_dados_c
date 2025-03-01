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

FilaDeListasEncadeadas* criarFila(){
    /* Função que aloca memória para uma nova fila e retorna-a */

    // Criando e verificando o alocamento:
    FilaDeListasEncadeadas* nova_fila = (FilaDeListasEncadeadas*) malloc(sizeof(FilaDeListasEncadeadas));
    if (nova_fila == NULL){
        printf("Não foi possível criar nova fila!\n");
        exit(1);
    }

    // Inicializando os ponteiros, com valores vazios:
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;

    // Retornando estrutura:
    return nova_fila;
}

int verificarFilaVazia(FilaDeListasEncadeadas* fila_passada){
    // Função que verifica se a fila está vazia:

    if(fila_passada == NULL){
        printf("Fila vazia!\n");
        return 1;
    }
    else{
        printf("Fila não vazia!\n");
        return 0;
    }
}

void inserirElementoFila(FilaDeListasEncadeadas* fila_passada, int informacao_passada){
    /* Função que insere um novo elemento 'Lista' na fila, a posição de inserção vai variar de acordo com 
    o estado atual da fila */
    
    // Inicializando novo elemento:
    Lista* novo_elemento = (Lista*) malloc(sizeof(Lista));
    if (novo_elemento == NULL){
        printf("Erro ao alocar a memória da nova elemento!\n");
        exit(1);
    }

    // Atribuindo valores:
    novo_elemento->informacao = informacao_passada;
    novo_elemento->proximo = NULL;
    
    // Verificando estado da fila para obter a ordem de inserção:
    if(fila_passada->fim != NULL){
        fila_passada->fim->proximo = novo_elemento;
    }
    else{
        fila_passada->inicio = novo_elemento;
    }

    // Atualizando ponteiro do fim da fila:
    fila_passada->fim = novo_elemento;  
}

void imprimirValores(FilaDeListasEncadeadas* fila_passada){
    // Função que imprime os valores da fila:

    verificarFilaVazia(fila_passada);

    // Alocando memória para uma 'lista_temporaria' que será responsável por percorrer a fila para imprimir os valores:
    Lista* lista_temporaria = (Lista*) malloc(sizeof(Lista));
    lista_temporaria = fila_passada->inicio; // Atribuo o valor do primeiro elemento da fila.

    // Percorrendo a fila e imprimindo os valores:
    while (lista_temporaria != NULL)
    {
        printf("Info -> %d\n", lista_temporaria->informacao);
        lista_temporaria = lista_temporaria->proximo;
    }
    
    // Liberando memória:
    free(lista_temporaria);
}

void retirarElementoFila(FilaDeListasEncadeadas* fila_passada){
    // Função que retira elemento da fila


    Lista* lista_temporaria; // Ponteiro que aponta para o elemento retirado
    int numero_retirado; // Armazena o valor do elemento retirado

    // Verificando fila:
    if(verificarFilaVazia(fila_passada)){
        printf("A fila está vazia!\n");
        exit(1);
    }

    // Atualizando ponteiros:
    lista_temporaria = fila_passada->inicio;
    numero_retirado = lista_temporaria->informacao;
    fila_passada->inicio = lista_temporaria->proximo;

    // Verificando se a lista possúia apenas 1 elemento:
    if(fila_passada->inicio == NULL){
        fila_passada->fim = NULL;
    }

    free(lista_temporaria); // Liberando memória(Removendo elemento)
    printf("Elemento retirado da fila: %d\n", numero_retirado);
}

// Função que libera todos os elementos da fila, para esvaziá-la:
void liberarElementosFila(FilaDeListasEncadeadas* fila_passada){
    Lista* lista_incial = fila_passada->inicio;
    while (lista_incial != NULL)
    {
        Lista* lista_temporaria = lista_incial->proximo;
        free(lista_incial);
        lista_incial = lista_temporaria;
    }
    free(fila_passada);
}


void ordenarFilaOrdemCrescente(FilaDeListasEncadeadas* fila_passada); // Implementar....

