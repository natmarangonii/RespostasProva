#include <stdio.h>

struct aluno {
    char nome[50];
    int idade;
    float nota;
};

struct aluno alunos[3];
void listarAlunos();

int main() {
    for (int i = 0; i < 3; i++) {
        printf("Digite os dados do aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }

    listarAlunos();

    return 0;
}

void listarAlunos() {
    for (int i = 0; i < 3; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n", alunos[i].nota);
    }
}
