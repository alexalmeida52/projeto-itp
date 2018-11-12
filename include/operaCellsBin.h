#ifndef OPERACELLSBIN_H_INCLUDED
#define OPERACELLSBIN_H_INCLUDED

typedef struct tcelula celula;
void createCellsBin(char *tabela, int qtdCampos, celula *campo);
void readCellsBin(char *tabela, celula *aux_campos);
void printCellsBin(char *tabela);
int lengthCellsBin(char *tabela);

#endif // OPERACELLSBIN_H_INCLUDED