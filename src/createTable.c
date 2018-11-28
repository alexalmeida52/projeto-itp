#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createTable.h"
#include "operaTable.h"
#include "panel.h"
#include "operaInsertTable.h"

typedef struct tcelula{ // Definindo estrutura de todas as células das tabelas que serão criadas.
	char tipoCelula[10];
	char valorCelula[10];
} celula;


void createTable(){
	
	// Lendo o nome da tabela
	char nome[100];
	printf("Nome da tabela: "); 
	scanf("%s", nome);

	// Lendo a quantidade de colunas.
	char qtdColunas[10];
	printf("Quantos campos: ");
	scanf("%s", qtdColunas);
	char tipoColuna[50];

	// Declarando a matriz tabela que armazenará as colunas para serem salva no arquivo.
	celula **tabela; //a tabela é uma matriz de celulas
	int colunas;

	if(onlyNumbers(qtdColunas)){ // Verifica se a quantidade de colunas é um inteiro

		colunas = atoi(qtdColunas); // Converte  a quantidae de colunas que é uma string  para um inteiro.

		// Alocando uma matriz de uma linha pela quantidade de colunas informada.
		tabela = malloc(sizeof(celula *)*1); //para armazenar as colunas precisamos de somente uma linha
		for (int i = 0; i < 1; ++i){
			tabela[i] = malloc(sizeof(celula)*colunas); 
		} // tabela[1][colunas]

		printf("Nome da coluna (chave primária)[1]: ");
		scanf("%s", tabela[0][0].valorCelula);
		strcpy(tabela[0][0].tipoCelula, "int(PK)"); // Definindo a primeira coluna como chave primária.

		// Lendo os nomes e tipos das colunas e salvando na matriz tabela.
		for (int i = 1; i < colunas; i++){
			printf("Nome da coluna[%d]: ", i+1);
			scanf("%s", tabela[0][i].valorCelula);
			printf("Tipo da coluna[%d]: ", i+1);
			scanf("%s",tipoColuna);
			strcpy(tabela[0][i].tipoCelula, verificaTipoColuna(tipoColuna)); // O verificaTipoColuna é uma função recursiva que obriga o usuário digitar um tipo válido.
		}
	} else {
		printf("Error. Digite um valor inteiro.\n");
	}

	// Criar arquivo com os nomes e tipos da colunas
	writeTable(nome, 1, colunas, tabela); // 
}


char * verificaTipoColuna(char * tipoColuna){ //Função recursiva que obriga o usuário a digitar o tipo da coluna correto.

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
		scanf("%s", tipo);
		return verificaTipoColuna(tipo); // Chamada recursiva.
	}
}
