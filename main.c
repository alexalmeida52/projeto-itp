#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "operaTable.h"
#include "createTable.h"
#include "selectTable.h"
#include "help.h"
#include "panel.h"
#include "deleteTable.h"
#include "insertTable.h"
#include "removeLine.h"
#include "searchTable.h"



int main(int argc, char const *argv[])
{
	system("clear");
	char op[50];
	
	char nomeTabela[50];
	do{
		panel(); // Exibe o painel de comandos.
		printf("Digite uma opção: ");
		scanf("%s", op); // Ler o comando a ser executado.
		if (strcmp(op, "createTable")==0 || strcmp(op, "1")==0){ // Verifica se o comando é o para criar uma tabela.
			createTable(); // Esse comando exucuta um conjunto de funções para a criação de uma tabela.
		
		} else if(strcmp(op, "selectTable")==0 || strcmp(op, "2")==0){ // Verifica se o comando é o para exibir as tabelas existentes.
			system("clear");
			selectTable(); // Esse comando exucuta um conjunto de funções para a exibição das tabelas criadas.
			printf("Deseja inserir novos dados em alguma tabela?(s/n) "); // Ao exibir as tabela é perguntado se o usuário deseja inserir dados em alguma tabela.
			char op1;
			scanf(" %c", &op1); //Para não ter que inserir sempre ao ver as tabelas.
			if (op1=='s'){ // Verifica a entrada
				insertTable(); // Comando para inserir uma linha em uma tabela.
			} 
		
		} else if(strcmp(op, "deleteTable")==0 || strcmp(op, "3")==0){// Verifica se o comando é o para deletar uma tabela.
			deleteTable();
		} else if(strcmp(op, "insertTable")==0 || strcmp(op, "4")==0){// Verifica se o comando é o para inserir uma linha em uma tabela.
			insertTable();
		} else if(strcmp(op, "removeLine")==0 || strcmp(op, "6")==0){// Verifica se o comando é o para remover uma linha de uma tabela.
			removeLine();
			system("clear");
		} else if(strcmp(op, "help")==0 || strcmp(op, "9")==0){// Verifica se o comando é o para exibir a descrição dos comandos.
			help();
		} else if(strcmp(op, "clear")==0 || strcmp(op, "8")==0){// Verifica se o comando é o para limpar a tela.
			system("clear");
		} else if(strcmp(op, "showTables")==0 || strcmp(op, "5")==0){// Verifica se o comando é o para exibir todas as linhas de uma tabela.
			system("clear");
			selectTable();
			printf("Nome da tabela para ser exibida: ");
			scanf("%s", nomeTabela);
			system("clear");
			printf("Dados da tabela %s:\n\n", nomeTabela);
			printTable(nomeTabela);
			printf("\n\n\n");
		}else if(strcmp(op, "searchTable")==0 || strcmp(op, "7")==0) {// Verifica se o comando é o para pesquisar algum valor em uma tabela.
			panelSearchTable();
		} else{
			system("clear");
			printf("Comando inválido.\n");
		}
	} while (!(strcmp(op, "quit")==0 || strcmp(op, "10")==0));// Verifica se o comando é o para finalizar o programa.
	system("clear");
	return 0;
}
