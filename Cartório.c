#include <stdio.h>     // Inclui a biblioteca padrão de entrada e saída, usada para funções como printf
#include <stdlib.h>    // Inclui a biblioteca padrão do C usada para funções utilitárias como alocação de memória e controle do programa
#include <locale.h>    // Inclui a biblioteca usada para definir configurações regionais, como acentuação e idioma
#include <string.h>    // Inclui a biblioteca resposável por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); // Resposável por copiar os valores das string
	
	FILE *file; // cria o arquivo de banco de dados
	file=fopen(arquivo, "w"); // cria o arquivo de banco de dados
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o Cargo a ser Cadastrado: ");
	scanf("%s", cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
		{
		 	printf("Não foi possível abrir o arquivo, registro não localizado.\n");
		}
	
	while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
	system("pause");
}

int deletar()
{
	
	char cpf[40];
	
	printf("Você Escolheu Deletar um Registro!\n");
	printf("Digite o CPF a ser Deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
		{
			
			printf("O usuário não se encontra no sistema.\n");
			system("pause");
			
		}
}

int main()             // Função principal onde a execução do programa começa
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
		{
			
			system("cls");
			
			setlocale(LC_ALL, "Portuguese");  // Define o idioma do programa para Português, permitindo acentos e caracteres especiais
			
			printf("### Cartório da EBAC ###\n\n");  // Exibe o título do sistema do cartório
			printf("Escolha a opção desejada do menu:\n\n");  // Exibe a instrução para o usuário escolher uma opção
			printf("\t1 - Registrar Nomes\n");       // Exibe a opção 1 do menu: Registrar nomes (com tabulação para organização)
			printf("\t2 - Consultar Nomes\n");       // Exibe a opção 2 do menu: Consultar nomes
			printf("\t3 - Deletar Nomes\n\n");         // Exibe a opção 3 do menu: Deletar nomes
			printf("\t4 - Sair Do Sistema\n\n");         // Exibe a opção 4 do menu: Sair do Sistema
			printf("Opção: ");

			scanf("%d", &opcao);
	
			system("cls");
			
			switch(opcao)
				{
					case 1:
						registro();
					break;
					
					case 2:
						consulta();					
						break;
					
					case 3:
						deletar();
					break;
					
					case 4:
						printf("Obrigado por utilizar o sistema!\n");
						return 0;
					break;
					
					default:
						printf("Essa Opção Não Está Disponível.\n");
						system("pause");
					break;
				}
			
		}
}


