# Projeto ITP 2025-2 - Sistema de Gerenciamento de Produtos

Este é o projeto principal do curso, desenvolvido em C com interface de terminal e preparação para interface gráfica GTK.

## 🎯 Objetivo

Desenvolver um sistema completo de gerenciamento de produtos com funcionalidades de CRUD (Create, Read, Update, Delete), validação de dados, cálculos automáticos e interface amigável, aplicando conceitos de programação estruturada, modularização e boas práticas de desenvolvimento.

## 🎥 Demonstração

Assista ao vídeo de apresentação: [https://youtu.be/ISW3GK7lOW8](https://youtu.be/ISW3GK7lOW8)

## Estrutura do Projeto

```
projeto/
├── src/               # Código-fonte principal
│   ├── app/           # Lógica da aplicação e regras de negócio
│   │   └── produto.c  # Sistema principal completo
│   └── view/          # Interface gráfica (preparação futura)
│       └── test.gtk.c # Exemplo básico de janela GTK
├── build/             # Arquivos compilados (criado automaticamente)
├── Makefile           # Automação de compilação e execução
└── README.md          # Este arquivo de documentação
```

### Descrição das Pastas

- **src/app/**: Contém a lógica completa da aplicação
  - `produto.c`: Sistema completo de gerenciamento com CRUD, validações e interface
- **src/view/**: Preparação para interface gráfica futura
  - `test.gtk.c`: Exemplo básico de janela GTK para testes
- **build/**: Diretório para arquivos compilados (criado automaticamente pelo Makefile)
- **Makefile**: Automação completa de build com comandos simplificados

## 🚀 Como Compilar e Executar

### 🎮 Sistema Principal (Recomendado)

**Compilar e executar em um comando:**
```bash
make run
```

**Outros comandos úteis:**
```bash
make clean        # Remove arquivos compilados
```

### 📋 Menu do Sistema
Após executar, você verá um menu interativo:

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

### 🧪 Compilação Manual (Opcional)

Se preferir compilar manualmente:
```bash
cd src/app
gcc -Wall produto.c -o produto
./produto
```

### 🧪 Interface GTK (Experimental)

Para testar a janela GTK de exemplo:

```bash
cd src/view
gcc test.gtk.c -o test-gtk `pkg-config --cflags --libs gtk+-3.0`
./test-gtk
```

## Requisitos do Sistema

### 🖥️ **Ambiente Mínimo**
- **Sistema Operacional**: Linux, WSL ou macOS
- **Compilador**: GCC (GNU Compiler Collection)
- **Make**: Para automação de build

### 📦 **Para Interface GTK (Opcional)**
```bash
# Ubuntu/Debian/WSL
sudo apt update
sudo apt install build-essential libgtk-3-dev

# Fedora/RedHat
sudo dnf install gcc gtk3-devel

# macOS (com Homebrew)
brew install gtk+3
```

## 🔧 Tecnologias Utilizadas

- **Linguagem**: C (padrão C99)
- **Compilador**: GCC com flags de segurança (`-Wall -Wextra`)
- **Build System**: Make (Makefile personalizado)
- **Interface**: Terminal/CLI com formatação ASCII
- **Estruturas de Dados**: Arrays, structs e typedef
- **Ambiente de Desenvolvimento**: Linux/WSL
- **Controle de Versão**: Git

## � Resolução de Problemas

### ❌ **Erro de Compilação**
```bash
# Se o make não funcionar, compile manualmente:
cd src/app
gcc -Wall produto.c -o produto
```

### 📁 **Pasta build não criada**
```bash
# Crie manualmente se necessário:
mkdir build
```

### 🚫 **Permissão negada**
```bash
# Torne o arquivo executável:
chmod +x build/produto
```

## �👨‍💻 Autor

**Pedro Ruan**  
Estudante de ITP 2025-2  
GitHub: [@ruannnrcn](https://github.com/ruannnrcn)

---

*Sistema desenvolvido como projeto final da disciplina Introdução às Técnicas de Programação, demonstrando competências em programação estruturada, manipulação de dados e desenvolvimento de interfaces.*
