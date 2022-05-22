#define COORDENADA_INVALIDA -1
#define ERRO_ABERTURA -1

typedef struct{
	int **dados;
	int lin, col;
} Matriz;

void inicializa_matriz(Matriz *p,int l,int c);
void mostra_matriz(Matriz *x);
void desaloca_matriz(Matriz *y);
int set_valor(Matriz *z, int l, int c, int valor);
int get_valor(Matriz *z, int l, int c);
int carrega_arquivo(char *nome, Matriz *p);
int escreve_arquivo(char *nome, Matriz *p);
int get_capacidade(Matriz *w);
