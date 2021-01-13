#include "stan_gry_def.h"

ruchy *ruchyskoczka(int i, int j, ruchy *koniec, szachownica *baza, int tryb)
{
    if (tryb == 1)
    {
        if (baza->plansza[i + 2][j + 1] == ' ' || baza->plansza[i + 2][j + 1] == 'w' || baza->plansza[i + 2][j + 1] == 's' || baza->plansza[i + 2][j + 1] == 'h' || baza->plansza[i + 2][j + 1] == 'k' || baza->plansza[i + 2][j + 1] == 'p' || baza->plansza[i + 2][j + 1] == 'w' || baza->plansza[i + 2][j + 1] == 'g')
        {
            if (i + 2 < 8 && j + 1 < 8 && i + 2 >= 0 && j + 1 >= 0)
            {
                koniec->z[0] = i; //kon skok +2 +1
                koniec->z[1] = j;
                koniec->d[0] = i + 2;
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i + 2][j - 1] == ' ' || baza->plansza[i + 2][j - 1] == 'w' || baza->plansza[i + 2][j - 1] == 's' || baza->plansza[i + 2][j - 1] == 'h' || baza->plansza[i + 2][j - 1] == 'k' || baza->plansza[i + 2][j - 1] == 'p' || baza->plansza[i + 2][j - 1] == 'w' || baza->plansza[i + 2][j - 1] == 'g')
        {
            if (i + 2 < 8 && j - 1 < 8 && i + 2 >= 0 && j - 1 >= 0)
            {
                koniec->z[0] = i; //kon skok +2 -1
                koniec->z[1] = j;
                koniec->d[0] = i + 2;
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i + 1][j + 2] == ' ' || baza->plansza[i + 1][j + 2] == 'w' || baza->plansza[i + 1][j + 2] == 's' || baza->plansza[i + 1][j + 2] == 'h' || baza->plansza[i + 1][j + 2] == 'k' || baza->plansza[i + 1][j + 2] == 'p' || baza->plansza[i + 1][j + 2] == 'w' || baza->plansza[i + 1][j + 2] == 'g')
        {
            if (i + 1 < 8 && j + 2 < 8 && i + 1 >= 0 && j + 2 >= 0)
            {
                koniec->z[0] = i; //kon skok +1 +2
                koniec->z[1] = j;
                koniec->d[0] = i + 1;
                koniec->d[1] = j + 2;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i + 1][j - 2] == ' ' || baza->plansza[i + 1][j - 2] == 'w' || baza->plansza[i + 1][j - 2] == 's' || baza->plansza[i + 1][j - 2] == 'h' || baza->plansza[i + 1][j - 2] == 'k' || baza->plansza[i + 1][j - 2] == 'p' || baza->plansza[i + 1][j - 2] == 'w' || baza->plansza[i + 1][j - 2] == 'g')
        {
            if (i + 1 < 8 && j - 2 < 8 && i + 1 >= 0 && j - 2 >= 0)
            {
                koniec->z[0] = i; //kon skok +1 -2
                koniec->z[1] = j;
                koniec->d[0] = i + 1;
                koniec->d[1] = j - 2;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i - 1][j + 2] == ' ' || baza->plansza[i - 1][j + 2] == 'w' || baza->plansza[i - 1][j + 2] == 's' || baza->plansza[i - 1][j + 2] == 'h' || baza->plansza[i - 1][j + 2] == 'k' || baza->plansza[i - 1][j + 2] == 'p' || baza->plansza[i - 1][j + 2] == 'w' || baza->plansza[i - 1][j + 2] == 'g')
        {
            if (i - 1 < 8 && j + 2 < 8 && i - 1 >= 0 && j + 2 >= 0)
            {
                koniec->z[0] = i; //kon skok -1 +2
                koniec->z[1] = j;
                koniec->d[0] = i - 1;
                koniec->d[1] = j + 2;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i - 1][j - 2] == ' ' || baza->plansza[i - 1][j - 2] == 'w' || baza->plansza[i - 1][j - 2] == 's' || baza->plansza[i - 1][j - 2] == 'h' || baza->plansza[i - 1][j - 2] == 'k' || baza->plansza[i - 1][j - 2] == 'p' || baza->plansza[i - 1][j - 2] == 'w' || baza->plansza[i - 1][j - 2] == 'g')
        {
            if (i - 1 < 8 && j - 2 < 8 && i - 1 >= 0 && j - 2 >= 0)
            {
                koniec->z[0] = i; //kon skok -1 -2
                koniec->z[1] = j;
                koniec->d[0] = i - 1;
                koniec->d[1] = j - 2;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i - 2][j + 1] == ' ' || baza->plansza[i - 2][j + 1] == 'w' || baza->plansza[i - 2][j + 1] == 's' || baza->plansza[i - 2][j + 1] == 'h' || baza->plansza[i - 2][j + 1] == 'k' || baza->plansza[i - 2][j + 1] == 'p' || baza->plansza[i - 2][j + 1] == 'w' || baza->plansza[i - 2][j + 1] == 'g')
        {
            if (i - 2 < 8 && j + 1 < 8 && i - 2 >= 0 && j + 1 >= 0)
            {
                koniec->z[0] = i; //kon skok -2 +1
                koniec->z[1] = j;
                koniec->d[0] = i - 2;
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i - 2][j - 1] == ' ' || baza->plansza[i - 2][j - 1] == 'w' || baza->plansza[i - 2][j - 1] == 's' || baza->plansza[i - 2][j - 1] == 'h' || baza->plansza[i - 2][j - 1] == 'k' || baza->plansza[i - 2][j - 1] == 'p' || baza->plansza[i - 2][j - 1] == 'w' || baza->plansza[i - 2][j - 1] == 'g')
        {
            if (i - 2 < 8 && j - 1 < 8 && i - 2 >= 0 && j - 1 >= 0)
            {
                koniec->z[0] = i; //kon skok -2 -1
                koniec->z[1] = j;
                koniec->d[0] = i - 2;
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                koniec = koniec->next;
                //printf("xd\n");
            }
        }
    }
    else if (tryb == -1)
    {
        if (baza->plansza[i + 2][j + 1] == ' ' || baza->plansza[i + 2][j + 1] == 'W' || baza->plansza[i + 2][j + 1] == 'S' || baza->plansza[i + 2][j + 1] == 'H' || baza->plansza[i + 2][j + 1] == 'K' || baza->plansza[i + 2][j + 1] == 'P' || baza->plansza[i + 2][j + 1] == 'W' || baza->plansza[i + 2][j + 1] == 'g')
        {
            if (i + 2 < 8 && j + 1 < 8 && i + 2 >= 0 && j + 1 >= 0)
            {
                koniec->z[0] = i; //kon skok +2 +1
                koniec->z[1] = j;
                koniec->d[0] = i + 2;
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i + 2][j - 1] == ' ' || baza->plansza[i + 2][j - 1] == 'W' || baza->plansza[i + 2][j - 1] == 'S' || baza->plansza[i + 2][j - 1] == 'H' || baza->plansza[i + 2][j - 1] == 'K' || baza->plansza[i + 2][j - 1] == 'P' || baza->plansza[i + 2][j - 1] == 'W' || baza->plansza[i + 2][j - 1] == 'g')
        {
            if (i + 2 < 8 && j - 1 < 8 && i + 2 >= 0 && j - 1 >= 0)
            {
                koniec->z[0] = i; //kon skok +2 -1
                koniec->z[1] = j;
                koniec->d[0] = i + 2;
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i + 1][j + 2] == ' ' || baza->plansza[i + 1][j + 2] == 'W' || baza->plansza[i + 1][j + 2] == 'S' || baza->plansza[i + 1][j + 2] == 'H' || baza->plansza[i + 1][j + 2] == 'K' || baza->plansza[i + 1][j + 2] == 'P' || baza->plansza[i + 1][j + 2] == 'W' || baza->plansza[i + 1][j + 2] == 'g')
        {
            if (i + 1 < 8 && j + 2 < 8 && i + 1 >= 0 && j + 2 >= 0)
            {
                koniec->z[0] = i; //kon skok +1 +2
                koniec->z[1] = j;
                koniec->d[0] = i + 1;
                koniec->d[1] = j + 2;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i + 1][j - 2] == ' ' || baza->plansza[i + 1][j - 2] == 'W' || baza->plansza[i + 1][j - 2] == 'S' || baza->plansza[i + 1][j - 2] == 'H' || baza->plansza[i + 1][j - 2] == 'K' || baza->plansza[i + 1][j - 2] == 'P' || baza->plansza[i + 1][j - 2] == 'W' || baza->plansza[i + 1][j - 2] == 'g')
        {
            if (i + 1 < 8 && j - 2 < 8 && i + 1 >= 0 && j - 2 >= 0)
            {
                koniec->z[0] = i; //kon skok +1 -2
                koniec->z[1] = j;
                koniec->d[0] = i + 1;
                koniec->d[1] = j - 2;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i - 1][j + 2] == ' ' || baza->plansza[i - 1][j + 2] == 'W' || baza->plansza[i - 1][j + 2] == 'S' || baza->plansza[i - 1][j + 2] == 'H' || baza->plansza[i - 1][j + 2] == 'K' || baza->plansza[i - 1][j + 2] == 'P' || baza->plansza[i - 1][j + 2] == 'W' || baza->plansza[i - 1][j + 2] == 'g')
        {
            if (i - 1 < 8 && j + 2 < 8 && i - 1 >= 0 && j + 2 >= 0)
            {
                koniec->z[0] = i; //kon skok -1 +2
                koniec->z[1] = j;
                koniec->d[0] = i - 1;
                koniec->d[1] = j + 2;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i - 1][j - 2] == ' ' || baza->plansza[i - 1][j - 2] == 'W' || baza->plansza[i - 1][j - 2] == 'S' || baza->plansza[i - 1][j - 2] == 'H' || baza->plansza[i - 1][j - 2] == 'K' || baza->plansza[i - 1][j - 2] == 'P' || baza->plansza[i - 1][j - 2] == 'W' || baza->plansza[i - 1][j - 2] == 'g')
        {
            if (i - 1 < 8 && j - 2 < 8 && i - 1 >= 0 && j - 2 >= 0)
            {
                koniec->z[0] = i; //kon skok -1 -2
                koniec->z[1] = j;
                koniec->d[0] = i - 1;
                koniec->d[1] = j - 2;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i - 2][j + 1] == ' ' || baza->plansza[i - 2][j + 1] == 'W' || baza->plansza[i - 2][j + 1] == 'S' || baza->plansza[i - 2][j + 1] == 'H' || baza->plansza[i - 2][j + 1] == 'K' || baza->plansza[i - 2][j + 1] == 'P' || baza->plansza[i - 2][j + 1] == 'W' || baza->plansza[i - 2][j + 1] == 'g')
        {
            if (i - 2 < 8 && j + 1 < 8 && i - 2 >= 0 && j + 1 >= 0)
            {
                koniec->z[0] = i; //kon skok -2 +1
                koniec->z[1] = j;
                koniec->d[0] = i - 2;
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (baza->plansza[i - 2][j - 1] == ' ' || baza->plansza[i - 2][j - 1] == 'W' || baza->plansza[i - 2][j - 1] == 'S' || baza->plansza[i - 2][j - 1] == 'H' || baza->plansza[i - 2][j - 1] == 'K' || baza->plansza[i - 2][j - 1] == 'P' || baza->plansza[i - 2][j - 1] == 'W' || baza->plansza[i - 2][j - 1] == 'G')
        {
            if (i - 2 < 8 && j - 1 < 8 && i - 2 >= 0 && j - 1 >= 0)
            {
                koniec->z[0] = i; //kon skok -2 -1
                koniec->z[1] = j;
                koniec->d[0] = i - 2;
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
    }
    return koniec;
}