#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"
#include <locale.h>

float media_aluno;// variavel global do exercicio2
int n1,n2,n3;

int exercicio1(){
	float r,vol;
	printf("Digite o raio da Esfera: ");
	scanf("%f",&r);
	vol=volume_esfera(r);
	printf("O volume da esfera é %.2f\n",vol);
	return (0);

}
void calcula_media(int a,int b,int c,char l){
// pre: Três numeros inteiros e um char
// pós: media dos numeros se char for A ponderada se Char for P ou harmonica se char for H
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
		printf("Opção %c não existe execute novamente e escolha entre A,P ou H!\n",l);
	}
}

int exercicio2(){
	int a,b,c;
	char l;
	printf("Digite a letra:\n");
	scanf("%c",&l);
	printf("Digite a 1 nota:\n");
	scanf("%d",&a);
	printf("Digite a 2 nota:\n");
	scanf("%d",&b);
	printf("Digite a 3 nota:\n");
	scanf("%d",&c);
	calcula_media(a,b,c,l);
	printf("\nMédia=%.2f\n",media_aluno);
	return 0;
}
int exercicio3(){
	int a,primo;
	printf("Digite um numero inteiro positivo:\n");
	scanf("%d",&a);
	primo=verifica_primo(a);
	if (primo==1){
		printf("Numero Primo!");
	}
	else{
		printf("Numero não primo!");
	}
	return 0;
}

int exercicio4(){
	float a,b,c;
	float r1,r2,delta;
	printf("Digite os coeficientes a,b,c da formula ax2+bx+c:\n");
	printf("Digite a: ");
	scanf("%f",&a);
	printf("Digite b: ");
	scanf("%f",&b);
	printf("Digite c: ");
	scanf("%f",&c);
	baskara(a,b,c,&delta,&r1,&r2);
	if (delta>0){
		printf("As raizes são: %.4f e %.4f ",r1,r2);
	} else if (delta==0){
		printf("A função possui apenas a raiz %.4f ",r1);
	}else {
		printf("a função não possui raizes");
	}
	return 0;
}

int exercicio5(){
	int h,m,s;
	printf("Entre com o numero de horas: ");
	scanf("%d",&h);
	printf("Entre com o numero de minutos: ");
	scanf("%d",&m);
	printf("Entre com o numero de segundos: ");
	scanf("%d",&s);
	segundos_para_horas(&h,&m,&s);
	printf("resultado %d %d %d",h,m,s);
	return 0;
}

int exercicio6(){

	int a,m,d,dias;
	printf("Entre com o numero de anos: ");
	scanf("%d",&a);
	printf("Entre com o numero de meses: ");
	scanf("%d",&m);
	printf("Entre com o numero de dias: ");
	scanf("%d",&d);
	dias=anos_para_dias(a,m,d);
	printf("resultado %d dias",dias);
	return 0;
}

int exercicio7(){
	int p,n;
	printf("Digite o numero que quer testar:");
	scanf("%d",&n);
	p=perfeito(n);
	if (p==1) {
	printf("O numero %d é perfeito!",n);
	}
	else{
	printf("O numero %d não é perfeito!",n);	
	}
	return 0;
}

int exercicio8(){
	int idade;
	char *ret;
	printf("Digite a idade que deseja classificar:");
	scanf("%d",&idade);
	ret=categoria(idade);
	if (idade>=5) {
		printf("A idade %d corresponde a categoria %s",idade,ret);	
		}
	else {
		printf("%s",ret);
	}
	return 0;
}
int exercicio9(){
	int n,res;
	printf("Entre com o numero: ");
	scanf("%d",&n);
	res=positivo(n);
	if (res==1){
		printf("O numero %d é positivo",n);
	} else{
		printf("O numero %d é negativo",n);
	}
	
}

int exercicio10(){
    int i;
    printf("Digite um numero para verificar se é par:\n");
    scanf("%d",&i);
    if (par(i)==1) {
        printf("%d é um numero Par",i);
    }
    else {
        printf("%d é um numero Impar",i);
    }
    return 0;
}

int exercicio11(){
	float n;
	char res;
	printf("Digite a nota que deseja transformar em conceito:");
	scanf("%f",&n);
	res=conceito_nota(n);
	if (res!='E') {
		printf("A nota %.2f corresponde ao conceito %c",n,res);	
		}
	else {
		printf("Erro na digitação da nota!");
	}
	return 0;
}

