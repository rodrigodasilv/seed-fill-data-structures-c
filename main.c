#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "Pixel.h"
#include "PilhasGenericas.h"

int main(int argc, char *argv[]) {
	Matriz m;
	
	if (carrega_arquivo("arquivo_entrada.txt",&m)==ERRO_ABERTURA){
		printf("Erro na abertura do arquivo!");
		return -1;
	}
	
	
	mostra_matriz(&m);
	
	
	int x, y, COR;
	int S[] = {0, 0};
	int I[] = {0, 0};
	printf("Digite as coordenadas (x, y): ");
	scanf("%d%d", &x, &y);
	S[0] = x;
	S[1] = y;
	

	printf("Digite o valor para a nova cor: ");
	scanf("%d", &COR);
	

	PilhaGenerica p1;
	inicializa_pilha( &p1, m.lin * m.col, sizeof( Pixel ) );
	
	
	int ORIG = get_valor( &m, S[0], S[1]);
	
	
	empilha( &p1, &S );
	while( !pilha_vazia( p1 ) ){
		Pixel K;
		desempilha(&p1, &K);
		
		
		if(get_valor( &m, K.x, K.y) != COR){
			set_valor(&m, K.x, K.y,COR);
			
			if((K.x+1 < m.lin ) && (get_valor( &m, K.x+1, K.y) == ORIG)){
				Pixel I = {K.x+1, K.y};
				empilha( &p1, &I );
			}
			
			if((K.x-1 >= 0 ) && (get_valor( &m, K.x-1, K.y) == ORIG)){
				Pixel I = {K.x-1, K.y};
				empilha( &p1, &I );
			}
			
			if((K.y+1 < m.col) && (get_valor( &m, K.x, K.y+1) == ORIG)){
				Pixel I = {K.x, K.y+1};
				empilha( &p1, &I );
			}
			
			if((K.y-1 >= 0) && (get_valor( &m, K.x, K.y-1) == ORIG)){
				Pixel I = {K.x, K.y-1};
				empilha( &p1, &I );
			}
		} 	
	}
	printf("\n");
	mostra_matriz(&m);
	escreve_arquivo("arquivo_saida.txt",&m);
	desaloca_matriz(&m);
	
	return 0;
}