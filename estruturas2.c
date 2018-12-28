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
	int i=0,n;
	FILE *arq;
	ficha f[100];
	if (!(arq=fopen("clientes.txt","r"))){
		printf("Erro no arquivo");
	}
	else{
		arq=fopen("clientes.txt","r");
		while(!feof(arq)){
			fscanf(arq,"%s",f[i].nome);
			fscanf(arq,"%d",&f[i].idade);
			fscanf(arq,"%f",&f[i].altura);
			n=i;
			i++;
		}
		for (i=0;i<n;i++){
		printf("%s %i %f\n",f[i].nome,f[i].idade,f[i].altura);	
		}
	}
	return 0;
}

