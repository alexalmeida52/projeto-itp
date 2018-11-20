#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createTable.h"
#include "operaTable.h"
#include "panel.h"

typedef struct tcelula{
	char tipoCelula[10];
	char valorCelula[10];
} celula;

char * verificaTipoColuna(char * tipoColuna){ //Função recursiva que obriga o usuário a digitar o tipo correto

	char tipo[50];
	if(strcmp(tipoColuna, "int")==0){
		return tipoColuna;
	} else if(strcmp(tipoColuna, "float")==0){
		return tipoColuna;
	} else if(strcmp(tipoColuna, "double")==0){
		return tipoColuna;
	} else if(strcmp(tipoColuna, "char")==0){
		return tipoColuna;
	} else if(strcmp(tipoColuna, "string")==0){
		return tipoColuna;
	} else {
		printf("Tipo inválido. Os únicos tipos possíveis são: int, float, double, char e string.\n\nInsira novamente: ");
		scanf("%s", &tipo);
		return verificaTipoColuna(tipo);
	}
}

void createTable(){
	FILE *file;
	char dir[100]= "tables/";
	char nome[100];
	int qtdColunas;
	celula **tabela; //a tabela é uma matriz de celulas
	printf("Nome da tabela: ");
	scanf("%s", nome);
	strcat(dir, nome);
	printf("%s\n", dir);
	printf("Quantos campos: ");
	scanf("%d", &qtdColunas);

	char tipoColuna[50];
	
	if(((int)qtdColunas)){ 
		
		tabela = malloc(sizeof(celula *)*1); //para armazenar as colunas precisamos de somente uma linha
		for (int i = 0; i < 1; ++i){
			tabela[i] = malloc(sizeof(celula)*qtdColunas);
		} // tabela[1][qtdColunas]



		printf("Nome da coluna (chave primária)[1]: ");
		scanf("%s", tabela[0][0].valorCelula);
		strcpy(tabela[0][0].tipoCelula, "int(PK)");

		for (int i = 1; i < qtdColunas; i++){
			printf("Nome da coluna[%d]: ", i+1);
			scanf("%s", tabela[0][i].valorCelula);
			printf("Tipo da coluna[%d]: ", i+1);
			scanf("%s",tipoColuna);
			strcpy(tabela[0][i].tipoCelula, verificaTipoColuna(tipoColuna));
		}

		file = fopen(dir, "w");
		if (file!=NULL){
			for (int i = 0; i < qtdColunas; ++i){
				fprintf(file, "{%s} %s\t\t", tabela[0][i].tipoCelula, tabela[0][i].valorCelula);
			}
			system("clear");
			panel();
			printf("Tabela criada com sucesso.\n\n");
			fclose(file);

		} else {
			printf("Arquivo não encontrado.\n");
			fclose(file);
		}
	} else {
		printf("Error. Digite um valor inteiro.\n");
	}

	printf("%s\n", nome);
	createTableBin(nome, 1, qtdColunas, tabela);

	celula **aux_tabela;

	aux_tabela = malloc(sizeof(celula *)*1); //para armazenar as colunas precisamos de somente uma linha
	for (int i = 0; i < 1; ++i){
		aux_tabela[i] = malloc(sizeof(celula)*qtdColunas);
	} // aux_tabela[1][qtdColunas]

	readTableBin(nome, 1, qtdColunas, aux_tabela);

	for (int i = 0; i < 1; ++i)
	{
		for (int j = 0; j < qtdColunas; ++j)
		{
			printf("%s %s\n", aux_tabela[i][j].tipoCelula, aux_tabela[i][j].valorCelula);
		}
	}
}
