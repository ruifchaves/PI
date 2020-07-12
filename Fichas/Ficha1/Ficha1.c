#include <stdio.h>

//2
void quadrado(int x){
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++)
            putchar('#');
        putchar('\n');
    }
}

//3
void xadrez(int x){
    int conta=0;
    for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            if(conta%2==0) putchar('#');  //if((i+j)%2)
            else putchar('_');
            conta++;
        }
        putchar('\n');
    }
} 

//4
int triangulo1(int x){
    for(int i=0;i<x;i++){
        for(int j=0; j<i; j++)
            putchar('#');
        putchar('\n');
    }
    for(int i=x;i>0;i--){
        for(int j=0; j<i; j++)
            putchar('#');
        putchar('\n');
    }
}

void triangulo2 (int n){
    for(int i = 1; i<=n; i++){
        for(int j = (n-i)/2; j; j--) putchar(' ');
        for(int l = i; l; l--) putchar('#');
        putchar('\n');
        i++;
    }
}

//compile: gcc -o Ficha1.exe Ficha1.c
//         gcc Ficha1.c -o Ficha1
//run: ./Ficha1.exe	
void main(){
    quadrado(5);
    printf("\n");
    xadrez(5);
    printf("\n");
    triangulo1(5);
    printf("\n");
    triangulo2(5);
}