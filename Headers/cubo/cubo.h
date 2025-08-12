typedef struct Cubo cubo;

cubo * cria_cubo(float dim);

void destroi_cubo(cubo * cube);

float tamanho_aresta(cubo * cube);

float perimetro_cubo(cubo * cube);

float area_uma_face(cubo * cube);

float area_total(cubo * cube);

float volume_cubo(cubo * cube);

float diagonal(cubo * cube);

void atribui_aresta(cubo * cube, float nova_aresta);