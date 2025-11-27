#include <stdio.h>

int main() {
    int M, x;
    
    // Ler número de usuários
    scanf("%d", &M);
    
    // Declarar matriz de amizades
    int amizades[100][100];
    
    // Ler matriz de amizades
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &amizades[i][j]);
        }
    }
    
    // Ler usuário para sugestões
    scanf("%d", &x);
    
    // Array para armazenar sugestões
    int sugestoes[100];
    int num_sugestoes = 0;
    
    // Para cada usuário que não é o próprio x
    for (int candidato = 0; candidato < M; candidato++) {
        if (candidato == x) continue; // Não sugerir a si mesmo
        
        // Verificar se x e candidato já são amigos
        if (amizades[x][candidato] == 1) continue; // Já são amigos
        
        // Verificar se têm amigos em comum
        int tem_amigo_comum = 0;
        for (int comum = 0; comum < M; comum++) {
            if (comum == x || comum == candidato) continue; // Ignorar eles mesmos
            
            // Se x é amigo de 'comum' E candidato também é amigo de 'comum'
            if (amizades[x][comum] == 1 && amizades[candidato][comum] == 1) {
                tem_amigo_comum = 1;
                break; // Encontrou pelo menos um amigo em comum
            }
        }
        
        // Se tem amigo em comum, adicionar à lista de sugestões
        if (tem_amigo_comum) {
            sugestoes[num_sugestoes] = candidato;
            num_sugestoes++;
        }
    }
    
    // Imprimir sugestões
    for (int i = 0; i < num_sugestoes; i++) {
        printf("%d", sugestoes[i]);
        if (i < num_sugestoes - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
