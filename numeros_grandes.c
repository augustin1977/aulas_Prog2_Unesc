#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 100
int char_int(char a){
if (a=='1') return 1;
else if (a=='2') return 2;
else if (a=='3') return 3;
else if (a=='4') return 4;
else if (a=='5') return 5;
else if (a=='6') return 6;
else if (a=='7') return 7;
else if (a=='8') return 8;
else if (a=='9') return 9;
else if (a=='0') return 0;
else return 0;
}
char int_char(int a){
if (a==1) return '1';
else if (a==2) return '2';
else if (a==3) return '3';
else if (a==4) return '4';
else if (a==5) return '5';
else if (a==6) return '6';
else if (a==7) return '7';
else if (a==8) return '8';
else if (a==9) return '9';
else if (a==0) return '0';
else return 'a';
}

void inverte(char num[MAX]){
	int c,i;
	char aux;
	c=strlen(num);
	for (i=0;i<c/2;i++){
		aux=num[c-i-1];
		num[c-i-1]=num[i];
		num[i]=aux;
	}
}
void soma(char n1[MAX],char n2[MAX], char ru[MAX]){
	int c1,c2,i,j,maior,a,b,r,vai=0;
	c1=strlen(n1);
	c2=strlen(n2);
	inverte(n1);
	inverte(n2);
	if (c1>c2){
		maior=c1;		
	} else {
		maior=c2;
	}
	for (i=0;i<maior;i++){
		if (i>c1) a=0;
		else a=char_int(n1[i]);
		if (i>c2) b=0;
		else b=char_int(n2[i]);
		//printf("a=%d b=%d \n",a,b);
		if (vai==0)	r=a+b;
		else r=a+b+vai;
		vai=r/10;
		r=r%10;
		//printf("r=%d vai=%d \n",r,vai);
		ru[i]=int_char(r);		
	}
	if (vai>0) {
		ru[i]=int_char(vai);
		vai=0;
		ru[i+1]='\0';
	}
	inverte(ru);
}
void produto(char n1[MAX],char n2[MAX], char ru[MAX]){
	int c1,c2,i,j,maior,a,b,r,vai=0;
	char rut[MAX];
	c1=strlen(n1);
	c2=strlen(n2);
	inverte(n1);
	inverte(n2);
	if (c1>c2){
		maior=c1;		
	} else {
		maior=c2;
	}	
	
	for (i=0;j<c2;j++){ 
		for (i=0;i<maior;i++){
			if (i>c1) a=0;
			else a=char_int(n1[i]);
			if (i>c2) b=0;
			else b=char_int(n2[i]);
			//printf("a=%d b=%d \n",a,b);
			if (vai==0)	r=a*b;
			else r=(a*b)+vai;
			vai=r/10;
			r=r%10;
			//printf("r=%d vai=%d \n",r,vai);
			rut[i]=int_char(r);		
		}
	if (vai>0) {
		rut[i]=int_char(vai);
		vai=0;
		rut[i+1]='\0';
	}
	soma(rut,ru,ru);
	}
	inverte(ru);
	
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	char a[MAX];
	char b[MAX];
	char c[MAX];
	scanf("%s",&a);
	scanf("%s",&b);
	produto(a,b,c);
	printf("\n%s\n",c);
	
}

