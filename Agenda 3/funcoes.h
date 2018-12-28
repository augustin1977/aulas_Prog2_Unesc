#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 100 // define o numero maximo de registros da agenda
#define MAXNOME 31 // define o comprimento máximo do nome em 30 caacteres

typedef struct agenda{ // define a variavel agenda como sendo do tipo struct
	int usa;
	char nome[MAXNOME]; // define variavel nome como um string de 100 caracteres dentro da struct agenda
	int telefone; // define a variavel telefone como um string de 15 caracteres dentro da struct agenda
} agenda;

int menu(int z, int k);
// pre: função que exibe na tela o menu de seleção e recebe z e k, sendo,k o numero de registros da agenda e z limpa a tela caso z=1 o unão limpa caso z!=0
// pos: retorna a opção escolhida

int busca_vazio(agenda a[MAX]);
//pre: Recebe um vetor do tipo agenda
//pos: retorna indice do primeiro endereço vazio
	
void limpa(agenda a[MAX]);
//pre: Recebe um vetor do tipo agenda
//pos: limpa a memoria de todo o lixo	

void insere_registro(agenda a[MAX]);
// pre: Recebe o vetor do tipo agenda 
// pos: busca uma posição vazia e insere o registro digitado

int conta(agenda a[MAX]);
//pre: Recebe um vetor do tipo agenda
//pos: Retorna o numero de registros ativos


void listar_registros(agenda a[MAX], int k);
//pre: Recebe o vetor do tipo agenda o um inteiro k
//pos: imprime todos os registros se k=-1 , nada se k>MAX ou o registro de numero k

void listar_1registro(agenda a[MAX]);
//pre: recebe um vetor do tipo agenda e uma entrada do teclado
//pos: busca o registro digitado pelo usuário e chama a função listar_registro para  mostrar na tela o registro desejado

void salva_registros(agenda a[MAX]);
//pre: recebe um vetor do tipo agenda
//pos: grava esse vetor no arquivo agenda.txt no formato CSV

void carrega_registro(agenda a[MAX]);
//pre: recebe um vetor do tipo agenda
//pos: Lê os dados do arquivo no arquivo agenda.txt para o esse vetor recebido


int busca_registro(char nome[MAXNOME],agenda a[MAX]);
//pre: recebe o nome a ser buscado no vetor, o vetor da busca e o numero de registros
//pos: retorna o numero do registro buscado ou -1 em caso de erro

void exclui_registro(agenda a[MAX]);
//pre: Recebe agenda e o numero de registros
//pos: Retorna a agenda com a exclusão do item desejado


void edita_registro(agenda a[MAX]);
//pre: Recebe agenda e do teclado o nome e o telefone a serem alterados
//pos: Retorna a agenda com a as alterações desejadas


void listar_tudo(agenda a[MAX]);
//pre: Recebe o vetor do tipo agenda 
//pos: imprime todos os registros independete da variavel usa - usado apenas para eliminação de bugs do sistema

