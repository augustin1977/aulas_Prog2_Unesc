#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float volume_esfera(float r){
// pre: entra raio da esfera
// pós: retorna volume da esfera
    float vol;
    vol=pow(r,3)*M_PI*4/3;
    return vol;
}

long long fatorial(int f){
// pre: recebe um numero inteiro
// pós: retorna um inteiro (long long) correspondente ao fatorial do numero entrado
    int i;
    long fat=1;
    for (i=f;i>0;i--){
        fat=fat*i;
    }
    return fat;
}

float imc(float p, float h){
// pre: entra peso e altura
// pós: sai o IMC
    float indice;
    indice=p/h/h;
    return indice;
}

int par(int n){
// pre: Entra um inteiro
// pós: verdadeiro para par e falso para impar

int res;
if (n%2==0){
    res=1;
} else {
    res=0;
}
return res;
}

int positivo(int n){
// pre: Entra um inteiro
// pós: verdadeiro de positivo e falso se negativo
int res;
if (n>=0){
    res=1;
} else {
    res=0;
}
return res;
}

int verifica_primo(int a){
// pre: um numero inteiro
// pós: retorna verdadeiro se primo, senão falso
	int i,primo;
	primo=0;
	for (i=a/2+1;i>0;i--){
		if (a%i==0){
			primo=1;
		}
	
	}
	return (primo);
}

void baskara(float a,float b,float c,float *delta,float *raiz1,float *raiz2){
	*delta=(pow(b,2))-(4*a*c);
	printf("delta=%.2f\n",*delta);
	if (*delta >0 ){
		*raiz1=(-b+pow(*delta,0.5))/(2*a);
		*raiz2=(-b-pow(*delta,0.5))/(2*a);
	} else if (*delta==0){
		*raiz1=(-b+pow(*delta,0.5))/(2*a);
	} else{
		*raiz1=0;
		*raiz2=0;
	}
}

int segundos_para_horas(int *h,int *m, int *s){
// pre: três endereços de numero inteiro Hora, minuto e segundo
// pós: retorna tres inteiros hora, minuto e segundo	
	if (*s>=60){
		*m=*m+*s/60;
		*s=*s%60;
	}
	if (*m>60){
		*h=*h+*m/60;
		*m=*m%60;
	}
	return 0;
}

int anos_para_dias(int a, int m, int d){
// pre: três  numero inteiro dias, meses e anos
// pós: retorna um inteiros em dias
	d=d+m*30+a*365;
	return d;
}

int perfeito(int n){
// pre: um inteiro
// pós: rverdadeiro para numero perfeito ou falso para os demais
	int div[100];
	int m,i,j,sum,ret;
	m=n;
	div[0]=1;
	j=1;
	for (i=2;i<n;i++){
		
		while(m%i==0){
			div[j]=i;
			m=m/i;
			j++;	
		}	
	}
	for (i=j;i>=0;i--){
		sum=sum+i;
		}
	if (sum==n){ ret=1;
	}
	else {
		ret=0;
	}
	return ret;
}

char *categoria(int n){
// pre: um inteiro (idade)
// pós: retorna com um string com a categoria da idade
	char *cat;
	if (n>=5 && n<=7){
		cat="Infantil A";
	}else if (n>7 && n<=10){
		cat="Infantil B";
	}else if (n>10 && n<=13){
		cat="Juvenil A";
	}else if (n>13 && n<=17){
		cat="Juvenil B";
	} else if (n>17){
		cat="Adulto";
	}else{
		cat="Fora das categorias pré-definidas!!";
	}
	return cat;
}

char conceito_nota(float n){
// pre: um inteiro (nota)
// pós: retorna com um string com o conceito da nota (A,B,C,D) ou E se erro.
	char res;
	if (n<5 && n>=0){
		res='D';
	} else if (n<7){
		res='C';	
	} else if (n<9){
		res='B';
	} else if (n<=10){
		res='A';
	} else {
		res='E';
	}
	return res;
}

float peso_ideal(char s, float h){
// pre: entra sexo e peso
// pós: retorna o peso ideal
	float peso;
    if (s=='M'||s=='m'){
    	peso= 72.7*h - 58;
    }
    else if (s=='f'||s=='F'){
    	peso= 62.1 *h - 44.7;
	}
	return peso;
}

int troca(int *a, int *b){
	// pre: Recebe dois inteiros;
	// pós: retorna eles trocados;
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
	return 0;
}

int ordena(int *vetor,int n){
// pre: Recebe um vetor;
// pós: retorna o vetor ordenado;
	int i,j;
	for (i=0;i<n;i++){
		for (j=i;j<n;j++){
			if (vetor[i]>vetor[j]){
				troca(&vetor[i],&vetor[j]);
			}
		}
	}
	return 0;
}

