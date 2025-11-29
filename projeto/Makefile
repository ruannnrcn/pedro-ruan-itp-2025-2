# Makefile para o Sistema de Produtos
CC = gcc
CFLAGS = -Wall -I$(SRC_DIR)
GTK_CFLAGS = $(shell pkg-config --cflags gtk+-3.0 2>/dev/null)
GTK_LIBS = $(shell pkg-config --libs gtk+-3.0 2>/dev/null)

# Diretórios
SRC_DIR = src/app
VIEW_DIR = src/view
BUILD_DIR = build

# Executáveis
TARGET_GUI = produto_gui
TARGET_ORIGINAL = produto

# Arquivos fonte
CORE_SOURCES = $(SRC_DIR)/produto_core.c
GUI_SOURCES = $(VIEW_DIR)/produto_gui.c $(VIEW_DIR)/produto_callbacks.c $(VIEW_DIR)/main_gui.c
ORIGINAL_SOURCES = $(SRC_DIR)/produto.c

# Criar diretório de build se não existir
$(shell mkdir -p $(BUILD_DIR))

# Compilar tudo
all: original gui

# Produto original (PRINCIPAL)
original: $(BUILD_DIR)/$(TARGET_ORIGINAL)

# GUI (Interface Gráfica)
gui: $(BUILD_DIR)/$(TARGET_GUI)

# Interface Gráfica GTK
$(BUILD_DIR)/$(TARGET_GUI): $(GUI_SOURCES) $(CORE_SOURCES)
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(GUI_SOURCES) $(CORE_SOURCES) -o $(BUILD_DIR)/$(TARGET_GUI) $(GTK_CFLAGS) $(GTK_LIBS)
	@echo "GUI compilada com sucesso!"

# Produto original
$(BUILD_DIR)/$(TARGET_ORIGINAL): $(ORIGINAL_SOURCES)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET_ORIGINAL) $(ORIGINAL_SOURCES)
	@echo "Versão original compilada com sucesso!"

# Executar produto.c (padrão)
run: $(BUILD_DIR)/$(TARGET_ORIGINAL)
	@echo "Executando produto.c..."
	./$(BUILD_DIR)/$(TARGET_ORIGINAL)

# Executar GUI
run-gui: $(BUILD_DIR)/$(TARGET_GUI)
	@echo "Executando Interface Gráfica..."
	./$(BUILD_DIR)/$(TARGET_GUI)


# Limpar arquivos compilados
clean:
	@echo "Limpando arquivos compilados..."
	rm -rf $(BUILD_DIR)
	@echo "Limpeza concluída!"

# Rebuild produto original
rebuild: clean original
	@echo "Produto original reconstruído!"

# Rebuild GUI
rebuild-gui: clean gui
	@echo "GUI reconstruída!"

# Rebuild tudo
rebuild-all: clean all
	@echo "Todos os executáveis reconstruídos!"

# INSTALAÇÃO DE DEPENDÊNCIAS

# Instalar todas as dependências (GCC + GTK)
install-deps:
	@echo "=========================================="
	@echo "Instalando todas as dependências"
	@echo "=========================================="
	@$(MAKE) install-gcc
	@$(MAKE) install-gtk
	@echo ""
	@echo "✓ Todas as dependências instaladas!"

# Instalar apenas GCC e build-essential
install-gcc:
	@echo "Verificando GCC..."
	@if command -v gcc >/dev/null 2>&1; then \
		echo "✓ GCC já instalado: $$(gcc --version | head -n1)"; \
	else \
		echo "Instalando GCC e build-essential..."; \
		sudo apt update && sudo apt install -y build-essential; \
		echo "✓ GCC instalado com sucesso!"; \
	fi

# Instalar apenas GTK 3
install-gtk:
	@echo "Verificando GTK..."
	@if pkg-config --exists gtk+-3.0 2>/dev/null; then \
		echo "✓ GTK já instalado: $$(pkg-config --modversion gtk+-3.0)"; \
	else \
		echo "Instalando GTK 3 e dependências..."; \
		sudo apt update && sudo apt install -y libgtk-3-dev pkg-config; \
		echo "✓ GTK instalado com sucesso!"; \
	fi

# Verificar status de todas as dependências
check-deps:
	@echo "=========================================="
	@echo "Status das dependências"
	@echo "=========================================="
	@echo -n "GCC: "
	@if command -v gcc >/dev/null 2>&1; then \
		echo "✓ Instalado ($$(gcc --version | head -n1))"; \
	else \
		echo "✗ Não instalado"; \
	fi
	@echo -n "GTK 3: "
	@if pkg-config --exists gtk+-3.0 2>/dev/null; then \
		echo "✓ Instalado (versão $$(pkg-config --modversion gtk+-3.0))"; \
	else \
		echo "✗ Não instalado"; \
	fi
	@echo -n "pkg-config: "
	@if command -v pkg-config >/dev/null 2>&1; then \
		echo "✓ Instalado"; \
	else \
		echo "✗ Não instalado"; \
	fi

# Mostrar ajuda
help:
	@echo "INSTALAÇÃO DE DEPENDÊNCIAS:"
	@echo "  make install-deps - Instala GCC + GTK (completo)"
	@echo "  make install-gcc  - Instala apenas GCC"
	@echo "  make install-gtk  - Instala apenas GTK"
	@echo "  make check-deps   - Verifica dependências instaladas"
	@echo ""
	@echo "COMPILAÇÃO:"
	@echo "  make all          - Compila produto.c + GUI"
	@echo "  make original     - Compila apenas produto.c"
	@echo "  make gui          - Compila apenas GUI"
	@echo ""
	@echo "EXECUÇÃO:"
	@echo "  make run          - Executa produto.c"
	@echo "  make run-gui      - Executa interface gráfica"
	@echo ""
	@echo "LIMPEZA E REBUILD:"
	@echo "  make clean        - Remove arquivos compilados"
	@echo "  make rebuild      - Limpa e recompila produto.c"
	@echo "  make rebuild-gui  - Limpa e recompila GUI"
	@echo "  make rebuild-all  - Reconstrói tudo"

# Targets que não criam arquivos
.PHONY: all original gui run run-gui clean rebuild rebuild-gui rebuild-all \
        install-deps install-gcc install-gtk check-deps help