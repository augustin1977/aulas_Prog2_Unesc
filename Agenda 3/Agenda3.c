#include "funcoes.h"
int main(){
	setlocale(LC_ALL,"");// define o conjuntos de caracteres do SO para poder usar acentos e outros caracteres da lingua local
	agenda a[MAX]; // declara a variavel a como sendo uma variavel do tipo agenda declarada como um vetor de 100 posi��es
	int j,i,zera_tela=0,n=0,opcao=9;// declara um contador n com o numero de registros  e a variavel opcao para controlar a opcao do usu�rio
	limpa(a);// limpa a agenda apara evitar lixos da mem�ria;
	while (opcao!=8){
		n=conta(a); // verifica o numero de registros da agenda
		//listar_tudo(a);
		opcao=menu(zera_tela,n); // chama a fun��o menu e aguarda o retorno de um inteiro com a fun��o selecionada pelo usu�rio
		if (opcao==1){ // verifica se  op��o chamada � a de inserir registro
		printf("Escolheu a op��o 1 - inserir registro\n");
			insere_registro(a); //chama a fun��o para inserir o registro
			zera_tela=1; // apaga a tela ao final do procedimento
		} else if (opcao==2){ // verifica se a op��o chamada � a de editar registro
			printf("Op��o 2 - editar registro\n");
			edita_registro(a); // chama a fun��o para editar o registro
			zera_tela=1; // apaga a tela ao final do procedimento
		} else if (opcao==3){// verifica se a op��o chamada � a de excluir registro
			printf("Op��o 3 - excluir registro\n");	
			exclui_registro(a); // chama a fun��o para excluir o registro
			zera_tela=1; // apaga a tela ao final do procedimento
		} else if (opcao==4){ // verifica se a op��o chamada � a de listar contatos
			system("cls"); // apagua a tela
			printf("Op��o 4 - listar todos contatos\n");
			listar_registros(a,-1); // lista os registros 
			zera_tela=0; // n�o apaga a tela ao final do procedimento
		} else if (opcao==5){ // verifica se a op��o chamada � a de exibir contato
			system("cls"); // limpa tela
			printf("Op��o 5 - exibir contato\n");
			listar_1registro(a); // lista um unico registro
			zera_tela=0; // n�o apaga a tela ao final do procedimento
		} else if (opcao==6){ // verifica se a op��o chamada � a de salvar contatos no disco
			printf("Op��o 6 - salvar contatos no disco\n");
			zera_tela=1; // apaga a tela ao final do procedimento
			salva_registros(a); // chama a fun��o que salva os registros
		} else if (opcao==7){ // verifica se a op��o chamada � a de carregar contatos do disco
			printf("Op��o 7 - carregar contatos do disco\n");
			carrega_registro(a); // chama a fun��o para carregar os registros do disco
			zera_tela=1; // apaga a tela ao final do procedimento
		} else { printf("Saindo do programa....\n"); // encerra o programa
		}
	}
	return 0;
}

