#include "../include/createTable.h"
#include <stdio.h>

struct coluna{
	char tipoColuna[10];
	char nomeColuna[10];
};

void createTable(){
    FILE *file;


	char dir[8]= "tables/";

	char nome[50];
    	int qtdCampos;
			struct coluna *campo;
			printf("Nome da tabela: ");
			scanf("%s", nome);

			strcat(dir, nome);
			printf("%s\n", dir);
			printf("Quantos campos: ");
			scanf("%d", &qtdCampos);
			if(((int)qtdCampos)){
                campo = malloc(sizeof(struct coluna)*qtdCampos);
                for (int i = 0; i < qtdCampos; i++){
                    printf("Nome da coluna[%d]: ", i+1);
                    scanf("%s", campo[i].nomeColuna);
                    printf("Tipo da coluna[%d]: ", i+1);
                    scanf("%s", campo[i].tipoColuna);
                }
                file = fopen(dir, "w");
                for (int i = 0; i < qtdCampos; ++i){
                    fprintf(file, "( %s ) %s\t\t", campo[i].tipoColuna, campo[i].nomeColuna);
                }
                if (file!=NULL){
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


}
