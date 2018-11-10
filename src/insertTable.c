#include <stdio.h>
#include <dirent.h>
#include "insertTable.h"


char* stringEntreCaracteres(char *string, char inicio, char final){
	// seleciona e retorna uma string dentro de outra a partir de um caracter específico até outro.
	// por exemplo: stringEntreCaracteres("ola{mundo}ola", '{', '}') retorna "mundo"



}


void insertTable(){ //insere nova linha

    char tabela[50];
    printf("Insira o nome da tabela: ");
    scanf("%s", &tabela);

    DIR *dir;
    dir = opendir("tables/");
    struct dirent *lsdir;
    while( (lsdir = readdir(dir)) != NULL){

    	if((strcmp(lsdir->d_name, tabela)==0)){

    		FILE *pArquivo;
			pArquivo = fopen(tabela, "r");

			int i = 0;

			char c = fgetc(pArquivo);
			char tipo[10];
			while(c == '\n'){

				if(c == '('){

				}


			}
			fclose(pArquivo);



    	} else {
            printf("Erro. Tabela não existe. Tente novamente.\n");
    	}
    }
    printf("\n");

}
