#include <stdio.h>

int main() {
    int M, N;
    
    // Ler dimensões
    scanf("%d %d", &M, &N);
    
    // Declarar matrizes
    int campo[10][10];      // Campo original
    int irrigado[10][10];   // Matriz para marcar setores irrigados
    
    // Inicializar matriz de irrigação
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            irrigado[i][j] = 0;
        }
    }
    
    // Ler a matriz do campo
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &campo[i][j]);
        }
    }
    
    // Encontrar irrigadores e marcar setores irrigados
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (campo[i][j] == 2) { // É um irrigador
                // Marcar vizinhos (norte, sul, leste, oeste)
                
                // Norte
                if (i - 1 >= 0) {
                    irrigado[i-1][j] = 1;
                }
                
                // Sul  
                if (i + 1 < M) {
                    irrigado[i+1][j] = 1;
                }
                
                // Oeste
                if (j - 1 >= 0) {
                    irrigado[i][j-1] = 1;
                }
                
                // Leste
                if (j + 1 < N) {
                    irrigado[i][j+1] = 1;
                }
            }
        }
    }
    
    // Contar setores férteis irrigados e não irrigados
    int ferteis_irrigados = 0;
    int ferteis_nao_irrigados = 0;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (campo[i][j] == 1) { // É um setor fértil
                if (irrigado[i][j] == 1) {
                    ferteis_irrigados++;
                } else {
                    ferteis_nao_irrigados++;
                }
            }
        }
    }
    
    // Imprimir resultado
    printf("%d %d\n", ferteis_irrigados, ferteis_nao_irrigados);
    
    return 0;
}
