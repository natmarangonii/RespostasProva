#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    int quantidade;
    float preco;
} Produto;

Produto produto[20];
int numproduto = 0;

void cadastroProduto();
void listarProduto();
void comprarProduto();
void finalizaFuncao();

int main() {
    int opcao;
    do {
        printf("\n---- SuperMais ----\n");
        printf("1- Cadastrar produto\n");
        printf("2- Listar produtos\n");
        printf("3- Comprar\n");
        printf("0- Sair\n");
        scanf("%d", &opcao);
        
        getchar();
        
        switch (opcao) {
            case 1:
            cadastroProduto();
            break;
            
            case 2:
            listarProduto();
            break;
            
            case 3:
            comprarProduto();
            break;
            
            case 0:
            system("clear");
            printf("Obrigado! :)\n");
            break;
            
            default:
            system("clear");
            printf("Opção inválida!\n");
            finalizaFuncao();
            break;
        }
    } while (opcao != 0);
    return 0;
}

void cadastroProduto() {
    system("clear");
    if (numproduto < 20) {
        printf("---- Cadastro do Produto ----\n");
        printf("Nome: ");
        scanf(" %[^\n]", produto[numproduto].nome);
        
        printf("Preço: ");
        scanf("%f", &produto[numproduto].preco);
        
        printf("Quantidade: ");
        scanf("%d", &produto[numproduto].quantidade);
        getchar(); 
        
        numproduto++;
        
        printf("Produto cadastrado com sucesso!\n");
    } else {
        printf("Limite de produtos atingido!\n");
    }
    finalizaFuncao();
}

void listarProduto() {
    system("clear");
    printf("---- Lista de Produtos ----\n");
    if (numproduto == 0) {
        printf("Nenhum produto cadastrado.\n");
    } else {
        for (int i = 0; i < numproduto; i++) {
            printf("Produto: %s\n", produto[i].nome);
            printf("Preço: %.2f\n", produto[i].preco);
            printf("Quantidade: %d\n", produto[i].quantidade);
            printf("-------------------------\n");
        }
    }
    finalizaFuncao();
}

void comprarProduto() {
    int quantCompra;
    float valorCompra;
    int produtoEscolhido;
    
    system("clear");
    printf("---- Comprar Produto ----\n");
    if (numproduto == 0) {
        printf("Nenhum produto cadastrado.\n");
    } else {
        printf("Produtos disponíveis:\n");
        for (int i = 0; i < numproduto; i++) {
            printf("%d - %s\n", i + 1, produto[i].nome);
        }
        printf("Escolha o produto que deseja comprar: ");
        scanf("%d", &produtoEscolhido);
        getchar();
        produtoEscolhido--;
        if (produtoEscolhido >= 0 && produtoEscolhido < numproduto) {
            printf("Quantidade disponivel: %d\n", produto[produtoEscolhido].quantidade);
            printf("Quantidade que deseja comprar: ");
            scanf("%d", &quantCompra);
            getchar();
            valorCompra = quantCompra * produto[produtoEscolhido].preco;
            if (quantCompra <= produto[produtoEscolhido].quantidade) {
                system("clear");
                printf("Compra aprovada!\n");
                printf("O valor da sua compra é de: %.2f\n", valorCompra);
                produto[produtoEscolhido].quantidade -= quantCompra;
                printf("Quantidade restante: %d\n", produto[produtoEscolhido].quantidade);
            } else {
                system("clear");
                printf("Compra não autorizada! Quantidade indisponivel.\n");
            }
        } else {
            system("clear");
            printf("Produto inválido!\n");
        }
    }
    finalizaFuncao();
}

void finalizaFuncao() {
    printf("Enter para continuar...");
    getchar();
    system("clear");
}
            
            
            
            
            