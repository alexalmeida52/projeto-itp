
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selectTable.h"
#include "operaTable.h"

typedef struct tcelula{
	char tipoCelula[10];
	char valorCelula[10];
} celula;


void searchTable(){
	
}

void panelSearchTable(){
	
	printf("Pesquisar na valores na tabela\n");

	//Lista tabelas
	system("clear");
	selectTable();

	//Seleciona a tabela
	printf("Selecione a tabela: \n");
	char nomeTabela[50];
	scanf("%s", nomeTabela);

}



int optionsSearchTable(char * nomeTabela){

	system("clear");
	//Imprime colunas da tabela selecionada
	printf("Tabela selecionada: %s\n", nomeTabela);
	printColumnsTableBin(nomeTabela);

	//Seleciona uma das colunas
	printf("Selecione a coluna: \n");
	char coluna[50];
	scanf("%s", coluna);

	

	if ((strcmp(verificaTypeColumnSearch(nomeTabela, coluna), "char")==0)||
		(strcmp(verificaTypeColumnSearch(nomeTabela, coluna), "string")==0)){

		printf("Opções\n\n");
		printf("3. valores igual o valor informado\n"); //int, float, double, string, char 
		printf("6. valores próximo ao valor informado\n"); //string e char
		printf("\n\n");

	} else if ((strcmp(verificaTypeColumnSearch(nomeTabela, coluna), "int")==0)||
		(strcmp(verificaTypeColumnSearch(nomeTabela, coluna), "float")==0)||
		(strcmp(verificaTypeColumnSearch(nomeTabela, coluna), "double")==0)||
		(strcmp(verificaTypeColumnSearch(nomeTabela, coluna), "int(PK)")==0)){
		
			printf("Opções\n\n");
			printf("1. valores maior que o valor informado\n"); //int, float, double
			printf("2. valores maior ou igual que o valor informado\n"); //int, float, double
			printf("3. valores igual o valor informado\n"); //int, float, double, string, char 
			printf("4. valores menor que o valor informado\n"); //int, float, double
			printf("5. valores menor ou igual que o valor informado\n"); //int, float, double
			printf("\n\n");
	} else {

	}

	

	printf("Selecione uma das opções: \n");
	char opcao[2];
	scanf("%s", opcao);
	
	//Testa se a opcao submetida é válida. Se for válida, retorna a opção inserida.
	//Se não for, retorna a própria função panelOptionsSearchTable
	if(atoi(opcao) < 7){
		return atoi(opcao);
	} else{
		return optionsSearchTable(nomeTabela);
	}

}

char * verificaTypeColumnSearch(char *nomeTabela, char * nomeColuna){
	celula **tabela; //a tabela é uma matriz de celulas	
	int linhas = lengthLinesTableBin(nomeTabela);
	int colunas = lengthColumnsTableBin(nomeTabela);
	
	tabela = malloc(sizeof(celula *)*linhas); //linhas pra alocarmos o espaço dos dados que vão ser inseridos
	for (int i = 0; i < linhas; ++i){
		tabela[i] = malloc(sizeof(celula)*colunas);
	}

	readTableBin(nomeTabela, linhas, colunas, tabela);

	for (int i = 0; i < colunas; ++i)
	{
		if(strcmp(tabela[0][i].valorCelula, nomeColuna)==0){
			return tabela[0][i].tipoCelula;
		} 
	}

	printf("A coluna não existe. Insira novamente\n");
	
	scanf("%s", nomeColuna);
	return verificaTypeColumnSearch(nomeTabela, nomeColuna);
}