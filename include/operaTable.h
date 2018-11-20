#ifndef OPERATABLE_H_INCLUDED
#define OPERATABLE_H_INCLUDED

typedef struct tcelula celula;

/* A função diretorioArquivo recebe o nome da tabela e o adiciona 
na outra string recebida no seguinte formato: "dir/nomeTabela.bin" */
char * diretorioArquivo(char *nomeTabela, char *dir);

/* A função createTableBin recebe o nome da tabela, a matriz já preenchida com os dados, as linhas e colunas.
Com essas informações é gerado um arquivo nomeTabela.bin na pasta bin/ */
void createTableBin(char *nomeTabela, int linhas, int colunas, celula **matrizCelulas);

void readTableBin(char *nomeTabela, int linhas, int colunas, celula **aux_matrizCelulas);

int lengthLinesTableBin(char *nomeTabela);

int lengthColumnsTableBin(char *nomeTabela);

void printTableBin(char *nomeTabela);

void printColumnsTableBin(char *nomeTabela)

#endif // OPERATABLE_H_INCLUDED