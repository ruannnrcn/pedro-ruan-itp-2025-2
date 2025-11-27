#include "produto_gui.h"
#include <stdlib.h>

enum {
    COL_ID = 0,
    COL_NOME,
    COL_PRECO,
    COL_QUANTIDADE,
    COL_TOTAL,
    N_COLUMNS
};

void criar_janela_principal(AppWidgets *app) {
    // 1. Criar janela principal
    app->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(app->window), "Sistema de Gerenciamento de Produtos");
    gtk_window_set_default_size(GTK_WINDOW(app->window), 800, 600);
    gtk_window_set_position(GTK_WINDOW(app->window), GTK_WIN_POS_CENTER);
    
    // 2. Conectar evento de fechar janela
    g_signal_connect(app->window, "destroy", G_CALLBACK(on_window_destroy), NULL);
    
    // 3. Container principal (vertical)
    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(app->window), main_box);
    
    // 4. Criar abas (notebook)
    app->notebook = gtk_notebook_new();
    gtk_box_pack_start(GTK_BOX(main_box), app->notebook, TRUE, TRUE, 0);
    
    // 5. Barra de status (rodapé)
    app->statusbar = gtk_statusbar_new();
    app->context_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(app->statusbar), "main");
    gtk_box_pack_start(GTK_BOX(main_box), app->statusbar, FALSE, FALSE, 0);
    
    // 6. Chamar criação das abas
    criar_aba_adicionar(app);
    criar_aba_listar(app);
    
    // 7. Mostrar tudo
    gtk_widget_show_all(app->window);
    
    // 8. Inicializar dados
    atualizar_lista_produtos(app);
    mostrar_mensagem_status(app, "Sistema iniciado!");
}

void criar_aba_adicionar(AppWidgets *app) {
    // Container da aba
    GtkWidget *aba_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(aba_box), 20);
    
    // Título
    GtkWidget *titulo = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(titulo), "<b>Adicionar Novo Produto</b>");
    gtk_box_pack_start(GTK_BOX(aba_box), titulo, FALSE, FALSE, 10);
    
    // Grid para organizar campos
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    gtk_box_pack_start(GTK_BOX(aba_box), grid, FALSE, FALSE, 10);
    
    // Campo Nome
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Nome:"), 0, 0, 1, 1);
    app->entry_nome = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(app->entry_nome), "Digite o nome");
    gtk_widget_set_size_request(app->entry_nome, 300, -1);
    gtk_grid_attach(GTK_GRID(grid), app->entry_nome, 1, 0, 1, 1);
    
    // Campo Preço
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Preço (R$):"), 0, 1, 1, 1);
    app->spin_preco = gtk_spin_button_new_with_range(0.01, 99999.99, 0.01);
    gtk_spin_button_set_digits(GTK_SPIN_BUTTON(app->spin_preco), 2);
    gtk_grid_attach(GTK_GRID(grid), app->spin_preco, 1, 1, 1, 1);
    
    // Campo Quantidade
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Quantidade:"), 0, 2, 1, 1);
    app->spin_quantidade = gtk_spin_button_new_with_range(0.01, 99999.99, 0.01);
    gtk_spin_button_set_digits(GTK_SPIN_BUTTON(app->spin_quantidade), 2);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(app->spin_quantidade), 1.0);
    gtk_grid_attach(GTK_GRID(grid), app->spin_quantidade, 1, 2, 1, 1);
    
    // Botão Adicionar
    app->btn_adicionar = gtk_button_new_with_label("Adicionar Produto");
    gtk_widget_set_size_request(app->btn_adicionar, 200, 40);
    gtk_widget_set_halign(app->btn_adicionar, GTK_ALIGN_CENTER);
    gtk_box_pack_start(GTK_BOX(aba_box), app->btn_adicionar, FALSE, FALSE, 20);
    
    // Conectar callback (evento de clique)
    g_signal_connect(app->btn_adicionar, "clicked", G_CALLBACK(on_btn_adicionar_clicked), app);
    
    // Adicionar aba ao notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(app->notebook), aba_box, gtk_label_new("Adicionar"));
}

