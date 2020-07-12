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
            aux = (*l);             //aux = (*l)->prox
            *l = (*l)->prox;        //free(*l)
            free(aux);              //(*l)=aux
            ret++;
        } else l = &(*l)->prox;
    }
    return ret;
}

//11 remove repetidos de uma ll, deixa 1a ocorr, ret num removidos      TODO:
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

//16 cria nova ll com elems na ordem em que aparecem na ll argumento
LInt cloneL (LInt l){        //acho que nao esta certo
    LInt ret = NULL;
    for(; l && l->prox; l=l->prox, ret=ret->prox){
        ret = malloc(sizeof(struct lligada));
        ret->valor = l->valor;
        ret->prox = l->prox;
    }
    ret = NULL;
    return ret;
}

LInt cloneL (LInt l){  //reolucao do goncas, acho certa
    LInt new, *r = &new;
    for( ; l; l=l->prox, r=&(*r)->prox){
        *r = (LInt) malloc(sizeof(struct lligada));
        (*r)->valor = l->valor;
        (*r)->prox = l->prox; //na res do goncas não tem esta linha
    }
    (*r) = NULL;
    return new;
}

//17 cria ll ordem inversa
LInt cloneRev (LInt l){
    return cloneL(reverseL(l));
}

LInt cloneRev (LInt l){
    LInt new, ant = NULL;
    for(; l; l=l->prox){
        new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = ant;
        ant = new;  //não é ant = l!
    }
    return new;
}

//18 maior elem ll nao vazia
int maximo (LInt l){
    int max = 0;
    for( ; l; l=l->prox)
        if(l->valor > max) max = l->valor;
    return max;
}

//19 dado int n e ll l, remove elems para alem de n-ésimo, libertando espaco na memoria. se ll tiver menos de n nao altera a ll.
//ret tamanho final da lista
int take (int n, LInt *l){  //minha
    int len=0;
    for(; *l && n; n--, len++, l=&(*l)->prox);
    if(*l){
        LInt aux = (*l);
        for(; *l; *l=(*l)->prox)
            free(*l);
        aux->prox = NULL; //esta certo mas nao faz sentido isto pq o aux já nao ponta para nada
        return len;
    } else {
        return len;
    }
}

int take (int n, LInt *l){
    int len=0;
    for(; *l && n; n--, len++, l=&(*l)->prox);
    for(; *l; *l=(*l)->prox){
        LInt aux = (*l);
        free(aux); 
    }
    return len;
}

int take (int n, LInt *l){ //goncas, certa
    int len=0;
    for(; *l && n; n--, len++, l=&(*l)->prox);
    while(*l){
        LInt aux = (*l)->prox;
        free(*l);
        (*l)=aux;
    }
    return len;
}



//20 dado int n e ll l, apaga os n primeiros elem da ll, libertando o espcao em memoria. se ll tiver menos de n, ll totalmente libertada.
//ret num elem rem
int drop (int n, LInt *l){
    int len=0;
    for(; *l && n; n--, len++, *l=(*l)->prox); //está certo mas não dá free, e se pusesse LInt aux = *l, free(aux) dava certo mas nao faria sentido pq nao iria conseguir incrementar. idk
    return len;
}

int drop (int n, LInt *l){  //certa, versão do goncalo
    int len=0;
    for(; *l && n; len++, n--){
        LInt aux = (*l)->prox;
        free(*l);
        *l = aux;
    }
    return len;
}


//21 LInt como lista circular, dado um ll circular retorna endereco do elem n posicoes à frente.
LInt Nforward (LInt l, int N){
    for( ; l && N; N--, l=l->prox);
    return l; //este apontador tem o endereco do elem n posicoes à frente
}

//22 dado ll l, preenche array v com elems de l. preenche no max N elems, ret num de preenchidos
int listToArray (LInt l, int v[], int N){
    int i=0;
    for( ; l && i<N; l=l->prox, i++)
        v[i] = l->valor;
    return i;
}

//23 controi ll com elems de array, msm ordem
LInt arrayToList (int v[], int N){
    LInt init = NULL, *aux = &init;
    for(int i=0; i<N; i++){
        *aux = malloc(sizeof(struct lligada));
        (*aux)->valor = v[i];
        aux = &(*aux)->prox;
    }
    *aux = NULL;
    return init;
}

