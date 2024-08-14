#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // Funçao responsavel por cadastrar os usuários no sistema 
{
	//inicio de cração de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cração de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:\t"); //coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); // Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,","); // adiciona a "," separando as informações
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o NOME a ser cadastrado:\t");
	scanf("%s",nome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,nome); //coletando informação do usuário
	fclose(file);// fecha o arquivo
	
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,","); // adiciona a "," separando as informações
	fclose(file); // fecha o arquivo
	
	
	printf("Digite o SOBRENOME a ser cadastrado:\t");
	scanf("%s",sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,sobrenome); //coletando informação do usuário
	fclose(file); // fecha o arquivo
	
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,","); // adiciona a "," separando as informações
	fclose(file);// fecha o arquivo
	
	
	printf("Digite o CARGO a ser cadastrado:\t");
	scanf("%s",cargo); // %s refere-se a string
	
	file = fopen(arquivo, "a"); // adiciona o valor digitado ao arquivo
	fprintf(file,cargo); //coletando informação do usuário
	fclose(file); // fecha o arquivo
	
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL,  "Portuguese"); // definição da linguagem
	
	char cpf[40]; // variavel que o arquivo foi cadastrada, e por onde será feita a busca
	char conteudo[200]; // refere-se a todo o conteudo do arquivo a ser lido
	
	printf("Digite o CPF a ser consultado:\t"); // consulta das informações do usuário
	scanf("%s",cpf); // %s refere-se a string a ser consultada
	
	FILE *file; //permite que faz a busca do arquivo
	file = fopen(cpf, "r"); //  leitura do arquivo pesquisado
	
	if(file == NULL) // caso o arquivo não se encontre salvo nesse sistema, é feita a leitura da frase a baixo
	{
		printf("\nArquivo não localizado, não é possivel abrir!\n\n"); 
		system("pause");
	}

	while(fgets(conteudo, 200, file)!= NULL) // encontrando o arquivo salvo no sistema, é feita a leitura da frase a baixo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); // %s refere-se a string a ser consultada
		printf("\n\n"); //comando para pularlinhas e ficar mais visualmente bonito
		
		system("pause");
	}
}

int deletar()
{
	char cpf[40];  // variavel que o arquivo foi cadastrada, e por onde será feita a busca
	
	printf("Digite o CPF do usuário a ser deletado:"); // consulta das informações do usuário a se deleado
	scanf("%s",cpf); // %s refere-se a string a ser consultada
	
	remove(cpf); //função que faz a remoção do usuario, pela busca com o cpf
	
	FILE*file;  //permite que faz a busca do arquivo
	file = fopen(cpf,"r"); //faz a leitura do arquivo

	if(file == NULL)  // caso o arquivo não se encontre salvo nesse sistema, é feita a leitura da frase a baixo
	{
		printf("\nO usuário não se encontra no sistema!.\n\n");
		system("pause");
	}
	
	if(file != NULL)// encontrando o arquivo salvo no sistema, é feita a leitura da frase a baixo e em seguida, deletado
	{
		printf("\nUsuário deletado com sucesso do sistema!\n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	
{
	
	system("cls"); // responsável por limpar a tela
	
	setlocale(LC_ALL,  "Portuguese"); // definição da linguagem
	
	printf("\n\t*Sejam bem vindos ao Cartório da EBAC*\n\n"); // inicio do menu
	printf("\tEscolha a opção desejada do menu a seguir:\n\n");
	printf("\t 1º - Registrar Nomes;\n\n");
	printf("\t 2º - Consultar Nomes;\n\n");
	printf("\t 3º - Deletar Nomes.\n\n");
	printf("\t 4º - Sair do sistema\n\n\n");
	printf("ESCOLHA A OPÇÃO DESEJADA:"); // fim do menu
	
	
	scanf("%d", &opcao); //armazenamento e escoha do usuário
	
	system("cls");  // responsável por limpar a tela

	switch (opcao) // inicio da seleção
	{
		case 1:
		registro(); // chamada da função
		break;
		
		case 2:
		consulta(); // chamada da função
		break;
		
		case 3:
		deletar(); // chamada da função
		break;
		
		case 4:
		printf("obrigada por utilizar o Cartorio EBAC!\n");
		return 0;
		break;
		
		default: // caso a opção de função não se encontre disponivel nesse sistema, é feita a leitura da frase a baixo
		printf("ESSA OPÇÃO NÃO ESTÁ DISPONÍVEL!\n");
		system("pause");
		break;
	}
	

	
	printf("\t\t\t\t\t\t\t\t\t\t\t\tEsse Softare é uma criação de Beatriz Bilicki");
	
}
}
