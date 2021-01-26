#include "stan_gry_def.h"

ruchy *listaruchowbezkrola(szachownica *plansza, int kolor)
{
    glowalisty *glowa = (glowalisty *)malloc(sizeof(glowalisty));
    glowa->glowa = (ruchy *)malloc(sizeof(ruchy));

    //printf("czy to dziala\n");
    ruchy *lista = glowa->glowa;
    glowalisty *poczatek = (glowalisty *)malloc(sizeof(glowalisty));
    poczatek->glowa = (ruchy *)malloc(sizeof(ruchy));
    //lista = ruchykrola(0, 1, lista, plansza, 1);
    if (kolor == 1) //biale
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                //printf("%c\n", plansza->plansza[i][j]);

                //printf("xd\n");
                if (plansza->plansza[i][j] == 'H')
                    lista = ruchyhetmana(i, j, lista, plansza, 1);
                if (plansza->plansza[i][j] == 'G')
                    lista = ruchygonca(i, j, lista, plansza, 1);
                if (plansza->plansza[i][j] == 'W')
                    lista = ruchywiezy(i, j, lista, plansza, 1);
                if (plansza->plansza[i][j] == 'S')
                    lista = ruchyskoczka(i, j, lista, plansza, 1);
                //printf("xd\n");
                if (plansza->plansza[i][j] == 'P')
                    lista = ruchypiona(i, j, lista, plansza, 1);
            }
            //printf("xd\n");
        }
    }
    else if (kolor == -1) //czarne
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (plansza->plansza[i][j] == 'h')
                    lista = ruchyhetmana(i, j, lista, plansza, -1);
                if (plansza->plansza[i][j] == 'g')
                    lista = ruchygonca(i, j, lista, plansza, -1);
                if (plansza->plansza[i][j] == 'w')
                    lista = ruchywiezy(i, j, lista, plansza, -1);
                if (plansza->plansza[i][j] == 's')
                    lista = ruchyskoczka(i, j, lista, plansza, -1);
                if (plansza->plansza[i][j] == 'p')
                    lista = ruchypiona(i, j, lista, plansza, -1);
            }
        }
    }
    lista->next = NULL;
    ruchy *cos = glowa->glowa;
    while (cos->next != lista)
    {
        cos = cos->next;
    }
    cos->next = NULL;
    lista = NULL;
    free(cos->next);
    //free(lista);
    lista = glowa->glowa;
    free(glowa);
    return lista;
}

int czy_szachowane(szachownica *mapa, int y, int x)
{
    ruchy *glowa = listaruchowbezkrola(mapa, mapa->ruch * -1);
    //printf("czy to dziala2\n");
    //wypiszliste(glowa);
    ruchy *ptr = glowa;
    while (glowa)
    {
        if (glowa->d[0] == y && glowa->d[1] == x)
            return 1;
        glowa = glowa->next;
    }
    zwolnienie_listy(ptr);
    return 0;
}