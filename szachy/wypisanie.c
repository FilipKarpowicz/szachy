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
        {.plansza = {{' ', 'S', ' ', 'K', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', 'p', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', 'p', ' ', ' '},
                     {'p', ' ', ' ', 'k', ' ', ' ', ' ', ' '}},
         .ruch = -1,
         .enpassant = {0, 0},
         .roszada = {{0, 0}, {0, 0}}};
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
    char szukana, szukana2;
    int ocena = 0;
    if (gra.ruch == 1) //1 to biale -1 to czarne duze biale male czarne
    {
        szukana = 'K';
        szukana2 = 'k';
    }
    else if (gra.ruch == -1)
    {
        szukana = 'k';
        szukana2 = 'K';
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (gra.plansza[i][j] == szukana)
                ocena++;
            if (gra.plansza[i][j] == szukana2)
                ocena = ocena + 2;
        }
    }
    if (ocena == 3)
        return sumabierek(&gra);
    if (ocena == 2)
        return -100;
    if (ocena == 1)
        return 100;
}
ruchy *pamiec()
{
    ruchy *wynik = (ruchy *)malloc(sizeof(ruchy));
    return wynik;
}

ruchy *listaruchow(szachownica *plansza, int kolor)
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
    return glowa->glowa;
}

void wypiszliste(ruchy *glowa)
{
    ruchy *lista = glowa;
    while (lista)
    {
        printf("%d%d %d%d %c\n", lista->z[0], lista->z[1], lista->d[0], lista->d[1], lista->promocja);
        lista = lista->next;
    }
}

struct szachownica wykonajruch(struct szachownica gra, ruchy *lr)
{
    if (lr->promocja)
    {
        gra.plansza[lr->z[0]][lr->z[1]] = ' ';
        gra.plansza[lr->d[0]][lr->d[1]] = lr->promocja;
        gra.ruch = -gra.ruch;
    }
    else
    {
        char fig = gra.plansza[lr->z[0]][lr->z[1]];
        gra.plansza[lr->z[0]][lr->z[1]] = ' ';
        gra.plansza[lr->d[0]][lr->d[1]] = fig;
        gra.ruch = -gra.ruch;
    }
    return gra;
}

int sumabierek(struct szachownica *gra)
{
    int wynik = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (gra->plansza[i][j] == ' ' || gra->plansza[i][j] == 'K' || gra->plansza[i][j] == 'k')
            {
            }
            if (gra->plansza[i][j] == 'P')
                wynik++;
            if (gra->plansza[i][j] == 'W')
                wynik = wynik + 5;
            if (gra->plansza[i][j] == 'S' || gra->plansza[i][j] == 'G')
                wynik = wynik + 3;
            if (gra->plansza[i][j] == 'H')
                wynik = wynik + 9;
            if (gra->plansza[i][j] == 'p')
                wynik = wynik - 1;
            if (gra->plansza[i][j] == 'w')
                wynik = wynik - 5;
            if (gra->plansza[i][j] == 's' || gra->plansza[i][j] == 'g')
                wynik = wynik - 3;
            if (gra->plansza[i][j] == 'h')
                wynik = wynik - 9;
        }
    }
    return wynik * gra->ruch;
}

int main()
{
    struct szachownica plansza = start();
    wypisanie(plansza);
    printf("%d\n", ocena(plansza));
    ruchy *glowa = listaruchow(&plansza, -1);
    wypiszliste(glowa);
    printf("xd\n");
    wykonajruch(plansza, glowa);
    glowa = listaruchow(&plansza, 1);
    wypiszliste(glowa);
    int ocena1 = negmax(&plansza, 1, -1000, 1000);
    printf("ocena= %d\n", ocena1);
    printf("%d\n", ocena(plansza));
}