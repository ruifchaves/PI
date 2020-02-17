#include <stdio.h>
#include <string.h>


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


/*											MAL, EXEMPLO:
int strstraux (char s1[], char s2[]){		Input: s1="ABCDEF" -- s2="CDEF"
											Output: expected "CDEF"
									        obtained NULL
											5 testes correctos
	int i=0;								
	for(;s1[i]==s2[i];i++);
	if(!s2[i]) return 1;
	else return 0;
}
*/ 

int strstraux (char s1[], char s2[]){
	int i=0;
	for(;s2[i];i++){				//s2[i]!!!!!!!! se for s1[i] não funcemina
		if(s1[i]!=s2[i]) return 0;
	}
	return 1;
}

char *mystrstr (char s1[], char s2[]){
	int i=0;
	if(s1[i] && s2[i]){
		for(i;s1[i];i++){
			if(strstraux(&s1[i], s2)) return &s1[i]; 
		}
		return NULL;
	}
	return s1;
}




int mystrlen (char s[]){
	int i=0;
	for(i;s[i];i++);
	return i;
}

void strrev (char s[]){  										//j=mystrlen(s)-1!!!
	int i=0, j=mystrlen(s)-1, l=(mystrlen(s)/2);   //se o número de letras for ímpar, ele deixa a letra do meio no sítio
	char store; 								   //example:    rui     -> iur
	for(i;i<l;i++,j--){							   //example #2  chaves  -> sevahc
		store=s[i];
		s[i]=s[j];
		s[j]=store;
	}
}



/*																1 de 10 certas
int mystrlen (char s[]){
	int i=0;
	for(; s[i]; i++);
	return i;
}

int isVogal (char s){
	if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u' || s=='A' || s=='E' || s=='I' || s=='O' || s=='U') return 1;
	else return 0;
}

void strnoV (char s[]){
	int i=0, len=(mystrlen(s)-1), m;
	while(s[i]){
		if(isVogal(s[i])){
			for(m=i;m<len;m++)
				s[m]=s[m++];
			s[m]='\0';
			len--;
		}
		else i++;
	}
	s[i]='\0';
}
*/


void strnoV (char s[]){
	int i=0, d=0;
	while(s[i]){
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') i++;
		else{
			s[d]=s[i];
			d++;
			i++;
		}
	}
	s[d]='\0';
}
/*
chaves
     d i 
c    1 1
ch   2 2
ch   2 3
chv  3 4
chv  3 5
chvs - - 
*/





void truncW (char t[], int n){
	int i=0, d=0, j;
	while(t[i]){
		if(t[i]==' '){
			t[d]=t[i];
			i++;
			d++;
		}
		else{ 
			for(j=0; j<n && t[i]!=' '; j++,i++,d++){      //&& t[i]!=' ' -> necessario pq no ciclo for, na palavra ' e ...' o i incrementa e vai ser acrescendo os caracteres seguintes pq ele não testa se a palavra tem menos do que 'n' valores(ou seja não testa se não corresponde a um espaco)
				t[d]=t[i];
			}
			while(t[i]!=' ' && t[i]) i++;
		}
	}
	t[d]='\0';
}