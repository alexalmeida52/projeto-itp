#include <stdlib.h>
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
    celula camposCelula[10];
} linha;

void insertTable(){ //insere nova linha
    char tabela[50];
    printf("Insira o nome da tabela: ");
    scanf("%s", &tabela);
    char dir[50] = "tables/";
    strcat(dir, tabela);
    int qtdColunas = lengthColumnsBin(tabela); //Era "dir" como parâmetro.
    

    coluna aux_colunas[qtdColunas];
    readColumnsBin(tabela, aux_colunas);
    
    for(int i = 0; i < qtdColunas; i++){
        printf("%s %s\t", aux_colunas[i].tipoColuna, aux_colunas[i].nomeColuna);

    } 
    printf("\n");

    int valorCelulaInt;
    char valorCelulaString[50];
    for(int i = 0; i < qtdColunas; i++){
        printf("Insira %s:", aux_colunas[i].nomeColuna);
        //do{ Sem o do while funciona da mesma forma.

            if ((strcmp(aux_colunas[i].tipoColuna, "int(PK)")==0)||(strcmp(aux_colunas[i].tipoColuna, "int")==0)){//condição alterado, pois não tava dando certo.
                while(1){
                    scanf("%d", &valorCelulaInt);//Tava faltando o &.
                    if((int)valorCelulaInt){ //Não tá funcionando com (int)valorCelulaInt.

                        break;
                    } else{
                        printf("O valor informado não é do tipo inteiro. Tente novamente.\n");
                        continue;
                    }
                }
            } else if(strcmp(aux_colunas[i].tipoColuna, "char")==0){
                while(1){
                    scanf("%s", valorCelulaString);
                    // falta a condição de para.
                    break;
                }
            } else if(strcmp(aux_colunas[i].tipoColuna, "float")==0){
                while(1){
                    scanf("%s", valorCelulaString);
                    // falta a condição de para.
                    break;
                }
            } else if(strcmp(aux_colunas[i].tipoColuna, "double")==0){
                while(1){
                    scanf("%s", valorCelulaString);
                    // falta a condição de para.
                    break;
                }
            }

        //} while(1);

            system("clear");

    }




    
    printf("\n");

}