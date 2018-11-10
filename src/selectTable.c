#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "selectTable.h"

void selectTable(){
    printf("\n");
    DIR *dir;
    dir = opendir("tables/");
    struct dirent *lsdir;
    int cont=0;
    while( (lsdir = readdir(dir)) != NULL){

        cont++;
    	if((strcmp(lsdir->d_name, "..")==0)  || (strcmp(lsdir->d_name, ".")==0)){

    	} else {
            printf("\t%s\n", lsdir->d_name);
    	}
    }
    if ( cont == 2 )
    {
        printf("Não existem tabelas.\n");
    }
    printf("\n");
}
