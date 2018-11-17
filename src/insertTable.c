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
    int valorCelula;
    char valorCelulaString[50];
    for(int i = 0; i < qtdColunas; i++){
        printf("Insira o %s:", aux_colunas[i].nomeColuna);
        //do{ Sem o do while funciona da mesma forma.

            if ((strcmp(aux_colunas[i].tipoColuna, "int(PK)")==0)||(strcmp(aux_colunas[i].tipoColuna, "int")==0)){//condição alterado, pois não tava dando certo.
                while(1){
                    scanf("%s", &valorCelulaString);//Tava faltando o &.
                    if (atoi(valorCelulaString)){ // Verifica se tem existe letra.
                        // código para inserir o campo no arquivo.
                        break;
                    } else {
                        printf("Erro. Você não está inserindo um valor inteiro.\n");
                        printf("Insira novamente o %s:", aux_colunas[i].nomeColuna);
                        continue;
                    }
                    
                    
                }
            } else if(strcmp(aux_colunas[i].tipoColuna, "char")==0){
                while(1){
                    scanf("%s", valorCelulaString);
                    // código para inserir o campo no arquivo.
                    break;
                    
                }
            } else if(strcmp(aux_colunas[i].tipoColuna, "float")==0){
                while(1){
                    scanf("%s", valorCelulaString);
                    if (atoi(valorCelulaString)){ // Verifica se existe letra.
                        // código para inserir o campo no arquivo.
                        break;
                    } else {
                        printf("Erro. Você não está inserindo um valor float.\n");
                        printf("Insira novamente o %s:", aux_colunas[i].nomeColuna);
                        continue;
                    }
                    
                    
                    break;
                }
            } else if(strcmp(aux_colunas[i].tipoColuna, "double")==0){
                while(1){
                    scanf("%s", valorCelulaString);
                    if (atoi(valorCelulaString)){ // Verifica se tem existe letra.
                        // código para inserir o campo no arquivo.
                        break;
                    } else {
                        printf("Erro. Você não está inserindo um valor double.\n");
                        printf("Insira novamente o %s:", aux_colunas[i].nomeColuna);
                        continue;
                    }
                    break;
                }
            }

        //} while(1);


    }

        printf("Inserido com súcesso.\n");



    
    printf("\n");

}