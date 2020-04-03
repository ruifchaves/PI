


//FICHEIRO DE INTERFACE

#ifndef _LLINT//vai testar se a constante está definida ou não. Ele vai ler este ficheiro uma vez e não mais. A constante serve como semáfaro
//diretivas ao pre processador, todos os comandos comecados por cardinal

#define _LLINT

typedef struct slist *LInt; //apontador para uma struct slist
typedef struct slist {
    int valor;
    LInt prox; //tipo de dados recursivo
} Nodo;
//em listas ligadas é sempre preciso o Nodo e o *LInt
//O nodo serve basicamente para alocar memoria

//assinatura das funcões
void showLInt(LInt l);
void showLIntRec(LInt l);
LInt cons (LInt l, int x);
LInt tail (LInt l);
LInt init (LInt l);
LInt snoc (LInt l, int x);
LInt concat (LInt a, LInt b);

#endif