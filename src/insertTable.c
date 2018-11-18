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

	coluna aux_colunas[qtdColunas];
	readColumnsBin(tabela, aux_colunas);


	linha aux_linha;

	for(int i=0; i<10; i++){
		strcpy(aux_linha.vetorCelula[i].valorCelula, ""); //inicia todos as celulas da linha com vazio
	}
	
	int celulaInt, celulaDaTabela;
	char valorCelulaString[50];
	
	for(int i = 0; i < qtdColunas; i++){

		panelInsertTable(tabela, aux_colunas, qtdColunas, aux_linha);
		printf("Insira o %s: ", aux_colunas[i].nomeColuna);

		if (strcmp(aux_colunas[i].tipoColuna, "int(PK)")==0){
			scanf("%s", &valorCelulaString);
			// Se verificaChavePrimaria() retornar ERROR, então já existe esse id.
			if(strcmp(verificaChavePrimaria(valorCelulaString, aux_colunas, i, tabela), "ERROR")==0){
				exit(1);
			} else {
				strcpy(
					aux_linha.vetorCelula[i].valorCelula,
					verificaChavePrimaria(valorCelulaString, aux_colunas, i, tabela)
				);
			}

		} else if(strcmp(aux_colunas[i].tipoColuna, "int")==0){
			scanf("%s", &valorCelulaString);
			strcpy(
				aux_linha.vetorCelula[i].valorCelula,
				verificaInt(valorCelulaString, aux_colunas, i)
			);
		} else if(strcmp(aux_colunas[i].tipoColuna, "float")==0){
			scanf("%s", &valorCelulaString);
			celulaDaTabela = verificaFloat(valorCelulaString, aux_colunas, i);

		} else if(strcmp(aux_colunas[i].tipoColuna, "double")==0){
			scanf("%s", &valorCelulaString);
			celulaDaTabela = verificaDouble(valorCelulaString, aux_colunas, i);

		} else if(strcmp(aux_colunas[i].tipoColuna, "char")==0){
			scanf("%s", &valorCelulaString);

		} else if(strcmp(aux_colunas[i].tipoColuna, "string")==0){
			scanf("%s", &valorCelulaString);
		}

	}



	printf("\nDados inseridos com súcesso na tabela %s.\n", tabela);
	printf("Valor id:::: %s\n", aux_linha.vetorCelula[0].valorCelula);




	
	printf("\n");

}