#ifndef funcoes
#define funcoes
#include "funcoes.c"

float volume_esfera(float r);
// pre: entra raio da esfera
// p�s: retorna volume da esfera

long long  fatorial(int f);
// pre: recebe um numero inteiro
// p�s: retorna um inteiro (long long) correspondente ao fatorial do numero entrado

float imc(float p, float h);
// pre: entra peso e altura
// p�s: sai o IMC

int par(int n);
// pre: Entra um inteiro
// p�s: verdadeiro para par e falso para impar

int positivo(int n);
// pre: Entra um inteiro
// p�s: verdadeiro de positivo e falso se negativo

int verifica_primo(int a);
// pre: um numero inteiro
// p�s: retorna verdadeiro se primo, sen�o falso

void baskara(float a,float b,float c,float *delta,float *raiz1,float *raiz2);
// pre: tres paramentros da equa��o e os endere�os do delta e das duas raizes
// p�s: retorna o valor do delta e das raizes

int segundos_para_horas(int *h,int *m, int *s);
// pre: tr�s endere�os de numero inteiro Hora, minuto e segundo
// p�s: retorna tres inteiros hora, minuto e segundo

int anos_para_dias(int a, int m, int d);
// pre: tr�s  numero inteiro dias, meses e anos
// p�s: retorna um inteiros em dias

int perfeito(int n);
// pre: um inteiro
// p�s: rverdadeiro para numero perfeito ou falso para os demais

char *categoria(int n);
// pre: um inteiro (idade)
// p�s: retorna com um string com a categoria da idade

char conceito_nota(float n);
// pre: um inteiro (nota)
// p�s: retorna com um string com o conceito da nota (A,B,C,D) ou E se erro.

float peso_ideal(char s, float h);
// pre: entra sexo e peso
// p�s: retorna o peso ideal

int troca(int *a, int*b);
// pre: Recebe dois inteiros;
// p�s: retorna eles trocados;

int ordena(int *vetor,int n);
// pre: Recebe um vetor;
// p�s: retorna o vetor ordenado;

int verifica_triangulo(float a, float b, float c);
// pre: Rrecebe tres  valores (float) correspondetes ao tamanho dos lados de um triangulo;
// p�s: retorna boleando sendo verdadeiro quanto o triangulo existe e falso quando n�o existe

int tipo_triangulo(float a,float b, float c);
// pre: Rrecebe tres valores (float) correspondetes ao tamanho dos lados de um triangulo;
// p�s: retorna inteiro sendo 1= triangulo equilatero, 2= triangulo isoceles, 3=triangulo escaleno ou 4=n�o � um triangulo

float recebesalario();
// pre: Recebe um valor (Float)
// p�s: Retorna o valor que recebeu

int recebefilhos();
// pre: Recebe um valor (int)
// p�s: Retorna o valor que recebeu

int calcula_media_valores();
// pre: Recebe valores at� o usu�rios decidir parar
// p�s: Retorna o a media dos valores digitados

int *maior_menor(int indice[2], int n);
// pre: recebe um vetor de duas posi��es, onde ser�o armazenamos o maior e o menor valores da sequencia de numeros, e um inteiro indicando a quantidade de numeros a serem digitados
// p�s: Retorna um vetor onde na posi��o o temos o maior valor da sequencia e na posi��o 1 temos o menor valor da sequencia

void taboada(int n);
// pre: recebe um inteiro e imprime sua taboada
// p�s: n�o retorna valor.

int *divisores(int n,int vetor[100]);
// pre: recebe um vetor de inteiros vazios e um numero que quer se saber os multiplos
// p�s: retorna um vetor com o numero de multiplos na posi��o 0 e todos os multiplos nas demais posi��es

int somatorio(int n);
// pre: recebe um inteiro
// p�s: retorna o somatario de todos os inteiros positivos menors que o numero entrado

float calcula_s(int n);
// pre: recebe um inteiro n
// p�s: retorna um float com o resultado da equa��o S = 1 + � + 1/3 + � + 1/5 + 1/N

float calcula_s_fatorial(long long n);
// pre: recebe um inteiro (long long)
// p�s: retorna um float com o resultado da equa��o S = 1 + 1/2!+1/3!+1/n!
#endif
