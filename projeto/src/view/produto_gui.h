#ifndef PRODUTO_GUI_H
#define PRODUTO_GUI_H

#include <gtk/gtk.h>
#include "../app/produto_core.h"

// Estrutura para widgets globais da aplicação
typedef struct {
    GtkWidget *window;
    GtkWidget *notebook;
    
    // Widgets para adicionar produto
    GtkWidget *entry_nome;
    GtkWidget *spin_preco;
    GtkWidget *spin_quantidade;
    GtkWidget *btn_adicionar;
    
    // Widgets para listar produtos
    GtkWidget *tree_view;
    GtkListStore *list_store;
    GtkWidget *label_total;
    GtkWidget *label_count;
    
    // Widgets para ações
    GtkWidget *btn_editar;
    GtkWidget *btn_deletar;
    GtkWidget *btn_limpar;
    
    // Status
    GtkWidget *statusbar;
    guint context_id;
} AppWidgets;

// Declarações das funções principais
void criar_janela_principal(AppWidgets *app);
void criar_aba_adicionar(AppWidgets *app);
void criar_aba_listar(AppWidgets *app);
void atualizar_lista_produtos(AppWidgets *app);
void mostrar_mensagem_status(AppWidgets *app, const char *message);

// Callbacks (funções que respondem a eventos)
void on_btn_adicionar_clicked(GtkWidget *widget, gpointer data);
void on_btn_editar_clicked(GtkWidget *widget, gpointer data);
void on_btn_deletar_clicked(GtkWidget *widget, gpointer data);
void on_btn_limpar_clicked(GtkWidget *widget, gpointer data);
void on_tree_selection_changed(GtkTreeSelection *selection, gpointer data);
void on_window_destroy(GtkWidget *widget, gpointer data);

#endif // PRODUTO_GUI_H