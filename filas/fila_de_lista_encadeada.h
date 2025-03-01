#ifndef FILA_DE_LISTA_ENCADEADA.H
#define FILA_DE_LISTA_ENCADEADA.H


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

FilaDeListasEncadeadas* criarFila();
int verificarFilaVazia(FilaDeListasEncadeadas* fila_passada);
void inserirElementoFila(FilaDeListasEncadeadas* fila_passada, int informacao_passada);
void imprimirValores(FilaDeListasEncadeadas* fila_passada);
void retirarElementoFila(FilaDeListasEncadeadas* fila_passada);
void liberarElementosFila(FilaDeListasEncadeadas* fila_passada);
void ordenarFilaOrdemCrescente(FilaDeListasEncadeadas* fila_passada);

#endif