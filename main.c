#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "filas/fila_de_listas_encadeadas.h"

int main() {


    FilaDeListasEncadeadas* minha_fila = criarFila();
    liberarElementosFila(minha_fila);
    verificarFilaVazia(minha_fila);



    return 0;
}