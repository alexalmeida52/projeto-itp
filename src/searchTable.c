
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selectTable.h"

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


	printf("Opções\n\n");
	printf("1. valores maior que o valor informado\n");
	printf("2. valores maior ou igual que o valor informado\n");
	printf("3. valores igual o valor informado\n");
	printf("4. valores menor que o valor informado\n");
	printf("5. valores menor ou igual que o valor informado\n");
	printf("6. valores próximo ao valor informado\n");
	printf("\n\n");

	printf("Selecione uma das opções: \n");
	char opcao[2];
	scanf("%s", opcao);
	
	//Testa se a opcao submetida é válida. Se for válida, retorna a opção inserida.
	//Se não for, retorna a própria função panelOptionsSearchTable
	if(atoi(opcao) < 6){
		return atoi(opcao);
	} else{
		return panelOptionsSearchTable();
	}

}