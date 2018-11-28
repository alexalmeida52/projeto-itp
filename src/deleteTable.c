#include "deleteTable.h"
#include <stdio.h>
#include "selectTable.h"
#include <string.h>
#include <dirent.h>

// Apagar o arquivo
void deleteTable(){
	
	char table[50];
	char arquivo[50] = "tables/";
	char confirm [2];
	selectTable(); //Imprime as tabelas existentes no diretório
	printf("Qual tabela dejesa excluir? ");
	scanf("%s", table);
	DIR *dir;
    dir = opendir("tables/"); //Abre o diretório tables
    struct dirent *lsdir;
    while( (lsdir = readdir(dir)) != NULL){

    	if((strcmp(lsdir->d_name, table)==0)){ //Se o nome da tabela informado for igual a um dos arquivos existentes no diretório:
    		printf("Tem certeza que deseja excluir a tabela %s?(s/n) ", table);
			scanf("%s", confirm);
			if (strcmp(confirm, "s")==0){
				strcat(arquivo, table);
				remove(arquivo); //Remove o arquivo
				break;
			} 
    	}
    } 
}