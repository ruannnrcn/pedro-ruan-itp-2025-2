#include <stdio.h>
#include <math.h>

int main () {
    float posicaox, posicaoy;                    
    float comprimento_teia;        
    int alvos;                       
    
    // Leitura da entrada
    printf("Digite a posição inicial do Homem-Aranha (x y): ");
    scanf("%f %f", &posicaox, &posicaoy);

    printf("Digite o comprimento máximo da teia: ");
    scanf("%f", &comprimento_teia);

    printf("Digite a quantidade de alvos: ");
    scanf("%d", &alvos);
    
    int conseguiu_todos = 1;  
    
    // Para cada alvo
    for (int i = 0; i < alvos; i++) {
        float ax, ay;

        printf("Digite as coordenadas do alvo %d (x y): ", i + 1);
        scanf("%f %f", &ax, &ay);
        
        // Calcula a distância euclidiana entre a posição atual e o alvo
        float distancia = sqrt(pow(ax - posicaox, 2) + pow(ay - posicaoy, 2));

        // Verifica se a teia alcança o alvo
        if (distancia < comprimento_teia) {
            // Consegue pegar! Atualiza a posição para a nova coordenada
            float novo_x = 2 * ax - posicaox;
            float novo_y = posicaoy;  // y permanece o mesmo

            posicaox = novo_x;
            posicaoy = novo_y;
        } else {
            // Não consegue alcançar este alvo
            conseguiu_todos = 0;
        }
    }
    
    // Imprime o resultado
    if (conseguiu_todos) {
        printf("S\n");
    } else {
        printf("N\n");
    }
    
    return 0;
}