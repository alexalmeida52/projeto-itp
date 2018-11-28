#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "insertTable.h"
#include "operaTable.h"
#include "operaInsertTable.h"
#include "selectTable.h"

typedef struct tcelula{ // Definindo estrutura de todas as células das tabelas que serão criadas.
	char tipoCelula[10];
	char valorCelula[10];
} celula;

void insertTable(){ //insere nova linha

	selectTable(); //imprime nome das tabelas existentes
	
	//Selecionando a tabela
	char nomeTabela[50];
	printf("Insira o nome da tabela: ");
	scanf("%s", nomeTabela);


	celula **aux_tabela; //a tabela é uma matriz de celulas	
	int linhas = lengthLinesTable(nomeTabela); 
	int colunas = lengthColumnsTable(nomeTabela);
	linhas++; //queremos alocar uma linha a mais para armazenar os novos dados
	
	//Declarando a matriz aux_tabela[linhas][colunas]
	aux_tabela = malloc(sizeof(celula *)*linhas); //linhas pra alocarmos o espaço dos dados que vão ser inseridos
	for (int i = 0; i < linhas; ++i){
		aux_tabela[i] = malloc(sizeof(celula)*colunas);
	}

	linhas--; //diminuimos 1 porque agora queremos utilizar a variavel linhas como indice, já que os indices começam a partir do zero
	
	readTable(nomeTabela, linhas, colunas, aux_tabela); //preeche a matriz aux_tabela com os valores do arquivo

	char valorCelulaString[50];
	for(int i = 0; i < colunas; i++){ //Coluna por coluna
		
		panelInsertTable(nomeTabela, aux_tabela); //imprime o estado atual da tabela enquanto o usuario vai inserindo os campos

		printf("Insira o %s: ", aux_tabela[0][i].valorCelula);


		/*
			Cada 'if' verifica o tipo da coluna, logo em seguida pede para iserir o valor.
			A partir daí, é feita uma verificação para saber se o dado lido é do tipo correspondente.
		*/

		if (strcmp(aux_tabela[0][i].tipoCelula, "int(PK)")==0){  //Veri
			scanf("%s", valorCelulaString);
			strcpy(
				//Verifica a existência do valor digitado na tabela e se é inteiro e armazena na nova linha
				aux_tabela[linhas][i].valorCelula,
				verificaChavePrimaria(valorCelulaString, aux_tabela, i, nomeTabela) 
			);
		} else if(strcmp(aux_tabela[0][i].tipoCelula, "int")==0){
			scanf("%s", valorCelulaString);
			strcpy(
				//Verifica se é inteiro e armazena na nova linha
				aux_tabela[linhas][i].valorCelula,
				verificaInt(valorCelulaString, aux_tabela, i)
			);
		} else if(strcmp(aux_tabela[0][i].tipoCelula, "float")==0){
			scanf("%s", valorCelulaString);
			strcpy(
				//Verifica se é float e armazena na nova linha
				aux_tabela[linhas][i].valorCelula,
				verificaFloat(valorCelulaString, aux_tabela, i)
			);
		} else if(strcmp(aux_tabela[0][i].tipoCelula, "double")==0){
			scanf("%s", valorCelulaString);
			strcpy(
				//Verifica se é double e armazena na nova linha
				aux_tabela[linhas][i].valorCelula,
				verificaDouble(valorCelulaString, aux_tabela, i)
			);

		} else if(strcmp(aux_tabela[0][i].tipoCelula, "char")==0){
			scanf("%s", valorCelulaString);
			strcpy(
				//Verifica se é char e armazena na nova linha
				aux_tabela[linhas][i].valorCelula,
				verificaChar(valorCelulaString, aux_tabela, i)
			);

		} else if(strcmp(aux_tabela[0][i].tipoCelula, "string")==0){
			scanf("%s", valorCelulaString);
			strcpy(aux_tabela[linhas][i].valorCelula, valorCelulaString);
		}

	}


	for (int i = 0; i < colunas; i++){ //Os dados não precisam de tipo pois, estes já foram definidos, então é atribuído vazio no campo tipo
		strcpy(aux_tabela[linhas][i].tipoCelula, "");
	}
	
	linhas++; //pois estávamos utilizando como índice
	writeTable(nomeTabela, linhas, colunas, aux_tabela); //sobreescrendo o arquivo com a nova linha
	printTable(nomeTabela); //imprimindo a nova tabela


	printf("\nDados inseridos com sucesso na tabela %s.\n", nomeTabela);




	
	printf("\n");

}