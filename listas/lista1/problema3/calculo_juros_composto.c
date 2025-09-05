#include <stdio.h>
#include <math.h>

// Protótipo da função para validação
float validacao_positivo(float valor);

int main () {
    // Declaração de variáveis
    float tempo, capital_inicial, taxa_juros, montante;

    // Entrada de dados
    printf("Digite o capital inicial: ");
    scanf("%f", &capital_inicial);

    //Definindo capital_inicial como um valor positivo usando a função de validação
    //O valor que será retornado pela função sobrescreve o valor anterior
    capital_inicial = validacao_positivo(capital_inicial);

    //O valor que será retornado pela função sobrescreve o valor anterior
    printf("Digite a taxa de juros (%%): ");
    scanf("%f", &taxa_juros);
    taxa_juros = validacao_positivo(taxa_juros);

    // Converte a taxa de porcentagem para decimal
    taxa_juros = taxa_juros / 100.0; 

    printf("Digite o tempo (em anos): ");
    scanf("%f", &tempo);
    tempo = validacao_positivo(tempo);

    //Cálculo do montante com juros compostos
    montante = capital_inicial * pow((1 + taxa_juros), tempo);
    printf("Montante após %.1f anos será de: R$ %.2f\n", tempo, montante);

    return 0;
}


//Função para validar se o valor é positivo, retornando o valor válido
float validacao_positivo(float valor) {
    while (valor <= 0) {
        printf("Valor inválido. Digite um valor positivo: ");
        scanf("%f", &valor);
    }
    printf("Valor válido: %.1f\n", valor);
    return valor; 
}
