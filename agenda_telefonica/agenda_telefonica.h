// Libs:
#include <stdio.h>
# include <stdlib.h>
#include <string.h>

// Estrutura para datas de aniversário:
typedef struct data_de_aniversario {
    char dia_de_aniversario[2];
    char mes_de_aniversario[2];
} Data;

// Estrutura que representa o contato da agenda:
typedef struct contato{
    char nome_contato[40];
    char telefone[15];
    char celular[15];
    char email[40];
    Data* data_de_aniversario;
} Contato;

// Estrutura que representa a agenda com uma lista de contatos:
typedef struct agenda{
    Contato* informacoes;
    struct agenda* proximo_contato; 
} Agenda;

// Função que cria lista inicialmente vazia:
Agenda* criarAgenda(){
    return NULL;
}

Agenda* inserirContato(Agenda* agenda_passada) {    
    system("clear");
    printf("Insira os dados do contato abaixo:\n\n");

    // Variáveis que serão usadas para definir os valores do contato:
    char nome_do_contato[40], telefone[15], celular[15], email[40], dia_niver[3], mes_niver[3];

    // Obtendo valores:
    printf("Nome do contato -> ");
    fgets(nome_do_contato, sizeof(nome_do_contato), stdin);
    nome_do_contato[strcspn(nome_do_contato, "\n")] = '\0'; // Remove o '\n'

    printf("\nTelefone -> ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';

    printf("Celular -> ");
    fgets(celular, sizeof(celular), stdin);
    celular[strcspn(celular, "\n")] = '\0';

    printf("Email -> ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Dia de aniversario -> ");
    fgets(dia_niver, sizeof(dia_niver), stdin);
    dia_niver[strcspn(dia_niver, "\n")] = '\0';

    printf("Mes de aniversario(em numero) -> ");
    fgets(mes_niver, sizeof(mes_niver), stdin);
    mes_niver[strcspn(mes_niver, "\n")] = '\0';

    // Alocando memória para um novo contato:
    Data* data_de_aniversario = (Data*) malloc(sizeof(Data));
    Contato* novas_informacoes = (Contato*) malloc(sizeof(Contato));
    Agenda* novo_contato = (Agenda*) malloc(sizeof(Agenda));    

    // Atribuindo valores (usando strcpy para strings):
    strcpy(novas_informacoes->nome_contato, nome_do_contato);
    strcpy(novas_informacoes->telefone, telefone);
    strcpy(novas_informacoes->celular, celular);
    strcpy(novas_informacoes->email, email);
    strcpy(novas_informacoes->data_de_aniversario->dia_de_aniversario, dia_niver);
    strcpy(novas_informacoes->data_de_aniversario->mes_de_aniversario, mes_niver);

    // VERIFICAR POR QUE OS DADOS NÃO ESTÃO SENDO GRAVADOS.

    // Preenchendo o novo nó da lista:;
    novo_contato->informacoes = novas_informacoes;
    novo_contato->proximo_contato = agenda_passada;

    // Liberando memória temporária:
    free(data_de_aniversario);
    free(novas_informacoes);

    // Adionar lógica de inserir o contato por ordem alfabética!

    printf("\nContato inserido com sucesso!\n");
    return novo_contato; // Retorna o novo nó como início da lista
}

