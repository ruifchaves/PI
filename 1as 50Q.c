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



int cMFAux (char c, char s[]){
	int i=0, conta=0;
	while(s[i]){
		if(s[i]==c) conta++;
		i++;
	}
	return conta;
}

char charMaisFreq (char s[]){
	int i=0, cMFconta=0;
	char cMF='\0';       			    //return 0 caso a string seja vazia.
	for(i;s[i];i++){
		if(cMFAux(s[i],s)>cMFconta){  	//não pode ser >=  !!!
			cMF=s[i];
			cMFconta=cMFAux(s[i],s);
		}
	}
	return cMF;
}




/*
a = 0;
b = a++;  // use the value and then increment --> a: 1, b: 0

a = 0;
b = ++a;  // increment and then use the value --> a: 1, b: 1
*/
int iguaisConsecutivos (char s[]){
	int i=0, conta=1, maior=0;
	while(s[i]){
		for(;s[i]==s[++i] && s[i];)
			conta++;
			//printf("conta: %d; char: %c \n", conta, s[i]);
		maior=(conta>maior) ? conta : maior;
		conta=1;
	}
	return maior;
}




/* AMBOS OS PRÓXIMOS DÃO ISTO:														///VER
Input: "mundo cruel!!!"
Output: expected 10, obtained 12
1 testes correctos
*/
int difConsecutivos (char s[]){
	int i=0, conta=1, maior=0;
	while(s[i]){
		for(;s[i]!=s[++i] && s[i];){
			conta++;
			printf("conta: %d; char: %c \n", conta, s[i]);
		}
		maior=(conta>maior) ? conta : maior;
		conta=1;
	}
	return maior;
}
int difConsecutivos(char s[], int n){
	int i=0,conta=0,maiorSeq=0;
	char last='\0';
	for(i;s[i];i++){
		if(s[i]!=last) conta++;
		else conta=1;
		last=s[i];
		if(conta>maiorSeq) maiorSeq=conta;
		printf("%d",conta);
	}
	printf("\n");
	return maiorSeq;
}





int maiorPrefixo(char s1[], char s2[]){
	int i=0, conta=0;
	while(s1[i] && s2[i] && s1[i]==s2[i]){
		conta++;
		i++;
	}
	return conta;
}





int mystrlen (char s[]){
	int i=0;
	for(i;s[i];i++);
	return i;
}

int maiorSufixo(char s1[], char s2[]){
	int s1len=mystrlen(s1)-1, s2len=mystrlen(s2)-1, conta=0;
	while(s1[s1len] && s2[s2len] && s1[s1len]==s2[s2len]){
		conta++;
		s1len--;
		s2len--;
	}
	return conta;
}




int sufPrefAux (char s1[], char s2[]){
	int conta=0, i=0;
	for(i; s1[i]; i++){
		if(s1[i]==s2[i]) conta++;
		else break;
	}
	if(!s1[i]) return conta;
	else return 0;
}

int sufPref (char s1[], char s2[]){
	int i1=0, prefSufConta=0;
	for(i1; s1[i1]; i1++){
	    //printf("conta: %d \n",prefSufConta);
		if(s2[0]==s1[i1])
		     prefSufConta = (prefSufConta<sufPrefAux(s1+i1, s2)) ? sufPrefAux(s1+i1, s2) : prefSufConta;
	}
	return prefSufConta;
}


/////////////////////// ANO PASSADO - mais simples
int mStrlen(char s[]){
	int i;
	for(i=0;s[i];i++);
	return i;
}

int sufPrexAux(char s1[], char s2[]){
    int i=0;
    while(s1[i] && s2[i] && s1[i]==s2[i]) i++;		//for(i;s1[i] && s2[i] && s1[i]==s2[i];i++);
    return (s1[i]=='\0');
}

int sufPref(char s1[], char s2[]){
    int i, max=mStrlen(s1);							//  |int i=mStrlen(s1)-1
    for(i=0;s1[i];i++){								//  |for(i;s1[i] && s2;i--){
        if(sufPrexAux(s1+i,s2)) return max-i;
    }
	return 0;
}







