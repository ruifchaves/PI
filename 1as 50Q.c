#include <stdio.h>

/* 
----INICIALIZAÇÂO----
gcc 1ª50Q.c -o 50Q
./50Q
*/

//scanf necessita de &x 
//do...while para pelo menos correr o ciclo uma vez, as in ver se o 1o valor que das é 0.
void maior(){
	int maior = 0, x;
	printf("Escreva uma sequência de números inteiros e termine com 0.\n");
	do{
		scanf("%d",&x);
		if(x > maior) maior = x;
	} while(x!=0);
	printf("O maior número é o %d.\n", maior);
}

void media(){
	int soma=0, i=0, x;
	float media=0;
	printf("Escreva uma sequência de números inteiros e termine com 0.\n");
	do{
		scanf("%d",&x);
		i+=1;
		soma=soma+x;
		//printf("soma: %d, i: %d\n",soma,i); 				para teste
	}while(x!=0);
	i--;													//o i incrimenta com x = 0 daí decrementar uma vez fora dps do ciclo
	media = soma/i;
	printf("A média dos números é %.5f.\n", media);         //%.5f porque a media corresponde a um float, com 5 digitos dps do ponto
}

void sndmaior(){
	int maior=0, segundomaior=0, x;
	printf("Escreva uma sequência de números inteiros e termine com 0.\n");
	do{
		scanf("%d",&x);
		if(x > maior){
			segundomaior = maior;
			maior = x;
		}
		else
			if(x > segundomaior) segundomaior=x;
	} while(x!=0);
	printf("O segundo maior número é o %d.\n", segundomaior);
}

void main(){
	//maior();
	//media();
	sndmaior();
}

int bitsUm(unsigned int n){
	int conta=0;
	while(n!=0){
		if(n%2) conta++;
		n/=2;
	}
	return conta;
}

int trailingZ(unsigned int n){   //o nº de zeros no final representacao. 00101010 -> return 2;
	int conta=0;
	while(n!=0){
		if(n%2==0) conta++;
		else break;
		n/=2;
	}
	return conta;
}

int qDig(unsigned int n){
	int conta=0;
	while(n!=0){
		conta++;
		n/=10;
	}
	return conta;
}
/*
ex: n = 440
iteracao 1: n=44, r=1
iteracao 2: n=4, r=2
iteracao 3: n=0, r=3
*/

char *mystrcat (char s1[], char s2[]){
	int i=0, j=0;
	while(s1[i]){
		i++;
	}
	//ou  for(i;s1[i];i++);  ou mystrlen
	for(j,i; s2[j]; j++,i++){
		s1[i]=s2[j];
	}
	s1[i]='\0';                              //importante nas funções com char
	return s1;
}

//ou

char *mystrcat (char s1[], char s2[]){
	int i=0, j=0;
	for(i;s1[i];i++);
	for(j,i; s2[j]; j++,i++){
		s1[i]=s2[j];
	}
	s1[i]='\0';
	return s1;
}

//ou

int mystrlen(char s[]){
	int i=0;
	for(i; s[i]; i++);
	return i;
}

char *mystrcat(char s1[], char s2[]){
	int i=mystrlen(s1), t=0;
	for(;s2[t];t++ & i++){
		s1[i]=s2[t];
	}
	s1[i]='\0';
	return s1;
}




char *mystrcpy (char *dest, char source[]){
	int i=0;
	for(i; source[i]; i++){
		dest[i]=source[i];
	}
	dest[i]='\0';
	return dest;
}

int mystrcmp(char s1[], char s2[]){
	int i=0;
	while(s1[i] && s2[i] && s1[i]==s2[i]) i++;
	return (s1[i]-s2[i]);
}