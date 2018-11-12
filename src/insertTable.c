#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "insertTable.h"
#include "operaColumnsBin.h"
#include "operaCellsBin.h"
#include "operaLinesBin.h"

typedef struct tcoluna{
    char tipoColuna[10];
    char nomeColuna[10];
} coluna;

typedef struct tcelula{
    char nomeColuna[10];
    char valorCelula[50];
} celula;

typedef struct tlinha{
    celula camposCelula[10]
} linha;

void insertTable(){ //insere nova linha
    char tabela[50];
    printf("Insira o nome da tabela: ");
    scanf("%s", &tabela);
    char dir[50] = "tables/";
    strcat(dir, tabela);
    int qtdColunas = lengthTableBin(dir);
    coluna aux_colunas[qtdColunas];
    readTableBin(dir, aux_colunas);
    
    for(int i = 0; i < qtdColunas; i++){
        printf("%s %s\t", aux_colunas[i].tipoColuna, aux_colunas[i].nomeColuna);
    }

    int valorCelulaInt;
    char valorCelulaString[50];

    for(int i = 0; i < qtdColunas; i++){
        printf("Insira %s:", aux_colunas[i].nomeColuna);
        do{

            if (strcmp(aux_colunas[i].tipoColuna, "int")==0 || strcmp(aux_colunas[i].tipoColuna, "int(PK)")){
                while(1){
                    scanf("%d", valorCelulaInt);
                    if((int)valorCelulaInt){

                        break;
                    } else{
                        printf("O valor informado não é do tipo inteiro. Tente novamente.\n");
                        continue;
                    }
                }
            } else if(strcmp(aux_colunas[i].tipoColuna, "char")==0){
                while(1){
                    scanf("%d", valorCelulaInt);
                    if((char)valorCelulaString){

                        break;
                    } else{
                        printf("O valor informado não é do tipo inteiro. Tente novamente.\n");
                        continue;
                    }
                }
            }

        } while();



    }




    
    printf("\n");

}
