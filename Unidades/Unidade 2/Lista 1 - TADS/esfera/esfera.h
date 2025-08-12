typedef struct Esfera esfera;

esfera * cria_esfera(double raio);

double raio_esfera(esfera * sphere);

double area_esfera(esfera * sphere);

double volume_esfera(esfera * sphere);

void destroi_esfera(esfera * sphere);