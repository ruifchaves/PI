#include <stdio.h>


//1.
float multInt (int n, float m){
    int r = 0;
    for(n ; n; n--)
        r += m;
    return r;
}

//2.
float multIntV2 (int n, float m){
    int soma = 0;
    for( ; n ; n/=2, m*=2)
        if(n%2) soma+=m;
    return soma;
}

//3.
int mdc (int a, int b){
    int menor = (a>b) ? b : a;
    int maior = (a>b) ? a : b;
    for(int i=menor; i>=0; i--){
        if(a%i==0 && b%i==0) return i;
    }
}

//4.
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

//5.
int ex5 (int a, int b){
    while(a>0 && b>0){
        if(a>b) a%=b;
        else b%=a;
    }
    return (a==0) ? b : a;
}


//compile: gcc -o Ficha2.exe Ficha2.c
//         gcc Ficha2.c -o Ficha2
//run: ./Ficha2.exe	
void main(){
    printf("%f\n", multInt(5, 5));
    printf("%f\n", multIntV2(81, 423)); //34263

    printf("%d\n", mdc(12, 18)); //6
    printf("%d\n", mdcV2(12, 18));
    printf("%d\n", mdcV3(12, 18));

    printf("%d\n", ex5(126, 45)); //9
}