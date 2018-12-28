#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

void estruturas1(){
	typedef struct minha_ficha{
		char nome[50];
		int matricula;
		float nota[3];
	}ficha;
	ficha f;
	printf("Digite o nome\n");
	gets(f.nome);
	printf("Digite a matricula\n");
	scanf("%d",&f.matricula);
	printf("Digite primeira nota\n");
	scanf("%f",&f.nota[0]);
	printf("Digite segunda nota\n");
	scanf("%f",&f.nota[1]);
	printf("Digite terceira nota\n");
	scanf("%f",&f.nota[2]);
	printf("%s %i %.2f %.2f %.2f",f.nome,f.matricula,f.nota[0],f.nota[1],f.nota[2]);
}
void estruturas2(){
	typedef struct minha_ficha{
		char nome[50];
		int matricula;
	}ficha;
	ficha f[3];
	printf("Digite o primeiro nome\n");
	gets(f[0].nome);
	printf("Digite a matricula\n");
	scanf("%d",&f[0].matricula);
	fflush(stdin);
	//------------
	printf("Digite o segundo nome\n");
	gets(f[1].nome);
	printf("Digite a matricula\n");
	scanf("%d",&f[1].matricula);
	fflush(stdin);
	//------------
	printf("Digite o terceiro nome\n");
	gets(f[2].nome);
	printf("Digite a matricula\n");
	scanf("%d",&f[2].matricula);
	//------------
	printf("%s %i \n",f[0].nome,f[0].matricula);
	printf("%s %i \n",f[1].nome,f[1].matricula);
	printf("%s %i \n",f[2].nome,f[2].matricula);
}
void estruturas3(){
	typedef struct minha_ficha{
		char nome[50];
		int matricula;
		float nota[3];
	}ficha;
	ficha f[3];
	printf("Digite o nome\n");
	gets(f[0].nome);
	printf("Digite a matricula\n");
	scanf("%d",&f[0].matricula);
	printf("Digite primeira nota\n");
	scanf("%f",&f[0].nota[0]);
	printf("Digite segunda nota\n");
	scanf("%f",&f[0].nota[1]);
	printf("Digite terceira nota\n");
	scanf("%f",&f[0].nota[2]);
	printf("%s %i %.2f %.2f %.2f",f[0].nome,f[0].matricula,f[0].nota[0],f[0].nota[1],f[0].nota[2]);
}
void exercicio_sala(){
	typedef struct ficha_alunos{
		char nome[50];
		int mat;
		float nota[3];
	} ficha;
	FILE *arq;
	ficha f[3];
	int i,j;
	arq=fopen("dados_alunos.txt","r");
	for (i=0;i<3;i++){
		fscanf(arq,"%s",&f[i].nome);
		fscanf(arq,"%i",&f[i].mat);
		for (j=0;j<3;j++){
			fscanf(arq,"%f",&f[i].nota[j]);
		}	
	}
	printf("Nome         Matr. Nota1 Nota2 Nota3 Média\n");
	for (i=0;i<3;i++){
		printf("%-10s ",f[i].nome);
		printf("%6d  ",f[i].mat);
		for (j=0;j<3;j++){
			printf("%2.2f  ",f[i].nota[j]);
		}
		printf("%2.2f\n",(f[i].nota[0]+f[i].nota[1]+f[i].nota[2])/3);
	}
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	//estruturas1();
	//estruturas2();
	//estruturas3();
	//exercicio_sala();
	return 0;

}



