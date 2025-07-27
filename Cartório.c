#include <stdio.h>     // Inclui a biblioteca padr�o de entrada e sa�da, usada para fun��es como printf
#include <stdlib.h>    // Inclui a biblioteca padr�o do C usada para fun��es utilit�rias como aloca��o de mem�ria e controle do programa
#include <locale.h>    // Inclui a biblioteca usada para definir configura��es regionais, como acentua��o e idioma
#include <string.h>    // Inclui a biblioteca respos�vel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); // Respos�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo de banco de dados
	file=fopen(arquivo, "w"); // cria o arquivo de banco de dados
	fprintf(file, cpf); //salva o valor da vari�vel
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
		 	printf("N�o foi poss�vel abrir o arquivo, registro n�o localizado.\n");
		}
	
	while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
	system("pause");
}

int deletar()
{
	
	char cpf[40];
	
	printf("Voc� Escolheu Deletar um Registro!\n");
	printf("Digite o CPF a ser Deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
		{
			
			printf("O usu�rio n�o se encontra no sistema.\n");
			system("pause");
			
		}
}

int main()             // Fun��o principal onde a execu��o do programa come�a
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
		{
			
			system("cls");
			
			setlocale(LC_ALL, "Portuguese");  // Define o idioma do programa para Portugu�s, permitindo acentos e caracteres especiais
			
			printf("### Cart�rio da EBAC ###\n\n");  // Exibe o t�tulo do sistema do cart�rio
			printf("Escolha a op��o desejada do menu:\n\n");  // Exibe a instru��o para o usu�rio escolher uma op��o
			printf("\t1 - Registrar Nomes\n");       // Exibe a op��o 1 do menu: Registrar nomes (com tabula��o para organiza��o)
			printf("\t2 - Consultar Nomes\n");       // Exibe a op��o 2 do menu: Consultar nomes
			printf("\t3 - Deletar Nomes\n\n");         // Exibe a op��o 3 do menu: Deletar nomes
			printf("\t4 - Sair Do Sistema\n\n");         // Exibe a op��o 4 do menu: Sair do Sistema
			printf("Op��o: ");

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
						printf("Essa Op��o N�o Est� Dispon�vel.\n");
						system("pause");
					break;
				}
			
		}
}


