

#include <stdio.h>  //chamar: ficha8 f1.txt argv[0] é o nome do prog, argv[1] é o nome do ficheiro.

int main (int argc, char *argv[]){ //argc é o número de argumentos passados
    FILE *input;    //struct que cria apontador para o sitio que está a ler
    int r=0, count=0;
    char word[100];  //array de chars, aka string
    //se só for passado um argumento, input passa a ser o stdin(normalmente associado ao teclado)
    if (argc==1) input=stdin; //ao chamar um programa tem sempre um argumento pelo menos arg>1
    else input=fopen(argv[1],"r"); //"r" flag de ler o ficheiro

    if (input==NULL) r=1; //há varios casos em que possa ser null
    else {  //se correu tudo bem ao fechar o fichiro..
        while ((fscanf(input,"%s",word)==1)){  //vamos ler uma string. enquanto conseguir ler é igual a 1, passa a 0 quando se deixa de ler
            count ++;  //conta o numero de palavras
            printf("--> %s\n", word); //retorna a ultima palavra lida
        } 
        fclose (input);
        printf ("%d palavras\n", count); 
    }
    return r;
}

typedef struct entrada{  //stuct lista ligada de palavras
    char* palavra; //string
    int ocorr;     //inteiro num ocorrencias
    struct entrada *prox; //
} *Palavras;

//run: gcc -o ficha8 ficha8.c
//um fichiero tem que ter sempre a marca endoffile(para o programa ), que é ctrl + d!!