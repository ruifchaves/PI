#include <stdio.h>
#define MAX = 20;

void insere (int v[], int N, int x){ //vetor ordenado
	int j=0;
	for(int i=0; v[i]<x && i<N; i++);
	if(i==N) v[i]=x;
	else{
		for(int l=N; l>=i; l--)
			v[l]=v[l-1];
		v[i]=x;
	}
}


void insere (int v[], int N, int x) {
	int i=N-1;
	while (x<v[i] && i>=0){
		v[i+1] = v[i];
		i--;
	}
	v[i] = x; //testar
} 

// FAZER A DE BAIXO

void iSort (int v[], int N) {
	int i;
	for (i=1; (i<N); i++)
		insere (v, i, v[i]);
}

//

int maxInd (int v[], int N){
	if(N<=0) return -1;
	else{
		int max=v[0], ind = 0;
		for(int i=1; i<N; i++){
			if(v[i]>max){
				max = v[i];
				ind = i;
			}
		}
		return ind;
	}
}

//

41
void swap (int v[], int i, int j){
	int t=v[i];
	v[i]=v[j];
	v[j]=t;
}

int maxSort(int v[], int N){
	int i,res;
    for (i=1; (i<N); i++){
        res=maxInd(v,i);
        if(res != i) swap(v,res,i);
    }
}

//

void showArray(int v[], int N){
	for(int i=0; i<N; i++)
		printf("%d ", v[i]);
	putchar('\n');
}

int main(){
	int A[MAX] = {12, 25, 37};
	int B[MAX] = {23, 93, 7, 13, 45}

	insere(A, 3, 17);
	showArray(A, 4);

	iSort(B, 5);
	showArray(B, 5);

	printf("MaxPos em B: %d", maxInd(B, 5));
	iSort(B, 5);
	printf("MaxPos em B: %d", maxInd(B, 5));

	maxSort()

	return 0;
}

//compile: gcc -o Ficha5.exe Ficha5.c
//run: ./Ficha5.exe


//50 QUESTOES
//esta tem tres erros no codeboard
int difConsecutivos(char s[]) {
    int i=0,j=0,conta1=1, conta2=0;
    while(s[i]){
        conta1=1;
        for(j=i;s[j] && s[j+1] && s[j]!=s[j+1];j++) if(s[j+1]!=0) conta1++;
        if(conta1>conta2){
            conta2=conta1;
        }
        
        i++;
    }
}

//esta está correta
int i = 0; int cont = 1, maiorcont = 1;
for( i = 0; s[i]; i++){
   if (s[i] != s[i+1]) cont ++;
   else {
         if(maiorcont < cont){
              maiorcont = cont;
        }
         cont = 1;
     }
 }
return maiorcont;