#ifndef OPERACOLUMNSBIN_H_INCLUDED
#define OPERACOLUMNSBIN_H_INCLUDED

typedef struct tcoluna coluna;
typedef struct tcelula celula;
void createColumnsBin(char *tabela, int qtdCampos, coluna *campo);
void readColumnsBin(char *tabela, coluna *aux_campos);
void printColumnsBin(char *tabela);
int lengthColumnsBin(char *tabela);
void createCelulaBin(char *tabela, int qtdCampos, celula *campo);

#endif // OPERACOLUMNSBIN_H_INCLUDED