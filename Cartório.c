#include <stdio.h>     	// Inclui a biblioteca padr�o de entrada e sa�da (printf, scanf)
#include <stdlib.h>    	// Inclui a biblioteca padr�o do C usada para fun��es utilit�rias como aloca��o de mem�ria e controle do programa (system, exit)
#include <locale.h>    	// Inclui a biblioteca usada para definir configura��es regionais, como acentua��o e idioma
#include <string.h>		// Inclui a biblioteca respos�vel por cuidar das string (strcpy, strcmp)
#include <unistd.h>	   	// Inclui a biblioteca para usar fun��es do Unix no caso sleep()
#include <conio.h>		// Inclui a biblioteca para captura de tecla sem exibir na tela (getch)
#include <ctype.h>		// Inclui a biblioteca para verificar tipo de caracteres (isprint)

int registro()
{
	char arquivo[40];   // char = � um tipo de vari�vel | arquivo � o nome dessa vari�vel, o nome � dado de acordo com o que se pede ent�o se de acordo com a necessidade do cliente a vari�vel seja at� chuchu
	char cpf[40];		// outro detalhe � o array [] funciona como se fosse um gaveta que cabe uma quantidade de itens, isso ajuda na aloca��o de mem�ria de uma vari�vel para n�o dar erro de tipo inconpleto
	char nome[40];		// no caso de n�o saber ao certo o quanto vai alocar de mem�ria, voc� usa o ponteiro * e o comando malloc(), ele vai reservar um espa�o que precisa ser liberado manualmente com o free()
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);	// L� o CPF digitado pelo usu�rio
	
	strcpy(arquivo, cpf); // Copia o CPF para vari�vel arquivo (nome do arquivo)
	
	FILE *file;  // Ponteiro para arquivo
	
	file=fopen(arquivo, "w"); 		// Cria arquivo novo para grava��o (sobrescreve se existir)
	fprintf(file, cpf); 		// Escreve o CPF no arquivo
	fclose(file); 			// Fecha o Arquivo
	
	file = fopen(arquivo, "a");	//Abre o arquivo para Acrescentar texto
	fprintf(file, ", ");		// � s� uma v�rgula, tipo agora, e agora. Sut�l n�o �?
	fclose(file); 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); 	//L� o nome digitado pelo usu�rio
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); 	//L� o sobrenome digitado pelo usu�rio
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o Cargo a ser Cadastrado: ");
	scanf("%s", cargo); 	//L� o cargo digitado pelo usu�rio
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); 	// Pausa o programa at� o usu�rio pressionar uma tecla
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");	// Define idioma para Portugu�s, com acentua��o
	
	char cpf[40]; 				// CPF para consulta
	char conteudo[200];        // Buffer de leitura: evita travar o sistema ao ler o arquivo linha por linha
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)           // Se arquivo n�o existir
		{
		 	printf("N�o foi poss�vel abrir o arquivo, registro n�o localizado.\n");
		}
	
	while(fgets(conteudo, 200, file) != NULL)  // L� linha por linha do arquivo
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);                  // Mostra conte�do lido
			printf("\n\n");
		}
		
	system("pause");          // Pausa para o usu�rio ler antes de continuar
}

int deletar()
{
	
	char cpf[40];              // CPF para deletar arquivo
	
	printf("Voc� Escolheu Deletar um Registro!\n");
	printf("Digite o CPF a ser Deletado: ");
	scanf("%s",cpf);           // L� o CPF a ser deletado
	
	remove(cpf);               // Apaga arquivo com o nome do CPF
	
	FILE *file;
	file = fopen(cpf,"r");     // Tenta abrir arquivo apagado para verificar
	
	if(file == NULL)           // Se n�o abriu, arquivo apagado com sucesso
		{
			
			printf("O usu�rio n�o se encontra no sistema.\n");
			system("pause");
			
		}
}

