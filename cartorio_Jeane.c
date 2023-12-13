#include <stdio.h> //bibblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bibliotecva de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //bioblioteca responsavel por cuidar das string

int registro() //Fun��o responsalvel por cadastrar os usu�rios no sistema 
{
	//inicio da cria��o de vari�veis/string
	char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
    //final da cria��o de variaveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", cpf); //% se refere-se a string
    
    strcpy(arquivo, cpf); // Responsavel por copiar valores das string
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" sisgnifica escrever 
    fprintf(file,cpf); // salvo valor da variavel
    fclose(file); // fecho arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file); //fecha arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando a informa��o do usu�rio
    scanf("%s",nome); //% se refere-se a string
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando a informa��o do usu�rio
    scanf("%s",sobrenome); //% se refere-se a string
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file); 
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause"); 
		   
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("N�o foi possivel abrir o arquivo, n�o localizado!./n");    
	}

    while(fgets(conteudo, 200, file) !=NULL)
    {
    	printf("\nEssas s�o as informa��es do usuario:");
    	printf("%s", conteudo);
    	printf("\n\n");
	}

	system("pause");
	
	
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado : ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf(" O usuario n�o se encontra no sistema!.\n");
    	system("pause");   	
	}
     
}



int main ()
    {
	int opcao=0; //Defininindo variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
{
	    system("cls"); // responsavel por limpar a tela 
	    	
	
	    setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	    	
		printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema");
		printf("Opcao: ");// fim de menu
	
	    scanf("%d", &opcao); // armazenamento a escolha do usuario 
	
	    system("cls"); //responsavel por limpar a tela  
	
	    switch(opcao) // inicio da sele��o do menu
	    
	   	{
		    case 1:
		    registro(); //chamada de fun��es
			break;	
					    		   
		    case 2:
		    consulta(); //chamdada de fun��es
		    break;
    	    	
    	    case 3:
    	    deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			
			default:
			printf("Essa opcao nao est� disponivel!\n");
		    system("pause");
		    break;    
	    } //fim da sele��o
	    
	}
}
	

	
	
	
	
	

