#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAMANHO_LISTA 100

typedef struct sMusica
{

    char nomeMusica[92];
    char cantorMusica[31];
    int duracaoMusica;

} Musica;

typedef struct sLista
{

    Musica playlist[TAMANHO_LISTA];
    int topoLista;

} ListaEstatica;

void inicializar_lista_estatica(ListaEstatica *ptrLista)
{
    ptrLista->topoLista = -1;
}

int lista_cheia(ListaEstatica *ptrLista)
{

    if (ptrLista->topoLista + 1 == TAMANHO_LISTA)
    {
        return 1;
    }

    return 0;
}

int lista_vazia(ListaEstatica *ptrLista)
{

    if (ptrLista->topoLista == -1)
    {
        return 1;
    }

    return 0;
}

int lista_insere_fim(ListaEstatica *ptrLista, Musica musica)
{

    if (lista_cheia(ptrLista))
    {
        printf("Erro - Lista Cheia!");
        return -1;
    }

    ptrLista->topoLista++;

    ptrLista->playlist[ptrLista->topoLista] = musica;

    return 0;
}

int insere_posicao_especifica(ListaEstatica *ptrLista, int posicao, Musica musica)
{

    if (lista_cheia(ptrLista))
    {
        printf("Erro - Lista Cheia!");
        return -1;
    }

    if (posicao < 0 || posicao > ptrLista->topoLista + 1)
    {
        printf("Erro! Posicao desejada para insercao eh invalida!\n");
        return -1;
    }

    for (int i = (ptrLista->topoLista + 1); i > posicao; i--)
    {
        ptrLista->playlist[i] = ptrLista->playlist[i - 1];
    }

    ptrLista->playlist[posicao] = musica;

    ptrLista->topoLista++;

    return 0;
}

int remove_elemento(ListaEstatica *ptrLista, int posicao)
{

    if (lista_vazia(ptrLista))
    {
        printf("Erro! A lista se encontra vazia!\n");
        return -1;
    }

    if (posicao < 0 || posicao > ptrLista->topoLista)
    {
        printf("Erro! Posicao desejada para insercao eh invalida!\n");
        return -1;
    }

    for (int i = posicao; i < (ptrLista->topoLista); i++)
    {
        ptrLista->playlist[i] = ptrLista->playlist[i + 1];
    }

    ptrLista->topoLista = ptrLista->topoLista - 1;

    return 0;
}

int insere_inicio(ListaEstatica *ptrLista, Musica musica)
{

    if (lista_cheia(ptrLista))
    {
        printf("Erro - Lista Cheia!");
        return -1;
    }

    if (lista_vazia(ptrLista)){
        printf("Erro - Lista nao inicializada!\n");
        return -1;
    }

    ptrLista->topoLista++;

    for (int i = 0; i < ptrLista->topoLista; i++)
    {
        ptrLista->playlist[i+1] = ptrLista->playlist[i];
    }

    ptrLista->playlist[0] = musica;

    return 0;
    
}

int pesquisa_musica(ListaEstatica* ptrLista, char nomeMusica[92]){

    if (lista_vazia(ptrLista))
    {
        printf("A sua playlist se encontra vazia!\n");
        return -1;
    }

    for (int i = 0; i < ptrLista->topoLista+1; i++)
    {
        if(strcmp(nomeMusica, ptrLista->playlist[i].nomeMusica)){
            return i;
        }
    }
    
    printf("Musica nao encontrada\n");
    return -1;
    
}