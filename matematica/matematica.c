#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#define INC 5
int sortear_numero(int max){
	int n;
	n=1+rand()%max;
	return n;
}
int grava_arquivo(int a, int b, int n,int acerto, int r){
	FILE *fa;
	if (!(fa=fopen("matematica.csv","r"))){
		if (!(fa=fopen("matematica.csv","a"))){
			printf("Erro na abertura do arquivo");
			r=-1;	
		} else{
			fa=fopen("matematica.csv","a");
			fprintf(fa,"A ; B ; Soma ; Acerto\n");
			fprintf(fa,"%d ; %d ; %d ; %d\n",a,b,n,acerto);
			fclose(fa);
		}	
	} else {
		fa=fopen("matematica.csv","a");
		fprintf(fa,"%d ; %d ; %d ; %d\n",a,b,n,acerto);
		fclose(fa);
	}
	return r;
}
int pergunta(int a, int b, int r,int fase){
	int o,n,acerto;
	printf("RESPONDA A CONTA:\n%d + %d = ?\n",a,b);
	printf("DIGITE A RESPOSTA: ");
	scanf("%d",&n);
	if (a+b==n){
		printf("VOCÊ ACERTOU!!!\n");
		r+=fase;
		acerto=1;
	} else {
		printf("VOCÊ ERROU !!!\n");
		printf("QUER CONTINUAR? (1=SIM / 0=NÃO)\n");
		scanf("%d",&o);
		if (o==1) r=0;
		else r=-1;
		acerto=0;
	}
	r=grava_arquivo(a,b,n,acerto,r);
	return r;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	srand( (unsigned)time(NULL) );
	int i,a,b,fase,max,pontos=0, nivel;
	while(pontos>=0){
	if(pontos==0) {
		nivel=0;
		fase=0;	
	}
	system("cls");
	if (nivel%INC==0) fase++;
	max=fase*INC;
	printf("FASE: %d  PONTOS: %d\n",fase,pontos);
	a=sortear_numero(max);
	b=sortear_numero(max);
	pontos=pergunta(a,b,pontos,fase);	
	nivel++;
	}
	return 0;
}

