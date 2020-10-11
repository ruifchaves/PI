#include <stdio.h>



void vertical (int n){
    for(int i = 1; i<=n; i++){
        for(int j = (n-i)/2; j; j--) putchar(' ');
        for(int l = i; l; l--) putchar('#');
        putchar('\n');
        i++;
    }
}

//gcc -c vertical.c