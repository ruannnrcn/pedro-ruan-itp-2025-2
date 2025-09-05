#include <stdio.h>

int main () {
    //Declaração de variáveis
    float celsius, fahrenheit, kelvin;

    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);

    //Cálculo das conversões
    fahrenheit = celsius * (9.0 / 5.0) + 32.0;
    kelvin = celsius + 273.15;

    //Saída de dados
    printf("Temperatura em Fahrenheit: %.1f °F\n", fahrenheit);
    printf("Temperatura em Kelvin: %.1f K\n", kelvin);

    return 0;
}