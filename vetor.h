#ifndef VETOR_H_INCLUDED
#define VETOR_H_INCLUDED

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ESTRUTURA
struct vetor
{
    float x;
    float y;
    float z;
};

typedef struct vetor Vetor;

//PROTOTIPOS
Vetor *CriaVetor(float x, float y, float z);
int VerificaVetorNulo(Vetor *v);
void LiberaVetor(Vetor *v);
void AtribuiVetor(Vetor *v, float x, float y, float z);
void ImprimeVetor(Vetor *v);
Vetor *SomaVetor(Vetor *v1, Vetor *v2);
Vetor *SubtraiVetor(Vetor *v1, Vetor *v2);
Vetor *MultiplicaVetor(Vetor *v1, float escalar);
Vetor *DivideVetor(Vetor *v1, float escalar);
float ProdutoEscalar(Vetor *v1, Vetor *v2);
Vetor *ProdutoVetorial(Vetor *v1, Vetor *v2);
float ModuloVetor(Vetor *v1);
//Vetor *NormalizaVetor(Vetor *v1);
float AnguloVetor(Vetor *v1, Vetor *v2);

//IMPLEMENTACAO
// Funcao que cria o vetor e aloca a memoria
Vetor *CriaVetor(float x, float y, float z)
{
    Vetor *v = (Vetor *)malloc(sizeof(Vetor));
    if (v == NULL)
    {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

// Funcao que verifica se o vetor é nulo
int VerificaVetorNulo(Vetor *v)
{
    if (v->x == NULL && v->y == NULL && v->z == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Funcao que libera o vetor
void LiberaVetor(Vetor *v)
{
    free(v);
}

// Funcao que atribui valores a um vetor já existente
void AtribuiVetor(Vetor *v, float x, float y, float z){
    v->x = x;
    v->y = y;
    v->z = z;
}

// Funcao que imprime o vetor
void ImprimeVetor(Vetor *v)
{
    printf("Vetor: %.10fi + %.10fj + %.10fk\n", v->x, v->y, v->z);
}

// Funcao que soma dois vetores
Vetor *SomaVetor(Vetor *v1, Vetor *v2)
{
    Vetor *v = CriaVetor(0, 0, 0);
    v->x = v1->x + v2->x;
    v->y = v1->y + v2->y;
    v->z = v1->z + v2->z;
    return v;
}

// Funcao que subtrai dois vetores
Vetor *SubtraiVetor(Vetor *v1, Vetor *v2)
{
    Vetor *v = CriaVetor(0, 0, 0);
    v->x = v1->x - v2->x;
    v->y = v1->y - v2->y;
    v->z = v1->z - v2->z;
    return v;
}

// Funcao que multiplica um vetor por um escalar
Vetor *MultiplicaVetor(Vetor *v1, float escalar){
    Vetor *v = CriaVetor(0,0,0);
    v->x = escalar * v1->x;
    v->y = escalar * v1->y;
    v->z = escalar * v1->z;
    return v;
}

#endif