#include <stdio.h>
#include <stdlib.h>


// aux 
void printv(int v[], int N) {
    for (int i=0;i<N; i++)
        printf("%d ", v[i]);
    printf("\n");
}


int maxInd (int v[], int N) {
    int max=v[0], maxi=0;
    for (int i=1; i<N; i++)
        if (v[i] > max) {
            max = v[i];
            maxi = i;
        }
    return maxi;
}


void maxIndSort(int v[], int N) {
    for (int i = N-1; i > 0; i--) {
        int maxi = maxInd(v, i+1);
        int aux = v[i];
        v[i] = v[maxi];
        v[maxi] = aux;
    }
}


void maxIndSort2(int v[], int N) {
    int max, maxi;
    for (int i = N-1; i > 0; i--) {
        //int maxi = maxInd(v, i+1);
        max = v[i];
        maxi = i;
        for(int j=0; j<i; j++) {
            if (v[j] > max) {
                max = v[j];
                maxi = j;
            }
        }
        int aux = v[i];//2
        v[i] = max;//77
        v[maxi] = aux;//2
    }
}

// data Stack = S [Int] Int
// data Queue = Q Int Int [Int]

#define MAX 1
typedef struct queue {
    int inicio;
    int tamanho;
    int valores [MAX];
} QUEUE;


void initQueue (QUEUE *q) {
    q->inicio = 0; // q->inicio = MAX-1;
    q->tamanho = 0;
}

// >0 => esta fazia
// 0 => nao esta vazia
int isEmptyQ (QUEUE *q) {
    int i;

    if ( q -> tamanho == 0 ) 
        i = 1;
    else 
        i = 0 ;

    return i ;
}

int isFullQ(QUEUE *q) {
    int i;

    if ( q -> tamanho == MAX ) 
        i = 1;
    else 
        i = 0 ;

    return i ;
}

int sizeQ(QUEUE *q) {
    return q->tamanho;
}

int enqueue (QUEUE *q, int x) {
    int i;
    if (isFullQ(q))
        i=1;
    else {
        i=0;
        q->valores[q->tamanho] = x;
        q->tamanho++;
    }
    return i;
}

// N = 5, i=4, i<4 => i=3
void shift(QUEUE *q, int N) {
    for(int i=0; i<N-1; i++)
        q->valores[i] = q->valores[i+1];
}

int dequeue (QUEUE *q, int *x) {
    int i;
    if (isEmptyQ(q))
        i=1;
    else {
        i=0;
        *x = q->valores[q->inicio];
        shift(q, q->tamanho);
        q->tamanho--;
    }
    //inicio++;
    return i;
}



int main(int argc, char const *argv[])
{   
    int size = 14;
    int v[15]={19, 1,14,4,5, 6, 2, 8, 9,  11,12,3,33,77};
    
    maxIndSort2(v, size);
    printv(v, size);

    QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
    initQueue(q);
    int ie = isEmptyQ(q);
    printf("queue vazia: %d\n", ie);
    int x;
    ie = dequeue(q, &x);
    printf("consegui dequeue? %d\n", ie);
    ie = enqueue(q, 5);
    printf("consegui queue %d\n", ie);
    ie = dequeue(q, &x);
    printf("consegui dequeue? %d, tirei valor %d\n", ie, x);
    ie = isEmptyQ(q);
    printf("queue vazia: %d\n", ie);
    ie = enqueue(q, 7);
    printf("consegui queue %d\n", ie);
    ie = enqueue(q, 9);
    printf("consegui queue %d\n", ie);
    ie = dequeue(q, &x);
    printf("consegui dequeue? %d, tirei valor %d\n", ie, x);
    ie = isEmptyQ(q);
    printf("queue vazia: %d\n", ie);
    ie = dequeue(q, &x);
    printf("consegui dequeue? %d, tirei valor %d\n", ie, x);

    ie = enqueue(q, 7);
    printf("consegui queue %d\n", ie);
    ie = isFullQ(q);
    printf("queue cheia: %d\n", ie);
    ie = enqueue(q, 77);
    printf("consegui queue %d\n", ie);
    ie = dequeue(q, &x);
    printf("consegui dequeue? %d, tirei valor %d\n", ie, x);
    ie = isFullQ(q);
    printf("queue cheia: %d\n", ie);
    return 1;
}




