#ifndef funcoes
#define funcoes
#include "funcoes.c"

float volume_esfera(float r);
// pre: entra raio da esfera
// pós: retorna volume da esfera

long long  fatorial(int f);
// pre: recebe um numero inteiro
// pós: retorna um inteiro (long long) correspondente ao fatorial do numero entrado

float imc(float p, float h);
// pre: entra peso e altura
// pós: sai o IMC

int par(int n);
// pre: Entra um inteiro
// pós: verdadeiro para par e falso para impar

int positivo(int n);
// pre: Entra um inteiro
// pós: verdadeiro de positivo e falso se negativo

int verifica_primo(int a);
// pre: um numero inteiro
// pós: retorna verdadeiro se primo, senão falso

void baskara(float a,float b,float c,float *delta,float *raiz1,float *raiz2);
// pre: tres paramentros da equação e os endereços do delta e das duas raizes
// pós: retorna o valor do delta e das raizes

int segundos_para_horas(int *h,int *m, int *s);
// pre: três endereços de numero inteiro Hora, minuto e segundo
// pós: retorna tres inteiros hora, minuto e segundo

int anos_para_dias(int a, int m, int d);
// pre: três  numero inteiro dias, meses e anos
// pós: retorna um inteiros em dias

int perfeito(int n);
// pre: um inteiro
// pós: rverdadeiro para numero perfeito ou falso para os demais

char *categoria(int n);
// pre: um inteiro (idade)
// pós: retorna com um string com a categoria da idade

char conceito_nota(float n);
// pre: um inteiro (nota)
// pós: retorna com um string com o conceito da nota (A,B,C,D) ou E se erro.

float peso_ideal(char s, float h);
// pre: entra sexo e peso
// pós: retorna o peso ideal

int troca(int *a, int*b);
// pre: Recebe dois inteiros;
// pós: retorna eles trocados;

int ordena(int *vetor,int n);
// pre: Recebe um vetor;
// pós: retorna o vetor ordenado;

int verifica_triangulo(float a, float b, float c);
// pre: Rrecebe tres  valores (float) correspondetes ao tamanho dos lados de um triangulo;
// pós: retorna boleando sendo verdadeiro quanto o triangulo existe e falso quando não existe

int tipo_triangulo(float a,float b, float c);
// pre: Rrecebe tres valores (float) correspondetes ao tamanho dos lados de um triangulo;
// pós: retorna inteiro sendo 1= triangulo equilatero, 2= triangulo isoceles, 3=triangulo escaleno ou 4=não é um triangulo

float recebesalario();
// pre: Recebe um valor (Float)
// pós: Retorna o valor que recebeu

int recebefilhos();
// pre: Recebe um valor (int)
// pós: Retorna o valor que recebeu

int calcula_media_valores();
// pre: Recebe valores até o usuários decidir parar
// pós: Retorna o a media dos valores digitados

int *maior_menor(int indice[2], int n);
// pre: recebe um vetor de duas posições, onde serão armazenamos o maior e o menor valores da sequencia de numeros, e um inteiro indicando a quantidade de numeros a serem digitados
// pós: Retorna um vetor onde na posição o temos o maior valor da sequencia e na posição 1 temos o menor valor da sequencia

void taboada(int n);
// pre: recebe um inteiro e imprime sua taboada
// pós: não retorna valor.

int *divisores(int n,int vetor[100]);
// pre: recebe um vetor de inteiros vazios e um numero que quer se saber os multiplos
// pós: retorna um vetor com o numero de multiplos na posição 0 e todos os multiplos nas demais posições

int somatorio(int n);
// pre: recebe um inteiro
// pós: retorna o somatario de todos os inteiros positivos menors que o numero entrado

float calcula_s(int n);
// pre: recebe um inteiro n
// pós: retorna um float com o resultado da equação S = 1 + ½ + 1/3 + ¼ + 1/5 + 1/N

float calcula_s_fatorial(long long n);
// pre: recebe um inteiro (long long)
// pós: retorna um float com o resultado da equação S = 1 + 1/2!+1/3!+1/n!
#endif
