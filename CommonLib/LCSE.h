#include <stdio.h>
#include <stdlib.h>

typedef struct sNo
{
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

void inserir_fim(No **lista, int elemento)
{
    No *novo;

    novo = AlocarNo();

    if (novo != NULL)
    {
        novo->info = elemento;
        if (is_lista_vazia(*lista))
        {
            novo->prox = novo;
        }
        else
        {
            novo->prox = (*lista)->prox;
            (*lista)->prox = novo;
        }

        *lista = novo;
    }

    printf("\nErro na alocacao!\n");
    exit(1);
}

void remover_inicio(No **lista)
{
    No *aux;

    if (is_lista_vazia(*lista))
    {
        if ((*lista) == (*lista)->prox)
        {
            DesalocaNo(*lista);
            *lista = NULL;
        }
        else
        {
            aux = (*lista)->prox;
            (*lista)->prox = aux->prox;
            DesalocaNo(aux);
        }
    }

    printf("\nLista vazia!\n");

    exit(1);
}


void imprimir_lista(No *lista){
    No *aux;

    if(lista != NULL){
        aux = lista->prox;
        do{
            printf("%d\t", aux->info);
            aux = aux->prox;
        }while(aux != lista->prox);
    }
    else{
        printf("\nLista vazia!\n");
        exit(1);
    }

    printf("\n");
}