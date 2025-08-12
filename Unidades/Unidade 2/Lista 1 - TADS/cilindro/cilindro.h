typedef struct Cilindro cilindro;

cilindro * cria_cilindro(double raio, double altura);

double altura_cilindro(cilindro * cilinder);

double raio_cilindro(cilindro * cilinder);

double area_cilindro(cilindro * cilinder);

double volume_cilindro(cilindro * cilinder);

void destroi_cilindro(cilindro * cilinder);