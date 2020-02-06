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