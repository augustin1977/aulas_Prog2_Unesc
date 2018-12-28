#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
int main(){
	setlocale(LC_ALL, "Portuguese");
	typedef struct ficha{
		char nome[50];
		int idade;
		float altura;
	} ficha;
	
	ficha f[100];
	gets(f[0].nome);
	scanf("%d",&f[0].idade);
	scanf("%f",&f[0].altura);
	printf("%s %i %f",f[0].nome,f[0].idade,f[0].altura);
	f[1]=f[0];
	printf("%s %i %f",f[1].nome,f[1].idade,f[1].altura);
	return 0;
}

