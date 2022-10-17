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

void inserir_fim(No **lista, int elemento)
{
    No *novo;
    No *aux;
    novo = AlocarNo();

    if (novo != NULL)
    {
        novo->info = elemento;
        novo->esq = NULL;
        novo->dir = NULL;
        if (is_lista_vazia(*lista))
        {
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->dir != NULL)
            {
                aux = aux->dir;
            }
            aux->dir = novo;
            novo->esq = aux;
        }
    }
}

void remover_inicio(No **lista)
{
    No *to_be_removed;
    to_be_removed = *lista;

    if (!is_lista_vazia(*lista))
    {
        *lista = to_be_removed->dir;
        if (*lista != NULL)
        {
            (*lista)->esq = NULL;
        }
        DesalocaNo(to_be_removed);
    }

    printf("\nErro: lista vazia!\n");
    exit(1);
}

No *pesquisar(No *lista, int elemento)
{
    No *aux;
    aux = lista;

    if (!is_lista_vazia(lista))
    {
        while (aux != NULL)
        {
            if (aux->info == elemento)
            {
                return aux;
            }
            aux = aux->dir;
        }
    }

    printf("\nNo nao encontrado\n");
    return NULL;
}

int remover_valor(No **lista, int elemento)
{
    No *to_be_removed;

    if ((to_be_removed = pesquisar(*lista, elemento)) != NULL)
    {
        if (*lista == to_be_removed)
        {
            remover_inicio(lista);
        }
        else
        {
            (to_be_removed->esq)->dir = to_be_removed->dir;
            if (to_be_removed->dir != NULL)
            {
                (to_be_removed->dir)->esq = to_be_removed->esq;
            }
            DesalocaNo(to_be_removed);
        }

        return 1;
    }

    return 0;
}