#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define RAMPA 50 // tempo até a aceleração total
int main(){
	setlocale(LC_ALL, "Portuguese");
	int n,a=0;
	float rampa, tempo, tini,tfim,i=0;
	rampa=(float)255/(float)RAMPA;
	printf("acelaranção em %d milissegundo\n",RAMPA);
	tini=(float)clock();
	while (i<255){
		a++;
		tempo=(float)clock();
		i=(tempo-tini)*rampa;
		printf("i=%.2f  clock=%f\n",i,tempo);
	}
	tfim=(float)clock();
	printf("\nCiclos %d \ntempo decorrido=%.2f milissegundos ",a,tfim-tini);
	return 0;
}

