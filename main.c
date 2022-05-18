#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

int main(int argc, char *argv[]) {
	Matriz m;
	if (carrega_arquivo("arquivo_entrada.txt",&m)==ERRO_ABERTURA){
		printf("Erro na abertura do arquivo!");
	}else{
		mostra_matriz(&m);
		set_valor(&m,1,1,5);
		mostra_matriz(&m);
		escreve_arquivo("arquivo_saida.txt",&m);
	}
	desaloca_matriz(&m);
	return 0;
}
