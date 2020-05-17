
#include <stdio.h>  //standard input output, printfs
#include <stdlib.h> //standard library, mallocs
#include <ctype.h>  //corrigir warning: implicit declaration of function 'isspace';


//1
int minusculas(char s[]){
    int conta=0;
    for(int i=0; s[i]; i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i] - 32;
            conta++;
        }
    }
    return conta;
}

//2
int contalinhas(char s[]){
    int conta=0;
    if(s[0]){
        conta++;
        for(int i = 1; s[i]; i++)
            if(s[i]=='\n') conta++;
    }
    return conta;
}

//3
int contaPal(char s[]){
	int i=0, flag=1, conta=0;
	for(i;s[i];i++){
		if(!isspace(s[i]) && flag) conta++;
		flag=isspace(s[i]);
	}
	return conta;
}


//4
int procura (char *p, char *ps[], int N){
    int ret = 0;
    for(int i=0; ps[i]; i++){
        if(p == ps[i]){
            ret = 1;
            break;
        }
    }
    return ret;
}


////////////////////////

//5  LIFO
#define MAX 100
typedef struct stack {
    int sp;
    int valores [MAX];
} STACK, *STACKPTR;
 //a STACK é uma stack e a STACKPTR é o apontador para uma struct stack.

//a)
void initStack (STACK *s){
    s->sp = 0;
}

//b)
int isEmptyS (STACK *s){
    return (s->sp == 0) ? 1 : 0;
}

//c)
int isFullS (STACK *s){
    return (s->sp==MAX) ? 1 : 0;
}

int push (STACK *s, int x){ //se conseguir inserir retorna 0, se não 1.
    if(!isFullS(s)){        //se nao está cheia colocamos o valor em sp e incrementamos o sp depois da operação.
        s->valores[s->sp++] = x;
        return 0;
    }
    return 1;
}

//d)
int pop (STACK *s, int *x){
    if(!isEmptyS(s)){
        (*x) = s->valores[--s->sp];  //o & dá-me a referencia para a variável,  "COLOCAR NO ENDEREÇO X"
        return 0;
    }
    return 1;
}

//e)
int top (STACK *s, int *x){
    if(!isEmptyS(s)){
        (*x) = s->valores[s->sp];  //o & dá-me a referencia para a variável
        return 0;
    }
    return 1;
}


    ///////////////////////
    void showStack (STACK s){
        putchar('\n');
        for(int i = 0; i<s.sp; i++){ //s é uma stack não um apontador, daí ser s.sp. Se fosse apontador: s->sp ou (*s).sp
            printf("%d ",s.valores[i]);
        }
        putchar('\n');
    }

    int main(){
        STACK s1;
        STACKPTR s2; //s2 é um apontador para uma struct, por isso é preciso alocar espaço

        initStack(&s1); //como são structs, tenho que passar os endereços
        s2 = (STACKPTR) malloc(sizeof(STACK)); //malloc, aloca espaço de memória
	    //"dá-me um bloco de memoria que dê para guardar a stack s2"
	    //"(STACKPTR) malloc, converte-me o void pointer que o malloc retorna em STACKPTR"
        initStack(s2);

        for(int i = 0; i<=20; i++){
            push(&s1, i);
            push(s2, 2*i);
        }

        printf("\nisEmptyS s1: %d",isEmptyS(&s1));
        printf("\nisEmptyS s2: %d",isEmptyS(s2));
        printf("\nisFullS s1: %d",isFullS(&s1));
        printf("\nisFullS s2: %d",isFullS(s2));

        int x, y;
        for(int j = 0; j<5; j++){
            pop(&s1, &x);
            pop(s2, &y);
        }

        showStack(s1);  //precisa de uma stack e o s1 já é uma stack
        showStack(*s2); //precisa de mostrar para onde mostra o apontador

        return 0;
    }
    //compile: gcc -o Ficha4.exe Ficha4.c
    //         gcc Ficha4.c -o Ficha4
    //run: ./Ficha4.exe	

    //pede um apontador e não é um apontador(é uma struct), function(&s)
    //pede um normal(uma struct) e é apontador, function(*s)