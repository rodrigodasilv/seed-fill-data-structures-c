#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arquivo.h"

int le_arquivo(FILE *arquivo, Matriz *m){
    if (arquivo == NULL) {
        return ERRO_ABERTURA;
    } else {
    	int altura, largura, ii, jj, numero;

    	if(fscanf(arquivo, "%d%d", &altura, &largura) != 2){
        	return ERRO_ABERTURA;
    	}else{
    		inicializa_matriz(m,altura,largura);
		}
    	
	    for(jj=0; jj<altura; jj++){
	        for(ii=0; ii<largura; ii++){
	            fscanf( arquivo, "%d", &numero);
	            set_valor(m,jj,ii,numero);
	        }
	    }
	    fclose(arquivo);
		return 1;  
    }	
}
