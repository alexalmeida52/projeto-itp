#ifndef OPERACOLUMNSBIN_H_INCLUDED
#define OPERACOLUMNSBIN_H_INCLUDED

typedef struct tcoluna coluna;
void createTableBin(char *tabela, int qtdCampos, coluna *campo);
void readTableBin(char *tabela, coluna *aux_campos);
void printTableBin(char *tabela);
int lengthTableBin(char *tabela);

#endif // OPERACOLUMNSBIN_H_INCLUDED