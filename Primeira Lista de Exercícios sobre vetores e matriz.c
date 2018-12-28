#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#define MAX1 12
#define MAX2 30
#define MAX3 16
#define MAX4 20
#define MAX5 40
#define MAX6 40
#define MAX7 20
#define MAX8 4
#define MAX12 9
#define MAX13 10
#define MAX14 50
#define MAX16 10
#define MAX17 5
#define MAX18 4
#define MAX19 6
#define MAX20 20
#define MAX21 4
#define MAX22 8
void imprime_vetor(int vetor[],int n){
// pre:recebe vetor e numero de elementos
// pós: imprime o vetor na ordem do registro
	int i;
	for(i=0;i<n;i++){
		printf("%2d)%3d ",i,vetor[i]);
	}
	printf("\n");
}

int criar_vetor_aleatorio(int vetor[], int n, int max){
// pre:recebe vetor e numero de elementos e o valor maximo dos aleatórios
// pós:escreve os numeros aleatorios no vetor na ordem digitada
	int i;
	
	for(i=0;i<n;i++){
		vetor[i]=rand()%(max+1);
		}
	return vetor;
}

int criar_vetor(int vetor[], int n){
// pre:recebe vetor e numero de elementos
// pós:escreve os numeros digitados no vetor na ordem digitada
	int i;
	for(i=0;i<n;i++){
		printf("Entre com o valor da posição %d :",i);
		scanf("%d",&vetor[i]);
		}
	return vetor;
}
void exercicio1(){
	int vetor[MAX1], i,x,y;
	criar_vetor(vetor,MAX1);
	imprime_vetor(vetor,MAX1);
	printf("Digite a primeira posição:");
	scanf("%d",&x);
	printf("Digite a segunda posição:");
	scanf("%d",&y);
	printf("A soma das posições é %d.",vetor[x]+vetor[y]);
}

int criar_vetor_impar(int vetor[], int n){
// pre:recebe vetor e numero de elementos
// pós:escreve os numeros impares até preencher o numero de elementos solicitados
	int i;
	for(i=0;i<n;i++){
		vetor[i]=i*2+1;
		}
	return vetor;
}
void exercicio2(){
	int vetor[MAX2],i;
	criar_vetor_impar(vetor,MAX2);
	imprime_vetor(vetor,MAX2);
}
int troca(int vetor[],int pos1,int pos2,int n){
// pre:recebe vetor, a posição de inicio do primeiro conjunto de trocas, a posição do segundo conjunto de trocas e numero de elementos a serem trocados
// pós:faz a troca de posição entre o primeiro grupo e o segundo grupo
	int i,temp;
	for (i=0;i<n;i++){
		temp=vetor[pos1+i];
		vetor[pos1+i]=vetor[pos2+i];
		vetor[pos2+i]=temp;
	}	
	return vetor;
}
void exercicio3(){
	int vetor[MAX3];
	criar_vetor(vetor,MAX3);
	troca(vetor,0,8,8);
	imprime_vetor(vetor,MAX3);
}
int procura_valor_vetor(int vetor[],int m, int n){
// pre:recebe vetor e o valor a ser buscado
// pos:Se não encontrar o valor retorna -1, se encontrar retorna a posição do valor encontrado no vetor.
	int i, pos_retorno=-1;
	i=0;
	while(i<n && pos_retorno==-1){
		if (vetor[i]==m) pos_retorno=i;
		i++;
	}
	return pos_retorno;
}
void exercicio4(){
	int vetor[MAX4],n,i;
	//criar_vetor(vetor,MAX4);
	criar_vetor_aleatorio(vetor,MAX4,50);
	imprime_vetor(vetor,MAX4);
	printf("Digite o valor que deseja procurar: ");
	scanf("%d",&n);
	i=procura_valor_vetor(vetor,n, MAX4);
	if (i>=0) printf("O valor porcurado está na posição %d",i);
	else printf("O valor procurado não foi encontrado");
}
int procura_pares(int vetor[], int n){
// pre:recebe vetor e tamanho do vetor
// pos:Retorna o numero de numeros pares encotrados no vetor
	int i,pares=0;
	for (i=0;i<MAX5;i++){
		if (vetor[i]%2==0) pares++;
	}
	return pares;
}
void exercicio5(){
	int vetor[MAX5],i,pares=0;
	criar_vetor(vetor,MAX5);
	imprime_vetor(vetor,MAX5);
	pares=procura_pares(vetor,MAX5);
	printf("O vetor possui %d numeros pares.",pares);
}
int *zera_negativos(int vetor[], int n){
// pre:recebe vetor e tamanho do vetor
// pos:Retorna o vetor com os numeros negativos substituidos por 0
	int i;
	for(i=0;i<n;i++){
		if (vetor[i]<0) vetor[i]=0;
		}
	return vetor;
}
void exercicio6(){
	int vetor[MAX6];
	criar_vetor(vetor,MAX6);
	vetor[3]=-4;
	imprime_vetor(vetor,MAX6);
	zera_negativos(vetor,MAX6);
	imprime_vetor(vetor,MAX6);
	}
