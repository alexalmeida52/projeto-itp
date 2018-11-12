#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "operaBin.h"
#include "createTable.h"
#include "selectTable.h"
#include "help.h"
#include "panel.h"
#include "deleteTable.h"


int main(int argc, char const *argv[])
{
	system("clear");
	panel();
	char op[50];

	do{
		printf("Digite uma opção: ");
		scanf("%s", op);
		if (strcmp(op, "createTable")==0 || strcmp(op, "1")==0){
			createTable();
		} else if(strcmp(op, "selectTable")==0 || strcmp(op, "3")==0){
			selectTable();
		} else if(strcmp(op, "help")==0 || strcmp(op, "5")==0){
            help();
		} else if(strcmp(op, "deleteTable")==0 || strcmp(op, "4")==0){
			deleteTable();
		} else if(strcmp(op, "clear")==0 || strcmp(op, "6")==0){
			system("clear");
			panel();
		}
	} while (!(strcmp(op, "sair")==0 || strcmp(op, "8")==0));
	system("clear");
	return 0;
}
