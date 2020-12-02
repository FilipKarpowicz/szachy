#include "stan_gry_def.h"
#include <stdio.h>

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
        {.plansza = {{'W', 'S', 'G', 'H', 'K', 'G', 'S', 'W'},
                     {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                     {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                     {'w', 's', 'g', 'h', 'k', 'g', 's', 'w'}}};
    return start;
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
    if (szukana = 'K')
        return -1;
    else if (szukana = 'k')
        return 1;
}

int main()
{
    struct szachownica plansza = start();
    wypisanie(plansza);
}