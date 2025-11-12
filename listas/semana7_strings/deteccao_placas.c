#include<stdio.h>
#include<string.h>
#include<ctype.h>

int validacaoFormatacao(char placa[]) {
    // Verificar se tem 7 ou 8 caracteres
    if (strlen(placa) != 7 && strlen(placa) != 8) {
        return 0;
    } 

    // Verificar se todas as letras são maiúsculas se nao for, retorna invalido
    for (int i = 0; i < strlen(placa); i++) {
        if (isalpha(placa[i]) && islower(placa[i])) {
            return 0;
        }
    }

    return 1;
}

int main () {
    char placa[11];
    scanf("%10s", placa);

    // Validar formatação básica
    if (!validacaoFormatacao(placa)) {
        printf("invalido\n");
        return 0;
    }
    

    // Verificar formato brasileiro: LLL-AAAA
    int brasileiro = 1;
    
    // Verificar se tem exatamente 8 caracteres para formato brasileiro
    if (strlen(placa) == 8) {
        for (int i = 0; i < 3; i++) {
            if (!isalpha(placa[i])) {
                brasileiro = 0;
                break;
            }
        }
        if (placa[3] != '-') brasileiro = 0;
        for (int i = 4; i < 8; i++) {
            if (!isdigit(placa[i])) {
                brasileiro = 0;
                break;
            }
        }
    } else {
        brasileiro = 0;
    }

    if (brasileiro) {
        printf("brasileiro\n");
        return 0;
    }

    // Verificar formato mercosul: LLLALAA
    int mercosul = 1;
    
    // Verificar se tem exatamente 7 caracteres para formato mercosul
    if (strlen(placa) == 7) {
        for (int i = 0; i < 3; i++) {
            if (!isalpha(placa[i])) {
                mercosul = 0;
                break;
            }
        }
        if (!isdigit(placa[3])) mercosul = 0;
        if (!isalpha(placa[4])) mercosul = 0;
        for (int i = 5; i < 7; i++) {
            if (!isdigit(placa[i])) {
                mercosul = 0;
                break;
            }
        }
    } else {
        mercosul = 0;
    }

    if (mercosul) {
        printf("mercosul\n");
    } else {
        printf("invalido\n");
    }

    return 0;
}