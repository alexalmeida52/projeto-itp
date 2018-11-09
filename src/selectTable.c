#include "../include/createTable.h"
#include <stdio.h>
#include <dirent.h>

void selectTable(){

    DIR *dir;
    dir = opendir("tables/");
    struct dirent *lsdir;
    while( (lsdir = readdir(dir)) != NULL){


    	if((strcmp(lsdir->d_name, "..")==0)  || (strcmp(lsdir->d_name, ".")==0)){

    	} else {
            printf("%s\n", lsdir->d_name);
    	}
    }
    printf("\n");

}
