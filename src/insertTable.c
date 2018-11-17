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
	char nomeColuna[10];
	char valorCelula[50];
} celula;

typedef struct tlinha{
	celula camposCelula[10];
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
	
	int celulaDaTabela;
	char valorCelulaString[50];
	
	for(int i = 0; i < qtdColunas; i++){

		panelInsertTable(tabela, aux_colunas);
		printf("Insira o %s: ", aux_colunas[i].nomeColuna);

		if (strcmp(aux_colunas[i].tipoColuna, "int(PK)")==0){
			scanf("%s", &valorCelulaString);
			celulaDaTabela = verificaChavePrimaria(valorCelulaString, aux_colunas, i);

		} else if(strcmp(aux_colunas[i].tipoColuna, "int")==0){
			scanf("%s", &valorCelulaString);
			celulaDaTabela = verificaInt(valorCelulaString, aux_colunas, i);			

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



	
	printf("\n");

}