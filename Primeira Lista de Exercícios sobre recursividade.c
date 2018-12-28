#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
int fatorial(int n){
	int f;
	if (n==1) f=1;
	else f=(n*fatorial(n-1));
	return f;
}
int somatorio(int n){
	int s=0;
	if (n==1) s=1;
	else s=n+(somatorio(n-1));
	return s;
}
int fib(int n){
	int f;
	if (n==1){
		f=0;
	}
	else if (n==2){
		f=1;	
	}
	else {
		f=fib(n-1)+fib(n-2);
	}

	return f;
}

int mult(int n1,int n2){
	int s=0;
	
	if (n2==1) s=n1;
	else s=n1+mult(n1,n2-1);
	return s;
	
}
int fatquad(int n){
	return fatorial(2*n)/fatorial(n);
}
int exponencial(int n, int k){
	int p1=0;
	if (k==1) p1=n;
	else {
		p1=n*exponencial(n,k-1);
	}
	return p1;
}
int mdc(int x, int y){
	int resto;
	if (y==0) resto=x;
	else resto=mdc(y,x%y);
	return resto;
}
int contadigito(int x, int y){
	int cont=0,aux;
	aux=y%10;
	if (aux==0) cont=0;
	else {
		if (aux==x) cont++;
		cont=cont+contadigito(x,y/10);
	}
	return cont;
}
int imprimeinteirosc(int n){
	if (n==0) n=0;
	else {
		imprimeinteirosc(n-1);
	}
	printf("%d ",n);
	return (0);
}
int imprimeinteirosd(int n){
	printf("%d ",n);
	if (n==0) n=0;
	else {
		imprimeinteirosd(n-1);
	}

	return (0);
}
int imprimeparesc(int n){
	if (n==0) n=0;
	else imprimeparesc(n-2);
	printf("%d ",n);
	return (0);
}
int imprimeparesd(int n){
	printf("%d ",n);
	if (n==0) n=0;
	else imprimeparesd(n-2);
	return (0);
}

int fatduplo(int n){
	int res;
	if (n%2==0) res=fatduplo(n-1);
	else if (n==1) res=n;
	else res=n*fatduplo(n-2);
	return res;
}
int superfatorial(int n){
	int res;
	if (n==1) res=n;
	else res=fatorial(n)*superfatorial(n-1);
	return res;
}
int hiperfatorial(int n){
	int res;
	if (n==1) res=1;
	else res=exponencial(n,n)*hiperfatorial(n-1);
	return res;
}
int fatorialexpo( int n){
	int res;
	if (n==1) res=1;
	else res=exponencial(n,fatorialexpo(n-1));
	return res;
}
int tribonacci(int n){
	int res=0;
	if (n==0 ) res=0;
	else if (n==1) res=0;
	else if (n==2) res=1;
	else res=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
	return res;
}
int tetranacci(int n){
	int res=0;
	if (n==0 ) res=0;
	else if (n==1) res=0;
	else if (n==2) res=0;
	else if (n==3) res=1;
	else res=tetranacci(n-1)+tetranacci(n-2)+tetranacci(n-3)+tetranacci(n-4);
	return res;
}
int padovan(int n){
	int res=0;
	if (n==0 ) res=1;
	else if (n==1) res=1;
	else if (n==2) res=1;
	else res=padovan(n-2)+padovan(n-3);
	return res;
}
int pell(int n){
	int res=0;
	if (n==0 ) res=0;
	else if (n==1) res=1;
	else res=2*pell(n-1)+pell(n-2);
	return res;
}
int catalan(int n){
	int res=0;
	if (n==0) res=1;
	else res=(float)(4*n-2)/(n+1)*catalan(n-1);
	return res;
}
char fibo(int n ){
	char palavra;
	if (n=0) palavra='b';
	else if (n=1) palavra ='a';
	else palavra=fibo(n-1)+fibo(n-2);
	return palavra;
}
int funch(int m, int n){
	int ret=0,t;
	printf("%d %d %d\n",ret,m,n);
	//scanf("%d",&t);
	if (n==1) ret=m+1;
	else if (m==1) ret=n+1;
	else ret=funch(m,n-1)+funch(m-1,n);
	return ret;
}
int a(int m, int n){
	int ret;
	if (m==1) ret=n+1;
	else if (n==0) ret=a(m-1,n);
	else ret=a(m-1,a(m,n-1));
	return ret;
}
int somaserie(int i, int f, int k){
	int s=0;
	if (i==f) s=i;
	else if (i>f) s=0;
	else s=i+somaserie(i+k,f,k);
	return s;
}
float s(int n){
	float soma=0;
	if (n==0) soma=0;
	else soma=(float)(1+n*n)/n+s(n-1);
	return soma;
}
int menorv(int vetor[],int n){
	int m;
	if (n==0) m=n;
	else {
		m=menorv(vetor,n-1);
		if (vetor[n]<vetor[m]) m=n;	
	}
	return m;
}
int menor(int vetor[],int n){
	int m;
	if (n==0) m=vetor[n];
	else {
		m=menor(vetor,n-1);
		if (vetor[n]<m) m=vetor[n];	
	}
	return m;
}
int imprimeserie(int i, int f, int k){
	
	if (i<=f) {
		printf("%d ",i);
		imprimeserie(i+k,f,k);	
	}
}
void converte_dec_bin(int n,char bin[]){
	int ret;
	if (n==0) ret=2;
	else {
		converte_dec_bin(n/2,bin);
		ret=n%2;		
	}
	if (ret==0) strcat(bin,"0");
	else if (ret==1) strcat(bin,"1");
}
void dec_bin(){
	int n=15;
	char bin[1000];
	strcpy(bin,"");
	converte_dec_bin(n,bin);
	printf("O numero %d(10) = %s(2)",n,bin);
}
int exe40(int n){
	int cont;
	if (n==1) cont=1;
	else if (n==2) cont=2;
	else cont=2*exe40(n-1)+3*exe40(n-2);
	return cont;
	
}
 int fibg(int f0, int f1, int n){
 	int cont=0;
 	if (n==1) cont=f0;
 	else if (n==2) cont=f1;
 	else cont=fibg(f0,f1,n-2)+fibg(f0,f1,n-1);
 	return cont;
 }
 int exp3(int n){
 	int soma=0;
 	if (n==0) soma=0;
 	else soma=n*n*n+exp3(n-1);
 	return soma;
 }
 float media_vetor(int n, int vetor[]){
 	float media;
 	if (n==0) media=vetor[0];
 	else {
 		media=(vetor[n]+(media_vetor(n-1,vetor)*(n))/(n+1));
 		printf("%f %d\n",media,n);
	 }
 	media=media;
 	return media;
 }
