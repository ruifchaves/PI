#include <stdlib.h>
#include <stdio.h>
#include "llint.h"

//FICHEIRO DE IMPLEMENTAÇÃO

void showLInt(LInt l){
    while(l){ //enquanto l for um apontador válido
        printf("%d ", l->valor);
        l = l->prox;
    }
    putchar('\n');
}

//versão recursiva do showLInt 
void showLIntRec(LInt l){
    if(l){
        printf("%d ", l->valor);
        showLIntRec(l->prox);
    } else putchar('\n');
}

LInt cons (LInt l, int x){
    LInt l2;

    l2 = malloc(sizeof(Nodo));
    l2->valor = x;
    l2->prox = l;

    return l2;
}

LInt tail(LInt l){
    LInt temp = NULL; //sempre que trabalharem com apontadores, inicializem com null;
    if(l){
        temp= l->prox;
        free(l);
    }
    return temp;
}

LInt init (LInt l){
    LInt temp, l1;
    l1=l;
    while(l && l->prox!=NULL){
        temp = l;
        l = l->prox;
    }
    free(l);
    temp->prox = NULL;
    return l1;
}


LInt snoc(LInt l, int x){
    LInt novo = malloc(sizeof(Nodo));
    novo->valor = x;
    novo->prox = NULL;

    if (l == NULL)
        l = novo;
    else{
        LInt pt;
        for (pt = l; pt->prox != NULL; pt = pt->prox);
        pt->prox = novo;
    }
    return l;
}

LInt concat (LInt a, LInt b){ //concaterar as duas listas numa terceira lista
    LInt temp;
    for(temp=a; temp && temp->prox; temp=temp->prox);
    
    if(!a) a=b;
    else temp->prox=b;
    
    return a;
}