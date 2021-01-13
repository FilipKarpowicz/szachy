#include "stan_gry_def.h"

void wypisanie(struct szachownica plansza)
{
    printf("+---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("| %c ", plansza.plansza[i][j]);
            if (j == 7)
                printf("|\n");
        }
        printf("+---+---+---+---+---+---+---+---+\n");
    }
}

struct szachownica start(void)
{
    struct szachownica start =
        {.plansza = {{'s', 'S', 'G', 'H', 'K', 'G', ' ', ' '},
                     {'P', ' ', 'K', 'p', 'P', 'p', 'p', 'P'},
                     {' ', ' ', 'p', 'h', 'k', 'p', ' ', ' '},
                     {' ', 'P', 'g', 'k', 'w', 'p', ' ', ' '},
                     {' ', 'p', ' ', 'p', 's', 'p', ' ', 'W'},
                     {' ', 'p', ' ', 's', 'p', 'p', ' ', ' '},
                     {'p', 'p', 'g', 'p', 'p', 'p', ' ', ' '},
                     {'w', ' ', ' ', ' ', 'k', 'g', 's', 'w'}},
         .ruch = 0,
         .enpassant = {3, 3},
         .roszada = {{1, 1}, {1, 1}}};
    return start;
}

char liczby_na_litery(int co)
{
    if (co == 0)
        return 'a';
    if (co == 1)
        return 'b';
    if (co == 2)
        return 'c';
    if (co == 3)
        return 'd';
    if (co == 4)
        return 'e';
    if (co == 5)
        return 'f';
    if (co == 6)
        return 'g';
    if (co == 7)
        return 'h';
    return 'x';
}

int ocena(struct szachownica gra)
{
    char szukana;
    if (gra.ruch == 0) //zero to biale 1 to czarne duze biale male czarne
        szukana = 'K';
    else if (gra.ruch == 1)
        szukana = 'k';
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (gra.plansza[i][j] == szukana)
                return 0;
        }
    }
    if (szukana == 'k')
        return -1;
    else if (szukana == 'K')
        return 1;
    return -1;
}
ruchy *pamiec()
{
    ruchy *wynik = (ruchy *)malloc(sizeof(ruchy));
    return wynik;
}

glowalisty *listaruchow(szachownica *plansza, int kolor)
{
    glowalisty *glowa = (glowalisty *)malloc(sizeof(glowalisty));
    glowa->glowa = (ruchy *)malloc(sizeof(ruchy));
    //ruchy *ruch1;
    //printf("czy to dziala\n");
    ruchy *lista = glowa->glowa;
    /*glowalisty *poczatek = (glowalisty *)malloc(sizeof(glowalisty));
    printf("xd\n");
    poczatek->glowa = (ruchy *)malloc(sizeof(ruchy));
    printf("xd\n");
    ruchy *lista = poczatek->glowa;
    printf("xd\n");
    lista = ruchykrola(0, 1, lista, plansza, 1);
    printf("xd\n");*/
    if (kolor == 1) //biale
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                //printf("%c\n", plansza->plansza[i][j]);
                if (plansza->plansza[i][j] == 'K')
                    lista = ruchykrola(i, j, lista, plansza, 1);
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
                if (plansza->plansza[i][j] == 'k')
                    lista = ruchykrola(i, j, lista, plansza, -1);
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
    return glowa;
}

void wypiszliste(glowalisty *glowa)
{
    ruchy *lista = glowa->glowa;
    while (lista->next != NULL)
    {
        printf("%d%d %d%d %c\n", lista->z[0], lista->z[1], lista->d[0], lista->d[1], lista->promocja);
        lista = lista->next;
    }
}
int main()
{
    struct szachownica plansza = start();
    wypisanie(plansza);
    printf("%d\n", ocena(plansza));
    //glowalisty *glowa = (glowalisty *)malloc(sizeof(glowalisty));
    //glowa->glowa = (ruchy *)malloc(sizeof(ruchy));
    //ruchy *ruch1;
    //printf("czy to dziala\n");
    //ruchy *lista = glowa->glowa;
    //lista = ruchyhetmana(0, 3, lista, &plansza, 1);
    //lista = ruchyskoczka(0, 1, lista, &plansza, 1);
    //printf("xd\n");
    glowalisty *glowa = listaruchow(&plansza, 1);
    wypiszliste(glowa);
    // glowalisty *lista = listaruchow(&plansza, 1);
    //printf("xd\n");
    //wypiszliste(lista);
}