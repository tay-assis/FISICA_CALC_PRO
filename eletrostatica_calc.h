#ifndef fisica_calc_H_INCLUDED
#define fisica_calc_H_INCLUDED

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"

// CONSTANTES
#define PERM_VACUO 8.854e-12
#define ELETROSTATICA 9.0e-9
#define CARG_ELEM 1.602e-19

//PROTÓTIPOS
void Inicializador();
void MenuFisica();
int VerificarMod();
int VerificaCarga();
int VerificarSubtracaoForca();
int VerificarForcaSub();
void ModForcaEletrostatica();
int RespostaCalc();
float CalcForca(float q1, float q2, float d);
float CalcDistancia(float f, float q1, float q2);
float CalcCarga(float f, float q, float d, int resp);
Lista *CalForcaResultante(Lista *l, float q1, float q2, float d);
float SubtracaoForca(float f, float f2);
// void *ExcluirForcas(Lista *l, Lista *sub);
float CalcQuantCarga(float n_protons, float n_eletrons, float q);
void VerificarQuantCarga();
void VetForcaEletrostatica();

// IMPLEMENTAÇÕES
// Função que imprime o nome do programa
void Inicializador(){
    system("cls"); // Limpa a tela
    printf("CALCULADORA DE FISICA III\n");
    printf("Eletricidade e Eletromagnetismo\n");
    system("pause");
}

// Função que imprime o menu de opções
void MenuFisica(){
    system("cls"); // Limpa a tela
    printf("Formulas:\n");
    printf("1-Forca Eletrostatica\n");
    printf("2-Quantizacao da Carga Eletrica\n");
    printf("3-Sair\n");
    printf("Escolha uma opcao:\n");
}

// Função que verifica se o usuario deseja trabalhar com modulo
int VerificarMod(){
    int resp = 0;
    printf("Deseja trabalhar com modulo? (1-Sim/2-Nao)\n");
    if(scanf("%d", &resp) == 1) return 1;
    else return 0;
}

// Função que verifica quais dados o usuário quer calcular
int RespostaCalc(){
    int resp = 0;
    system("cls"); // Limpa a tela
    printf("O que voce deseja calcular?\n");
    printf("1-Forca\n");
    printf("2-Carga 1 ou Carga 2\n");
    printf("3-Carga\n");
    printf("4-Distancia\n");
    printf("5-Voltar\n");
    scanf("%d", &resp);
    return resp;
}

// Função que calcula a força de uma ou entre duas cargas
float CalcForca(float q1, float q2, float d){
    float f = 0;
    if (q2 == 0) f = (ELETROSTATICA * q1) / (d * d);
    else f = (ELETROSTATICA * q1 * q2) / (d * d);
    return f;
}

// Função que calcula uma das partículas ou a carga total
float CalcCarga(float f, float q, float d, int resp){
    float carga = 0;
    if(resp == 2) carga = (f * d * d) / (ELETROSTATICA * q); // calcula uma das cargas se a outra existir
    else carga = (f * d * d) / (ELETROSTATICA); // calcula a carga total se nenhuma das duas existir
    return carga;
}

// Função que verifica se possui duas cargas e retorna true se tiverem duas cargas e false se tiver apenas uma
int VerificaCarga(){
    int resp = 0;
    printf("Possui mais de 1 carga (1-Sim/2-Nao)?\n");
    scanf("%d", &resp);
    if(resp == 1) return 1;
    else return 0;
}

// Função que verifica se o usuário quer calcular a força resultante em uma carga qualquer
int VerificaForcaResultante(){
    int resp = 0;
    system("cls"); // Limpa a tela
    printf("Quer encontrar forca resultante em uma carga (1-Sim/2-Nao)?\n");
    scanf("%d", &resp);
    if(resp == 1) return 1;
    else return 0;
}

// Função que verifica se o usuário quer subtrair alguma força calculada
int VerificarSubtracaoForca(){
    int resp = 0;
    system("cls"); // Limpa a tela
    printf("Ha forcas para serem subtraidas (1-Sim/2-Nao)?\n");
    scanf("%d", &resp);
    if(resp == 1) return 1;
    else return 0;
}

