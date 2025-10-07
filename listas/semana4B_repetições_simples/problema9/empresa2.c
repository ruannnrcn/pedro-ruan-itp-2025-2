#include <stdio.h>

// Função para calcular o total gasto na compra
int calcularGastoTotal(int qtd_fornecedor1, int preco1, int qtd_fornecedor2, int preco2) {
    return (qtd_fornecedor1 * preco1) + (qtd_fornecedor2 * preco2);
}

// Função para calcular o resto (quantidade não comprada)
int calcularResto(int quantidade_disponivel, int qtd_fornecedor1, int qtd_fornecedor2) {
    int total_comprado = qtd_fornecedor1 + qtd_fornecedor2;
    return quantidade_disponivel - total_comprado;
}

// Função para verificar se a compra é possível
int compraPossivel(int quantidade_disponivel, int qtd_fornecedor1, int qtd_fornecedor2) {
    int total_comprado = qtd_fornecedor1 + qtd_fornecedor2;
    return total_comprado <= quantidade_disponivel;
}

int main() {
    int preco_fornecedor1, preco_fornecedor2, quantidade_disponivel;
    
    // Leitura dos dados
    printf("Digite o preço do primeiro fornecedor: ");
    scanf("%d", &preco_fornecedor1);
    
    printf("Digite o preço do segundo fornecedor: ");
    scanf("%d", &preco_fornecedor2);
    
    printf("Digite a quantidade disponível: ");
    scanf("%d", &quantidade_disponivel);
    
    // Variáveis para guardar a melhor combinação
    int melhor_qtd1 = 0, melhor_qtd2 = 0;
    int menor_gasto = -1;  // -1 indica que ainda não encontrou
    
    // Testa todas as combinações possíveis
    // Cada fornecedor pode vender de 0 a 10 unidades
    // Começa pelo fornecedor mais barato
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            // Verifica se a compra é possível
            if (compraPossivel(quantidade_disponivel, i, j)) {
                int gasto = calcularGastoTotal(i, preco_fornecedor1, j, preco_fornecedor2);
                
                // Só considera combinações onde pelo menos uma unidade é comprada
                // Se for o primeiro válido ou se o gasto for menor
                if ((i > 0 || j > 0) && (menor_gasto == -1 || gasto < menor_gasto)) {
                    menor_gasto = gasto;
                    melhor_qtd1 = i;
                    melhor_qtd2 = j;
                }
                // Se o gasto for igual, prefere comprar mais unidades
                else if (gasto == menor_gasto && (i + j) > (melhor_qtd1 + melhor_qtd2)) {
                    melhor_qtd1 = i;
                    melhor_qtd2 = j;
                }
            }
        }
    }
    
    // Imprime o resultado
    printf("Resta menos comprando %d do primeiro e %d do segundo\n", melhor_qtd1, melhor_qtd2);
    
    return 0;
}
