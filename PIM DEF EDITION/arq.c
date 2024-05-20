#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome[100], empresa[100], cnpj[20], telefone[20], endereco[200], email[100], cidade[50];
    
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite o nome da empresa: ");
    fgets(empresa, sizeof(empresa), stdin);

    printf("Digite o CNPJ: ");
    fgets(cnpj, sizeof(cnpj), stdin);

    printf("Digite o telefone: ");
    fgets(telefone, sizeof(telefone), stdin);

    printf("Digite o endereço: ");
    fgets(endereco, sizeof(endereco), stdin);

    printf("Digite o email: ");
    fgets(email, sizeof(email), stdin);

    printf("Digite a cidade: ");
    fgets(cidade, sizeof(cidade), stdin);

    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "Nome: %s", nome);
    fprintf(arquivo, "Empresa: %s", empresa);
    fprintf(arquivo, "CNPJ: %s", cnpj);
    fprintf(arquivo, "Telefone: %s", telefone);
    fprintf(arquivo, "Endereço: %s", endereco);
    fprintf(arquivo, "Email: %s", email);
    fprintf(arquivo, "Cidade: %s", cidade);

    fclose(arquivo);

    printf("Dados salvos com sucesso em dados.txt\n");

    return 0;
}