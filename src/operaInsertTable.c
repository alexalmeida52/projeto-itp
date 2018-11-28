#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operaInsertTable.h"
#include "operaTable.h"
#include <ctype.h>

typedef struct tcelula{ // Definindo estrutura de todas as células das tabelas que serão criadas.
	char tipoCelula[10];
	char valorCelula[10];
} celula;
	
int onlyNumbers(char *s){ //Verifica se a string é composta por apenas dígitos
	int len = strlen(s); //len = quatidade de letras
	for(int i = 0; i < len; i++){
		if(isdigit(s[i])==0){ // Verifica se possui caracteres e se é diferente de ponto
			return 0;
		}
	}
	return 1; // Returna 1 se a string possuir apenas de digitos 
}

int onlyRationalNumbers(char *s){ //Verifica se a string é composta por apenas dígitos e somente um ponto
	int cont=0;
	int len = strlen(s);
	for(int i = 0; i < len; i++){
		if(isdigit(s[i])==0){ // Verifica se o caractere da string é diferente de número, se for: 
			
			if ( s[i] == '.'){ // Verifica se é igual a um ponto.
				cont++; // Se sim some a cont.
			} else {
				return 0; // Se não retorne 0.
			}
		}
	}
	if ((cont > 1) || (s[0] == '.')){
		return 0; // Returna 0 se a string possuir mais de um ponto ou começar por um.
	} else {
		return 1; // Retorna 1 se a string possuir apenas digitos e somente um ponto.
	}
}

// A função verificaChavePrimaria verifica se a string inserida pelo usuario é um inteiro.
// Se sim, a função também verifica se o valor inserido já existe na tabela, se sim, é pedido
// que o usuário informe outro valor. Se o número iserido em algum momento não for inteiro, é
// pedido para o usuário informar um valor válido e verifica-o de novo utilizando a própria função. 
char * verificaChavePrimaria(char *valorCelulaString, celula **aux_tabela, int coluna, char *nomeTabela){

	char valorString[50];
	int linhas = lengthLinesTable(nomeTabela);

	if (onlyNumbers(valorCelulaString)){ // Se existir letra na variavel o onlyNumbers retorna 0

		for (int i = 0; i < linhas; i++){
			
			if (strcmp(aux_tabela[i][coluna].valorCelula, valorCelulaString)==0){
				printf("\nO valor inserido já existe. Insira novamente o %s: ", aux_tabela[0][coluna].valorCelula);
				scanf("%s", valorString);
				return verificaChavePrimaria(valorString, aux_tabela, coluna, nomeTabela);
			}

		}

		return valorCelulaString;
		
		
	} else {
		printf("\nErro. Você está inserindo um valor que não é INTEIRO.\n");
		printf("\nInsira novamente o %s: ", aux_tabela[0][coluna].valorCelula);
		scanf("%s", valorString);
		return verificaChavePrimaria(valorString, aux_tabela, coluna, nomeTabela);  //Chamada recursiva
		
	}
}


// A função verificaInt verifica se a string inserida pelo usuario é realmente um inteiro.
// Se sim, a função retorna a mesma string. Se não, pede para o usuário informar outro valor
// e verifica novamente utilizando a própria função.
char * verificaInt(char *valorCelulaString, celula **aux_tabela, int coluna){

	char valorString[50];

	if (onlyNumbers(valorCelulaString)){ // Se existir letra na variavel o onlyNumbers retorna 0
		return valorCelulaString;
	} else {
		printf("\nErro. Você está inserindo um valor que não é INTEIRO.\n");
		printf("\nInsira novamente o %s: ", aux_tabela[0][coluna].valorCelula);
		scanf("%s", valorString);
		return verificaInt(valorString, aux_tabela, coluna);  //Chamada recursiva
		
	}
}


// A função verificaFloat verifica se a string inserida pelo usuario é realmente um float.
// Se sim, a função retorna a mesma string. Se não, pede para o usuário informar outro valor
// e verifica novamente utilizando a própria função.
char * verificaFloat(char *valorCelulaString, celula **aux_tabela, int coluna){

	char valorString[50];
	

	if (onlyRationalNumbers(valorCelulaString)){ //Se for zero quer dizer que o valor inserido foi inválido ou foi zero mesmo
		return valorCelulaString;
	} else {
		printf("\nErro. Você está inserindo um valor que não é float.\n");		
		printf("\nInsira novamente o %s: ", aux_tabela[0][coluna].valorCelula);
		scanf("%s", valorString);
		return verificaFloat(valorString, aux_tabela, coluna);  //Chamada recursiva
		
	}
}


// A função verificaDouble verifica se a string inserida pelo usuario é realmente um double.
// Se sim, a função retorna a mesma string. Se não, pede para o usuário informar outro valor
// e verifica novamente utilizando a própria função.
char * verificaDouble(char *valorCelulaString, celula **aux_tabela, int coluna){
	char valorString[50];

	if (onlyRationalNumbers(valorCelulaString)){ // Se existir letra na variavel ou mais de um ponto o onlyRationalNumbers retorna 0.
		return valorCelulaString;
	} else {
		printf("\nErro. Você está inserindo um valor que não é INTEIRO.\n");
		printf("\nInsira novamente o %s: ", aux_tabela[0][coluna].valorCelula);
		scanf("%s", valorString);
		return verificaDouble(valorString, aux_tabela, coluna);  //Chamada recursiva
		
	}
}

// A função verificaChar verifica se a string inserida pelo usuario é realmente um char.
char * verificaChar(char *valorCelulaString, celula **aux_tabela, int coluna){
	char valorChar[2];
	if (strlen(valorCelulaString)==1){ //Se o tamanho da string for igual a 1 então o próprio valor é retornado, senão é pedido para inserir  novo valor
		return valorCelulaString; 
	} else {
		printf("\nErro. Você está inserindo um valor que não é do tipo char.\n");
		printf("\nInsira novamente o %s: ", aux_tabela[0][coluna].valorCelula);
		scanf("%s", valorChar);
		return verificaChar(valorChar, aux_tabela, coluna); //Chamada recursiva
	}
}

//imprime o estado atual da tabela enquanto o usuario vai inserindo os campos
void panelInsertTable(char *nomeTabela, celula **aux_tabela){
	system("clear");
	printf("Tabela selionada: %s\n\n", nomeTabela);
	printf("Colunas:\n");
	
	printTable(nomeTabela); //imprime a tabela salva

	/* codigo para exibir a linha que o usuário esta inserindo */
	int linhas = lengthLinesTable(nomeTabela);
	int colunas = lengthColumnsTable(nomeTabela);
	for (int i = 0; i < colunas; i++){
		printf("%s\t\t", aux_tabela[linhas][i].valorCelula);
	}
	/* fim do codigo para exibir a linha que o usuário esta inserindo */
	printf("\n\n\n");
}