#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
void exemplo(){
	int *p,x,y;
	x=20;
	p=&x;
	y=*p;
	printf("%p %i",p,y);
}

void exemplo2(){
	long *p,x;
	printf("%i\n",sizeof(x));
	x=20;
	p=&x;
	printf("%p\n",p);
	p++;
	printf("%p\n",p);
}

void troca(int *a, int *b){
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

void end_vetor(){
	int v[4],i;
	v[0]=100;
	v[1]=200;
	v[2]=300;
	int *p;
	p=&v[0];
	for(i=0;i<4;i++){
		(*p)++;
		printf("%p %d\n",p,*p);
		p++;
	}
}
void vetor_char(){
	char nome[100],i;
	gets(nome);
	char *p;
	p=&nome[0];
	for(i=0;i<strlen(nome);i++){
		//(*p)++;
		printf("%p %c\n",p,*p);
		p++;
	}

}
int somaporvalor(int a, int b){
	a++;
	b++;
	int s=a+b;
	return (s);
}
int somaporreferencia(int *a, int *b){
	(*a)++;
	(*b)++;
	int s=*a+*b;
	return (s);
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	int a=5,b=2;
	//troca(&a,&b);
	//exemplo2();
	//end_vetor();
	//vetor_char();
	printf("%d+%d=%d\n",a,b,somaporvalor(a,b));
	printf("%d+%d=%d\n",a,b,somaporreferencia(&a,&b));
	printf("%p %p\n",&a,&b);
	return 0;
}

