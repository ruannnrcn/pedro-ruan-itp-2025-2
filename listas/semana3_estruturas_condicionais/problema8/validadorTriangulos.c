#include <stdio.h>
#include <math.h>

int main () {
    //Declaração de variáveis
    int lado1, lado2, lado3;

    //Entrada de dados
    printf("Digite o comprimento do primeiro lado do triângulo: ");
    scanf("%d", &lado1);
    printf("Digite o comprimento do segundo lado do triângulo: ");
    scanf("%d", &lado2);
    printf("Digite o comprimento do terceiro lado do triângulo: ");
    scanf("%d", &lado3);

    //Validação dos lados para garantir que sejam positivos
    while (lado1 <= 0 || lado2 <= 0 || lado3 <= 0) {
        printf("Lados inválidos. Digite novamente os lados. Lembrando que devem ser positivos.\n");
        printf("Digite novamente o comprimento do primeiro lado do triângulo: ");
        scanf("%d", &lado1);
        printf("Digite novamente o comprimento do segundo lado do triângulo: ");
        scanf("%d", &lado2);
        printf("Digite novamente o comprimento do terceiro lado do triângulo: ");
        scanf("%d", &lado3);
    }

    // Verificação se os lados formam um triângulo
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        printf("Os lados formam um triângulo.\n");

        //Classifcacão do triângulo quanto aos ângulos
        if (pow(lado1, 2) + pow(lado2, 2) == pow(lado3, 2) ||
            pow(lado1, 2) + pow(lado3, 2) == pow(lado2, 2) ||
            pow(lado2, 2) + pow(lado3, 2) == pow(lado1, 2)) {
            printf("O triângulo é retângulo.\n");
        } else if (pow(lado1, 2) + pow(lado2, 2) > pow(lado3, 2) &&
                   pow(lado1, 2) + pow(lado3, 2) > pow(lado2, 2) &&
                   pow(lado2, 2) + pow(lado3, 2) > pow(lado1, 2)) {
            printf("O triângulo é acutângulo.\n");
        } else {
            printf("O triângulo é obtusângulo.\n");
        }

        // Classificação do triângulo
        if (lado1 == lado2 && lado2 == lado3) {
            printf("O triângulo é equilátero.\n");
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            printf("O triângulo é isósceles.\n");
        } else {
            printf("O triângulo é escaleno.\n");
        }

    } else {
        printf("Os lados não formam um triângulo.\n");
    }


    return 0;
}