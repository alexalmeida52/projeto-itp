#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaCelulasBin.h"

char NOME[100];
char DIR_CEL[100] = "bin/celulas/";
char EXT_CEL[5] = ".bin";

typedef struct tcelula{
	char nomeColuna[10];
	char valorCelula[50];
} celula;

void createCellsBin(char *tabela, int qtdCampos, celula *campo){
	strcpy(NOME, tabela);
	strcat(DIR_CEL, NOME);
	strcat(DIR_CEL, EXT_CEL);
	FILE *arq;
	arq=fopen(DIR_CEL,"wb");

	if(arq != NULL){
		for(int i = 0; i < qtdCampos; i++)
			fwrite(&campo[i], sizeof(celula), 1, arq);
		fclose(arq);
	}
	else{
		printf("\ncreateTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}

void readCellsBin(char *tabela, celula *aux_campos){
	strcpy(NOME, tabela);
	strcat(DIR_CEL, NOME);
	strcat(DIR_CEL, EXT_CEL);
	FILE *arq;
	arq=fopen(DIR_CEL,"rb");
	if(arq != NULL)
	{
		int indice = 0;
		while(1){
			celula p;
			size_t r = fread(&p, sizeof(celula), 1, arq);
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

void printCellsBin(char *tabela){
	strcpy(NOME, tabela);
	strcat(DIR_CEL, NOME);
	strcat(DIR_CEL, EXT_CEL);
	FILE *arq;
	arq=fopen(DIR_CEL,"rb");
	if(arq != NULL)
	{
		while(1){
			celula p;
			size_t r = fread(&p, sizeof(celula), 1, arq);
			if(r < 1)
				break;
			else
				printf("%s %s\t\t", p.nomeColuna, p.valorCelula);
		}
		fclose(arq);
	}
	else{
		printf("\nprintTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}


int lengthCellsBin(char *tabela){
	strcpy(NOME, tabela);
	strcat(DIR_CEL, NOME);
	strcat(DIR_CEL, EXT_CEL);
	FILE *arq;
	arq=fopen(DIR_CEL,"rb");
	if(arq != NULL)
	{
		int indice = 0;
		while(1){
			celula p;
			size_t r = fread(&p, sizeof(celula), 1, arq);
			if(r < 1)
				break;
			else
				indice++;
		}
		fclose(arq);
		return indice;
	}
	else{
		printf("\nlengthTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}