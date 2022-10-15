#include <stdio.h>
#include <stdlib.h>

typedef struct sNo
{
    // tipo int será utilizado aqui para fins didáticos, pode ser utilizado qualquer tipo no campo de 'informação' do nó

    int info;
    struct sNo *prox;

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

No *inserir_inicio(No *lista, int elemento)
{
    No *novo;
    novo = AlocarNo();

    if (novo != NULL)
    {
        novo->info = elemento;
        novo->prox = lista;
        lista = novo;
        return lista;
    }

    printf("\nErro na alocação do no\n");
    return NULL;
}

No *inserir_fim(No *lista, int elemento)
{
    No *novo;
    No *aux;

    novo = AlocarNo();

    if (novo != NULL)
    {
        novo->info = elemento;
        novo->prox = NULL;

        if (is_lista_vazia(lista))
        {
            lista = novo;
        }
        else
        {
            aux = lista;
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        return lista;
    }

    printf("\nErro na alocação do no\n");
    return NULL;
}

No *remover_inicio(No *lista)
{
    No *to_be_removed;

    to_be_removed = lista;

    if (!is_lista_vazia(lista))
    {
        lista = to_be_removed->prox;
        DesalocaNo(to_be_removed);
        return lista;
    }

    printf("\nLista vazia!\n");
    return NULL;
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
            aux = aux->prox;
        }
    }

    printf("\nNo nao encontrado\n");
    return NULL;
}

No *remover_valor(No *lista, int elemento)
{
    No *to_be_removed;
    No *aux;

    if ((to_be_removed = pesquisar(lista, elemento)) != NULL)
    {
        aux = lista;
        if (aux == to_be_removed)
        {
            remover_inicio(lista);
        }
        else
        {
            while (aux->prox != to_be_removed)
            {
                aux = aux->prox;
            }
            aux->prox = to_be_removed->prox;
            DesalocaNo(to_be_removed);
        }
        return lista;
    }

    printf("\nNao foi possivel remover o elemento\n");

    return NULL;
}