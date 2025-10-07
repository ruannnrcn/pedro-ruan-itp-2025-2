#include <stdio.h>
#include <stdlib.h>

// Função para calcular a soma dos divisores próprios de um número
int somaDivisoresProprios(int n) {
    int soma = 0;
    
    // Itera de 1 até n/2 (divisores próprios não incluem o próprio número)
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    
    return soma;
}

// Função para verificar se dois números são colegas
int saoNumerosColegas(int a, int b) {
    int divisoresA = somaDivisoresProprios(a);
    int divisoresB = somaDivisoresProprios(b);
    
    // Verifica as duas condições:
    // |D(A) - B| <= 2 e |D(B) - A| <= 2
    int diferencaA = abs(divisoresA - b);
    int diferencaB = abs(divisoresB - a);
    
    if (diferencaA <= 2 && diferencaB <= 2) {
        return 1;  // São colegas
    } else {
        return 0;  // Não são colegas
    }
}

int main() {
    int a, b;
    
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &a, &b);
    
    if (saoNumerosColegas(a, b)) {
        printf("S\n");
    } else {
        printf("N\n");
    }
    
    return 0;
}       