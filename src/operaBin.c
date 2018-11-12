#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaBin.h"

typedef struct tcoluna{
	char tipoColuna[10];
	char nomeColuna[10];
} coluna;

void createTableBin(char *tabela, int qtdCampos, coluna *campo){
	char nome[100];
	char ext[100] = ".bin";
	strcpy(nome, tabela);
	strcat(nome, ext);
	FILE *arq;
	arq=fopen(nome,"wb");

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
	char nome[100];
	char ext[100] = ".bin";
	strcpy(nome, tabela);
	strcat(nome, ext);
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
	char nome[100];
	char ext[100] = ".bin";
	strcpy(nome, tabela);
	strcat(nome, ext);
	FILE * arq = fopen(nome, "rb");
	if(arq != NULL)
	{
		while(1){
			coluna p;
			size_t r = fread(&p, sizeof(coluna), 1, arq);
			if(r < 1)
				break;
			else
				printf("%s %s\t\t", p.tipoColuna, p.nomeColuna);
		}
		fclose(arq); // fecha o arquivo
	}
	else{
		printf("\nprintTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}


int lengthTableBin(char *tabela){
	char nome[100];
	char ext[100] = ".bin";
	strcpy(nome, tabela);
	strcat(nome, ext);
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