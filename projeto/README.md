# Projeto ITP 2025-2 - Sistema de Gerenciamento de Produtos

Este é o projeto principal do curso, desenvolvido em C com múltiplas interfaces: terminal (CLI) e interface gráfica GTK. O projeto utiliza uma arquitetura modular com separação entre lógica de negócio (core) e interfaces (view).

## 🎯 Objetivo

Desenvolver um sistema completo de gerenciamento de produtos com funcionalidades de CRUD (Create, Read, Update, Delete), validação de dados, cálculos automáticos e interface amigável, aplicando conceitos de programação estruturada, modularização e boas práticas de desenvolvimento.

## 📁 Estrutura do Projeto

```
projeto/
├── src/                    # Código-fonte principal
│   ├── app/               # Lógica da aplicação (core + CLI)
│   │   ├── produto.c      # Sistema original completo
│   │   ├── produto_core.c # Lógica de negócio (backend)
│   │   ├── produto_core.h # Interface do core
│   │   └── produto_cli.c  # Interface de linha de comando
│   └── view/              # Interface gráfica GTK
│       ├── produto_gui.c    # Janela principal GTK
│       ├── produto_gui.h    # Header da interface GTK
│       ├── produto_callbacks.c # Callbacks dos botões
│       └── main_gui.c       # Ponto de entrada da GUI
├── build/                 # Executáveis (criado automaticamente)
├── Makefile              # Automação completa de build
└── README.md             # Este arquivo
```

### 🏗️ Arquitetura do Sistema

- **Core (Backend)**: `produto_core.c/h` - Lógica de negócio pura, sem interface
- **CLI**: `produto_cli.c` - Interface de terminal usando o core
- **GUI**: `view/` - Interface gráfica GTK usando o core  
- **Original**: `produto.c` - Versão monolítica original (compatibilidade)

## 🚀 Como Compilar e Executar

### 🎮 **Comandos Principais (Recomendado)**

**📋 Ver todos os comandos disponíveis:**
```bash
make help
```

**⚡ Execução rápida (produto.c original):**
```bash
make run
```

**🔄 Recompilar e executar:**
```bash
make rebuild
```

**🧹 Limpar arquivos compilados:**
```bash
make clean
```

### 🎛️ **Opções de Interface**

**1. 🖥️ Interface CLI (Terminal)**
```bash
# Compilar e executar CLI modular
make run-cli

# Apenas compilar CLI
make cli
```

**2. 🎨 Interface Gráfica GTK**
```bash
# Compilar e executar GUI
make run-gui

# Apenas compilar GUI
make gui
```

**3. 📄 Versão Original (Monolítica)**
```bash
# Executar produto.c original
make run

# Apenas compilar original
make original
```

### 🔧 **Comandos Avançados**

**Recompilar interfaces específicas:**
```bash
make rebuild-cli    # Reconstrói apenas CLI
make rebuild-gui    # Reconstrói apenas GUI
make rebuild-all    # Reconstrói tudo
```

**Limpeza seletiva:**
```bash
make clean-gui      # Remove apenas executável GUI
make clean          # Remove todos os executáveis
```

### 📋 Funcionalidades do Sistema

**Menu Principal (CLI/Original):**
```
╔══════════════════════════════════════╗
║            MENU PRINCIPAL            ║
╠══════════════════════════════════════╣
║  [A] Adicionar produto               ║
║  [D] Deletar produto                 ║
║  [L] Listar produtos                 ║
║  [N] Sair do programa                ║
╚══════════════════════════════════════╝
```

**Interface Gráfica GTK:**
- Janela intuitiva com botões
- Formulários para entrada de dados
- Listagem visual de produtos
- Cálculos automáticos em tempo real

### 💡 Exemplo de Uso

**1. Adicionar um produto:**
```
Escolha uma opção: A
Digite o nome do produto: Notebook Dell
Digite o preço do produto: 2500.50
Digite a quantidade do produto: 2
Produto Notebook Dell adicionado com sucesso!
Preço total: R$ 5001.00 / Quantidade: 2.00
```

**2. Listar produtos:**
```
=== LISTA DE PRODUTOS ===
ID  Nome                 Preço     Qtd        Total     
-------------------------------------------------------
0   Notebook Dell        R$ 2500.50 2.00       R$ 5001.00
1   Mouse Logitech       R$ 89.90   1.00       R$ 89.90
-------------------------------------------------------
Total geral: R$ 5090.90
Produtos cadastrados: 2
```

### 🧪 **Compilação Manual (Opcional)**

**Se preferir não usar o Makefile:**

```bash
# Produto original
cd src/app
gcc -Wall -o produto produto.c
./produto

# CLI modular
gcc -Wall -I. produto_cli.c produto_core.c -o produto_cli
./produto_cli

# Interface gráfica GTK
cd ../view
gcc -I../app produto_gui.c produto_callbacks.c main_gui.c ../app/produto_core.c \
    -o produto_gui `pkg-config --cflags --libs gtk+-3.0`
./produto_gui
```

## ⚙️ Requisitos do Sistema

### 🖥️ **Para Interface CLI (Terminal)**
- **Sistema Operacional**: Linux, WSL, macOS
- **Compilador**: GCC (GNU Compiler Collection)
- **Make**: Para automação de build (opcional)

### 🎨 **Para Interface Gráfica GTK (Opcional)**
- **Dependências GTK+3**:
  ```bash
  # Ubuntu/Debian/WSL
  sudo apt update
  sudo apt install build-essential libgtk-3-dev pkg-config
  
  # Fedora/RedHat
  sudo dnf install gcc gtk3-devel pkg-config
  
  # macOS (com Homebrew)
  brew install gtk+3 pkg-config
  ```

### 🔍 **Verificar Instalação**
```bash
# Verificar se GTK está disponível
make check-gtk

# Instalar dependências automaticamente (Ubuntu/Debian)
make install-deps
```

## 🔧 Tecnologias Utilizadas

- **Linguagem**: C (padrão C99)
- **Compilador**: GCC com flags de segurança (`-Wall`)
- **Build System**: Make (Makefile avançado)
- **Interface CLI**: Terminal/ASCII com formatação
- **Interface Gráfica**: GTK+3 (toolkit nativo Linux)
- **Arquitetura**: Separação core/view (MVC simplificado)
- **Estruturas de Dados**: Arrays, structs e typedef
- **Ambiente**: Linux/WSL (compatível com macOS)-

## 👨‍💻 Autor

**Pedro Ruan**  
Estudante de ITP 2025-2  
GitHub: [@ruannnrcn](https://github.com/ruannnrcn)

---

*Sistema desenvolvido como projeto final da disciplina Introdução às Técnicas de Programação, demonstrando competências em programação estruturada, arquitetura modular, interfaces múltiplas e boas práticas de desenvolvimento.*
