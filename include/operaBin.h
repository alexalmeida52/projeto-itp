#ifndef OPERABIN_H_INCLUDED
#define OPERABIN_H_INCLUDED

typedef struct tcoluna coluna;
void createTableBin(char *tabela, int qtdCampos, coluna *campo);
void readTableBin(char *tabela, coluna *aux_campos);
void printTableBin(char *tabela);
int lengthTableBin(char *tabela);

#endif // OPERABIN_H_INCLUDED