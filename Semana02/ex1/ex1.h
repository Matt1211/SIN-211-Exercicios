#include <stdlib.h>
#include <stdio.h>
#define TAMANHO_LISTA 100

typedef struct sMusica{

    char nomeMusica[92];
    char cantorMusica[31];
    int duracaoMusica;

}Musica;

typedef struct sLista{

    Musica playlist[TAMANHO_LISTA];
    int topoLista;

}ListaEstatica;


void inicializar_lista_estatica(ListaEstatica* ptrLista){
    ptrLista->topoLista = -1;
}


int lista_cheia(ListaEstatica* ptrLista){
    
    if(ptrLista->topoLista+1 == TAMANHO_LISTA){
        return 1;
    }

    return 0;
}

int lista_vazia(ListaEstatica* ptrLista){

    if(ptrLista->topoLista == -1){
        return 1;
    }

    return 0;
}

int lista_insere_fim(ListaEstatica* ptrLista, Musica musica){

    if(lista_cheia(ptrLista)){
        printf("Erro - Lista Cheia!");
        return -1;
    }

    ptrLista->topoLista++;

    ptrLista->playlist[ptrLista->topoLista] = musica;

    return 0;
}


int insere_posicao_especifica(ListaEstatica* ptrLista, int posicao, Musica musica){

    if(lista_cheia(ptrLista)){
        printf("Erro - Lista Cheia!");
        return -1;
    }

    if(posicao < 0 || posicao > ptrLista->topoLista+1){
        printf("Erro! Posicao desejada para insercao eh invalida!\n");
        return -1;
    }

    for(int i = (ptrLista->topoLista+1); i > posicao; i--){
        ptrLista->playlist[i] = ptrLista->playlist[i-1];
    }

    ptrLista->playlist[posicao] = musica;

    ptrLista->topoLista++;

    return 0;
}