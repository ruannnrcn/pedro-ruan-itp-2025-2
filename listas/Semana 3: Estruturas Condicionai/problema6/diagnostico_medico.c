#include <stdio.h> 
#include <ctype.h>

int main () {
    //Declaração de variáveis
    int febre = 0, dor_cabeca = 0, dor_corpo = 0, tosse = 0;
    char resposta;

    //Entrada de dados

    //Validação das respostas para garantir que sejam 's' ou 'n'
    //Caso sejam s modifica o valor da variável para 1 (verdadeiro)
    //Caso sejam n o valor permanece 0 (falso)
    printf("Você está com febre? (s/n): ");
    scanf(" %c", &resposta);
    resposta = tolower(resposta);
    if (resposta == 's') {
        febre = 1;
    }
    printf("Você está com dor de cabeça? (s/n): ");
    scanf(" %c", &resposta);
    resposta = tolower(resposta);
    if (resposta == 's') {
        dor_cabeca = 1;
    }
    printf("Você está com dor no corpo? (s/n): ");
    scanf(" %c", &resposta);
    resposta = tolower(resposta);               
    if (resposta == 's') {
        dor_corpo = 1;
    }
    printf("Você está com tosse? (s/n): ");
    scanf(" %c", &resposta);
    resposta = tolower(resposta);
    if (resposta == 's') {
        tosse = 1;
    }

    //Diagnóstico baseado nos sintomas e nas comobinações possíveis
    if (febre && dor_cabeca && dor_corpo) {
        printf("Diagnóstico: Possivel gripe.\n");
    } else if (tosse && febre) {
        printf("Diagnóstico: Possivel resfriado.\n");
    } else if (dor_cabeca) {
        printf("Diagnóstico: Possivel enxaqueca.\n");
    } else if (febre) {
        printf("Diagnóstico: Consulte um médico\n");
    } else if (!febre && !dor_cabeca && !dor_corpo && !tosse) {
        printf("Diagnóstico: Você está saudável.\n");
    } else {
        printf("Diagnóstico: Sintomas não específicos. Consulte um médico.\n");
    }

    return 0;
}