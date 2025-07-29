#include <stdio.h>     	// Inclui a biblioteca padrão de entrada e saída (printf, scanf)
#include <stdlib.h>    	// Inclui a biblioteca padrão do C usada para funções utilitárias como alocação de memória e controle do programa (system, exit)
#include <locale.h>    	// Inclui a biblioteca usada para definir configurações regionais, como acentuação e idioma
#include <string.h>		// Inclui a biblioteca resposável por cuidar das string (strcpy, strcmp)
#include <unistd.h>	   	// Inclui a biblioteca para usar funções do Unix no caso sleep()
#include <conio.h>		// Inclui a biblioteca para captura de tecla sem exibir na tela (getch)
#include <ctype.h>		// Inclui a biblioteca para verificar tipo de caracteres (isprint)

int registro()
{
	char arquivo[40];   // char = é um tipo de variável | arquivo é o nome dessa variável, o nome é dado de acordo com o que se pede então se de acordo com a necessidade do cliente a variável seja até chuchu
	char cpf[40];		// outro detalhe é o array [] funciona como se fosse um gaveta que cabe uma quantidade de itens, isso ajuda na alocação de memória de uma variável para não dar erro de tipo inconpleto
	char nome[40];		// no caso de não saber ao certo o quanto vai alocar de memória, você usa o ponteiro * e o comando malloc(), ele vai reservar um espaço que precisa ser liberado manualmente com o free()
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);	// Lê o CPF digitado pelo usuário
	
	strcpy(arquivo, cpf); // Copia o CPF para variável arquivo (nome do arquivo)
	
	FILE *file;  // Ponteiro para arquivo
	
	file=fopen(arquivo, "w"); 		// Cria arquivo novo para gravação (sobrescreve se existir)
	fprintf(file, cpf); 		// Escreve o CPF no arquivo
	fclose(file); 			// Fecha o Arquivo
	
	file = fopen(arquivo, "a");	//Abre o arquivo para Acrescentar texto
	fprintf(file, ", ");		// É só uma vírgula, tipo agora, e agora. Sutíl não é?
	fclose(file); 
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); 	//Lê o nome digitado pelo usuário
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); 	//Lê o sobrenome digitado pelo usuário
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o Cargo a ser Cadastrado: ");
	scanf("%s", cargo); 	//Lê o cargo digitado pelo usuário
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); 	// Pausa o programa até o usuário pressionar uma tecla
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");	// Define idioma para Português, com acentuação
	
	char cpf[40]; 				// CPF para consulta
	char conteudo[200];        // Buffer de leitura: evita travar o sistema ao ler o arquivo linha por linha
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)           // Se arquivo não existir
		{
		 	printf("Não foi possível abrir o arquivo, registro não localizado.\n");
		}
	
	while(fgets(conteudo, 200, file) != NULL)  // Lê linha por linha do arquivo
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);                  // Mostra conteúdo lido
			printf("\n\n");
		}
		
	system("pause");          // Pausa para o usuário ler antes de continuar
}

int deletar()
{
	
	char cpf[40];              // CPF para deletar arquivo
	
	printf("Você Escolheu Deletar um Registro!\n");
	printf("Digite o CPF a ser Deletado: ");
	scanf("%s",cpf);           // Lê o CPF a ser deletado
	
	remove(cpf);               // Apaga arquivo com o nome do CPF
	
	FILE *file;
	file = fopen(cpf,"r");     // Tenta abrir arquivo apagado para verificar
	
	if(file == NULL)           // Se não abriu, arquivo apagado com sucesso
		{
			
			printf("O usuário não se encontra no sistema.\n");
			system("pause");
			
		}
}

int main()             // Função principal onde a execução do programa começa
{
	int opcao=0;			// Variável para armazenar a opção do menu
	int laco=1;				// Controle de laço infinito: repete o menu continuamente até o usuário escolher sair
	char senhadigitada[]="a";	// Array para guardar senha digitada (tamanho ajustado)
	int comparacao;      // Resultado da comparação da senha
	int tentativas = 0;  // Contador de tentativas de login
	
	while (1)            // Laço infinito para manter programa rodando
	{
		system("cls");	   // Limpa a tela
		printf("### Cartório da EBAC ###\n\n");
		printf("Login do Administrador.\n\nDigite sua senha: ");
		int i = 0;		// Contador de quantos caracteres o usuário já digitou na senha
		char ch;
		while ((ch = getch()) != '\r')    // Captura caractere sem mostrar (Enter = '\r') '\r' é Enter (retorno do cursor), usado com aspas simples pois getch() retorna 1 caractere (char), não uma string. o cursor é esse "trem" que pisca na linha que você digita.
		{
			if  (ch == 8) {               // 8 é o apagar ou backspace em ascii
				if (i > 0){              // O código aqui dentro só executa se i for maior que zero
					i--;				// Diminui o índice para apagar o último caractere digitado, quando você digita, i aumenta 1 caractere e assim vai, então se você apertar o backspace logo... 
					senhadigitada[i] = '\0'; // Apaga caractere da senha
					printf("\b \b");		// Apaga asterisco da tela
					fflush(stdout);			// Força atualização da tela, vai que não apaga os astericos...
				}
			}
			else if (i < 19 && isprint(ch)) {		// Verifica se ainda tem espaço na senha e o caractere digitado é visível
				senhadigitada[i++] = ch;		   // se sim adiciona o caractere ch no array senhadigitada na posição i, e depois aumenta i em 1. Ou seja você pode digitar mais até o limite 19
				printf("*");					   // Então no lugar de letras aparece asterisco
			}
		}
		senhadigitada[i] = '\0'; 				// Finaliza string da senha
		
		comparacao = strcmp(senhadigitada, "1234");	// Compara senha digitada com "1234"
		
		if(comparacao == 0)			// Se senha correta
		{	
			tentativas = 0;        // Reseta tentativas
			for(laco=1;laco=1;)   // Laço do menu principal
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

					scanf("%d", &opcao);         // Lê opção escolhida
					system("cls");
			
					switch(opcao)               // Avalia opção escolhida
						{
							case 1:
								registro();          // Chama função para registrar
							break;
						
							case 2: 
								consulta();          // Chama função para consultar					
							break;
					
							case 3:
								deletar();          // Chama função para deletar
							break;
					
							case 4:
								printf("Obrigado por utilizar o sistema!\n");
								return 0;           // Encerra programa
							break;
					
							default:				// Caso o usuário tente escolher qualquer opção que não esteja prevista irá aparecer essa mensagem
								printf("Essa Opção Não Está Disponível.\n");
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

//Obviamente tem coisas a mais que que podem ser desenvolvidas, mas acho que já dei uma boa polida no código, 
//Claro que tive que ir na internet como no stack overflow ou devdocs, mas procurei ir me orientando certinho do que só dar um ctrl+c e ctrl+v.
