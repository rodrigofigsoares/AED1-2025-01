typedef struct Cubo cubo;

cubo * cria_cubo(double aresta);

double lado_cubo(cubo * cube);

double area_cubo(cubo * cube);

double volume_cubo(cubo * cube);

void destroi_cubo(cubo * cube);