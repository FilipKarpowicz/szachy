#include "stan_gry_def.h"

ruchy *ruchykrola(int i, int j, ruchy *koniec, szachownica *baza, int tryb)
{
    if (tryb == 1)
    {
        if (i + 1 < 8 && j + 1 < 8)
        {
            if (baza->plansza[i + 1][j + 1] == 'w' || baza->plansza[i + 1][j + 1] == ' ' || baza->plansza[i + 1][j + 1] == 's' || baza->plansza[i + 1][j + 1] == 'h' || baza->plansza[i + 1][j + 1] == 'k' || baza->plansza[i + 1][j + 1] == 'p' || baza->plansza[i + 1][j + 1] == 'w' || baza->plansza[i + 1][j + 1] == 'g')
            {
                koniec->z[0] = i; //ruch +1,+1
                koniec->z[1] = j;
                koniec->d[0] = i + 1;
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (i + 1 < 8 && j - 1 >= 0)
        {
            if (baza->plansza[i + 1][j - 1] == 'w' || baza->plansza[i + 1][j - 1] == ' ' || baza->plansza[i + 1][j - 1] == 's' || baza->plansza[i + 1][j - 1] == 'h' || baza->plansza[i + 1][j - 1] == 'k' || baza->plansza[i + 1][j - 1] == 'p' || baza->plansza[i + 1][j - 1] == 'w' || baza->plansza[i + 1][j - 1] == 'g')
            {
                koniec->z[0] = i; //ruch +1,-1
                koniec->z[1] = j;
                koniec->d[0] = i + 1;
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (i - 1 >= 0 && j - 1 >= 0)
        {
            if (baza->plansza[i - 1][j - 1] == 'w' || baza->plansza[i - 1][j - 1] == ' ' || baza->plansza[i - 1][j - 1] == 's' || baza->plansza[i - 1][j - 1] == 'h' || baza->plansza[i - 1][j - 1] == 'k' || baza->plansza[i - 1][j - 1] == 'p' || baza->plansza[i - 1][j - 1] == 'w' || baza->plansza[i - 1][j - 1] == 'g')
            {
                koniec->z[0] = i; //ruch -1,-1
                koniec->z[1] = j;
                koniec->d[0] = i - 1;
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (i - 1 >= 0 && j + 1 < 8)
        {
            if (baza->plansza[i - 1][j + 1] == 'w' || baza->plansza[i - 1][j + 1] == ' ' || baza->plansza[i - 1][j + 1] == 's' || baza->plansza[i - 1][j + 1] == 'h' || baza->plansza[i - 1][j + 1] == 'k' || baza->plansza[i - 1][j + 1] == 'p' || baza->plansza[i - 1][j + 1] == 'w' || baza->plansza[i - 1][j + 1] == 'g')
            {
                koniec->z[0] = i; //ruch -1,+1
                koniec->z[1] = j;
                koniec->d[0] = i - 1;
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (i + 1 < 8)
        {
            if (baza->plansza[i + 1][j] == 'w' || baza->plansza[i + 1][j] == ' ' || baza->plansza[i + 1][j] == 's' || baza->plansza[i + 1][j] == 'h' || baza->plansza[i + 1][j] == 'k' || baza->plansza[i + 1][j] == 'p' || baza->plansza[i + 1][j] == 'w' || baza->plansza[i + 1][j] == 'g')
            {
                koniec->z[0] = i; //ruch +1,0
                koniec->z[1] = j;
                koniec->d[0] = i + 1;
                koniec->d[1] = j;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (i - 1 >= 0)
        {
            if (baza->plansza[i - 1][j] == 'w' || baza->plansza[i - 1][j] == ' ' || baza->plansza[i - 1][j] == 's' || baza->plansza[i - 1][j] == 'h' || baza->plansza[i - 1][j] == 'k' || baza->plansza[i - 1][j] == 'p' || baza->plansza[i - 1][j] == 'w' || baza->plansza[i - 1][j] == 'g')
            {
                koniec->z[0] = i; //ruch -1,0
                koniec->z[1] = j;
                koniec->d[0] = i - 1;
                koniec->d[1] = j;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (j + 1 < 8)
        {
            if (baza->plansza[i][j + 1] == 'w' || baza->plansza[i][j + 1] == ' ' || baza->plansza[i][j + 1] == 's' || baza->plansza[i][j + 1] == 'h' || baza->plansza[i][j + 1] == 'k' || baza->plansza[i][j + 1] == 'p' || baza->plansza[i][j + 1] == 'w' || baza->plansza[i][j + 1] == 'g')
            {
                koniec->z[0] = i; //ruch 0,+1
                koniec->z[1] = j;
                koniec->d[0] = i;
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (j - 1 >= 0)
        {
            if (baza->plansza[i][j - 1] == 'w' || baza->plansza[i][j - 1] == ' ' || baza->plansza[i][j - 1] == 's' || baza->plansza[i][j - 1] == 'h' || baza->plansza[i][j - 1] == 'k' || baza->plansza[i][j - 1] == 'p' || baza->plansza[i][j - 1] == 'w' || baza->plansza[i][j - 1] == 'g')
            {
                koniec->z[0] = i; //ruch 0,-1
                koniec->z[1] = j;
                koniec->d[0] = i;
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
    }
    else if (tryb == -1)
    {
        if (i + 1 < 8 && j + 1 < 8)
        {
            if (baza->plansza[i + 1][j + 1] == 'W' || baza->plansza[i + 1][j + 1] == ' ' || baza->plansza[i + 1][j + 1] == 'S' || baza->plansza[i + 1][j + 1] == 'H' || baza->plansza[i + 1][j + 1] == 'K' || baza->plansza[i + 1][j + 1] == 'P' || baza->plansza[i + 1][j + 1] == 'W' || baza->plansza[i + 1][j + 1] == 'G')
            {
                koniec->z[0] = i; //ruch +1,+1
                koniec->z[1] = j;
                koniec->d[0] = i + 1;
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (i + 1 < 8 && j - 1 >= 0)
        {
            if (baza->plansza[i + 1][j - 1] == 'W' || baza->plansza[i + 1][j - 1] == ' ' || baza->plansza[i + 1][j - 1] == 'S' || baza->plansza[i + 1][j - 1] == 'H' || baza->plansza[i + 1][j - 1] == 'K' || baza->plansza[i + 1][j - 1] == 'P' || baza->plansza[i + 1][j - 1] == 'W' || baza->plansza[i + 1][j - 1] == 'G')
            {
                koniec->z[0] = i; //ruch +1,-1
                koniec->z[1] = j;
                koniec->d[0] = i + 1;
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (i - 1 >= 0 && j - 1 >= 0)
        {
            if (baza->plansza[i - 1][j - 1] == 'W' || baza->plansza[i - 1][j - 1] == ' ' || baza->plansza[i - 1][j - 1] == 'S' || baza->plansza[i - 1][j - 1] == 'H' || baza->plansza[i - 1][j - 1] == 'K' || baza->plansza[i - 1][j - 1] == 'P' || baza->plansza[i - 1][j - 1] == 'W' || baza->plansza[i - 1][j - 1] == 'G')
            {
                koniec->z[0] = i; //ruch -1,-1
                koniec->z[1] = j;
                koniec->d[0] = i - 1;
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (i - 1 >= 0 && j + 1 < 8)
        {
            if (baza->plansza[i - 1][j + 1] == 'W' || baza->plansza[i - 1][j + 1] == ' ' || baza->plansza[i - 1][j + 1] == 'S' || baza->plansza[i - 1][j + 1] == 'H' || baza->plansza[i - 1][j + 1] == 'K' || baza->plansza[i - 1][j + 1] == 'P' || baza->plansza[i - 1][j + 1] == 'W' || baza->plansza[i - 1][j + 1] == 'G')
            {
                koniec->z[0] = i; //ruch -1,+1
                koniec->z[1] = j;
                koniec->d[0] = i - 1;
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (i + 1 < 8)
        {
            if (baza->plansza[i + 1][j] == 'W' || baza->plansza[i + 1][j] == ' ' || baza->plansza[i + 1][j] == 'S' || baza->plansza[i + 1][j] == 'H' || baza->plansza[i + 1][j] == 'K' || baza->plansza[i + 1][j] == 'P' || baza->plansza[i + 1][j] == 'W' || baza->plansza[i + 1][j] == 'G')
            {
                koniec->z[0] = i; //ruch +1,0
                koniec->z[1] = j;
                koniec->d[0] = i + 1;
                koniec->d[1] = j;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (i - 1 >= 0)
        {
            if (baza->plansza[i - 1][j] == 'W' || baza->plansza[i - 1][j] == ' ' || baza->plansza[i - 1][j] == 'S' || baza->plansza[i - 1][j] == 'H' || baza->plansza[i - 1][j] == 'K' || baza->plansza[i - 1][j] == 'P' || baza->plansza[i - 1][j] == 'W' || baza->plansza[i - 1][j] == 'G')
            {
                koniec->z[0] = i; //ruch -1,0
                koniec->z[1] = j;
                koniec->d[0] = i - 1;
                koniec->d[1] = j;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (j + 1 < 8)
        {
            if (baza->plansza[i][j + 1] == 'W' || baza->plansza[i][j + 1] == ' ' || baza->plansza[i][j + 1] == 'S' || baza->plansza[i][j + 1] == 'H' || baza->plansza[i][j + 1] == 'K' || baza->plansza[i][j + 1] == 'P' || baza->plansza[i][j + 1] == 'W' || baza->plansza[i][j + 1] == 'G')
            {
                koniec->z[0] = i; //ruch 0,+1
                koniec->z[1] = j;
                koniec->d[0] = i;
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
        if (j - 1 >= 0)
        {
            if (baza->plansza[i][j - 1] == 'W' || baza->plansza[i][j - 1] == ' ' || baza->plansza[i][j - 1] == 'S' || baza->plansza[i][j - 1] == 'H' || baza->plansza[i][j - 1] == 'K' || baza->plansza[i][j - 1] == 'P' || baza->plansza[i][j - 1] == 'W' || baza->plansza[i][j - 1] == 'G')
            {
                koniec->z[0] = i; //ruch 0,-1
                koniec->z[1] = j;
                koniec->d[0] = i;
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                koniec = koniec->next;
            }
        }
    }
    if (tryb == 1)
    {
        if (baza->roszada[0][0] == 1 && czy_szachowane(baza, 0, 1) == 0 && czy_szachowane(baza, 0, 2) == 0 && czy_szachowane(baza, 0, 3) == 0)
        {
            printf("czy to dziala\n");
            koniec->z[0] = i; //roszada w lewo dla bialego
            koniec->z[1] = j;
            koniec->d[0] = i;
            koniec->d[1] = j - 2;
            koniec->roszada = 'r';
            koniec->next = pamiec();
            koniec = koniec->next;
        }
        if (baza->roszada[0][1] == 1 && czy_szachowane(baza, 0, 4) == 0 && czy_szachowane(baza, 0, 5) == 0 && czy_szachowane(baza, 0, 3) == 0)
        {
            koniec->z[0] = i; //roszada w prawo dla bialego
            koniec->z[1] = j;
            koniec->d[0] = i;
            koniec->d[1] = j + 2;
            koniec->roszada = 'r';
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    if (tryb == -1)
    {

        printf("czy to dziala\n");
        if (baza->roszada[1][0] == 1 && czy_szachowane(baza, 7, 1) == 0 && czy_szachowane(baza, 7, 2) == 0 && czy_szachowane(baza, 7, 3) == 0)
        {
            printf("czy to dziala\n");
            koniec->z[0] = i; //roszada w lewo dla czarnego
            koniec->z[1] = j;
            koniec->d[0] = i;
            koniec->d[1] = j - 2;
            koniec->roszada = 'r';
            koniec->next = pamiec();
            koniec = koniec->next;
        }
        if (baza->roszada[1][1] == 1 && czy_szachowane(baza, 7, 4) == 0 && czy_szachowane(baza, 7, 5) == 0 && czy_szachowane(baza, 7, 3) == 0)
        {
            koniec->z[0] = i; //roszada w prawo dla czarnego
            koniec->z[1] = j;
            koniec->d[0] = i;
            koniec->d[1] = j + 2;
            koniec->roszada = 'r';
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    return koniec;
}