int contaPal (char s[]){
	int i=0, flag=1, conta=0;
	for(i;s[i];i++){
		if(!isspace(s[i]) && flag) conta++;
		flag=isspace(s[i]);
	}
	return conta;
}




int contaVogais (char s[]){
	int i=0, conta=0;
	for(i;s[i];i++){
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
			conta++;
	}
	return conta;
}





int contida (char a[], char b[]){
	int i=0, e, result;
	for(i;a[i];i++){
		for(e=0;b[e];e++){
			if(a[i]==b[e]) break; //caso encontre dá break e não pesquisa nos restantes chars da string b.
		}
		if(!b[e]) return 0;   //caso chegue ao fim de b e não encontre dá logo return 0.
	}
	return 1; //caso chegue aqui é porque não deu return 0 pelo que dá return 1.
}





int mystrlen (char s[]){
	int i=0;
	for(i;s[i];i++);
	return i;
}

int palindroma (char s[]){
	int i=0, len=(mystrlen(s)-1), l2=(mystrlen(s)/2);
	for(i,len; i<l2; i++,len--){
		if(s[i]!=s[len]) return 0;
	}
	return 1;
}





int remRep (char x[]){
	int i=0, d=0;
	char last='\0';
	for(i;x[i];i++){
		if(x[i]!=last){
			x[d]=x[i];
			d++;
		}
		last=x[i];
	}
	x[d]='\0';
	return d;
}







int limpaEspacos (char t[]){
	int i=0, d=0, isLastSpace=0;
	for(i; t[i]; i++){
		if(t[i]==' ' && isLastSpace)
			isLastSpace=1;
		else{
		    if(t[i]==' ') isLastSpace=1;
		    else isLastSpace=0;
			t[d]=t[i];
			d++;
		}
	}
	t[d]='\0';
	return d;
}

////////////////////// OU, muito mais simples:
int limpaEspacos(char t[]){
	int i=0,j=0;
	for(i;t[i];i++){
		if(isspace(t[i+1]) && isspace(t[i]));
		else{
			t[j]=t[i];
			j++;
		}
	}
	t[j]='\0';
	return j;
}




void insere (int v[], int N, int x){
	int i=N-1, j=N;
	for(i,j; v[i]>=x && j>0; i--,j--){  //j>0 !!!!
		v[j]=v[i];
	}
	v[j]=x;           //mete-se no j pq ele já foi decrementado
}







void merge (int r[], int a[], int b[], int na, int nb){
	int ai=0, bi=0, d=0;
	for(d;d<(na+nb);d++){		//na=10, nb=10, indices:0-19, daí o j<(20)
		if(ai==na){
			for(;bi<nb;bi++,d++){
				r[d]=b[bi];
			}
		}
		if(bi==nb){
			for(;ai<na;ai++,d++){ //não se pode meter a[ai] na condição pq isto é uma lista de ints (que não tem fim). Uma lista de chars(string, char s[]) tem fim e é terminada por '\0'
				r[d]=a[ai];
			}
		}
		if(a[ai]<b[bi]){
			r[d]=a[ai];
			ai++;
		}
		else{
			r[d]=b[bi];
			bi++;
		}
	}
}

/////////OU

void merge (int r[], int a[], int b[], int na, int nb){
	int ai=0, bi=0, d=0;
	while(d<(na+nb)){
		for(; ai==na && bi<nb; bi++, d++)
			r[d]=b[bi];
		for(; ai<na && bi==nb; ai++, d++)
			r[d]=a[ai];
		if(a[ai]<b[bi]){
			r[d]=a[ai];
			ai++;
			d++;
		}
		else{
			r[d]=b[bi];
			bi++;
			d++;
		}
	}
}





int crescente (int a[], int i, int j){
	for(i,j; i<j; i++){
		if(a[i]>a[i+1]) return 0;
	}
	return 1;
}


