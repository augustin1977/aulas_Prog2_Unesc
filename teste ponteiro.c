#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
	typedef struct estrutura{
		int a,*b;
		FILE *t;
		
	} estrutura;
	estrutura t;
	setlocale(LC_ALL, "Portuguese");
	t.t=fopen("teste.dat","w");
	t.a=10;
	t.b=&t.a;
	printf("a=%d, endereço de A%p \nvalor do ponteiro de b=%d, valor de B %p, endereço de b=%p",t.a,&t.a,*t.b,t.b,&t.b);
	fprintf(t.t,"a=%d, endereço de A%p \n  valor do ponteiro de b=%d, valor de B %p, endereço de b=%p",t.a,&t.a,*t.b,t.b,&t.b);
	return 0;
}

