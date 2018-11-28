#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "removeLine.h"
#include "operaTable.h"
#include "selectTable.h"


typedef struct tcelula{
	char tipoCelula[10];
	char valorCelula[10];
} celula;

void removeLine(){

	//Lista tabelas
	selectTable();

	//Seleciona a tabela
	printf("Selecione a tabela: \n");
	char nomeTabela[50];
	scanf("%s", nomeTabela);

	//Imprime a tabela selecionada
	printf("Tabela selecionada: %s\n", nomeTabela);
	printTable(nomeTabela);

	//Seleciona a linha que se deseja apagar
	printf("Insira a chave primária da linha que fvocê deseja remover: \n");
	char chavePrimaria[10];
	scanf("%s", chavePrimaria);
	
	//Declara matriz para preenchê-la com dados da tabela selecionada
	int lin = lengthLinesTable(nomeTabela);
	int col = lengthColumnsTable(nomeTabela);
	celula **tabela;
	tabela = malloc(sizeof(celula *)*lin);
	for (int i = 0; i < lin; ++i){
		tabela[i] = malloc(sizeof(celula)*col);
	}

	//Preenche matriz com os dados da tabela selecionada
	readTable(nomeTabela, lin, col, tabela);

	//Declara matriz auxilar para preenchê-la com a tabela sem a linha desejada
	//A matriz auxiliar terá uma linha a menos, mas a mesma quantidade de colunas
	int aux_lin = lin-1;
	celula **aux_tabela;
	aux_tabela = malloc(sizeof(celula *)*aux_lin);
	for (int i = 0; i < lin; ++i){
		aux_tabela[i] = malloc(sizeof(celula)*col);
	}

	int i, j, k;
	int numLinhaRemovida = strcmpChavePrimaria(chavePrimaria, nomeTabela);
	
	if(numLinhaRemovida!=0){

		//O 'for' abaixo preenche a tabela auxiliar até a linha que se deseja remover
		for(i = 0; i < lin; i++){
			for(j = 0; j < col; j++){
				strcpy(aux_tabela[i][j].tipoCelula, tabela[i][j].tipoCelula);
				strcpy(aux_tabela[i][j].valorCelula, tabela[i][j].valorCelula);		
			}
		}

		i++; //Pulando a linha que queremos remover
		
		//Preenchendo a tabela auxiliar depois de pular a linha que queremos remover
		for(i; i < lin; i++){
			for(j = 0; j < col; j++){
				k = i-1; //afinal, a nova tabela irá ter uma linha a menos
				strcpy(aux_tabela[k][j].tipoCelula, tabela[i][j].tipoCelula);
				strcpy(aux_tabela[k][j].valorCelula, tabela[i][j].valorCelula);		
			}
		}

		writeTable(nomeTabela, aux_lin, col, aux_tabela);

	} else {
		printf("A chavePrimaria informada não existe.\n");
	}

}



//Verifica se a chavePrimaria informada é igual a de alguma linha da tabela
//Se sim, retorna o número da linha. Se não, retorna zero, já que é a linha
//zero é guarda somente meta dados da tabela, tipo e nome das colunas.
int strcmpChavePrimaria(char *chavePrimaria, char *nomeTabela){
	//Declara matriz para preenchê-la com dados da tabela selecionada
	int lin = lengthLinesTable(nomeTabela);
	int col = lengthColumnsTable(nomeTabela);
	celula **tabela;
	tabela = malloc(sizeof(celula *)*lin);
	for (int i = 0; i < lin; ++i){
		tabela[i] = malloc(sizeof(celula)*col);
	}

	//Preenche matriz com os dados da tabela selecionada
	readTable(nomeTabela, lin, col, tabela);

	for(int i = 0; i < lin; i++){

		if(strcmp(chavePrimaria, tabela[i][0].valorCelula)==0){ //tabela[i][0], o zero é a coluna da chave primária de todas as tabelas
			return i;
		}
	}

	return 0; //
}