#ifndef OPERATABLE_H_INCLUDED
#define OPERATABLE_H_INCLUDED

typedef struct tcelula celula;

/* A função diretorioArquivo recebe o nome da tabela e o adiciona 
na outra string recebida no seguinte formato: "tables/nomeTabela" */
char * diretorioArquivo(char *nomeTabela, char *dir);

/* A função createTable recebe o nome da tabela, a matriz já preenchida com os dados, as linhas e colunas.
Com essas informações é gerado um arquivo nomeTabela na pasta tables/ */
void writeTable(char *nomeTabela, int linhas, int colunas, celula **matrizCelulas);

void readTable(char *nomeTabela, int linhas, int colunas, celula **aux_matrizCelulas);

int lengthLinesTable(char *nomeTabela);

int lengthColumnsTable(char *nomeTabela);

void printTable(char *nomeTabela);

void printColumnsTable(char *nomeTabela);

void printLineTable(char *nomeTabela, int linha);

#endif // OPERATABLE_H_INCLUDED 