#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

//1
int length (LInt l){
    int i=0;
    for(l; l ; l=l->prox)
        i++;
    return i;    
}

//2
void freeL (LInt l){
    LInt aux;
    while(l){
        aux = l;
        l=l->prox;
        free(aux);
    }
}

//3
void imprimeL(LInt l){
    for(l; l; l=l->prox)
        printf("O valor desta célula é: %d\n",l->valor);
}

//4
LInt reverseL (LInt l){
    LInt ant = NULL, aux = l;
    while(aux){
        l = aux;
        aux = aux->prox;
        l -> prox = ant;
        ant = l;
    }    
}

//5
LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

void insertOrd (LInt *l, int x){
    LInt ant = NULL, nova = newLInt(x, NULL);

    for(; *l && (*l)->valor < x ; l = &(*l)->prox){  //(*l)=(*l)->prox não dava!!!
        ant = (*l);
    }
    if(!ant){
        nova->prox = *l;
        *l = nova;
    } else {
        nova->prox = ant->prox;
        ant->prox = nova;
    }
}

//6
int removeOneOrd (LInt *l, int x){
    LInt aux;
    int ret = 1;
    for( ; *l && (*l)->valor!=x; l = &(*l)->prox);
    
    if(*l){
        aux = *l;
        *l = (*l)->prox;
        free(aux);
        ret = 0;
    }
    return ret;
}

//7
void merge (LInt *r, LInt a, LInt b){
    for( ; a && b; r=&(*r)->prox){
        if(a->valor<b->valor){
            (*r) = a;
            a = a->prox;
        }
        else {
            (*r) = b;    
            b = b->prox;
        }
    }
    if(a)
        (*r) = a;
    else
        (*r) = b;
}

//8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    for( ; l ; l=l->prox){
        if(l->valor < x){
            *mx = l;
            mx = &(*mx)->prox;
        } else {
            *Mx = l;
            Mx = &(*Mx)->prox;
        }
    }
    *mx = *Mx = NULL;
}

//9
int lengthLInt (LInt l){
    int i;
    for (i=0; l ; i++, l=l->prox);
    return i;
}

LInt parteAmeio (LInt *l){
    int len = lengthLInt(*l);
    LInt y = NULL;
    for(int i=0 ; *l && i<(len/2); i++, (*l)=(*l)->prox, y=y->prox){
        y = *l;
    }
    y = NULL;
    return y;
}

LInt parteAmeio (LInt *l){ //TODO
    int len=0 , i=0;
    LInt y = NULL, aux=*l;
    for (aux = *l; aux; aux = aux->prox, len++);
    y=*l;
    for(len/=2; len; len--, y=y->prox);
    y = NULL;
    return y;
}

LInt parteAmeio (LInt *l){ //certo
    LInt nova = NULL, aux;
    int conta = 0;

    for (aux = *l; aux; aux = aux->prox, conta++);

    for (conta/=2; *l, conta; conta--, *l = (*l)->prox, aux->prox = NULL)
        if (!nova){
            nova = *l;
            aux = nova;
        } else {
            aux->prox = *l;
            aux = aux->prox;
        }
    return nova;
}


//10
int removeAll (LInt *l, int x){
    int i=0;
    LInt freeAux = NULL;
    while(*l){
        if((*l)->valor == x){
            i++;
            freeAux = *l;
            (*l)=(*l)->prox;
            free(freeAux);
        } else {
            l = &(*l)->prox;
        }
    }
    return i;
}

//11
int removeDups (LInt *l){

}

//12
int removeMaiorL (LInt *l){

}


//13
void init (LInt *l){
    LInt freeAux;
    for(;(*l)->prox; l=&(*l)->prox);
    freeAux = *l;
    *l = NULL;
    free(freeAux);
}

//14
void appendL (LInt *l, int x){
    for(; *l ; l = &(*l)->prox);
    *l = malloc(sizeof(struct lligada));
    (*l)->valor = x;
    (*l)->prox = NULL;
}

//15
void concatL (LInt *a, LInt b){
    for(;*a ; a = &(*a)->prox);
    *a = b;
}

//16
LInt clone (LInt l){
    LInt ret = NULL;
    for(; l && l->prox ; l=l->prox, ret=ret->prox){
        ret = malloc(sizeof(struct lligada));
        ret->valor = l->valor;
        ret->prox = l->prox;
    }
    ret = NULL;
    return ret;
}


LInt cloneL (LInt l) {
    LInt nova, aux;

    for (nova = NULL; l ; l=l->prox)
        if (nova == NULL){
            nova = malloc(sizeof(struct lligada));
            aux = nova;
        }
        else {
            aux->prox = malloc(sizeof(struct lligada));
            aux = aux->prox;
            aux->valor = l->valor;
            aux->prox = NULL;
        }
    return nova;
}

//17
LInt cloneRev (LInt l){
    LInt nova, ant=NULL;
    for( ; l ; l=l->prox){
        nova = malloc(sizeof(struct lligada));
        nova->valor = l->valor;
        nova->prox = ant;
        ant = nova;
    }
    return nova;
}

//18
int maximo (LInt l){
    int max = l->valor;
    for( ; l ; l=l->prox)
        if(max<l->valor) max=l->valor;
    return max;
}

//19
int take (int n, LInt *l){
    LInt aux;
    int i;
    for(i=0; *l && i<n; i++ , l=&(*l)->prox);
    for(; *l; (*l)=(*l)->prox){
        aux = *l;
        free(aux);
    }
    return i;
}