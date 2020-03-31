#include <stdio.h>  //standard io, printfs
#include <stdlib.h> //standard io, mallocs

#define MAX 100
typedef struct stack
{
	int sp;
	int valores [MAX];
} STACK, *STACKPTR;

//

void initStack (Stack *s){
	s->sp = 0;
}

//

int isEmptyS (Stack *s){
	return (s->sp==0)? 1 : 0;
}

//

int isFullS (Stack *s){
	return (s->sp < MAX)? 0 : 1;
}

int push (Stack *s, int x){ //se conseguir inserir retorna 0, se não 1.
	if (!isFullS(s)){           //se nao está cheia
		s->valores[s->sp++]		//colocamos o valor em sp
		return 0;				// e incrementamos o sp depois da operação.
	}
	else return 1;
}

//

int pop (Stack *s, int *x){ //se estiver vazia não conseguimos fazer o pop
	if(isEmptyS(s))	return 1;
	else{
		(*x) = s->valores[s->sp-1] //o & dá-me a referencia para a variável
		s->sp--;
		return 0;
	}
}

//

int top (Stack *s, int *x){
	if(isEmptyS(s))	return 1;
	else{
		(*x) = s->valores[s->sp-1] //o & dá-me a referencia para a variável
		return 0;
	}
}
//o elemento que está no topo da stack, o último a ser inserido, lifo, está em s->sp-1. 

//

void showStack(STACK s){
	for(int i=0; i<s.sp; i++){ //o s é uma stack não um apontador, daí ser assim: s.sp 
		printf("%d ", s.valores[i]);
	}printf("\n");
}

int main(){
	STACK s1;
	STACKPTR s2; //s2 é um apontador para uma struct, por isso é preciso alocar espaço[linha 63]

	initStack(&s1); //como são structs, tenho que passar os endereços
	s2 = (STACKPTR) malloc(sizof(STACK)); //malloc, aloca espaço de memória
	//"dá-me um bloco de memoria que dê para guardar a stack s2"
	//"(STACKPTR) malloc, converte-me o void pointer que o malloc retorna em STACKPTR"
	initStack(s2); 

	for(int i=0; i<50; i++){
		push(&s1, i);
		push(s2, 2*i);
	}

	showStack(s1)  //precisa de uma stack e o s1 já é uma stack
	showStack(*s2) //precisa de mostrar para onde mostra o apontador

	for(int j=0; j<20; j++)
		pop(&s1, &x);
	showStack(s1)

	return 0;
}

// compile: gcc -o s.exe stack.c
// run: 	./s.exe


 //a STACK é uma stack e a STACKPTR é o apontador para uma struct stack.