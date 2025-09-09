#include <stdio.h>
#include <ctype.h>

int main () {
    float kWh, valor_total;

    // Definição das taxas conforme o tipo de consumidor
    float taxa_residencial = 0.60;
    float taxa_comercial = 0.48;
    float taxa_industrial = 1.29;

    int taxa_fixa = 15;
    char tipo_consumidor;

    //Entrada de dados
    printf("Digite o consumo de energia em kWh: ");
    scanf("%f", &kWh);

    printf("Digite o tipo de consumidor (R - Residencial, C - Comercial, I - Industrial): ");
    scanf(" %c", &tipo_consumidor);

    // Converte o tipo de consumidor insrido para maiúsculo, assim evitando problemas de validação
    tipo_consumidor = toupper(tipo_consumidor);

    //Validação do tipo de consumidor
    while (tipo_consumidor != 'R' && tipo_consumidor != 'C' && tipo_consumidor != 'I') {
        printf("Tipo de consumidor inválido. Digite R, C ou I: ");
        scanf(" %c", &tipo_consumidor);
        //Refazendo a validação para maiúsculo
        tipo_consumidor = toupper(tipo_consumidor); 
    }

    //Cálculo do valor total a pagar conforme o tipo de consumidor
    if (tipo_consumidor == 'R') {
        // Caso seja residencial
        valor_total = (kWh * taxa_residencial) + taxa_fixa;
        printf("Valor total a pagar (Residencial): R$ %.1f\n", valor_total);
    } else if (tipo_consumidor == 'C') {
        // Caso seja comercial
        valor_total = (kWh * taxa_comercial) + taxa_fixa;
        printf("Valor total a pagar (Comercial): R$ %.1f\n", valor_total);
    } else {
        // Caso seja industrial
        valor_total = (kWh * taxa_industrial) + taxa_fixa;
        printf("Valor total a pagar (Industrial): R$ %.1f\n", valor_total);
    }


    return 0;
}