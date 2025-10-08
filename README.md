# ITP 2025-2 - Repositório de Estudos

Este repositório contém materiais, exercícios e projetos desenvolvidos durante o curso de Introdução às Técnicas de Programação (ITP) 2025-2.

## 🎥 Vídeo de Apresentação

**Duração:** 5-8 minutos  
**Link:** [https://youtu.be/ISW3GK7lOW8](https://youtu.be/ISW3GK7lOW8)

## 📂 Estrutura do Repositório

```
pedro-ruan-itp-2025-2/
├── listas/                    # Exercícios e listas resolvidas
│   ├── semana2_variáveis_tipos_operadores/      # 4 problemas ✅
│   ├── semana3_estruturas_condicionais/         # 8 problemas ✅
│   ├── semana4A_repetições_simples/             # 4 problemas ✅
│   ├── semana4B_repetições_simples/             # Questões 1-11 ✅
│   ├── semana5_funcoes/                          # 3 problemas ✅
│   └── semana6/                                  # 4 problemas (a fazer)
├── projeto/                   # Projeto principal
│   ├── src/                   # Código-fonte
│   ├── relatorio.pdf          # Relatório técnico (3-5 páginas)
│   └── README.md              # Documentação do projeto
├── .vscode/                   # Configurações do VS Code
└── README.md                  # Este arquivo
```

### Descrição das Pastas

- **listas/**: Exercícios organizados por semana/tema
  - Semana 2: Variáveis, tipos e operadores (4 problemas)
  - Semana 3: Estruturas condicionais (8 problemas)
  - Semana 4A: Repetições simples (4 problemas)
  - Semana 4B: Repetições simples (11 questões - 1-4 em .txt, 5-11 em .c)
  - Semana 5: Funções (3 problemas)
  - Semana 6: Exercícios avançados (4 problemas)
- **projeto/**: Projeto principal com interface GTK
  - Código-fonte modularizado
  - Relatório técnico em PDF
  - Documentação completa
- **.vscode/**: Configurações de IntelliSense para C/GTK

## 📋 Checklist de Entrega

### ✅ Estrutura do Arquivo
- [x] README.md principal presente
- [x] Estrutura de pastas organizada
- [x] Link do repositório: [https://github.com/ruannnrcn/pedro-ruan-itp-2025-2](https://github.com/ruannnrcn/pedro-ruan-itp-2025-2)

### 📁 Projeto
- [x] Código usa conceitos da Unidade 1
- [x] Possui 3+ funções além da main
- [ ] Relatório técnico em PDF (3-5 páginas) - **PENDENTE**
- [x] Projeto executa corretamente

### 📝 Listas Resolvidas
- [x] Semana 2: 4 problemas (variáveis, tipos, operadores)
- [x] Semana 3: 8 problemas (estruturas condicionais)
- [x] Semana 4A: 4 problemas (repetições simples)
- [x] Semana 4B: Questões 1-4 (.txt) e 5-11 (.c)
- [x] Semana 5: 3 problemas (funções)
- [ ] Semana 6: 4 problemas - **PENDENTE**

### 🎥 Vídeo
- [x] Duração: 5-8 minutos
- [x] Link acessível no README
- [x] Demonstra o projeto funcionando

## 📦 Como Gerar o ZIP de Entrega

Para criar o arquivo `sobrenome-nome-itp-u1-2025-2.zip`:

```bash
cd ~/projects
zip -r ruan-pedro-itp-u1-2025-2.zip pedro-ruan-itp-2025-2/ \
    -x "*.git*" "*/build/*" "*/bin/*" "*/__pycache__/*"
```

## 🚀 Como Usar

1. Clone o repositório:
   ```bash
   git clone https://github.com/ruannnrcn/pedro-ruan-itp-2025-2.git
   cd pedro-ruan-itp-2025-2
   ```

2. Para trabalhar com o projeto principal, acesse a pasta `projeto/` e siga as instruções no [README do projeto](./projeto/README.md).

3. Para os exercícios das listas, navegue até `listas/` e compile os arquivos individualmente.

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

**Última atualização:** Outubro/2025
