#include <stdio.h>
#include <stdlib.h>

typedef struct sNo
{
    int info;
    struct sNo *dir;
    struct sNo *esq;
} No;

No *AlocarNo()
{
    return (No *)malloc(sizeof(No));
}

void DesalocaNo(No *_No)
{
    free(_No);
}

No *inicializa_LSE(No *lista)
{
    lista = NULL;
    return lista;
}

int is_lista_vazia(No *lista)
{

    if (lista == NULL)
    {
        return 1;
    }

    return 0;
}

void inserir_inicio(No **lista, int elemento)
{
    No *novo;
    novo = AlocarNo();

    if (novo != NULL)
    {
        novo->info = elemento;
        novo->esq = NULL;
        novo->dir = *lista;

        if (!is_lista_vazia(*lista))
        {
            (*lista)->esq = novo;
        }
        *lista = novo;
    }

    printf("\nFalha na alocacao do no\n");
    exit(1);
}