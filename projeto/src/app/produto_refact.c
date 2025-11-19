#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para representar um produto
typedef struct {
    int id;
    char nome[51];
    float preco;
    float quantidade;
    float total;
} Produto;

// Array global para armazenar produtos e contador
// Usando alocação dinâmica para não ter limite fixo
Produto* produtos = NULL;
int totalProdutos = 0;

// Função para calcular o preço total do produto
float calcularTotal(float preco, float quantidade) {
    return preco * quantidade;
}

// Função para adicionar um produto ao array
void adicionarProduto(Produto produto) {
    // Realoca memória para um produto adicional
    Produto* temp = realloc(produtos, (totalProdutos + 1) * sizeof(Produto));
    
    if (temp == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo produto!\n");
        return;
    }
    produtos = temp;
    
    // Copia o produto recebido para o array
    produtos[totalProdutos] = produto;
    
    // Define o ID e calcula o total
    produtos[totalProdutos].id = totalProdutos;
    produtos[totalProdutos].total = calcularTotal(produto.preco, produto.quantidade);
    
    printf("Produto %s adicionado com sucesso!\n", produto.nome);
    printf("Preço total: R$ %.2f / Quantidade: %.2f\n", 
           produtos[totalProdutos].total, produto.quantidade);
    totalProdutos++;
}

// Função para listar todos os produtos
int listarProdutos() {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado ainda.\n");
        return 0;
    }
    
    printf("\n=== LISTA DE PRODUTOS ===\n");
    printf("%-3s %-20s %-10s %-10s %-10s\n", "ID", "Nome", "Preço", "Qtd", "Total");
    printf("-------------------------------------------------------\n");
    
    float somaTotal = 0;
    for (int i = 0; i < totalProdutos; i++) {
        printf("%-3d %-20s R$ %-6.2f %-10.2f R$ %-6.2f\n", 
               produtos[i].id,
               produtos[i].nome, 
               produtos[i].preco, 
               produtos[i].quantidade, 
               produtos[i].total);
        somaTotal += produtos[i].total;
    }
    
    printf("-------------------------------------------------------\n");
    printf("Total geral: R$ %.2f\n", somaTotal);
    printf("Produtos cadastrados: %d\n\n", totalProdutos);
    return 1; // Retorna 1 se há produtos
}

// Função para validar se o valor é positivo
float validacaoPositivo (float valor) {
    while (valor <= 0) {
        printf("Valor inválido. Digite um valor positivo: ");
        scanf("%f", &valor);
    }
    return valor;
}

//Função para deletar um produto
int deletarProduto(int id) {
    if (id < 0 || id >= totalProdutos) {
        printf("ID inválido. Nenhum produto deletado.\n");
        return 0;
    }

    //Validação para confirmar a deleção
    char confirmacao;
    printf("Tem certeza que deseja deletar o produto %s? (S/N): ", produtos[id].nome);
    scanf(" %c", &confirmacao);
    confirmacao = toupper(confirmacao);

    if (confirmacao != 'S') {
        printf("Deleção cancelada.\n");
        return 0;
    }

    // Move os produtos para preencher o espaço do produto deletado
    for (int i = id; i < totalProdutos - 1; i++) {
        produtos[i] = produtos[i + 1];
        produtos[i].id = i; // Atualiza o ID do produto
    }
    
    totalProdutos--;
    
    // Se não há mais produtos, libera toda a memória
    if (totalProdutos == 0) {
        free(produtos);
        produtos = NULL;
    } else {
        // Realoca memória para o novo tamanho
        Produto* temp = realloc(produtos, totalProdutos * sizeof(Produto));
        if (temp != NULL) {
            produtos = temp;
        }
    }
    
    printf("Produto com ID %d deletado com sucesso!\n", id);
    return 1;
}


int main () {
    //Declaração de variáveis
    float preco, quantidade;
    char acao;
    int id; //Idenficador do produto 
    Produto novoProduto; // Estrutura para o novo produto

    // Variável para o nome do produto com ate 50 caracteres
    char nome[51];

    printf("=== SISTEMA DE GERENCIAMENTO DE PRODUTOS ===\n\n");

    // Loop para adicionar um produto e mostrar seu preço total
    while (1) {
        printf("\n╔══════════════════════════════════════╗\n");
        printf("║            MENU PRINCIPAL            ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║  [A] Adicionar produto               ║\n");
        printf("║  [D] Deletar produto                 ║\n");
        printf("║  [L] Listar produtos                 ║\n");
        printf("║  [N] Sair do programa                ║\n");
        printf("╚══════════════════════════════════════╝\n");
        printf("Escolha uma opção: ");

        scanf(" %c", &acao);

        //Tratamento para aceitar tanto maiúsculas quanto minúsculas
        acao = toupper(acao);
        
        //Validação das ações usando switch case
        switch (acao) {
            case 'A':
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
                
                strcpy(novoProduto.nome, nome);
                novoProduto.preco = preco;
                novoProduto.quantidade = quantidade;
                
                // Chama a função para adicionar o produto
                adicionarProduto(novoProduto);
                break;
                
            case 'D':
                // Verifica se há produtos para deletar
                if (listarProdutos()) {
                    printf("Digite o ID do produto a ser deletado: ");
                    scanf("%d", &id);
                    deletarProduto(id);
                }
                break;
                
            case 'L':
                // Chama a função para listar produtos
                listarProdutos();
                break;
                
            case 'N':
                printf("Encerrando o programa.\n");
                // Libera a memória alocada antes de sair
                if (produtos != NULL) {
                    free(produtos);
                    produtos = NULL;
                }
                break;
                
            default:
                //Validação para caso o usuário digite uma ação inválida
                printf("Ação inválida. \n");
                break;
        }

        // Sai do loop se a ação for 'N'
        if (acao == 'N') {
            break;
        }
    }

    return 0;
}