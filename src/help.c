#include <stdio.h>
#include <stdlib.h>
#include "help.h"


void help(){
	system("clear");
	printf("Painel de Ajuda\n\n");
	printf("\t1. createTable - Cria uma tabela.\n\t2. selectTables - Exibe as tabelas existentes.\n");
	printf("\t3. deleteTable - Apaga uma tabela\n\t4. insertTable - Insire dados na tabela.\n");
	printf("\t5. showTables - Mostra os dados de uma tabela.\n\t6. removeLine - Remove uma linha de dados da tabela.\n");
	printf("\t7. searchTable - Pesquisa os dados de uma coluna.\n\t8. clear - Limpa a tela.\n");
	printf("\t9. help - Descrição dos comandos.\n\t10. quit - Fechar o programa.\n");
	printf("\n\n");
}