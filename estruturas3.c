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
		float peso;
		float imc;
	} ficha;
	int i=0,n,opcao;
	FILE *arq;
	ficha f[100];
	if (!(arq=fopen("clientes2.txt","a"))){
		printf("Erro no arquivo");
	}
	else{
		opcao=1;
		arq=fopen("clientes2.txt","a");
		while(opcao==1){
			printf("Nome:\n");
			scanf("%s",f[i].nome);
			printf("Idade:\n");
			scanf("%d",&f[i].idade);
			printf("Altura:\n");
			scanf("%f",&f[i].altura);
			printf("Peso:\n");
			scanf("%f",&f[i].peso);
			f[i].imc=1;
			f[i].imc=f[i].peso/(f[i].altura * f[i].altura);
			printf("Continuar (1=sim/2=não):\n");
			scanf("%d",&opcao);
			i++;
		}
		n=i;
		for (i=0;i<n;i++){
		fprintf(arq,"%s;%i;%f;%f;%f\n",f[i].nome,f[i].idade,f[i].altura,f[i].peso, f[i].imc);	
		}
	}
	return 0;
}

