#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "insertTable.h"
#include "operaColumnsBin.h"
#include "operaCellsBin.h"
#include "operaLinesBin.h"
#include "operaInsertTable.h"

typedef struct tcoluna{
	char tipoColuna[10];
	char nomeColuna[10];
} coluna;

typedef struct tcelula{
	char valorCelula[50];
} celula;

typedef struct tlinha{
	celula vetorCelula[10];
} linha;

void insertTable(){ //insere nova linha
	char tabela[50];
	printf("Insira o nome da tabela: ");
	scanf("%s", &tabela);
	char dir[50] = "tables/";
	strcat(dir, tabela);
	int qtdColunas = lengthColumnsBin(tabela); //Era "dir" como parâmetro.
	char op1;
	coluna vetor[qtdColunas];
	coluna aux_colunas[qtdColunas];
	readColumnsBin(tabela, aux_colunas);
	


	linha aux_linha;

/*	for(int i=0; i<10; i++){
		strcpy(vetor[i].nomeColuna, ""); //inicia todos as celulas da linha com vazio
	}*/
	printf("Colunas %d\n", qtdColunas);
	int celulaInt, celulaDaTabela;
	char valorCelulaString[50];
	for(int i = 0; i < qtdColunas; i++){
		
		//panelInsertTable(tabela, aux_colunas, qtdColunas, aux_linha);
		printf("Insira o %s: ", aux_colunas[i].nomeColuna);

		if (strcmp(aux_colunas[i].tipoColuna, "int(PK)")==0){
			scanf("%s", &valorCelulaString);
			// Se verificaChavePrimaria() retornar ERROR, então já existe esse id.
			if(strcmp(verificaChavePrimaria(valorCelulaString, aux_colunas, i, tabela), "ERROR")==0){
				exit(1);
			} else {
				strcpy(
					vetor[i].nomeColuna,
					verificaChavePrimaria(valorCelulaString, aux_colunas, i, tabela)
				);
			}

		} else if(strcmp(aux_colunas[i].tipoColuna, "int")==0){
			scanf("%s", &valorCelulaString);
			strcpy(
				vetor[i].nomeColuna,
				verificaInt(valorCelulaString, aux_colunas, i)
			);
		} else if(strcmp(aux_colunas[i].tipoColuna, "float")==0){
			scanf("%s", &valorCelulaString);
			celulaDaTabela = verificaFloat(valorCelulaString, aux_colunas, i);
			//strcpy(vetor[i].valorCelula, celulaDaTabela);

		} else if(strcmp(aux_colunas[i].tipoColuna, "double")==0){
			scanf("%s", &valorCelulaString);
			celulaDaTabela = verificaDouble(valorCelulaString, aux_colunas, i);
			//strcpy(vetor[i].valorCelula, celulaDaTabela);

		} else if(strcmp(aux_colunas[i].tipoColuna, "char")==0){
			scanf("%s", &valorCelulaString);
			strcpy(vetor[i].nomeColuna, valorCelulaString);

		} else if(strcmp(aux_colunas[i].tipoColuna, "string")==0){
			scanf("%s", &valorCelulaString);
		}

	}

	for (int i = 0; i < qtdColunas; i++)
	{
		strcpy(vetor[i].tipoColuna, "");
	}
	createColumnsBin(tabela, qtdColunas, vetor);
	printColumnsBin(tabela);


	printf("\nDados inseridos com súcesso na tabela %s.\n", tabela);




	
	printf("\n");

}