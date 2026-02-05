#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//Criando as estruturas

struct Livro
{
    int cod_livro;
    char titulo[100];
    char autor[80];
    char editora[60];
    int ano;
    int num_exemplares; //quantidade de livros
    bool status; //disponível(TRUE) ou emprestado(FALSE)
    
};

struct Usuario
{
    int matricula;
    char nome_completo[100];
    char curso[50];
    char telefone[15]; // (ddd)9xxxxxxxx
    int data_cadastro[3]; //dia, mês, ano
    
};

struct Emprestimo
{
    int cod_emprestimo;
    int matricula;
    int cod_livro;
    int data_emprestimo[3]; // dia, mês, ano
    int data_devolucao[3]; // 7 dias após o empréstimo
    bool status; //ativo(TRUE) ou devolvido(FALSE)
    
};

// Funções de inicialização de estruturas (inicia com 0 e string vazia)
void inicializar_acervo(struct Livro acervo[], int tam_acervo)
    {
        for (int i = 0; i < tam_acervo; i++)
        {
            acervo[i].cod_livro = 0;
            strcpy(acervo[i].autor,"");
            strcpy(acervo[i].titulo,"");
            strcpy(acervo[i].editora,"");
            acervo[i].ano = 0;
            acervo[i].num_exemplares = 0;
            acervo[i].status = true;
        }
    }

void inicializar_usuario(struct Usuario clientes[],int tam_clientes)
    {
        for (int i = 0; i < tam_clientes; i++)
        {
            clientes[i].data_cadastro[0] = 0;
            clientes[i].data_cadastro[1] = 0;
            clientes[i].data_cadastro[2] = 0;
            strcpy(clientes[i].nome_completo,"");
            strcpy(clientes[i].curso,"");
            strcpy(clientes[i].telefone,"");
            clientes[i].matricula = 0;
        }
    }

void inicializar_emprestimo(struct Emprestimo emprestimos[],int tam_emprestimos)
    {
        for (int i = 0; i < tam_emprestimos; i++)
        {
            emprestimos[i].cod_emprestimo = 0;
            emprestimos[i].cod_livro = 0;
            emprestimos[i].matricula = 0;
            emprestimos[i].data_emprestimo[0] = 0;
            emprestimos[i].data_emprestimo[1] = 0;
            emprestimos[i].data_emprestimo[2] = 0;
            emprestimos[i].data_devolucao[0] = 0;
            emprestimos[i].data_devolucao[1] = 0;
            emprestimos[i].data_devolucao[2] = 0;
            emprestimos[i].status = false;
        }  
    }

// Funções principais

