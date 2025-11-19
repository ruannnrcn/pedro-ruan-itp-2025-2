#include <stdio.h>
#include <string.h>

int main() {
    // Array com os nomes dos meses
    char meses[12][10] = {
        "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    
    // Arrays para armazenar os dados
    int chuva[12];
    char mesesOrdenados[12][10];
    int chuvaOrdenada[12];
    
    // Lendo as 12 quantidades de chuva
    printf("Digite a quantidade de chuva para os 12 meses (Jan a Dez):\n");
    for (int i = 0; i < 12; i++) {
        scanf("%d", &chuva[i]);
    }
    
    // Copiando os dados para os arrays que serão ordenados
    for (int i = 0; i < 12; i++) {
        chuvaOrdenada[i] = chuva[i];
        strcpy(mesesOrdenados[i], meses[i]);
    }
    
    // Bubble Sort - ordenando do maior para o menor (decrescente)
    for (int i = 0; i < 12 - 1; i++) {
        for (int j = 0; j < 12 - i - 1; j++) {
            // Se o elemento atual é menor que o próximo, troca
            if (chuvaOrdenada[j] < chuvaOrdenada[j + 1]) {
                // Troca as quantidades de chuva
                int tempChuva = chuvaOrdenada[j];
                chuvaOrdenada[j] = chuvaOrdenada[j + 1];
                chuvaOrdenada[j + 1] = tempChuva;
                
                // Troca os nomes dos meses correspondentes
                char tempMes[10];
                strcpy(tempMes, mesesOrdenados[j]);
                strcpy(mesesOrdenados[j], mesesOrdenados[j + 1]);
                strcpy(mesesOrdenados[j + 1], tempMes);
            }
        }
    }
    
    // Exibindo o ranking do mais chuvoso para o menos chuvoso
    printf("\nRanking dos meses mais chuvosos:\n");
    for (int i = 0; i < 12; i++) {
        printf("%s %d\n", mesesOrdenados[i], chuvaOrdenada[i]);
    }
    
    return 0;
}
