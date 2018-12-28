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
int main(){
	setlocale(LC_ALL, "Portuguese");
	//printf("%d\n",fatorial(16)); // exercicio1 da lista de recursividade
    //printf ("%d", fib(10));// exercicio1 da lista de recursividade
	//printf("%d\n",somatorio(10)); // exercicio5 da lista de recursividade
	//printf("%d\n",mult(5,100)); // exercicio11 da lista de recursividade
	
	printf("5!=%d 10!=%d\n", fatorial(3),fatorial(6));
	printf("%d\n",fatquad(3)); // exercicio17 da lista de recursividade
	return 0;
}

