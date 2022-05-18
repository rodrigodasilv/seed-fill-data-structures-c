#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "Pixel.h"

int main(int argc, char *argv[]) {
	Matriz m;
	if (carrega_arquivo("arquivo_entrada.txt",&m)==ERRO_ABERTURA){
		printf("Erro na abertura do arquivo!");
	}else{
		mostra_matriz(&m);
		set_valor(&m,1,1,5);
		printf("%d \n",get_valor(&m,1,1));
		mostra_matriz(&m);
		escreve_arquivo("arquivo_saida.txt",&m);
		Pixel p1;
		carrega_pixel(1,5,&p1);
		mostra_pixel(&p1);
	}
	desaloca_matriz(&m);
	return 0;
}
