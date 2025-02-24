// Libs:
#include <stdio.h>
#include <stdlib.h>
#include "arvore_AVL.h"
#include "arvore/arvore_binaria/calculo_informacoes_gerais_arvore_binaria.h"
#define max(a, b) ((a) > (b) ? (a) : (b)) // Função que define o maior entre dois valores


ArvoreAVL* criarArvoreAVL(int informacao){
    /* Função que cria um novo nó da arvore AVL: */
    
    ArvoreAVL* arvore_criada = (ArvoreAVL*)malloc(sizeof(ArvoreAVL));

    // Definindo valores:
    if(arvore_criada != NULL){
        arvore_criada->informacao = informacao;
        arvore_criada->esquerda = NULL;
        arvore_criada->direita = NULL;
        arvore_criada->altura = 0;
    }
    return arvore_criada;
}

int obterBalancoDeArvore(ArvoreAVL* arvore_passada){
    /* Função que retorna o balanco de uma arvore AVL: */
    
    if (arvore_passada == NULL){
        return 0;
    }
    return arvore_passada->esquerda->altura - arvore_passada->direita->altura;
}

ArvoreAVL* rotacionarEsquerda(ArvoreAVL* arvore_passada){
    /* Função que realiza a rotacao esquerda de uma arvore AVL: */
    
    // Implementar....
}


ArvoreAVL* rotacionarDireita(ArvoreAVL* arvore_passada){
    /* Função que realiza a rotacao direita de uma arvore AVL: */
    
    // Implementar....
}


ArvoreAVL *inserirElementoNaArvoreAVL(ArvoreAVL* arvore_passada, int informacao){
    
    // Criando novo nó quando acho uma folha:
    if(arvore_passada == NULL){
        return criarArvoreAVL(informacao);
    }

    // Buscando onde inserir com base no valor da informação:
    if(informacao < arvore_passada->informacao){
        arvore_passada->esquerda = inserirElementoNaArvoreAVL(arvore_passada->esquerda, informacao);
    }
    else if(informacao > arvore_passada->informacao){
        arvore_passada->direita = inserirElementoNaArvoreAVL(arvore_passada->direita, informacao);
    }
    else{
        return arvore_passada;
    }

    // Atualizando altura da árvore depois da inserção:
    arvore_passada->altura = 1 + max(arvore_passada->esquerda->altura, arvore_passada->direita->altura);

    // Obtendo balaciamento:
    int balanco = obterBalancoDeArvore(arvore_passada);

    // Fazendo a rotação em caso de desbalanceamento:

        // Rotação LL:
        if(balanco > 1 && informacao < arvore_passada->esquerda->informacao){
            return rotacionarDireita(arvore_passada);
        }

        // Rotação RR:
        if(balanco < -1 && informacao > arvore_passada->direita->informacao){
            return rotacionarEsquerda(arvore_passada);
        }

        // Rotação LR: 
        if(balanco > 1 && informacao > arvore_passada->esquerda->informacao){
            arvore_passada->esquerda = rotacionarEsquerda(arvore_passada->esquerda);
            return rotacionarDireita(arvore_passada);
        }
        
        // rotação RL:
        if(balanco < -1 && informacao < arvore_passada->direita->informacao){
            arvore_passada->direita = rotacionarDireita(arvore_passada->direita);
            return rotacionarEsquerda(arvore_passada);
        }

    return arvore_passada;
}

ArvoreAVL* buscarElementoNaArvoreAVL(ArvoreAVL* arvore_passada, int informacao){
    /* Função que busca um elemento na arvore AVL: */

    // Casos onde a árvore é nula ou o elemento é a raiz:
    if(arvore_passada == NULL || arvore_passada->informacao == informacao){
        return arvore_passada;
    }

    // Buscando o elemento com base no valor passado:
    if(informacao < arvore_passada->informacao){
        return buscarElementoNaArvoreAVL(arvore_passada->esquerda, informacao);
    }
    
    return buscarElementoNaArvoreAVL(arvore_passada->direita, informacao);
}

ArvoreAVL* removerElementoDaArvoreAVL(ArvoreAVL* arvore_passada, int informacao){
    /* Função que remove um elemento da arvore AVL: */

    // Casos onde elemento não é achado:
    if (arvore_passada == NULL){
        return arvore_passada;
    }

    // Buscando o elemento com base no valor passado:
    if(informacao < arvore_passada->informacao){
        arvore_passada->esquerda = removerElementoDaArvoreAVL(arvore_passada->esquerda, informacao);
    }
    else if(informacao > arvore_passada->informacao){
        arvore_passada->direita = removerElementoDaArvoreAVL(arvore_passada->direita, informacao);
    }
    // Quando encontro o elemento, verifico a quantidade de filhos que o mesmo tem(se possúi 1 ou nenhum):
    else{
        if(arvore_passada->esquerda == NULL){
            return arvore_passada->direita;
        }
        else if(arvore_passada->direita == NULL){
            return arvore_passada->esquerda;
        }
        // Em casos onde o nó possúi dois filhos, substituirei pelo maior filho à esquerda:
        ArvoreAVL* maior_filho_a_esquerda = obterMaiorValorDaArvore(arvore_passada->esquerda);
        arvore_passada->informacao = maior_filho_a_esquerda->informacao;    
        arvore_passada->esquerda = removerElementoDaArvoreAVL(arvore_passada->esquerda, maior_filho_a_esquerda->informacao);
    }

    // Atualizando altura da árvore depois da remoção:
    arvore_passada->altura = 1 + max(arvore_passada->esquerda->altura, arvore_passada->direita->altura);

    // Obtendo balanco:
    int balanco = obterBalancoDeArvore(arvore_passada);

    // Fazendo rotacao em caso de desbalanceamento:
        // Rotação LL:
        if(balanco > 1 && informacao < arvore_passada->esquerda->informacao){
            return rotacionarDireita(arvore_passada);
        }

        // Rotação RR:
        if(balanco < -1 && informacao > arvore_passada->direita->informacao){
            return rotacionarEsquerda(arvore_passada);
        }
        
        // Rotação LR:
        if(balanco > 1 && informacao > arvore_passada->esquerda->informacao){
            arvore_passada->esquerda = rotacionarEsquerda(arvore_passada->esquerda);
            return rotacionarDireita(arvore_passada);
        }   

        // Rotação RL:
        if(balanco < -1 && informacao < arvore_passada->direita->informacao){
            arvore_passada->direita = rotacionarDireita(arvore_passada->direita);
            return rotacionarEsquerda(arvore_passada);
        }   
    
    return arvore_passada;
}

void imprimirArvoreAVL(ArvoreAVL* arvore_passada){
    /* Função que imprime uma arvore AVL de forma recursiva */

    if(arvore_passada == NULL){
        return;
    }
    imprimirArvoreAVL(arvore_passada->esquerda);
    printf("No %d --- Valor -> %d\n", arvore_passada->altura, arvore_passada->informacao);
    imprimirArvoreAVL(arvore_passada->direita);
}

void liberarArvoreAVL(ArvoreAVL* arvore_passada){
    /* Função que libera uma arvore AVL de forma recursiva */

    // Quando acho uma folha, retorno vazio para voltar na chamada recursiva:
    if(arvore_passada == NULL){
        return;
    }   

    // Liberando filhos:
    liberarArvoreAVL(arvore_passada->esquerda);
    liberarArvoreAVL(arvore_passada->direita);
    free(arvore_passada);
}
