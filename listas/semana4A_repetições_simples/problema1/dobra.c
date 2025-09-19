#include <stdio.h>

int main () {
    //Definindo as variáveis
    float comprimento_folha, largura_folha, comprimento_bolso;
    int contador = 0;

    //Entrada de dados e valores
    printf("Digite as dimensões da folha (comprimento e largura) em cm: ");
    scanf("%f %f", &comprimento_folha, &largura_folha);
    printf("Digite o comprimento do bolso (cm): ");
    scanf("%f", &comprimento_bolso);

    //Validação para as dimnensões da folha serem maiores que o tamanho do bolso. 
    //Enquanto essa condição for verdadeira, o programa continuará validando os valores
    while (comprimento_folha >= comprimento_bolso || largura_folha >= comprimento_bolso){
        if (comprimento_folha >= comprimento_bolso){
            comprimento_folha = comprimento_folha / 2;

            //Incrementa o contador a cada dobra de comprimento
            contador++;
        } else {
            largura_folha = largura_folha / 2;

            //Incrementa o contador a cada dobra de largura
            contador++;
        } 
    }

    printf("Número de dobras necessárias: %d\n", contador);
    
    return 0;
}