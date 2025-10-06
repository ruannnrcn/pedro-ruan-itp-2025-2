# Projeto ITP 2025-2

Este é o projeto principal do curso, desenvolvido em C com interface gráfica GTK.

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

- **src/app/**: Contém a lógica da aplicação, incluindo validações, cálculos e manipulação de dados.
- **src/view/**: Contém os arquivos de interface gráfica desenvolvidos com GTK 3.
- **.vscode/**: Arquivos de configuração para facilitar o desenvolvimento no VS Code, incluindo o IntelliSense para C/GTK.

## Como Compilar e Executar

### Exemplo GTK (Janela Simples)

Entre na pasta `src/view` e execute:

```bash
gcc test.gtk.c -o test-gtk `pkg-config --cflags --libs gtk+-3.0`
./test-gtk
```

### Projeto Completo

Para compilar o projeto completo (quando estiver implementado):

```bash
# A partir da raiz do projeto
gcc src/app/*.c src/view/*.c -o app `pkg-config --cflags --libs gtk+-3.0`
./app
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

## Observações

- Para garantir o funcionamento do IntelliSense, mantenha a pasta `.vscode` versionada.
- Se estiver usando WSL, certifique-se de ter um servidor X instalado (VcXsrv, Xming, etc.) para visualizar as janelas GTK.
