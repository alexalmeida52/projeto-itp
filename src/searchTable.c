
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "selectTable.h"
#include "searchTable.h"
#include "operaTable.h"

typedef struct tcelula{
	char tipoCelula[10];
	char valorCelula[10];
} celula;


void searchTable(char *nomeTabela, char *nomeColuna, int opcao, char *valorPesquisa){


	//alocando matriz e preenchendo
	celula **tabela; //a tabela é uma matriz de celulas	
	int linhas = lengthLinesTableBin(nomeTabela);
	int colunas = lengthColumnsTableBin(nomeTabela);
	
	tabela = malloc(sizeof(celula *)*linhas); //linhas pra alocarmos o espaço dos dados que vão ser inseridos
	for (int i = 0; i < linhas; ++i){
		tabela[i] = malloc(sizeof(celula)*colunas);
	}

	readTableBin(nomeTabela, linhas, colunas, tabela);
	//fim alocando matriz e preenchendo

	switch(opcao){
		case 1:
			//Percorre todas as colunas
		for (int i = 0; i < colunas; ++i){
				//Encontra a coluna
			if(strcmp(tabela[0][i].valorCelula, nomeColuna)==0){ 
					//Percorre todas as linhas
				for (int j = 0; j < linhas; ++j){ 
						//Testa se valor informado é menor que o da tabela, se sim, imprime a linha
					if (atof(valorPesquisa) < atof(tabela[j][i].valorCelula)){ 
							printLineTableBin(nomeTabela, j); //j = linha
						}
					}
				}
			}
			;break;

			case 2:
			//Percorre todas as colunas
			for (int i = 0; i < colunas; ++i){
				//Encontra a coluna
				if(strcmp(tabela[0][i].valorCelula, nomeColuna)==0){ 
					//Percorre todas as linhas
					for (int j = 0; j < linhas; ++j){ 
						//Testa se valor informado é menor ou igual que o da tabela, se sim, imprime a linha
						if (atof(valorPesquisa) <= atof(tabela[j][i].valorCelula)){ 
							printLineTableBin(nomeTabela, j); //j = linha
						}
					}
				}
			}
			;break;

			case 3:
			//Percorre todas as colunas
			for (int i = 0; i < colunas; ++i){
				//Encontra a coluna
				if(strcmp(tabela[0][i].valorCelula, nomeColuna)==0){ 
					//Percorre todas as linhas
					for (int j = 0; j < linhas; ++j){ 
						//Testa se valor informado é menor ou igual que o da tabela, se sim, imprime a linha
						if (strcmp(tabela[j][i].valorCelula, valorPesquisa)==0){ 
							printLineTableBin(nomeTabela, j); //j = linha
						}
					}
				}
			}
			;break;

			case 4:
			//Percorre todas as colunas
			for (int i = 0; i < colunas; ++i){
				//Encontra a coluna
				if(strcmp(tabela[0][i].valorCelula, nomeColuna)==0){ 
					//Percorre todas as linhas
					for (int j = 0; j < linhas; ++j){ 
						//Testa se valor informado é menor ou igual que o da tabela, se sim, imprime a linha
						if (atof(valorPesquisa) > atof(tabela[j][i].valorCelula)){ 
							printLineTableBin(nomeTabela, j); //j = linha
						}
					}
				}
			}
			;break;

			case 5:
			//Percorre todas as colunas
			for (int i = 0; i < colunas; ++i){
				//Encontra a coluna
				if(strcmp(tabela[0][i].valorCelula, nomeColuna)==0){ 
					//Percorre todas as linhas
					for (int j = 0; j < linhas; ++j){ 
						//Testa se valor informado é menor ou igual que o da tabela, se sim, imprime a linha
						if (atof(valorPesquisa) >= atof(tabela[j][i].valorCelula)){ 
							printLineTableBin(nomeTabela, j); //j = linha
						}
					}
				}
			}
			;break;
		}
	}


	void panelSearchTable(){

	//Lista tabelas
		system("clear");
		printf("Pesquisar na valores na tabela\n");
		selectTable();

	//Seleciona a tabela
		printf("Selecione a tabela: ");
		char nomeTabela[50];
		scanf("%s", nomeTabela);


		system("clear");
	//Imprime colunas da tabela selecionada
		printf("Tabela selecionada: %s\n\n", nomeTabela);
		printColumnsTableBin(nomeTabela);

	//Seleciona uma das colunas
		printf("\nSelecione a coluna: ");
		char coluna[50];
		scanf("%s", coluna);

	//Seleciona opcão
		int opcao = optionsSearchTable(nomeTabela, coluna);

	//Informa valor
		printf("Insira o valor: ");
		char valorPesquisa[50];
		scanf("%s", valorPesquisa);

	if(!((opcao==3)||(opcao==6))){ //Se opcao não for nem 3 nem 6 
		while(!(onlyNumbers(valorPesquisa))){ //enquanto existir um caracter no valorPesquisa, faça
			printf("Erro. A opção %d só é válida para valores numéricos", opcao);
			printf("Insira um valor válido: ");
			scanf("%s", valorPesquisa);
		}
	}
	
	searchTable(nomeTabela, coluna, opcao, valorPesquisa);


}



int optionsSearchTable(char *nomeTabela, char *coluna){

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

		printf("Selecione uma das opções: ");
		char opcao[2];
		scanf("%s", opcao);

	//Testa se a opcao submetida é válida. Se for válida, retorna a opção inserida.
	//Se não for, retorna a própria função panelOptionsSearchTable
		if(atoi(opcao) < 7){
			return atoi(opcao);
		} else{
			return optionsSearchTable(nomeTabela, coluna);
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

	for (int i = 0; i < colunas; ++i){
		if(strcmp(tabela[0][i].valorCelula, nomeColuna)==0){
			return tabela[0][i].tipoCelula;
		}
	}

	printf("A coluna não existe. Insira novamente\n");
	
	scanf("%s", nomeColuna);
	return verificaTypeColumnSearch(nomeTabela, nomeColuna);
}


int onlyNumbers(char *s){
	int len = strlen(s);
	for(int i = 0; i < len; i++){
		if(isdigit(s[i])==0 && s[i]!='.'){
			return 0;
		}
	}
	return 1;
}