int retiraNeg(int v[], int N){
	int nNeg=0, i=0, d=0;
	for(;i<N;i++){
		if(v[i]>0){
			v[d]=v[i];
			nNeg++;
			d++;
		}
	}
	return nNeg;
}






int menosFreqAux (int v[], int N, int x){
	int i=0, conta=0;
	for(;i<N;i++){
		if(v[i]==x) conta++;
	}
	return conta;
}

int menosFreq (int v[], int N){
	int store, min=N+1, i=0;                 //min=N+1!!!!!!!
	for(;i<N;i++){
		if(menosFreqAux(v, N, v[i])<min){
			min=menosFreqAux(v, N, v[i]);
			store=v[i];
		}
	}
	return store;
}







int maisFreqAux (int v[], int N, int x){
	int i=0, conta=0;
	for(;i<N;i++){
		if(v[i]==x) conta++;
	}
	return conta;
}

int maisFreq (int v[], int N){
	int store, max=0, i=0;
	for(;i<N;i++){
		if(maisFreqAux(v, N, v[i])>max){
			max=maisFreqAux(v, N, v[i]);
			store=v[i];
		}
	}
	return store;
}






int maxCresc (int v[], int N){
	int i=0, conta=1, max=0;			//valor inicial de conta é 1.
	while(i<(N-1)){
		for(;v[i]<=v[i+1]; i++){        //pode ser sequencia com numeros crescentes ou iguais "<="
			conta++;
		}
		if(conta>max)
			max=conta;
		conta=1;
		i++;
	}
	return max;
}

//OU
int maxCresc(int v[], int N){
	int i, conta=1, maxConta=0;
	for(i=0;i<N;i++){
		if(v[i]<=v[i+1]) conta++;   //tbm pode ser igual: '<='.
		else conta=1;
		if(maxConta<conta) maxConta=conta;
	}
	return maxConta;
}






int isRepetido (int v[], int j){
	int i=0;
	for(; i<j; i++){
		if(v[i]==v[j]) return 1;
	}
	return 0;
}

int elimRep (int v[], int n){
	int i=0, d=0;
	for(; i<n; i++){
		if(!isRepetido(v, i)){
			v[d]=v[i];
			d++;
		}
	}
	return d;
}




//caso inicializasse com 0 e testasse com o elemento a seguir num array de inteiros com todos os valores iguais, ficava vazio.

int elimRepOrd (int v[], int n){
	int i=1, d=1;                 //i e d inicializados com o valor 1.
	for(; i<n; i++){
	if(v[i-1]!=v[i]){             //testar com o índice anterior
			v[d]=v[i];
			d++;
		}
	}
	v[d]=v[i];
	return d;
}





int comunsOrd (int a[], int na, int b[], int nb){                  ////////////////////////FAZER
	int ia=0, ib=0, r=0;
	for(;ia<na; ia++){
		a[ia-1]
		for(;ib<nb; ib++){

		}
	}
	else()
}

int comuns          											////////////////////////FAZER










int minInd (int v[], int n){
	int i=0, iMen=0, store=v[i];
	for( ; i<n; i++){
		if(v[i]<store){
			store = v[i];
			iMen = i;
		}
	}
	return iMen;
}


void somasAc (int v[], int Ac [], int N){
	int soma=0, i=0;
	for( ; i<N; i++){
		soma+=v[i];
		Ac[i]=soma;
	}
}

int triSup (int N, float m [N][N]){
	int v=0, h=0;
	for(; v<N; v++){
		for(h=0; h<v; h++){
			if(m [v][h]!=0) return 0;
		}
	}
	return 1;
}

void transposta (int N, float m [N][N]){
	int v=0, h=0, store;
	for(; v<N; v++){
		for(h=0; h<v && h<N; h++){       //iniciar h com 0.
			store=m [v][h];
			m [v][h]=m [h][v];
			m [h][v]=store;
		}
	}
}


void addTo (int N, int M, int a[N][M], int b[N][M]){
	int v=0, h=0;
	for(;v<N;v++){
		for(h=0;h<M;h++){
			a[v][h]=a[v][h]+b[v][h];
		}
	}
}