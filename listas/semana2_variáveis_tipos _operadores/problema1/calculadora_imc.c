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

    //Saída de dados
    printf("Seu IMC é: %.2f\n", imc);

    return 0;
}