#ifndef fisica_calc_H_INCLUDED
#define fisica_calc_H_INCLUDED

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// CONSTANTES
#define PERM_VACUO 8.854e-12
#define ELETROSTATICA 9.0e-9
#define MOD_CARGA 1.602e-19

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
void Inicializador();
void MenuFisica();
int VerificarMod();
int VerificaCarga();
//void ModForcaEletrostatica();
int RespostaCalc();
float CalcForca(float q1, float q2, float d);
float CalcDistancia(float f, float q1, float q2);
float CalcCarga(float f, float q, float d, int resp);
Lista *CalForcaResultante(Lista *l, float q1, float q2, float d);
float SomaListaForca(Forcas *vet);
void ImprimirListaForca(Forcas *list);
//int verificar_resp(int resp);

// IMPLEMENTAÇÕES
// // Inializa a lista como nula
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

void Inicializador(){
    system("cls");
    printf("CALCULADORA DE FISICA III\n");
    printf("Eletricidade e Eletromagnetismo\n");
    system("pause");
}
void MenuFisica(){
    system("cls");
    printf("Formulas:\n");
    printf("1-Forca Eletrostatica\n");
    printf("2-Quantizacao da Carga Eletrica\n");
    printf("3-Sair\n");
    printf("Escolha uma opcao:\n");
}

// função que verifica se o usuario deseja trabalhar com modulo
int VerificarMod(){
    int resp = 0;
    printf("Deseja trabalhar com modulo? (1-Sim/2-Nao)\n");
    if(scanf("%d", &resp) == 1) return 1;
    else return 0;
}

// função que verifica quais dados o usuário quer calcular
int RespostaCalc(){
    int resp = 0;
    system("cls");
    printf("O que voce deseja calcular?\n");
    printf("1-Forca\n");
    printf("2-Carga 1 ou Carga 2\n");
    printf("3-Carga\n");
    printf("4-Distancia\n");
    printf("5-Voltar\n");
    scanf("%d", &resp);
    return resp;
}

// função que calcula a força de uma ou entre duas cargas
float CalcForca(float q1, float q2, float d){
    float f = 0;
    if (q2 == 0) f = (ELETROSTATICA * q1) / (d * d);
    else f = (ELETROSTATICA * q1 * q2) / (d * d);
    return f;
}
// função que calcula uma das partículas ou a carga total
float CalcCarga(float f, float q, float d, int resp){
    float carga = 0;
    if(resp == 2) carga = (f * d * d) / (ELETROSTATICA * q); // calcula uma das cargas se a outra existir
    else carga = (f * d * d) / (ELETROSTATICA); // calcula a carga total se nenhuma das duas existir
    return carga;
}

//função que verifica se possui duas cargas e retorna true se tiverem duas cargas e false se tiver apenas uma
int VerificaCarga(){
    int resp = 0;
    printf("Possui carga 1 e carga 2 (1-Sim/2-Nao)?\n");
    if(scanf("%d", &resp) == 1) return 1;
    else return 0;
}

// função que verifica se o usuário quer calcular a força resultante em uma carga qualquer
int VerificaForcaResultante(){
    int resp = 0;
    system("cls");
    printf("Quer encontrar forca resultante em uma carga (1-Sim/2-Nao)?\n");
    if(scanf("%d", &resp) == 1) return 1;
    else return 0;
}

// função que calcula a distância de uma carga a algum ponto ou entre duas cargas
float CalcDistancia(float f, float q1, float q2){
    float d = 0;
    if(q2 == 0) d = sqrt((ELETROSTATICA * q1) / f);
    else d = sqrt((ELETROSTATICA * q1 * q2) / f);
    return d;
}

