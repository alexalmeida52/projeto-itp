#ifndef OPERAINSERTTABLE_H_INCLUDED
#define OPERAINSERTTABLE_H_INCLUDED

typedef struct tcelula celula;
	
/*Verifica se o valor informado é inteiro e se já existe na tabela.
Caso exista, pede para o usuario informar o valor novamente até que
seja válido para inserção.*/
char * verificaChavePrimaria(char *valorCelulaString, celula **aux_tabela, int coluna, char *nomeTabela);


/*Verifica se o valor informado é inteiro e se já existe na tabela.
Caso exista, pede para o usuario informar o valor novamente até que
seja válido para inserção.*/
char * verificaInt(char *valorCelulaString, celula **aux_tabela, int coluna);

char * verificaFloat(char *valorCelulaString, celula **aux_tabela, int coluna);

char * verificaDouble(char *valorCelulaString, celula **aux_tabela, int coluna);

void panelInsertTable(char *nomeTabela, celula **aux_colunas);

#endif // OPERAINSERTTABLE_H_INCLUDED