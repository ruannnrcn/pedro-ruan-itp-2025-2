#include "produto_gui.h"

int main(int argc, char *argv[]) {
    // Inicializar GTK
    gtk_init(&argc, &argv);
    
    // Criar estrutura da aplicação
    AppWidgets app = {0};
    
    // Criar interface
    criar_janela_principal(&app);
    
    // Executar loop principal do GTK
    gtk_main();
    
    return 0;
}