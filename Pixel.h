typedef struct{
	int x, y;
}Pixel;

void mostra_pixel( void *x );
void carrega_pixel(Pixel *p, int x, int y);
int get_x(Pixel *p);
int get_y(Pixel *p);
