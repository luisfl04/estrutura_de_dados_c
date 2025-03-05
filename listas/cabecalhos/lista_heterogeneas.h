// Libs:
#include <stdio.h>
#include <stdlib.h>

// Definindo os tipos de dados:
#define RETANGULO 0
#define TRIANGULO 1
#define CIRCULO 2
#define PI 3.14

// Estruturas que representam as informações que o meu nó de lista pode armazenar:
typedef struct retangulo {
    float base;
    float altura;
} Retangulo;

typedef struct circulo{
    float raio;
} Circulo;

typedef struct triangulo{
    float base;
    float altura;
} Triangulo;

// Nó da lista:
typedef struct  lista_heterogenea{
    int tipo_de_dado;
    void *informacao_armazenada;
    struct lista_heterogenea* proxima_lista;
} ListaHeterogenea;

// função que cria um nó com retangulo:
ListaHeterogenea* criarRetangulo(ListaHeterogenea* lista_passada, float base, float altura){
    // Alocando memória:
    Retangulo* novo_retangulo = (Retangulo*) malloc(sizeof(Retangulo));
    ListaHeterogenea* nova_lista = (ListaHeterogenea*) malloc(sizeof(ListaHeterogenea));

    // Atribuindo valores:
    novo_retangulo->base = base;
    novo_retangulo->altura = altura;
    nova_lista->tipo_de_dado = RETANGULO;
    nova_lista->informacao_armazenada = novo_retangulo;
    nova_lista->proxima_lista =  lista_passada;

    return nova_lista;  
}

// Função que cria um triângulo:
ListaHeterogenea* criarTriangulo(ListaHeterogenea* lista_passada, float base, float altura){
    // Alocando memória:
    Triangulo* novo_triangulo = (Triangulo*) malloc(sizeof(Triangulo));
    ListaHeterogenea* nova_lista = (ListaHeterogenea*) malloc(sizeof(ListaHeterogenea));

    // Atribuindo valores:
    novo_triangulo->base = base;
    novo_triangulo->altura = altura;
    nova_lista->tipo_de_dado = TRIANGULO;
    nova_lista->informacao_armazenada = novo_triangulo;
    nova_lista->proxima_lista =  lista_passada;

    return nova_lista;  
}

// Função que cria um circulo:
ListaHeterogenea* criarCirculo(ListaHeterogenea* lista_passada, float raio){
    // Alocando memória:
    Circulo* novo_circulo = (Circulo*) malloc(sizeof(Circulo));
    ListaHeterogenea* nova_lista = (ListaHeterogenea*) malloc(sizeof(ListaHeterogenea));

    // Atribuindo valores:
    novo_circulo->raio = raio;
    nova_lista->tipo_de_dado = CIRCULO;
    nova_lista->informacao_armazenada = novo_circulo;
    nova_lista->proxima_lista =  lista_passada;

    return nova_lista;  
}

// Funções que calculam a área dos tipos de dados:
    // Retangulo:
    static float calcularAreaRetangulo(Retangulo* retangulo_passado){
        return retangulo_passado->base * retangulo_passado->altura;
    }
    // Triangulo:
    static float calculaarAreaTriangulo(Triangulo* triangulo_passado){
        return (triangulo_passado->base * triangulo_passado->altura) / 2;
    }
    // Circulo:
    static float calculaarAreaCirculo(Circulo* circulo_passado){
        return PI * (circulo_passado->raio * circulo_passado->raio);
    }

// Função que obtém a área da informação de acordo com o tipo do nó da lista:
static float obterArea(ListaHeterogenea* lista_passada){
    float area;

    switch(lista_passada->tipo_de_dado){
        case RETANGULO:
            area = calcularAreaRetangulo((Retangulo*) lista_passada->informacao_armazenada);
            break;
        case TRIANGULO:
            area = calculaarAreaTriangulo((Triangulo*) lista_passada->informacao_armazenada );
            break;
        case CIRCULO:
            area = calculaarAreaCirculo( (Circulo*) lista_passada->informacao_armazenada );
            break;
        default:
            printf("Valor de tipo de dado invalido!");
            break;
    }   

    return area;
}

// Função que recebe a lista e verifica qual a maior aréa entre os valores armazenados:
static ListaHeterogenea* calcularMaiorValorDeArea(ListaHeterogenea* lista_passada){
    // Verificando se a lista está vazia:
    if(lista_passada == NULL){
        printf("Impossivel calcular valor, a lista esta vazia.");
        exit(1);
    }

    // Lista que armazena o maior valor e ponteiro de acesso:
    ListaHeterogenea* maior_lista = NULL;
    ListaHeterogenea* ponteiro_de_acesso = lista_passada;

    // Obtendo maior valor:
    while(ponteiro_de_acesso != NULL){
        if(ponteiro_de_acesso->proxima_lista == NULL){
            maior_lista = ponteiro_de_acesso;   
        }
        else if( obterArea(ponteiro_de_acesso) > obterArea(ponteiro_de_acesso->proxima_lista) ){
            maior_lista = ponteiro_de_acesso;
        }
        else{
            maior_lista = ponteiro_de_acesso->proxima_lista;
        }
    
        ponteiro_de_acesso = ponteiro_de_acesso->proxima_lista;
        free(ponteiro_de_acesso);
    }

    // Exibindo valores:
    printf("Maior valor de area encontrado na lista -> %.2f\nTipo de dado -> %d\n", obterArea(maior_lista), maior_lista->tipo_de_dado);

    return maior_lista;
}


