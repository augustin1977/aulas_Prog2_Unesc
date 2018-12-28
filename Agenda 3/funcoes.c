#include "funcoes.h"

int menu(int z, int k){
	// pre: função que exibe na tela o menu de seleção e recebe z, caso z=1 limpa tela
	// pos: retorna a opção escolhida
	int opcao=0; // variavel onde será armazenada a função escolhida
	int n=0; // contador de numero de tentativas de escolha da função
	while(opcao>8 || opcao<1){ // loop para garatir que será digitada uma função valida
		if(z==1) system("cls"); // apaga a tela para manter o ambiente limpo para o usuário caso seja pedido a função
		printf("----Agenda de telefones----\nA agenda ja possui %d registros\nEscolha a opção desejada:\n",k);// impressão do menu
		printf("1) Inserir contato\n");// impressão do menu
		printf("2) Editar um contato existente\n");// impressão do menu
		printf("3) Excluir um contato existente\n");// impressão do menu
		printf("4) Listar todos os contatos\n");// impressão do menu
		printf("5) Exibir um contato na tela\n");// impressão do menu
		printf("6) Salvar os contatos no disco\n");// impressão do menu
		printf("7) Carregar contatos do disco\n");// impressão do menu
		printf("8) Sair\n");// impressão do menu
		if (n>0) printf("Opção incorreta!\nTente novamente!!\n"); // verificação de erro de digitação, se contador meior que 0 significa que ja houve erro
		scanf("%d",&opcao); // leitura da opção
		n++;// contador de numero de vezes tentadas
	}
	return opcao; // retorna a opção digitada
}
int busca_vazio(agenda a[MAX]){
//pre: Recebe um vetor do tipo agenda
//pos: retorna indice do primeiro endereço vazio
	int i=0;
	while(a[i].usa==1 && i<MAX){// busca a primeira posição vazia
		i++;// incrementa o contador
	}
	return i;	
}	
void limpa(agenda a[MAX]){
//pre: Recebe um vetor do tipo agenda
//pos: limpa a memoria de todo o lixo	
	int i;//declara a variavel contadora
	for (i=0;i<MAX;i++){ // passa todos os registros do vetor agenda
		a[i].usa=0;// atribui a variavel usa=0
		a[i].telefone=0; // atribui telefone=0
		strcpy(a[i].nome,"0");// atribui nome="0"
	}
}
void insere_registro(agenda a[MAX]){
// pre: Recebe o vetor do tipo agenda 
// pos: busca uma posição vazia e insere o registro digitado
	int i;
	i=busca_vazio(a); // busca o primeiro indice vazio para inserir valor
	if (i<MAX){ // verifica se ha endereço vazio
		printf("Digite o nome:\n"); 
		scanf("%s",&a[i].nome); // entra com o nome do registro
		printf("Digite o telefone:\n");
		scanf("%d",&a[i].telefone); // entra com o telefone do registro
		a[i].usa=1;
	} else {
		printf("Numero maximo de registros atingidos\nNão é possivel cadastrar mais registros!!\n");
		system("pause")	;
	}
}
int conta(agenda a[MAX]){
//pre: Recebe um vetor do tipo agenda
//pos: Retorna o numero de registros ativos
	int i,n=0;
	for (i=0;i<MAX;i++){ // percorre todos os registros
		if (a[i].usa==1) n++; // incrementa o contados quando encontra um registro valido
	}
	return n; // retorna o numero de registros ativos
}

