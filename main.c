#include <stdio.h>
#include <stdlib.h>
#include "agenda_telefonica/agenda_telefonica.h"

int main(){

    Agenda* minha_agenda = criarAgenda();

    minha_agenda = inserirContato(minha_agenda);

    printf("%s\n", minha_agenda->informacoes->nome_contato);

}   