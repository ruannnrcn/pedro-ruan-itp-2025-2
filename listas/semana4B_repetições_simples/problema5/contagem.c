#include <stdio.h>

int main () {
    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    int contador = 1;  // Contador para a sequência contínua
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", contador);
            contador++;  // Incrementa para o próximo número da sequência
        }
        printf("\n");
    }

    return 0;
}