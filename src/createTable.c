#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createTable.h"
#include "operaColumnsBin.h"
#include "panel.h"

typedef struct tcoluna{
    char tipoColuna[10];
    char nomeColuna[10];
} coluna;

void createTable(){
	FILE *file;
	char dir[100]= "tables/";
	char nome[100];
	int qtdCampos;
	coluna *campo;
	printf("Nome da tabela: ");
	scanf("%s", nome);
	strcat(dir, nome);
	printf("%s\n", dir);
	printf("Quantos campos: ");
	scanf("%d", &qtdCampos);
	
	if(((int)qtdCampos)){ 
		campo = malloc(sizeof(coluna)*qtdCampos);

		printf("Nome da coluna (chave primária)[1]: ");
		scanf("%s", campo[0].nomeColuna);
		strcpy(campo[0].tipoColuna, "int(PK)");

		for (int i = 1; i < qtdCampos; i++){
			printf("Nome da coluna[%d]: ", i+1);
			scanf("%s", campo[i].nomeColuna);
			printf("Tipo da coluna[%d]: ", i+1);
			scanf("%s", campo[i].tipoColuna);
		}

		file = fopen(dir, "w");
		if (file!=NULL){
			for (int i = 0; i < qtdCampos; ++i){
				fprintf(file, "{%s} %s\t\t", campo[i].tipoColuna, campo[i].nomeColuna);
			}
			system("clear");
			panel();
			printf("Tabela criada com sucesso.\n\n");
			fclose(file);

		} else {
			printf("Arquivo não encontrado.\n");
			fclose(file);
		}
	} else {
		printf("Error. Digite um valor inteiro.\n");
	}

	printf("%s\n", dir);
	createTableBin(dir, qtdCampos, campo);
}