//24 nova ll com somas acumuladas
LInt somasAcL (LInt l){
    LInt init = NULL, *aux = &init;
    int soma = 0;
    for( ; l; l=l->prox, aux=&(*aux)->prox){
        *aux = malloc(sizeof(struct lligada));
        soma += l->valor;
        (*aux)->valor = soma;
    }
    *aux = NULL;
    return init;
}

//25 dada ll ordenada!, elimina
void remreps (LInt l){
    LInt next = NULL, aux;
    for( ; l; l=l->prox){
        next = l->prox;
        while(next && next->valor == l->valor){
            aux = next->prox;
            free(next);
            next=aux;
        }
        l->prox=next; //é l->prox porque l vai ser 'incrementado'
    }
}

//26 1o elem no fim. se vazia ou com um elem ret a mesma ll          TODO:       
LInt rotateL (LInt l){ 
    LInt *aux = &l;
    for( ; *aux; aux = &(l)->prox);
    if(l && l->prox){
        (*aux);
    }
    return l;
}

//27 parte ll em duas, na 1a elems pos impares, na ret os em indice par  TODO:
LInt parte (LInt l){  //minha, so duas certas
    LInt xx = NULL, yy = NULL;
    LInt *x = &xx, *y = &yy;
    int i;
    for(i=1; l; i++, l=l->prox){ 
        if(i%2){        //add to x os ímpares
            *x=malloc(sizeof(struct lligada));
            (*x)->valor = l->valor;
            x = &(*x)->prox;
        } else {
            *y=malloc(sizeof(struct lligada));
            (*y)->valor = l->valor;
            y = &(*y)->prox;
        }
    }
    *x = NULL;
    *y = NULL;
    return y;
}

LInt parte (LInt l){ //goncas, certo
	LInt ppares;
	LInt *efim = &ppares;
	while(l!=NULL){
		if(l->prox != NULL){
			*efim = l->prox; //guarda em ppares o 2o elem
			efim = &(l->prox->prox); //passa elem para 3o
			l->prox = l->prox->prox; //apontador do 2o passa a apontar para o 4o
		}
		*efim = NULL;
		l = l->prox; //l passa para 2o elem
	}
	return ppares;
}




//ARVORES BINARIAS

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

//28 altura ABin
int maior (int a, int b){
    return (a>b) ? a : b;
}

int altura (ABin a){
	if(!a) return 0;
	else return 1+maior(altura(a->esq), altura(a->dir));
}

//29 cria copia da arvore
ABin cloneAB (ABin a){
    ABin ret;
    if(!a) ret = NULL;
    else {
        ret = malloc(sizeof(struct nodo));
        ret->valor = a->valor;
        ret->esq = cloneAB(a->esq);
        ret->dir = cloneAB(a->dir);
    }
    return ret;
}

//30 inverte arvore sem criar nova
void mirror (ABin *a){
    if(*a){
        ABin temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&(*a)->esq);
        mirror(&(*a)->dir);
    }
}

//31 cria ll a partir de uma travessia inorder de abin   TODO: 
void inorder (ABin a, LInt *l){  //minha errada
    if(!a){
        inorder(a->esq, l);
        (*l) = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        l=&(*l)->prox;
        inorder(a->dir, l);
    }
}

void inorder (ABin a, LInt *l){
    if(!a) (*l) = NULL;
    else{
        inorder(a->esq, l);
        while(*l)
            l = &(*l)->prox;
        (*l) = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        l=&(*l)->prox;
        inorder(a->dir, l);
    }
}

//32
void preorder (ABin a, LInt *l){
	if(!a) (*l) = NULL;
	else{
		*l = malloc(sizeof(struct lligada));
		(*l)->valor = a->valor;
		l = &(*l)->prox;
		preorder(a->esq, l);
		LInt *aux = l;
		while(*aux) aux = &(*aux)->prox;
		preorder(a->dir, aux);
	}
}

//33 minha esta mal
void posorder (ABin a, LInt *l){
    if(!a) (*l) = NULL;
    else {
        posorder(a->esq, l);
        while(*l) l=&(*l)->prox;
        posorder(a->dir, l);
        *l = malloc (sizeof(struct lligada));
        (*l)->valor = a->valor;
        l = &(*l)->prox;
    }
}

