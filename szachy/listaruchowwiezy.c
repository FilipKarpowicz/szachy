#include "stan_gry_def.h"

ruchy *ruchywiezy(int i, int j, ruchy *koniec, szachownica *baza, int tryb)
{
    int k = i + tryb;
    while (baza->plansza[k][j] == ' ' && k < 8 && k >= 0)
    {
        koniec->z[0] = i; //ruchy w pionie gora
        koniec->z[1] = j;
        koniec->d[0] = k;
        koniec->d[1] = j;
        koniec->next = pamiec();
        koniec = koniec->next;
        k = k + tryb;
    }
    if (tryb == 1 && k < 8 && k >= 0)
    {
        if (baza->plansza[k][j] == 'w' || baza->plansza[k][j] == 's' || baza->plansza[k][j] == 'h' || baza->plansza[k][j] == 'k' || baza->plansza[k][j] == 'p' || baza->plansza[k][j] == 'w' || baza->plansza[k][j] == 'g')
        {
            koniec->z[0] = i; //bicie bialych w pionie gora
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = j;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    if (tryb == -1 && k < 8 && k >= 0)
    {
        if (baza->plansza[k][j] == 'W' || baza->plansza[k][j] == 'S' || baza->plansza[k][j] == 'H' || baza->plansza[k][j] == 'K' || baza->plansza[k][j] == 'P' || baza->plansza[k][j] == 'W' || baza->plansza[k][j] == 'G')
        {
            koniec->z[0] = i; //bicie czarnych w pionie gora
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = j;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    k = i - tryb;
    while (baza->plansza[k][j] == ' ' && k < 8 && k >= 0)
    {
        koniec->z[0] = i; //ruchy w pionie dol
        koniec->z[1] = j;
        koniec->d[0] = k;
        koniec->d[1] = j;
        koniec->next = pamiec();
        koniec = koniec->next;
        k = k - tryb;
    }
    if (tryb == 1 && k < 8 && k >= 0)
    {
        if (baza->plansza[k][j] == 'w' || baza->plansza[k][j] == 's' || baza->plansza[k][j] == 'h' || baza->plansza[k][j] == 'k' || baza->plansza[k][j] == 'p' || baza->plansza[k][j] == 'w' || baza->plansza[k][j] == 'g')
        {
            koniec->z[0] = i; //bicie bialych w pionie dol
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = j;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    if (tryb == -1 && k < 8 && k >= 0)
    {
        if (baza->plansza[k][j] == 'W' || baza->plansza[k][j] == 'S' || baza->plansza[k][j] == 'H' || baza->plansza[k][j] == 'K' || baza->plansza[k][j] == 'P' || baza->plansza[k][j] == 'W' || baza->plansza[k][j] == 'G')
        {
            koniec->z[0] = i; //bicie czarnych w pionie dol
            koniec->z[1] = j;
            koniec->d[0] = k;
            koniec->d[1] = j;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    k = j - 1;
    while (baza->plansza[i][k] == ' ' && k < 8 && k >= 0)
    {
        koniec->z[0] = i; //ruchy w poziomie w lewo
        koniec->z[1] = j;
        koniec->d[0] = i;
        koniec->d[1] = k;
        koniec->next = pamiec();
        koniec = koniec->next;
        k = k - 1;
    }
    if (tryb == -1 && k < 8 && k >= 0)
    {
        if (baza->plansza[i][k] == 'W' || baza->plansza[i][k] == 'S' || baza->plansza[i][k] == 'H' || baza->plansza[i][k] == 'K' || baza->plansza[i][k] == 'P' || baza->plansza[i][k] == 'W' || baza->plansza[i][k] == 'G')
        {
            koniec->z[0] = i; //bicie w lewo czarnych
            koniec->z[1] = j;
            koniec->d[0] = i;
            koniec->d[1] = k;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    if (tryb == 1 && k < 8 && k >= 0)
    {
        if (baza->plansza[i][k] == 'w' || baza->plansza[i][k] == 's' || baza->plansza[i][k] == 'h' || baza->plansza[i][k] == 'k' || baza->plansza[i][k] == 'p' || baza->plansza[i][k] == 'w' || baza->plansza[i][k] == 'g')
        {
            koniec->z[0] = i; //bicie w lewo bialych
            koniec->z[1] = j;
            koniec->d[0] = i;
            koniec->d[1] = k;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    k = j + 1;
    while (baza->plansza[i][k] == ' ' && k < 8 && k >= 0)
    {
        koniec->z[0] = i;
        koniec->z[1] = j;
        koniec->d[0] = i;
        koniec->d[1] = k;
        koniec->next = pamiec();
        koniec = koniec->next;
        k = k + 1;
    }
    if (tryb == -1 && k < 8 && k >= 0)
    {
        if (baza->plansza[i][k] == 'W' || baza->plansza[i][k] == 'S' || baza->plansza[i][k] == 'H' || baza->plansza[i][k] == 'K' || baza->plansza[i][k] == 'P' || baza->plansza[i][k] == 'W' || baza->plansza[i][k] == 'G')
        {
            koniec->z[0] = i; //bicie w prawo czarnych
            koniec->z[1] = j;
            koniec->d[0] = i;
            koniec->d[1] = k;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    if (tryb == 1 && k < 8 && k >= 0)
    {
        if (baza->plansza[i][k] == 'w' || baza->plansza[i][k] == 's' || baza->plansza[i][k] == 'h' || baza->plansza[i][k] == 'k' || baza->plansza[i][k] == 'p' || baza->plansza[i][k] == 'w' || baza->plansza[i][k] == 'g')
        {
            koniec->z[0] = i; //bicie w prawo bialych
            koniec->z[1] = j;
            koniec->d[0] = i;
            koniec->d[1] = k;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    return koniec;
}