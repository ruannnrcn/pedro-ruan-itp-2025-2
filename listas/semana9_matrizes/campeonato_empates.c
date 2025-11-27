#include <stdio.h>

int main() {
    int M;
    
    // Ler número de times
    scanf("%d", &M);
    
    // Declarar matriz de resultados
    int resultados[20][20];
    
    // Ler matriz de resultados
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &resultados[i][j]);
        }
    }
    
    // Contar empates
    int empates = 0;
    
    // Para cada par de times (i, j) onde i < j
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            // Se os gols são iguais nos dois sentidos, é empate
            if (resultados[i][j] == resultados[j][i]) {
                empates++;
            }
        }
    }
    
    // Imprimir resultado
    printf("%d\n", empates);
    
    return 0;
}
