#include <stdio.h>  
#include <math.h> 

int main () {
    //declaração de variáveis
    float a, b, c;
    float delta, raiz1, raiz2;

    //entrada de dados
    printf("Digite os coeficientes a, b e c: ");
    scanf("%f %f %f", &a, &b, &c);

    //Validação do coeficiente 'a' para garantir que a equação seja do 2º grau
    if (a == 0){
        //Caso não seja do 2º grau, exibe mensagem de erro e encerra o programa
        printf("O coeficiente 'a' não pode ser zero em uma equação do segundo grau.\n");
        return 1;
    } else {
        printf("A equação é uma equação do 2º grau.\n");
    }

    //Calculando o valor de delta
    delta = (pow(b, 2)) - 4 * a * c;

    //Condicionais para determinar o número de raízes reais com base no valor de delta
    if (delta < 0) {
        printf("A equação não possui raízes reais.\n");
    } else if (delta == 0) {
        raiz1 = -b / (2 * a);
        printf("A equação possui uma raiz real: %.2f\n", raiz1);
    } else {
        raiz1 = (-b + sqrt(delta)) / (2 * a);
        raiz2 = (-b - sqrt(delta)) / (2 * a);
        printf("A equação possui duas raízes reais: %.2f e %.2f\n", raiz1, raiz2);
    }

    return 0;
}