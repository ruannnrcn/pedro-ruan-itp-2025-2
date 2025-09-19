#include <stdio.h>

int main () {
    //Declaração de variáveis
    float valor_compra, valor_desconto, valor_final;

    //Declarando a variavel de porcentagem de desconto como 0 para ser modificada de acordo com cada caso
    float porcentagem_desconto = 0.0;

    //Entrada de dados
    printf("Digite o valor da compra: ");
    scanf("%f", &valor_compra);

    //Validação do valor da compra sendo positivo
    while (valor_compra <= 0){
        printf("Valor inválido. Digite um valor positivo: ");
        scanf("%f", &valor_compra);
    }
    
    if (valor_compra < 100.00) {
        // Caso o valor da compra seja menor que R$ 100,00
        printf("Valor da compra é menor que R$ 100,00. Sem desconto aplicado.\n");
        valor_final = valor_compra;   
        valor_desconto = 0.0;
    } else if (valor_compra >= 100.01 && valor_compra <=500.00) {
        //Caso o valor da compra esteja entre R$ 100,01 e R$ 500,00 ele irá modificar a variável porcentagem_desconto para 10%
        porcentagem_desconto = 0.10;
        valor_desconto = valor_compra * porcentagem_desconto;
        valor_final = valor_compra - valor_desconto;
    } else if (valor_compra >= 500.01 && valor_compra <= 1000.00) {
        //Caso o valor da compra esteja entre R$ 500,01 e R$ 1000,00 ele irá modificar a variável porcentagem_desconto para 15%
        porcentagem_desconto = 0.15;
        valor_desconto = valor_compra * porcentagem_desconto;
        valor_final = valor_compra - valor_desconto;
    } else {
        // Caso o valor da compra seja maior que R$ 1000,00 ele irá modificar a variável porcentagem_desconto para 20%
        porcentagem_desconto = 0.20; 
        valor_desconto = valor_compra * porcentagem_desconto;
        valor_final = valor_compra - valor_desconto;
    }

    //Exibição dos resultados
    printf("Valor do desconto: R$ %.2f\n", valor_desconto);
    printf("Valor final a pagar: R$ %.2f\n", valor_final);
    printf("Porcentagem de desconto aplicada: %.0f%%\n", porcentagem_desconto * 100);

    return 0;
}