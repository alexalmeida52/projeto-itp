#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaColumnsBin.h"

char NOME[100];
char DIR_COL[100] = "bin/colunas/";
char EXT_COL[5] = ".bin";

typedef struct tcoluna{
	char tipoColuna[10];
	char nomeColuna[10];
} coluna;

void createTableBin(char *tabela, int qtdCampos, coluna *campo){
	strcpy(NOME, tabela);
	strcat(DIR_COL, NOME);
	strcat(DIR_COL, EXT_COL);
	FILE *arq;
	arq=fopen(DIR_COL,"wb");
	if(arq != NULL){
		for(int i = 0; i < qtdCampos; i++)
			fwrite(&campo[i], sizeof(coluna), 1, arq);
		fclose(arq);
	}
	else{
		printf("\ncreateTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}

void readTableBin(char *tabela, coluna *aux_campos){
	strcpy(NOME, tabela);
	strcat(DIR_COL, NOME);
	strcat(DIR_COL, EXT_COL);
	FILE *arq;
	arq=fopen(DIR_COL,"rb");
	if(arq != NULL)
	{
		int indice = 0;
		while(1){
			coluna p;
			size_t r = fread(&p, sizeof(coluna), 1, arq);
			if(r < 1)
				break;
			else
				aux_campos[indice++] = p;
		}
		fclose(arq); // fecha o arquivo
	}
	else{
		printf("\nreadTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}

}

void printTableBin(char *tabela){
	strcpy(NOME, tabela);
	strcat(DIR_COL, NOME);
	strcat(DIR_COL, EXT_COL);
	FILE *arq;
	arq=fopen(DIR_COL,"rb");
	if(arq != NULL)
	{
		while(1){
			coluna p;
			size_t r = fread(&p, sizeof(coluna), 1, arq);
			if(r < 1)
				break;
			else
				printf("%s %s\t", p.tipoColuna, p.nomeColuna);
		}
		fclose(arq); // fecha o arquivo
	}
	else{
		printf("\nprintTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}


int lengthTableBin(char *tabela){
	strcpy(NOME, tabela);
	strcat(DIR_COL, NOME);
	strcat(DIR_COL, EXT_COL);
	FILE *arq;
	arq=fopen(DIR_COL,"rb");
	FILE * arq = fopen(nome, "rb");
	if(arq != NULL)
	{
		int indice = 0;
		while(1){
			coluna p;
			size_t r = fread(&p, sizeof(coluna), 1, arq);
			if(r < 1)
				break;
			else
				indice++;
		}
		fclose(arq); // fecha o arquivo
		return indice;
	}
	else{
		printf("\nlengthTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}