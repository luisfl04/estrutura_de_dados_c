#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa os nós lista:
typedef struct lista{
    int informacao;
    struct lista* proximo;
} Lista;


// Função que cria uma lista:
Lista* criarLista(){
    return NULL;
}

// Função que insere um elemento na lista:
Lista* inserirElemento(Lista* lista_apontada, int elemento_inserido){
    // Criando nova lista que receberá os valores e será retornada:
    Lista* nova_lista = (Lista*) malloc(sizeof(Lista));

    // Inserindo valores:
    nova_lista->informacao = elemento_inserido;
    nova_lista->proximo = lista_apontada;

    return nova_lista;
}   

// Função que verifica se a lista está vazia:
int verificarListaVazia(Lista* lista_passada){
    if(lista_passada == NULL){
        return 1;
    }
    
    return 0;
}

// Função que imprime os valores da lista:
void imprimirLista(Lista* lista_impressa){
    // Imprimirá a informação que está sendo armazenada na lista e logo em seguida chamará a mesma função recursivamente.

    if(!verificarListaVazia(lista_impressa)){
        printf(" [%d] ", lista_impressa->informacao);
        imprimirLista(lista_impressa->proximo);
    }
}

// função que realiza a busca de um elemento na lista:
Lista* buscarElementoNaLista(Lista* lista_passada, int valor_pesquisado){
    // Ponteiro que faz a comparação dos elementos:
    Lista* ponteiro_de_busca;

    // Busca do elemento:
    for(ponteiro_de_busca = lista_passada; ponteiro_de_busca != NULL; ponteiro_de_busca = ponteiro_de_busca->proximo){
        if(ponteiro_de_busca->informacao == valor_pesquisado){
            printf("Valor encontrado!\n");
            return ponteiro_de_busca;
        }
    }

    free(ponteiro_de_busca);
    return NULL;
}

// Função que remove um elemento da lista caso ele esteja presente:
Lista* removerElementoDaLista(Lista* lista_passada, int elemento_para_retirar){
    
    // Verificando se a lista passada é nula:
    if(verificarListaVazia(lista_passada)){
        return NULL;
    }

    // Ponteiros usados:
    Lista* ponteiro_busca = lista_passada; // Ponteiro que será usado para percorrer a lista. 
    Lista* ponteiro_auxiliar = NULL; // ponteiro que armazena a lista atual antes do ponteiro de busca ser alterado, para evitar perda de informação.

    // Fazendo a procura do elemento passado na lista:
    while(ponteiro_busca != NULL && ponteiro_busca->informacao != elemento_para_retirar){
        ponteiro_auxiliar = ponteiro_busca;
        ponteiro_busca = ponteiro_busca->proximo;
    }

    // Verificando se o elemento foi encontrado:

        // Não achou, retorna a lista passada:
        if(ponteiro_busca == NULL){
            return lista_passada;
        }

        // Se achou, retira o elemento:
        if(ponteiro_auxiliar == NULL){
            // Retirando elemento do início:
            lista_passada = ponteiro_busca->proximo;
        }
        else{
            ponteiro_auxiliar->proximo = ponteiro_busca->proximo;
        }
    
    // removendo elemento:
    free(ponteiro_busca);

    return lista_passada;
}  

// Função que libera todos os elementos alocados:
void liberarLista(Lista* lista_passada){
    Lista* ponteiro_de_acesso = lista_passada;

    while(ponteiro_de_acesso != NULL){
        Lista* lista_temporaria = ponteiro_de_acesso->proximo;
        free(ponteiro_de_acesso);
        ponteiro_de_acesso = lista_temporaria;
    }
}

// função que insere elementos na lista ordenadamente:
Lista* inserirElementoOrdenado(Lista* lista_passada, int elemento_inserido){
    // Elementos usados na inserção:
    Lista* lista_anterior = NULL;    
    Lista* ponteiro_de_acesso = lista_passada;
    
    // Percorrendo lista para encontrar a posição de inserção:
    while(ponteiro_de_acesso != NULL && ponteiro_de_acesso->informacao < elemento_inserido){
        lista_anterior = ponteiro_de_acesso;
        ponteiro_de_acesso = ponteiro_de_acesso->proximo;
    }

    // Criando novo elemento:
    Lista* novo_elemento = inserirElemento(lista_passada, elemento_inserido);

    
    // Organizando o elemento na lista:
    if(lista_anterior == NULL){
        novo_elemento->proximo = lista_passada;
        lista_passada = novo_elemento;
    }
    else {
        novo_elemento->proximo = lista_anterior->proximo;
        lista_anterior->proximo = novo_elemento;
    }

    return lista_passada;
}   

// Implementação de função que retira um elemento da lista usando recursividade:
Lista* retirarElementoListaRecursivamente(Lista* lista_passada, int elemento_a_ser_retirado){
    if(!verificarListaVazia(lista_passada)){
        // Implementação de retirada para o caso do elemento a ser retirado ser o primeiro:
        if(lista_passada->informacao == elemento_a_ser_retirado){
            Lista* lista_temporaria = lista_passada;
            lista_passada = lista_passada->proximo;
            free(lista_temporaria);
        }
        else{
            // Chamada recursiva até achar o elemento a ser retirado(Se achar).
            lista_passada->proximo = retirarElementoListaRecursivamente(lista_passada->proximo, elemento_a_ser_retirado);
        }
    }

    return lista_passada;
}

// Função que verifica se duas listas são iguais:
int verificarIgualdadeLista(Lista* lista_um, Lista* lista_dois){
    // Ponteiros que acessam os valores:
    Lista* ponteiro_um;
    Lista* ponteiro_dois;

    // Percorrendo listas enquanto elas tiverem valores iguais:
    for(ponteiro_um = lista_um, ponteiro_dois = lista_dois; 
        ponteiro_um != NULL && ponteiro_dois != NULL;
        ponteiro_um = ponteiro_um->proximo, ponteiro_dois = ponteiro_um->proximo ){
            // Verificando informações
            if(ponteiro_um->informacao != ponteiro_dois->informacao){
                return 0;
            }
    }

    // Se no acesso ao elementos foi percorrido até a ultima sub-lista, então as listas são iguais:
    return ponteiro_um == ponteiro_dois; // Retorna 1(True);
}

// Vericação de igualdade de lista de modo recursivo:
int verificarIgauldadeListaRecursivamente(Lista* lista_um, Lista* lista_dois){
    // Verificando se as duas listas estão vazias:
    if(lista_um == NULL && lista_dois == NULL){
        return 1;
    }
    // Verificando se alguma das duas são vazias:
    else if(lista_um == NULL || lista_dois == NULL){
        return 0;
    }
    else{
        return lista_dois->informacao == lista_um->informacao && verificarIgauldadeListaRecursivamente(lista_um->proximo, lista_dois->proximo);
    }
}





