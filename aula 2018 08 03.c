#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"
#include <locale.h>
int a,b,c;
float m;
void entrada(){
    scanf("%i",&a);
    scanf("%i",&b);
    scanf("%i",&c);

}
void processamento(){
    m=(a+b+c)/3.0;

}
void saida(){
    printf("A média é %.2f!",m);
}

int exercicio1(){

    entrada();
    processamento();
    saida();
    return 0;
}

int exercicio2(){
    int i;
    long f;
    printf("Calculo do Fatoria!\n Digite um numero:\n");
    scanf("%i",&i);
    f=fatorial(i);
    printf("O fatoria de %d é %ld",i,f);
    return 0;
    }
int exercicio3(){
    float p,h,indice;
    scanf("%f",&p);
    scanf("%f",&h);
    indice=imc(p,h);
    printf("%.2f",indice);
    return 0;
}
int exercicio4(){
    int i;
    printf("Digite um numero para verificar se é par:\n");
    scanf("%d",&i);
    printf("%d\n",par(i));
    if (par(i)==1) {
        printf("%d é um numero Par",i);
    }
    else {
        printf("%d é um numero Impar",i);
    }
    return 0;
}
int main(){
	setlocale(LC_ALL, "Portuguese");
    //exercicio1();
    //exercicio2();
    //exercicio3();
    //exercicio4();
    return 0;
}

