#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct queue {
    int inicio, tamanho;
    int valores [MAX];
} QUEUE;

//a
void initQueue (QUEUE *q){
    q->inicio = 6;
    q->tamanho = 0;
}

//b
int isEmptyQ (QUEUE *q){
    return (q->tamanho == 0);
}

//c

int isFullQ (QUEUE *q){
    return (q->tamanho == MAX);
}

int enqueue (QUEUE *q, int x){
    if(!isFullQ(q)){
        q->valores[(q->tamanho + q->inicio) % MAX] = x;  //this
        q->tamanho++;
        return 1;
    }
    return 1;
}

//d
int dequeue (QUEUE *q, int *x){
    if(!isEmptyQ(q)){
        (*x) = q->valores[q->inicio];
        q->inicio = (q->inicio+1) % MAX;   //this
        q->tamanho--;
        return 0;
    }
    return 1;
}

//e
int front (QUEUE *q, int *x){
    if(!isEmptyQ(q)){
        (*x) = q->valores[q->inicio];
        return 0;
    }
    return 1;
}


void showQueue (QUEUE q){
    int pos;
    for(int i=0; i<q.tamanho ; i++){
        pos = (q.inicio + i) % MAX;
        printf("\n%d   em %d", q.valores[pos], pos);
    }
}

/////////////////

typedef struct queue2 {
    int size; //guarda o tamanho do array valores
    int inicio, tamanho;
    int *valores;
} QUEUE2;

void initQueue2 (QUEUE2 *q){
    q->inicio = 0;
    q->tamanho = 0;
    q->size = 10;
}

int enqueue2 (QUEUE2 *q, int x){
    int r = 0, *t, i, j;
    if(q->tamanho == q->size){
        t = malloc(2*q->size*sizeof(int)); //arranjar espaco parra o array maior
        for(i=0, j=q->inicio; j<q->size; i++, j++)
            t[i] = q->valores[j];
        for(j=0; j<q->inicio; i++, j++)
            t[i] = q->valores[j];
        free(q->valores); q->valores = t;
        //q->capacidade [...]
    }
}

int main(){
    QUEUE q;
    initQueue(&q);
    for(int i = 0; i<8; i++)
        enqueue(&q, i);
    int x;
    dequeue(&q, &x);
    showQueue(q);

    QUEUE2 q2;
    initQueue(&q);

    return 0;
}