#include <stdio.h>
#include <math.h>

int main() {
    //Declaração de variáveis
    float peso, altura, imc;

    //Entrada de dados
    printf("Digite seu peso (kg): ");
    scanf("%f", &peso);

    //Validação do peso sendo positivo
    while (peso <= 0) {
        printf("Peso inválido. Digite um valor positivo para o peso (kg): ");
        scanf("%f", &peso);
    }

    printf("Digite sua altura (m): ");
    scanf("%f", &altura);

    //Validação da altura sendo positiva
    while (altura <= 0) {
        printf("Altura inválida. Digite um valor positivo para a altura (m): ");
        scanf("%f", &altura);
    }

    //Cálculo do IMC
    imc = peso / pow(altura, 2);

    //Condicionais para classificar o IMC
    if (imc < 18.5) {
        printf("Seu IMC é: %.1f - Abaixo do peso ideal\n", imc);
    } else if (imc >= 18.5 && imc < 24.9) {
        printf("Seu IMC é: %.1f - Peso ideal\n", imc);
    } else if (imc >= 25 && imc < 29.9) {
        printf("Seu IMC é: %.1f - Sobrepeso\n", imc);
    } else {
        printf("Seu IMC é: %.1f - Obesidade\n", imc);
    }

    return 0;
}