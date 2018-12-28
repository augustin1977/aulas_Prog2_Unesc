#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 1500
#define ML 50
typedef struct genoma{ 
		char p[MAX];
		char pinv[MAX]; 
		char t[MAX];
		int direto[ML];
		int inverso[ML];
		int m;
		int n;
	} genoma; 
void imprime_sequencias(genoma g[ML],int m){
	int i=0,j,n;
	FILE *arq; 
	if (!(arq=fopen("GENOMA.OUT","w"))){ 
		printf("Erro no arquivo");
	}
	else{ 
		arq=fopen("GENOMA.OUT","w");
		for (j=0;j<m;j++){
			fprintf(arq,"Teste %d\n",j+1);
			n=busca_sequencia_direta(g,j);
			fprintf(arq,"Ocorrencia Direta:");
			if (n==0) fprintf(arq," 0");
			else for (i=0;i<n;i++) fprintf(arq," %d",g[j].direto[i]);
			fprintf(arq,"\nOcorrencia Complementar Invertida:");
			n=busca_sequencia_inversa(g,j);
			if (n==0) fprintf(arq," 0");
			else for (i=0;i<n;i++) fprintf(arq," %d",g[j].inverso[i]);
			fprintf(arq,"\n\n");
	}
	fclose(arq);
	}
}	
int inverte(genoma g[ML],int l){
	int i, erro=0;
	for (i=0;i<g[l].m; i++){
		if (g[l].p[i]=='A') g[l].pinv[g[l].m-i-1]='T';
		else if (g[l].p[i]=='T') g[l].pinv[g[l].m-i-1]='A';
		else if (g[l].p[i]=='C') g[l].pinv[g[l].m-i-1]='G';
		else if (g[l].p[i]=='G') g[l].pinv[g[l].m-i-1]='C';
		else {
			erro= 1;
		}
	}
	return erro;	
}

int carrega_genoma(genoma g[ML]){
	int i=0,a;
	FILE *arq; 
	if (!(arq=fopen("GENOMA.IN","r"))){ 
		printf("Erro no arquivo");
	}
	else{ 
		arq=fopen("GENOMA.IN","r");
		fscanf(arq,"%d %d \n",&g[i].m,&g[i].n);
		while(g[i].m>0 && g[i].n>0){ 
			fscanf(arq,"%s\n",&g[i].p);
			fscanf(arq,"%s\n",&g[i].t); 
			a=inverte(g,i);
			i++; 
			fscanf(arq,"%d %d",&g[i].m,&g[i].n);
		}
	fclose(arq);
	}
return i;
}
int busca_sequencia_direta(genoma g[ML], int l){
	int i,j=0,k=0,n1=0;
	for (i=0; i<g[l].n;i++){
		if (g[l].t[i]==g[l].p[j]){
			//printf("Letra l=%d j=%d k=%d i=%d\n g[%d].m=%d",l,j,k,i,l,g[l].m);
			j++;
			k++;
			if (k==g[l].m) {
				g[l].direto[n1]=i-k+2;
				n1++;
			}
		}
		else{
			j=0;
			k=0;
			if (g[l].t[i]==g[l].p[j]){
				j++;
				k++;
			}
		}
		
	}
	return n1;
}
int busca_sequencia_inversa(genoma g[ML], int l){
	int i,ji=0,ki=0,n2=0;
	for (i=0; i<g[l].n;i++){
		if (g[l].t[i]==g[l].pinv[ji]){
			ji++;
			ki++;
			if (ki==g[l].m) {
				g[l].inverso[n2]=i-ki+2;
				n2++;
			}
		}
		else{
			ji=0;
			ki=0;
			if (g[l].t[i]==g[l].pinv[ji]){
				ji++;
				ki++;
			}
		}
	}
	return n2;
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	genoma g[ML];
	int n,m;
	//int i,j;
	//scanf("%d",&j);
	m=carrega_genoma(g);
	imprime_sequencias(g,m);
	/*0
	printf("Teste %d\n",j+1);
	n=busca_sequencia_direta(g,j);
	printf("\nOcorrencia Direta:");
	if (n==0) printf(" 0");
	else for (i=0;i<n;i++) printf(" %d",g[j].direto[i]);
	*/
	
	
	
	return 0;
}