int *funde_vetores(int vetor1[], int vetor2[], int vetor3[], int n){
// pre:recebe 3 vetores de mesmo tamanho e o tamanho dos vetores
// pos:funde os dois primerios vetores e retorna o terceiro com os endereços pares do primeiro e impares do segundo, em caso de erro retorna o vetor preenchdo com 0
	int i;
	printf("%d\n",n);
	if (sizeof(vetor1)==sizeof(vetor2) && sizeof(vetor2)==sizeof(vetor3) ) {
		for (i=0;i<n;i++){
			printf("%d> %d %d %d\n",i,vetor1[i],vetor2[i],vetor3[i]);
			if (i%2==0) {
				vetor3[i]=vetor1[i];
				//printf("par %d\n",vetor3[i]);
			}
			else {
				vetor3[i]=vetor2[i];
				//printf("impar %d\n",vetor3[i]);
			}
		}
	}
	else{	
	for (i=0;i<n;i++){
		vetor3[i]=0;
	}
	}
	return vetor3;
}
void exercicio7(){
	int vetor1[MAX7],vetor2[MAX7],vetor3[MAX7];
	printf("Criar primeiro vetor:\n");
	criar_vetor(vetor1,MAX7);
	printf("Criar segundo vetor:\n");
	criar_vetor(vetor2,MAX7);
	funde_vetores(vetor1,vetor2,vetor3,MAX7);
	printf("\n");
	imprime_vetor(vetor1,MAX7);
	printf("\n");
	imprime_vetor(vetor2,MAX7);
	printf("\n");
	imprime_vetor(vetor3,MAX7);
}
int *acumula_vetor(int vetor[],int vetor_ret[],int n){
// pre:recebe 1 vetor origem e 1 destino  e o tamanho dos vetors
// pos: retorna no segundo vetor o valor acumulado dos termos do primeiro vetor, iniciando pelo termo 0 até n
	int i;
	vetor_ret[0]=vetor[0];
	for (i=1;i<n;i++){
		vetor_ret[i]=vetor_ret[i-1]+vetor[i];
		printf("%d ",vetor_ret[i]);
	}
	printf("\n");
	return vetor_ret;
}

void exercicio8(){
	int vetor1[MAX8],vetor2[MAX8];
	criar_vetor_impar(vetor1,MAX8);
	imprime_vetor(vetor1,MAX8);
	acumula_vetor(vetor1,vetor2,MAX8);
	imprime_vetor(vetor2,MAX8);
}

int *retira_espacos(char string[],char vetor[]){
// pre: recebe 1 vetor origem com uma string e 1 destino;
// pos: retorna no segundo vetor a string sem os espaços em branco
	int i,j,n;
	j=0;
	for(i=0;string[i]!='\0';i++){
		if (string[i]!=32){
			vetor[j]=string[i];
		 	j=j+1;
			}
		}
	return 0;
}

