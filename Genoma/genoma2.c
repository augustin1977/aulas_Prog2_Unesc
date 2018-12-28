#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 15001
#define ML 50
typedef struct genoma{ 
		char p[ML];
		char pinv[ML]; 
		char t[MAX];
		int direto[ML];
		int inverso[ML];
		int m;
		int n;
	} genoma; 
void imprime_sequencias(genoma g[ML],int m){
//pre: Recebe a matriz e o numero de registros
//pos: Faz a gravação dos dados no arquivo de saida genoma.out
	int i=0,j,n;
	FILE *arq; 
	if (!(arq=fopen("GENOMA.OUT","w"))){ 
		printf("Erro no arquivo");
	}
	else{ 
		arq=fopen("GENOMA.OUT","w");
		for (j=0;j<m;j++){
			fprintf(arq,"Teste %d\n",j+1);
			fprintf(arq,"Ocorrencia Direta:");
			if (g[j].direto[0]==0) fprintf(arq," 0");
			else for (i=1;i<g[j].direto[0]+1;i++) fprintf(arq," %d",g[j].direto[i]);
			fprintf(arq,"\nOcorrencia Complementar Invertida:");
			if (g[j].inverso[0]==0) fprintf(arq," 0");
			else for (i=1;i<g[j].inverso[0]+1;i++) fprintf(arq," %d",g[j].inverso[i]);
			fprintf(arq,"\n\n");
		}
	fclose(arq);
	}
}	
int inverte(genoma g[ML],int l){// inverte a sequencia
// pre: Recebe a matriz com os dados e a linha que deve ser invertida
// pos: retorna a matriz com vetor pinv preenchido e um inteiro sendo 0=sem erro e 1=caracter não reconhecido
	int i,j, erro=0; // declara as variaveis
	for (i=0;i<g[l].m; i++){ // percorre todos os caracteres da sequencia 
		if (g[l].p[i]=='A') g[l].pinv[g[l].m-i-1]='T'; // preenche com os caracteres complementares
		else if (g[l].p[i]=='T') g[l].pinv[g[l].m-i-1]='A'; // preenche com os caracteres complementares
		else if (g[l].p[i]=='C') g[l].pinv[g[l].m-i-1]='G'; // preenche com os caracteres complementares
		else if (g[l].p[i]=='G') g[l].pinv[g[l].m-i-1]='C'; // preenche com os caracteres complementares
		else { // caso nenhum caracter conhecido seja encontrado 
			erro= 1; //altera a variavel para erro=1 para indicar que houve um erro
		}
	}
	if (erro==1){ // caso de erro
		for (j=0;j<g[l].m;j++){ // percore todos as posições
				g[l].pinv[j]=0; // preenche todas as posições de pinv com 0
				g[l].p[j]=0; // preenche todas as posições p com 0
			}
	}
	return erro;	//retorna erro
}

