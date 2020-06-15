#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct slist { int valor; struct slist *prox;} *LInt;




int verifica(int s[], int N){
	int i=0, a, b, ret = 1;
	for (a=s[0], b=(s[1]/s[0]) ;s[0] && s[1] && i<N && s[i]==a *(b^i); i++);
	if(i<N) ret = 0;
	return ret;
}

int verifica2(int s[],int N)
{
    int flag = 0;
    if(N>1){
    flag=1;
    int a=s[0]; // primeiro elemento vai ser o a pois a*b^0.
    int b=s[1]/a; //segundo elememento é s[1]/2 pois a*b^1.
    int i;
    for(i=2;i<N;i++){
        int x = a*pow(b,i);
        if(s[i]!=a*pow(b,i)){ flag=0;}    
    }
    }
    return flag;
}
int fact(int n){
	int i, fact = 1;
	for(i = 1; i<= n; ++i){
		fact *= i;
	}
	return fact;
}

void gera(LInt *l, int N){
	int i=0;
	LInt ant = NULL;
	for( ; i<N; i++){
		(*l)= malloc(sizeof(struct slist));
		(*l)->valor = fact(i+1);
		if(ant){
			ant->prox = (*l);
		}
		ant = (*l);
	}
}



LInt anterior(LInt l){
	LInt aux = l, ant;
	for(; l && l->prox!=aux; l=l->prox)
		ant=l;
	return ant;
}


typedef struct dlist { 
	int valor;
	struct dlist *ant, *prox;
 } NodoD;

typedef struct {
	NodoD *front, *last;
} DLint;

int capicua(DLint l){
	if(l==NULL)
		return 0; 
	NodoD f1 = l.front, f2 = l.front, j = l.last;
	int ret = 0;
    for( ; f1!=j && f2!=j && f1 == f2; f1=f1.ant, f2=f2.prox);
	if(f1==j) ret=1;
	return ret;
}

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

void imprime(ABin t){
	if(t==NULL)
		return ; 
	if(t->esq != NULL){
       printf("\n<");
       imprime(t->esq);
    }
	if(t->dir != NULL){
       printf("\n>");
       imprime(t->dir);
    }
	printf("%d", t->valor);
}

void imprime(ABin t){

    if (t == NULL)
         return;

    imprimeAux(t,1);
}

void imprimeAux(ABin t, int i){

    if (t == NULL)
         return;

    printf("%d\n", t.valor);

    if(t->esq != NULL){
       for(int w = 0; w<i; w++)    
               printf("<");
       imprimeAux(t->esq, i+1);
     }


     if(t->dir != NULL){
          for(int w = 0; w<i; w++)    
              printf(">");
       imprime(t->dir, i+1);
     }
} 

typedef struct nodo { char *raiz; int quantos; struct nodo *esq, *dir; } *Palavras;


int calculaQuantos(Palavras p){
    if (t == NULL)
         return;

    return calculaQuantosAux(p,0);
}

int calculaQuantosAux(Palavras p, int tam){
    int p = 0;

    if (p != NULL)
    {
        tam ++;
    }

    if (p->esq || p->dir) {
         p = calculaQuantos(p->esq, tam) + calculaQuantos(p->dir, tam);
    }
    return tam;
}

int size(ABin *node){   
  if (node==NULL)  
    return 0; 
  else     
    return(size(node->esq) + size(node->dir) + 1);   
}  

int existePal(Palavras pals, char *pal){
	int r;
	if(pals == NULL) return 0;
    if(strcmp(pals, pal)!=0)
        return 0;

    if(pals && strcmp(pals->palavra, pal)==0)
        res = pals;

    return res;
}

int acrescenta (Palavras *e, char *p){
	Palavras aux = *e;
	if(existePal(aux, p))

	}

int addOrd (ABin *a, int x) {
    int r = 0;


    while (*a && !r)
        if ((*a)->valor > x)
            a = &(*a)->esq;
        else if ((*a)->valor < x)
            a = &(*a)->dir;
        else r = 1;

    if (!r) {
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
    }
    return r;
}

void pad (char *texto, int p, int N){

}



int main(){
	int v[4] = {2,6,18,54};
	printf("%d", verifica(v, 4));

	printf("%d", verifica2(v, 4));
}