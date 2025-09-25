#include <stdio.h>
#include <ctype.h>

// Função para calcular o preço total do produto
float calcularTotal(float preco, float quantidade) {
    return preco * quantidade;
}

// Função para validar se o valor é positivo
float validacaoPositivo (float valor) {
    while (valor <= 0) {
        printf("Valor inválido. Digite um valor positivo: ");
        scanf("%f", &valor);
    }
    return valor;
}


int main () {
    //Declaração de variáveis
    float preco, quantidade;
    char acao;

    // Variável para o nome do produto com ate 50 caracteres
    char nome[50];

    // Loop para adicionar um produto e mostrar seu preço total
    while (1) {
        printf("Deseja adicionar um novo produto? (S/N): ");
        scanf(" %c", &acao);

        //Tratamento para aceitar tanto maiúsculas quanto minúsculas
        acao = toupper(acao);
        
        //Validação para adicionar produto ou sair
        if (acao == 'S') {
            //Caso ele queira adicionar um produto, pede os dados do produto
            printf("Digite o nome do produto: ");
            scanf(" %[^\n]", nome);
            printf("Digite o preço do produto: ");
            scanf("%f", &preco);
            //Validação para garantir que o preço seja positivo chamando a função
            preco = validacaoPositivo(preco);
            printf("Digite a quantidade do produto: ");
            scanf("%f", &quantidade);
            //Validação para garantir que a quantidade seja positiva chamando a função
            quantidade = validacaoPositivo(quantidade);
            printf("Produto %s adicionado com sucesso!\n", nome);
            printf("Preço total: R$ %.2f / Quantidade: %.2f\n", calcularTotal(preco, quantidade), quantidade);
        }
        else if (acao == 'N')
        {
            printf("Encerrando o programa.\n");
            break;
        }
        else {
            //Validação para caso o usuário digite uma ação inválida
            printf("Ação inválida. Por favor, digite 'S' para sim ou 'N' para não.\n");
        } 
    
    }

    return 0;
}