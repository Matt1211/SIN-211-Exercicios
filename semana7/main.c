#include "pilha_est.h"

int main(){
    int opt;
    Pilha *ptrPilha;
    inicializaTopo(ptrPilha);
    float elemento, result;

    do
    {
        printf("\nEscolha uma das opcoes abaixo\n");
        printf("1 - inserir numero real na pilha\n");
        printf("2 - remover numero real do topo da pilha\n");
        printf("3 - retornar numero real do topo da pilha\n");
        printf("4 - exibir os elementos da pilha\n");
        printf("5 - sair\n");
        printf("Sua escolha: ");
        scanf("%d", &opt);


        switch (opt)
        {
        case 1:
            printf("Digite um numero real: ");
            scanf("%f", &elemento);
            push(ptrPilha, elemento);
            break;

        case 2:
            printf("Tentando remover elemento...");
            pop(ptrPilha);
            break;

        case 3:
            printf("Retornando...\n");
            stacktop(ptrPilha);
            break;

        case 4:
            printf("Exibindo...\n");
            exibeElementos(ptrPilha);
            break;
        
        default:
            opt = 5;
            break;
        }
    } while (opt != 5);
    
    printf("Encerrando programa!\n");

    return 0;
}