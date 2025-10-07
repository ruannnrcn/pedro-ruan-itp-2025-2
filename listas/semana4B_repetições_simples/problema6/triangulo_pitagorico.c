#include <stdio.h>
#include <math.h>

int main () {

    printf("Trios pitagóricos onde o maior número é menor que 1000:\n\n");

    // a deve ser menor que b, e b deve ser menor que c
    for (int a = 1; a < 1000; a++) {
        for (int b = a; b < 1000; b++) {
            for (int c = b; c < 1000; c++) {
                // Verifica se a² + b² = c²
                if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }

    return 0;
}