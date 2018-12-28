#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#define MAX 5000 // define o maximo numero de jogadores
#define MCART 10 // define o comprimento máximo ddas cartelas
#define MAXNOME 30 // define o tamanho maximo do nome
#define M 50 // numero bolas a serem sorteados
#define classes 10 // define classes de tamanho 10
typedef struct jogo{ // define a variavel agenda como sendo do tipo struct
	char nome[MAXNOME]; // define variavel nome como um string de 100 caracteres dentro da struct agenda
	int aposta; // define a aposta
	int cartela[MCART];
	int vencedor;
} jogo;

void organiza_cartela(jogo jogador[MAX], int n){
	int i,j,t;
	for (i=0;i<MCART;i++){
		for (j=0;j<i;j++){
					if (jogador[n].cartela[i]<jogador[n].cartela[j]){
						t=jogador[n].cartela[i];
						jogador[n].cartela[i]=jogador[n].cartela[j];
						jogador[n].cartela[j]=t;
				}
		}
	}
}
void sorteia_cartela(jogo jogador[MAX],int n){
	int i,j,k,t,igual,c=0;
	//recebe todos os jogadores e o numero da cartela que será sorteada
	t=(M/classes);
	//printf("%d",t);
	for(i=0;i<MCART;i++){
		
		if (i%(MCART/t)==0 && i>0){
			c+=classes;
		}
		// Sorteio de numeros não repetidos
		igual=1;
		while(igual){
			igual=0;
			jogador[n].cartela[i]=(rand()%classes)+1+c;
			for(j=0;j<i;j++){
				if (jogador[n].cartela[i]==jogador[n].cartela[j]) igual=1;
			}
		}
		
	}
	jogador[n].vencedor=0;
}

void monta_cartelas(jogo jogador[MAX], int n){
	int i,j;
	for(j=0;j<n;j++){
		sorteia_cartela(jogador,j);
		organiza_cartela(jogador,j);
	}
	//system("pause");
	
}
void imprime_cartelas(jogo jogador[MAX],int n){
	int i,j;
	for(j=0;j<n;j++){
		for(i=0;i<MCART;i++){
			printf("%2d ",jogador[j].cartela[i]);
		}
		printf("%s ",jogador[j].nome);
		if (jogador[j].vencedor==-1) printf("Está por uma bola! \n");
		else if (jogador[j].vencedor==1) printf( "VENCEDOR !!!! \n");
		else printf("\n");
		
	}
}
int sorteio(int bolas[M], int n){
	int sorteado,i,repete=1;
	while(repete){
		sorteado=(rand()%M)+1;
		repete=0;
		for (i=0;i<n;i++){
			if(sorteado==bolas[i]) repete=1;
		}	
	}
	return sorteado;
}

int verifica_vencedor(jogo jogador[MAX],int sorteado, int n){
	int i,j,soma,vencedor=0;
	for (i=0;i<n;i++){
		soma=0;
		for(j=0;j<MCART;j++){
			if (jogador[i].cartela[j]==sorteado) {
				jogador[i].cartela[j]=0;
				//organiza_cartela(jogador,i);
			}
			soma=soma+(jogador[i].cartela[j]!=0);
		}
		 if (soma==0) {
			jogador[i].vencedor=1;
			vencedor=1;
		} else if (soma==1){
			jogador[i].vencedor=-1;
		} 
	}
	return vencedor;
}
void cartelas(jogo jogador[MAX], int n){
	FILE *f;
	int i,j,t,k=0;
	
	f=fopen("cartelas.dat","w");
	t=(M/classes);
	for(j=0;j<n;j++){
		k=0;
		fprintf(f,"%s \nB ",jogador[j].nome);
		for(i=0;i<MCART;i++){
			//printf("MCART/t=%d i=%d k=%d",MCART/t,i, k);
			//system("pause");
			if ((i+1)%(MCART/t)==0 && i>0) k++;
			else if (k==1) fprintf(f,"\nI ");
			else if (k==2) fprintf(f,"\nN ");
			else if (k==3) fprintf(f,"\nG ");
			else if (k==4) fprintf(f,"\nO ");
			else if (k>4) fprintf(f,"\n ");
			fprintf(f,"%2d ",jogador[j].cartela[i]);
		}
		fprintf(f,"\n-------------------------------------\n");	
	}
	fclose(f);
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	char a;
	char nome[100];
	jogo jogador[MAX];
	int i,j,bolas[M],vencedor=0,sorteado,n=0,numero_jogadores=MAX+1,total_apostado=0;
	srand(time(NULL));
	while(numero_jogadores>MAX){
		printf("Quantos jogadores?\n");
		scanf("%d",&numero_jogadores);
	}
	monta_cartelas(jogador,numero_jogadores);
	for (i=0;i<numero_jogadores;i++) {
		strcpy(nome,"");
		strcpy(jogador[i].nome,"Jogador ");
		//jogador[i].aposta=1;
		//printf("Digite o nome do jogador %d: ",i+1);
		//scanf("%s",&jogador[i].nome);
		itoa(i+1,nome,10);
		strcat(jogador[i].nome,nome);
		//printf("Entre com a aposta: ");
		//scanf("%d",&jogador[i].aposta);
		jogador[i].aposta=1;
		total_apostado=total_apostado+jogador[i].aposta;
	}
	printf("O total apostado foir de %d\n",total_apostado);
	//imprime_cartelas(jogador,numero_jogadores);
	cartelas(jogador,numero_jogadores);
	printf("Sorteando Cartelas...\n Pressione uma tecla para iniciar...\n");
	getch();
	while(vencedor==0){
		system("cls");
		sorteado=sorteio(bolas,n);
		bolas[n]=sorteado;
		printf("Bola Sorteada: ");
		for (i=0;i<=n;i++) printf("%d ",bolas[i]);
		printf("\n");
		//imprime_cartelas(jogador,numero_jogadores);
		getch();
		n++;
		vencedor=verifica_vencedor(jogador,sorteado, numero_jogadores);
		
	}
	//printf("\n");
	system("cls");
	printf("Bola Sorteada: ");
	for (i=0;i<n;i++) printf("%d ",bolas[i]);
	printf("\n");
	imprime_cartelas(jogador,numero_jogadores);
	j=0;
	for (i=0;i<numero_jogadores;i++){
		if (jogador[i].vencedor==1) {
			printf("\nA cartela %d é vencedora e o nome do vencedor é %s\n",i+1,jogador[i].nome);
			j++;
		}
	}
	if (j==1) printf("O vencedor ganhará %d\n",total_apostado/j);
	else printf("Cada vencedor ganhará %d\n",total_apostado/j);
	return 0;
}
