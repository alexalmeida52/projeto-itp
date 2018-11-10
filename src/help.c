#include <stdio.h>
#include <stdlib.h>
#include "help.h"


void help(){
	system("clear");
	printf("Painel de Ajuda\n\n");
	printf("\t1. createTable - Cria uma tabela.\n\t2. updateTable - Atualiza uma tabela.\n");
	printf("\t3. selectTables - Exibe as tabelas existentes.\n\t4. deleteTable - Apaga uma tabela\n");
	printf("\t5. help - Descrição dos comandos.\n\t6. clear - Limpa a tela.\n");
	printf("\t7. read - Sobre o sistema.\n\t8. sair - Finaliza a execução do programa.\n");
	printf("\n\n");
}