// verifica se o texto extrapola o tamanho do vetor
int extrapolou_o_buffer(char texto[])
{
    if (strchr(texto,'\n') == NULL)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF){};
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int eh_numero_positivo(int n)
{
    if( (n > 0) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

// obtém a data atual do sistema
struct tm obter_data_atual()
{
    // Obtendo o tempo base em segundos
    time_t tempo_base;
    time(&tempo_base);

    // Transformando em estrutura de tempo
    struct tm *tempo_atual;
    tempo_atual = localtime(&tempo_base);

    // Criando uma estrutura cópia para retorno
    struct tm data_retorno = *tempo_atual;

    return data_retorno;
}

void cadastrar_livros(struct Livro acervo[],int tam_acervo)
{
    int i, n, cod_livro, avancar;
    cod_livro = 0;
    n = 0;
    i = 0;
    printf("Digite o codigo do livro.\n");
    scanf("%d",&cod_livro);
    limpar_buffer();

    // Verificando se o livro já está no acervo (n = 1)
    if(eh_numero_positivo(cod_livro))
    {
        for (int j = 0; j < tam_acervo; j++)
        {
            if (cod_livro == acervo[j].cod_livro)
            {
                n++;
                break;
            }
        }
    }
    
    // Se o livro não está no acervo e o codigo do livro é um numero positivo, o cadastro é feito
    if ( (n == 0)&&(eh_numero_positivo(cod_livro)) )
    {
        for(i=0; i<tam_acervo; i++)
        {
            // verifica se a posição do vetor está disponível
            if(acervo[i].cod_livro == 0)
            {
                acervo[i].cod_livro = cod_livro;
                
                // verifica a entrada de dados
                do
                {
                    avancar = 0;
                    printf("Digite o titulo do livro.\n");
                    fgets(acervo[i].titulo,100,stdin);
                    if (extrapolou_o_buffer(acervo[i].titulo))
                    {
                        printf("Limite de caracteres ultrapassado!\n");
                    }
                    else
                    {
                        avancar++;
                    }

                } while (avancar == 0);

                do
                {
                    avancar = 0;
                    printf("Digite o autor do livro.\n");
                    fgets(acervo[i].autor,80,stdin);
                    if (extrapolou_o_buffer(acervo[i].autor))
                    {
                        printf("Limite de caracteres ultrapassado!\n");
                    }
                    else
                    {
                        avancar++;
                    }
                } while (avancar == 0);
                    
                do
                {
                    avancar = 0;
                    printf("Digite a editora do livro.\n");
                    fgets(acervo[i].editora,60,stdin);
                    if (extrapolou_o_buffer(acervo[i].editora))
                    {
                        printf("Limite de caracteres ultrapassado!\n");
                    }
                    else
                    {
                        avancar++;
                    }
                } while(avancar == 0);

                do
                {
                    avancar = 0;
                    printf("Digite o ano do livro.\n");
                    scanf("%d",&acervo[i].ano);
                    limpar_buffer();
                    if (!eh_numero_positivo(acervo[i].ano))
                    {
                        printf("Digite apenas numeros!\n");
                    }
                    else
                    {
                        avancar++;
                    }
                } while(avancar == 0);
                
                do
                {
                    avancar = 0;
                    printf("Digite o numero de exemplares do livro.\n");
                    scanf("%d",&acervo[i].num_exemplares);
                    limpar_buffer();
                    if (!eh_numero_positivo(acervo[i].num_exemplares))
                    {
                        printf("Digite apenas numeros!\n");
                    }
                    else
                    {
                        avancar++;
                    }
                } while(avancar == 0);

                printf("Livro cadastrado com sucesso!\n");

                break;
            }
            
        }
    }
    else
    {
        if (n == 1)
        {
            printf("O livro ja esta cadastrado!\n");
        }

        if (!eh_numero_positivo(cod_livro))
        {
            printf("Codigo invalido!\n");
        }
        
        
    }

    if(i == tam_acervo)
    {
        printf("O acervo esta cheio!\n");
    }
    
    
}

void pesquisar_livros(struct Livro acervo[], int tam_acervo)
{
    int cod_livro, opcao;
    char pesquisa[100];
    opcao = 0;
    cod_livro = 0;
    
    do
    {
        printf("\nSelecione como voce quer pesquisar:\n");
        printf("1 - Codigo do livro\n");
        printf("2 - Titulo ou autor do livro\n");
        printf("3 - Sair\n");
        scanf("%d",&opcao);
        limpar_buffer();

        if (opcao == 1)
        {
            printf("Digite o codigo do livro\n");
            scanf("%d",&cod_livro);
            limpar_buffer();
            int contador = 0;
            
            // se o código do livro for válido, então a pesquisa é feita
            if (eh_numero_positivo(cod_livro))
            {
                for (int i = 0; i < tam_acervo; i++)
                {
                    if (cod_livro == acervo[i].cod_livro)
                    {
                        printf("\nO livro foi encontrado.\n");
                        printf("Codigo: %d\n",acervo[i].cod_livro);
                        printf("Titulo: %s\n",acervo[i].titulo);
                        printf("Autor: %s\n",acervo[i].autor);
                        printf("Editora: %s\n",acervo[i].editora);
                        printf("Ano: %d\n",acervo[i].ano);
                        contador++;
                        break;
                    }
                    
                }

                printf("\nQuantidade de livros encontrados: %d\n",contador);
            }
            else
            {
                printf("\nCodigo invalido\n");
            }
        }

        if (opcao == 2)
        {
            printf("Digite o titulo ou o autor\n");
            fgets(pesquisa, 100, stdin);
            int contador = 0;
            
            // se o texto extrapolar o tamanho do vetor, a busca é feita
            if(!extrapolou_o_buffer(pesquisa))
            {
                for (int i = 0; i < tam_acervo; i++)
                {
                    if ( (strcmp(pesquisa,acervo[i].titulo) == 0)||(strcmp(pesquisa,acervo[i].autor) == 0) )
                    {
                        printf("\nO livro foi encontrado.\n");
                        printf("Codigo: %d\n",acervo[i].cod_livro);
                        printf("Titulo: %s\n",acervo[i].titulo);
                        printf("Autor: %s\n",acervo[i].autor);
                        printf("Editora: %s\n",acervo[i].editora);
                        printf("Ano: %d\n",acervo[i].ano);
                        contador++;
                    }
                    
                }
                
                printf("\nQuantidade de livros encontrados: %d\n",contador);
            }
            else
            {
                printf("Limite de caracteres ultrapassado!\n");
            }
        }

        
    } while (opcao != 3);
}

void cadastrar_usuarios(struct Usuario clientes[],int tam_clientes)
{
    
    int i,n, cod_matricula, avancar;
    cod_matricula = 0;
    n = 0;
    i = 0;
    printf("Digite a matricula do usuario.\n");
    scanf("%d",&cod_matricula);
    limpar_buffer();

    // Verificando se o usuario é cadastrado (n = 1)
    if(eh_numero_positivo(cod_matricula))
    {
        for (int j = 0; j < tam_clientes; j++)
        {
            if (cod_matricula == clientes[j].matricula)
            {
                n++;
                break;
            }
        }
    }

    // Se o usuário não é cadastrado e a matrícula é um numero positivo, o cadastro é feito
    if ( (n == 0)&&(eh_numero_positivo(cod_matricula)) )
    {
        for(i=0; i<tam_clientes; i++)
        {
            
            if(clientes[i].matricula == 0)
            {
                clientes[i].matricula = cod_matricula;

                do
                {
                    avancar = 0;
                    printf("Digite o nome completo do usuario.\n");
                    fgets(clientes[i].nome_completo,100,stdin);
                    if (extrapolou_o_buffer(clientes[i].nome_completo))
                    {
                        printf("Limite de caracteres ultrapassado!\n");
                    }
                    else
                    {
                        avancar++;
                    }

                } while(avancar == 0);

                do
                {
                    avancar = 0;
                    printf("Digite o curso do usuario.\n");
                    fgets(clientes[i].curso,50,stdin);
                    if (extrapolou_o_buffer(clientes[i].curso))
                    {
                        printf("Limite de caracteres ultrapassado!\n");
                    }
                    else
                    {
                        avancar++;
                    }

                } while (avancar == 0);
                
                
                do
                {
                    avancar = 0;
                    printf("Digite o telefone do usuario. Exemplo: (11)963121263\n");
                    fgets(clientes[i].telefone,15,stdin);
                    if (extrapolou_o_buffer(clientes[i].telefone))
                    {
                        printf("Limite de caracteres ultrapassado!\n");
                    }
                    else
                    {
                        avancar++;
                    }

                } while (avancar == 0);
                
                // Pegando a data atual
                struct tm data_atual = obter_data_atual();
                clientes[i].data_cadastro[0] = data_atual.tm_mday;
                clientes[i].data_cadastro[1] = data_atual.tm_mon + 1; // janeiro é 0, então deve-se somar 1
                clientes[i].data_cadastro[2] = data_atual.tm_year + 1900; // tm_year = ano atual - 1900, por isso soma-se 1900

                printf("Usuario cadastrado com sucesso!\n");

                break;
            }
            
        }
    }
    else
    {
        if (n == 1)
        {
            printf("O usuario ja esta cadastrado!\n");
        }

        if (cod_matricula <= 0)
        {
            printf("Codigo invalido!\n");
        } 
        
    }
    
    if(i == tam_clientes)
    {
        printf("O cadastro de usuarios esta cheio!\n");
    }
    
    
}

void pesquisar_usuarios(struct Usuario clientes[], int tam_clientes)
{
    int cod_matricula, opcao;
    char nome_usuario[100];
    opcao = 0;
    cod_matricula = 0;
    
    do
    {
        printf("\nSelecione como você quer pesquisar:\n");
        printf("1 - Codigo de matricula\n");
        printf("2 - Nome do usuario\n");
        printf("3 - Sair\n");
        scanf("%d",&opcao);
        limpar_buffer();

        if (opcao == 1)
        {
            printf("Digite o codigo de matricula\n");
            scanf("%d",&cod_matricula);
            limpar_buffer();
            int contador = 0;
            
            if (eh_numero_positivo(cod_matricula))
            {
                for (int i = 0; i < tam_clientes; i++)
                {
                    if (cod_matricula == clientes[i].matricula)
                    {
                        printf("\nO usuario foi encontrado.\n");
                        printf("Nome do usuario: %s\n",clientes[i].nome_completo);
                        printf("Matricula: %d\n",clientes[i].matricula);
                        printf("Curso: %s\n",clientes[i].curso);
                        printf("Telefone: %s\n",clientes[i].telefone);
                        contador++;
                        break;
                    }
                    
                }

                printf("\nQuantidade de usuarios encontrados: %d\n",contador);
            }
            else
            {
                printf("\nMatricula invalida!\n");
            }
        }

        if (opcao == 2)
        {
            printf("Digite o nome completo do usuario\n");
            fgets(nome_usuario, 100, stdin);
            int contador = 0;

            if(!extrapolou_o_buffer(nome_usuario))
            {
                for (int i = 0; i < tam_clientes; i++)
                {
                    if (strcmp(nome_usuario, clientes[i].nome_completo) == 0 )
                    {
                        printf("\nO usuario foi encontrado.\n");
                        printf("Nome do usuario: %s\n",clientes[i].nome_completo);
                        printf("Matricula: %d\n",clientes[i].matricula);
                        printf("Curso: %s\n",clientes[i].curso);
                        printf("Telefone: %s\n",clientes[i].telefone);
                        contador++;
                        break;
                    }
                    
                }
                
                printf("\nQuantidade de usuarios encontrados: %d\n",contador);

            }
            else
            {
                printf("Limite de caracteres ultrapassado!\n");
            }
        }

        
    } while (opcao != 3);
}

void realizar_emprestimo(struct Usuario clientes[], int tam_clientes, struct Livro acervo[], int tam_acervo, struct Emprestimo emprestimos[], int tam_emprestimos)
{
    
    int i, avancar, cod_livro, cod_matricula, n, pos_livro;
    bool disponibilidade, usuario_encontrado;
    n = 0;
    cod_livro = 0;
    cod_matricula = 0;
    pos_livro = -1;
    disponibilidade = true;
    usuario_encontrado = false;

    printf("Digite o codigo do livro.\n");
    scanf("%d",&cod_livro);
    limpar_buffer();
    printf("Digite a matricula do usuario.\n");
    scanf("%d",&cod_matricula);
    limpar_buffer();

    // Verificando se o livro está no acervo
    for (int j = 0; j < tam_acervo; j++)
    {
        if ( (cod_livro == acervo[j].cod_livro)&&(eh_numero_positivo(cod_livro)) )
        {
            pos_livro = j;
            disponibilidade = acervo[j].status;
        }
        
    }

    // Verificando se o usuario está cadastrado
    for (int j = 0; j < tam_clientes; j++)
    {
        if ( (cod_matricula == clientes[j].matricula)&&(eh_numero_positivo(cod_matricula)) )
        {
            usuario_encontrado = true;
        }
        
    }
    
    // Se o usuario tá cadastrado e o livro tá no acervo e disponível, o empréstimo é feito
    if( (pos_livro > -1)&&(disponibilidade)&&(usuario_encontrado) )
    {
        for(i=0; i<tam_emprestimos; i++)
        {
            
            if(emprestimos[i].cod_emprestimo == 0)
            {
                
                emprestimos[i].cod_livro = cod_livro;
                emprestimos[i].matricula = cod_matricula;

                do
                {
                    avancar = 0;
                    printf("Digite o codigo do emprestimo.\n");
                    scanf("%d",&emprestimos[i].cod_emprestimo);
                    limpar_buffer();

                    if (eh_numero_positivo(emprestimos[i].cod_emprestimo))
                    {
                        avancar++;
                    }
                    else
                    {
                        printf("Digite apenas numeros!\n");
                    }
                    
                } while (avancar == 0);
                
                

                // Pegando a data atual
                struct tm data_atual = obter_data_atual();
                emprestimos[i].data_emprestimo[0] = data_atual.tm_mday;
                emprestimos[i].data_emprestimo[1] = data_atual.tm_mon + 1; // janeiro é 0, então deve-se somar 1
                emprestimos[i].data_emprestimo[2] = data_atual.tm_year + 1900; // tm_year = ano atual - 1900, por isso soma-se 1900

                // Calculando a data de devolução
                data_atual.tm_mday += 7;
                mktime(&data_atual);
                emprestimos[i].data_devolucao[0] = data_atual.tm_mday;
                emprestimos[i].data_devolucao[1] = data_atual.tm_mon + 1; // janeiro é 0, então deve-se somar 1
                emprestimos[i].data_devolucao[2] = data_atual.tm_year + 1900; // tm_year = ano atual - 1900, por isso soma-se 1900
                
                // Indicando que o emprestimo está ativo
                emprestimos[i].status = true;
                printf("Emprestimo realizado com sucesso!\n");
                n++;

                //Alterando a disponibilidade do livro
                acervo[pos_livro].num_exemplares = acervo[pos_livro].num_exemplares - n;
        
                if (acervo[pos_livro].num_exemplares == 0)
                {
                    acervo[pos_livro].status = false;
                }

                break;
            }  
        }
        
        if(i == tam_emprestimos)
        {
            printf("O banco de dados de emprestimos esta cheio!\n");
        }


    }
    else
    {
        if (pos_livro == -1)
        {
            printf("O livro nao esta no acervo!\n");
        }

        if (!disponibilidade)
        {
            printf("O livro nao esta disponivel para emprestimo!\n");
        }

        if (!usuario_encontrado)
        {
            printf("O usuario nao foi encontrado!\n");
        }
        
    }
               
}

void realizar_devolucao(struct Livro acervo[], int tam_acervo, struct Emprestimo emprestimos[], int tam_emprestimos)
{
    
    int n, cod_livro, cod_emprestimo, pos_livro, pos_emprestimo;
    
    n = 0;
    cod_livro = 0;
    cod_emprestimo = 0;
    pos_emprestimo = -1;
    
    printf("Digite o codigo do livro.\n");
    scanf("%d",&cod_livro);
    limpar_buffer();

    printf("Digite o codigo do emprestimo.\n");
    scanf("%d",&cod_emprestimo);
    limpar_buffer();

    // validando os códigos e verificando se o empréstimo existe e está ativo
    if ( (eh_numero_positivo(cod_livro))&&(eh_numero_positivo(cod_emprestimo)) )
    {
        for (int i = 0; i < tam_emprestimos; i++)
        {
            if ( (cod_emprestimo == emprestimos[i].cod_emprestimo)&&(emprestimos[i].status == true) )
            {
                pos_emprestimo = i;
                for (int j = 0; j < tam_acervo; j++)
                {
                    if (cod_livro == acervo[j].cod_livro)
                    {
                        pos_livro = j;
                        break;
                    }
                        
                }
                    
                break;
            }
                
        }
    }
    
    // Se o emprestimo foi encontrado e está ativo, a devolução é feita
    if (pos_emprestimo > -1)
    {
        emprestimos[pos_emprestimo].status = false;
        printf("Devolucao realizada com sucesso!\n");
        n++;
        acervo[pos_livro].num_exemplares = acervo[pos_livro].num_exemplares + n;
        acervo[pos_livro].status = true;
        printf("O livro esta disponivel para emprestimo!\n");

        // Pegando a data atual
        struct tm data_atual = obter_data_atual();
        data_atual.tm_mon++; // janeiro é 0, então deve-se somar 1
        data_atual.tm_year += 1900; // tm_year = ano atual - 1900, por isso soma-se 1900

        // Verificando se o usuario devolveu o livro dentro do prazo
        if (data_atual.tm_year <= emprestimos[pos_emprestimo].data_devolucao[2])
        {
            if (data_atual.tm_mon <= emprestimos[pos_emprestimo].data_devolucao[1])
            {
                if (data_atual.tm_mday <= emprestimos[pos_emprestimo].data_devolucao[0])
                {
                    printf("Devolucao feita dentro do tempo limite!\n");
                }
                else
                {
                    printf("Devolucao feita fora do tempo limite. Aplicar multa!\n");
                }
            
            }
            else
            {
                printf("Devolucao feita fora do tempo limite. Aplicar multa!\n");
            }
        
        }
        else
        {
            printf("Devolucao feita fora do tempo limite. Aplicar multa!\n");
        }

    }
    else
    {
        printf("O emprestimo nao foi encontrado!\n");
    }
                                
}

void listar_emprestimos_ativos(struct Emprestimo emprestimos[], int tam_emprestimos)
{
    int n = 0;
    for (int i = 0; i < tam_emprestimos; i++)
    {
        if (emprestimos[i].status == true)
        {
            printf("Codigo do emprestimo: %d\n",emprestimos[i].cod_emprestimo);
            printf("Codigo do livro: %d\n",emprestimos[i].cod_livro);
            printf("Matricula do usuario: %d\n",emprestimos[i].matricula);
            printf("Data de emprestimo: %d/%d/%d\n",emprestimos[i].data_emprestimo[0],emprestimos[i].data_emprestimo[1],emprestimos[i].data_emprestimo[2]);
            printf("Data de devolucao: %d/%d/%d\n",emprestimos[i].data_devolucao[0], emprestimos[i].data_devolucao[1], emprestimos[i].data_devolucao[2]);
            printf("\n-------------------------------------\n");
            n++;
        }
        
    }

    if (n == 0)
    {
        printf("Nao existem emprestimos ativos!\n");
    }
    else
    {
        printf("O total de emprestimos ativos eh: %d\n",n);
    }
    
    
}

// Funções para criar, salvar e carregar arquivos

void criar_livros_txt()
{
    FILE* arquivo = fopen("../livros.txt", "a");
    FILE* backup = fopen("../livros_backup.txt", "a");
    if ( (arquivo == NULL)||(backup == NULL) )
    {
        printf("Erro ao criar arquivo!\n");
    }
    fclose(arquivo);
    fclose(backup);
}

void criar_usuarios_txt()
{
    FILE* arquivo = fopen("../usuarios.txt", "a");
    FILE* backup = fopen("../usuarios_backup.txt", "a");
    if ( (arquivo == NULL)||(backup == NULL) )
    {
        printf("Erro ao criar arquivo!\n");
    }
    fclose(arquivo);
    fclose(backup);
}

void criar_emprestimos_txt()
{
    FILE* arquivo = fopen("../emprestimos.txt", "a");
    FILE* backup = fopen("../emprestimos_backup.txt", "a");
    if ( (arquivo == NULL)||(backup == NULL) )
    {
        printf("Erro ao criar arquivo!\n");
    }
    fclose(arquivo);
    fclose(backup);
}

void salvar_livros(struct Livro acervo[],int tam_acervo)
{
    FILE *arquivo = fopen("../livros.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de livros!\n");
        return;
    }
    for (int i = 0; i < tam_acervo; i++)
    {
        fprintf(arquivo,"%d;%s;%s;%d;%s;%d;%d\n",
            acervo[i].cod_livro,
            acervo[i].titulo,
            acervo[i].autor,
            acervo[i].ano,
            acervo[i].editora,
            acervo[i].num_exemplares,
            acervo[i].status);
    }
    
    fclose(arquivo);
}

void carregar_livros(struct Livro acervo[],int tam_acervo)
{
    FILE *arquivo = fopen("../livros.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de livros!\n");
        return;
    }
    int temp_status;
    for (int i = 0; i < tam_acervo; i++)
    {
        fscanf(arquivo,"%d;%100[^;];%80[^;];%d;%60[^;];%d;%d\n",
            &acervo[i].cod_livro,
            acervo[i].titulo,
            acervo[i].autor,
            &acervo[i].ano,
            acervo[i].editora,
            &acervo[i].num_exemplares,
            &temp_status);
        
        acervo[i].status = (bool)temp_status;
    }
    
    fclose(arquivo);
}