void listar_registros(agenda a[MAX], int k){
//pre: Recebe o vetor do tipo agenda o um inteiro k
//pos: imprime todos os registros se k=-1 , nada se k>MAX ou o registro de numero k
	if (k<=MAX){
		int i,n=0; // define o contador
		printf("Nome                 |   Telefone\n");//imprime o cabeçalho da tabela
		printf("----------------------------------------\n");//imprime o cabeçalho da tabela
		if (k==-1){
			for (i=0;i<MAX;i++){// Percorre todo o vetor
				if (a[i].usa==1) {
					printf("%-20s |   %d \n",a[i].nome, a[i].telefone);// imprime cada elemento do agenda
					n++; // incrementa o contador de registros impressos na tela
				}	
			}
		} else{
			printf("%-20s |   %d \n",a[k].nome, a[k].telefone);// imprime elemento k da agenda
			n++; // incrementa o contador de registros impressos na tela
		}
		
		printf("Foram listados %d registros\n\n",n);// imprime o numero de registros listados
	}
}
int busca_registro(char nome[MAXNOME],agenda a[MAX]){
// pre: recebe o nome a ser buscado no vetor, o vetor da busca e o numero de registros
// pos: retorna o numero do registro buscado ou -1 em caso de erro
	int i=0,k=-1; // define as variaveis i - contador e k - retorno da função e inicializa -1 que é o retorno da mesma caso não ache a string
	while ((a[i].usa==0 || strcmp(nome,a[i].nome)!=0) && (a[i].usa==0 || i<MAX)){ // busca a string até encontrar ou até chegar no fim do vetor
		//printf("%d procurando... %s \n",i,a[i].nome); // imprime o relatório de busca
		i++;// incrementa o contador da busca
	}
	if (a[i].usa==1 && strcmp(nome,a[i].nome)==0){// verifica se encontrou a string no vetor
		k=i;// informa a posição do vetor onde a string foi encontrada
		//printf("%d procurando... %s ... Achei!!! \n",i,a[i].nome); // imprime o a posição do vetor encontrado
	}
	return k;// retorna o valor da posição da string encontrada no vetor
}
void listar_1registro(agenda a[MAX]){
//pre: recebe um vetor do tipo agenda e uma entrada do teclado
//pos: busca o registro digitado pelo usuário e chama a função listar_registro para  mostrar na tela o registro desejado
	int i=-1,j=0,opt=-1,telefone; // Declara variaáveis sendo i o endereço do item a ser buscado, j contador para avaliar erro de digitação e opt é opçao de gravação da edição dos dados
	char nome[MAXNOME]; // declara as variaves que serão lidas do teclado
	while(i<0){
		if(j>0){ // verifica se houve erro
			 printf("Opção invalida ou nome inexistente!\n Tente novamente!");// imprime mensagem de erro
		}
		printf("Digite o nome do registro que quer buscar:\nCaso não listar nada digite 0. \n");
		scanf("%s",&nome);// le o nome a ser editado
		i=busca_registro(nome,a);// busca na memoria o registro a ser editado
		j++;
		if (strcmp(nome,"0")==0) i=MAX+1; // verifica se o usuário digitou 0 para não listar nada
		}
		//printf("%d",i);
	listar_registros(a,i); // chama a função para listar o registro desejado
}
void salva_registros(agenda a[MAX]){
//pre: recebe um vetor do tipo agenda
//pos: grava esse vetor no arquivo agenda.txt no formato CSV
	int i;
	FILE *arq; // declara o arquivo
	if (!(arq=fopen("agenda.txt","w"))){ // verifica se o arquivo esta disponivel
		printf("Erro no arquivo\n"); // imprime mensagem de erro
		system("pause");// aguardo 2 segundo para voltar ao menu
	}
	else{ // caso não ocorra erro 
		arq=fopen("agenda.txt","w");// abre o arquivo como gravação
	for (i=0;i<MAX;i++){// passa todos os registros
		fprintf(arq,"%d ; %s ; %d\n",a[i].usa,a[i].nome,a[i].telefone);// grava cada registro no arquivo
		//if (a[i].usa==1) fprintf(arq,"%d ; %s ; %d\n",a[i].usa,a[i].nome,a[i].telefone);// grava cada registro no arquivo
		}
	fclose(arq);// fecha o arquivo
	}
	
}
void carrega_registro(agenda a[MAX]){
//pre: recebe um vetor do tipo agenda
//pos: Lê os dados do arquivo no arquivo agenda.txt para o esse vetor recebido
	int i=0;
	FILE *arq; // declara o arquivo
	if (!(arq=fopen("agenda.txt","r"))){ // verifica se o arquivo esta disponivel
		printf("Erro no arquivo\n");// imprime mensagem de erro
		system("pause");
	}
	else{// caso não ocorra erro 
		arq=fopen("agenda.txt","r");// abre o arquivo como leitura
		limpa(a);
	while(!feof(arq)&& i<MAX){ // le os registros até encontrar o fim do arquivo
		fscanf(arq,"%d ; %s ; %d\n",&a[i].usa,&a[i].nome,&a[i].telefone); // carrega na memoria cada registro
		i++; // incrementa o numero de registros
		}	
	fclose(arq);// fecha o arquivo
	}	// retorna o numero de registros para o programa principal
}


