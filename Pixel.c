#include <stdlib.h>
#include <stdio.h>
#include "Pixel.h"

void mostra_pixel( void *x ){
	Pixel *p = x;
	printf("(%d, %d)\n", p->x, p->y);
}

void carrega_pixel(int x, int y, void *pix ){
	Pixel *p = pix;
	p->x = x;
	p->y = y;
}