int main()             // Fun��o principal onde a execu��o do programa come�a
{
	int opcao=0;			// Vari�vel para armazenar a op��o do menu
	int laco=1;				// Controle de la�o infinito: repete o menu continuamente at� o usu�rio escolher sair
	char senhadigitada[]="a";	// Array para guardar senha digitada (tamanho ajustado)
	int comparacao;      // Resultado da compara��o da senha
	int tentativas = 0;  // Contador de tentativas de login
	
	while (1)            // La�o infinito para manter programa rodando
	{
		system("cls");	   // Limpa a tela
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Login do Administrador.\n\nDigite sua senha: ");
		int i = 0;		// Contador de quantos caracteres o usu�rio j� digitou na senha
		char ch;
		while ((ch = getch()) != '\r')    // Captura caractere sem mostrar (Enter = '\r') '\r' � Enter (retorno do cursor), usado com aspas simples pois getch() retorna 1 caractere (char), n�o uma string. o cursor � esse "trem" que pisca na linha que voc� digita.
		{
			if  (ch == 8) {               // 8 � o apagar ou backspace em ascii
				if (i > 0){              // O c�digo aqui dentro s� executa se i for maior que zero
					i--;				// Diminui o �ndice para apagar o �ltimo caractere digitado, quando voc� digita, i aumenta 1 caractere e assim vai, ent�o se voc� apertar o backspace logo... 
					senhadigitada[i] = '\0'; // Apaga caractere da senha
					printf("\b \b");		// Apaga asterisco da tela
					fflush(stdout);			// For�a atualiza��o da tela, vai que n�o apaga os astericos...
				}
			}
			else if (i < 19 && isprint(ch)) {		// Verifica se ainda tem espa�o na senha e o caractere digitado � vis�vel
				senhadigitada[i++] = ch;		   // se sim adiciona o caractere ch no array senhadigitada na posi��o i, e depois aumenta i em 1. Ou seja voc� pode digitar mais at� o limite 19
				printf("*");					   // Ent�o no lugar de letras aparece asterisco
			}
		}
		senhadigitada[i] = '\0'; 				// Finaliza string da senha
		
		comparacao = strcmp(senhadigitada, "1234");	// Compara senha digitada com "1234"
		
		if(comparacao == 0)			// Se senha correta
		{	
			tentativas = 0;        // Reseta tentativas
			for(laco=1;laco=1;)   // La�o do menu principal
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

					scanf("%d", &opcao);         // L� op��o escolhida
					system("cls");
			
					switch(opcao)               // Avalia op��o escolhida
						{
							case 1:
								registro();          // Chama fun��o para registrar
							break;
						
							case 2: 
								consulta();          // Chama fun��o para consultar					
							break;
					
							case 3:
								deletar();          // Chama fun��o para deletar
							break;
					
							case 4:
								printf("Obrigado por utilizar o sistema!\n");
								return 0;           // Encerra programa
							break;
					
							default:				// Caso o usu�rio tente escolher qualquer op��o que n�o esteja prevista ir� aparecer essa mensagem
								printf("Essa Op��o N�o Est� Dispon�vel.\n");
								system("pause");
							break;
						}
			
				}
		}
		else{                                 // Se senha incorreta
			tentativas++;                     // Incrementa contador de tentativas
			system("cls");
    		printf("\nSenha Incorreta. Tentativas %d de 3.\n\n", tentativas);
    		
    		if (tentativas >= 3)              // Se passou do limite de tentativas
    			{
       			printf("Excesso de Tentativas. Acesso bloqueado por 10 segundos...\n");
      			sleep(10);                    // Pausa o programa por 10 segundos
      		  	tentativas = 0;              // Reseta contador de tentativas
    			}
    	system("pause");
			}
	}
}

//Obviamente tem coisas a mais que que podem ser desenvolvidas, mas acho que j� dei uma boa polida no c�digo, 
//Claro que tive que ir na internet como no stack overflow ou devdocs, mas procurei ir me orientando certinho do que s� dar um ctrl+c e ctrl+v.
