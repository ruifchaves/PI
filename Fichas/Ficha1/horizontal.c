#include <stdio.h>



int horizontal(int x){
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

//gcc -c horixontal.c