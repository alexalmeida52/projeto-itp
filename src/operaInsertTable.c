#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operaInsertTable.h"
#include "operaColumnsBin.h"

typedef struct tcoluna{
    char tipoColuna[10];
    char nomeColuna[10];
} coluna;

typedef struct tcelula{
    char valorCelula[50];
} celula;

typedef struct tlinha{
    celula vetorCelula[10];
} linha;

	
/*Verifica se o valor informado é inteiro e se já existe na tabela.
Caso exista, pede para o usuario informar o valor novamente até que
seja válido para inserção.*/
char * verificaChavePrimaria(char *valorCelulaString, coluna *aux_colunas, int i){
    
    char op1;
    char valorString[50];

    if (atoi(valorCelulaString)){ // Verifica se tem existe letra, se sim, o atoi retorna 0
        return valorCelulaString;
        // verificar se PK já existe
        
    } else {
        printf("\nErro. Você está inserindo um valor que não é INTEIRO ou que é NULO(zero).\n");
        printf("Você deseja inserir outro valor na coluna %s que não seja nulo(zero)?(s/n) ", aux_colunas[i].nomeColuna);
        scanf(" %c", &op1);
        if (op1=='s'){
            printf("\nInsira novamente o %s: ", aux_colunas[i].nomeColuna);
            scanf("%s", &valorString);
            return verificaChavePrimaria(valorString, aux_colunas, i);
        	
        } else {
        	strcpy(valorCelulaString, "0");
        	return valorCelulaString;
        }
    }
}


/*Verifica se o valor informado é inteiro e se já existe na tabela.
Caso exista, pede para o usuario informar o valor novamente até que
seja válido para inserção.*/
char * verificaInt(char *valorCelulaString, coluna *aux_colunas, int i){
    
    char op1;
    char valorString[50];

    if (atoi(valorCelulaString)){ // Verifica se tem existe letra, se sim, o atoi retorna 0
        return valorCelulaString;
    } else {
        printf("\nErro. Você está inserindo um valor que não é INTEIRO ou que é NULO(zero).\n");
        printf("Você deseja inserir outro valor na coluna %s que não seja nulo(zero)?(s/n) ", aux_colunas[i].nomeColuna);
        scanf(" %c", &op1);
        if (op1=='s'){
            printf("\nInsira novamente o %s: ", aux_colunas[i].nomeColuna);
            scanf("%s", &valorString);
            return verificaInt(valorString, aux_colunas, i);
        } else {
        	strcpy(valorCelulaString, "0");
        	return valorCelulaString;
        }
    }
}

float verificaFloat(char *valorCelulaString, coluna *aux_colunas, int i){
    
    char op1;
    char valorString[50];
    float valorDouble = atof(valorCelulaString); //se tem existe letra, se sim, o atof retorna 0
    float valorFloat = (float)valorDouble; //o atof retorna double por isso tem que converter em float

    if (valorFloat){ //Se for zero quer dizer que o valor insero foi inválido ou foi zero mesmo
        printf("O valorCelulaInt: %d é inteiro ehehe\n", atof(valorCelulaString));   
        return valorFloat;
    } else {
        printf("\nErro. Você está inserindo um valor que não é FLOAT ou que é NULO(zero).\n");
        printf("Você deseja inserir outro valor na coluna %s que não seja nulo(zero)?(s/n) ", aux_colunas[i].nomeColuna);
        scanf(" %c", &op1);
        if (op1=='s'){
            printf("\nInsira novamente o %s: ", aux_colunas[i].nomeColuna);
            scanf("%s", &valorString);
            return verificaFloat(valorString, aux_colunas, i);
        } else {
        	return 0;
        }
    }
}


double verificaDouble(char *valorCelulaString, coluna *aux_colunas, int i){
    
    char op1;
    char valorString[50];

    if (atof(valorCelulaString)){ // Verifica se tem existe letra, se sim, o atof retorna 0
            
        printf("O valorCelulaInt: %d é inteiro ehehe\n", atof(valorCelulaString));   
        return atof(valorCelulaString);
        // verificar se PK já existe
        // código para inserir o campo no arquivo.

    } else {
        printf("\nErro. Você está inserindo um valor que não é DOUBLE ou que é NULO(zero).\n");
        printf("Você deseja inserir outro valor na coluna %s que não seja nulo(zero)?(s/n) ", aux_colunas[i].nomeColuna);
        scanf(" %c", &op1);
        if (op1=='s'){
            printf("\nInsira novamente o %s: ", aux_colunas[i].nomeColuna);
            scanf("%s", &valorString);
            return verificaDouble(valorString, aux_colunas, i);
            //verificar se a PK já existe
        } else {
            return 0;
        }
    }
}

void panelInsertTable(char *tabela, coluna *aux_colunas, int qtdColunas, linha aux_linha){
	system("clear");
	printf("Tabela selionada: %s\n\n", tabela);
	printf("Colunas:\n");
	printColumnsBin(tabela);
	printf("\n");
	for (int i = 0; i < qtdColunas; i++){
		printf("%s\t", aux_linha.vetorCelula[i].valorCelula);
	}
	printf("\n\n\n");
}