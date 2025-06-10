#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    int quantidade;
    float preco;
} Produto;

Produto produto;

void cadastroProduto();
void listarProduto();
void comprarProduto();
void finalizaFuncao();

int main(){
    int opcao;
    
    do{
        printf("---- SuperMais ----\n");
        printf("1- Cadastrar produto\n");
        printf("2- Listar o produto\n");
        printf("3- Comprar\n");
        printf("0- Sair\n");
        scanf("%d", &opcao);
        
        switch (opcao){
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
            system ("clear");
            printf("Obrigado! :)\n");
            break;
            
            default:
            system ("clear");
            printf("Opção inválida!\n");
            break;
        }
        
    } while (opcao != 0);
    
    return 0;
}

void cadastroProduto() {
    system ("clear");
    printf("---- Cadastro do Produto ----\n");
    printf("Nome: ");
    scanf(" %[^\n]", produto.nome);
    
    printf("Preço: ");
    scanf("%f", &produto.preco);
    
    printf("Quantidade: ");
    scanf("%d", &produto.quantidade);
    
    finalizaFuncao();
}

void listarProduto() {
    system ("clear");
    printf("---- Informações do Produto ----\n");
    printf("Nome: %s\n", produto.nome);
    printf("Preço: %.2f\n", produto.preco);
    printf("Quantidade: %d\n", produto.quantidade);
    finalizaFuncao();
}

void comprarProduto() {
    int quantCompra;
    float valorCompra;
    system ("clear");
    
        printf("---- Comprar Produto ----\n");
        printf("Disponivel:\n");
        printf("%s\n", produto.nome);
        printf("Preço do produto: %.2f\n", produto.preco);
        printf("Quantidade disponivel: %d\n", produto.quantidade);
        printf("Quantidade que deseja comprar de %s:\n", produto.nome);
        scanf("%d", &quantCompra);
        
        valorCompra = quantCompra * produto.preco;
        
        if (quantCompra <= produto.quantidade) {
            system("clear");
            printf("Compra aprovada!\n");
            printf("O valor da sua compra é de: %.2f\n", valorCompra);
            
            produto.quantidade -= quantCompra;
            
            printf("Quantidade restante: %d\n", produto.quantidade);
        } 
        else {
            system("clear");
            printf("Compra não autorizada! Quantidade indisponivel.\n");
        }
    
    finalizaFuncao();
}

void finalizaFuncao() {
    printf("Enter para continuar...");
    getchar();   
    getchar();
    system("clear");
}
