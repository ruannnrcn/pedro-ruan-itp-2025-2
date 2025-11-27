#include <stdio.h>

int main() {
    int M, X, Z;
    
    // Ler número de cidades
    scanf("%d", &M);
    
    // Declarar matriz de preços
    int precos[10][10];
    
    // Ler matriz de preços
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &precos[i][j]);
        }
    }
    
    // Ler origem e destino
    scanf("%d %d", &X, &Z);
    
    // Inicializar com viagem direta
    int menor_custo = precos[X][Z];
    int melhor_intermediaria = -1; // -1 indica viagem direta
    
    // Testar todas as cidades intermediárias possíveis
    for (int k = 0; k < M; k++) {
        if (k == X || k == Z) continue; // Não pode ser origem nem destino
        
        // Calcular custo passando pela cidade k
        int custo_via_k = precos[X][k] + precos[k][Z];
        
        // Se for menor que o melhor custo atual
        if (custo_via_k < menor_custo) {
            menor_custo = custo_via_k;
            melhor_intermediaria = k;
        }
    }
    
    // Imprimir resultado
    if (melhor_intermediaria == -1) {
        // Viagem direta é a melhor
        printf("%d-%d R$%d\n", X, Z, menor_custo);
    } else {
        // Viagem com parada é a melhor
        printf("%d-%d-%d R$%d\n", X, melhor_intermediaria, Z, menor_custo);
    }
    
    return 0;
}
