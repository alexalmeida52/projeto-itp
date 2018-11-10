#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "include/createTable.h"
#include "include/selectTable.h"
#include "include/help.h"
#include "include/panel.h"

int contadorDeLinhas(char nomeArquivo[]);
void alterarLinha(char novaFrase[], int linha, char nomeArquivo[]);

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
		} else if(strcmp(op, "clear")==0 || strcmp(op, "6")==0){
			system("clear");
			panel();
		}
	} while (!(strcmp(op, "sair")==0));
	system("clear");
	return 0;
}


/////////////////////////////////////////
int contadorDeLinhas(char nomeArquivo[]){ //https://youtu.be/YMK0iyv3_YM
	FILE *pArquivo;
	pArquivo = fopen(nomeArquivo, "r");

	char c;
	int contador = 0;
	if(pArquivo != NULL){
		do{
			c = fgetc(pArquivo);
			if(c == '\n'){
				contador++;
			}
		} while (c != EOF);
		fclose(pArquivo);
	} else {
		exit(1);
	}

	return contador;
}

void alterarLinha(char novaFrase[], int linha, char nomeArquivo[]){
	FILE * fOriginal;
    FILE * fTemporario;

    char frase[1000];
    int cont;

    fOriginal  = fopen(nomeArquivo, "r");
    fTemporario = fopen("arquivo.tmp", "w");

    if (fOriginal == NULL || fTemporario == NULL)
    {
        printf("Erro: função alterarLinha.\n");
        exit(1);
    }


    cont = 0;
    while ((fgets(frase, 1000, fOriginal)) != NULL)
    {
        cont++;
        if (cont == linha){
            fputs(novaFrase, fTemporario);
            fputc('\n', fTemporario);
        }
        else{
            fputs(frase, fTemporario);
}
    }

    fclose(fOriginal);
    fclose(fTemporario);

    char nomeBackup[100];
    strcpy(nomeBackup, nomeArquivo);
    strcat(nomeBackup, ".backup");

    rename(nomeArquivo, nomeBackup);
    rename("arquivo.tmp", nomeArquivo);
}