void criar_aba_listar(AppWidgets *app) {
    // Container da aba
    GtkWidget *aba_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(aba_box), 20);
    
    // Título
    GtkWidget *titulo = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(titulo), "<b>Lista de Produtos</b>");
    gtk_box_pack_start(GTK_BOX(aba_box), titulo, FALSE, FALSE, 10);
    
    // Criar TreeView (tabela)
    app->tree_view = gtk_tree_view_new();
    
    // Criar colunas da tabela
    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    
    gtk_tree_view_append_column(GTK_TREE_VIEW(app->tree_view),
        gtk_tree_view_column_new_with_attributes("ID", renderer, "text", COL_ID, NULL));
    gtk_tree_view_append_column(GTK_TREE_VIEW(app->tree_view),
        gtk_tree_view_column_new_with_attributes("Nome", renderer, "text", COL_NOME, NULL));
    gtk_tree_view_append_column(GTK_TREE_VIEW(app->tree_view),
        gtk_tree_view_column_new_with_attributes("Preço", renderer, "text", COL_PRECO, NULL));
    gtk_tree_view_append_column(GTK_TREE_VIEW(app->tree_view),
        gtk_tree_view_column_new_with_attributes("Quantidade", renderer, "text", COL_QUANTIDADE, NULL));
    gtk_tree_view_append_column(GTK_TREE_VIEW(app->tree_view),
        gtk_tree_view_column_new_with_attributes("Total", renderer, "text", COL_TOTAL, NULL));
    
    // Modelo de dados da tabela
    app->list_store = gtk_list_store_new(N_COLUMNS, 
                                         G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, 
                                         G_TYPE_STRING, G_TYPE_STRING);
    gtk_tree_view_set_model(GTK_TREE_VIEW(app->tree_view), GTK_TREE_MODEL(app->list_store));
    
    // Conectar callback de seleção
    GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(app->tree_view));
    g_signal_connect(selection, "changed", G_CALLBACK(on_tree_selection_changed), app);
    
    // Scroll para tabela
    GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scrolled), app->tree_view);
    gtk_widget_set_size_request(scrolled, -1, 300);
    gtk_box_pack_start(GTK_BOX(aba_box), scrolled, TRUE, TRUE, 0);
    
    // Botões
    GtkWidget *button_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_widget_set_halign(button_box, GTK_ALIGN_CENTER);
    
    app->btn_editar = gtk_button_new_with_label("Editar");
    app->btn_deletar = gtk_button_new_with_label("Deletar");
    app->btn_limpar = gtk_button_new_with_label("Limpar Todos");
    
    // Desabilitar botões inicialmente (até algo ser selecionado)
    gtk_widget_set_sensitive(app->btn_editar, FALSE);
    gtk_widget_set_sensitive(app->btn_deletar, FALSE);
    
    gtk_box_pack_start(GTK_BOX(button_box), app->btn_editar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(button_box), app->btn_deletar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(button_box), app->btn_limpar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(aba_box), button_box, FALSE, FALSE, 10);
    
    // Labels de informação
    GtkWidget *info_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 20);
    app->label_count = gtk_label_new("Produtos: 0");
    app->label_total = gtk_label_new("Total: R$ 0,00");
    gtk_box_pack_start(GTK_BOX(info_box), app->label_count, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(info_box), app->label_total, FALSE, FALSE, 0);
    gtk_widget_set_halign(info_box, GTK_ALIGN_CENTER);
    gtk_box_pack_start(GTK_BOX(aba_box), info_box, FALSE, FALSE, 10);
    
    // Conectar eventos dos botões
    g_signal_connect(app->btn_editar, "clicked", G_CALLBACK(on_btn_editar_clicked), app);
    g_signal_connect(app->btn_deletar, "clicked", G_CALLBACK(on_btn_deletar_clicked), app);
    g_signal_connect(app->btn_limpar, "clicked", G_CALLBACK(on_btn_limpar_clicked), app);
    
    // Adicionar aba
    gtk_notebook_append_page(GTK_NOTEBOOK(app->notebook), aba_box, gtk_label_new("Listar"));
}

void atualizar_lista_produtos(AppWidgets *app) {
    // Limpar lista atual
    gtk_list_store_clear(app->list_store);
    
    // Obter dados do core
    Produto *produtos = getProdutos();
    int total = getTotalProdutos();
    
    // Preencher tabela
    for (int i = 0; i < total; i++) {
        GtkTreeIter iter;
        gtk_list_store_append(app->list_store, &iter);
        
        char preco_str[32], qtd_str[32], total_str[32];
        snprintf(preco_str, sizeof(preco_str), "R$ %.2f", produtos[i].preco);
        snprintf(qtd_str, sizeof(qtd_str), "%.2f", produtos[i].quantidade);
        snprintf(total_str, sizeof(total_str), "R$ %.2f", produtos[i].total);
        
        gtk_list_store_set(app->list_store, &iter,
                          COL_ID, produtos[i].id,
                          COL_NOME, produtos[i].nome,
                          COL_PRECO, preco_str,
                          COL_QUANTIDADE, qtd_str,
                          COL_TOTAL, total_str, -1);
    }
    
    // Atualizar labels
    char count_text[64], total_text[64];
    snprintf(count_text, sizeof(count_text), "Produtos: %d", total);
    snprintf(total_text, sizeof(total_text), "Total: R$ %.2f", getSomaTotal());
    
    gtk_label_set_text(GTK_LABEL(app->label_count), count_text);
    gtk_label_set_text(GTK_LABEL(app->label_total), total_text);
}

void mostrar_mensagem_status(AppWidgets *app, const char *message) {
    gtk_statusbar_pop(GTK_STATUSBAR(app->statusbar), app->context_id);
    gtk_statusbar_push(GTK_STATUSBAR(app->statusbar), app->context_id, message);
}