#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "Pixel.h"
#include "PilhasGenericas.h"

int main(int argc, char *argv[]) {
	Matriz m;
	if (carrega_arquivo("arquivo_entrada.txt",&m)==ERRO_ABERTURA){
		printf("Erro na abertura do arquivo!");
		return ERRO_ABERTURA;
	}
	mostra_matriz(&m);	
	int x, y, COR;
	Pixel S,I;
	printf("Digite as coordenadas (x, y): ");
	scanf("%d%d", &x, &y);
	carrega_pixel(&S,x,y);

	printf("Digite o valor para a nova cor: ");
	scanf("%d", &COR);

	PilhaGenerica p1;
	inicializa_pilha( &p1, get_capacidade(&m), sizeof(Pixel));
	if(get_valor( &m, get_x(&S), get_y(&S))==COORDENADA_INVALIDA){
		printf("Coordenada invalida!");
		return COORDENADA_INVALIDA;
	}
	int ORIG = get_valor( &m, get_x(&S), get_y(&S));
	
	empilha( &p1, &S );
	while( !pilha_vazia( p1 ) ){
		Pixel K;
		desempilha(&p1, &K);
		
		if(get_valor( &m, get_x(&K), get_y(&K)) != COR){
			set_valor(&m, get_x(&K), get_y(&K),COR);
			
			if((get_valor( &m, get_x(&K)+1, get_y(&K)) == ORIG)){
				carrega_pixel(&I,get_x(&K)+1, get_y(&K));
				empilha( &p1, &I );
			}
			
			if((get_valor( &m, get_x(&K)-1, get_y(&K)) == ORIG)){
				carrega_pixel(&I,get_x(&K)-1, get_y(&K));
				empilha( &p1, &I );
			}
			
			if((get_valor( &m, get_x(&K), get_y(&K)+1) == ORIG)){
				carrega_pixel(&I,get_x(&K), get_y(&K)+1);
				empilha( &p1, &I );
			}
			
			if((get_valor( &m, get_x(&K), get_y(&K)-1) == ORIG)){
				carrega_pixel(&I,get_x(&K), get_y(&K)-1);
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
