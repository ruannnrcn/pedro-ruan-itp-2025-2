# Makefile para o Sistema de Produtos
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Diretórios
SRC_DIR = src/app
BUILD_DIR = build

# Nome do executável
TARGET = produto

# Arquivos fonte
SOURCES = $(SRC_DIR)/produto.c

# Criar diretório de build se não existir
$(shell mkdir -p $(BUILD_DIR))

# Compilar o programa
all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $(SOURCES)
	@echo "Compilação concluída!"

# Executar o programa
run: $(BUILD_DIR)/$(TARGET)
	@echo "Executando o programa..."
	./$(BUILD_DIR)/$(TARGET)

# Limpar arquivos compilados
clean:
	rm -rf $(BUILD_DIR)
	@echo "Arquivos removidos"

# Recompilar e executar
rebuild: clean all run

.PHONY: all run clean rebuild