void exercicio9(){
	char palavra[1000],vetor[1000];
	printf("Digite uma frase:");
	//strcpy(palavra,"teste de frase que quero testar"); // strcopy é um comando para atribuir uma string a um vetor de char
	gets(palavra); 
	retira_espacos(palavra,vetor);
	printf("%s",vetor);
	}
int string_para_numero(char palavra[]){
// pre:recebe um vetor com uma string que só contem digitos numericos
// pos: retorna um inteiro equivalente ao valor dessa string
	int i,j=0,n=0,numero=0;
	for(i=0;palavra[i]!='\0';i++){
		n++;
	}
	for(i=0;i<n;i++){
		numero=numero+(palavra[i]-'0')*pow(10,n-i-1);
		}
	return numero;
}	
int escrever_por_extenso(int numero,char frase[]){
// pre: recebe um inteiro e uma string vazia
// pos: retorna a string preenchida com o inteiro escrito por extenço
	int resto,dezena,centena,unidade,milhar,dezena_milhar;
	strcpy(frase,"");
	if (numero>0 && numero<=99999){
		unidade=numero%10;
		dezena=(numero%100-unidade)/10;
		centena=(numero%1000-dezena-unidade)/100;
		milhar=(numero%10000-centena-dezena-unidade)/1000;
		dezena_milhar=(numero%100000-milhar-centena-dezena-unidade)/10000;
		//printf("10000 %d\n",dezena_milhar);
		//printf("1000 %d\n",milhar);
		//printf("100 %d\n",centena);
		//printf("10 %d\n",dezena);
		//printf("1 %d\n",unidade);
		if (dezena_milhar==1 && unidade==0) strcat(frase,"dez ");
		else if (dezena_milhar==1 && milhar==1) strcat(frase,"onze ");
		else if (dezena_milhar==1 && milhar==2) strcat(frase,"doze ");
		else if (dezena_milhar==1 && milhar==3) strcat(frase,"treze ");
		else if (dezena_milhar==1 && milhar==4) strcat(frase,"quatorze ");
		else if (dezena_milhar==1 && milhar==5) strcat(frase,"quinze ");
		else if (dezena_milhar==1 && milhar==6) strcat(frase,"dezesseis ");
		else if (dezena_milhar==1 && milhar==7) strcat(frase,"dezessete ");
		else if (dezena_milhar==1 && milhar==8) strcat(frase,"dezoito ");
		else if (dezena_milhar==1 && milhar==9) strcat(frase,"dezenove ");
		else if (dezena_milhar==2) strcat(frase,"vinte ");
		else if (dezena_milhar==3) strcat(frase,"trinta ");
		else if (dezena_milhar==4) strcat(frase,"quarenta ");
		else if (dezena_milhar==5) strcat(frase,"cinquenta ");
		else if (dezena_milhar==6) strcat(frase,"sessenta ");
		else if (dezena_milhar==7) strcat(frase,"setenta ");
		else if (dezena_milhar==8) strcat(frase,"oitenta ");
		else if (dezena_milhar==9) strcat(frase,"noventa ");
		if (milhar >0 && dezena_milhar>1 ) strcat(frase,"e ");
		if (dezena_milhar!=1 && milhar==1) strcat(frase,"um ");
		else if (dezena_milhar!=1 && milhar==2) strcat(frase,"dois ");
		else if (dezena_milhar!=1 && milhar==3) strcat(frase,"tres ");
		else if (dezena_milhar!=1 && milhar==4) strcat(frase,"quatro ");
		else if (dezena_milhar!=1 && milhar==5) strcat(frase,"cinco ");
		else if (dezena_milhar!=1 && milhar==6) strcat(frase,"seis ");
		else if (dezena_milhar!=1 && milhar==7) strcat(frase,"sete ");
		else if (dezena_milhar!=1 && milhar==8) strcat(frase,"oito ");
		else if (dezena_milhar!=1 && milhar==9) strcat(frase,"nove ");
		if (milhar+dezena_milhar>0) strcat(frase,"mil ");
		if (centena>0 && milhar+dezena_milhar >0 && unidade==0) strcat(frase,"e ");
		if (centena==1 && dezena==0 && unidade==0) strcat(frase,"cem");
		else if (centena==1) strcat(frase,"cento ");
		else if (centena==2) strcat(frase,"duzentos ");
		else if (centena==3) strcat(frase,"trezentos ");
		else if (centena==4) strcat(frase,"quatrocentos ");
		else if (centena==5) strcat(frase,"quinhentos ");
		else if (centena==6) strcat(frase,"seissentos ");
		else if (centena==7) strcat(frase,"setecentos ");
		else if (centena==8) strcat(frase,"oitocentos ");
		else if (centena==9) strcat(frase,"novecentos ");
		if ( dezena >0&& (centena>0 || milhar>0)) strcat(frase,"e ");
		if (dezena==1 && unidade==0) strcat(frase,"dez");
		else if (dezena==1 && unidade==1) strcat(frase,"onze");
		else if (dezena==1 && unidade==2) strcat(frase,"doze");
		else if (dezena==1 && unidade==3) strcat(frase,"treze");
		else if (dezena==1 && unidade==4) strcat(frase,"quatorze");
		else if (dezena==1 && unidade==5) strcat(frase,"quinze");
		else if (dezena==1 && unidade==6) strcat(frase,"dezesseis");
		else if (dezena==1 && unidade==7) strcat(frase,"dezessete");
		else if (dezena==1 && unidade==8) strcat(frase,"dezoito");
		else if (dezena==1 && unidade==9) strcat(frase,"dezenove");
		else if (dezena==2) strcat(frase,"vinte ");
		else if (dezena==3) strcat(frase,"trinta ");
		else if (dezena==4) strcat(frase,"quarenta ");
		else if (dezena==5) strcat(frase,"cinquenta ");
		else if (dezena==6) strcat(frase,"sessenta ");
		else if (dezena==7) strcat(frase,"setenta ");
		else if (dezena==8) strcat(frase,"oitenta ");
		else if (dezena==9) strcat(frase,"noventa ");
		if (unidade >0 && dezena!=1 && ( centena>0|| milhar>0 )) strcat(frase,"e ");
		if (dezena!=1 && unidade==1) strcat(frase,"um");
		else if (dezena!=1 &&unidade==2) strcat(frase,"dois");
		else if (dezena!=1 && unidade==3) strcat(frase,"tres");
		else if (dezena!=1 && unidade==4) strcat(frase,"quatro");
		else if (dezena!=1 && unidade==5) strcat(frase,"cinco");
		else if (dezena!=1 && unidade==6) strcat(frase,"seis");
		else if (dezena!=1 && unidade==7) strcat(frase,"sete");
		else if (dezena!=1 && unidade==8) strcat(frase,"oito");
		else if (dezena!=1 && unidade==9) strcat(frase,"nove");
		frase[0]=frase[0]+('A'-'a');
		return 1;
	}
	else{
		return 0;
	}
}