int main(){
	setlocale(LC_ALL, "Portuguese");
	int vetor[20]={9,3,5,7,2,6,4,10,8,9,10},n=11;
	//printf("%d\n",fatorial(16)); // exercicio1 da lista de recursividade
    //printf ("fibonacci %d\n", fib(20));// exercicio 2 da lista de recursividade
	//printf("%d\n",somatorio(10)); // exercicio 5 da lista de recursividade
	//printf("%d\n",exponencial(2,3)); // exercicio 6 da lista de recursividade
	//printf("%d\n",mdc(3600,5040)); // exercicio 8 da lista de recursividade
	//printf("%d\n",somatorio(10)); // exercicio 9 da lista de recursividade
	//printf("%d\n",contadigito(2,12222123)); // exercicio 10 da lista de recursividade
	//printf("%d\n",mult(5,100)); // exercicio 11 da lista de recursividade
	//imprimeinteirosc(20);// exercicio 12 da lista de recursividade
	//imprimeinteirosd(20);// exercicio 13 da lista de recursividade
	//imprimeparesc(20);// exercicio 14 da lista de recursividade
	//imprimeparesd(20);// exercicio 15 da lista de recursividade
	//printf("Fatoria duplo = %d\n",fatduplo(17)); // exercicio 16 da lista de recursividade
	//printf("%d\n",fatquad(3)); // exercicio 17 da lista de recursividade
	//printf("%d\n",superfatorial(4)); // exercicio 18 da lista de recursividade
	//printf("%d\n",hiperfatorial(3)); // exercicio 19 da lista de recursividade
	//printf("%d\n",fatorialexpo(4)); // exercicio 20 da lista de recursividade
	//printf("\n%d\n",tribonacci(5)); // exercicio 21 da lista de recursividade
	//printf("\n%d\n",tetranacci(11)); // exercicio 22 da lista de recursividade
	//printf("\n%d\n",padovan(11)); // exercicio 23 da lista de recursividade
	//printf("\n%d\n",pell(7)); // exercicio 24 da lista de recursividade
	//printf("\n%i\n",catalan(8)); // exercicio 25 da lista de recursividade
	// não funcionou !!! printf("\n%s\n",fibo(3)); // exercicio 26 da lista de recursividade - pedir para fazer...
	//printf("\n%i\n",funch(2,7)); // exercicio 29 da lista de recursividade
	//printf("\n%i\n",a(2,2)); // exercicio 30 da lista de recursividade
	//printf("\n%i\n",somaserie(0,10,5));// exercicio 31 da lista de recursividade - pedir para fazer...
	//printf("\n%.2f\n",s(9000));// exercicio 32 da lista de recursividade
	//printf("\n%d\n",vetor[menorv(vetor,10)]);// exercicio 33 da lista de recursividade versão 1 com retorno da posição no vetor
	//printf("\n%d\n",menor(vetor,10));// exercicio 33 da lista de recursividade versão 2 com retorno dao menor valor
	//imprimeserie(2,11,2);// exercicio 34 da lista de recursividade 
	//dec_bin();// exercicio 35 da lista de recursividade
	//printf("\n%d\n",exe40(3));// exercicio 40 da lista de recursividade
	//printf("fibonacci geral %d\n",fibg(0,1,10));// exercicio 43 da lista de recursividade
	//printf("%d\n",exp3(10));// exercicio 44 da lista de recursividade
	printf("Media do vetor de N de tamanho %d é %f",n,media_vetor(n,vetor));
	return 0;
}

