#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "selectTable.h"

//Exibe todas as tabelas criadas
void selectTable(){
	printf("Tabelas existentes:\n");
	printf("\n");
	DIR *dir;
	dir = opendir("tables/"); //Abre o diretório tables
	struct dirent *lsdir;
	int cont=0;
	while( (lsdir = readdir(dir)) != NULL){ //Enquanto existir arquivos, faça:

		cont++;
		if((strcmp(lsdir->d_name, "..")==0)  || (strcmp(lsdir->d_name, ".")==0)){ //Se o nome do arquivo(lsdir->d_name) for '..' ou '.' não faça nada

		} else { //Se não, imprima o nome do arquivo
			printf("\t%s\n", lsdir->d_name);
		}
	}
	if ( cont == 2 )
	{
		printf("Não existem tabelas.\n");
	}
	printf("\n");
}