int VerificarForcaSub(){
    int resp = 0;
    system("cls"); // Limpa a tela
    printf("Deseja subtrair a forca a ser calculada (1-Sim/2-Nao)?\n");
    scanf("%d", &resp);
    if(resp == 1) return 1;
    else return 0;
}

// Função que calcula a distância de uma carga a algum ponto ou entre duas cargas
float CalcDistancia(float f, float q1, float q2){
    float d = 0;
    if(q2 == 0) d = sqrt((ELETROSTATICA * q1) / f);
    else d = sqrt((ELETROSTATICA * q1 * q2) / f);
    return d;
}

// Função principal que contém funções auxiliares para calcular a força eletrostática em módulo
void ModForcaEletrostatica(){
    float f = 0, f2 = 0, q1 = 0, q2 = 0, d = 0, valor = 0;
    //Forcas *vet = InicializaListaForca();
    int resp = 0;
    resp = RespostaCalc();
    switch (resp){
        case 1:
            if(!VerificaCarga()){
                system("cls"); // Limpa a tela
                printf("Calculando a Forca Eletrostatica de uma Carga\n");
                printf("Digite o valor da carga (C): ");
                scanf("%f", &q1);
                printf("Digite o valor da distancia (m): ");
                scanf("%f", &d);
                f = CalcForca(q1, q2, d);
                printf("A forca eletrostatica e: %.10f N\n", f);
                system("pause"); // Pausa o programa
            }else{
                if(!VerificaForcaResultante()){
                    printf("Calculando a Força Eletrostatica entre duas Cargas\n");
                        system("cls");
                        printf("Digite o valor da carga 1 (C): ");
                        scanf("%f", &q1);
                        printf("Digite o valor da carga 2 (C): ");
                        scanf("%f", &q2);
                        printf("Digite o valor da distancia (m): ");
                        scanf("%f", &d);
                        f = CalcForca(q1, q2, d);
                        printf("A forca eletrostatica e: %.10f N\n", f);
                        system("pause"); // Pausa o programa
                }else{
                    Lista *l = InicializaListaForca();
                    Lista *sub = InicializaListaForca();
                        // Se o usuário desejar subtrair alguma força, chama a função que adiciona forças na lista de forças subtrativas
                        if(VerificarSubtracaoForca()){
                            int resp = 0;
                            do{
                                if(VerificarForcaSub()){
                                    system("cls"); // Limpa a tela
                                    printf("Calculando a Forca Eletrostatica a ser Subtraida\n");
                                    sub = CalForcaResultante(sub, q1, q2, d);
                                    f = SomaListaForca(sub->inicio);
                                }else{
                                    printf("Calculando a Forca Eletrostatica a ser Adicionada\n");
                                    l = CalForcaResultante(l, q1, q2, d);
                                    f2 = SomaListaForca(l->inicio);
                                }
                            printf("Deseja calcular mais forcas (1-Sim/2-Nao)?\n");
                            scanf("%d", &resp);
                            }while(resp == 1);    
                            valor = SubtracaoForca(f, f2);
                            printf("A forca eletrostatica resultante e: %.10f N\n", valor);
                            system("pause"); // Pausa o programa
                        // Se o usuário não desejar subtrair nenhuma força, apenas soma as forças
                        }else{
                            l = CalForcaResultante(l, q1, q2, d);
                            f = SomaListaForca(l->inicio);
                            printf("A forca eletrostatica resultante e: %.10f N\n", f);
                            system("pause"); // Pausa o programa
                        }
                    DesalocarListaForca(l);
                    DesalocarListaForca(sub);
                }
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
            system("pause"); // Pausa o programa

            break;
        case 3:
            printf("Digite o valor da forca (N): ");
            scanf("%f", &f);
            printf("Digite o valor da distancia (m): ");
            scanf("%f", &d);
            q1 = CalcCarga(f, q2, d, resp);
            printf("O valor da carga desejada e: %f C\n", q1);
            system("pause"); // Pausa o programa

            break;
        case 4:
            if(!VerificaCarga()){
                printf("Digite o valor da forca (N): ");
                scanf("%f", &f);
                printf("Digite o valor da carga (C): ");
                scanf("%f", &q1);
                d = CalcDistancia(f, q1, q2);
                printf("A distancia e: %f m\n", d);
                system("pause"); // Pausa o programa
            }else{
                printf("Digite o valor da forca (N): ");
                scanf("%f", &f);
                printf("Digite o valor da carga 1 (C): ");
                scanf("%f", &q1);
                printf("Digite o valor da carga 2 (C): ");
                scanf("%f", &q2);
                d = CalcDistancia(f, q1, q2);
                printf("A distancia e: %f m\n", d);
                system("pause"); // Pausa o programa
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

// Função que cria uma lista de forças para calcular a força resultante em módulo
Lista *CalForcaResultante(Lista *l, float q1, float q2, float d){
    Lista *aux = l;
    float f = 0;
    int resp = 0;  
    
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

// // função que adiciona forças na lista de forças subtrativas
// void ExcluirForcas(Lista *l, Lista *sub){
//     int posicao = 0, resp = 0;
//     float valor = 0;
//     system("cls"); // Limpa a tela
//     printf("Forca Eletrostatica Calculadas:\n");
//     do{
//         ImprimirListaForca(l->inicio);
//         printf("Quais dessas forcas voce deseja subtrair?\n(Digite o numero da Forca -> 1, 2, etc)\n");
//         scanf("%d", &posicao);
//         valor = BuscarForca(l->inicio, posicao);
//         InsereForcaLista(sub, valor); // Insere a força que deseja subtrair na lista de forças subtrativas
//         RemoverForca(l, posicao);
//         ImprimirListaForca(l->inicio);
//         ImprimirListaForca(sub->inicio);
//         printf("Deseja parar? (1-Sim/2-Nao)\n");
//         scanf("%d", &resp);
//     }while(resp != 1);
// }

float SubtracaoForca(float f, float f2){
    float valor = 0;
    if(f > f2) valor = f - f2;
    else valor = f2 - f;
    return valor;
}

// Função que calcula a quantidade de carga elétrica e suas variáveis
float CalcQuantCarga(float n_protons, float n_eletrons, float q){
    float resp = 0;
    if(n_eletrons == 0){
        resp = (q/CARG_ELEM) - n_protons;
        return resp;
    }
    else if(n_protons == 0){
        resp =  (q/CARG_ELEM) + n_eletrons;
        return resp;
    }
    else{
        resp = (n_protons * CARG_ELEM) - (n_eletrons * CARG_ELEM);
    }
    return resp;
}

// Função que verifica se o usuário quer calcular a quantidade de carga elétrica e suas variáveis
void VerificarQuantCarga(){
    int resp = 0;
    float n_protons = 0, n_eletrons = 0, q = 0;
    system("cls"); // Limpa a tela
    printf("Escolha a operacao que deseja fazer:\n");
    printf("1-Calcular a quantidade de carga eletrica\n");
    printf("2-Calcular o numero de protons ou carga do proton\n");
    printf("3-Calcular o numero de eletrons ou carga do eletron\n");
    printf("4-Voltar\n");
    
    
    scanf("%d", &resp);
    switch (resp){
    case 1:
        printf("Digite o numero de protons: \n");
        scanf("%f", &n_protons);
        printf("Digite o numero de eletrons: \n");
        scanf("%f", &n_eletrons);
        q = CalcQuantCarga(n_protons, n_eletrons, q);
        printf("A quantidade de carga e: %.10f C\n", q);
        system("pause"); // Pausa o programa
        break;
    case 2:
        printf("Digite o numero de eletrons: \n");
        scanf("%f", &n_eletrons);
        printf("Digite o valor da carga: \n");
        scanf("%f", &q);
        n_protons = CalcQuantCarga(n_protons, n_eletrons, q);
        printf("O numero de protons e: %.10f\n", n_protons);
        system("pause"); // Pausa o programa
        break;
    case 3:
        printf("Digite o numero de protons: \n");
        scanf("%f", &n_protons);
        printf("Digite o valor da carga: \n");
        scanf("%f", &q);
        n_eletrons = CalcQuantCarga(n_protons, n_eletrons, q);
        printf("O numero de eletrons e: %.10f\n", n_eletrons);
        system("pause"); // Pausa o programa
        break;
    case 4:
        break;
    default:
        printf("Opcao invalida, tente novamente\n");
        break;
    }
}

// Função principal que contém funções auxiliares para calcular a força eletrostática vetorial
void VetForcaEletrostatica(){
    
}

#endif