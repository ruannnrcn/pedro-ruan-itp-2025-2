#include "produto_core.h"
#include <string.h>
#include <stdio.h>

//Arquivo responsável pela lógica de negócio dos produtos
//Implementa as funções declaradas em produto_core.h

static Produto produtos[MAX_PRODUTOS];
static int totalProdutos = 0;

int adicionarProduto(const char* nome, float preco, float quantidade){
    if (nome == NULL || strlen(nome) == 0) return 0;
    if (preco <= 0 || quantidade <= 0) return 0;
    if (totalProdutos >= MAX_PRODUTOS) return -1;

    strncpy(produtos[totalProdutos].nome, nome, 50);
    produtos[totalProdutos].nome[50] = '\0';
    produtos[totalProdutos].preco = preco;
    produtos[totalProdutos].quantidade = quantidade;
    produtos[totalProdutos].id = totalProdutos;
    produtos[totalProdutos].total = calcularTotal(preco, quantidade);
    
    totalProdutos++;
    return 1; 
}

int deletarProduto(int id){
    if (id < 0 || id >= totalProdutos) return 0;

    for (int i = id; i < totalProdutos - 1; i++) {
        produtos[i] = produtos[i + 1];
        produtos[i].id = i;
    }
    totalProdutos--;
    return 1; 
}

int editarProduto(int id, const char* nome, float preco, float quantidade) {
    if (id < 0 || id >= totalProdutos) return 0;           
    if (nome == NULL || strlen(nome) == 0) return 0;       
    if (preco <= 0 || quantidade <= 0) return 0;           
    
    strncpy(produtos[id].nome, nome, 50);
    produtos[id].nome[50] = '\0';
    produtos[id].preco = preco;
    produtos[id].quantidade = quantidade;
    produtos[id].total = calcularTotal(preco, quantidade);
    
    return 1; 
}

int getTotalProdutos(void) {
    return totalProdutos;
}

float calcularTotal(float preco, float quantidade) {
    return preco * quantidade;
}

float getSomaTotal(void) {
    float soma =0;
    for (int i = 0; i < totalProdutos; i++) {
        soma += produtos[i].total;
    }
    return soma;
}

void limparTodosProdutos(void) {
    totalProdutos = 0;
}  

Produto* getProdutos(void) {
    return produtos;
}