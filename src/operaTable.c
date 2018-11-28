//Esse código possui as funções que manipulam os arquivos que armezenam as tabelas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tcelula{ // Definindo estrutura de todas as células das tabelas que serão criadas.
	char tipoCelula[10];
	char valorCelula[10];
} celula;

char NOME[100]; //a variável NOME armazena o nome da tabela
char DIR[100] = "tables/"; //a variável DIR armazena o diretorio onde será salvo os arquivos

/* A função diretorioArquivo recebe o nome da tabela e o adiciona 
na string dir no seguinte formato: "tables/nomeTabela" */
char * diretorioArquivo(char *nomeTabela, char *dir){
	strcpy(dir, "");
	strcpy(dir, DIR);
	strcpy(NOME, nomeTabela);
	strcat(dir, NOME);
	return dir;
}
 
//A função writeTable recebe o nome da tabela, as linhas, as colunas e uma matriz com os dados que queremos escrever no arquivo.
//Com essas informações é gerado o arquivo.
void writeTable(char *nomeTabela, int linhas, int colunas, celula **matrizCelulas){ //matrizCelulas é a tabela em si
	char dir[100];
	diretorioArquivo(nomeTabela, dir); //a função diretorioArquivo retorna o nome da tabela no formato correto "tables/nomeTabela"
	FILE *arq;
	arq = fopen(dir,"wb");
	if(arq != NULL){
		
		fwrite(&linhas, sizeof(int), 1, arq); //armazena a qtd de linhas da tabela no arquivo
		fwrite(&colunas, sizeof(int), 1, arq);	//em seguida, a qtd de colunas da tabela no arquivo
		
		for(int i=0; i<linhas; i++){ //e, por fim, celula por celula da tabela no arquivo
			for(int j=0; j<colunas; j++){
				fwrite(&matrizCelulas[i][j], sizeof(celula), 1, arq);
			}
		}

		fclose(arq);
	}
	else{
		printf("\nwriteTable: Erro ao abrir o arquivo para escrita!\n");
		exit(1);
	}
}

//A função lengthLinesTable recebe o nome da tabela e retorna seu número de linhas.
int lengthLinesTable(char *nomeTabela){ 
	char dir[100];
	diretorioArquivo(nomeTabela, dir); //a função diretorioArquivo retorna o nome da tabela no formato correto "tables/nomeTabela"
	FILE *arq;
	arq = fopen(dir,"rb");

	int lin, col;

	if(arq != NULL){
		fread(&lin, sizeof(int), 1, arq);
		fclose(arq);
	}
	else{
		printf("A tabela não existe, tente novamente!\n");
		exit(1);
	}

	return lin;
}


//A função lengthColumnsTable recebe o nome da tabela e retorna seu número de colunas.
int lengthColumnsTable(char *nomeTabela){
	char dir[100];
	diretorioArquivo(nomeTabela, dir);//a função diretorioArquivo retorna o nome da tabela no formato correto "tables/nomeTabela"
	FILE *arq;
	arq = fopen(dir,"rb");

	int lin, col;

	if(arq != NULL){
		fread(&lin, sizeof(int), 1, arq);
		fread(&col, sizeof(int), 1, arq);
		fclose(arq);
	}
	else{
		printf("\nlengthColumnsTable: Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}

	return col;
}


//A função readTable recebe o nome da tabela, as linhas, as colunas e uma matriz vazia para ser preenchida com os dados do arquivo.
void readTable(char *nomeTabela, int linhas, int colunas, celula **aux_matrizCelulas){
	char dir[100];
	diretorioArquivo(nomeTabela, dir); //a função diretorioArquivo retorna o nome da tabela no formato correto "tables/nomeTabela"
	FILE *arq;
	arq = fopen(dir,"rb");

	int lin, col;

	if(arq != NULL){
		fread(&lin, sizeof(int), 1, arq);
		fread(&col, sizeof(int), 1, arq);
		for(int i=0; i<lin; i++){
			for(int j=0; j<col; j++){
				fread(&aux_matrizCelulas[i][j], sizeof(celula), 1, arq);
			}
		}
		fclose(arq);
	}
	else{
		printf("\nreadTable: Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}

//A função printTable recebe o nome da tabela e imprime os dados salvos no arquivo.
void printTable(char *nomeTabela){

		//Declando linhas e colunas para alocar a matriz
		int linhas = lengthLinesTable(nomeTabela);
		int colunas = lengthColumnsTable(nomeTabela);

		//Alocando matriz tabela[linhas][colunas]
		celula **tabela; 
		tabela = malloc(sizeof(celula *)*linhas);
		for (int i = 0; i < linhas; ++i){
			tabela[i] = malloc(sizeof(celula)*colunas);
		}

		readTable(nomeTabela, linhas, colunas, tabela); //preenchendo a matriz tabela

		//imprimindo colunas
		for (int j = 0; j < colunas; ++j){
			printf("%s %s\t", tabela[0][j].tipoCelula, tabela[0][j].valorCelula);
		}
		printf("\n");
		//imprimindo valores
		for (int i = 1; i < linhas; ++i){ //começa de 1 porque a primeira linha já foi exibida
			for (int j = 0; j < colunas; ++j){
				printf("%s\t\t", tabela[i][j].valorCelula);
			}
			printf("\n");
		}
}

//A função printColumnsTable recebe o nome da tabela e imprime seu cabeça-lho.
void printColumnsTable(char *nomeTabela){

		//Declando linhas e colunas para alocar a matriz
		int linhas = lengthLinesTable(nomeTabela);
		int colunas = lengthColumnsTable(nomeTabela);

		//Alocando matriz tabela[linhas][colunas]
		celula **tabela;
		tabela = malloc(sizeof(celula *)*linhas);
		for (int i = 0; i < linhas; ++i){
			tabela[i] = malloc(sizeof(celula)*colunas);
		}

		readTable(nomeTabela, linhas, colunas, tabela); //Preenchendo a matriz tabela

		//imprimindo colunas
		for (int j = 0; j < colunas; ++j){
			printf("%s %s\t", tabela[0][j].tipoCelula, tabela[0][j].valorCelula);
		}
		printf("\n");
}

//A função printLineTable recebe o nome da tabela e uma linha específica para imprimi-la.
void printLineTable(char *nomeTabela, int linha){

		int linhas = lengthLinesTable(nomeTabela);
		int colunas = lengthColumnsTable(nomeTabela);

		//Declara matriz para preenchê-la com dados da tabela passada nos parâmetros
		celula **tabela;
		tabela = malloc(sizeof(celula *)*linhas);
		for (int i = 0; i < linhas; ++i){
			tabela[i] = malloc(sizeof(celula)*colunas);
		} // tabela[linhas][colunas]

		readTable(nomeTabela, linhas, colunas, tabela); //Preenchendo a matriz tabela

		//imprimindo linha específica
		for (int j = 0; j < colunas; ++j){
			printf("%s %s\t\t", tabela[linha][j].tipoCelula, tabela[linha][j].valorCelula);
		}
		printf("\n");
}

