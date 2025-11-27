#include "produto_core.h"
#include <stdio.h>
#include <ctype.h>

// Função para validar se o valor é positivo
float validacaoPositivo(float valor) {
    while (valor <= 0) {
        printf("Valor inválido. Digite um valor positivo: ");
        scanf("%f", &valor);
    }
    return valor;
}

// Interface para adicionar produto
void interface_adicionarProduto() {
    char nome[51];
    float preco, quantidade;
    
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nome);
    printf("Digite o preço do produto: ");
    scanf("%f", &preco);
    preco = validacaoPositivo(preco);
    printf("Digite a quantidade do produto: ");
    scanf("%f", &quantidade);
    quantidade = validacaoPositivo(quantidade);
    
    int resultado = adicionarProduto(nome, preco, quantidade);
    
    if (resultado == 1) {
        printf("Produto %s adicionado com sucesso!\n", nome);
        printf("Preço total: R$ %.2f\n", calcularTotal(preco, quantidade));
    } else if (resultado == -1) {
        printf("Limite máximo de produtos atingido!\n");
    } else {
        printf("Dados inválidos!\n");
    }
}

// Interface para listar produtos
void interface_listarProdutos() {
    if (getTotalProdutos() == 0) {
        printf("Nenhum produto cadastrado ainda.\n");
        return;
    }
    
    printf("\n=== LISTA DE PRODUTOS ===\n");
    printf("%-3s %-20s %-10s %-10s %-10s\n", "ID", "Nome", "Preço", "Qtd", "Total");
    printf("-------------------------------------------------------\n");
    
    Produto* produtos = getProdutos();
    for (int i = 0; i < getTotalProdutos(); i++) {
        printf("%-3d %-20s R$ %-6.2f %-10.2f R$ %-6.2f\n", 
               produtos[i].id,
               produtos[i].nome, 
               produtos[i].preco, 
               produtos[i].quantidade, 
               produtos[i].total);
    }
    
    printf("-------------------------------------------------------\n");
    printf("Total geral: R$ %.2f\n", getSomaTotal());
    printf("Produtos cadastrados: %d\n\n", getTotalProdutos());
}

// Interface para mostrar dados de um produto específico
void interface_mostrarDadosProduto(int id) {
    Produto* produtos = getProdutos();
    if (id < 0 || id >= getTotalProdutos()) {
        printf("ID inválido.\n");
        return;
    }
    
    printf("\n=== DADOS DO PRODUTO (ID: %d) ===\n", id);
    printf("Nome: %s\n", produtos[id].nome);
    printf("Preço: R$ %.2f\n", produtos[id].preco);
    printf("Quantidade: %.2f\n", produtos[id].quantidade);
    printf("Total: R$ %.2f\n", produtos[id].total);
    printf("--------------------------------\n");
}

// Interface para editar produto
void interface_editarProduto() {
    if (getTotalProdutos() == 0) {
        printf("Nenhum produto cadastrado ainda.\n");
        return;
    }
    
    interface_listarProdutos();
    
    int id;
    printf("Digite o ID do produto a ser editado: ");
    scanf("%d", &id);
    
    if (id < 0 || id >= getTotalProdutos()) {
        printf("ID inválido!\n");
        return;
    }
    
    printf("\n=== EDITANDO PRODUTO ===\n");
    interface_mostrarDadosProduto(id);
    
    char nome[51];
    float preco, quantidade;
    
    printf("\nDigite o novo nome do produto: ");
    scanf(" %[^\n]", nome);
    printf("Digite o novo preço do produto: ");
    scanf("%f", &preco);
    preco = validacaoPositivo(preco);
    printf("Digite a nova quantidade do produto: ");
    scanf("%f", &quantidade);
    quantidade = validacaoPositivo(quantidade);
    
    char confirmacao;
    printf("\nTem certeza que deseja editar este produto? (S/N): ");
    scanf(" %c", &confirmacao);
    confirmacao = toupper(confirmacao);
    
    if (confirmacao != 'S') {
        printf("Edição cancelada.\n");
        return;
    }
    
    int resultado = editarProduto(id, nome, preco, quantidade);
    
    if (resultado == 1) {
        printf("\nProduto editado com sucesso!\n");
        printf("\n--- DADOS APÓS A EDIÇÃO ---");
        interface_mostrarDadosProduto(id);
    } else {
        printf("Erro ao editar produto!\n");
    }
}

// Interface para deletar produto
void interface_deletarProduto() {
    if (getTotalProdutos() == 0) {
        printf("Nenhum produto cadastrado ainda.\n");
        return;
    }
    
    interface_listarProdutos();
    
    int id;
    printf("Digite o ID do produto a ser deletado: ");
    scanf("%d", &id);
    
    if (id < 0 || id >= getTotalProdutos()) {
        printf("ID inválido!\n");
        return;
    }
    
    Produto* produtos = getProdutos();
    char confirmacao;
    printf("Tem certeza que deseja deletar o produto %s? (S/N): ", produtos[id].nome);
    scanf(" %c", &confirmacao);
    confirmacao = toupper(confirmacao);
    
    if (confirmacao != 'S') {
        printf("Deleção cancelada.\n");
        return;
    }
    
    int resultado = deletarProduto(id);
    
    if (resultado == 1) {
        printf("Produto deletado com sucesso!\n");
    } else {
        printf("Erro ao deletar produto!\n");
    }
}

void imprimirMenu() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║            MENU PRINCIPAL            ║\n");
    printf("║        (CLI usando Core)             ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  [A] Adicionar produto               ║\n");
    printf("║  [E] Editar produto                  ║\n");
    printf("║  [D] Deletar produto                 ║\n");
    printf("║  [L] Listar produtos                 ║\n");
    printf("║  [C] Limpar todos produtos           ║\n");
    printf("║  [N] Sair do programa                ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");
}

int main() {
    char acao;
    
    printf("=== SISTEMA DE GERENCIAMENTO DE PRODUTOS ===\n");
    printf("=== Versão CLI usando Core ===\n\n");
    
    while (1) {
        imprimirMenu();
        scanf(" %c", &acao);
        acao = toupper(acao);
        
        switch (acao) {
            case 'A':
                interface_adicionarProduto();
                break;
                
            case 'E':
                interface_editarProduto();
                break;
                
            case 'D':
                interface_deletarProduto();
                break;
                
            case 'L':
                interface_listarProdutos();
                break;
                
            case 'C':
                printf("Tem certeza que deseja limpar todos os produtos? (S/N): ");
                scanf(" %c", &acao);
                if (toupper(acao) == 'S') {
                    limparTodosProdutos();
                    printf("Todos os produtos foram removidos!\n");
                } else {
                    printf("Operação cancelada.\n");
                }
                break;
                
            case 'N':
                printf("Encerrando o programa.\n");
                return 0;
                
            default:
                printf("Ação inválida.\n");
                break;
        }
    }
    
    return 0;
}
