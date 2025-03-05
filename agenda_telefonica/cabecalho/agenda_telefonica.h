#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Estrutura que representa o contato da agenda:
typedef struct contato {
    char nome_contato[40];
    int telefone;
    int celular;
    char email[40];
    int dia_de_aniversario;
    char mes_de_aniversario[40];
} Contato;

// Estrutura que representa a agenda com uma lista de contatos:
typedef struct agenda {
    Contato* informacoes;
    struct agenda* proximo_contato;
} Agenda;

// Função que cria uma agenda inicialmente vazia:
Agenda* criarAgenda() {
    Agenda* nova_agenda = (Agenda*) malloc(sizeof(Agenda));
    if (!nova_agenda) {
        printf("\nErro ao alocar memória!\n");
        exit(EXIT_FAILURE);
    }
    nova_agenda->informacoes = NULL;
    nova_agenda->proximo_contato = NULL;
    return nova_agenda;
}

// função que verifica se a agenda é vazia:
int verificarAgendaVazia(Agenda* agenda_passada) {
    if (agenda_passada == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// Função que insere um contato na agenda:
Agenda* inserirContato(Agenda* agenda_passada) {
    printf("Insira os dados do contato abaixo:\n\npressione enter para prosseguir...\n\n");

    // Variáveis para entrada de dados:
    char nome_do_contato[40], email[40], mes_niver[40];
    int telefone, celular, dia_niver;

    // Limpar buffer:
    getchar(); // Para evitar problemas com fgets após scanf

    // Obtendo valores:
    printf("Nome do contato -> ");
    fgets(nome_do_contato, sizeof(nome_do_contato), stdin);
    nome_do_contato[strcspn(nome_do_contato, "\n")] = '\0';

    printf("\nTelefone -> ");
    scanf("%d", &telefone);

    printf("\nCelular -> ");
    scanf("%d", &celular);

    getchar(); // Limpar o buffer após scanf

    printf("\nEmail -> ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("\nDia de aniversario -> ");
    scanf("%d", &dia_niver);

    getchar(); // Limpar o buffer após scanf

    printf("\nMes de aniversario -> ");
    fgets(mes_niver, sizeof(mes_niver), stdin);
    mes_niver[strcspn(mes_niver, "\n")] = '\0';

    // Alocação de memória:
    Agenda* novo_contato = (Agenda*) malloc(sizeof(Agenda));
    if (!novo_contato) {
        printf("Erro ao alocar memória para novo contato!\n");
        exit(EXIT_FAILURE);
    }

    Contato* novas_informacoes = (Contato*) malloc(sizeof(Contato));
    if (!novas_informacoes) {
        printf("Erro ao alocar memória para informações do contato!\n");
        free(novo_contato);
        exit(EXIT_FAILURE);
    }

    // Atribuir valores:
    strcpy(novas_informacoes->nome_contato, nome_do_contato);
    novas_informacoes->telefone = telefone;
    novas_informacoes->celular = celular;
    strcpy(novas_informacoes->email, email);

    novas_informacoes->dia_de_aniversario = dia_niver;
    strcpy(novas_informacoes->mes_de_aniversario, mes_niver);

    novo_contato->informacoes = novas_informacoes;
    novo_contato->proximo_contato = NULL;

    // Inserção na lista, ordenando alfabeticamente:
    if (agenda_passada->informacoes == NULL || strcmp(novo_contato->informacoes->nome_contato, agenda_passada->informacoes->nome_contato) < 0) {
        novo_contato->proximo_contato = agenda_passada;
        printf("\nContato inserido com sucesso!\n");
        return novo_contato;
    } else {
        Agenda* atual = agenda_passada;
        while (atual->proximo_contato && strcmp(atual->proximo_contato->informacoes->nome_contato, novo_contato->informacoes->nome_contato) < 0) {
            atual = atual->proximo_contato;
        }
        novo_contato->proximo_contato = atual->proximo_contato;
        atual->proximo_contato = novo_contato;
        printf("\nContato inserido com sucesso!\n");
        return agenda_passada;
    }
}

// Função para imprimir os contatos:
void imprimirContatos(Agenda* agenda_passada) {
    printf("\nAgenda de contatos:\n\n");    
    
    Agenda* contato_atual = agenda_passada;
    if(verificarAgendaVazia(contato_atual) == 1){
        printf("Agenda vazia!\n");
        exit(1);
    }
    else{    
        int i = 1;
        while (contato_atual != NULL) {
            if (contato_atual->informacoes != NULL) {
                printf("Contato %d:\n", i);
                printf("Nome -> %s\n", contato_atual->informacoes->nome_contato);
                printf("Telefone -> %d\n", contato_atual->informacoes->telefone);
                printf("Celular -> %d\n", contato_atual->informacoes->celular);
                printf("Email -> %s\n", contato_atual->informacoes->email);
                printf("Dia de aniversário -> %d\n", contato_atual->informacoes->dia_de_aniversario);
                printf("Mês de aniversário -> %s\n\n", contato_atual->informacoes->mes_de_aniversario);
            }
            contato_atual = contato_atual->proximo_contato;
            i++;
        }
    }
}

// Função que libera todos os elementos alocados:
void liberarAgenda(Agenda* agenda_passada) {
    Agenda* contato_atual = agenda_passada;
    while (contato_atual != NULL) {
        Agenda* contato_temporario = contato_atual->proximo_contato;
        Contato* informacoes_temporarias = contato_atual->informacoes;
        free(informacoes_temporarias);
        free(contato_atual);
        contato_atual = contato_temporario;
    }
    system("clear");
    printf("\nAgenda liberada com sucesso!\n");
}

// Função que busca um contato na agenda de acordo com o nome:
Agenda* buscaContato(Agenda* agenda_passada) {
    // Pedindo o nome do contato:
    getchar();
    char nome_contato[40];
    printf("Insira o nome do contato:\n");
    fgets(nome_contato, sizeof(nome_contato), stdin);
    nome_contato[strcspn(nome_contato, "\n")] = '\0';
    
    // Buscando contato:
    Agenda* contato_atual = agenda_passada;
    while (contato_atual != NULL) {
        if (contato_atual->informacoes != NULL && strcmp(contato_atual->informacoes->nome_contato, nome_contato) == 0) {
            printf("Contato encontrado com o nome %s encontrado!\n", contato_atual->informacoes->nome_contato);
            return contato_atual;
        }
        contato_atual = contato_atual->proximo_contato;
    }
    printf("Contato nao encontrado!");
    return NULL;
}

// Função que remove um contato da agenda:
Agenda* removerContato(Agenda* agenda_passada) {
    // Alocando memória:
    Agenda* contato_atual = agenda_passada;
    Agenda* contato_anterior = NULL;
    
    // Obtendo o nome do contato:
    getchar();
    char nome_contato[40];
    printf("Insira o nome do contato:\n");
    fgets(nome_contato, sizeof(nome_contato), stdin);
    nome_contato[strcspn(nome_contato, "\n")] = '\0';

    // Buscando contato:
    while (contato_atual != NULL) {
        if (contato_atual->informacoes != NULL) {
            if (strcmp(contato_atual->informacoes->nome_contato, nome_contato) == 0) {
                if (contato_anterior == NULL) {
                    agenda_passada = contato_atual->proximo_contato;
                } else {
                    contato_anterior->proximo_contato = contato_atual->proximo_contato;
                }
                free(contato_atual->informacoes);
                free(contato_atual);
                printf("Contato %s removido com sucesso!\n", nome_contato);
                return agenda_passada;
            }
        }
        contato_anterior = contato_atual;
        contato_atual = contato_atual->proximo_contato;
    }
    printf("Contato nao encontrado!");
    return NULL;
}

Agenda* atualizarContato(Agenda* agenda_passada) {
    // Verificar se o contato existe
    Agenda* contato_buscado = buscaContato(agenda_passada);
    if (contato_buscado == NULL) { 
        printf("O contato não existe na agenda.\n");
        return agenda_passada;
    }

    // Atualizar o contato:
    printf("\nAtualizando contato:\n");

    getchar(); // Limpar buffer

    char nome_contato[40];
    printf("Insira o novo nome do contato:\n");
    fgets(nome_contato, sizeof(nome_contato), stdin);
    nome_contato[strcspn(nome_contato, "\n")] = '\0';
    strcpy(contato_buscado->informacoes->nome_contato, nome_contato);

    int telefone;
    printf("Insira o novo telefone do contato:\n");
    scanf("%d", &telefone);
    contato_buscado->informacoes->telefone = telefone;

    int celular;
    printf("Insira o novo celular do contato:\n");
    scanf("%d", &celular);
    contato_buscado->informacoes->celular = celular;

    getchar(); 

    char email[40];
    printf("Insira o novo email do contato:\n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    strcpy(contato_buscado->informacoes->email, email); 

    int dia_niver;
    printf("Insira o novo dia de aniversário do contato:\n");
    scanf("%d", &dia_niver);
    contato_buscado->informacoes->dia_de_aniversario = dia_niver;

    getchar();

    char mes_niver[40];
    printf("Insira o novo mês de aniversário do contato:\n");
    fgets(mes_niver, sizeof(mes_niver), stdin);
    mes_niver[strcspn(mes_niver, "\n")] = '\0';
    strcpy(contato_buscado->informacoes->mes_de_aniversario, mes_niver);

    // Imprimir informações atualizadas:
    printf("\nContato atualizado com sucesso!\n");
    printf("Contato atualizado:\n");
    printf("Nome -> %s\n", contato_buscado->informacoes->nome_contato);
    printf("Telefone -> %d\n", contato_buscado->informacoes->telefone);
    printf("Celular -> %d\n", contato_buscado->informacoes->celular);
    printf("Email -> %s\n", contato_buscado->informacoes->email);
    printf("Dia de aniversário -> %d\n", contato_buscado->informacoes->dia_de_aniversario);
    printf("Mês de aniversário -> %s\n", contato_buscado->informacoes->mes_de_aniversario);

    return agenda_passada; // Retornar a agenda atualizada
}

// Removendo elementos duplicados da string:
Agenda* removerDuplicados(Agenda* agenda_passada) {
    Agenda* contato_atual = agenda_passada;

    while (contato_atual != NULL && contato_atual->proximo_contato != NULL) {
        Agenda* contato_anterior = contato_atual;
        Agenda* contato_proximo = contato_atual->proximo_contato;

        while (contato_proximo != NULL) {
            if (strcmp(contato_atual->informacoes->nome_contato, contato_proximo->informacoes->nome_contato) == 0) {
                // Remove o nó duplicado:
                contato_anterior->proximo_contato = contato_proximo->proximo_contato;
                printf("Contato duplicado '%s' removido com sucesso!\n", contato_proximo->informacoes->nome_contato);

                // Libera memória do nó duplicado:
                free(contato_proximo->informacoes);
                free(contato_proximo);

                // Avança para o próximo nó:
                contato_proximo = contato_anterior->proximo_contato;
            } else {
                // Avança apenas quando não há remoção:
                contato_anterior = contato_proximo;
                contato_proximo = contato_proximo->proximo_contato;
            }
        }

        // Avança para o próximo nó na lista principal:
        contato_atual = contato_atual->proximo_contato;
    }

    return agenda_passada;
}

// Função que representa o menu de opções para o usuário:
void menu(Agenda* agenda_passada) {
    int opcao;
    do {
        printf("\nMenu de opções:\n");
        printf("1. Inserir contato\n");
        printf("2. Remover contato\n");
        printf("3. Buscar contato\n");
        printf("4. Atualizar contato\n");
        printf("5. Imprimir contatos\n");
        printf("6. Remover duplicados\n");
        printf("7. Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                agenda_passada = inserirContato(agenda_passada);
                break;
            case 2:
                agenda_passada = removerContato(agenda_passada);
                break;
            case 3:
                agenda_passada = buscaContato(agenda_passada);
                break;
            case 4:
                agenda_passada = atualizarContato(agenda_passada);
                break;
            case 5:
                imprimirContatos(agenda_passada);
                break;
            case 6:
                agenda_passada = removerDuplicados(agenda_passada);
                break;
            case 7:
                liberarAgenda(agenda_passada);
                exit(1);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 7);
}




