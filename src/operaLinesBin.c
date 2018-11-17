#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaLinesBin.h"

char NOME[100];
char DIR_LIN[100] = "bin/linha/";
char EXT_LIN[5] = ".bin";

typedef struct tcelula{
	char nomeColuna[10];
	char valorCelula[50];
} celula;

typedef struct tlinha{
	celula camposCelula[10];
} linha;

void createLinesBin(char *tabela, int qtdCampos, linha *campo){	
	char dir[100];
	strcpy(dir, DIR_LIN);
	strcpy(NOME, tabela);
	strcat(dir, NOME);
	strcat(dir, EXT_LIN);
	FILE *arq;
	arq=fopen(dir,"wb");

	if(arq != NULL){
		for(int i = 0; i < qtdCampos; i++)
			fwrite(&campo[i], sizeof(linha), 1, arq);
		fclose(arq);
	}
	else{
		printf("\ncreateTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}

void readLinesBin(char *tabela, linha *aux_campos){
	char dir[100];
	strcpy(dir, DIR_LIN);
	strcpy(NOME, tabela);
	strcat(dir, NOME);
	strcat(dir, EXT_LIN);
	FILE *arq;
	arq=fopen(dir,"rb");
	if(arq != NULL)
	{
		int indice = 0;
		while(1){
			linha p;
			size_t r = fread(&p, sizeof(linha), 1, arq);
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
/*
void printLinesBin(char *tabela){
	char dir[100];
	strcpy(dir, DIR_LIN);
	strcpy(NOME, tabela);
	strcat(dir, NOME);
	strcat(dir, EXT_LIN);
	FILE *arq;
	arq=fopen(dir,"rb");
	if(arq != NULL)
	{
		while(1){
			linha p;
			size_t r = fread(&p, sizeof(linha), 1, arq);
			if(r < 1)
				break;
			else
				printf("%s %s\t\t", p.nomeColuna, p.valorlinha);
		}
		fclose(arq);
	}
	else{
		printf("\nprintTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}
*/

int lengthLinesBin(char *tabela){
	char dir[100];
	strcpy(dir, DIR_LIN);
	strcpy(NOME, tabela);
	strcat(dir, NOME);
	strcat(dir, EXT_LIN);
	FILE *arq;
	arq=fopen(dir,"rb");
	if(arq != NULL)
	{
		int indice = 0;
		while(1){
			linha p;
			size_t r = fread(&p, sizeof(linha), 1, arq);
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