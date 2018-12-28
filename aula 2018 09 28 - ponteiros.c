#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

/*
dados
int x=14, *py=&x,**ppy=&px;
float y=7,8, *px=&y, *ppx=&py

X=14	 &x=FFA0
Y=7.8	 &y=FFB4
PX=FFB4	 &PX=FFF0
PY=FFA0	 &PY=FFC6
PPY=FFF0 &PPY=FFA6
PPX=FFC6 &PPX=FFD4

Responda:
X=14
*PY=14
PX=FFB4
&Y=FFB4
*PX=7.8
y=&.8
*PPX=FFA0
&PY=FFC6
&X=FFA0
*&PX=FFB4
&PPY=FFA6
&PPX=FFD4
*/

void troca(int *a,int *b){
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
void organiza(int v[], int n){
	int i, o=1;
	while(o){
		o=0;
		for (i=0;i<n-1;i++){
			if (v[i]>v[i+1]) {
			troca(&v[i],&v[i+1]);
			o=1;
			}		
		}
	}
}	
int retorna_maior(int v[], int n){
	int i,maior=v[0];
	for (i=1; i<n; i++){
		if (v[i]>maior) maior=v[i];
	}
	return maior;
}
void ponteiro(){
	char v1[10],i; // Declara o vetor
	gets(v1); // Pega o vetor do teclado
	char *p; // declara um ponteiro
	p=v1; // faz o ponteiro apontar para o vetor
	printf("%c",*p); // imprime o conteudo do ponteiro

}
void imprime_vetor(int v[], int n){
	int i;
	for (i=0; i<n; i++){
		printf("%d ",v[i]);
	}
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	int n=10,v[n],i;
	srand(time(NULL));
	for (i=0; i<n; i++){
		v[i]=rand()%1000;
		printf("%d ",v[i]);
	}
	//ponteiro();
	printf("\nO maior do valor do vetor é o %d\n",retorna_maior(v,10));
	printf("O vetor organizado fica assim!\n");
	organiza(v,n);
	imprime_vetor(v,n);
	return 0;
}
