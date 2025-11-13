# ITP 2025-2 - Repositório de Estudos

Este repositório contém materiais, exercícios e projetos desenvolvidos durante o curso de Introdução às Técnicas de Programação (ITP) 2025-2.

## 🎥 Vídeo de Apresentação

**Duração:** 5-8 minutos  
**Link:** [https://youtu.be/ISW3GK7lOW8](https://youtu.be/ISW3GK7lOW8)

## 📂 Estrutura do Repositório

```
pedro-ruan-itp-2025-2/
├── listas/                    # Exercícios e listas resolvidas
│   ├── semana2_variáveis_tipos_operadores/      
│   ├── semana3_estruturas_condicionais/         
│   ├── semana4A_repetições_simples/             
│   ├── semana4B_repetições_simples/             
│   ├── semana5_funcoes/                          
│   ├── semana7_strings/                          
│   └── semana8_repeticoes_aninhadas/            
├── projeto/                   # Projeto principal - Sistema de Produtos
│   ├── src/                   # Código-fonte
│   │   ├── app/              # Lógica de negócio
│   │   │   └── produto.c     # Sistema principal
│   │   └── view/             # Interface
│   │       └── test.gtk.c    # Interface GTK (teste)
│   ├── build/                 # Arquivos compilados (criado pelo Makefile)
│   ├── Makefile              # Automação de build
│   └── README.md             # Documentação do projeto
├── .vscode/                   # Configurações do VS Code
└── README.md                  # Este arquivo
```

### Descrição das Pastas

#### 📚 **Listas de Exercícios**
- **Semana 2**: Variáveis, tipos e operadores 
- **Semana 3**: Estruturas condicionais 
- **Semana 4A**: Repetições simples 
- **Semana 4B**: Repetições simples 
- **Semana 5**: Funções 
- **Semana 7**: Strings 
- **Semana 8**: Repetições aninhadas 

#### 🛍️ **Projeto Principal - Sistema de Produtos**
Um sistema completo de gerenciamento de produtos em terminal com as seguintes funcionalidades:
- ✅ **Adicionar produtos** (nome, preço, quantidade)
- ✅ **Listar produtos** (com IDs, formatação tabular e totais)
- ✅ **Deletar produtos** (com confirmação e reorganização de IDs)
- ✅ **Validações** (valores positivos, confirmações)
- ✅ **Interface amigável** (menu com bordas ASCII)

**Características técnicas:**
- Uso de `struct` com `typedef` para organização de dados
- Arrays para armazenamento de até 100 produtos
- Funções modulares para cada operação
- Sistema de IDs automático e reorganização após deleções
- Makefile para compilação automatizada

#### ⚙️ **Configurações**
- **.vscode/**: Configurações de IntelliSense para C/GTK

## 📋 Checklist de Entrega

### ✅ Estrutura do Arquivo
- [x] README.md principal presente
- [x] Estrutura de pastas organizada
- [x] Link do repositório: [https://github.com/ruannnrcn/pedro-ruan-itp-2025-2](https://github.com/ruannnrcn/pedro-ruan-itp-2025-2)

### �️ Projeto Principal
- [x] **Sistema de Produtos** implementado
- [x] Usa conceitos da Unidade 1 (variáveis, estruturas, funções, arrays)
- [x] Possui 4+ funções além da main:
  - `calcularTotal()` - Calcula preço total
  - `adicionarProduto()` - Adiciona produto ao sistema
  - `listarProdutos()` - Lista todos os produtos
  - `deletarProduto()` - Remove produto do sistema
  - `validacaoPositivo()` - Valida valores positivos
- [x] Projeto executa corretamente com `make run`
- [x] Interface de terminal funcional e intuitiva

## 🚀 Como Usar

### 📦 Clonando o Repositório
```bash
git clone https://github.com/ruannnrcn/pedro-ruan-itp-2025-2.git
cd pedro-ruan-itp-2025-2
```

### 🛍️ Executando o Projeto Principal
```bash
cd projeto/
make run          # Compila e executa o sistema
make clean        # Limpa arquivos compilados
make rebuild      # Recompila tudo do zero e executa
```

### 🎮 Usando o Sistema de Produtos
1. Execute com `make run`
2. Use o menu interativo:
   - **[A]** - Adicionar um novo produto
   - **[L]** - Listar todos os produtos
   - **[D]** - Deletar um produto (por ID)
   - **[N]** - Sair do programa

## 🔧 Tecnologias Utilizadas

- **Linguagem**: C (padrão C17)
- **Compilador**: GCC
- **Interface Gráfica**: GTK 3
- **Ambiente**: Linux/WSL
- **Editor**: VS Code
- **Controle de Versão**: Git/GitHub

## 👨‍💻 Autor

**Pedro Ruan**  
Curso: Introdução às Técnicas de Programação (ITP) 2025-2  
Repositório: [https://github.com/ruannnrcn/pedro-ruan-itp-2025-2](https://github.com/ruannnrcn/pedro-ruan-itp-2025-2)

---

**Última atualização:** Novembro/2025
