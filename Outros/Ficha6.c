



// Na stack todas as operacoes é apenas num dos extremos da estrutura
// Na queue opera-se sobre os dois extremos

// QUEUE:
// -é uma struct ou é um apontador?
// é uma struct, porque está definida como struct 

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct queue { //typedef: definir o tipo de dados
int inicio, tamanho;   //inicio:  aponta para o primeiro elemento da lista
int valores [MAX];
} QUEUE, *QPTR; //apontador seria QUEUE, *QPTR está definido como apontador



void initQueue (QUEUE *q){ //ou QPTR p
    //instrucao para fazer inicialização do tamanho
    q->tamanho = 0;
    q->inicio = 0; //apesar de não ter lá nada, fica a 0
    //não é necessário inicializar os valores, porque não exite
} 

///////

int isEmptyQ (QPTR q){
    return (q->tamanho == 0);
}

//////////

int isFullQ (QPTR q){
    return (q->tamanho == MAX);
}

int enqueue (QUEUE *q, int x){ //temos que ver se está cheia, se não estiver podemos adicionar
    int pos; //para usar round robin(posições livres no início, mete no início)
    if(!isFullQ(q)){
        pos = (q->inicio + q->tamanho) % MAX;
        q->valores[pos] = x;
        q->tamanho++;
        return 0;
    }
    return 1;
}

//ou 
int enqueue(QUEUE *q, int x){
	int r=0;
	if(q->tamanho == MAX) r=1;
	else{
		q->valores[(q->inicio + q->tamanho) % MAX] = x;
		q->tamanho++;
	}
	return r;
}

//////////////

int dequeue (QUEUE *q, int *x){
    if(!isEmptyQ (q)){
        *x = q->valores[q->inicio];
        q->inicio = (q->inicio +1) % MAX; //para garantir que ele não aumenta para além do tamanho máximo
        q->tamanho--;
        return 0;
    }
    return 1;
}

//ou
int dequeue(QUEUE *q, int *x){
	int r=0;
	if(q->tamanho == 0) r=1;
	else{
		*x = q->valores[q->inicio];
		q->inicio = (q->inicio + 1) % MAX;
		q->tamanho--;
	}
	return r;
}

//////////////


int front (QUEUE *q, int x){
    if(!isEmptyQ (q)){
        *x = q->valores[q->inicio];
        return 0;
    }
    return 1;
}

////////////// uma que não está na ficha

void showQueue(QPTR q){  //recebe um apontador
    int i, p;
    printf ("Inicio %d, %d Items: ", q->inicio, q->tamanho);
    for (i=0, p=q->front; i<q->tamanho; i++) {
        printf ("%d ", q->valores[p]);
        p = (p+1) % MAX;
    }
    putchar ('\n');
}



int main(){
    QUEUE q1 =  {0, 10, {1,2,3,4,5,6,7,8,9,10}}; //é uma struct, pelo que pode ser inicializada assim
    QPTR q2; //como é um apontador não se pode definir com chavetas. É preciso alocar espaço de memória.

    q2 = (QPTR)malloc(sizeof(QUEUE));
    *q2 = {0,1,{34}};

    printf("Queue1: \n");
    showQueue(&q1);    //como é uma struct, passa-se o endereço de struct
    printf("Queue2: \n");
    showQueue(q2);
}

//gcc -o q.exe Ficha6.c  