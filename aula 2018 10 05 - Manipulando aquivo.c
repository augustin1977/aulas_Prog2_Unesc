#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
void calculo_media(){
	FILE *arq;
	int nota,maior,i=0;
	float media=0.0;
	double media2=0.0;
	arq=fopen("dadosleo.txt","r");

	while(!feof(arq)){
		fscanf(arq,"%i",&nota);
		media=media+nota;
		media2=media2+nota;
		i++;
		} 

	media=media/i;
	media2=media2/i;
	printf("float %.5f double%.5f \n",media,media2);
}


void acha_maior(){
	FILE *arq;
	int nota,maior;
	arq=fopen("dadosleo.txt","r");
	fscanf(arq,"%d",&nota);
	maior=nota;
	while(!feof(arq)){
		fscanf(arq,"%d",&nota);
		if (nota>maior){
			maior=nota;
		} 
	}
	printf("%d\n",maior);
}

int conta_linhas(char nome[100]){
	FILE *arq;
	int i=0;
	float a;
	if (!(arq=fopen(nome,"r"))){
		printf ("Erro ao abrir arquivo!");
		i=-1;
	}
	
	else {
		arq=fopen(nome,"r");
		while(!feof(arq)){
			fscanf(arq,"%f",&a);
			i++;
		}
		fclose(arq);
	}	
	return i;
}
void coloca_vetor(int n, float vetor[n], char nome[100]){
	FILE *arq;
	int i=0,m=0;
	float media=0.0;
	if (!(arq=fopen(nome,"r"))){
		printf ("Erro ao abrir arquivo!");
	}
	
	else {
		arq=fopen(nome,"r");
		for (i=0;i<n;i++){
			fscanf(arq,"%f",&vetor[i]);
			media=media+vetor[i];
			}
		fclose(arq);
		media=media/n;
		for (i=0;i<n;i++){
			if (vetor[i]>media) m++;
		}
		printf("A media foi %.2f e %d notas acima da média!", media, m);	
	}
}		

int main(){
	int i=0;
	float v[1000];
	//setlocale(LC_ALL, "Portuguese");
	//acha_maior();
	//calculo_media();
	i=conta_linhas("notas.txt");
	if (i>=0) printf("Possui %d linhas\n",i);
	coloca_vetor(i,v,"notas.txt");
	return 0;
}

