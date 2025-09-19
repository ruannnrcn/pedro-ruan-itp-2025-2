#include <stdio.h>

int main () {
    //Declaração de variáveis
    float nota1, nota2, nota3, nota_recuperacao, media, media_final;

    //Entrada de dados 
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    //Cálculo da média
    media = (nota1 + nota2 + nota3) / 3.0;

    //Saída de dados
    if (media >= 7.0) {
        printf("Aprovado com média: %.1f\n", media);
    } else if (media < 4.0) {
        printf("Reprovado com média: %.1f\n", media);
    } else {
        printf("Recuperação com média: %.1f\n", media);
        printf("Digite a nota da recuperação: ");
        scanf("%f", &nota_recuperacao);
        media_final = (media + nota_recuperacao) / 2.0;

        if (media_final >= 5.0) {
            printf("Aprovado com média final: %.1f\n", media_final);
        } else {
            printf("Reprovado com média final: %.1f\n", media_final);
        }
        
    }

    return 0;
}