int exercicio12(){
	float peso,h;
	char sexo;
	printf("Digite o sexo: (M/F)");
	scanf("%c",&sexo);
	printf("Digite a altura: ");
	scanf("%f",&h);
	peso=peso_ideal(sexo,h);
	printf("O peso ideal é %.2f\n",peso);
	return (0);
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

int exercicio13(){
	printf("Entre com 3 numeros que vou ordena-los:\n");
	scanf("%d",&n1);
	scanf("%d",&n2);
	scanf("%d",&n3);	
	ordena2(n1,n2,n3);
	printf("a ordem crescente é :%d %d %d",n1,n2,n3);	
	return 0;
}
int exercicio13_vetor(){
	int n,vetor[20],nentradas=3;
	printf("Entre com %d numeros que vou ordena-los:\n",nentradas);
	for(n=0;n<nentradas;n++){
		printf("N=%d: ",n);
		scanf("%d",&vetor[n]);
	}	
	ordena(vetor,nentradas);
	for(n=0;n<nentradas;n++){
		printf("%d ",vetor[n]);
	}
	return 0;
}

int exercicio15(){
	int valido;
	float a,b,c;
	printf("Entre com 3 lados de um triangulo:\n");
	printf("Entra com o primeiro lado:");
	scanf("%f",&a);
	printf("Entra com o segundo lado:");
	scanf("%f",&b);
	printf("Entra com o terceiro lado:");
	scanf("%f",&c);	
	valido=tipo_triangulo(a,b,c);
	if (valido==1){
		printf("Tringulo equilátero!\n");
	}else if (valido==2){
		printf("Tringulo isóceles!\n");
	}else if (valido==3){
		printf("Tringulo escaleno!\n");
	}else{
		printf("Não é um tringulo!\n");
	}
	return 0;
	
}

int exercicio16(){
	float salario=0, salario_medio=0, n_medio_filhos=0;
	int n=0,nfilhos=0,n_salarios_acima=0,opcao;
	printf("Programa para calcular media salario e do numero de filhos.\nDigite 0 para sair ou 1 para entrar com dados:\n");
	scanf("%d",&opcao);
	if (opcao==0) n=1;
	while(opcao==1){
		salario=recebesalario();
		nfilhos=recebefilhos();
		printf("Deseja entrar com outros dados (0-não/1-Sim)");
		scanf("%d",&opcao);
		salario_medio=salario_medio+salario;
		n_medio_filhos=n_medio_filhos+nfilhos;
		n++;
		if (salario>350){
			n_salarios_acima++;
		}
	}
	salario_medio=salario_medio/(n);
	n_medio_filhos=n_medio_filhos/(n);
	printf("O salario médio é de R$%.2f\nO numero médio de filhos é %.2f\nOnumero de salarios acima de R$350,00 é %d",salario_medio,n_medio_filhos,n_salarios_acima);
	return 0;
}

int exercicio17(){
	printf("Programa de calculo de média");
	printf("%d",calcula_media_valores());
	return 0;
	
}

int exercicio18(){
	int n;
	long long res;
	printf("Programa para calculo do fatoriar.\n");
	printf("Digite um numero inteiro positivo: ");
	scanf("%d",&n);
	res=fatorial(n);
	printf("O fatorial de %d é %ld",n,res);
	return 0;
}

int exercicio19(){
	int vetor[2];
	maior_menor(vetor,50);
	printf("maior=%d menor=%d",vetor[0],vetor[1]);
	return 0;
}

int exercicio20(){
	int n;
	printf("Digite o numero o qual quer ver a taboada:\n");
	scanf("%d",&n);
	taboada(n);
	return 0;	
}

int exercicio21(){
	int i,vetor[100],n;
	printf("Digite o numero o qual quer saber o divisores:\n");
	scanf("%d",&n);
	divisores(n,vetor);
	printf("Os multiplos de %d são: ",n);
	for (i=1;i<=vetor[0];i++){
		if (i<vetor[0]) printf("%d, ",vetor[i]); else printf("%d. ",vetor[i]);
	}
	return 0;
}


int exercicio22(){
	int sum,n;
	printf("Digite um numero que quer obter o somatorio: \n");
	scanf("%d",&n);
	sum=somatorio(n);
	printf("O somatório é %d",sum);
}

int exercicio23(){
	int n;
	float s;
	printf("Digite um inteiro:");
	scanf("%d",&n);
	s=calcula_s(n);
	printf("O resultado da equação é %f",s);
	return 0;
	
}


int exercicio24(){
	long long n;
	float s;
	printf("Digite um inteiro:");
	scanf("%d",&n);
	s=calcula_s_fatorial(n);
	printf("O resultado da equação é %f",s);
	return 0;
	
}

int exercicio25(){
	int n;
	float s;
	printf("Digite um inteiro:");
	scanf("%d",&n);
	s=calcula_somatorio_quadatico(n);
	printf("O resultado da equação é %f",s);
	return 0;
}

float cosseno(float n){
	int i;
	float res=0;
	for (i=0;i<14;i++){
		if (i%2==0) res=res+(pow(n,2*i))/fatorial(2*i);
		else res=res-(pow(n,2*i))/fatorial(2*i);
		//printf("%f ",res);
	}
	return res;
}
int exercicio26(){
	float n=0,res;
	printf("Vamos calcular o cosseno(X)?\nEntre com o Valor de X em graus: ");
	scanf("%f",&n);
	res=cosseno(n/180*M_PI);
	printf("O cosseno de %.2f é %.6f",n,res);
	return 0;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	//exercicio1();
	//exercicio2();
	//exercicio3();
	//exercicio4();
	//exercicio5();
	//exercicio6();
	//exercicio7();
	//exercicio8();
	//exercicio9();
	//exercicio10();
	//exercicio11();
	//exercicio12();
	//exercicio13_vetor();
	//exercicio13();
	//exercicio15();
	//exercicio16();
	//exercicio17();
	//exercicio18();
	//exercicio19();
	//exercicio20();
	//exercicio21();
	//exercicio22();
	//exercicio23();
	//exercicio24();
	//exercicio25();
	exercicio26();
return 0;
}

