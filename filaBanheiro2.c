#include <stdio.h>
#include <stdlib.h>
#include "filaBanheiro2.h"

Fila * Cria_fila(){
    Fila* pt;
    pt = (Fila*) malloc(sizeof(Fila));
    if (pt == NULL)
        return NULL;
    pt->prim = NULL;
    pt->ult = NULL;
    return pt;
}

Fila* Insere(Fila* pt){
    char nome[30];
    no *ptf;

    ptf = (no *)malloc(sizeof(no));
    if (ptf == NULL)
        return pt;

    printf("\nInsira seu nome: ");
    getchar();
    scanf("%[^\n]", &nome);
    strcpy(ptf->nome, nome);
    
    ptf->prox = NULL;
    if (pt->ult == NULL) // fila vazia
        pt->prim = ptf;
    else
        pt->ult->prox = ptf;
    pt->ult = ptf;

}

void ConsultaPosicao(Fila* pt){
    char nome[30];
    int cont=0;

    printf("\nInsira seu nome: ");
    getchar();
    scanf("%[^\n]", &nome);

    no *ptf;
    ptf = pt->prim;
    while(ptf != NULL){
        if (strcmp(ptf->nome, nome) == 0){
            printf("Voce esta na posicao %d\n", cont+1);
            break;
        }
        ptf = ptf->prox;
        cont++;
    }
    if(ptf == NULL){
        printf("Esta pessoa nao esta na fila :(\n");
    }
}
Fila* IrAoBanheiro(Fila* pt){
    no* aux;

    if(pt->prim == NULL)
        return pt;
    printf("\n %s foi ao banheiro!!", pt->prim->nome);

    aux = pt->prim;
    pt->prim = pt->prim->prox;
    if(pt->prim == NULL)
        pt->ult = NULL;
    free(aux);
    
}
void EspiarFila(Fila* pt){

    if (pt->prim == NULL){
        printf("\nFila vazia, banheiro disponivel!!\n");
        return;
    }
    no *aux;
    aux = pt->prim;
    printf("\n--- FILA DO BANHEIRO ---\n");
    while (aux != NULL){
        printf(" %s", aux->nome);
        aux = aux->prox;
        if (aux != NULL){
            printf(",");
        }
    }
    printf("\n");

    return pt;
}

Fila* Libera_fila(Fila *pt){
    Fila* ptf;
    if (pt == NULL)
        return NULL;
    while(pt->prim != NULL){
        ptf = pt->prim;
        pt->prim = pt->prim->prox;
        free(ptf);
    }
    free(pt);
    return NULL;
}