void posorder (ABin a, LInt *l){
    if(!a) (*l) = NULL;
    else {
        posorder(a->esq, l);
        while(*l) l=&(*l)->prox;
        posorder(a->dir, l);
        while(*l) l=&(*l)->prox;
        *l = malloc (sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
    }
}

//34 calcula o nivel (menor) a que um elem esta numa abin
int depth (ABin a, int x){
    if(a == NULL) return -1;
    if(a->valor == x) return 1;
    int dl = depth(a->esq, x);
    int dr = depth(a->dir, x);
    if(dl == -1 && dr == -1) return -1;
    else if(dr == -1) 
        return 1+dl;
    else if(dl == -1)
        return 1+dr;
    return (dr > dl) ? dr : dl;  // devia ser return 1 + ((dr > dl) ? dr : dl);
}

//35 liberta espaco de abin e ret num nodos libertados
int freeAB (ABin a){
    if(!a) return 0;
    int total = 0;
    total += freeAB(a->esq) + freeAB(a->dir);
    free(a);
    return 1 + total;
}

//36 rem todos elems a profundidade de > que l, ret num rem
int pruneAB (ABin *a, int l){
    if(!(*a)) return 0;
    int totRems = 0;
    totRems += pruneAB(&(*a)->esq, l-1) + pruneAB(&(*a)->dir, l-1);
    if(l<=0){
        free(*a);
        (*a)=0;   //linha necessária
        totRems++;
    }
    return totRems;
}

//37 testa duas abins iguais, mesmos elems e mesma forma. ret 1 se iguais.
int iguaisAB (ABin a, ABin b){
    if(!a && !b) return 1;
    int ret = 0;
    if(a && b){
        ret = (a->valor == b->valor) &&  //&& operation: apenas dá 1 quando todos sao 1
                iguaisAB(a->dir, b->dir) &&
                iguaisAB(a->esq, b->esq);
    }
    return ret;
}

//ou
int iguaisAB(ABin a, ABin b){
    if(a==NULL && b==NULL) return 1;
    if(!a || !b || a->valor != b->valor) return 0;
    return (iguaisAB(a->dir, b->dir) && iguaisAB(a->esq, b->esq));
}

//38 constroi ll com elem do nivel n da abin
LInt nivelL (ABin a, int n){
    LInt l;
    if(!a) return NULL;
    if(n==1){
        l = malloc(sizeof(struct lligada));
        l->valor = a->valor;
        l->prox = NULL;
        return l;
    } else {
        LInt lesq = nivelL(a->esq, n-1);
        LInt ldir = nivelL(a->dir, n-1);
        LInt *l = &lesq;
        while(*l) l = &(*l)->prox;
        (*l) = ldir;
        return lesq;
    }
}

//39 preenche vetor v com elems do nivel n, ret num de posicoes preeenchidas
int nivelV (ABin a, int n, int v[]){
    if(!a) return 0;
    if(n == 1){
        int i=0;
        *v = a->valor;
        return 1;
    } else {
        int filled = nivelV(a->esq, n-1, v);
        filled += nivelV(a->dir, n-1, v+filled);
        return filled;
    }
}

//40 preenche array com elems segundo travessia inorder, preenche no max N elems, ret num preenchidos
int dumpAbin (ABin a, int v[], int N){
    int i = 0;
    if(!a) return i;
    else{
        i += dumpAbin(a->esq, v, N);
        if(i<N) v[i++] = a->valor;
        i += dumpAbin(a->dir, v+i, N-i);
        return i;
    }
}

//41 dada abin calcula arvore das somas acumuladas
int somasABin (ABin a){
    int ret = 0;
    if(a) ret = a->valor + somasABin(a->esq) + somasABin(a->dir);
    return ret;
}

ABin novoNodo(int x, ABin esq, ABin dir){
    ABin new = malloc(sizeof(struct nodo));
    new -> valor = x;
    new->esq = esq;
    new->dir = dir;
    return new;
}

ABin somasAcA (ABin a){
    ABin ret = NULL;
    if(a) 
        ret = novoNodo(somasABin(a), somasAcA(a->esq), somasAcA(a->dir));
        return ret;
}

//42 conta qts dos nodos sao folhas, sem descendentes.
int contaFolhas (ABin a){
    int i = 0;
    if(!a) return 0;
    if(!(a->esq) && !(a->dir)) return 1;
    else {
        i += contaFolhas(a->esq) + contaFolhas(a->dir);
        return i;
    }
}

//43 nova arvore espelho
ABin novoNodo(int x, ABin esq, ABin dir){
    ABin new = malloc(sizeof(struct nodo));
    new->valor = x;
    new->esq = esq;
    new->dir = dir;
    return new;
}

ABin cloneMirror (ABin a){ 
    ABin ret = NULL;
    if(a)
        ret = novoNodo(a->valor, cloneMirror(a->dir), cloneMirror(a->esq));
    return ret;
}

//ou
ABin cloneMirror (ABin a){
	ABin ret = NULL;
	if(a){
		ret = (ABin) malloc(sizeof(struct nodo));
		ret->valor = a->valor;
		ret->esq = cloneMirror(a->dir);
		ret->dir = cloneMirror(a->esq);
	}
	return ret;
}

//44 add elem em abin de procura, ret 1 se existir 0 se nao. NAO RECURSIVA
int addOrd (ABin *a, int x){
    if(!(*a)) {
        (*a) = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
        return 0;;
    }
    else if ((*a)->valor > x)
        addOrd(&(*a)->esq, x);
    else if ((*a)->valor < x)
        addOrd(&(*a)->dir, x);
    else return 1;
}

int addOrd (ABin *a, int x){
	int r=0;
	while((*a)!=NULL && r==0){
		if((*a)->valor>x)
			a=&((*a)->esq);
		else{
			if((*a)->valor<x) a=&((*a)->dir);
			else r=1;
		}
	}
	if(r==0){
		*a= (ABin) malloc(sizeof(struct nodo));
		(*a)->valor = x;
		(*a)->esq = NULL;
		(*a)->dir = NULL;
	}
	return r;
}

//45 if elem is in binary search tree. NAO RECURSIVA
int lookupAB (ABin a, int x){
    if(!a) return 0;
    else if(a->valor < x)
        lookupAB(a->dir, x);
    else if(a->valor > x)
        lookupAB(a->esq, x);
    else return 1;
}

int lookupAB (ABin a, int x){
    int r = 0;
    while(a && r==0){
        if(a->valor > x)
            a=a->esq;
        else if(a->valor < x)
            a=a->dir;
        else r=1;
    }
    return r;
}

//46 ret de nivel de elem em binary search tree, -1 caso n exista. NAO RECURSIVA
int depthOrd (ABin a, int x){
    int i=0;
    if(!a) return -1;
    else if(a->valor > x)
        i = 1+lookupAB(a->esq, x);
    else if(a->valor < x)
        i = 1+lookupAB(a->dir, x);
    else return i;
}

int depthOrd (ABin a, int x){
    int i = 1;
    while(a){
        if(a->valor > x){
            i++;
            a=a->esq;
        }
        else if(a->valor < x){
            i++;
            a=a->dir;
        }
        else return i;
    }
    return -1;
}

//47 calcula maior elem de uma binary search tree nao vazia. NAO RECURSIVA
int maiorAB (ABin a){
    int store = 0;
    while (a){
        store = a->valor;
        a=a->dir;
    }
    return store;
}

int maiorAB (ABin a){
    for( ; a && a->dir; a=a->dir);
    return a->valor;
}

//48 remove maior elem de abin de procura
void removeMaiorA (ABin *a){  //sem libertar espaco
    if(!(*a)->dir) 
        *a = (*a)->esq;
    else removeMaiorA(&(*a)->dir);
}

//49 com elems maiores que x
int quantosMaiores (ABin a, int x){
    if(!a) return 0;
    else {
        if(a->valor <= x)
            return quantosMaiores(a->dir, x);
        else if(a->valor > x)
            return 1 + quantosMaiores(a->esq, x) + quantosMaiores(a->dir, x);
    }
}

//50  
void listToBTree (LInt l, ABin *a){  //minha seg fault
    while(*a){
        if((*a)->valor > l->valor)
             a = &(*a)->esq;
        else a = &(*a)->dir;
    }
    (*a) = malloc(sizeof(struct nodo));
    (*a)->valor = l->valor;
    (*a)->esq = NULL;
    (*a)->dir = NULL;
    if(l->prox) listToBTree(l->prox, &(*a));
}




void insere (ABin a, ABin *ca){  //goncas certa
	while(*ca != NULL){
		if((*ca)->valor > a->valor)
			ca=&((*ca)->esq);
		else if((*ca)->valor < a->valor)
			ca=&((*ca)->dir);
	}
	*ca=a;
}

void listToBTree (LInt l, ABin *ca){
	ABin a;
	while(l!=NULL){
		a= (ABin) malloc(sizeof(struct nodo));
		a->valor = l->valor;
		a->esq = a->dir = NULL;
		insere(a,ca);
		l=l->prox;
	}
}

