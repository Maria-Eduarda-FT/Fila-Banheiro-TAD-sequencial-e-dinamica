#include <stdio.h>
#include <stdlib.h>
#include "filaBanheiro.h"

int main(){

    int resposta;
    Fila* pt;
    pt = Cria_fila();
   do{
    printf("\n----- FILA DO BANHEIRO -----\n");
    printf("\n1- Entrar na Fila\n");
    printf("2- Consultar minha posição\n");
    printf("3- Ir ao banheiro\n");
    printf("4- Espiar quem esta na fila\n");
    printf("5- Sair\n");
    scanf("%d", &resposta);

    if (resposta == 1){
        Insere(pt);
    }
    else if (resposta == 2){
        ConsultaPosicao(pt);
    }
    else if (resposta == 3){
        IrAoBanheiro(pt);
    }
    else if (resposta == 4){
        EspiarFila(pt);
    }
    else if (resposta == 5){
        Libera_fila(pt);
    }
   }while(resposta != 5);
   return 0;
}