void exercicio10(){
	char palavra[6],frase[1000];
	int numero,status;
	printf("Digite um numero para se transcrito para estenso:\n");
	scanf("%s",&palavra);
	numero=string_para_numero(palavra);
	status=escrever_por_extenso(numero,frase);
	if (status==1) {
	 	printf("%s",frase);
	}
	else {
		printf("Erro!");
	}

}
int *caixa_alta(char palavra[]){
// pre:recebe 1 string
// pos: retorna a string toda em maiuscula
	int i,n,soma=0;
	for (i=0;palavra[i]!='\0';i++){
		if (palavra[i]>='a') {
			palavra[i]=palavra[i]+'A'-'a';
		}
	}
		return 0;
}
int valor_palavra(char palavra[]){
// pre:recebe 1 string
// pos: a soma dos valores ASCII de cada caractere da string
	int i,n,soma=0;
	for (i=0;palavra[i]!='\0';i++){
		soma=soma+palavra[i];
		}
		return soma;
}	
int anagrama(char palavra[], char teste[]){
// pre:recebe 2 strings
// pos:retorna 1 se a soma dos valores ASCII das strings forem iguais e 0 se forem diferentes
	int vpalavra,vteste,retorno;
	vpalavra=valor_palavra(palavra);
	vteste=valor_palavra(teste);
	if (vpalavra==vteste) retorno=1;
	else retorno=0;
	return retorno;
}

