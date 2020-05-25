#include <stdio.h>
#include <stdlib.h>
#include "llint.h"

//FICHEIRO DE IMPLEMENTAÇÃO

void showLInt (LInt l){
    for (l ;l ;l = l->prox){  //enquanto l for um apontador válido
        printf("%d ", l->valor);
    }
    putchar('\n');
}

//versão recursiva do showLInt 
void showLIntRec (LInt l){
    if(l){
        printf("%d ", l->valor);
        showLIntRec(l->prox);
    }
    putchar('\n');
}

//acrescenta um elemento no inicio da lista
LInt cons (LInt l, int x){
    LInt l2 = malloc(sizeof(Nodo));
    l2->valor = x;
    l2->prox = l;

    return l2;
}

//remove o primeiro elemento de uma lista nao vazia
LInt tail (LInt l){ 
    LInt temp = NULL; //sempre que trabalharem com apontadores, inicializem com null;
    if(l){
        temp = l->prox;
        free(l);
    }
    return temp;
}

//remove o ultimo elemento de uma lista nao vazia
LInt init (LInt l){
    LInt q = l; //guarda o l
    LInt temp;
    for (l ; l && l->prox; l = l->prox)
        temp = l; //guarda o penultimo
    free(l); //free ao ultimo
    temp->prox = NULL;
    return q;
}

//acrescenta um elemento no fim da lista
LInt snoc (LInt l, int x){
    LInt new = malloc(sizeof(Nodo));
    new -> valor = x;
    new -> prox = NULL;
    if(l==NULL)
        l = new;
    else {
        LInt q;
        for(q = l; q->prox; q = q->prox);
        q->prox = new;
    }
    return l;
}

//que acrecenta a lista b a a, retornando o inicio da a
LInt concat (LInt a, LInt b){
    LInt aux;
    for(aux = a; aux && aux->prox; aux=aux->prox);

    if(!a) a = b;
    else aux->prox = b;
    return a;
}