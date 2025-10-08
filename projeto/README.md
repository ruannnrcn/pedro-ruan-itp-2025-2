# Projeto ITP 2025-2 - Sistema de Cadastro de Produtos

Este é o projeto principal do curso, desenvolvido em C com interface gráfica GTK.

## 🎯 Objetivo

Desenvolver um sistema de cadastro de produtos com validação de dados, cálculos automáticos e interface gráfica, aplicando conceitos de programação estruturada, modularização e boas práticas de desenvolvimento.

## 🎥 Demonstração

Assista ao vídeo de apresentação: [https://youtu.be/ISW3GK7lOW8](https://youtu.be/ISW3GK7lOW8)

## ⚙️ Funcionalidades Implementadas

- ✅ Cadastro de produtos com nome, preço unitário e quantidade
- ✅ Validação de entrada de dados (valores positivos)
- ✅ Cálculo automático do valor total (preço × quantidade)
- ✅ Exibição de informações completas do produto
- ✅ Interface via linha de comando (CLI)
- ⏳ Interface gráfica GTK (em desenvolvimento)

## Estrutura do Projeto

```
projeto/
├── src/           # Código-fonte principal
│   ├── app/       # Lógica da aplicação e regras de negócio
│   └── view/      # Interface gráfica (GTK)
├── .vscode/       # Configurações do VS Code (IntelliSense, includes)
└── README.md      # Este arquivo de documentação
```

### Descrição das Pastas

- **src/app/**: Contém a lógica da aplicação
  - `produto.c`: Implementação do sistema de cadastro com validações e cálculos
- **src/view/**: Contém os arquivos de interface gráfica
  - `test.gtk.c`: Exemplo de janela GTK (base para interface futura)
- **.vscode/**: Configurações do VS Code para IntelliSense C/GTK

## 🚀 Como Compilar e Executar

### Sistema de Cadastro (CLI)

Entre na pasta `src/app` e execute:

```bash
cd src/app
gcc produto.c -o produto
./produto
```

**Exemplo de uso:**
```
Digite o nome do produto: Notebook
Digite o preço unitário: 2500.00
Digite a quantidade: 3

Produto cadastrado com sucesso!
Nome: Notebook
Preço unitário: R$ 2500.00
Quantidade: 3
Valor total: R$ 7500.00
```

### Interface GTK (em desenvolvimento)

Entre na pasta `src/view` e execute:

```bash
cd src/view
gcc test.gtk.c -o test-gtk `pkg-config --cflags --libs gtk+-3.0`
./test-gtk
```

## Requisitos

- **Sistema Operacional**: Linux ou WSL
- **Bibliotecas**: 
  - GTK 3 development libraries (`libgtk-3-dev`)
  - HarfBuzz development (`libharfbuzz-dev`)
  - ATK development (`libatk1.0-dev`)
- **Compilador**: GCC
- **Editor**: VS Code (opcional, recomendado para melhor experiência)

### Instalação das Dependências

No Ubuntu/Debian/WSL:

```bash
sudo apt update
sudo apt install build-essential libgtk-3-dev libharfbuzz-dev libatk1.0-dev
```

## Configuração do Ambiente de Desenvolvimento

Para garantir o funcionamento correto do IntelliSense no VS Code:

1. A pasta `.vscode` deve estar versionada (já está incluída no projeto)
2. O arquivo `c_cpp_properties.json` contém os caminhos de include necessários para GTK
3. Ao abrir o projeto no VS Code, o IntelliSense reconhecerá automaticamente os headers do GTK

## 📚 Conceitos Aplicados

- **Modularização**: Código organizado em funções reutilizáveis
- **Validação de dados**: Verificação de entradas do usuário
- **Estruturas de controle**: Loops e condicionais
- **Tipos de dados**: Uso adequado de int, float, char
- **Boas práticas**: Código limpo, comentado e bem estruturado

## 🔧 Tecnologias Utilizadas

- **Linguagem**: C (padrão C17)
- **Compilador**: GCC
- **Interface Gráfica**: GTK 3 (planejada)
- **Ambiente**: Linux/WSL
- **Controle de Versão**: Git

## 📝 Observações

- Para garantir o funcionamento do IntelliSense, mantenha a pasta `.vscode` versionada
- Se estiver usando WSL, certifique-se de ter um servidor X instalado (VcXsrv, Xming, etc.) para visualizar as janelas GTK
- O projeto está em desenvolvimento contínuo, com melhorias sendo adicionadas regularmente

## 👨‍💻 Autor

Pedro Ruan - Estudante de ITP 2025-2
