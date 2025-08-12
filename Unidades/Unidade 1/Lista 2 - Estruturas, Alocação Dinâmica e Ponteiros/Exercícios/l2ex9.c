#include <stdio.h>

int main() {
    int x = 7, y = 2;
    if(&x > &y) printf("&x > &y\n");
    else printf("&y > &x\n");
    return 0;
}