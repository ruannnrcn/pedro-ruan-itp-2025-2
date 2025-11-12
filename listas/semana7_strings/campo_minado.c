#include<stdio.h>
#include<string.h>

int main () {

    char palavra[21];
    int indice;
    
    scanf("%20s %d", palavra, &indice); 

    if (palavra[indice] == 'x') {
        printf("bum!\n");
    } else {
        // Contar bombas adjacentes
        int bombas_adjacentes = 0;
        int tamanho = strlen(palavra);
        
        // Verificar posição à esquerda
        if (indice > 0 && palavra[indice - 1] == 'x') {
            bombas_adjacentes++;
        }
        
        // Verificar posição à direita
        if (indice < tamanho - 1 && palavra[indice + 1] == 'x') {
            bombas_adjacentes++;
        }
        
        printf("%d\n", bombas_adjacentes);
    }

    return 0;
}
