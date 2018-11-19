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

typedef struct tcelula{
	char valorCelula[50];
} celula;

void createColumnsBin(char *tabela, int qtdCampos, coluna *campo){
	strcpy(DIR_COL, "bin/colunas/");//correção para a variável global possuir o caminho correto nesta função.
	printf("Inicio createColumnsBin %s \n", tabela);
	strcpy(NOME, tabela);
	strcat(DIR_COL, NOME);
	strcat(DIR_COL, EXT_COL);
	FILE *arq;
	arq=fopen(DIR_COL,"ab");
	if(arq != NULL){
		for(int i = 0; i < qtdCampos; i++)
			fwrite(&campo[i], sizeof(coluna), 1, arq);
		fclose(arq);
	}
	else{
		printf("\ncreateColumnsBin: Erro ao abrir o arquivo para escrita!\n");
		exit(1);
	}
}

void readColumnsBin(char *tabela, coluna *aux_campos){
	strcpy(DIR_COL, "bin/colunas/");//correção para a variável global possuir o caminho correto nesta função.
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
		printf("\nreadColumnsBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}

}

void printColumnsBin(char *tabela){
	strcpy(DIR_COL, "bin/colunas/");//correção para a variável global possuir o caminho correto nesta função.
	strcpy(NOME, tabela);
	strcat(DIR_COL, NOME);
	strcat(DIR_COL, EXT_COL);
	FILE *arq;
	arq=fopen(DIR_COL,"rb");
	int length = lengthColumnsBin(tabela);
	int i=0;
	int ax=1;
	int cont=0;
	if(arq != NULL)

	{
		while(ax){
			


				
				
				for (int i = 0; i < length; i++)
				{
					coluna p;
					size_t r = fread(&p, sizeof(coluna), 1, arq);
					if(r < 1){
						ax = 0;
						break;
						
					}
					else{
						if (cont)
						{
							
							printf("%s %s\t\t", p.tipoColuna, p.nomeColuna);
						} else {
							printf("%s %s\t", p.tipoColuna, p.nomeColuna);
						}
						
					}
				}
				
				printf("\n");
				cont=1;
				


		}
		printf("\n");
		fclose(arq); // fecha o arquivo
	}
	else{
		printf("\nprintColumnsBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}


int lengthColumnsBin(char *tabela){
	strcpy(DIR_COL, "bin/colunas/");//correção para a variável global possuir o caminho correto nesta função.
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
			else{
				
				if (atoi(p.nomeColuna))
				{
					break;
				} else{
					
					indice++;
				}
			}
		}
		fclose(arq); // fecha o arquivo
		
		return indice;
	}
	else{
		printf("\nlengthColumnsBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}


