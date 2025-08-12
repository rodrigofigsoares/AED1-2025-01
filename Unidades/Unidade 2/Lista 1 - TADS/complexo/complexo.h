typedef struct Complexo complexo;

complexo * cria_complexo(double real, double imaginaria);

void soma_complexo(complexo * complex1, complexo * complex2, complexo * complexSum);

void subtrai_complexo(complexo * complex1, complexo * complex2, complexo * complexSub);

void multiplica_complexo(complexo * complex1, complexo * complex2, complexo * complexProd);

double le_parte_real(complexo * complex);

double le_parte_imaginaria(complexo * complex);

void destroi_complexo(complexo * complex);