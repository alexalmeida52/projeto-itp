#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operaInsertTable.h"
#include "operaTable.h"

typedef struct tcelula{
	char tipoCelula[10];
	char valorCelula[10];
} celula;
	

// A função verificaChavePrimaria verifica se a string inserida pelo usuario é um inteiro.
// Se sim, a função também verifica se o valor inserido já existe na tabela, se sim, é pedido
// que o usuário informe outro valor. Se o número iserido em algum momento não for inteiro, é
// pedido para o usuário informar um valor válido e verifica-o de novo utilizando a própria função. 
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


// A função verificaInt verifica se a string inserida pelo usuario é realmente um inteiro.
// Se sim, a função retorna a mesma string. Se não, pede para o usuário informar outro valor
// e verifica novamente utilizando a própria função.
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


// A função verificaFloat verifica se a string inserida pelo usuario é realmente um float.
// Se sim, a função retorna a mesma string. Se não, pede para o usuário informar outro valor
// e verifica novamente utilizando a própria função.
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


// A função verificaDouble verifica se a string inserida pelo usuario é realmente um double.
// Se sim, a função retorna a mesma string. Se não, pede para o usuário informar outro valor
// e verifica novamente utilizando a própria função.
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

//imprime o estado atual da tabela enquanto o usuario vai inserindo os campos
void panelInsertTable(char *nomeTabela, celula **aux_tabela){
	system("clear");
	printf("Tabela selionada: %s\n\n", nomeTabela);
	printf("Colunas:\n");
	
	printTableBin(nomeTabela); //imprime a tabela salva

	/* codigo para exibir a linha que o usuário esta inserindo */
	int linhas = lengthLinesTableBin(nomeTabela);
	int colunas = lengthColumnsTableBin(nomeTabela);
	for (int i = 0; i < colunas; i++){
		printf("%s\t\t", aux_tabela[linhas][i].valorCelula);
	}
	/* fim do codigo para exibir a linha que o usuário esta inserindo */
	printf("\n\n\n");
}