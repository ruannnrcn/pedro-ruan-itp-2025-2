#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//Estrutura principal do projeto para produto.c, focando em CLI
//Utilizando alocação dinâmica de memória para gerenciar produtos


// Estrutura para representar um produto
typedef struct {
    int id;
    char nome[51];
    float preco;
    float quantidade;
    float total;
} Produto;

// Ponteiro para array dinâmico de produtos e contadores
Produto *produtos = NULL;  
int totalProdutos = 0;     
int capacidade = 0;       

// Função para inicializar o sistema de produtos com alocação dinâmica de memória
int inicializarSistema() {
    //Inicializa a capacidade inicial para array de produtos
    capacidade = 10; 
    produtos = (Produto*) malloc(capacidade * sizeof(Produto));
    
    if (produtos == NULL) {
        printf("ERRO: Falha ao alocar memória inicial!\n");
        return 0;
    }
    
    printf("Sistema inicializado com capacidade para %d produtos.\n", capacidade);
    return 1;
}

// Função para expandir a capacidade do array dinamicamente
int expandirCapacidade() {

    //Dobra a capacidade atual para manter sempre espaço suficiente para os produtos
    int novaCapacidade = capacidade * 2;
    Produto *temp = (Produto*) realloc(produtos, novaCapacidade * sizeof(Produto));
    
    if (temp == NULL) {
        printf("ERRO: Falha ao expandir memória!\n");
        return 0;
    }
    
    produtos = temp;
    capacidade = novaCapacidade;
    printf("Capacidade expandida para %d produtos.\n", capacidade);
    return 1;
}

// Função para liberar toda a memória alocada
void liberarMemoria() {

    // Reinicializa o ponteiro e contadores após liberar a memória, utilizado no final do programa
    if (produtos != NULL) {
        free(produtos);
        produtos = NULL;
        totalProdutos = 0;
        capacidade = 0;
        printf("Memória liberada com sucesso.\n");
    }
}

// Função para calcular o preço total do produto
float calcularTotal(float preco, float quantidade) {
    return preco * quantidade;
}

// Função para adicionar um produto ao array
void adicionarProduto(Produto produto) {
    // Verifica se precisa expandir a capacidade
    if (totalProdutos >= capacidade) {
        if (!expandirCapacidade()) {
            printf("Não foi possível adicionar o produto por falta de memória.\n");
            return;
        }
    }
    
    // Copia o produto recebido para o array
    produtos[totalProdutos] = produto;
    
    // Define o ID e calcula o total
    produtos[totalProdutos].id = totalProdutos;
    produtos[totalProdutos].total = calcularTotal(produto.preco, produto.quantidade);
    
    printf("Produto %s adicionado com sucesso!\n", produto.nome);
    printf("Preço total: R$ %.2f / Quantidade: %.2f\n", 
           produtos[totalProdutos].total, produto.quantidade);
    printf("Produtos cadastrados: %d / Capacidade: %d\n", 
           totalProdutos + 1, capacidade);
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

// Função para deletar um produto
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
    printf("Produto com ID %d deletado com sucesso!\n", id);
    return 1;
}

// Função para mostrar os dados de um produto específico
void mostrarDadosProduto(int id) {
    if (id < 0 || id >= totalProdutos) {
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

// Função para editar um produto existente 
int editarProduto(int id, const char* nome, float preco, float quantidade) {
    // Validação de ID
    if (id < 0 || id >= totalProdutos) {
        printf("ID inválido. Nenhum produto editado.\n");
        return 0;
    }
    
    // Validação dos dados
    if (nome == NULL || strlen(nome) == 0) {
        printf("Nome inválido. Nenhum produto editado.\n");
        return 0;
    }
    
    if (preco <= 0 || quantidade <= 0) {
        printf("Preço e quantidade devem ser positivos. Nenhum produto editado.\n");
        return 0;
    }

    printf("\n--- DADOS ATUAIS ---");
    mostrarDadosProduto(id);
    
    // Confirmação da edição
    char confirmacao;
    printf("\nTem certeza que deseja editar este produto? (S/N): ");
    scanf(" %c", &confirmacao);
    confirmacao = toupper(confirmacao);
    
    if (confirmacao != 'S') {
        printf("Edição cancelada.\n");
        return 0;
    }
    
    // Atualiza os dados do produto
    strncpy(produtos[id].nome, nome, 50);
    produtos[id].nome[50] = '\0';
    produtos[id].preco = preco;
    produtos[id].quantidade = quantidade;
    produtos[id].total = calcularTotal(preco, quantidade);
    
    printf("\n--- DADOS APÓS A EDIÇÃO  ---");
    mostrarDadosProduto(id);
    
    return 1;
}

// Função para imprimir o menu principal 
void imprimirMenu() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║            MENU PRINCIPAL            ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  [A] Adicionar produto               ║\n");
    printf("║  [E] Editar produto                  ║\n");
    printf("║  [D] Deletar produto                 ║\n");
    printf("║  [L] Listar produtos                 ║\n");
    printf("║  [N] Sair do programa                ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");
}


int main () {
    //Declaração de variáveis
    float preco, quantidade;
    char acao;
    int id; //Idenficador do produto 
    Produto novoProduto; // Estrutura para o novo produto

    // Variável para o nome do produto com ate 50 caracteres
    char nome[51];

    printf("=== SISTEMA DE GERENCIAMENTO DE PRODUTOS ===\n");
    printf("Com alocação dinâmica de memória\n\n");
    
    // Inicializa o sistema com alocação dinâmica
    if (!inicializarSistema()) {
        printf("Falha ao inicializar o sistema. Encerrando...\n");
        return 1;
    }

    // Loop para adicionar um produto e mostrar seu preço total
    while (1) {
        imprimirMenu();

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
                
            case 'E':
                // Verifica se há produtos para editar
                if (listarProdutos()) {
                    printf("Digite o ID do produto a ser editado: ");
                    scanf("%d", &id);
                    
                    // Verifica se o ID é válido antes de pedir novos dados
                    if (id >= 0 && id < totalProdutos) {
                        printf("\n=== EDITANDO PRODUTO ===\n");
                        printf("Digite o novo nome do produto: ");
                        scanf(" %[^\n]", nome);
                        printf("Digite o novo preço do produto: ");
                        scanf("%f", &preco);
                        //Validação para garantir que o preço seja positivo
                        preco = validacaoPositivo(preco);
                        printf("Digite a nova quantidade do produto: ");
                        scanf("%f", &quantidade);
                        //Validação para garantir que a quantidade seja positiva
                        quantidade = validacaoPositivo(quantidade);
                        
                        // Chama a função para editar o produto
                        editarProduto(id, nome, preco, quantidade);
                    } else {
                        printf("ID inválido!\n");
                    }
                }
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

    // Libera toda a memória alocada antes de encerrar
    liberarMemoria();

    return 0;
}