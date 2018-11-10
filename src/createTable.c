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
                for (int i = 0; i < qtdCampos; ++i){
                    fprintf(file, "{%s} %s\t\t", campo[i].tipoColuna, campo[i].nomeColuna);
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


/*    void insertTable(){ //insere nova linha

        char tabela[50];
        printf("Insira o nome da tabela: ");
        scanf("%s", &tabela);

        DIR *dir;
        dir = opendir("tables/");
        struct dirent *lsdir;
        while( (lsdir = readdir(dir)) != NULL){

        	if((strcmp(lsdir->d_name, tabela)==0)){



        	} else {
                printf("Erro. Tabela não existe. Tente novamente.\n");
        	}
        }
        printf("\n");

    }
*/