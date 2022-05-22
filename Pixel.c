#include <stdlib.h>
#include <stdio.h>
#include "Pixel.h"

void mostra_pixel( void *x ){
	Pixel *p = x;
	printf("(%d, %d)\n", p->x, p->y);
}

void carrega_pixel(Pixel *p,int x, int y){
	p->x = x;
	p->y = y;
}

int get_x(Pixel *p){
	return p->x;
}
int get_y(Pixel *p){
	return p->y;
}