int verifica_triangulo(float a, float b, float c){
// pre: Rrecebe tres valores (float) correspondetes ao tamanho dos lados de um triangulo;
// pós: retorna booleando sendo verdadeiro quanto o triangulo existe e falso quando não existe
	int res;
	if (a<b+c && b<a+c && c<a+b){
		res=1;
	}
	else {
		res=0;
	}
	return res;
}

int tipo_triangulo(float a,float b, float c){
// pre: Rrecebe tres valores (float) correspondetes ao tamanho dos lados de um triangulo;
// pós: retorna inteiro sendo 1= triangulo equilatero, 2= triangulo isoceles, 3=triangulo escaleno ou 4=não é um triangulo
	int res;
	if(verifica_triangulo(a,b,c)==0){
		res=4;
	}
	else{
		if(a==b && b==c){
			res=1;
		}else if(a==b || b==c|| c==a){
			res=2;
		}else{
			res=3;
		}
	}
	return res;
}
float recebesalario(){
// pre: Recebe um valor (Float)
// pós: Retorna o valor que recebeu
	float salario;
	printf("Digite o salario:");
	scanf("%f",&salario);
	return salario;
}
int recebefilhos(){
// pre: Recebe um valor (int)
// pós: Retorna o valor que recebeu
	int filhos;
	printf("Digite o numero de filhos :");
	scanf("%d",&filhos);
	return filhos;
}


int calcula_media_valores(){
// pre: Recebe valores até o usuários decidir parar
// pós: Retorna o a media dos valores digitados
	int opcao,n=0,valor;
	float media;
	printf("Programa para calcular media de uma sequencia de números.\nDigite 0 para sair ou 1 para entrar com dados:\n");
	scanf("%d",&opcao);
	if (opcao==0) n=1;
	while(opcao==1){
		printf("Digite o numero: ");
		scanf("%d",&valor);
		media=media+valor;
		n++;
		printf("Deseja digitar mais valores (0-não / 1-sim):");
		scanf("%d",&opcao);
	}
	media=media/n;
	return media;
}

int *maior_menor(int indice[2], int n){
// pre: recebe um vetor de duas posições, onde serão armazenamos o maior e o menor valores da sequencia de numeros, e um inteiro indicando a quantidade de numeros a serem digitados
// pós: Retorna um vetor onde na posição o temos o maior valor da sequencia e na posição 1 temos o menor valor da sequencia
	int valor,i;
	for(i=0;i<n;i++){
		printf("Digite o %d° numero:\n",i+1);
		scanf("%d",&valor);
		if (i==0 || indice[0]<valor){
			indice[0]=valor;
		}
		if (i==0 || indice[1]>valor){
			indice[1]=valor;
		}	
	}
	return indice;
}

void taboada(int n){
// pre: recebe um inteiro e imprime sua taboada
// pós: não retorna valor.
	int i;
	for (i=1;i<=n;i++){
		printf("%d x %d = %d\n",i,n,i*n);
	}
}

int *divisores(int n,int vetor[100]){
// pre: recebe um vetor de inteiros vazios e um numero que quer se saber os multiplos
// pós: retorna um vetor com o numero de multiplos na posição 0 e todos os multiplos nas demais posições
	int i,k=0;
	for (i=1;i<(n/2)+1;i++){
		if (n%i==0){
			vetor[k]=i;
			k++;
		}
	}
	for (i=k;i>=0;i--){
		vetor[i]=vetor[i-1];
		}
	vetor[0]=k;
	return vetor;
}

int somatorio(int n){
// pre: recebe um inteiro
// pós: retorna o somatario de todos os inteiros positivos menors que o numero entrado
	int i,sum=0;
	sum=(1+n)*(n/2);
	if (n%2==1) sum=sum+(n/2+1);
	printf("%d\n",sum);
	sum=0;
	/*for (i=1;i<=n;i++){
		sum=sum+i;
	}*/
	return sum;
}

float calcula_s(int n){
// pre: recebe um inteiro n
// pós: retorna um float com o resultado da equação S = 1 + ½ + 1/3 + ¼ + 1/5 + 1/N
	float s;
	s = 1.0 + 1.0/2 + 1.0/3 + 1.0/4 + 1.0/5 + 1.0/n;
	return s;
}

float calcula_s_fatorial(long long n){
// pre: recebe um inteiro (long long)
// pós: retorna um float com o resultado da equação S = 1 + 1/2!+1/3!+1/n!
	float s;
	s = 1.0 + 1.0/fatorial(2) + 1.0/fatorial(3)+ 1.0/fatorial(n);
	return s;
}

float calcula_somatorio_quadatico(int n){
// pre: recebe um inteiro ()
// pós: retorna um float com o resultado da equação S = 1 + 1/2!+1/3!+1/n!
	float s;
	int i;
	for (i=1;i<=n;i++){
		s=s+(1+pow(i,2))/(i+3);
	}
	return s;
}
