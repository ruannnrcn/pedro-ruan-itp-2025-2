#include <stdio.h>

// Função para verificar se um número é primo
int ehPrimo(int n) {
    // Números menores que 2 não são primos
    if (n < 2) {
        return 0;
    }
    
    // 2 é primo
    if (n == 2) {
        return 1;
    }
    
    // Números pares não são primos (exceto 2)
    if (n % 2 == 0) {
        return 0;
    }
    
    // Verifica divisibilidade por números ímpares até a raiz quadrada de n
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

// Função para verificar se (x, x+2, x+6) formam um trio de primos
int ehTrioPrimo(int x) {
    return ehPrimo(x) && ehPrimo(x + 2) && ehPrimo(x + 6);
}

int main() {
    // Encontra todos os trios de primos até 50000
    // x deve ser tal que x+6 <= 50000, logo x <= 49994
    for (int x = 2; x <= 49994; x++) {
        if (ehTrioPrimo(x)) {
            printf("(%d, %d, %d)\n", x, x + 2, x + 6);
        }
    }
    
    return 0;
}
