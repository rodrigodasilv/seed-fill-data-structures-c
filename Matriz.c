#include <stdlib.h>
#include <stdio.h>
#include "Matriz.h"

void inicializa_matriz(Matriz *p,int l,int c){
	int i,j;
	(*p).dados= malloc(sizeof(int *)*l);
	for(i=0;i<l;i++){
		(*p).dados[i] = malloc(sizeof(int)*c);
		for(j=0; j<c;j++){
			(*p).dados[i][j] = 0;
		}
	}
	(*p).lin = l;
	(*p).col = c;
}

void mostra_matriz(Matriz *x){
	printf("Dados da Matriz (%dx%d):\n",(*x).lin,(*x).col);
	int i,j;
	for(i=0;i< (*x).lin; i++){
		for(j=0;j< (*x).col; j++){
			printf("%4i ", (*x).dados[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void desaloca_matriz(Matriz *y){
	int i;
	for(i=0; i<(*y).lin ;i++){
		free((*y).dados[i]);
	}
	free((*y).dados);
}

int set_valor(Matriz *z, int l, int c, int valor){
	if (l>=(*z).lin || c>=(*z).col)
		return COORDENADA_INVALIDA;
	(*z).dados[l][c] = valor;
	return 0;
}

int get_valor(Matriz *z, int l, int c){
	if (l>=z->lin || c>=z->col || l<0 || c<0)
		return COORDENADA_INVALIDA;
	return z->dados[l][c];
}

int get_capacidade(Matriz *w){
	return w->col*w->lin;
}

int carrega_arquivo(char *nome, Matriz *p){
	FILE *f = fopen(nome, "r");
	if (f==NULL)
		return ERRO_ABERTURA;
		
	int linha, coluna, ii, jj, numero;

	if(fscanf(f, "%d %d", &linha, &coluna) != 2)
    	return ERRO_ABERTURA;
	
	inicializa_matriz(p,linha,coluna);	
    for(ii=0; ii<linha; ii++){
        for(jj=0; jj<coluna; jj++){
            fscanf( f, "%d", &numero);
            set_valor(p,ii,jj,numero);
        }
    }
	    
	fclose(f);
	return 1;
}

int escreve_arquivo(char *nome, Matriz *p){
	FILE *f = fopen(nome, "w");
	if (f==NULL)
		return ERRO_ABERTURA;
		
	fprintf(f,"%d %d \n",p->lin, p->col);
	int i,j;
	for(i=0;i< p->lin; i++){
		for(j=0;j< p->col; j++){
			fprintf(f,"%i ", p->dados[i][j]);
		}
		fprintf(f,"\n");
	}
	fclose(f);
	return 1;
}
