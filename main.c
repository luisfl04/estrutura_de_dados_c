#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listas/cabecalhos/lista_encadeada.h"

int main() {

    Lista* lista = criarLista();
    lista = inserirElemento(lista, 1);
    lista = inserirElemento(lista, 2);
    lista = inserirElemento(lista, 3);
    lista = inserirElemento(lista, 4);
    lista = inserirElemento(lista, 5);
    lista = inserirElemento(lista, 6);
    lista = inserirElemento(lista, 7);


    
    imprimirLista(lista);








    return 0;
}