void salvar_usuarios(struct Usuario clientes[],int tam_clientes)
{
    FILE *arquivo = fopen("../usuarios.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de usuarios!\n");
        return;
    }
    for (int i = 0; i < tam_clientes; i++)
    {
        fprintf(arquivo,"%d;%s;%s;%s;%d;%d;%d\n",
            clientes[i].matricula,
            clientes[i].nome_completo,
            clientes[i].curso,
            clientes[i].telefone,
            clientes[i].data_cadastro[0],
            clientes[i].data_cadastro[1],
            clientes[i].data_cadastro[2]);
    }
    
    fclose(arquivo);
}

void carregar_usuarios(struct Usuario clientes[],int tam_clientes)
{
    FILE *arquivo = fopen("../usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de usuarios!\n");
        return;
    }

    for (int i = 0; i < tam_clientes; i++)
    {
        fscanf(arquivo,"%d;%100[^;];%50[^;];%15[^;];%d;%d;%d\n",
            &clientes[i].matricula,
            clientes[i].nome_completo,
            clientes[i].curso,
            clientes[i].telefone,
            &clientes[i].data_cadastro[0],
            &clientes[i].data_cadastro[1],
            &clientes[i].data_cadastro[2]);
    }
    
    fclose(arquivo);
}

void salvar_emprestimos(struct Emprestimo emprestimos[],int tam_emprestimos)
{
    FILE *arquivo = fopen("../emprestimos.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de emprestimos!\n");
        return;
    }
    for (int i = 0; i < tam_emprestimos; i++)
    {
        fprintf(arquivo,"%d;%d;%d;%d;%d;%d;%d;%d;%d;%d\n",
            emprestimos[i].cod_emprestimo,
            emprestimos[i].cod_livro,
            emprestimos[i].matricula,
            emprestimos[i].data_emprestimo[0],
            emprestimos[i].data_emprestimo[1],
            emprestimos[i].data_emprestimo[2],
            emprestimos[i].data_devolucao[0],
            emprestimos[i].data_devolucao[1],
            emprestimos[i].data_devolucao[2],
            emprestimos[i].status);
    }
    
    fclose(arquivo);
}

