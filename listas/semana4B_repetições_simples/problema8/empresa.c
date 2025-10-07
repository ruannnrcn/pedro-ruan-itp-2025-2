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
    
    // Testa todas as combinações possíveis
    // Cada fornecedor pode vender de 0 a 10 unidades
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            // Verifica se a compra é possível
            if (compraPossivel(quantidade_disponivel, i, j)) {
                int resto = calcularResto(quantidade_disponivel, i, j);
                printf("Comprando %d do primeiro e %d do segundo resta: %d\n", i, j, resto);
            }
        }
    }
    
    return 0;
}
