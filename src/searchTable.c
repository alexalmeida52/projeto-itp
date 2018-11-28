
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "selectTable.h"
#include "searchTable.h"
#include "operaTable.h"
#include "operaInsertTable.h"

typedef struct tcelula{ // Definindo estrutura de todas as células das tabelas que serão criadas.
	char tipoCelula[10];
	char valorCelula[10];
} celula;

void panelSearchTable(){

	//Lista tabelas
	system("clear");
	printf("Pesquisar valores na tabela\n");
	selectTable(); //imprime as tabelas existentes

	//Selecionando a tabela
	printf("Selecione a tabela: ");
	char nomeTabela[50];
	scanf("%s", nomeTabela);


	system("clear");
	//Imprimindo colunas da tabela selecionada
	printf("Tabela selecionada: %s\n\n", nomeTabela);
	printTable(nomeTabela);

	//Selecionando uma das colunas
	printf("\nSelecione a coluna: ");
	char coluna[50];
	scanf("%s", coluna);

	//A função optionsSearchTable serve para exibir as opções de acordo com o tipo da coluna selecionada.
	//e retorna uma opção de 1 a 6
	int opcao = optionsSearchTable(nomeTabela, coluna); 

	//Informando valor
	printf("Insira o valor: ");
	char valorPesquisa[50];
	scanf("%s", valorPesquisa);

	if(!(opcao==3)){ //Se a opcao não for 3 
		while(!(onlyRationalNumbers(valorPesquisa))){ //enquanto existir um caracter no valorPesquisa, faça
			printf("Erro. A opção %d só é válida para valores numéricos", opcao);
			printf("Insira um valor válido: ");
			scanf("%s", valorPesquisa);
		}
	}

	system("clear");
	printColumnsTable(nomeTabela);	//imprimindo cabeçalho da tabela selecionada

	// A função searchTable recebe o nome da tabela, o nome da coluna selecionada, a opção escolhida e o valor a ser pesquisado.
	// Para cada opção ocorre a verificação do valor digitado em relação aos valores do arquivo e de acordo com a opção digitada.
	searchTable(nomeTabela, coluna, opcao, valorPesquisa);
	printf("\n\n");

}



//A função optionsSearchTable serve para exibir as opções de acordo com o tipo da coluna selecionada
//e retorna uma opção de 1 a 6
int optionsSearchTable(char *nomeTabela, char *coluna){

	//Se o tipo da coluna informada for char ou string, imprime as opções 3 e 6
	if ((strcmp(verificaTypeColumnSearch(nomeTabela, coluna), "char")==0)||
		(strcmp(verificaTypeColumnSearch(nomeTabela, coluna), "string")==0)){

		printf("Opções\n\n");
		printf("3. valores igual o valor informado\n"); //int, float, double, string, char 
		printf("\n\n");

	//Se o tipo da coluna informada for númerica imprime as opções de 1 a 5.
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
	}

		printf("Selecione uma das opções: ");
		char opcao[2];
		scanf("%s", opcao);

		//Testa se a opcao submetida é válida. Se for válida, retorna a opção inserida.
		//Se não for, retorna a própria função panelOptionsSearchTable
		if(atoi(opcao) < 6){
			return atoi(opcao);
		} else{
			return optionsSearchTable(nomeTabela, coluna); //Chamada recursiva
		}

}

//A função verificaTypeColumnSearch verifica se a coluna informada existe.
//Se não existir, é solicitado que o usuário selecione uma coluna válida.
//Caso exista, a função retorno o tipo da coluna informada.
char * verificaTypeColumnSearch(char *nomeTabela, char *nomeColuna){
	
	celula **tabela; //a tabela é uma matriz de celulas	
	int linhas = lengthLinesTable(nomeTabela);
	int colunas = lengthColumnsTable(nomeTabela);
	
	tabela = malloc(sizeof(celula *)*linhas); //linhas pra alocarmos o espaço dos dados que vão ser inseridos
	for (int i = 0; i < linhas; ++i){
		tabela[i] = malloc(sizeof(celula)*colunas);
	}

	readTable(nomeTabela, linhas, colunas, tabela);

	for (int i = 0; i < colunas; ++i){
		if(strcmp(tabela[0][i].valorCelula, nomeColuna)==0){
			return tabela[0][i].tipoCelula;
		}
	}

	printf("A coluna não existe. Insira novamente\n");
	
	scanf("%s", nomeColuna);
	return verificaTypeColumnSearch(nomeTabela, nomeColuna); //Chamada recursiva
}




// A função searchTable recebe o nome da tabela, o nome da coluna selecionada, a opção escolhida e o valor a ser pesquisado.
// Para cada opção ocorre a verificação do valor digitado em relação aos valores do arquivo e de acordo com a opção digitada.
void searchTable(char *nomeTabela, char *nomeColuna, int opcao, char *valorPesquisa){

	// Alocando matriz e preenchendo
	celula **tabela; //a tabela é uma matriz de celulas	
	int linhas = lengthLinesTable(nomeTabela);
	int colunas = lengthColumnsTable(nomeTabela);
	
	tabela = malloc(sizeof(celula *)*linhas); //linhas pra alocarmos o espaço dos dados que vão ser inseridos
	for (int i = 0; i < linhas; ++i){
		tabela[i] = malloc(sizeof(celula)*colunas);
	}

	readTable(nomeTabela, linhas, colunas, tabela);
	//fim alocando matriz e preenchendo

	//Encontra indice da coluna selecionada
	int i;
	for (i = 0; i < colunas; ++i){
		if(strcmp(tabela[0][i].valorCelula, nomeColuna)==0){ 
			break;
		}
	}

	int naoExisteValor = 1;
	switch(opcao){
		case 1:
			for(int j = 1; j < linhas; ++j){ 
				//Testa se valor informado é menor que o da tabela, se sim, imprime a linha
				if(atof(valorPesquisa) < atof(tabela[j][i].valorCelula)){ 
					printLineTable(nomeTabela, j); //j = linha
				}
			}
			;break;


		case 2:
			for(int j = 1; j < linhas; ++j){ 
				//Testa se valor informado é menor ou igual que o da tabela, se sim, imprime a linha
				if(atof(valorPesquisa) <= atof(tabela[j][i].valorCelula)){ 
					printLineTable(nomeTabela, j); //j = linha
				}
			}		
			;break;


		case 3:
			for(int j = 1; j < linhas; ++j){ 
				//Testa se valor informado é menor ou igual que o da tabela, se sim, imprime a linha
				if(strcmp(tabela[j][i].valorCelula, valorPesquisa)==0){ 
					printLineTable(nomeTabela, j); //j = linha
					naoExisteValor = 0; // Existe um valor igual
				} 
			}	
			if(naoExisteValor){
				printf("Não existe valor igual no campo %s.\n", tabela[0][i].valorCelula);
				return;
			}
			;break;


		case 4:
				for(int j = 1; j < linhas; ++j){ 
					//Testa se valor informado é menor ou igual que o da tabela, se sim, imprime a linha
					if(atof(valorPesquisa) > atof(tabela[j][i].valorCelula)){ 
						printLineTable(nomeTabela, j); //j = linha
					}
				}
				;break;


		case 5:
				for (int j = 1; j < linhas; ++j){ 
					//Testa se valor informado é menor ou igual que o da tabela, se sim, imprime a linha
					if (atof(valorPesquisa) >= atof(tabela[j][i].valorCelula)){ 
						printLineTable(nomeTabela, j); //j = linha
					}
				}
				;break;

		default: 
			printf("Opção inválida.\n");
		}

	}


