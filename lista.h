#ifndef INCLUDE_LISTA_H_
#define INCLUDE_LISTA_H_

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//ESTRUTURA
//Lista de forças
struct forcas
{
    float forca;
    struct forcas *prox;
};
typedef struct forcas Forcas;

struct lista
{
    Forcas *inicio;
};
typedef struct lista Lista;

//PROTÓTIPOS
Lista *InicializaListaForca();
Lista *InsereForcaLista(Lista *l, float valor);
void DesalocarListaForca(Lista *l);
float SomaListaForca(Forcas *vet);
void ImprimirListaForca(Forcas *list);
int BuscarForca(Forcas *f, int posicao);
void RemoverForca(Lista *l, int posicao);
// float SubtrairLista(Lista *adc, Lista *sub);

// IMPLEMENTAÇÕES
// Inializa a lista como nula
Lista *InicializaListaForca(){
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if(l == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    l->inicio = NULL;
    return l;
}

// Insere as forças na lista de forças
Lista *InsereForcaLista(Lista *l, float valor){
    Forcas *novo = (Forcas *)malloc(sizeof(Forcas));
    if(novo == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novo->forca = valor;
    novo->prox = l->inicio;
    l->inicio = novo;
    return l;
}

// Desaloca lista de forças na memória
void DesalocarListaForca(Lista *l){
    Forcas *aux = l->inicio; 
    while (aux != NULL){
        Forcas *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(l);
}

// Soma os valores das forças em módulo e retorna o valor da força resultante
float SomaListaForca(Forcas *vet){
    float soma = 0;
    Forcas *aux = vet;
    while(aux != NULL){
        soma += aux->forca;
        aux = aux->prox;
    }
    return soma;
}

// Imprime a lista de forças
void ImprimirListaForca(Forcas *list){
    Forcas *aux = list;
    int indice = 1;
    while(aux != NULL){
        printf("Forca %d: %.10f N\n", indice, aux->forca);
        aux = aux->prox;
        indice++;
    }
}

// Função que verifica se existe o valor da força na lista através da posição
int BuscarForca(Forcas *f, int posicao){
    Forcas *aux = f;
    float valor = 0;
    int cont = 1; // Posicão incial da lista
    while (aux != NULL){
        if (cont == posicao){
            valor = aux->forca;
            return valor; // Retorna o valor da força se encontrar na lista
        }else{
            aux = aux->prox;
            cont++;
        }
    }
    return 1; // Retorna 1 se não encontrar o valor da força na lista
}

// Função que remove o valor da força da lista
void RemoverForca(Lista* l, int posicao) {
    Forcas* atual = l->inicio;
    Forcas* anterior = NULL;
    float valor = BuscarForca(l->inicio, posicao);
    int cont = 1; // Posicão incial da lista
    
    //Se o valor não estiver na lista de forças
    if(valor == 1){
        printf("Forca nao encontrada, tente novamente\n");
        return ;
    //Se o valor da força estiver na lista de forças
    }else{ 
        //se o primeiro nó for o nó a ser removido
        while(anterior == NULL && cont == posicao){
            l->inicio = atual->prox;
            cont++;
            free(atual);
            return;
        }
        //se o nó a ser removido não for o primeiro
        while(atual != NULL && cont != posicao){
            anterior = atual;
            atual = atual->prox;
            cont++;
        }
        //se o nó a ser removido for encontrado
        while(atual != NULL && cont == posicao){
            anterior->prox = atual->prox;
            free(atual);
            return;
        }
    }
}

// // Função que subtrai os valores das forças de duas listas
// float SubtrairLista(Lista *adc, Lista *sub){
//     float subtracao = 0;
//     Forcas *aux_adc = adc;
//     Forcas *aux_sub = sub;
//     while(aux_adc != NULL && aux_sub != NULL){
//         if(aux_adc->forca < aux_sub->forca){
//             subtracao = aux_sub->forca - aux_adc->forca;
//         }else{
//             subtracao = aux_adc->forca - aux_sub->forca;
//         }
        
//         aux_adc = aux_adc->prox;
//         aux_adc = aux_adc->prox;
//     }
//     return subtracao;
// }

#endif  // INCLUDE_LISTA_H_