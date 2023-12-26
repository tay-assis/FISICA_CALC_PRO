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

// IMPLEMENTAÇÕES
// Inializa a lista como nula
Lista *InicializaListaForca(){
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

// insere as forças na lista de forças
Lista *InsereForcaLista(Lista *l, float valor){
    Forcas *novo = (Forcas *)malloc(sizeof(Forcas));
    novo->forca = valor;
    novo->prox = l->inicio;
    l->inicio = novo;
    return l;
}
// Desaloca lista de forças
void DesalocarListaForca(Lista *l){
    Forcas *aux = l->inicio; 
    while (aux != NULL){
        Forcas *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(l);
}

// soma o modulo das forças e retorna o valor da força resultante
float SomaListaForca(Forcas *vet){
    float soma = 0;
    Forcas *aux = vet;
    while(aux != NULL){
        soma += aux->forca;
        aux = aux->prox;
    }
    return soma;
}

void ImprimirListaForca(Forcas *list){
    Forcas *aux = list;
    while(aux != NULL){
        printf("Forca: %.10f N\n", aux->forca);
        aux = aux->prox;
    }
}

#endif  // INCLUDE_LISTA_H_