// BIBLIOTECAS
#include "eletrotastica_calc.h"

int main (){
    int r = 0;
    Inicializador();
    do{
        MenuFisica();
        scanf("%d", &r);
        switch (r){
        case 1:
            ModForcaEletrostatica();
            break;
        case 2:
            printf("Ainda nao desenvolvido\n");
            break;
        case 3:
            break;
        default:
            printf("Opcao invalida, tente novamente\n");
            break;
        }

    }while(r != 3);

    return 0;
}