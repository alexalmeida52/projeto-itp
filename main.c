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


int main(int argc, char const *argv[])
{
	system("clear");
	char op[50];
	char op1;
	char nomeTabela[50];

	do{
		panel();
		printf("Digite uma opção: ");
		scanf("%s", op);
		if (strcmp(op, "createTable")==0 || strcmp(op, "1")==0){
			createTable();
		} else if(strcmp(op, "selectTable")==0 || strcmp(op, "3")==0){
			system("clear");
			selectTable();
			printf("Deseja inserir novos dados em alguma tabela?(s/n) ");
			scanf(" %c", &op1); //Para não ter que inserir sempre ao ver as tabelas.
			if (op1=='s'){
				insertTable();
			} else {

			}
		} else if(strcmp(op, "deleteTable")==0 || strcmp(op, "4")==0){
			deleteTable();
		} else if(strcmp(op, "insertTable")==0 || strcmp(op, "5")==0){
			insertTable();
		} else if(strcmp(op, "removeLine")==0 || strcmp(op, "6")==0){
			removeLine();
		} else if(strcmp(op, "help")==0 || strcmp(op, "7")==0){
			help();
		} else if(strcmp(op, "clear")==0 || strcmp(op, "8")==0){
			system("clear");
		} else if(strcmp(op, "showTables")==0 || strcmp(op, "9")==0){
			system("clear");
			selectTable();
			printf("Nome da tabela para ser exibida: ");
			scanf("%s", nomeTabela);
			system("clear");
			printf("Dados da tabela %s:\n\n", nomeTabela);
			printTableBin(nomeTabela);
			printf("\n\n\n");
		}else {
			system("clear");
			printf("Comando inválido.\n");
		}
	} while (!(strcmp(op, "sair")==0 || strcmp(op, "10")==0));
	system("clear");
	return 0;
}
