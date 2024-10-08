#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // Fun�ao responsavel por cadastrar os usu�rios no sistema 
{
	//inicio de cra��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cra��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:\t"); //coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); // Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,","); // adiciona a "," separando as informa��es
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o NOME a ser cadastrado:\t");
	scanf("%s",nome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,nome); //coletando informa��o do usu�rio
	fclose(file);// fecha o arquivo
	
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,","); // adiciona a "," separando as informa��es
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o SOBRENOME a ser cadastrado:\t");
	scanf("%s",sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,sobrenome); //coletando informa��o do usu�rio
	fclose(file); // fecha o arquivo
	
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,","); // adiciona a "," separando as informa��es
	fclose(file);// fecha o arquivo
	
	
	printf("Digite o CARGO a ser cadastrado:\t");
	scanf("%s",cargo); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,cargo); //coletando informa��o do usu�rio
	fclose(file); // fecha o arquivo
	
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,  "Portuguese"); // defini��o da linguagem
	
	char cpf[40]; // variavel que o arquivo foi cadastrada, e por onde ser� feita a busca
	char conteudo[200]; // refere-se a todo o conteudo do arquivo a ser lido
	
	printf("Digite o CPF a ser consultado:\t"); // consulta das informa��es do usu�rio
	scanf("%s",cpf); // %s refere-se a string a ser consultada
	
	FILE *file; //permite que faz a busca do arquivo
	file = fopen(cpf, "r"); //  leitura do arquivo pesquisado
	
	if(file == NULL) // caso o arquivo n�o se encontre salvo nesse sistema, � feita a leitura da frase a baixo
	{
		printf("\nArquivo n�o localizado, n�o � possivel abrir!\n\n"); 
		system("pause");
	}

	while(fgets(conteudo, 200, file)!= NULL) // encontrando o arquivo salvo no sistema, � feita a leitura da frase a baixo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); // %s refere-se a string a ser consultada
		printf("\n\n"); //comando para pularlinhas e ficar mais visualmente bonito
		
		system("pause");
	}
}

int deletar()
{
	char cpf[40];  // variavel que o arquivo foi cadastrada, e por onde ser� feita a busca
	
	printf("Digite o CPF do usu�rio a ser deletado:"); // consulta das informa��es do usu�rio a se deleado
	scanf("%s",cpf); // %s refere-se a string a ser consultada
	
	remove(cpf); //fun��o que faz a remo��o do usuario, pela busca com o cpf
	
	FILE*file;  //permite que faz a busca do arquivo
	file = fopen(cpf,"r"); //faz a leitura do arquivo

	if(file == NULL)  // caso o arquivo n�o se encontre salvo nesse sistema, � feita a leitura da frase a baixo
	{
		printf("\nO usu�rio n�o se encontra no sistema!.\n\n");
		system("pause");
	}
	
	if(file != NULL)// encontrando o arquivo salvo no sistema, � feita a leitura da frase a baixo e em seguida, deletado
	{
		printf("\nUsu�rio deletado com sucesso do sistema!\n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	
{
	
	system("cls"); // respons�vel por limpar a tela
	
	setlocale(LC_ALL,  "Portuguese"); // defini��o da linguagem
	
	printf("\n\t*Sejam bem vindos ao Cart�rio da EBAC*\n\n"); // inicio do menu
	printf("\tEscolha a op��o desejada do menu a seguir:\n\n");
	printf("\t 1� - Registrar Nomes;\n\n");
	printf("\t 2� - Consultar Nomes;\n\n");
	printf("\t 3� - Deletar Nomes.\n\n");
	printf("\t 4� - Sair do sistema\n\n\n");
	printf("ESCOLHA A OP��O DESEJADA:"); // fim do menu
	
	
	scanf("%d", &opcao); //armazenamento e escoha do usu�rio
	
	system("cls");  // respons�vel por limpar a tela

	switch (opcao) // inicio da sele��o
	{
		case 1:
		registro(); // chamada da fun��o
		break;
		
		case 2:
		consulta(); // chamada da fun��o
		break;
		
		case 3:
		deletar(); // chamada da fun��o
		break;
		
		case 4:
		printf("obrigada por utilizar o Cartorio EBAC!\n");
		return 0;
		break;
		
		default: // caso a op��o de fun��o n�o se encontre disponivel nesse sistema, � feita a leitura da frase a baixo
		printf("ESSA OP��O N�O EST� DISPON�VEL!\n");
		system("pause");
		break;
	}
	

	
	printf("\t\t\t\t\t\t\t\t\t\t\t\tEsse Softare � uma cria��o de Beatriz Bilicki");
	
}
}
