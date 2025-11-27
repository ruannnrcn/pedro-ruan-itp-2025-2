#ifndef PRODUTO_CORE_H
#define PRODUTO_CORE_H

#define MAX_PRODUTOS 100

//Funções e classes do core de produtos
//Servindo como uma camada intermediária entre a interface (CLI/GUI) e a lógica de negócio

//Declaração da estrutura para representar um produto
typedef struct {
    int id;
    char nome[51];
    float preco;
    float quantidade;
    float total;
} Produto;

//Declaração das funções do core e separação de funções

//Funções para manipular produtos
int adicionarProduto(const char* nome, float preco, float quantidade);
int deletarProduto(int id);
int editarProduto(int id, const char* nome, float preco, float quantidade);

//Funções para consultar produtos
int getTotalProdutos(void);
Produto* getProdutos(void);
float getSomaTotal(void);

//Funções utilitárias  
float calcularTotal(float preco, float quantidade);
void limparTodosProdutos(void);

#endif // PRODUTO_CORE_H