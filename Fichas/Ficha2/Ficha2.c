#include <stdio.h>


//////1
float multInt (int n, float m){
    int r=0;
    for(int i=0; i<n; i++)
        r+=m;
    return r;
}

///////2

float multIntV2 (int n, float m){
    int soma = 0;
    for(; n>0; n/=2, m*=2)
        if(n%2!=0) soma+=m;
    return soma;
}

float multIntV3 (int n, float m){
    int soma = 0;
    while(n>0){
        if(n%2!=0) soma+=m;
        n/=2; m*=2;
    }
    return soma;
}

/////3
int mdc (int a, int b){
    int menor = (a>b) ? b : a;
    int maior = (a>b) ? a : b;
    for(int i=menor; i>=0; i--){
        if(a%i==0 && b%i==0) return i;
    }
}

///////4
int mdcV2 (int a, int b){ //com recursividade, acho que não é suposto
    if(a==b) return a;
    if(a>b) mdcV2(a-b,b);
    else mdcV2(a,b-a);
}

int mdcV3 (int a, int b){
    while(a>0 && b>0){
        if(a==b) return a;
        if(a>b) a-=b;
        else b-=a;
    }
}

///////5
int ex5 (int a, int b){
    while(a>0 && b>0){
        if(a>b) a%=b;
        else b%=a;
        if(a==b) return a;
    }
}


//compile: gcc -o Ficha2.exe Ficha2.c
//         gcc Ficha2.c -o Ficha2
//run: ./Ficha2.exe	
void main(){
    printf("\n%f",multInt(5,5));
    printf("\n%f",multIntV2(5,5));
    printf("\n%f",multIntV3(5,5));

    printf("\n%d",mdc(30,50));
    printf("\n%d",mdcV2(30,50));
    printf("\n%d",mdcV3(30,50));

    printf("\n%d",ex5(30,50));
}