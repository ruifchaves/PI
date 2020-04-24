

#ifndef _DIC
#define _DIC

typedef struct entrada{
    char *palavra;
    int ocorr;
    struct entrada *prox;
} *Palavras, Palavra;

typedef struct sDic{
    Palavras lista;
    int npal;
} Dicionario;

void initDic(Dicionario *d);
int acrescenta (Dicionario *d, char *pal);
void showDic (Dicionario d);
char *maisFreq (Dicionario d, int *c);

#endif