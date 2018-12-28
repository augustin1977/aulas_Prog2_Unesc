#include <stdio.h>
#include<stdlib.h>
#include <locale.h>
#define TAM 3
int tab[TAM][TAM];
int ganhador(int jogador){
	int retorno;
	if (tab[0][0]==jogador && tab[0][1]==jogador && tab[0][2]==jogador) retorno=0;
	else if (tab[1][0]==jogador && tab[1][1]==jogador && tab[1][2]==jogador) retorno=0;
	else if (tab[2][0]==jogador && tab[2][1]==jogador && tab[2][2]==jogador) retorno=0;
	else if (tab[0][0]==jogador && tab[1][1]==jogador && tab[2][2]==jogador) retorno=0;
	else if (tab[0][0]==jogador && tab[1][0]==jogador && tab[2][0]==jogador) retorno=0;
	else if (tab[0][1]==jogador && tab[1][1]==jogador && tab[2][1]==jogador) retorno=0;
	else if (tab[0][2]==jogador && tab[1][2]==jogador && tab[2][2]==jogador) retorno=0;
	else if (tab[2][0]==jogador && tab[1][1]==jogador && tab[0][2]==jogador) retorno=0;
	else retorno=1;
	return retorno;
}

int jogada(int jogador){
	int linha,coluna,valido=1;
	while(valido){
		printf("Jogador %d\n",jogador);
		printf("Digite a linha:\n");
		scanf("%d",&linha);
		printf("Digite a coluna:\n");
		scanf("%d",&coluna);
		linha--;
		coluna--;
		if (tab[linha][coluna]==0) valido=0;
		else printf("Jogada invalida!!\nJogue novamente!!!\n");
	}
	tab[linha][coluna]=jogador;
}
void imprime_tab(){
	int i,j;
	printf("  1 2 3\n-------\n");
	for (i=0;i<TAM;i++){
		printf("%d| ",i+1);
		for(j=0;j<TAM;j++){
			printf("%d ",tab[i][j]);
		}
		printf("\n");
	}
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	int i,j,n=0,jogador=1,res;
	printf("Deseja Jogar? (1=sim/2=não)\n");
	scanf("%d",&res);
	while(res==1){
		for (i=0;i<TAM;i++){
			for(j=0;j<TAM;j++){
				tab[i][j]=0;
			}
		}	
		
		while(ganhador(jogador)&&n<9){
			system("cls");
			imprime_tab();
			jogador=n%2+1;
			jogada(jogador);
			n++;
		}
		system("cls");
		imprime_tab();	
		if(n!=9) printf("O jogador %d ganhou\n",jogador);
		printf("O jogo empatou\n");
		printf("Deseja Jogar novamente? (1=sim/2=não)\n");
		scanf("%d",&res);
	}
	return 0;
}

