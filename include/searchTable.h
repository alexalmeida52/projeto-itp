#ifndef SEARCHTABLE_H_INCLUDED
#define SEARCHTABLE_H_INCLUDED

typedef struct tcelula celula;

void searchTable(char *nomeTabela, char *nomeColuna, int opcao, char *valorPesquisa);

void panelSearchTable();

int optionsSearchTable(char *nomeTabela, char *coluna);

char * verificaTypeColumnSearch(char *nomeTabela, char * nomeColuna);

int onlyNumbers(char *s);

#endif // SEARCHTABLE_H_INCLUDED
