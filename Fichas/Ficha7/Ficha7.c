#include <stdio.h>
#include <stdlib.h>
#include "llint.h"



int main(){
    LInt l;
    l = malloc(sizeof(Nodo)); //sizeof da struct, nao do apontador
    l->valor = 10;
    l->prox = malloc(sizeof(Nodo));
    l->prox->valor = 5;
    l->prox->prox = malloc(sizeof(Nodo));
    l->prox->prox->valor = 15;
    l->prox->prox->prox = NULL;
    showLInt(l);
    showLIntRec(l);


    LInt lista = NULL;
    int i;
    for(i=0; i<=10; i++)
        lista = cons(lista, i);
    showLInt(lista);

    lista = tail(tail(lista));
    showLInt(lista);

    lista = init(init(lista));
    showLInt(lista);

    snoc(lista, 4);
    snoc(lista, 2);
    snoc(lista, 0);
    showLInt(lista);

    concat(l, lista);
    showLInt(l);

    return 0;
}

    //compile: gcc -o Ficha7.exe Ficha7.c llint.c
    // ou      gcc -c Ficha7.c -> compilar parcialmente, cria um ficha7.o que é o codigo compilado pseudocodigo maquina
    //         gcc -c compila só para objeto, cria os .o
    //run    : ./Ficha7.exe