void exercicio11(){
	char palavra1[100],palavra2[100];
	int teste;
	printf("Programa de teste de anagramas\nDigite a primeira palavra:");
	scanf("%s",&palavra1);
	caixa_alta(palavra1);
	printf("Digite a segunda palavra:");
	scanf("%s",&palavra2);
	caixa_alta(palavra2);
	teste=anagrama(palavra1,palavra2);
	if (teste==1) printf("São anagramas!");
	else printf("Não são anagramas");
}

int dividir_vetor_tercos(int vetor1[],int vetor2[],int vetor3[],int vetor4[],int n){
// pre:recebe 4 vetores de inteiros e um inteiro com o tamanho dos vetores
// pos:retorna o quarto vetor com primeiro terco do primeiro vetor, o segundo terco do segundo vetor e o terceiro terco do terceiro vetor;
	int i;
	for (i=0;i<n;i++){
		
		if (i<n/3) {
			vetor4[i]=vetor1[i];
		}
		else if (i<2*(n/3)) {
			vetor4[i]=vetor2[i];
		}
		else {
			vetor4[i]=vetor3[i];
		}

	}
	return 0;
}
void exercicio12(){
	int vetor1[MAX12],vetor2[MAX12],vetor3[MAX12],vetor4[MAX12];
	criar_vetor(vetor1,MAX12);
	criar_vetor(vetor2,MAX12);
	criar_vetor(vetor3,MAX12);
	//criar_vetor_aleatorio( vetor1 ,MAX12,50);
	//imprime_vetor(vetor1,MAX12);
	//criar_vetor_aleatorio( vetor2 ,MAX12,50);
	//imprime_vetor(vetor2,MAX12);
	//criar_vetor_aleatorio( vetor3 ,MAX12,50);
	//imprime_vetor(vetor3,MAX12);
	dividir_vetor_tercos(vetor1,vetor2,vetor3,vetor4,MAX12);
	imprime_vetor(vetor4,MAX12);	
}

int esta(int valor, int vetor[], int n){
// pre:recebe um inteiro, um vetor e o tamanho do vetor e verifica se o numero está no vetor
// pos:retorna 0 se o numero não estiver no vetor e 1 se estiver
	int i,ret=0;
	for(i=0;i<n;i++){
		if (valor==vetor[i]) ret=1;
	}
	return ret;
}

int retorna_repetidos(int vetor[], int retorno[], int n){
// pre:recebe um vetor com a sequencia a ser analisada, um vetor vazio, e o tamanho dos vetores
// pos:retorna no vetor vazios os numeros repetidos na sequencia analisada, sem repetição de valores

	int i,j,adiciona,repete=0,cont=0,aux[n],k=0;
	for (i=0;i<n;i++){
		adiciona=1;
		for (j=0;j<cont;j++){
			if (aux[j]==vetor[i]|| cont==0) adiciona=0;
		}	
		if (adiciona) {
			aux[cont]=vetor[i];
			cont++;
		}
		else {
			if (!(esta(vetor[i],retorno,k))) { 
				retorno[k]=vetor[i];
				k++;
			}
		}		
	}
	return k;
}
void exercicio13(){
	int  vetor[MAX13], retorno[MAX13], repete;
	criar_vetor_aleatorio(vetor,MAX13,10);
	imprime_vetor(vetor,MAX13);
	repete=retorna_repetidos(vetor, retorno, MAX13);
	if (repete==0) printf("Não ha numeros repetidos!");
	else {
		printf("Os numeros repetidos são:\n");
		imprime_vetor(retorno,repete);	
	}
}
int compacta_vetor(int vetor[], int comp[], int n){
// pre:recebe um vetor com a sequencia a ser analisada, um vetor vazio, e o tamanho dos vetores
// pos:retorna no vetor vazios o vetor original com os zeros ao final do vetor
	int i,cont=0,c;
	for (i=0;i<n;i++){
		if (vetor[i]!=0 ){
			comp[cont]=vetor[i];
			cont++;
		}
	}
	for (i=cont;i<n;i++){
		comp[i]=0;
	}
	return n-cont;
}
void exercicio14(){
	int vetor[MAX14],vetor_compactado[MAX14],c=0;
	criar_vetor_aleatorio(vetor,MAX14,20);
	imprime_vetor(vetor,MAX14);
	c=compacta_vetor(vetor,vetor_compactado,MAX14);
	imprime_vetor(vetor_compactado,MAX14);
	
}

