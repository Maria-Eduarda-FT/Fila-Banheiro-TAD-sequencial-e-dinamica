#include <stdio.h>
#include <stdlib.h>
#include "filaBanheiro.h"

Fila * Cria_fila(){
    Fila* pt;
    pt = (Fila*) malloc(sizeof(Fila));
    if (pt == NULL)
        return;
    else{
        pt->inicio = 0;
        pt->final = 0;
        pt->n = 0;
    }
    return pt;
}

Fila* Insere(Fila* pt){
    char nome[30];
    if (pt == NULL || pt->n == max)
        return pt;
    if (pt->n == max){ // fila cheia
        printf("\nNao e possivel inserir mais elementos nessa fila! :(");
        return pt;
    }

    printf("\nInsira seu nome: ");
    getchar();
    scanf("%[^\n]", &nome);
    strcpy(pt->fila[pt->final], nome);
    pt->final = (pt->final+1)%max;
    pt->n++;
}

void ConsultaPosicao(Fila* pt){
    Fila* ptf = pt;
    char nome[30];
    int in, n;

    printf("\nInsira seu nome: ");
    getchar();
    scanf("%[^\n]", &nome);

    in = pt->inicio;
    n = pt->n;
    while(n != 0){
        if (strcmp(ptf->fila[in], nome) == 0){
            printf("Voce esta na posicao %d\n", n+1);
            break;
        }
        in++;
        n--;
    }
    if(n == 0){
        printf("\nEsta pessoa nao esta na fila :(");
    }
}
Fila* IrAoBanheiro(Fila* pt){
    if(pt == NULL || pt->n == 0)
        return pt;
    printf("\n %s foi ao banheiro!!", pt->fila[pt->inicio]);
    pt->inicio = (pt->inicio+1) % max;
    pt->n--;
    return pt;
}
void EspiarFila(Fila* pt){
    Fila* ptf = pt;

    if (pt->n == 0){
        printf("\nFila vazia, banheiro disponivel!!\n");
        return;
    }
    printf("--- FILA DO BANHEIRO ---\n");
    while(ptf->n != 0){
        printf(" %s", ptf->fila[ptf->inicio]);
        ptf->inicio++;
        ptf->n--;
        if (ptf->n != 0) {
            printf(",");
        }
    }
    printf("\n");
    return;
}

Fila* Libera_fila(Fila *pt){
    if (pt == NULL)
        return NULL;
    free(pt);
    return NULL;
}
