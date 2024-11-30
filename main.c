#include <stdio.h>
#include <stdlib.h>
#include "listas/lista_heterogeneas.h"

int main(){

    ListaHeterogenea* minha_lista;


    // Resolver problema de linkagem na criação de um novo nó.
    minha_lista = criarTriangulo(minha_lista, 10, 20);
    minha_lista = criarRetangulo(minha_lista, 9.80, 5.13);
    minha_lista = criarCirculo(minha_lista, 4.5);

    
    return 0;
}