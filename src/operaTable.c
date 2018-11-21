#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char NOME[100]; //armazena o nome da tabela
char DIR[100] = "bin/"; //armazena o diretorio onde será salvo os arquivos binarios
char EXT[5] = ".bin"; //extensao dos arquivos binarios

typedef struct tcelula{
	char tipoCelula[10];
	char valorCelula[10];
} celula;
 
/* A função diretorioArquivo recebe o nome da tabela e o adiciona 
na outra string recebida no seguinte formato: "dir/nomeTabela.bin" */
char * diretorioArquivo(char *nomeTabela, char *dir){
	strcpy(dir, "");
	strcpy(dir, DIR);
	strcpy(NOME, nomeTabela);
	strcat(dir, NOME);
	strcat(dir, EXT);
	return dir;
}

/* A função createTableBin recebe o nome da tabela, a matriz já preenchida com os dados, as linhas e colunas.
Com essas informações é gerado um arquivo nomeTabela.bin na pasta bin/ */
void createTableBin(char *nomeTabela, int linhas, int colunas, celula **matrizCelulas){ //matrizCelulas é a tabela em si
	char dir[100];
	diretorioArquivo(nomeTabela, dir); //escreve na string dir: "dir/nomeTabela.bin"
	FILE *arq;
	arq = fopen(dir,"wb");
	if(arq != NULL){
		
		fwrite(&linhas, sizeof(int), 1, arq); //armazena a qtd de linhas no primeiro espaço de inteiro
		fwrite(&colunas, sizeof(int), 1, arq);	//armazena a qtd de colunas no segundo espaço de inteiro
		
		for(int i=0; i<linhas; i++){ //armazena celula por celula na matriz
			for(int j=0; j<colunas; j++){
				fwrite(&matrizCelulas[i][j], sizeof(celula), 1, arq);
			}
		}

		fclose(arq);
	}
	else{
		printf("\ncreateTableBin: Erro ao abrir o arquivo para escrita!\n");
		exit(1);
	}
}

void readTableBin(char *nomeTabela, int linhas, int colunas, celula **aux_matrizCelulas){ //matrizCelulas é a tabela em si
	char dir[100];
	diretorioArquivo(nomeTabela, dir); //escreve na string dir: "dir/nomeTabela.bin"
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
		printf("\nreadTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}

int lengthLinesTableBin(char *nomeTabela){ //matrizCelulas é a tabela em si
	char dir[100];
	diretorioArquivo(nomeTabela, dir); //escreve na string dir: "dir/nomeTabela.bin"
	FILE *arq;
	arq = fopen(dir,"rb");

	int lin, col;

	if(arq != NULL){
		fread(&lin, sizeof(int), 1, arq);
		fread(&col, sizeof(int), 1, arq);
		fclose(arq);
	}
	else{
		printf("\nlengthLinesTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}

	return lin;
}

int lengthColumnsTableBin(char *nomeTabela){ //matrizCelulas é a tabela em si
	char dir[100];
	diretorioArquivo(nomeTabela, dir); //escreve na string dir: "dir/nomeTabela.bin"
	FILE *arq;
	arq = fopen(dir,"rb");

	int lin, col;

	if(arq != NULL){
		fread(&lin, sizeof(int), 1, arq);
		fread(&col, sizeof(int), 1, arq);
		fclose(arq);
	}
	else{
		printf("\nlengthColumnsTableBin: Erro ao abrir o arquivo para leitura!\n");
		exit(1);
	}

	return col;
}

void printTableBin(char *nomeTabela){

		int linhas = lengthLinesTableBin(nomeTabela);
		int colunas = lengthColumnsTableBin(nomeTabela);

		celula **tabela; //a tabela é uma matriz de celulas
		tabela = malloc(sizeof(celula *)*linhas);
		for (int i = 0; i < linhas; ++i){
			tabela[i] = malloc(sizeof(celula)*colunas);
		} // tabela[linhas][colunas]

		readTableBin(nomeTabela, linhas, colunas, tabela); //preenchendo a matriz tabela

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

void printColumnsTableBin(char *nomeTabela){

		int linhas = lengthLinesTableBin(nomeTabela);
		int colunas = lengthColumnsTableBin(nomeTabela);

		//Declara matriz para preenchê-la com dados da tabela passada nos parâmetros
		celula **tabela;
		tabela = malloc(sizeof(celula *)*linhas);
		for (int i = 0; i < linhas; ++i){
			tabela[i] = malloc(sizeof(celula)*colunas);
		} // tabela[linhas][colunas]

		readTableBin(nomeTabela, linhas, colunas, tabela); //Preenchendo a matriz tabela

		//imprimindo colunas
		for (int j = 0; j < colunas; ++j){
			printf("%s %s\t", tabela[0][j].tipoCelula, tabela[0][j].valorCelula);
		}
		printf("\n");
}



/*int main(void) {
  
  char tabela[] = "minhaTabela";

  celula matrizCelula[2][3];

  strcpy(matrizCelula[0][0].tipoCelula, "int");
  strcpy(matrizCelula[0][0].valorCelula, "ola");
  strcpy(matrizCelula[0][1].tipoCelula, "char");
  strcpy(matrizCelula[0][1].valorCelula, "hehe");


  createTableBin(tabela, 2, 3, matrizCelula);

  celula aux_matrizCelula[2][3];

  readTableBin(tabela, 2, 3, aux_matrizCelula);

  printf("%s %s\n", aux_matrizCelula[0][0].tipoCelula, aux_matrizCelula[0][0].valorCelula);
  printf("%s %s\n", aux_matrizCelula[0][1].tipoCelula, aux_matrizCelula[0][1].valorCelula);

  aa(tabela);
  return 0;
}*/