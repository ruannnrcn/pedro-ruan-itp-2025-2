#include <stdio.h>
#include <math.h>

// Função para calcular a distância euclidiana até o centro (0, 0)
float calcularDistancia(float x, float y) {
    return sqrt(x * x + y * y);
}

// Função para calcular a pontuação principal baseada na distância
int calcularPontuacaoPrincipal(float distancia) {
    if (distancia >= 0 && distancia <= 1) {
        return 10;
    } else if (distancia > 1 && distancia <= 2) {
        return 6;
    } else if (distancia > 2 && distancia <= 3) {
        return 4;
    } else {
        return 0;
    }
}

// Função para calcular a pontuação bônus baseada na distância
int calcularPontuacaoBonus(float distancia) {
    if (distancia >= 0 && distancia <= 1) {
        return 5;
    } else if (distancia > 1 && distancia <= 2) {
        return 3;
    } else if (distancia > 2 && distancia <= 3) {
        return 2;
    } else {
        return 0;
    }
}

int main() {
    int pontuacaoTotal = 0;
    float x_anterior = -999, y_anterior = -999;  // Valores impossíveis para primeira rodada
    
    printf("Digite as coordenadas de 10 lançamentos:\n");
    
    for (int i = 0; i < 10; i++) {
        float coordenadax, coordenaday;
        scanf("%f %f", &coordenadax, &coordenaday);
        
        float distancia = calcularDistancia(coordenadax, coordenaday);
        
        // Calcula pontuação principal
        int pontos = calcularPontuacaoPrincipal(distancia);
        pontuacaoTotal += pontos;
        
        // Verifica se acertou no mesmo lugar que o lançamento anterior
        if (i > 0 && coordenadax == x_anterior && coordenaday == y_anterior) {
            int bonus = calcularPontuacaoBonus(distancia);
            pontuacaoTotal += bonus;
        }
        
        // Atualiza as coordenadas anteriores
        x_anterior = coordenadax;
        y_anterior = coordenaday;
    }
    
    printf("%d\n", pontuacaoTotal);

    return 0;
}