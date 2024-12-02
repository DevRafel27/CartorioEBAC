#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca aloca��o de mem�ria
#include <locale.h> //biblioteca de alica�es de texto por regi�o
#include <string.h>	//biblioteca responsavel por cuidar das strings


int registro()															//fun��o por cadastrar o usuario no sistema
{
	//inicio cria��o de variav�is/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variav�is/string
	
	printf("VOC� ESCOLHEU REGISTRAR NOMES\n");								
	printf("Digite o CPF a ser cadastrado: ");							//coletando informa��o do usu�rio
	scanf("%s", cpf);													//%s refere-se a string
	
	strcpy(arquivo, cpf);												//responsavel por copiar valores das string
	
	FILE *file;															//cria o arquivo
	file = fopen(arquivo, "w");											//cria o arquivo
	fprintf(file, cpf);													//salvo o valor da variavel
	fclose(file);														//fechar o arquivo
	
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
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
	file = fopen(cpf, "r");                                             //"a" atualizar "w" escrever "r" read, ler
	
	if(file == NULL)
	{
		printf("N�O FOI POSSIVEL ABRIR O ARQUIVO, N�O LOCALIZADO.\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL )	
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}		
	
	system("pause");											
																																			
																	
}

int deleta()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O USU�RIO N�O SE ENCONTRA NO SISTEMA!\n");
		system("pause");
		
	}



}



int main()                                                              //Func�o Principal                        
{
	int opcao=0;						  //definindo as variaveis  	//espa�o op��o n�o esta livre
	int laco=1;
		
	for(laco=1;laco=1;)                   
	{
	
 		system("cls");
	
		setlocale(LC_ALL,"Portuguese");   							    	//definir pontu��o no PORTUGU�S
	                                
		printf("|CARTORIO DA EBAC|\n\n");                                  //PRINTF Aparecer texto para usu�rio
		printf("Escolha a op��o desejada: \n\n");                          // \n jogar mensagem para baixo
		printf("\t 1 - Registrar nomes \n");                               //\t Dar espa�o para mensagem
		printf("\t 2 - Consultar nomes \n ");
		printf("\t 3 - Deletar nomes\n");
		printf("\t 4 - Sair do sistema\n\n");
		printf("Op��o:");													//fim do menu
	
		scanf("%d", &opcao);										    	//registrar resposta do usario
	
		system("cls");                                                      //Limpar Tela 
	
		switch(opcao)														//inicio da sele��o do menu
		{
			case 1:															
			registro();														//chamada de fun��es
			break;                                                          
		
			case 2:
			consulta();														
			break;
			
			case 3:
			deleta();
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistema!\n");
			return 0;
			break;	
			
			default:
			printf("ESSA OP��O N�O ESTA DISPONIVEL!\n");
		    system("pause");
			break;											            	//fim da sele��o
				
				
		}
	
															
	}
	
}
