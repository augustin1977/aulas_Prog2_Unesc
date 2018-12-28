#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
#define QTDLETRAS 150
#define QTDLINHAS 100

void teste_com_scanf(){
	char nome[50];
	printf("Teste com scanf\n");
	scanf("%s",&nome);
	printf("%s",nome);

}
void teste_com_gets(){
	char nome[50];
	printf("Teste com gets\n");
	gets(nome);
	printf("%s",nome);

}
void imprimindo_invetido(){
	char nome[50];
	int i,max;
	printf("Imprimindo invertido\n");
	gets(nome);
	max=strlen(nome)-1;
	for (i=max;i>=0;i--){
		printf("%c",nome[i]);
	}
	printf("\n");
	printf("%s",nome);
}
int criptografa(int t, char nome[t], char cod[t]){
	int max=t,n,i;
	n=max/2;
	for (i=0;i<n;i++){
		cod[2*i]=nome[i];
		cod[2*i+1]=nome[max-1-i];
	}
	if (max%2!=0){
		cod[max-1]=nome[n];
	}
	cod[max]=nome[max];
	return 0;
}
int descriptografa(int t, char nome[t], char cod[t]){
	int max=t,n,i;
	n=max/2;
	for (i=0;i<n;i++){
		cod[i]=nome[2*i];
		cod[max-1-i]=nome[2*i+1];
	}
	if (max%2!=0){
		cod[n]=nome[max-1];
	}
	cod[max]=nome[max];
	return 0;
}
void criptografia(){
	char nome[151],cod[151];
	int i,j,max;
	printf("Imprimindo criptografado\n");
	gets(nome);
	max=strlen(nome);
	criptografa(max,nome,cod);

	printf("Criptografado \n%s\n",cod);			
}

void descriptografia(){
	char nome[151],cod[151];
	int i,j,max;
	printf("Imprimindo descriptografado\n");
	gets(nome);
	max=strlen(nome);
	descriptografa(max,nome,cod);
	
	printf("Descriptografado \n%s\n",cod);			
}
void matriz_de_char(){
	char nomes[QTDLINHAS][QTDLETRAS];
	int i;
	for (i=0;i<3;i++){
		gets(nomes[i]);
	}
	for (i=0;i<3;i++){
		printf("%s\n",nomes[i]);
	}
}

int analise_de_notas(){
	int alunos=10000,cont=0,soma=0,i,a[QTDLINHAS];
	char nomes[QTDLINHAS][QTDLETRAS];
	float media;
	while(alunos>QTDLINHAS){
		printf("Quantos alunos deseja inserir a nota? :\n");
		scanf("%d",&alunos);
	}
	fflush(stdin);
	for (i=0;i<alunos;i++){
		printf("Digite o nome do aluno:\n");
		gets(nomes[i]);
		fflush(stdin);
		printf("Digite a nota do aluno:\n");
		scanf(" %d",&a[i]);
		fflush(stdin);
	}
	for (i=0;i<alunos;i++){
		soma=soma+a[i];
	}
	media=(float)soma/alunos;
	for (i=0;i<alunos;i++){
		if (a[i]>media){
			printf("O aluno %s tirou nota %i que é acima da média %2f\n",nomes[i],a[i],media);
		}
	}
	return 0;
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	//teste_com_scanf();
	//teste_com_gets();
	//imprimindo_invetido();
	criptografia();
	descriptografia();
	//matriz_de_char();
	//analise_de_notas();
	return 0;
}

