# ITP 2025-2 - Repositório de Estudos

Este repositório contém materiais, exercícios e projetos desenvolvidos durante o curso de Introdução às Técnicas de Programação (ITP) 2025-2.

📂 Estrutura do Repositório

```
pedro-ruan-itp-2025-2/
├── listas/                    
│   ├── semana2_variáveis_tipos_operadores/      
│   ├── semana3_estruturas_condicionais/         
│   ├── semana4A_repetições_simples/             
│   ├── semana4B_repetições_simples/             
│   ├── semana5_funcoes/                         
│   ├── semana7_strings/                         
│   ├── semana8_repeticoes_aninhadas/          
│   └── semana9_matrizes/                       
├── projeto/                   # 🎯 Projeto principal - Sistema de Produtos
│   ├── src/                   # Código-fonte modular
│   │   ├── app/              # Backend e lógica de negócio
│   │   │   ├── produto.c     # Sistema monolítico original
│   │   │   ├── produto_core.c/h  # Lógica de negócio (backend)
│   │   │   └── produto_cli.c     # Interface de linha de comando
│   │   └── view/             # Frontend e interfaces gráficas
│   │       ├── produto_gui.c/h   # Interface GTK principal
│   │       ├── produto_callbacks.c # Eventos e callbacks GTK
│   │       └── main_gui.c        # Ponto de entrada GUI
│   ├── build/                # Executáveis compilados (auto-gerado)
│   ├── Makefile             # Build system avançado (15+ comandos)
│   └── README.md            # Documentação técnica detalhada
├── relatorios/              # 📊 Documentação acadêmica e análises
├── videos/                  # 🎥 Material audiovisual e demonstrações
├── .vscode/                 # ⚙️ Configurações de desenvolvimento
│   └── c_cpp_properties.json   # IntelliSense para C/GTK
└── README.md                # 📖 Este arquivo de documentação geral
```


#### 🎯 **Projeto Principal - Sistema de Gerenciamento de Produtos**

**📋 Funcionalidades Implementadas:**
- ✅ **CRUD Completo** - Create, Read, Update, Delete de produtos
- ✅ **Múltiplas Interfaces** - CLI (terminal) e GUI (GTK+3)
- ✅ **Validações Robustas** - Entrada de dados, valores positivos, confirmações
- ✅ **Cálculos Automáticos** - Totais por produto e geral
- ✅ **Formatação Profissional** - Tabelas ASCII, bordas decorativas
- ✅ **Arquitetura Modular** - Separação core/view (MVC simplificado)

**🏗️ Arquitetura do Sistema:**
- **Core/Backend**: `produto_core.c/h` - Lógica de negócio pura
- **CLI**: `produto_cli.c` - Interface de terminal usando core
- **GUI**: `view/` - Interface gráfica GTK usando core
- **Original**: `produto.c` - Versão monolítica (compatibilidade)

**🛠️ Características Técnicas Avançadas:**
- Uso de `struct` com `typedef` para organização de dados
- Arrays dinâmicos para armazenamento de até 100 produtos
- Sistema de IDs automático com reorganização após deleções
- Makefile avançado com 15+ comandos de build/execução
- Separação clara de responsabilidades (Single Responsibility)
- Interface gráfica responsiva com callbacks
- Gerenciamento de memória eficiente

**⚡ Comandos do Makefile:**
```bash
make run          # Executa versão original (produto.c)
make run-cli      # Executa interface CLI modular
make run-gui      # Executa interface gráfica GTK
make help         # Lista todos os comandos disponíveis
make clean        # Limpa todos os arquivos gerados pelo build
make install-deps # Instala dependências GTK automaticamente
```

#### 📊 **Relatórios e Documentação Acadêmica**
- Análises de desempenho e complexidade algorítmica
- Documentação de design e arquitetura
- Relatórios de testes e validação

#### 🎥 **Material Audiovisual**
- Demonstrações das funcionalidades implementadas
- Explicações técnicas e conceituais
- Apresentações do projeto final

#### ⚙️ **Configurações de Desenvolvimento**
- **`.vscode/c_cpp_properties.json`**: Configuração de IntelliSense para C/C++
- **Suporte completo a GTK+3**: Headers, bibliotecas e debugging
- **Integração com GDB**: Debug avançado com breakpoints

## 📋 Checklist de Entrega e Conformidade Acadêmica

