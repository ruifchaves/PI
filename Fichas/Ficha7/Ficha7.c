#include <stdlib.h>
#include "llint.h"


//compile: gcc -o ficha7.exe ficha7.c llint.c
// ou      gcc -c ficha7.c -> compilar parcialmente, cria um ficha7.o que é o codigo compilado pseudocodigo maquina
//         gcc -c compila só para objeto, cria os .o
//run    : ./ficha7.exe
int main(){
    LInt l, lista;
    l = malloc(sizeof(Nodo)); //l é um LInt 

    l->valor = 10;
    //para adicionar o 5 é preciso reservar espaco;
    l->prox=malloc(sizeof(Nodo));
    l->prox->valor=5;

    l->prox->prox = malloc(sizeof(Nodo));
    l->prox->prox->valor = 15;
    l->prox->prox->prox = NULL;

    showLInt(l);
    //showLIntRec(l);

    int i;
    for(i=0; i<=10; i++)
        lista = cons(lista, i);
    showLInt(lista);

    lista = tail(tail(lista));
    showLInt(lista);

    lista = init(init(lista));
    showLInt(lista);

    for(i=0; i<=20; i++)
        lista = snoc(lista, i*2);
    showLInt(lista);

    LInt listaA, listaB;
    for(i=1; i<=10; i++){
        listaA = snoc(listaA, i);
        listaB = cons(listaA, i);
    }
    showLInt(listaA);
    showLInt(listaB);
    showLInt(concat(listaA, listaB));

    
}


//->10->5->15