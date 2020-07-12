#include <stdio.h>

//2.
void swapM(int *x, int *y){
    int aux = *x;  //aux = apontador para x
    *x = *y;    //apontador para x (passa a ser) apontador para y
    *y = aux;   //apontador y (passa a ser) apontador para x;
}

//3.
void swap(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

//4.
int soma(int v[], int N){
    int soma=0;
    for(int i = 0; i<N; i++)
        soma += v[i];
    return soma;
}

//5.
int maximum (int v[], int N, int *m){
    *m = v[0];
    int ret = 1;
    for(int i = 0; i<N; i++){
        if( v[i] > (*m)) (*m) = v[i];
        ret = 0;
    }
    return ret; //return (*m); para testar
}

//6.
void quadrados(int q[], int N){
    for(int i = 0; i<N; i++)
        q[i] = (i*i);
}

//7.
void pascal(int v[], int N){    
    for(int i = 0; i<N; i++){
        v[i] = 1;
        for(int j = i-1; j>0; j--)
            v[j] += v[j-1];
    }
}


//compile: gcc -o Ficha3.exe Ficha3.c
//         gcc Ficha3.c -o Ficha3
//run: ./Ficha3.exe	
void main(){
    int x=3, y=5;
    swapM(&x, &y); //apontador contem os enderecos da variavel, &x passamos os enderecos
    printf("%d %d\n", x, y);

    int v[5] = {1, 2, 3, 4, 5};
    int i1=1, i2=2;
    swap(v, i1, i2);
    printf("%d %d\n", v[i1], v[i2]);
    printf("%d\n", soma(v, 5));
    
    int p;
    printf("%d\n", maximum(v, 5, &p));  

    int tam=5, q[tam];
    quadrados(q,tam);
    putchar('\n');
    for(int i=0; i<tam; i++)
        printf("%d ", q[i]);

    int t=6, m[t];
    pascal(m,t);
    putchar('\n');
    for(int i=0; i<t; i++)
        printf("%d ", m[i]);
}