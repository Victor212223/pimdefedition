#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// Função para criar a pasta
void criarPasta(const char *nomePasta) {
    #ifdef _WIN32
        mkdir(nomePasta);
    #else
        mkdir(nomePasta, 0777); // Permissões de leitura, escrita e execução para o proprietário, grupo e outros
    #endif
}

// Função para criar e escrever no arquivo
void criarArquivo(const char *nomePasta, const char *nomeArquivo, const char *conteudo) {
    char caminho[100]; // Ajuste o tamanho conforme necessário
    snprintf(caminho, sizeof(caminho), "%s/%s", nomePasta, nomeArquivo);
    FILE *arquivo = fopen(caminho, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }
    fprintf(arquivo, "%s", conteudo);
    fclose(arquivo);
}

int main() {
    char nome[50];
    char email[50];
    char telefone[15];
    char endereco[100];

    printf("=== Formulário de Cadastro ===\n");
    printf("Nome: ");
    scanf("%s", nome);
    printf("Email: ");
    scanf("%s", email);
    printf("Telefone: ");
    scanf("%s", telefone);
    printf("Endereço: ");
    scanf("%s", endereco);

    // Criando a pasta com o nome do usuário
    criarPasta(nome);

    // Criando e escrevendo no arquivo dentro da pasta
    char conteudoArquivo[200]; // Ajuste o tamanho conforme necessário
    snprintf(conteudoArquivo, sizeof(conteudoArquivo), "Nome: %s\nEmail: %s\nTelefone: %s\nEndereço: %s\n", nome, email, telefone, endereco);
    criarArquivo(nome, "dados.txt", conteudoArquivo);

    printf("Cadastro concluído com sucesso!\n");

    return 0;
}
