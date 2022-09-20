#include "ex1.h"

int main()
{
    int opcao = 0;
    Musica novaMusica;
    int qtd_Musicas = 1;
    char busca[92];

    ListaEstatica *ptrPlaylist;

    ptrPlaylist = (ListaEstatica *)malloc(sizeof(ListaEstatica));

    inicializar_lista_estatica(ptrPlaylist);

    if (ptrPlaylist->topoLista != -1)
    {
        printf("Falha na inicialização da lista!\n");
        return -1;
    }

    while (opcao != 4)
    {
        printf("Escolha uma opcao:\n");

        printf("1 - Cadastrar musica na playlist\n");
        printf("2 - Pesquisar musica na playlist\n");
        printf("3 - Remover musica da playlist\n");

        printf("Sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            printf("Adicionando Musica %d...\n", qtd_Musicas);
            printf("Nome da musica %d: ", qtd_Musicas);
            scanf("%[^\n]%*c", novaMusica.nomeMusica);
            printf("Nome do cantor da musica %d: ", qtd_Musicas);
            scanf("%[^\n]%*c", novaMusica.cantorMusica);
            printf("Duracao da musica %d em segundos: ", qtd_Musicas);
            scanf("%d", &novaMusica.duracaoMusica);

            insere_inicio(ptrPlaylist, novaMusica);
        break;

        case 2:
            printf("Pesquisando Musicas...\n");
        break;

        case 3:
        break;

        default:
            opcao = 4;
            break;
        }
    }

    free(ptrPlaylist);

    return 0;
}
