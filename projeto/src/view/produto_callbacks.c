#include "produto_gui.h"

// Enumeração para as colunas da TreeView (mesma do produto_gui.c)
enum {
    COL_ID = 0,
    COL_NOME,
    COL_PRECO,
    COL_QUANTIDADE,
    COL_TOTAL,
    N_COLUMNS
};

// Função auxiliar para obter ID do item selecionado
int obter_id_selecionado(AppWidgets *app) {
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(app->tree_view));
    GtkTreeModel *model;
    GtkTreeIter iter;
    
    if (gtk_tree_selection_get_selected(selection, &model, &iter)) {
        int id;
        gtk_tree_model_get(model, &iter, COL_ID, &id, -1);
        return id;
    }
    return -1;
}

// Callback para adicionar produto
void on_btn_adicionar_clicked(GtkWidget *widget, gpointer data) {
    AppWidgets *app = (AppWidgets*)data;
    
    // Obter dados dos campos
    const char *nome = gtk_entry_get_text(GTK_ENTRY(app->entry_nome));
    float preco = gtk_spin_button_get_value(GTK_SPIN_BUTTON(app->spin_preco));
    float quantidade = gtk_spin_button_get_value(GTK_SPIN_BUTTON(app->spin_quantidade));
    
    // Validar nome
    if (strlen(nome) == 0) {
        mostrar_mensagem_status(app, "Erro: Nome do produto não pode estar vazio!");
        return;
    }
    
    // Chamar o core
    int resultado = adicionarProduto(nome, preco, quantidade);
    
    // Processar resultado
    if (resultado == 1) {
        mostrar_mensagem_status(app, "Produto adicionado com sucesso!");
        
        // Limpar campos
        gtk_entry_set_text(GTK_ENTRY(app->entry_nome), "");
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(app->spin_preco), 0.01);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(app->spin_quantidade), 1.0);
        
        // Atualizar lista
        atualizar_lista_produtos(app);
        
        // Focar no campo nome para próxima entrada
        gtk_widget_grab_focus(app->entry_nome);
    } else if (resultado == -1) {
        mostrar_mensagem_status(app, "Erro: Limite máximo de produtos atingido!");
    } else {
        mostrar_mensagem_status(app, "Erro: Dados inválidos!");
    }
}

// Callback para editar produto
void on_btn_editar_clicked(GtkWidget *widget, gpointer data) {
    AppWidgets *app = (AppWidgets*)data;
    
    int id = obter_id_selecionado(app);
    if (id < 0) {
        mostrar_mensagem_status(app, "Nenhum produto selecionado!");
        return;
    }
    
    // Obter produto atual
    Produto *produtos = getProdutos();
    if (id >= getTotalProdutos()) {
        mostrar_mensagem_status(app, "Produto não encontrado!");
        return;
    }
    
    Produto *produto_atual = &produtos[id];
    
    // Criar diálogo de edição
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Editar Produto",
                                                   GTK_WINDOW(app->window),
                                                   GTK_DIALOG_MODAL,
                                                   "Cancelar", GTK_RESPONSE_CANCEL,
                                                   "Salvar", GTK_RESPONSE_OK,
                                                   NULL);
    
    gtk_window_set_default_size(GTK_WINDOW(dialog), 400, 300);
    
    // Conteúdo do diálogo
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_container_set_border_width(GTK_CONTAINER(grid), 20);
    gtk_container_add(GTK_CONTAINER(content_area), grid);
    
    // Campo Nome
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Nome:"), 0, 0, 1, 1);
    GtkWidget *entry_nome = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry_nome), produto_atual->nome);
    gtk_grid_attach(GTK_GRID(grid), entry_nome, 1, 0, 1, 1);
    
    // Campo Preço
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Preço (R$):"), 0, 1, 1, 1);
    GtkWidget *spin_preco = gtk_spin_button_new_with_range(0.01, 99999.99, 0.01);
    gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_preco), 2);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_preco), produto_atual->preco);
    gtk_grid_attach(GTK_GRID(grid), spin_preco, 1, 1, 1, 1);
    
    // Campo Quantidade
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Quantidade:"), 0, 2, 1, 1);
    GtkWidget *spin_quantidade = gtk_spin_button_new_with_range(0.01, 99999.99, 0.01);
    gtk_spin_button_set_digits(GTK_SPIN_BUTTON(spin_quantidade), 2);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_quantidade), produto_atual->quantidade);
    gtk_grid_attach(GTK_GRID(grid), spin_quantidade, 1, 2, 1, 1);
    
    gtk_widget_show_all(dialog);
    
    // Executar diálogo
    int response = gtk_dialog_run(GTK_DIALOG(dialog));
    
    if (response == GTK_RESPONSE_OK) {
        // Obter novos dados
        const char *novo_nome = gtk_entry_get_text(GTK_ENTRY(entry_nome));
        float novo_preco = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin_preco));
        float nova_quantidade = gtk_spin_button_get_value(GTK_SPIN_BUTTON(spin_quantidade));
        
        // Validar
        if (strlen(novo_nome) == 0) {
            mostrar_mensagem_status(app, "Erro: Nome não pode estar vazio!");
        } else {
            // Chamar o core
            int resultado = editarProduto(id, novo_nome, novo_preco, nova_quantidade);
            
            if (resultado == 1) {
                mostrar_mensagem_status(app, "Produto editado com sucesso!");
                atualizar_lista_produtos(app);
            } else {
                mostrar_mensagem_status(app, "Erro ao editar produto!");
            }
        }
    }
    
    gtk_widget_destroy(dialog);
}

