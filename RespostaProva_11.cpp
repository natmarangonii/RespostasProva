#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char banda[30];
    char genero[30];
    int ano;
    int quantidade;
    float preco;
    int id;
} CD;

CD cds[100];
int numCds = 0;

void cadastrarCd();
void venderCd();
void consultarCd();
void listarCds();
void finalizaFuncao();

int main() {
    int opcao;
    do {
        printf("---- Som & Arte ----\n");
        printf("1- Cadastrar CD\n");
        printf("2- Vender CD\n");
        printf("3- Consultar CD\n");
        printf("4- Listar CDS\n");
        printf("0- Sair\n");
        scanf("%d", &opcao);
        getchar();
        switch (opcao) {
            case 1:
            cadastrarCd();
            break;
            
            case 2:
            venderCd();
            break;
            
            case 3:
            consultarCd();
            break;
            
            case 4:
            listarCds();
            break;
            
            case 0:
            system("clear");
            printf("Obrigado! :)\n");
            break;
            
            default:
            system("clear");
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);
    return 0;
}

void finalizaFuncao() {
    printf("Enter para continuar...");
    getchar();
    system("clear");
}

void cadastrarCd() {
    system("clear");
    printf("---- Cadastrar CD ----\n");
    printf("ID do CD: ");
    scanf("%d", &cds[numCds].id);
    getchar(); 
    printf("Banda: ");
    scanf(" %[^\n]", cds[numCds].banda);
    printf("Ano: ");
    scanf("%d", &cds[numCds].ano);
    getchar();
    printf("Gênero: ");
    scanf(" %[^\n]", cds[numCds].genero);
    printf("Quantidade: ");
    scanf("%d", &cds[numCds].quantidade);
    printf("Preço: ");
    scanf("%f", &cds[numCds].preco);
    getchar(); 
    
    numCds++;
    
    finalizaFuncao();
}

void venderCd() {
    int id = 0;
    int quantidade;
    system("clear");
    printf("---- Vender CD ----\n");
    printf("ID do CD: ");
    scanf("%d", &id);
    getchar();
    int encontrado = 0;
    for (int i = 0; i < numCds; i++) {
        if (cds[i].id == id) {
            printf("Quantidade: ");
            scanf("%d", &quantidade);
            getchar();
            if (cds[i].quantidade >= quantidade) {
                cds[i].quantidade -= quantidade;
                printf("Venda realizada com sucesso!\n");
                printf("Valor total da compra: %.2f\n", quantidade * cds[i].preco);
            } else {
                printf("Quantidade indisponivel no estoque!\n");
            }
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("CD não encontrado!\n");
    }
    finalizaFuncao();
}

void consultarCd() {
    int id;
    system("clear");
    printf("---- Consultar CD ----\n");
    printf("ID do CD: ");
    scanf("%d", &id);
    
    getchar();
    
    int encontrado = 0;
    for (int i = 0; i < numCds; i++) {
        if (cds[i].id == id) {
            printf("Banda: %s\n", cds[i].banda);
            printf("Ano: %d\n", cds[i].ano);
            printf("Gênero: %s\n", cds[i].genero);
            printf("Quantidade: %d\n", cds[i].quantidade);
            printf("Preço: %.2f\n", cds[i].preco);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("CD não encontrado!\n");
    }
    finalizaFuncao();
}

void listarCds() {
    system("clear");
    printf("---- Lista de CDs ----\n");
    if (numCds == 0) {
        printf("Nenhum CD cadastrado.\n");
    } 
    else {
        
        for (int i = 0; i < numCds; i++) {
            printf("ID: %d\n", cds[i].id);
            printf("Banda: %s\n", cds[i].banda);
            printf("Ano: %d\n", cds[i].ano);
            printf("Gênero: %s\n", cds[i].genero);
            printf("Quantidade: %d\n", cds[i].quantidade);
            printf("Preço: %.2f\n", cds[i].preco);
            printf("-------------------------\n");
        }
    }
    finalizaFuncao();
}