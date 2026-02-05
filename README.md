# 📚 Sistema de Gerenciamento de Biblioteca

Este é um projeto desenvolvido em **C** focado na gestão completa de uma biblioteca. O software permite o cadastro de livros e usuários, o controle de empréstimos e devoluções com cálculo de prazo, além de possuir um sistema de persistência de dados em arquivos `.txt` e geração automática de backups.

## 💻 Tecnologias
- **Linguagem:** C
- **Bibliotecas:** `stdio.h`, `stdlib.h`, `string.h`, `stdbool.h`, `time.h` 

## ⚙️ Instalação
1. Certifique-se de ter um compilador C instalado em sua máquina.
2. Baixe o arquivo `sistema_de_gerenciamento_de_biblioteca.c`.
3. Abra o terminal na pasta do arquivo e compile o projeto:
```bash
gcc Sistema_de_gerenciamento_de_biblioteca.c -o biblioteca
```
4. Execute o programa:
```bash
./biblioteca
```

## 🛠️ Funcionalidades

| Recurso | Descrição | Detalhes |
| :--- | :--- | :--- |
| **Gestão de Acervo** | Cadastro e pesquisa de livros por código, título ou autor. | Armazena título, autor, editora, ano e exemplares. |
| **Controle de Usuários** | Cadastro de leitores com matrícula e curso. | Captura automática da data de cadastro via sistema. |
| **Empréstimos/Devolução** | Gerencia a saída de livros e verifica prazos de entrega. | Calcula devolução para 7 dias após o empréstimo. |
| **Persistência de Dados** | Salva todas as informações em arquivos de texto. | Carrega dados automaticamente ao iniciar o programa. |
| **Sistema de Backup** | Cria cópias de segurança dos arquivos de dados. | Gera arquivos `_backup.txt` ao encerrar o programa. |

## 🕹️ Como usar
1. Ao iniciar, o programa carregará os dados existentes dos arquivos .txt.
2. Utilize o menu numérico (1-8) para navegar pelas opções.
3. Para Empréstimos, informe o código do livro e a matrícula do usuário. O sistema reduzirá o estoque automaticamente.
4. Na Devolução, o programa informará se o livro foi entregue no prazo ou se deve ser aplicada multa.
5. Selecione a opção 8 para encerrar; o sistema salvará as alterações e criará os backups de segurança.

## 💡 Exemplo de uso

Ao realizar uma devolução após o prazo:

Digite o código do livro: 101

Digite o código do emprestimo: 50

Devolucao realizada com sucesso! > Devolucao feita fora do tempo limite. Aplicar multa!

## 🚀 Status do Projeto

✅ Concluído

## 👤 Autor

Feito por **Matheus Felipe Claudino de Santana**  
GitHub: https://github.com/matheuscsantana-arch
