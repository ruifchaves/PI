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


void main(){
	maior();
}