#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
struct coluna{
	char tipoColuna[10];
	char nomeColuna[10];
};

void ajuda(){
	system("clear");
	printf("Painel de Ajuda\n\n");
	printf("\t1. createTable - Cria uma tabela.\n\t2. updateTable - Atualiza uma tabela.\n");
	printf("\t3. selectTables - Exibe as tabelas existentes.\n\t4. deleteTable - Apaga uma tabela\n");
	printf("\t5. help - Descrição dos comandos.\n\t6. clear - Limpa a tela.\n");
	printf("\t7. read - Sobre o sistema.\n\t8. sair - Finaliza a execução do programa.\n");
	printf("\n\n");
}

void painel(){
	printf("Painel de comandos\n\n");
	printf("\t1. createTable\t\t2. updateTable\n");
	printf("\t3. selectTable\t\t4. deleteTable\n");
	printf("\t5. help\t\t\t6. clear\n");
	printf("\t7. read\t\t\t8. sair\n");
	printf("\n\n");
}

int main(int argc, char const *argv[])
{
	system("clear");
	FILE *file;
	
	painel();
	char op[50];
	char dir[8]= "tables/";
	char ext[5] = ".txt";
	char nome[50];
	do{
		printf("Digite uma opção: ");
		scanf("%s", &op);
		if (strcmp(op, "createTable")==0){
			int qtdCampos;
			struct coluna *campo;
			printf("Nome da tabela: ");
			scanf("%s", &nome);
			strcat(nome, ext);
			strcat(dir, nome);
			printf("%s\n", dir);
			printf("Quantos campos: ");
			scanf("%d", &qtdCampos);
			campo = malloc(sizeof(struct coluna)*qtdCampos);
			for (int i = 0; i < qtdCampos; i++){
				printf("Nome da coluna[%d]: ", i+1);
				scanf("%s", &campo[i].nomeColuna);
				printf("Tipo da coluna[%d]: ", i+1);
				scanf("%s", &campo[i].tipoColuna);
			}
			file = fopen(dir, "w");
			for (int i = 0; i < qtdCampos; ++i){
				fprintf(file, "%s %s\t", campo[i].tipoColuna, campo[i].nomeColuna);
			}
			if (file!=NULL){
				
				printf("Tabela criada com sucesso.\n");
				fclose(file);
				system("clear");
			} else {
				printf("Arquivo não encontrado.\n");
				fclose(file);
			}
			
		} else if(strcmp(op, "selectTable")==0){
				DIR *dir;
    			struct dirent *lsdir;
    			dir = opendir("tables/");
    			while( (lsdir = readdir(dir)) != NULL){
    				printf("%s\n", lsdir->d_name);
    			} 
    			printf("\n");

		} else if(strcmp(op, "help")==0){
				ajuda();
		} else if(strcmp(op, "clear")==0){
			system("clear");
			painel();
		}
	} while (!(strcmp(op, "sair")==0));
	system("clear");
	return 0;
}