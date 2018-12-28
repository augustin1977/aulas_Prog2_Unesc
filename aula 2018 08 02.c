#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
float media_aluno;// variavel global do exercicio2
float raiz1 , raiz2;// variavel global do exercicio4
int soma( int x, int y) { // assinatura da sub-fun��o
// pre: Dois numeros inteiros
// p�s: soma dos numeros inteiros
	return(x+y); // corpo da fun��o
}
int produto( int x, int y) { // assinatura da sub-fun��o
// pre: Dois numeros inteiros
// p�s: produto dos numeros inteiros
	return(x*y); // corpo da fun��o
}
int subtracao( int x, int y) { // assinatura da sub-fun��o
// pre: Dois numeros inteiros
// p�s: Subtra��o dos numeros inteiros
	return(x-y); // corpo da fun��o
}
float divisao( int x, int y) { // assinatura da sub-fun��o
// pre: Dois numeros inteiros
// p�s: Divis�o dos numeros inteiros
	return((float) x/y); //corpo da fun��o com type_casting de inteiro para flutuante
}
int exercicio1 (){ //  assinatura da fun��o principal
	int a,b,s,s2,s3;
	float s4;
	scanf("%d",&a);
	scanf("%d",&b);
	s=soma(a,b);
	s2=produto(a,b);
	s3=subtracao(a,b);
	s4=divisao(a,b);
	printf("soma=%d\n",s);
	printf("produto=%d\n",s2);
	printf("subtra��o=%d\n",s3);
	printf("divis�o=%.2f\n",s4);
	return 0;
}
float media( int a, int b , int c){
// pre: Tr�s numeros inteiros
// p�s: media dos numeros inteiros entrados
	return(((float)a+b+c)/3);
}
void calcula_media(int a,int b,int c,char l){
// pre: Tr�s numeros inteiros e um char
// p�s: media dos numeros se char for A ponderada se Char for P ou harmonica se char for H
	if (l=='A'){
		media_aluno=(a+b+c)/3.0;
	}
	else if (l=='P'){
		media_aluno=(a*5+b*3+c*2)/10.0;
	}
	else if (l=='H'){
		media_aluno=pow(a*b*c,(1/3.0));
	}
	else {
		printf("Op��o %c n�o existe execute novamente e escolha entre A,P ou H!\n",l);
	}
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	//exercicio1();
	//exercicio2();
	//exercicio3();
	
}
