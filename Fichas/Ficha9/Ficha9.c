#include <stdio.h>
#include <stdlib.h>

typedef struct abin {
    char *pal;
    int ocorr;
    struct abin *esq, *dir;
} *Dicionario;

void initDic (Dicionario *d){
    (*d) = malloc(sizeof(struct abin));
    (*d) = NULL;
}

int acrescenta (Dicionario *d, char *pal){
    int r = 1;
    Dicionario pt = *d, ant = NULL;
    while(pt != NULL && r == 1){
        
    }
    if(*d == NULL){
        *d = malloc(sizeof(struct abin));
        (*d)->pal = malloc(sizeof(pal) + 1);
        strcpy((*d)->pal, pal);
        (*d)->ocorr = 1;
        (*d)->dir = (*d)->esq = NULL;
    } else if(r==1){

    }

}