### ✅ **Estrutura e Organização**
- [x] README.md principal presente e documentado
- [x] Estrutura de pastas organizada por semanas/tópicos
- [x] Nomenclatura consistente e descritiva
- [x] Link do repositório: [https://github.com/ruannnrcn/pedro-ruan-itp-2025-2](https://github.com/ruannnrcn/pedro-ruan-itp-2025-2)

### 🎯 **Projeto Principal - Critérios Atendidos**
- [x] **Sistema de Produtos** implementado e funcional
- [x] **Conceitos da Unidade 1** aplicados (variáveis, estruturas, funções, arrays)
- [x] **4+ funções além da main** implementadas:
  - `calcularTotal()` - Cálculo de preços totais
  - `adicionarProduto()` - Inserção de novos produtos
  - `listarProdutos()` - Exibição formatada de dados
  - `deletarProduto()` - Remoção com reorganização
  - `validacaoPositivo()` - Validação de entrada
  - `reorganizarIds()` - Manutenção de integridade
- [x] **Projeto executa corretamente** com `make run`
- [x] **Interface funcional e intuitiva** para usuários finais
- [x] **Arquitetura modular** com separação de responsabilidades

### 🏆 **Critérios Avançados (Extras)**
- [x] **Múltiplas interfaces** (CLI + GUI GTK)
- [x] **Build system avançado** (Makefile com 15+ comandos)
- [x] **Validações robustas** e tratamento de erros
- [x] **Documentação técnica** completa e profissional
- [x] **Código limpo** com boas práticas de programação

## 🚀 Como Usar o Repositório

### 📦 **Setup Inicial do Ambiente**
```bash
# 1. Clone o repositório
git clone https://github.com/ruannnrcn/pedro-ruan-itp-2025-2.git
cd pedro-ruan-itp-2025-2

# 2. Verificar estrutura
ls -la

# 3. Navegar para o projeto principal
cd projeto/

# 4. Ver comandos disponíveis
make help
```

### 🎯 **Executando o Projeto Principal**
```bash
# Execução rápida (recomendado)
make run              # Compila e executa sistema original

# Outras opções de interface
make run-cli          # Interface de linha de comando modular
make run-gui          # Interface gráfica GTK (requer dependências)

# Comandos de build
make clean           # Limpa arquivos compilados
make rebuild         # Recompila completamente
make install-deps    # Instala dependências GTK (Ubuntu/Debian)
```

### 🎮 **Interface do Sistema de Produtos**
Após executar `make run`, você verá:

```
╔══════════════════════════════════════╗
║            MENU PRINCIPAL            ║
╠══════════════════════════════════════╣
║  [A] Adicionar produto               ║
║  [L] Listar produtos                 ║
║  [D] Deletar produto                 ║
║  [E] Editar produto                  ║
║  [N] Sair do programa                ║
╚══════════════════════════════════════╝
```

**Exemplo de uso completo:**
1. **[A]** - Adicionar: "Notebook Dell", R$ 2500,50, Qtd: 2
2. **[L]** - Listar: Visualizar produtos cadastrados
3. **[D]** - Deletar: Remover produto por ID
4. **[N]** - Sair: Finalizar programa

## 🔧 Tecnologias e Ferramentas Utilizadas

### 💻 **Stack Principal**
- **Linguagem**: C (padrão C99/C17)
- **Compilador**: GCC (GNU Compiler Collection) com flags de segurança
- **Build System**: Make com Makefile avançado
- **IDE**: Visual Studio Code com extensões C/C++

### 🎨 **Interfaces e UX**
- **CLI**: Terminal/ASCII com formatação profissional
- **GUI**: GTK+3 (toolkit gráfico nativo Linux)
- **Design**: Bordas ASCII decorativas, tabelas formatadas
- **UX**: Validações em tempo real, confirmações de segurança

### 🏗️ **Arquitetura e Padrões**
- **Arquitetura**: MVC simplificado (core/view separation)
- **Modularização**: Separação clara de responsabilidades
- **Estruturas de Dados**: Arrays, structs, typedef
- **Gerenciamento de Memória**: Alocação estática eficiente

### 🔄 **Desenvolvimento e Deploy**
- **Controle de Versão**: Git com GitHub
- **Ambiente**: Linux/WSL (compatível com macOS)
- **Debugging**: GDB integrado, logging personalizado
- **Automação**: Scripts de build, instalação de dependências

### 📦 **Dependências e Bibliotecas**
```bash
# Dependências básicas (CLI)
gcc, make, libc6-dev

# Dependências GUI (opcional)
libgtk-3-dev, pkg-config

# Ferramentas de desenvolvimento
gdb, valgrind (análise de memória)
```

## � Estatísticas do Projeto

### � **Métricas de Código**
- **Total de Arquivos C**: 40+ exercícios + projeto principal
- **Linhas de Código**: ~2000+ linhas implementadas
- **Funções Implementadas**: 50+ funções modulares
- **Estruturas de Dados**: 10+ structs e tipos personalizados

### 🏆 **Funcionalidades Avançadas**
- **Arquitetura Modular**: Core/View separation
- **Múltiplas Interfaces**: CLI + GUI
- **Build System**: 15+ comandos automatizados
- **Validações**: Robustas e user-friendly
- **Documentação**: Técnica e acadêmica completa

## 👨‍💻 Autor

**Pedro Ruan**  
📚 **Curso**: Introdução às Técnicas de Programação (ITP) 2025-2  
🔗 **Repositório**: [https://github.com/ruannnrcn/pedro-ruan-itp-2025-2](https://github.com/ruannnrcn/pedro-ruan-itp-2025-2)  
📧 **Contato**: [GitHub @ruannnrcn](https://github.com/ruannnrcn)

### 🎓 **Competências Demonstradas**
- Programação estruturada em C
- Desenvolvimento de interfaces (CLI/GUI)
- Arquitetura modular e design patterns
- Build systems e automação
- Documentação técnica profissional
- Controle de versão e colaboração

---

### 🏅 **Resumo Executivo**

Este repositório representa um portfólio completo da disciplina ITP 2025-2, demonstrando evolução progressiva desde conceitos básicos até implementação de sistemas complexos. O projeto principal showcases arquitetura avançada com separação de responsabilidades, múltiplas interfaces e build system robusto, superando os requisitos mínimos da disciplina.

---

**📅 Última atualização:** Novembro/2025  
**🎯 Status:** Projeto Finalizado ✅
