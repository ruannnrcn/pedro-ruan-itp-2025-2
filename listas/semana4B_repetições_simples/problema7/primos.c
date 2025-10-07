#include <stdio.h>

int main () {
    int a, b;

    printf("Insira a e b: ");
    scanf("%d %d", &a, &b);

    // Valida se a <= b (a deve ser menor ou igual a b)
    while (b > a) {
        printf("Valor invalido, a < b. Insira novamente a e b: \n");
        scanf("%d %d", &a, &b);
    }

    // Percorre todos os números no intervalo [a, b]
    for (int i = b; i <= a; i++) {
        int eh_primo = 1; 
        
        // Verifica se i é primo
        if (i < 2) {
            eh_primo = 0;  // Números menores que 2 não são primos
        } else {
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    eh_primo = 0; 
                    break; 
                }
            }
        }

        if (eh_primo) {
            printf("%d ", i);
        }
    }
    
    printf("\n");  // Quebra de linha no final
    
    return 0;
}