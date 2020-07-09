#include <stdio.h>
#include <stdlib.h>


typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;


//1
int length (LInt l){
    int i = 0;
    for (i = 0; l ; i++, l=l->prox);
    return i;
}

//2
//void freeL (LInt l){
//    LInt aux;
//    for(; l ; l=l->prox){  
//        aux=l;
//        free(aux);  //assim não dá porque deixa de existir o nodo para onde l aponta, daí não haver l->prox.
//    }
//}

//certa
void freeL (LInt l){
    LInt aux;
    while (l){
        aux = l;
        l = l->prox;
        free(aux);
    }
}

//3
void imprimeL (LInt l){
    LInt aux = l;
    while(aux != NULL){  //aux é um apontador para um nodo. Null é o valor do apontador
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

void imprimeL (LInt l){
    for ( ; l; l=l->prox){ //l passa a ser o apontador para o prox
        printf("%d\n", l->valor);
    }
}

//4
LInt reverseL (LInt l){
    LInt aux = NULL;
    LInt storenext;
    while(l){
        storenext = l->prox;
        l->prox = aux;
        aux = l;
        l=storenext;
    }
    return aux;
}

//5
void insertOrd(LInt *l, int x){
    LInt store = NULL;
    for( ; *l && (*l)->valor<x; l=&(*l)->prox){  //podemos percorrer l porque é um apontador para apontador, não estragamos a lista
        store = (*l); //store é o endereço do apontador para l
    }
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    if(store){
        new->prox = (*l);
        store->prox = new;

    } else {
        new->prox = (*l);
        (*l) = new;
    }
}

//6 remove elem de lista ardenada, ret 1 caso elem n exista
int removeOneOrd (LInt *l, int x){  //criar variavel store(que corresponde ao anterior) e dps fazer store->prox = (*l)->prox dentro do if dava seg fault.
    int ret = 1;
    LInt aux;
    for( ; (*l) && (*l)->valor!=x; l = &(*l)->prox);
    if(*l){
        aux = (*l);
        (*l) = (*l)->prox; //não está a mudar o apontador de apontador (oomo em l = &(*l)->prox), pelo que está mesmo a fazer alterações à ll.
        free(aux); //free deallocates the memory region pointed to by that pointer
        ret = 0;
    }
    return ret;
}

//7 junta duas ll ordenadas, a e b, numa ordenada, r
void merge (LInt *r, LInt a, LInt b){
    for( ; a && b; r = &(*r)->prox){
        if(a->valor < b->valor){
            (*r) = a;
            a=a->prox;
        } else {
            (*r) = b;
            b=b->prox;
        }
    }
    if(!a) //se nao existir o apontador a, as in se for null
        (*r) = b;
    else
        (*r) = a;
}

//8 parte ll em duas, 1a com elems < que x e 2a com > ou =
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    for( ; l ; l=l->prox){
        if(l->valor < x){
            (*mx) = l;
            mx = &(*mx)->prox;
        } else {
            (*Mx) = l;
            Mx = &(*Mx)->prox;
        }
    }
    *mx = *Mx = NULL;
}

//9 parte ll ñ vazia a meio. ret 1a lista que em caso de num impar tem menos elems
int lengthLInt (LInt l){  //precisa ser *l? assim destruo a lista da funcao parteAmeio?
    int i;
    for(i=0; l ; i++, l=l->prox);
    return i;
}

LInt parteAmeio (LInt *l){ //minha, 0 corretos
    LInt *x = (malloc (sizeof (struct lligada)));
    LInt *y = (malloc (sizeof (struct lligada)));
    int len = lengthLInt(*l);
    x = (*l);
    for(int i = 0; i<(len/2); i++, x = &(*x)->prox, l=&(*l)->prox);
    (*x) = NULL;
    y = (*l);
    return x;
}

LInt parteAmeio (LInt *l){ //certo nao percebo esta
    LInt x, aux = NULL;
    int len = lengthLInt(*l); //ou LInt aux = NULL, for (aux = *l, int conta = 0; aux; aux = aux->prox, conta++);

    for(len/=2; *l, len; len--, l=&(*l)->prox );
}


//10 remove todas as ocurrencias de um x na ll, ret num nodos removidos
int removeAll (LInt *l, int x){
    int ret = 0;
    LInt aux = NULL;
    while(*l){
        if((*l)->valor == x){
            aux = (*l);
            *l = (*l)->prox;
            free(aux);
            ret++;
        } else l = &(*l)->prox;
    }
    return ret;
}

//11 remove repetidos de uma ll, deixa 1a ocorr, ret num removidos      ???????????????????????
int removeDups (LInt *l){
    int i=0;
    while (*l){
        i += removeAll(&(*l)->prox, (*l)->valor);
        l = &(*l)->prox;
    }
    return i;
}

//12 remove a 1a ocorr do maior elem da ll nao vazia, ret valor desse elem
int removeMaiorL (LInt *l){
    LInt *aux = l, r = NULL;
    for( ; *aux ; aux = &(*aux)->prox)
        if( (*l)->valor < (*aux)->valor)
            l = aux;
    int ret = (*l)->valor;
    r = (*l)->prox;        
    free(*l);
    *l = r;         //entender melhor isto
    return ret;
}

//13 remove ultimo elem de ll n vazia, libertando espaco em mem
void init (LInt *l){
    for( ; *l && (*l)->prox; l=&(*l)->prox);
    LInt aux = *l;
    *l = NULL;  //ou *l=(*l)->prox;
    free(aux);
}

//14 add elem to end
void appendL (LInt *l, int x){  //nao se cria um novo lInt e testa qd nao há prox e faz-se (*l)->prox = new, sá seg fault.
    for(; *l; l = &(*l)->prox);
    *l = malloc(sizeof(struct lligada));
    (*l)->valor = x;
    (*l)->prox = NULL;
}

//15 acrescenta ll b à ll *a
void concatL (LInt *a, LInt b){
    for(; *a; a = &(*a)->prox);
    *a = b;
}