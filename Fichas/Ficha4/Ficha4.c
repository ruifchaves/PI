#include <stdio.h>

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


//5
#define MAX 100
typedef struct stack{
    int sp;
    int valores [MAX];
} STACK;

//a)
void initStack (Stack *s){

}

//b)
int isEmptyS (STACK *s){

}

//c)
int push (STACK *s, int *x){

}

//d)
int pop (STACK *s, int *x){
    
}

//e)
int top (STACK *s, int *x){
    
}








void main(){
    printf("\n");

}