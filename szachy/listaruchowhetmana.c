#include "stan_gry_def.h"

ruchy *ruchyhetmana(int i, int j, ruchy *koniec, szachownica *baza, int tryb)
{
    int k = i + 1;
    int l = j + 1;
    while (baza->plansza[k][l] == ' ' && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        koniec->z[0] = i; //ruch +1,+1
        koniec->z[1] = j;
        koniec->d[0] = k;
        koniec->d[1] = l;
        koniec->next = pamiec();
        koniec = koniec->next;
        k = k + 1;
        l = l + 1;
    }
    if (tryb == 1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 's' || baza->plansza[k][l] == 'h' || baza->plansza[k][l] == 'k' || baza->plansza[k][l] == 'p' || baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 'g')
        {
            koniec->z[0] = i; //bicie bialy +1,+1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }

    if (tryb == -1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'S' || baza->plansza[k][l] == 'H' || baza->plansza[k][l] == 'K' || baza->plansza[k][l] == 'P' || baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'G')
        {
            koniec->z[0] = i; //bicie czarny +1,+1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    k = i - 1;
    l = j - 1;
    while (baza->plansza[k][l] == ' ' && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        koniec->z[0] = i; //ruch -1,-1
        koniec->z[1] = j;
        koniec->d[0] = k;
        koniec->d[1] = l;
        koniec->next = pamiec();
        koniec = koniec->next;
        k = k - 1;
        l = l - 1;
    }
    if (tryb == 1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 's' || baza->plansza[k][l] == 'h' || baza->plansza[k][l] == 'k' || baza->plansza[k][l] == 'p' || baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 'g')
        {
            koniec->z[0] = i; //bicie bialy-1,-1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }

    if (tryb == -1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'S' || baza->plansza[k][l] == 'H' || baza->plansza[k][l] == 'K' || baza->plansza[k][l] == 'P' || baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'G')
        {
            koniec->z[0] = i; //bicie czarny -1,-1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    k = i + 1;
    l = j - 1;
    while (baza->plansza[k][l] == ' ' && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        koniec->z[0] = i; //ruch +1,-1
        koniec->z[1] = j;
        koniec->d[0] = k;
        koniec->d[1] = l;
        koniec->next = pamiec();
        koniec = koniec->next;
        k = k + 1;
        l = l - 1;
    }
    if (tryb == 1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 's' || baza->plansza[k][l] == 'h' || baza->plansza[k][l] == 'k' || baza->plansza[k][l] == 'p' || baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 'g')
        {
            koniec->z[0] = i; //bicie bialy+1,-1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }

    if (tryb == -1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'S' || baza->plansza[k][l] == 'H' || baza->plansza[k][l] == 'K' || baza->plansza[k][l] == 'P' || baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'G')
        {
            koniec->z[0] = i; //bicie czarny +1,-1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    k = i - 1;
    l = j + 1;
    while (baza->plansza[k][l] == ' ' && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        koniec->z[0] = i; //ruch -1,+1
        koniec->z[1] = j;
        koniec->d[0] = k;
        koniec->d[1] = l;
        koniec->next = pamiec();
        koniec = koniec->next;
        k = k - 1;
        l = l + 1;
    }
    if (tryb == 1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 's' || baza->plansza[k][l] == 'h' || baza->plansza[k][l] == 'k' || baza->plansza[k][l] == 'p' || baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 'g')
        {
            koniec->z[0] = i; //bicie bialy-1,+1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }

    if (tryb == -1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'S' || baza->plansza[k][l] == 'H' || baza->plansza[k][l] == 'K' || baza->plansza[k][l] == 'P' || baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'G')
        {
            koniec->z[0] = i; //bicie czarny -1,+1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    k = i + 1;
    l = j;
    while (baza->plansza[k][l] == ' ' && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        koniec->z[0] = i; //ruch +1,0
        koniec->z[1] = j;
        koniec->d[0] = k;
        koniec->d[1] = l;
        koniec->next = pamiec();
        koniec = koniec->next;
        k = k + 1;
    }
    if (tryb == 1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 's' || baza->plansza[k][l] == 'h' || baza->plansza[k][l] == 'k' || baza->plansza[k][l] == 'p' || baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 'g')
        {
            koniec->z[0] = i; //bicie bialy +1,0
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }

    if (tryb == -1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'S' || baza->plansza[k][l] == 'H' || baza->plansza[k][l] == 'K' || baza->plansza[k][l] == 'P' || baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'G')
        {
            koniec->z[0] = i; //bicie czarny +1,0
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    k = i - 1;
    l = j;
    // printf(" k %d l %d\n", i, j);
    while (baza->plansza[k][l] == ' ' && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        //printf("czy dziala\n");
        koniec->z[0] = i; //ruch -1,0
        koniec->z[1] = j;
        koniec->d[0] = k;
        koniec->d[1] = l;
        koniec->next = pamiec();
        koniec = koniec->next;
        k = k - 1;
    }
    if (tryb == 1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 's' || baza->plansza[k][l] == 'h' || baza->plansza[k][l] == 'k' || baza->plansza[k][l] == 'p' || baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 'g')
        {
            koniec->z[0] = i; //bicie bialy-1,0
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }

    if (tryb == -1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'S' || baza->plansza[k][l] == 'H' || baza->plansza[k][l] == 'K' || baza->plansza[k][l] == 'P' || baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'G')
        {
            koniec->z[0] = i; //bicie czarny -1,0
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    k = i;
    l = j - 1;

    while (baza->plansza[k][l] == ' ' && k < 8 && k >= 0 && l < 8 && l >= 0)
    {

        koniec->z[0] = i; //ruch 0,-1
        koniec->z[1] = j;
        koniec->d[0] = k;
        koniec->d[1] = l;
        koniec->next = pamiec();
        koniec = koniec->next;
        l = l - 1;
    }
    if (tryb == 1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 's' || baza->plansza[k][l] == 'h' || baza->plansza[k][l] == 'k' || baza->plansza[k][l] == 'p' || baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 'g')
        {
            koniec->z[0] = i; //bicie bialy0,-1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }

    if (tryb == -1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'S' || baza->plansza[k][l] == 'H' || baza->plansza[k][l] == 'K' || baza->plansza[k][l] == 'P' || baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'G')
        {
            koniec->z[0] = i; //bicie czarny 0,-1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    k = i;
    l = j + 1;
    while (baza->plansza[k][l] == ' ' && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        koniec->z[0] = i; //ruch 0,+1
        koniec->z[1] = j;
        koniec->d[0] = k;
        koniec->d[1] = l;
        koniec->next = pamiec();
        koniec = koniec->next;
        l = l + 1;
    }
    if (tryb == 1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 's' || baza->plansza[k][l] == 'h' || baza->plansza[k][l] == 'k' || baza->plansza[k][l] == 'p' || baza->plansza[k][l] == 'w' || baza->plansza[k][l] == 'g')
        {
            koniec->z[0] = i; //bicie bialy0,+1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    if (tryb == -1 && k < 8 && k >= 0 && l < 8 && l >= 0)
    {
        if (baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'S' || baza->plansza[k][l] == 'H' || baza->plansza[k][l] == 'K' || baza->plansza[k][l] == 'P' || baza->plansza[k][l] == 'W' || baza->plansza[k][l] == 'G')
        {
            koniec->z[0] = i; //bicie czarny 0,+1
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = l;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    return koniec;
}