#include "stan_gry_def.h"

void wypisanie(struct szachownica *plansza, char **Bierki)
{
    printf(" | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d", i);
        for (int j = 0; j < 8; j++)
        {
            printf("| %s ", Bierki[jaka_bierka(plansza->plansza[i][j])]);
            if (j == 7)
                printf("|\n");
        }
        printf(" +---+---+---+---+---+---+---+---+\n");
    }
}

int jaka_bierka(char co)
{
    if (co == 'P')
        return 0;
    if (co == 'K')
        return 1;
    if (co == 'S')
        return 2;
    if (co == 'G')
        return 3;
    if (co == 'W')
        return 4;
    if (co == 'H')
        return 5;
    if (co == 'p')
        return 6;
    if (co == 'k')
        return 7;
    if (co == 's')
        return 8;
    if (co == 'g')
        return 9;
    if (co == 'w')
        return 10;
    if (co == 'h')
        return 11;
    if (co == ' ')
        return 12;
}

struct szachownica start(void)
{
    struct szachownica start =
        {.plansza = {{'W', 'S', 'G', 'K', 'H', 'G', 'S', 'W'},
                     {'P', 'P', 'P', ' ', ' ', ' ', 'P', 'P'},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', 'W', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {'w', ' ', ' ', 'k', ' ', ' ', ' ', ' '}},
         .ruch = -1,
         .enpassant = {0, 0},
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
    ruchy *ruch1;
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
        printf("%d%d %d%d %c %c\n", lista->z[0], lista->z[1], lista->d[0], lista->d[1], lista->promocja, lista->roszada);
        lista = lista->next;
    }
}

struct szachownica wykonajruch(struct szachownica gra, ruchy *lr)
{

    if (gra.plansza[lr->z[0]][lr->z[1]] == 'W' && gra.roszada[0][0] == 1 && lr->z[0] == 0 && lr->z[1] == 0)
    {
        gra.roszada[0][0] = 0;
    }
    if (gra.plansza[lr->z[0]][lr->z[1]] == 'W' && gra.roszada[0][1] == 1 && lr->z[0] == 0 && lr->z[1] == 7)
    {
        gra.roszada[0][1] = 0;
    }
    if (gra.plansza[lr->z[0]][lr->z[1]] == 'w' && gra.roszada[1][0] == 1 && lr->z[0] == 7 && lr->z[1] == 0)
    {
        gra.roszada[1][0] = 0;
    }
    if (gra.plansza[lr->z[0]][lr->z[1]] == 'w' && gra.roszada[1][1] == 1 && lr->z[0] == 7 && lr->z[1] == 7)
    {
        gra.roszada[1][1] = 0;
    }
    if (gra.plansza[lr->z[0]][lr->z[1]] == 'K')
    {
        gra.roszada[0][0] = 0;
        gra.roszada[0][1] = 0;
    }
    if (gra.plansza[lr->z[0]][lr->z[1]] == 'k')
    {
        gra.roszada[1][0] = 0;
        gra.roszada[1][1] = 0;
    }
    if (gra.plansza[lr->z[0]][lr->z[1]] == 'P' || gra.plansza[lr->z[0]][lr->z[1]] == 'p')
    {
        // printf("lr z %d d %d\n", lr->z[0], lr->d[0]);
        if (lr->z[0] - lr->d[0] == 2 || lr->z[0] - lr->d[0] == -2)
        {
            //printf("!!!!\n");
            gra.enpassant[0] = lr->d[0];
            gra.enpassant[1] = lr->d[1];
        }
    }
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
        if (lr->d[0] - gra.ruch == gra.enpassant[0] && lr->d[1] == gra.enpassant[1])
        {
            gra.plansza[gra.enpassant[0]][gra.enpassant[1]] = ' ';
        }
        gra.ruch = -gra.ruch;
    }
    return gra;
}

struct szachownica wykonajruchpatologiczny(struct szachownica gra, ruchy *lr, int a, int b, int c, int d)
{
    if (lr->promocja)
    {
        gra.plansza[a][b] = ' ';
        gra.plansza[c][d] = lr->promocja;
        gra.ruch = -gra.ruch;
    }
    else
    {
        char fig = gra.plansza[a][b];
        gra.plansza[a][b] = ' ';
        gra.plansza[c][d] = fig;
        gra.ruch = -gra.ruch;
    }
    return gra;
}
//wypisać warunek ruchu

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
                wynik = wynik + 1;
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
    char *Bierki[] = {
        "\u265F", //pion bialy
        "\u265A", //hetman bialy
        "\u265E", //skoczek bialy
        "\u265D", //goniec bialy
        "\u265C", //wieza biala
        "\u265B", //krol bialy

        "\u2659", //pionek czarny
        "\u2654", //hetman czarny
        "\u2658", //skoczek czarny
        "\u2657", //goniec czarny
        "\u2656", //wieza czarna
        "\u2655", //krol czarny
        " ",
    };
    int e = 0;
    int f = 0;
    int g = 0;
    int h = 0;
    struct szachownica plansza = start();
    wypisanie(&plansza, Bierki);
    //printf("%d\n", ocena(plansza));
    ruchy *glowa = listaruchow(&plansza, plansza.ruch);
    printf("czy dziala\n");
    wypiszliste(glowa);

    // glowa = listaruchow(&plansza, plansza.ruch);
    //wypiszliste(glowa);
    int ocena1 = negmax(&plansza, 1, -1000, 1000);
    printf("wynik negmax= %d\n", ocena1);
    printf("ocena wezla%d\n", ocena(plansza));

    /*e = najlepszy_ruch1(&plansza, 1, -1000, 1000);
    f = najlepszy_ruch2(&plansza, 1, -1000, 1000);
    g = najlepszy_ruch3(&plansza, 1, -1000, 1000);
    h = najlepszy_ruch4(&plansza, 1, -1000, 1000);
    printf("%d%d %d%d\n",
           e, f, g, h);
    plansza = wykonajruchpatologiczny(plansza, glowa, e, f, g, h);
    wypisanie(&plansza, Bierki);*/
    int i, j, k, l;
    ruchy *ruchgracza = malloc(sizeof(ruchy));
    ruchy *ruch;
    for (int i = 0; i < 1; i++)
    {
        ruch = jakiruch(&plansza, 4, -1000, 1000);
        plansza = wykonajruch(plansza, ruch);
        wypisanie(&plansza, Bierki);
        printf("\n");
        scanf("%d%d%d%d", &i, &j, &k, &l);
        ruchgracza->z[0] = i;
        ruchgracza->z[1] = j;
        ruchgracza->d[0] = k;
        ruchgracza->d[1] = l;
        plansza = wykonajruch(plansza, ruchgracza);
        wypisanie(&plansza, Bierki);
        printf("\n");
    }
    // printf("czy szach %d\n", czy_szachowane(&plansza, 7, 3));
}