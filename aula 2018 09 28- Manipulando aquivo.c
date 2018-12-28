#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
void texto(){
	FILE *arq;
	arq=fopen("dados.txt","w");
	char nome[20];
	int idade;
	gets(nome);
	scanf("%d",&idade);
	fprintf(arq,"%s\n",nome);
	fprintf(arq,"%i\n",idade);
}
void agenda(){
	FILE *arq;
	arq=fopen("dados.csv","a");
	char nome[50], tel[20];
	int idade;
	printf("Digite o nome:\n");
	gets(nome);
	fflush(stdin);
	printf("Digite a idade:\n");
	scanf("%d",&idade);
	fflush(stdin);
	printf("Digite o telefone:\n");
	gets(tel);
	fprintf(arq,"%s;%s;%2d\n",nome,tel,idade);

}
void cria_vetor(int v[],int n){
	int i;
	for (i=0; i<n; i++){
		v[i]=rand()%10;
	}
}


void numeros(int v[],int n){
	FILE *arq;
	int i;
	arq=fopen("numeros.txt","w");
	for (i=0;i<n;i++){
		fprintf(arq,"%d , %d\n",i,v[i]);
	}
	
}
void le_arq(){
	FILE *arq, *arq2;
	int n,i=0,j,col=10;
	int a[2000],b[2000];
	arq=fopen("numeros.txt","r");
	arq2=fopen("numeros2.txt","w");
	n=fscanf(arq,"%i , %i",&a[i],&b[i]);
	while(n!=EOF){
		printf("%3i | %i\t",a[i],b[i]);
		i++;
		n=fscanf(arq,"%i , %i",&a[i],&b[i]);
	}
	j=i;
	for (i=0;i<j;i++){
		if (i%col==col-1) fprintf(arq2,"%03i,%02i\n",a[i],b[i]);
		else fprintf(arq2,"%03i,%02i,",a[i],b[i]);
	}
}
void cria_fib(double v[],int n){
	int i;
	for (i=0; i<n; i++){
		if (i<2) v[i]=1;
		else v[i]=v[i-1]+v[i-2];	
	}
}

void grava_fib_arq(){
	FILE *arq;
	arq=fopen("fib.csv","w");
	int n=1000,i;
	double v[n],a;
	cria_fib(v,n);
	fprintf(arq,"numero;fibonacci;Fib+1;fib+1-1\n");
	for (i=0;i<n;i++){
		a=v[i]+1;
		fprintf(arq,"%d;%f;%f;%f\n",i,v[i],a,a-v[i]);
	}
	
}

void calculoe(){
	FILE *arq;
	arq=fopen("e.csv","w");
	int n=1000,i=1;
	double e=1,a,b,erro=1;
	fprintf(arq,"n;e;\n");
	while(erro>0.000000001){
		b=1+(1.0/i);
		//printf("%f %d\n",b,i);
		a=e;
		e=pow(b,i);
		erro=pow((e-a)*(e-a),0.5);
		//printf("%d;%f;%f\n",i,e,erro);
		fprintf(arq,"%06d;%.15f\n",i,e);
		i++;
	}
	printf("%6d;%.15f;%f.15\n",i,e,erro);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	//int n=1000,v[n];
	//cria_vetor(v,n);
	//numeros(v,n);
	//le_arq();
	//texto();
	//grava_fib_arq();
	//calculoe();
	agenda();
	return 0;
}

