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
    while (comprimento_folha >= comprimento_bolso && largura_folha >= comprimento_bolso){
        //Verificação para saber qual lado da folha é maior
        //O maior lado será dobrado

        if (comprimento_folha >= largura_folha) {
            comprimento_folha /= 2;
        } else {
            largura_folha /= 2;
        }

        //Contador que contabiliza o número de dobras necessárias para cada dobra
        contador++;
    }

    printf("Número de dobras necessárias: %d\n", contador);
    
    return 0;
}