void exercicio15(){
	int v[10]={5, 7 ,6 ,9 , 2, 8, 4, 0, 3 }, i, j=0,indice=1;
	for (i=0;i<=9;i++){
		printf("%d ",j+indice);
		j=v[j]-indice;
	}

	
}
int cria_matriz_aleatoria(int n, int matriz[n][n], int max){
// pre:recebe um inteiro com o tamanho da matriz quadrada e a propria matriz o o range maximo do sorteio aleatório
// pos:retorna a matriz preenchida com os valores aleatório preenchidos
	int v[n],i,j;
	for (j=0;j<n;j++){
		criar_vetor_aleatorio(v,n,max);
		for (i=0;i<n;i++){
			matriz[j][i]=v[i];
		}	
	}
	return 0;	
}

int retorna_maior_valor(int n, int *l, int *c, int matriz[n][n]){
// pre:recebe um inteiro com o tamanho da matriz quadrada, o endereço da variavel do endereço da linha e da coluna com o maior valor da matriz, respectivamente, e a propria matriz
// pos:retorna o maior valor
	int i,j;
	*l=0;
	*c=0;
	for(i=0;i<n;i++){
		for (j=0;j<n;j++){
			if (matriz[*l][*c]<matriz[i][j] ){
				*c=j;
				*l=i;
			}
		}
	}
	return matriz[*l][*c];
}
void imprime_matriz(int n,int v[n][n]){
// pre:recebe um inteiro com o tamanho da matriz quadrada e a matriz
// pos:imprime a matriz
	int i,j;
	for (i=0; i<n;i++){
		printf("%2d|",i);
		imprime_vetor(v[i],n);
	}
}
void exercicio16(){
	int matriz[MAX16][MAX16],i,j,max;
	cria_matriz_aleatoria(MAX16,matriz,1000);
	imprime_matriz(MAX16,matriz);
	max=retorna_maior_valor(MAX16,&j,&i,matriz);
	printf("Linha=%2d\nColuna=%2d\nValor=%3d\n",j,i,max);
}
int criar_matriz_diagonal(int n, int matriz[n][n]){
// pre:recebe um inteiro com o tamanho da matriz quadrada e a matriz
// pos:cria uma matriz diagonal unitária
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if (i==j) {
				matriz[j][i]=1;
			}
			else{
				matriz[j][i]=0;
		}
		}
	}
	return 0;
}
void exercicio17(){
	int matriz[MAX17][MAX17];
	criar_matriz_diagonal(MAX17,matriz);
	imprime_matriz(MAX17,matriz);
}

int escolhe_maior(int n,int v1[n][n],int v2[n][n],int v3[n][n]){
// pre:recebe um inteiro com o tamanho das matrizes quadradas tres matrizes
// pos:retorna o maior valor das matrizes 1 e 2 na matriz 3 para cada posição delas respectivamente
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if (v1[j][i]>v2[j][i]) {
				v3[j][i]=v1[j][i];
			}
			else{
				v3[j][i]=v2[j][i];
		}
		}
	}
	return 0;
}

