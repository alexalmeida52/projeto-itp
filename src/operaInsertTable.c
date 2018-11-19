#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operaInsertTable.h"
#include "operaTable.h"

typedef struct tcelula{
	char tipoCelula[10];
	char valorCelula[10];
} celula;
	
/*Verifica se o valor informado é inteiro e se já existe na tabela.
Caso exista, pede para o usuario informar o valor novamente até que
seja válido para inserção.*/
char * verificaChavePrimaria(char *valorCelulaString, celula **aux_tabela, int coluna, char *nomeTabela){
	
	char op;
	char valorString[50];
	int linhas = lengthLinesTableBin(nomeTabela);

	if (atoi(valorCelulaString)){ // Se existir letra na variavel o atoi retorna 0

		for (int i = 0; i < linhas; i++){
			
			if (strcmp(aux_tabela[i][coluna].valorCelula, valorCelulaString)==0){
				printf("\nO valor inserido já existe. Insira novamente o %s: ", aux_tabela[0][coluna].valorCelula);
				scanf("%s", &valorString);
				return verificaChavePrimaria(valorString, aux_tabela, coluna, nomeTabela);
			}

		}

		return valorCelulaString;
		
		
	} else {
		printf("\nErro. Você está inserindo um valor que não é INTEIRO ou que é NULO(zero).\n");
		printf("Você deseja inserir outro valor na coluna %s que não seja nulo(zero)?(s/n) ", aux_tabela[0][coluna].valorCelula);
		scanf(" %c", &op);
		if (op=='s'){
			printf("\nInsira novamente o %s: ", aux_tabela[0][coluna].valorCelula);
			scanf("%s", &valorString);
			return verificaChavePrimaria(valorString, aux_tabela, coluna, nomeTabela);
			
		} else {
			strcpy(valorCelulaString, "0");
			return valorCelulaString;
		}
	}
}


/*Verifica se o valor informado é inteiro e se já existe na tabela.
Caso exista, pede para o usuario informar o valor novamente até que
seja válido para inserção.*/
char * verificaInt(char *valorCelulaString, celula **aux_tabela, int coluna){
	
	char op;
	char valorString[50];

	if (atoi(valorCelulaString)){ // Se existir letra na variavel o atoi retorna 0
		return valorCelulaString;
	} else {
		printf("\nErro. Você está inserindo um valor que não é INTEIRO ou que é NULO(zero).\n");
		printf("Você deseja inserir outro valor na coluna %s que não seja nulo(zero)?(s/n) ", aux_tabela[0][coluna].valorCelula);
		scanf(" %c", &op);
		if (op=='s'){
			printf("\nInsira novamente o %s: ", aux_tabela[0][coluna].valorCelula);
			scanf("%s", &valorString);
			return verificaInt(valorString, aux_tabela, coluna);
		} else {
			strcpy(valorCelulaString, "0");
			return valorCelulaString;
		}
	}
}

char * verificaFloat(char *valorCelulaString, celula **aux_tabela, int coluna){
	
	char op;
	char valorString[50];
	float valorDouble = atof(valorCelulaString); //se existir letra na variavel o atof retorna 0
	float valorFloat = (float)valorDouble; //o atof retorna em double por isso tem que converter em float

	if (valorFloat){ //Se for zero quer dizer que o valor inserido foi inválido ou foi zero mesmo
		return valorCelulaString;
	} else {
		printf("\nErro. Você está inserindo um valor que não é INTEIRO ou que é NULO(zero).\n");
		printf("Você deseja inserir outro valor na coluna %s que não seja nulo(zero)?(s/n) ", aux_tabela[0][coluna].valorCelula);
		scanf(" %c", &op);
		if (op=='s'){
			printf("\nInsira novamente o %s: ", aux_tabela[0][coluna].valorCelula);
			scanf("%s", &valorString);
			return verificaFloat(valorString, aux_tabela, coluna);
		} else {
			strcpy(valorCelulaString, "0");
			return valorCelulaString;
		}
	}
}

char * verificaDouble(char *valorCelulaString, celula **aux_tabela, int coluna){
	
	char op;
	char valorString[50];

	if (atof(valorCelulaString)){ // Se existir letra na variavel o atof retorna 0
		return valorCelulaString;
	} else {
		printf("\nErro. Você está inserindo um valor que não é INTEIRO ou que é NULO(zero).\n");
		printf("Você deseja inserir outro valor na coluna %s que não seja nulo(zero)?(s/n) ", aux_tabela[0][coluna].valorCelula);
		scanf(" %c", &op);
		if (op=='s'){
			printf("\nInsira novamente o %s: ", aux_tabela[0][coluna].valorCelula);
			scanf("%s", &valorString);
			return verificaDouble(valorString, aux_tabela, coluna);
		} else {
			strcpy(valorCelulaString, "0");
			return valorCelulaString;
		}
	}
}

void panelInsertTable(char *nomeTabela, celula **aux_tabela){
	system("clear");
	printf("Tabela selionada: %s\n\n", nomeTabela);
	printf("Colunas:\n");
	
	int linhas = lengthLinesTableBin(nomeTabela);
	int colunas = lengthColumnsTableBin(nomeTabela);
	//imprime colunas
	for (int i = 0; i < colunas; ++i){
		printf("%s %s\t", aux_tabela[0][i].tipoCelula, aux_tabela[0][i].valorCelula);
	}
	printf("\n");
	
	for (int i = 0; i < colunas; i++){
		printf("%s\t\t", aux_tabela[linhas][i].valorCelula);
	}
	printf("\n\n\n");
}