void carregar_emprestimos(struct Emprestimo emprestimos[],int tam_emprestimos)
{
    FILE *arquivo = fopen("../emprestimos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de emprestimos!\n");
        return;
    }
    int temp_status;
    for (int i = 0; i < tam_emprestimos; i++)
    {
        fscanf(arquivo,"%d;%d;%d;%d;%d;%d;%d;%d;%d;%d\n",
            &emprestimos[i].cod_emprestimo,
            &emprestimos[i].cod_livro,
            &emprestimos[i].matricula,
            &emprestimos[i].data_emprestimo[0],
            &emprestimos[i].data_emprestimo[1],
            &emprestimos[i].data_emprestimo[2],
            &emprestimos[i].data_devolucao[0],
            &emprestimos[i].data_devolucao[1],
            &emprestimos[i].data_devolucao[2],
            &temp_status);
        
        emprestimos[i].status = (bool)temp_status;
    }
    
    fclose(arquivo);
}

void criar_backup_livros ()
{ 
    FILE *arquivo = fopen("../livros.txt", "r"); 
    FILE *backup = fopen("../livros_backup.txt", "w"); 

    if (arquivo == NULL || backup == NULL) { 
        printf("Erro ao copiar arquivo!\n");
        return;
    }

    int c;
    while ((c = fgetc(arquivo)) != EOF) {
        fputc(c, backup);
    }

    fclose(arquivo);
    fclose(backup);
}

