#include "dicionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initDic (Dicionario *d){
    d->lista = NULL;
    d->npal = 0;
}

Palavras existePal(Palavras pals, char *pal){
    Palavras res = NULL;
    while(pals && strcmp(pals->palavra, pal) != 0)
        pals = pals->prox;

    if(pals && strcmp(pals->palavra, pal)==0)
        res = pals;

    return res;
}

int acrescenta (Dicionario *d, char *pal){
    Palavras palPtr;
    if((palPtr = existePal(d->lista ,pal))){
        palPtr->ocorr++;
    }
    else{
        d->npal++;
        palPtr = malloc(sizeof(Palavra));
        palPtr->palavra = strdup(pal);
        palPtr->ocorr = 1;
        palPtr->prox = d->lista;
        d->lista = palPtr;
    }
    return d->npal;
}

void showPalavras(Palavras pals){
    if(pals){
        printf("%s :: %d\n", pals->palavra, pals->ocorr);
        showPalavras(pals->prox);
    }
}

void showDic(Dicionario d){
    printf("%d Palavras: \n\n", d.npal);
    showPalavras(d.lista);
}

char *maisFreq (Dicionario d, int *c);

//gcc -c dicionario.c
//gcc -c readFile.c
//gcc -o r.exe readFile.o dicionario.o
//./r.exe
//write somthing to be read
//Generate EOF(end of file) -> "What generates EOF is platform dependent. If you are on *nix systems, use CTRL+D. CTRL+Z works on Windows"