#include <stdio.h>

int main() {
    int n; // número de pilotos
    
    // Lê o número de pilotos
    scanf("%d", &n);
    
    int vitorias[n]; // array para contar vitórias de cada piloto
    
    // Inicializa o contador de vitórias
    for (int i = 0; i < n; i++) {
        vitorias[i] = 0;
    }
    
    // Para cada piloto, lê suas posições
    for (int piloto = 0; piloto < n; piloto++) {
        int posicao;
        
        // Lê as posições até encontrar -1 (fim das corridas deste piloto)
        while (scanf("%d", &posicao)) {
            if (posicao == -1) {
                break; // Fim das corridas deste piloto
            }
            
            // Se a posição foi 1º lugar, conta uma vitória
            if (posicao == 1) {
                vitorias[piloto]++;
            }
        }
    }
    
    // Encontra o piloto com mais vitórias
    int maxVitorias = 0;
    int pilotoVencedor = -1;
    
    // Debug: imprime vitórias de cada piloto
    /*
    for (int i = 0; i < n; i++) {
        printf("Piloto %d: %d vitorias\n", i+1, vitorias[i]);
    }
    */
    
    // Primeiro, encontra o máximo de vitórias
    for (int i = 0; i < n; i++) {
        if (vitorias[i] > maxVitorias) {
            maxVitorias = vitorias[i];
        }
    }
    
    // Verifica quantos pilotos têm o máximo de vitórias
    int countMaxVitorias = 0;
    for (int i = 0; i < n; i++) {
        if (vitorias[i] == maxVitorias) {
            countMaxVitorias++;
            pilotoVencedor = i + 1; // +1 porque os pilotos são numerados de 1 a n
        }
    }
    
    // Se mais de um piloto tem o máximo, é empate
    if (countMaxVitorias > 1) {
        printf("empate\n");
    } else {
        printf("%d\n", pilotoVencedor);
    }
    
    return 0;
}
