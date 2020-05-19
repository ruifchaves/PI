#include <stdio.h>
#define MAX 20

//1
void insere (int v[], int N, int x){
    int i;
    for(i = N; v[i]>x && i>=0; i--){ //i = N-1 && v[i+1]==v[i] nao funciona
        v[i]=v[i-1];
    }
    v[i]=x;
}

//ou 
void insere2 (int v[], int N, int x){ //vetor ordenado
	int j=0, i;
	for(i=0; v[i]<x && i<N; i++);
	if(i==N) v[i]=x;
	else{
		for(int l=N; l>=i; l--)
			v[l]=v[l-1];
		v[i]=x;
	}
}

//2
void iSort (int v[], int N){
    int i;
    for (i=1; (i<N); i++){
        insere (v, i, v[i]);
    }
}

void iSortAlt(int v[], int N){ //TODO

}

//3
int maxInd (int v[], int N){
    if(N<=0) return -1;
    else{
        int iMaior = 0;
        for(int i=0; i<N; i++)
            if(v[i]>v[iMaior]) iMaior = i;
        return iMaior;
    }
}

//ou
int maxInd2 (int v[], int N){
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

//4
void swap(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void maxSort (int v[], int N){ //TODO
    int i, ret;
    for(i=1; i<N; i++){
        ret = maxInd(v, i);
        if(ret != (i-1)) swap(v, ret, i);  //resolucao prof: (ret != i)
    }
}

//6
void bubble (int v[], int N){ //o maior elemento do vetor encontra se na última posição.
    int i;
    for(i=1; i<N; i++)
        if(v[i-1] > v[i])
            swap (v, i-1, i);
}

//7
void bubbleSort (int v[], int N){ //TODO
    for(int i=1; i<N; i++)
        bubble(v,i);
}

//////////

void showArray(int v[], int N){
    printf("\n[");
    for(int i=0; i<N; i++)
        printf("%d ",v[i]);
    printf("]\n");
}

int main(){
    int A[MAX] = {1,2,3,4,5};
	int B[MAX] = {23, 93, 7, 13, 45, 43, 33};
   	int C[MAX] = {23, 33, 7, 45, 3};


    showArray(A, 5);
    insere(A, 5, 7);
    insere(A, 6, 3);
    showArray(A, 7);


    printf("\nIndice de max B: %d", maxInd(B, 7));
    showArray(B, 7);
    iSort(B, 7);
    showArray(B, 7);
    printf("\nIndice de max B depois de Sort: %d", maxInd(B, 7));

    maxSort(C, 5);
    showArray(C, 5);

    int D[MAX] = {2, 6, 4, 8, 1};
    bubble(D, 5);
    showArray(D, 5);
    bubbleSort(D, 5);
    showArray(D, 5);

    return 0;
}

//gcc -o Ficha5.exe Ficha5.c
//.\Ficha5.exe