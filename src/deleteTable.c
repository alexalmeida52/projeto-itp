#include "deleteTable.h"
#include <stdio.h>
#include "selectTable.h"
#include <string.h>
#include <dirent.h>

void deleteTable(){
	
	// Apagar o arquivo txt
	char table[50];
	char arquivo[50] = "tables/";
	char confirm [2];
	selectTable();
	printf("Qual tabela dejesa excluir? ");
	scanf("%s", table);
	DIR *dir;
    dir = opendir("tables/");
    struct dirent *lsdir;
    while( (lsdir = readdir(dir)) != NULL){


    	if((strcmp(lsdir->d_name, table)==0)){
    		printf("Tem certeza que deseja excluir a tabela %s?(s/n) ", table);
			scanf("%s", confirm);
			if (strcmp(confirm, "s")==0){
				strcat(arquivo, table);
				remove(arquivo);
				break;
			} 
    	}
    } 
    // Apagar o arquivo bin.
    char arquivoBin[50] = "bin/";
	char ext[10] = ".bin";
	strcat(table, ext);
    dir = opendir("bin/");
   
    while( (lsdir = readdir(dir)) != NULL){


    	if((strcmp(lsdir->d_name, table)==0)){
    		printf("Tem certeza que deseja excluir a tabela %s?(s/n) ", table);
			scanf("%s", confirm);
			if (strcmp(confirm, "s")==0){
				strcat(arquivoBin, table);
				remove(arquivoBin);
				return;
			} 
    	}
    } 
    printf("A tabela %s não existe!\n", table);

	
}