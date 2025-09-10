#include <stdio.h>
#include <ctype.h>

int main() {
    //Declaração de variáveis
    //p1 = jogador 1 
    //p2 = jogador 2
    char jogada_p1, jogada_p2;

    //Entrada de dados
    printf("Jogador 1, escolha sua jogada (P = pedra, A = papel, T = tesoura): ");
    scanf(" %c", &jogada_p1);
    jogada_p1 = toupper(jogada_p1);

    //Validação das jogadas para o jogador 1 selecionar uma alternativa válida
    while (jogada_p1 != 'P' && jogada_p1 != 'A' && jogada_p1 != 'T') {
        printf("Jogada inválida para Jogador 1. Escolha P, A ou T: ");
        scanf(" %c", &jogada_p1);
        jogada_p1 = toupper(jogada_p1);
    }

    printf("Jogador 2, escolha sua jogada (P = pedra, A = papel, T = tesoura): ");
    scanf(" %c", &jogada_p2);
    jogada_p2 = toupper(jogada_p2);
   
    //Validação das jogadas para o jogador 2 selecionar uma alternativa válida
    while (jogada_p2 != 'P' && jogada_p2 != 'A' && jogada_p2 != 'T') {
        printf("Jogada inválida para Jogador 2. Escolha P, A ou T: ");
        scanf(" %c", &jogada_p2);
        jogada_p2 = toupper(jogada_p2);
    }

    //Lógica do jogo para determinar o vencedor
    if (jogada_p1 == jogada_p2) {
        printf("Empate!\n");
    } else if ((jogada_p1 == 'P' && jogada_p2 == 'T') ||
               (jogada_p1 == 'A' && jogada_p2 == 'P') ||
               (jogada_p1 == 'T' && jogada_p2 == 'A')) {
        printf("Jogador 1 venceu!\n");
    } else {
        printf("Jogador 2 venceu!\n");
    }

    return 0;
}