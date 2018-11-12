#ifndef OPERALINESBIN_H_INCLUDED
#define OPERALINESBIN_H_INCLUDED

typedef struct tlinha linha;
void createLinesBin(char *tabela, int qtdCampos, linha *campo);
void readLinesBin(char *tabela, linha *aux_campos);
void printLinesBin(char *tabela);
int lengthLinesBin(char *tabela);

#endif // OPERALINESBIN_H_INCLUDED