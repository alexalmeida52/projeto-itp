#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "insertTable.h"
#include "operaTable.h"
#include "operaInsertTable.h"
#include "selectTable.h"

typedef struct tcelula{
	char tipoCelula[10];
	char valorCelula[10];
} celula;

void insertTable(){ //insere nova linha

	selectTable();
	
	char nomeTabela[50];
	printf("Insira o nome da tabela: ");
	scanf("%s", nomeTabela);


	celula **aux_tabela; //a tabela é uma matriz de celulas	
	int linhas = lengthLinesTableBin(nomeTabela);
	int colunas = lengthColumnsTableBin(nomeTabela);
	linhas++; //queremos alocar uma linha a mais para armazenar os novos dados
	
	// aux_tabela[linhas][colunas]
	aux_tabela = malloc(sizeof(celula *)*linhas); //linhas pra alocarmos o espaço dos dados que vão ser inseridos
	for (int i = 0; i < linhas; ++i){
		aux_tabela[i] = malloc(sizeof(celula)*colunas);
	}

	linhas--; //diminuimos 1 porque agora queremos utilizar a variavel como indice, já que os indices começam a partir do zero
	
	readTableBin(nomeTabela, linhas, colunas, aux_tabela); //preeche a matriz aux_tabela com os valores do arquivo

	char valorCelulaString[50];
	for(int i = 0; i < colunas; i++){
		
		panelInsertTable(nomeTabela, aux_tabela);

		printf("Insira o %s: ", aux_tabela[0][i].valorCelula);

		if (strcmp(aux_tabela[0][i].tipoCelula, "int(PK)")==0){
			scanf("%s", valorCelulaString);
			strcpy(
				aux_tabela[linhas][i].valorCelula,
				verificaChavePrimaria(valorCelulaString, aux_tabela, i, nomeTabela)
			);

		} else if(strcmp(aux_tabela[0][i].tipoCelula, "int")==0){
			scanf("%s", valorCelulaString);
			strcpy(
				aux_tabela[linhas][i].valorCelula,
				verificaInt(valorCelulaString, aux_tabela, i)
			);
		} else if(strcmp(aux_tabela[0][i].tipoCelula, "float")==0){
			scanf("%s", valorCelulaString);
			strcpy(
				aux_tabela[linhas][i].valorCelula,
				verificaFloat(valorCelulaString, aux_tabela, i)
			);
		} else if(strcmp(aux_tabela[0][i].tipoCelula, "double")==0){
			scanf("%s", valorCelulaString);
			strcpy(
				aux_tabela[linhas][i].valorCelula,
				verificaDouble(valorCelulaString, aux_tabela, i)
			);

		} else if(strcmp(aux_tabela[0][i].tipoCelula, "char")==0){
			scanf("%s", valorCelulaString);
			strcpy(aux_tabela[linhas][i].valorCelula, valorCelulaString);

		} else if(strcmp(aux_tabela[0][i].tipoCelula, "string")==0){
			scanf("%s", valorCelulaString);
			strcpy(aux_tabela[linhas][i].valorCelula, valorCelulaString);
		}

	}


	for (int i = 0; i < colunas; i++){
		strcpy(aux_tabela[linhas][i].tipoCelula, "");
	}
	
	linhas++;
	createTableBin(nomeTabela, linhas, colunas, aux_tabela);
	printTableBin(nomeTabela);


	printf("\nDados inseridos com súcesso na tabela %s.\n", nomeTabela);




	
	printf("\n");

}