#include <stdio.h>
#include <math.h>

int main () {
    //Declaração de variáveis
    int num1, num2;

    //Entrada de dados
    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);

    //Cálculo das operações aritméticas
    int soma = num1 + num2;
    int diferenca = num1 - num2;
    int produto = num1 * num2;
    float divisao_real = (float)num1 / (float)num2;
    int resto_divisao = num1 % num2;
    float media_aritmetica = (num1 + num2) / 2.0;

    //Saída de dados e exibição dos resultados
    printf("Soma: %d\n", soma);
    printf("Diferença: %d\n", diferenca);
    printf("Produto: %d\n", produto);
    printf("Divisão real: %.f\n", divisao_real);
    printf("Resto da divisão: %d\n", resto_divisao);
    printf("Média aritmética: %.2f\n", media_aritmetica);

    return 0;
}