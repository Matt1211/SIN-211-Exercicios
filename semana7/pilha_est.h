#include <stdio.h>
#include <stdlib.h>
#define tamanhoPilha 50

typedef struct sPilha
{

    float items[tamanhoPilha];
    int topo;

} Pilha;

void inicializaTopo(Pilha *ptrPilha)
{
    ptrPilha->topo = -1;
}

int isPilhaVazia(Pilha *ptrPilha)
{
    if (ptrPilha->topo == -1)
    {
        return 1;
    }

    return 0;
}

int isPilhaCheia(Pilha *ptrPilha)
{
    if (ptrPilha->topo == 49)
        return 1;

    return 0;
}

void push(Pilha *ptrPilha, float elemento)
{
    if (isPilhaCheia(ptrPilha))
    {
        printf("Pilha Cheia!");
        exit(1);
    }

    (ptrPilha->topo)++;
    ptrPilha->items[ptrPilha->topo] = elemento;

    printf("Elemento inserido!\n");
}

void pop(Pilha *ptrPilha)
{
    float to_be_removed;

    if (isPilhaVazia(ptrPilha))
    {
        printf("Pilha vazia!\n");
        return -1;
    }

    to_be_removed = ptrPilha->items[ptrPilha->topo];
    (ptrPilha->topo)--;

    printf("Elemento removido com sucesso!\n");
}

float stacktop(Pilha *ptrPilha)
{
    if (isPilhaVazia(ptrPilha))
    {
        printf("Pilha vazia!\n");
        return -1;
    }

    return ptrPilha->items[ptrPilha->topo];
}


void exibeElementos(Pilha *ptrPilha){
    if(isPilhaVazia(ptrPilha)){
        printf("Pilha vazia\n");
        exit(1);
    }
    for (int i = 0; i < ptrPilha->topo; i++)
    {
        printf("%f\n", ptrPilha->items[i]);
    }
    
}