int carrega_genoma(genoma g[ML]){
// pre: recebe a matriz genoma e preenche com os dados do arquivo genoma.in que está na mesma pasta
// pos: Retorna a matriz preenchia e o numero de registros encontrado
	int i=0,a; // declara as variaveis 
	FILE *arq; // declara a vairavel do tipo arquivo (FILE)
	if (!(arq=fopen("GENOMA.IN","r"))){  // Verifica se o arquivo existe e pode ser aberto
		printf("Erro no arquivo"); // em caso de erro informa mensagem de erro
	}
	else{ 
		arq=fopen("GENOMA.IN","r");// caso contrario abre o arquivo
		fscanf(arq,"%d %d \n",&g[i].m,&g[i].n); // le a primeira linha e guarda os valores de m e n
		while(g[i].m>0 && g[i].n>0){  // repete o laço enquanto m>0 e n>0
			fscanf(arq,"%s\n",&g[i].p); // lê o vetor de procura p
			fscanf(arq,"%s\n",&g[i].t); // le o vetor t onde o vetor p será procutado
			a=inverte(g,i); // chama a função inverte e preenche o resutado no vetor pinv
			if (a!=0) {
				printf("Sequencia de caracteres incorreta no teste %d\n",i+1);
			}
			i++; // incrementa i para ler a proxima linha e preencher os proximos vetores da matriz
			fscanf(arq,"%d %d",&g[i].m,&g[i].n); // le m e n novamente para reiniciar o ciclo.
		}
	fclose(arq); // fecha o arquivo
	}
return i; // retorna o numero de registros encontrados no arquivo
}
void busca_sequencia_direta(genoma g[ML], int l){
//pre: Recebe a matriz g e o numero da linha onde ira fazer busca do valor de p no vetor t
//pos: Retorna dirreto preenchido com o numero de ocorrencias na primeira posição e a posição das ocorrencias nas demais posições
	int i,j=0,k=0,n1=0;
	for (i=0; i<g[l].n;i++){  // faz a busca em todas as posições da sequencia recebida
		if (g[l].t[i]==g[l].p[j]){ // se a letra for igual
			//printf("Letra l=%d j=%d k=%d i=%d\n g[%d].m=%d",l,j,k,i,l,g[l].m);
			j++; // incrementa a contagem da posição do valor buscado
			k++; // incrementa o numero de letras coincidentes encontradas
			if (k==g[l].m) { // se o numero de letras encontrados foi igual ao comprimento do vetor procurado então...
				g[l].direto[n1+1]=i-k+2; // grava a primeira posição da ocorrencia, deixando a primeira posição do vetor vazia
				n1++; // incrementa o numero de sequencias encontradas
			}
		}
		else{ // senão
			j=0; // zera os contadores de posição do vetor procurado
			k=0; // zera o numero de letras encontradas
			if (g[l].t[i]==g[l].p[j]){ // se a letra atual for igual a primeira letra da sequencia procurada então...
				j++; // incrementa a contagem da posição
				k++; // incrementa o numero de letras coincidentes encontradas
			}
		}
		
	}
	g[l].direto[0]=n1; // grava na primeira posição do vetor direto o numero de ocorrencias encontradas
}
void busca_sequencia_inversa(genoma g[ML], int l){
//pre: Recebe a matriz g e o numero da linha onde ira fazer busca do valor de pinv no vetor t
//pos: Retorna inverso preenchido com o numero de ocorrencias na primeira posição e a posição das ocorrencias nas demais posições
	int i,ji=0,ki=0,n2=0;
	for (i=0; i<g[l].n;i++){ // faz a busca em todas as posições da sequencia recebida
		if (g[l].t[i]==g[l].pinv[ji]){ // se a letra for igual
			ji++; // incrementa a contagem da posição do valor buscado
			ki++; // incrementa o numero de letras coincidentes encontradas
			if (ki==g[l].m) { // se o numero de letras encontrados foi igual ao comprimento do vetor procurado então...
				g[l].inverso[n2+1]=i-ki+2; // grava a a primeira posição da ocorrencia, deixando a primeira posição do vetor vazia
				n2++; // incrementa o numero de sequencias encontradas
			}
		}
		else{ // senão
			ji=0; // zera os contadores de posição do vetor procurado
			ki=0; // zera o numero de letras encontradas
			if (g[l].t[i]==g[l].pinv[ji]){ // se a letra atual for igual a primeira letra da sequencia procurada então...
				ji++; // incrementa a contagem da posição
				ki++; // incrementa o numero de letras coincidentes encontradas
			}
		}
	}
	g[l].inverso[0]=n2; // grava na primeira posição  do vetro inverso o numero de ocorrencias encontradas
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	genoma g[ML];
	int n,m;
	int i,j;
	//scanf("%d",&j);
	m=carrega_genoma(g);
	for (j=0;j<m;j++){
		busca_sequencia_direta(g,j);
		busca_sequencia_inversa(g,j);
	}
	imprime_sequencias(g,m);
	/*
	---- Teste das funções -----
	printf("Teste %d\n",j+1);
	n=busca_sequencia_direta(g,j);
	printf("\nOcorrencia Direta:");
	if (n==0) printf(" 0");
	else for (i=0;i<n;i++) printf(" %d",g[j].direto[i]);
	---- fim do teste das fuções -----
	*/
	return 0;
}

