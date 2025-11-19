# Makefile para o Sistema de Produtos
CC = gcc
CFLAGS = -Wall 

# Diretórios
SRC_DIR = src/app
BUILD_DIR = build

# Nome do executável
TARGET = produto

# Nome do arquivo produto_refact
TARGET_REFACT = produto_refact

# Arquivos fonte
SOURCES = $(SRC_DIR)/produto.c
SOURCES_REF = $(SRC_DIR)/produto_refact.c

# Criar diretório de build se não existir
$(shell mkdir -p $(BUILD_DIR))

# Compilar o programa
all: $(BUILD_DIR)/$(TARGET)


$(BUILD_DIR)/$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $(SOURCES)
	@echo "Compilação concluída!"

# Compilar o programa refatorado
$(BUILD_DIR)/$(TARGET_REFACT): $(SOURCES_REF)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET_REFACT) $(SOURCES_REF)
	@echo "Compilação do produto_refact concluída!"

# Executar o programa
run: $(BUILD_DIR)/$(TARGET)
	@echo "Executando o programa..."
	./$(BUILD_DIR)/$(TARGET)

run_refact: $(BUILD_DIR)/$(TARGET_REFACT)
	@echo "Executando o programa refatorado..."
	./$(BUILD_DIR)/$(TARGET_REFACT)

# Limpar arquivos compilados
clean:
	rm -rf $(BUILD_DIR)
	@echo "Arquivos removidos"

.PHONY: all run run_refact clean