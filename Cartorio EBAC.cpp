	#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca alocação de memória
#include <locale.h> //biblioteca de alicaões de texto por região
#include <string.h>	//biblioteca responsavel por cuidar das strings


int registro()															//função por cadastrar o usuario no sistema
{
	//inicio criação de variavéis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variavéis/string
	
	printf("VOCÊ ESCOLHEU REGISTRAR NOMES\n");								
	printf("Digite o CPF a ser cadastrado: ");							//coletando informação do usuário
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
		printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO, NÃO LOCALIZADO.\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL )	
	{
		printf("\nEssas são as informações do usuario: ");
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
		printf("O USUÁRIO NÃO SE ENCONTRA NO SISTEMA!\n");
		system("pause");
		
	}



}



int main()                                                              //Funcão Principal                        
	{
	int opcao=0;						  //definindo as variaveis  	//espaço opção não esta livre
	int laco=1;
	char senhadigitada[10]="a" ;
	int comparacao; 
	
	printf("|CARTORIO DA EBAC|\n\n");
	printf("Login de Administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if (comparacao == 0)
		{ 
		
		system ("cls");
		
	
	
		for(laco=1;laco=1;)                   
		{
	
 		
	
			setlocale(LC_ALL,"Portuguese");   							    	//definir pontução no PORTUGUÊS
	                                
			printf("|CARTORIO DA EBAC|\n\n");                                  //PRINTF Aparecer texto para usuário
			printf("Escolha a opção desejada: \n\n");                          // \n jogar mensagem para baixo
			printf("\t 1 - Registrar nomes \n");                               //\t Dar espaço para mensagem
			printf("\t 2 - Consultar nomes \n ");
			printf("\t 3 - Deletar nomes\n");
			printf("\t 4 - Sair do sistema\n\n");
			printf("Opção:");													//fim do menu
	
			scanf("%d", &opcao);										    	//registrar resposta do usario
	
			system("cls");                                                      //Limpar Tela 
		
			switch(opcao)														//inicio da seleção do menu
			{
				case 1:															
				registro();														//chamada de funções
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
				printf("ESSA OPÇÃO NÃO ESTA DISPONIVEL!\n");
		  	  system("pause");
				break;											            	//fim da seleção
				
				
			}
	
															
		}
	}
		else
		printf("SENHA INCORRETA!");
}
	

		