// Callback para deletar produto
void on_btn_deletar_clicked(GtkWidget *widget, gpointer data) {
    AppWidgets *app = (AppWidgets*)data;
    
    int id = obter_id_selecionado(app);
    if (id < 0) {
        mostrar_mensagem_status(app, "Nenhum produto selecionado!");
        return;
    }
    
    // Obter nome do produto para confirmação
    Produto *produtos = getProdutos();
    if (id >= getTotalProdutos()) {
        mostrar_mensagem_status(app, "Produto não encontrado!");
        return;
    }
    
    // Criar diálogo de confirmação
    char mensagem[256];
    snprintf(mensagem, sizeof(mensagem), 
             "Tem certeza que deseja deletar o produto:\n\n%s ?", 
             produtos[id].nome);
    
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app->window),
                                              GTK_DIALOG_MODAL,
                                              GTK_MESSAGE_QUESTION,
                                              GTK_BUTTONS_YES_NO,
                                              "%s", mensagem);
    
    gtk_window_set_title(GTK_WINDOW(dialog), "Confirmar Deleção");
    
    int response = gtk_dialog_run(GTK_DIALOG(dialog));
    
    if (response == GTK_RESPONSE_YES) {
        int resultado = deletarProduto(id);
        
        if (resultado == 1) {
            mostrar_mensagem_status(app, "Produto deletado com sucesso!");
            atualizar_lista_produtos(app);
        } else {
            mostrar_mensagem_status(app, "Erro ao deletar produto!");
        }
    }
    
    gtk_widget_destroy(dialog);
}

// Callback para limpar todos os produtos
void on_btn_limpar_clicked(GtkWidget *widget, gpointer data) {
    AppWidgets *app = (AppWidgets*)data;
    
    if (getTotalProdutos() == 0) {
        mostrar_mensagem_status(app, "Não há produtos para remover!");
        return;
    }
    
    // Diálogo de confirmação
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(app->window),
                                              GTK_DIALOG_MODAL,
                                              GTK_MESSAGE_WARNING,
                                              GTK_BUTTONS_YES_NO,
                                              "Tem certeza que deseja remover TODOS os produtos?\n\nEsta ação não pode ser desfeita!");
    
    gtk_window_set_title(GTK_WINDOW(dialog), "Confirmar Limpeza");
    
    int response = gtk_dialog_run(GTK_DIALOG(dialog));
    
    if (response == GTK_RESPONSE_YES) {
        limparTodosProdutos();
        mostrar_mensagem_status(app, "Todos os produtos foram removidos!");
        atualizar_lista_produtos(app);
    }
    
    gtk_widget_destroy(dialog);
}

// Callback para mudança de seleção na tabela
void on_tree_selection_changed(GtkTreeSelection *selection, gpointer data) {
    AppWidgets *app = (AppWidgets*)data;
    
    // Verificar se há item selecionado
    GtkTreeModel *model;
    GtkTreeIter iter;
    gboolean has_selection = gtk_tree_selection_get_selected(selection, &model, &iter);
    
    // Habilitar/desabilitar botões baseado na seleção
    gtk_widget_set_sensitive(app->btn_editar, has_selection);
    gtk_widget_set_sensitive(app->btn_deletar, has_selection);
    
    if (has_selection) {
        int id;
        gtk_tree_model_get(model, &iter, COL_ID, &id, -1);
        
        char mensagem[128];
        snprintf(mensagem, sizeof(mensagem), "Produto ID %d selecionado", id);
        mostrar_mensagem_status(app, mensagem);
    }
}

// Callback para destruição da janela
void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}