void criar_backup_usuarios ()
{ 
    FILE *arquivo = fopen("../usuarios.txt", "r"); 
    FILE *backup = fopen("../usuarios_backup.txt", "w"); 

    if (arquivo == NULL || backup == NULL) { 
        printf("Erro ao copiar arquivo!\n");
        return;
    }

    int c;
    while ((c = fgetc(arquivo)) != EOF) {
        fputc(c, backup);
    }

    fclose(arquivo);
    fclose(backup);
}

void criar_backup_emprestimos ()
{ 
    FILE *arquivo = fopen("../emprestimos.txt", "r"); 
    FILE *backup = fopen("../emprestimos_backup.txt", "w"); 

    if (arquivo == NULL || backup == NULL) { 
        printf("Erro ao copiar arquivo!\n");
        return;
    }

    int c;
    while ((c = fgetc(arquivo)) != EOF) {
        fputc(c, backup);
    }

    fclose(arquivo);
    fclose(backup);
}

// Constantes
const int tam_acervo = 2;
const int tam_clientes = 3;
const int tam_emprestimos = 2;

// Programa principal
int main ()
{
    int opcao = 0;

    struct Livro acervo[tam_acervo];
    struct Usuario clientes[tam_clientes];
    struct Emprestimo emprestimos[tam_emprestimos];

    // Criando os arquivos
    
    criar_livros_txt();
    criar_usuarios_txt();
    criar_emprestimos_txt();

    // Inicializando as estruturas

    inicializar_acervo(acervo,tam_acervo);
    inicializar_usuario(clientes,tam_clientes);
    inicializar_emprestimo(emprestimos,tam_emprestimos);

    // Carregando arquivos
    
    carregar_livros(acervo,tam_acervo);
    carregar_usuarios(clientes,tam_clientes);
    carregar_emprestimos(emprestimos,tam_emprestimos);

    // Menu

    do
    {
        printf("\nSelecione uma opcao: \n");
        printf("1 - Cadastrar livro \n");
        printf("2 - Cadastrar usuario \n");
        printf("3 - Realizar emprestimo \n");
        printf("4 - Realizar devolucao \n");
        printf("5 - Pesquisar livro \n");
        printf("6 - Pesquisar usuario \n");
        printf("7 - Listar emprestimos ativos \n");
        printf("8 - Fechar programa \n");
        printf("=================================\n");
        scanf("%d",&opcao);
        limpar_buffer();

        switch (opcao)
        {
            case 1:
                cadastrar_livros(acervo, tam_acervo);
                salvar_livros(acervo,tam_acervo);
                break;

            case 2:
                cadastrar_usuarios(clientes, tam_clientes);
                salvar_usuarios(clientes,tam_clientes);
                break;

            case 3:
                realizar_emprestimo(clientes, tam_clientes, acervo, tam_acervo, emprestimos, tam_emprestimos);
                salvar_livros(acervo,tam_acervo);
                salvar_emprestimos(emprestimos,tam_emprestimos);
                break;

            case 4:
                realizar_devolucao(acervo, tam_acervo, emprestimos, tam_emprestimos);
                salvar_livros(acervo,tam_acervo);
                salvar_emprestimos(emprestimos,tam_emprestimos);
                break;

            case 5:
                pesquisar_livros(acervo, tam_acervo);
                break;

            case 6:
                pesquisar_usuarios(clientes, tam_clientes);
                break;

            case 7:
                listar_emprestimos_ativos(emprestimos, tam_emprestimos);
                break;

            case 8:
                printf("Programa encerrado!\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }        

    } while (opcao != 8);

    salvar_livros(acervo,tam_acervo);
    salvar_usuarios(clientes,tam_clientes);
    salvar_emprestimos(emprestimos,tam_emprestimos);
    criar_backup_livros();
    criar_backup_usuarios();
    criar_backup_emprestimos();

    return 0;
}