void exercicio18(){
	int m1[MAX18][MAX18],m2[MAX18][MAX18],m3[MAX18][MAX18],i,j;
	cria_matriz_aleatoria(MAX18,m1,1000);
	cria_matriz_aleatoria(MAX18,m2,1000);
	imprime_matriz(MAX18,m1);
	printf("\n");
	imprime_matriz(MAX18,m2);
	escolhe_maior(MAX18,m1,m2,m3);
	printf("\n");
	imprime_matriz(MAX18,m3);
}
int procura_valor_maior(int n, int v[n][n],int pos[(n*n)][2], int p){
	int i,j,k=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if (v[i][j]>p){
				pos[k][0]=i;
				pos[k][1]=j;
				k++;
			}
		}
	}
	return k;
}
void exercicio19(){
	int pos[(MAX19*MAX19)][2],m1[MAX19][MAX19],nmax,i,j,k=10;
	cria_matriz_aleatoria(MAX19,m1, 15);
	imprime_matriz(MAX19,m1);
	nmax=procura_valor_maior(MAX19, m1, pos, k);
	printf("Foram encontrados %d numeros maiores que %d:\n",nmax,k);
	for (i=0;i<nmax;i++){
		printf("%2d)Linha=%3d Coluna=%3d\n",i+1,pos[i][0],pos[i][1]);	
	}
}
int procura_valor_exato(int n, int v[n][n],int pos[(n*n)][2], int p){
	int i,j,k=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if (v[i][j]==p){
				pos[k][0]=i;
				pos[k][1]=j;
				k++;
			}
		}
	}
	return k;
}
void exercicio20(){
	int pos[(MAX20*MAX20)][2],m1[MAX20][MAX20],nmax,i,j,k;
	cria_matriz_aleatoria(MAX20,m1, 15);
	imprime_matriz(MAX20,m1);
	printf("Digite o numero que quer buscar na matriz:\n");
	scanf("%d",&k);
	nmax=procura_valor_exato(MAX20, m1, pos, k);
	if (nmax>0) {
		printf("Foram encontrados %d numeros iguais a %d:\n",nmax,k);
		for (i=0;i<nmax;i++){
			printf("%2d)Linha=%3d Coluna=%3d\n",i+1,pos[i][0],pos[i][1]);	
		}
	}
	else printf("Não foi encontrado o numero %d.",k);
	}

int troca_1linha_4coluna(int n,int m[n][n]){
	int i,aux[n];
	for (i=0;i<n;i++){
		aux[i]=m[0][i];
	}
	for (i=0;i<n;i++){
		m[0][i]=m[i][3];
	}
	for (i=0;i<n;i++){
		m[i][3]=aux[i];
	}
	return 0;
}
void exercicio21(){
	int m[MAX21][MAX21];
	cria_matriz_aleatoria(MAX21,m, 15);
	imprime_matriz(MAX21,m);
	printf("\n");
	troca_1linha_4coluna(MAX21,m);
	imprime_matriz(MAX21,m);
}
int matriz_triangular_inferior_unitaria(int n, int m[n][n]){
	int i,j;
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			if (i>=j) m[i][j]=1;
			else m[i][j]=0;
		}
	}
	return 0;
}

int multiplica_matriz(int n, int m1[n][n], int m2[n][n],int m3[n][n]){
	int i,j;
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			m3[i][j]=m1[i][j]*m2[i][j];
		}
	}
	return 0;
}
void exercicio22(){
	int m1[MAX22][MAX22],m2[MAX22][MAX22],m3[MAX22][MAX22],i,j;
	cria_matriz_aleatoria(MAX22,m1, 15);
	imprime_matriz(MAX22,m1);
	matriz_triangular_inferior_unitaria(MAX22, m2);
	multiplica_matriz(MAX22, m1, m2, m3);
	printf("\n");
	imprime_matriz(MAX22,m3);
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	srand( (unsigned)time(NULL) );
	//exercicio1();
	exercicio2();
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
	//exercicio13();
	//exercicio14();
	//exercicio15();
	//exercicio16();
	//exercicio17();
	//exercicio18();
	//exercicio19();
	//exercicio20();
	//exercicio21();
	//exercicio22();
	return 0;
}