void ModForcaEletrostatica(){
    float f = 0, q1 = 0, q2 = 0, d = 0;
    //Forcas *vet = InicializaListaForca();
    int resp = 0;
    resp = RespostaCalc();
    switch (resp){
        case 1:
            if(VerificaForcaResultante() != 1){
                if(!VerificaCarga()){
                    system("cls");
                    printf("Digite o valor da carga (C): ");
                    scanf("%f", &q1);
                    printf("Digite o valor da distancia (m): ");
                    scanf("%f", &d);
                    f = CalcForca(q1, q2, d);
                    printf("A forca eletrostatica e: %.10f N\n", f);
                    system("pause");
                }
                else{
                    system("cls");
                    printf("Digite o valor da carga 1 (C): ");
                    scanf("%f", &q1);
                    printf("Digite o valor da carga 2 (C): ");
                    scanf("%f", &q2);
                    printf("Digite o valor da distancia (m): ");
                    scanf("%f", &d);
                    f = CalcForca(q1, q2, d);
                    printf("A forca eletrostatica e: %.10f N\n", f);
                    system("pause");
                }
            }else{
                Lista *l = InicializaListaForca();
                l = CalForcaResultante(l, q1, q2, d);
                ImprimirListaForca(l->inicio);
                f = SomaListaForca(l->inicio);

                printf("A forca eletrostatica resultante e: %.10f N\n", f);
                system("pause");
                DesalocarListaForca(l);
            }
                break;
        case 2:
            printf("Digite o valor da forca (N): ");
            scanf("%f", &f);
            printf("Digite o valor da carga 2 (C): ");
            scanf("%f", &q2);
            printf("Digite o valor da distancia (m): ");
            scanf("%f", &d);
            q1 = CalcCarga(f, q2, d, resp);
            printf("O valor da carga desejada e: %.10f C\n", q1);
            system("pause");

            break;
        case 3:
            printf("Digite o valor da forca (N): ");
            scanf("%f", &f);
            printf("Digite o valor da distancia (m): ");
            scanf("%f", &d);
            q1 = CalcCarga(f, q2, d, resp);
            printf("O valor da carga desejada e: %f C\n", q1);
            system("pause");

            break;
        case 4:
            if(!VerificaCarga()){
                printf("Digite o valor da forca (N): ");
                scanf("%f", &f);
                printf("Digite o valor da carga (C): ");
                scanf("%f", &q1);
                d = CalcDistancia(f, q1, q2);
                printf("A distancia e: %f m\n", d);
                system("pause");
            }else{
                printf("Digite o valor da forca (N): ");
                scanf("%f", &f);
                printf("Digite o valor da carga 1 (C): ");
                scanf("%f", &q1);
                printf("Digite o valor da carga 2 (C): ");
                scanf("%f", &q2);
                d = CalcDistancia(f, q1, q2);
                printf("A distancia e: %f m\n", d);
                system("pause");
            }
            break;
        case 5:
            //DesalocarListaForca(vet);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
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

// função que cria uma lista de forças enquanto o usuário desejar
// o cálculo é feito com base no cálcula da força eletrostática entre duas cargas
Lista *CalForcaResultante(Lista *l, float q1, float q2, float d){
    Lista *aux = l;
    float f = 0;
    int resp = 0;
    system("cls");
    printf("Calculando a Forca Resultante em uma carga\n");
    system("pause");   
    do{
        printf("Digite o valor da carga 1 (C): ");
        scanf("%f", &q1);
        printf("Digite o valor da carga 2 (C): ");
        scanf("%f", &q2);
        printf("Digite o valor da distancia (m): ");
        scanf("%f", &d);
        f = CalcForca(q1, q2, d);
        printf("A forca eletrostatica e: %.10f N\n", f);
        
        aux = InsereForcaLista(aux, f);
        printf("Deseja parar? (1-Sim/2-Nao)\n");
        scanf("%d", &resp);

    }while(resp != 1);
    return aux;
}

void ImprimirListaForca(Forcas *list){
    Forcas *aux = list;
    while(aux != NULL){
        printf("Forca: %.10f N\n", aux->forca);
        aux = aux->prox;
    }
}

#endif