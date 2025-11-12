#include<stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    // Ler os números sorteados
    int sorteados[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &sorteados[i]);
    }
    
    // Ler os números apostados
    int apostados[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &apostados[i]);
    }
    
    // Contar quantos números apostados foram sorteados
    int acertos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (apostados[i] == sorteados[j]) {
                acertos++;
                break; // Para não contar o mesmo número duas vezes
            }
        }
    }
    
    printf("%d\n", acertos);
    
    return 0;
}
