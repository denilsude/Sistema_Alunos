#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100

// Variáveis globais
char nomes[MAX_ALUNOS][50]; // Array para armazenar os nomes dos alunos
float notasN1[MAX_ALUNOS]; // Array para armazenar as notas N1 dos alunos
float notasN2[MAX_ALUNOS]; // Array para armazenar as notas N2 dos alunos
int numAlunos = 0; // Variável para rastrear o número de alunos cadastrados

// Função para limpar o buffer de entrada do teclado
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int opcao;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Cadastrar um aluno\n");
        printf("2. Cadastrar N alunos\n");
        printf("3. Listar alunos cadastrados\n");
        printf("4. Excluir aluno\n");
        printf("5. Inserir notas de um aluno\n");
        printf("6. Alterar notas de um aluno\n");
        printf("7. Listar alunos com notas e media\n");
        printf("8. Sair do programa\n");

        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o buffer de entrada após a leitura da opção

        switch (opcao) {
            case 1:
                // Cadastrar um único aluno
                if (numAlunos < MAX_ALUNOS) {
                    printf("Informe o nome do aluno: ");
                    fgets(nomes[numAlunos], sizeof(nomes[numAlunos]), stdin);
                    strtok(nomes[numAlunos], "\n"); // Remove a quebra de linha do nome
                    printf("Informe a nota N1 do aluno: ");
                    scanf("%f", &notasN1[numAlunos]);
                    printf("Informe a nota N2 do aluno: ");
                    scanf("%f", &notasN2[numAlunos]);
                    numAlunos++;
                    printf("Aluno cadastrado com sucesso!\n");
                } else {
                    printf("Limite de alunos atingido. Impossível cadastrar mais alunos.\n");
                }
                break;
            case 2:
                // Cadastrar N alunos simultaneamente
                printf("Quantos alunos deseja cadastrar? ");
                int quantidade;
                scanf("%d", &quantidade);
                for (int i = 0; i < quantidade; i++) {
                    if (numAlunos < MAX_ALUNOS) {
                        printf("Informe o nome do aluno %d: ", i + 1);
                        fgets(nomes[numAlunos], sizeof(nomes[numAlunos]), stdin);
                        strtok(nomes[numAlunos], "\n"); // Remove a quebra de linha do nome
                        printf("Informe a nota N1 do aluno %d: ", i + 1);
                        scanf("%f", &notasN1[numAlunos]);
                        printf("Informe a nota N2 do aluno %d: ", i + 1);
                        scanf("%f", &notasN2[numAlunos]);
                        numAlunos++;
                        printf("Aluno cadastrado com sucesso!\n");
                    } else {
                        printf("Limite de alunos atingido. Impossível cadastrar mais alunos.\n");
                        break;
                    }
                }
                break;
            case 3:
                // Listar alunos cadastrados
                printf("Alunos cadastrados:\n");
                for (int i = 0; i < numAlunos; i++) {
                    printf("Nome: %s, Nota N1: %.2f, Nota N2: %.2f\n", nomes[i], notasN1[i], notasN2[i]);
                }
                break;
            case 4:
                // Excluir aluno
                printf("Informe o índice do aluno que deseja excluir (começando de 1): ");
                int indiceExcluir;
                scanf("%d", &indiceExcluir);
                if (indiceExcluir > 0 && indiceExcluir <= numAlunos) {
                    for (int i = indiceExcluir - 1; i < numAlunos - 1; i++) {
                        strcpy(nomes[i], nomes[i + 1]);
                        notasN1[i] = notasN1[i + 1];
                        notasN2[i] = notasN2[i + 1];
                    }
                    numAlunos--;
                    printf("Aluno excluído com sucesso!\n");
                } else {
                    printf("Índice inválido!\n");
                }
                break;
            case 5:
                // Inserir notas de um aluno
                printf("Informe o índice do aluno para inserir as notas: ");
                int indiceInserir;
                scanf("%d", &indiceInserir);
                if (indiceInserir > 0 && indiceInserir <= numAlunos) {
                    printf("Informe a nova nota N1 do aluno: ");
                    scanf("%f", &notasN1[indiceInserir - 1]);
                    printf("Informe a nova nota N2 do aluno: ");
                    scanf("%f", &notasN2[indiceInserir - 1]);
                    printf("Notas atualizadas com sucesso!\n");
                } else {
                    printf("Indice invalido!\n");
                }
                break;
            case 6:
                // Alterar notas de um aluno
                printf("Informe o índice do aluno para alterar as notas: ");
                int indiceAlterar;
                scanf("%d", &indiceAlterar);
                if (indiceAlterar > 0 && indiceAlterar <= numAlunos) {
                    printf("Informe a nova nota N1 do aluno: ");
                    scanf("%f", &notasN1[indiceAlterar - 1]);
                    printf("Informe a nova nota N2 do aluno: ");
                    scanf("%f", &notasN2[indiceAlterar - 1]);
                    printf("Notas atualizadas com sucesso!\n");
                } else {
                    printf("Índice inválido!\n");
                }
                break;
            case 7:
                // Listar alunos com notas e média
                printf("Alunos cadastrados com notas e média:\n");
                for (int i = 0; i < numAlunos; i++) {
                    float media = (notasN1[i] + notasN2[i]) / 2.0;
                    printf("Nome: %s, Nota N1: %.2f, Nota N2: %.2f, Média: %.2f\n", nomes[i], notasN1[i], notasN2[i], media);
                }
                break;
            case 8:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}
