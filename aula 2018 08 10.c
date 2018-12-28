#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#define MAX 4
int n1,n2,n3;
int tempo(int anos, int meses, int dias){
// pre: quantidade de anos, meses e dias de vida
// quantidade de horas de vida
	int horas;
	horas= (dias+meses*30+anos*365)*24;
	return horas;
}
int exercicio1(){
	int anos,meses,dias;
	printf("Calculadora de idade:\n");
	printf("Digite o numero de anos de vida: ");
	scanf("%d",&anos);
	printf("Digite o numero de meses de vida: ");
	scanf("%d",&meses);
	printf("Digite o numero de dias de vida: ");
	scanf("%d",&dias);
	printf("0A idade em horas é %d", tempo(anos,meses,dias));
}


void ordena2(int a, int b, int c) {
	int temp;
	if (a>b){
		temp=b;
		b=a;
		a=temp;
	}
	if ((a>c)){
		temp=c;
		c=a;
		a=temp;	
	}
	if (b>c){
		temp=c;
		c=b;
		b=temp;		
	}
	n1=a;
	n2=b;
	n3=c;
}
int exercicio13_lista(){
	printf("Entre com 3 numeros que vou ordena-los:\n");
	scanf("%d",&n1);
	scanf("%d",&n2);
	scanf("%d",&n3);	
	ordena2(n1,n2,n3);
	printf("a ordem crescente é :%d %d %d",n1,n2,n3);	
	return 0;
}
void taboada(int n){
// pre: recebe um inteiro e imprime sua taboada
// pós: não retorna valor.
	int i;
	for (i=1;i<=10;i++){
		printf("%2d x %d = %d\n",i,n,i*n);
	}
}
int exercicio20_lista(){
	int n;
	printf("Digite o numero o qual quer ver a taboada:\n");
	scanf("%d",&n);
	taboada(n);
	return 0;	
}
int exemplo_vetor1(){
	int i,a[3];
	for (i=0;i<3;i++){
		scanf("%d",&a[i]);
	}
	for (i=0;i<3;i++){
		printf("%d\n",a[i]);
	}
	printf("Tamanho do vetor %d",sizeof(a)/sizeof(int));
	return 0;
}
int exercicio_vetor1(){
	int cont=0,soma=0,i,a[MAX];
	float media;
	for (i=0;i<MAX;i++){
		scanf("%d",&a[i]);
	}
	for (i=0;i<MAX;i++){
		soma=soma+a[i];
	}
	media=(float)soma/MAX;
	for (i=0;i<MAX;i++){
		if (a[i]>media) cont++;
	}
	printf("média dos valores digitados é %.2f.\n",media );
	printf("O vetors possui %d valores acima da média.\n",cont);
	return 0;
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	//exercicio1();
	//exercicio13_lista();
	//exercicio20_lista();
	//exemplo_vetor1();
	exercicio_vetor1();
}
