#ifndef OPERAINSERTTABLE_H_INCLUDED
#define OPERAINSERTTABLE_H_INCLUDED


typedef struct tcoluna coluna;
typedef struct tcelula celula;
typedef struct tlinha linha;
int verificaChavePrimaria(char *valorCelulaString, coluna *aux_colunas, int i);
int verificaInt(char *valorCelulaString, coluna *aux_colunas, int i);
float verificaFloat(char *valorCelulaString, coluna *aux_colunas, int i);
double verificaDouble(char *valorCelulaString, coluna *aux_colunas, int i);
void panelInsertTable(char *tabela, coluna *aux_colunas);

#endif // OPERAINSERTTABLE_H_INCLUDED