void exclui_registro(agenda a[MAX]){
//	pre: Recebe agenda e o numero de registros
//	pos: Retorna a agenda com a exclusão do item desejado
	int i=-1,j=0,opt=-1,telefone; // Declara variaáveis sendo i o endereço do item a ser buscado, j contador para avaliar erro de digitação e opt é opçao de gravação da edição dos dados
	char nome[MAXNOME]; // declara as variaves que serão lidas do teclado
	while(i<0){
		if(j>0){ // verifica se houve erro
			 printf("Opção invalida!\n Tente novamente!");// imprime mensagem de erro caso seja contado mais de 1 tentativa
		}
		printf("Digite o nome do registro que quer excluir:\nCaso não queira excluir nada digite 0. \n");
		scanf("%s",&nome);// le o nome a ser editado
		if (strcmp(nome,"0")!=0){ // caso seja digitado 0 não faz exclusão caso contrario aguarda ser digitado um valor válido
			i=busca_registro(nome,a);// busca na memoria o registro a ser editado
			j++; // incrementa o contador para verificar se houve erro de digitação
		}
		else{
		opt=0; // faz opt==0 para não altrar nada na agenda
		i=MAX; // define i=para valor positivo para sair do while
		}
	}
	j=0; // zera contador de tentativas 
	while (opt!=0 && opt!=1){ // avalia se vai haver ou não a exclusão
		printf("O registro foi localizado!\n");
		listar_registros(a,i);
		if(j>0){ // verifica se houve erro
			 printf("Opção invalida!\n Tente novamente!");// imprime mensagem de erro
		}
		printf("Deseja confirmar a exclusão? (1=sim/0=não)"); // imprime as opções
		scanf("%d",&opt);// le a opção desejada gravar sim ou não
		j++; // Incremente o contador de tentativas
	}
	if (opt==1){ // elimina o registro selecionado
		a[i].usa=0; // faz o campo usa=0 para efetivar a exclusão.
	}	
	
}

void edita_registro(agenda a[MAX]){
//	pre: Recebe agenda e do teclado o nome e o telefone a serem alterados
//	pos: Retorna a agenda com a as alterações desejadas
	int i=-1,j=0,opt=-1,telefone; // Declara variáveis sendo i o endereço do item a ser buscado, j contador para avaliar erro de digitação e opt é opçao de gravação da edição dos dados
	char nome[MAXNOME]; //Declara variavel para buscar nome
	while(i<0){
		if(j>0){ // verifica se houve erro
			 printf("Opção invalida!\n Tente novamente!");// imprime mensagem de erro
		}
		printf("Digite o nome do registro que quer editar:\n");
		scanf("%s",&nome);// le o nome a ser editado
		i=busca_registro(nome,a);// busca na memoria o registro a ser editado
		j++;
	}
	j=0;
	printf("Nome Antigo:\n%s\n",a[i].nome); // imprime o nome do registro buscado
	printf("Digite o novo nome:\n");
	scanf("%s",&nome); // le o novo nome do teclado
	printf("Telefone Antigo:\n%d\n",a[i].telefone);// imprime o telefone do registro buscado
	printf("Digite o novo telefone:\n");
	scanf("%d",&telefone);// le o novo telefone do teclado
	printf("Deseja confirmar a alteração? (1=sim/0=não): ");
	while(opt!=0 && opt!=1){ // verifica a opção de gravação na memoria
		if(j>0){ // verifica se houve erro
			 printf("Opção invalida!\n Tente novamente (1=sim/0=não): ");// imprime mensagem de erro
		}
		scanf("%d",&opt);// le a opção desejada gravar sim ou não
		j++; // incrementa o contador
	}	
	if (opt==1) { // grava os novos dados na memoria
		strcpy(a[i].nome ,nome); // grava o nome
		a[i].telefone=telefone;// grava o telefoneo
	}
	
}

void listar_tudo(agenda a[MAX]){
//pre: Recebe o vetor do tipo agenda 
//pos: imprime todos os registros independete da variavel usa - usado apenas para eliminação de bugs do sistema
		int i,n=0; // define o contador
		printf("Nome                 |   Telefone\n");//imprime o cabeçalho da tabela
		printf("----------------------------------------\n");//imprime o cabeçalho da tabela
			for (i=0;i<MAX;i++){// Percorre todo o vetor
					printf("%-20s |   %d \n",a[i].nome, a[i].telefone);// imprime cada elemento do agenda
					n++; // incrementa o contador de registros impressos na tela	
			}
		printf("Foram listados %d registros\n\n",n);// imprime o numero de registros listados
}

