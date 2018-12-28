#include "funcoes.h"
int main(){
	setlocale(LC_ALL,"");// define o conjuntos de caracteres do SO para poder usar acentos e outros caracteres da lingua local
	agenda a[MAX]; // declara a variavel a como sendo uma variavel do tipo agenda declarada como um vetor de 100 posições
	int j,i,zera_tela=0,n=0,opcao=9;// declara um contador n com o numero de registros  e a variavel opcao para controlar a opcao do usuário
	limpa(a);// limpa a agenda apara evitar lixos da memória;
	while (opcao!=8){
		n=conta(a); // verifica o numero de registros da agenda
		//listar_tudo(a);
		opcao=menu(zera_tela,n); // chama a função menu e aguarda o retorno de um inteiro com a função selecionada pelo usuário
		if (opcao==1){ // verifica se  opção chamada é a de inserir registro
		printf("Escolheu a opção 1 - inserir registro\n");
			insere_registro(a); //chama a função para inserir o registro
			zera_tela=1; // apaga a tela ao final do procedimento
		} else if (opcao==2){ // verifica se a opção chamada é a de editar registro
			printf("Opção 2 - editar registro\n");
			edita_registro(a); // chama a função para editar o registro
			zera_tela=1; // apaga a tela ao final do procedimento
		} else if (opcao==3){// verifica se a opção chamada é a de excluir registro
			printf("Opção 3 - excluir registro\n");	
			exclui_registro(a); // chama a função para excluir o registro
			zera_tela=1; // apaga a tela ao final do procedimento
		} else if (opcao==4){ // verifica se a opção chamada é a de listar contatos
			system("cls"); // apagua a tela
			printf("Opção 4 - listar todos contatos\n");
			listar_registros(a,-1); // lista os registros 
			zera_tela=0; // não apaga a tela ao final do procedimento
		} else if (opcao==5){ // verifica se a opção chamada é a de exibir contato
			system("cls"); // limpa tela
			printf("Opção 5 - exibir contato\n");
			listar_1registro(a); // lista um unico registro
			zera_tela=0; // não apaga a tela ao final do procedimento
		} else if (opcao==6){ // verifica se a opção chamada é a de salvar contatos no disco
			printf("Opção 6 - salvar contatos no disco\n");
			zera_tela=1; // apaga a tela ao final do procedimento
			salva_registros(a); // chama a função que salva os registros
		} else if (opcao==7){ // verifica se a opção chamada é a de carregar contatos do disco
			printf("Opção 7 - carregar contatos do disco\n");
			carrega_registro(a); // chama a função para carregar os registros do disco
			zera_tela=1; // apaga a tela ao final do procedimento
		} else { printf("Saindo do programa....\n"); // encerra o programa
		}
	}
	return 0;
}

