typedef struct ponto Ponto;

Ponto * ponto_cria(float x, float y);

void ponto_libera(Ponto *p);

int ponto_acessa(Ponto *p, float *x, float *y);

int ponto_atribui(Ponto *p, float x, float y);

float ponto_distancia(Ponto *p1, Ponto *p2);