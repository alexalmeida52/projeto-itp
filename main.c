#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "operaColumnsBin.h"
#include "operaCellsBin.h"
#include "operaLinesBin.h"
#include "createTable.h"
#include "selectTable.h"
#include "help.h"
#include "panel.h"
#include "deleteTable.h"
#include "insertTable.h"


int main(int argc, char const *argv[])
{
	system("clear");
	char op[50];
	char op1;

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
			scanf(" %c", &op1); //Para não ter que inserir sempre que quiser ver as tabelas.
			if (op1=='s'){
				insertTable();
			} else {

			}
		} else if(strcmp(op, "help")==0 || strcmp(op, "5")==0){
			help();
		} else if(strcmp(op, "deleteTable")==0 || strcmp(op, "4")==0){
			deleteTable();
		} else if(strcmp(op, "clear")==0 || strcmp(op, "6")==0){
			system("clear");
		} else {
			system("clear");
			printf("Comando inválido.\n");
		}
	} while (!(strcmp(op, "sair")==0 || strcmp(op, "8")==0));
	system("clear");
	return 0;
}
