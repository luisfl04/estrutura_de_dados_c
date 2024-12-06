#include <stdio.h>
#include <stdlib.h>
#include "agenda_telefonica/agenda_telefonica.h"

int main() {

    Agenda* agenda = criarAgenda();
    menu(agenda);
    return 0;

}