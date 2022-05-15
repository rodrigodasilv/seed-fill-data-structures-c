#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "Arquivo.h"

int main(int argc, char *argv[]) {
	Matriz m;
	FILE *arquivo = fopen("arquivo_entrada.txt", "r");
	if (le_arquivo(arquivo,&m)==ERRO_ABERTURA){
		printf("Erro na abertura do arquivo!");
	}else{
		mostra_matriz(&m);
	}
	desaloca_matriz(&m);
	return 0;
}
