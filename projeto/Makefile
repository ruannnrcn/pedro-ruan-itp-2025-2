# Makefile para o Sistema de Produtos
CC = gcc
CFLAGS = -Wall -I$(SRC_DIR)
GTK_CFLAGS = $(shell pkg-config --cflags gtk+-3.0)
GTK_LIBS = $(shell pkg-config --libs gtk+-3.0)

# Diretórios
SRC_DIR = src/app
VIEW_DIR = src/view
BUILD_DIR = build

# Executáveis
TARGET_CLI = produto_cli
TARGET_GUI = produto_gui
TARGET_ORIGINAL = produto


# Arquivos fonte
CORE_SOURCES = $(SRC_DIR)/produto_core.c
CLI_SOURCES = $(SRC_DIR)/produto_cli.c
GUI_SOURCES = $(VIEW_DIR)/produto_gui.c $(VIEW_DIR)/produto_callbacks.c $(VIEW_DIR)/main_gui.c
ORIGINAL_SOURCES = $(SRC_DIR)/produto.c

# Criar diretório de build se não existir
$(shell mkdir -p $(BUILD_DIR))

# Compilar tudo
all: original cli gui

# Produto original (PRINCIPAL)
original: $(BUILD_DIR)/$(TARGET_ORIGINAL)

# CLI usando core
cli: $(BUILD_DIR)/$(TARGET_CLI)

# GUI (Interface Gráfica)
gui: $(BUILD_DIR)/$(TARGET_GUI)

# Interface Gráfica GTK
$(BUILD_DIR)/$(TARGET_GUI): $(GUI_SOURCES) $(CORE_SOURCES)
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(GUI_SOURCES) $(CORE_SOURCES) -o $(BUILD_DIR)/$(TARGET_GUI) $(GTK_CFLAGS) $(GTK_LIBS)
	@echo "GUI compilada com sucesso!"

# CLI usando core  
$(BUILD_DIR)/$(TARGET_CLI): $(CLI_SOURCES) $(CORE_SOURCES)
	$(CC) $(CFLAGS) $(CLI_SOURCES) $(CORE_SOURCES) -o $(BUILD_DIR)/$(TARGET_CLI)
	@echo "CLI (usando core) compilada com sucesso!"

# Produto original
$(BUILD_DIR)/$(TARGET_ORIGINAL): $(ORIGINAL_SOURCES)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET_ORIGINAL) $(ORIGINAL_SOURCES)
	@echo "Versão original compilada com sucesso!"

# Executar produto.c 
run: $(BUILD_DIR)/$(TARGET_ORIGINAL)
	@echo "Executando produto.c (original)..."
	./$(BUILD_DIR)/$(TARGET_ORIGINAL)

# Executar CLI usando core
run-cli: $(BUILD_DIR)/$(TARGET_CLI)
	@echo "Executando CLI (usando core)..."
	./$(BUILD_DIR)/$(TARGET_CLI)

# Executar GUI
run-gui: $(BUILD_DIR)/$(TARGET_GUI)
	@echo "Executando Interface Gráfica..."
	./$(BUILD_DIR)/$(TARGET_GUI)

# Executar versão original
run-original: $(BUILD_DIR)/$(TARGET_ORIGINAL)
	@echo "Executando versão original..."
	./$(BUILD_DIR)/$(TARGET_ORIGINAL)


# Limpar todos os arquivos compilados
clean:
	@echo "Limpando arquivos compilados..."
	rm -rf $(BUILD_DIR)
	@echo "Limpeza concluída!"

# Limpar apenas GUI
clean-gui:
	rm -f $(BUILD_DIR)/$(TARGET_GUI)
	@echo "GUI removida!"


# Rebuild produto.c
rebuild: clean original
	@echo "Produto original reconstruído com sucesso!"

# Rebuild CLI
rebuild-cli: clean cli
	@echo "CLI reconstruída com sucesso!"
# Rebuild GUI
rebuild-gui: clean gui
	@echo "GUI reconstruída com sucesso!"

# Rebuild tudo
rebuild-all: clean all
	@echo "Todos os executáveis reconstruídos!"

# Instalar dependências GTK (Ubuntu/Debian)
install-deps:
	@echo "Instalando dependências GTK..."
	sudo apt update
	sudo apt install -y libgtk-3-dev pkg-config

# Verificar se GTK está instalado
check-gtk:
	@echo "Verificando GTK..."
	pkg-config --modversion gtk+-3.0 && echo "GTK instalado!" || echo "GTK não encontrado!"

# Mostrar ajuda
help:
	@echo "COMANDOS DISPONÍVEIS:"
	@echo ""
	@echo "=== PRINCIPAIS ==="
	@echo "  make run          - Executa produto.c"
	@echo "  make rebuild      - Limpa e recompila produto.c"
	@echo "  make clean        - Remove arquivos compilados"
	@echo ""
	@echo "=== DESENVOLVIMENTO ==="
	@echo "  make original     - Compila apenas produto.c"
	@echo "  make cli          - Compila apenas CLI"
	@echo "  make gui          - Compila apenas GUI"
	@echo "  make run-cli      - Executa CLI"
	@echo "  make run-gui      - Executa interface gráfica"
	@echo "  make rebuild-all  - Reconstrói tudo"
	@echo ""
	@echo "=== SETUP ==="
	@echo "  make install-deps - Instala dependências GTK"
	@echo "  make check-gtk    - Verifica se GTK está instalado"

# Targets que não criam arquivos
.PHONY: all cli gui original run run-gui run-cli run-original clean clean-gui rebuild rebuild-gui rebuild-all install-deps check-gtk help