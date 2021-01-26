#include "stan_gry_def.h"

//zmienilem enpassant na tablice

ruchy *ruchypiona(int i, int j, ruchy *koniec, szachownica *baza, int kolor)
{
    if (baza->plansza[i + kolor][j] == ' ' && i + kolor < 8 && i + kolor >= 0)
    {
        //printf("%c\n", liczby_na_litery(i));
        //ruch bialego zwykly
        koniec->z[0] = (i);
        koniec->z[1] = j;
        koniec->d[0] = (i + kolor);
        koniec->d[1] = j;
        //printf("czy to dziala\n");
        koniec->next = pamiec();
        if (i + kolor == 7 && kolor == 1) //promocja bialego
        {
            koniec->promocja = 'H';
            koniec = koniec->next;
            koniec->next = pamiec();
            koniec->z[0] = (i);
            koniec->z[1] = j;
            koniec->d[0] = (i + kolor);
            koniec->d[1] = j;
            koniec->promocja = 'S';
            koniec = koniec->next;
            koniec->next = pamiec();
            koniec->z[0] = (i);
            koniec->z[1] = j;
            koniec->d[0] = (i + kolor);
            koniec->d[1] = j;
            koniec->promocja = 'G';
            koniec = koniec->next;
            koniec->next = pamiec();
            koniec->z[0] = (i);
            koniec->z[1] = j;
            koniec->d[0] = (i + kolor);
            koniec->d[1] = j;
            koniec->promocja = 'W';
            koniec = koniec->next;
            koniec->next = pamiec();
            koniec->z[0] = (i);
            koniec->z[1] = j;
            koniec->d[0] = (i + kolor);
            koniec->d[1] = j;
            koniec->promocja = 'K';
        }
        else if (kolor == -1 && i + kolor == 0) //promocja czarnego
        {
            koniec->promocja = 'h';
            koniec = koniec->next;
            koniec->next = pamiec();
            koniec->z[0] = (i);
            koniec->z[1] = j;
            koniec->d[0] = (i + kolor);
            koniec->d[1] = j;
            koniec->promocja = 's';
            koniec = koniec->next;
            koniec->next = pamiec();
            koniec->z[0] = (i);
            koniec->z[1] = j;
            koniec->d[0] = (i + kolor);
            koniec->d[1] = j;
            koniec->promocja = 'g';
            koniec = koniec->next;
            koniec->next = pamiec();
            koniec->z[0] = (i);
            koniec->z[1] = j;
            koniec->d[0] = (i + kolor);
            koniec->d[1] = j;
            koniec->promocja = 'w';
            koniec = koniec->next;
            koniec->next = pamiec();
            koniec->z[0] = (i);
            koniec->z[1] = j;
            koniec->d[0] = (i + kolor);
            koniec->d[1] = j;
            koniec->promocja = 'k';
        }
        koniec = koniec->next;
    }
    //printf("czy to dziala\n");
    if (baza->plansza[i + 2][j] == ' ' && i + kolor < 8 && i == 1 && kolor == 1 && baza->plansza[i + 1][j] == ' ') //przeskok o 2 z pierwszego
    {

        koniec->next = pamiec();
        koniec->z[0] = i;
        koniec->z[1] = j;
        koniec->d[0] = (i + 2);
        koniec->d[1] = j;
        koniec = koniec->next;
    }
    else if (baza->plansza[i - 2][j] == ' ' && i + kolor < 8 && i == 6 && kolor == -1 && baza->plansza[i - 1][j] == ' ')
    {

        koniec->next = pamiec();
        koniec->z[0] = i;
        koniec->z[1] = j;
        koniec->d[0] = (i - 2);
        koniec->d[1] = j;
        koniec = koniec->next;
    }

    if (kolor == 1)
    {
        if (j + kolor < 8 && j - kolor >= 0)
        {
            if (baza->plansza[i + kolor][j + 1] == 'k' || baza->plansza[i + kolor][j + 1] == 'w' || baza->plansza[i + kolor][j + 1] == 's' || baza->plansza[i + kolor][j + 1] == 'g' || baza->plansza[i + kolor][j + 1] == 'h' || baza->plansza[i + kolor][j + 1] == 'p')
            {
                koniec->z[0] = (i); //bicie bialego w prawo
                koniec->z[1] = j;
                koniec->d[0] = (i + kolor);
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                if (i + kolor == 7)
                {
                    koniec->promocja = 'W';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j + 1;
                    koniec->promocja = 'S';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j + 1;
                    koniec->promocja = 'G';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j + 1;
                    koniec->promocja = 'H';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j + 1;
                    koniec->promocja = 'K';
                }
                koniec = koniec->next;
                //printf("essa?\n");
            }
        }
        //printf("%c\n", baza->plansza[i][j]);
    }

    if (kolor == -1)
    {
        if (j - kolor < 8 && j + kolor >= 0)
        {
            if (baza->plansza[i + kolor][j + 1] == 'K' || baza->plansza[i + kolor][j + 1] == 'W' || baza->plansza[i + kolor][j + 1] == 'S' || baza->plansza[i + kolor][j + 1] == 'G' || baza->plansza[i + kolor][j + 1] == 'H' || baza->plansza[i + kolor][j + 1] == 'P')
            {
                koniec->z[0] = (i); //bicie czarnego w prawo
                koniec->z[1] = j;
                koniec->d[0] = (i + kolor);
                koniec->d[1] = j + 1;
                koniec->next = pamiec();
                if (i + kolor == 0)
                {
                    koniec->promocja = 'w';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j + 1;
                    koniec->promocja = 's';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j + 1;
                    koniec->promocja = 'g';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j + 1;
                    koniec->promocja = 'h';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j + 1;
                    koniec->promocja = 'k';
                }
                koniec = koniec->next;
                //printf("essa?\n");
            }
        }
    }
    // printf("czy to dziala\n");
    if (kolor == -1)
    {
        if (j - kolor < 8 && j + kolor >= 0)
        {
            if (baza->plansza[i + kolor][j - 1] == 'K' || baza->plansza[i + kolor][j - 1] == 'W' || baza->plansza[i + kolor][j - 1] == 'S' || baza->plansza[i + kolor][j - 1] == 'G' || baza->plansza[i + kolor][j - 1] == 'H' || baza->plansza[i + kolor][j - 1] == 'P')
            {
                koniec->z[0] = (i); //bicie czarnego w lewo
                koniec->z[1] = j;
                koniec->d[0] = (i + kolor);
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                if (i + kolor == 0)
                {
                    koniec->promocja = 'w';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j - 1;
                    koniec->promocja = 's';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j - 1;
                    koniec->promocja = 'g';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j - 1;
                    koniec->promocja = 'h';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j - 1;
                    koniec->promocja = 'k';
                }
                koniec = koniec->next;
                // printf("essa?\n");
            }
        }
    }
    if (kolor == 1)
    {
        if (j + kolor < 8 && j - kolor >= 0)
        {
            if (baza->plansza[i + kolor][j - 1] == 'k' || baza->plansza[i + kolor][j - 1] == 'w' || baza->plansza[i + kolor][j - 1] == 's' || baza->plansza[i + kolor][j - 1] == 'g' || baza->plansza[i + kolor][j - 1] == 'h' || baza->plansza[i + kolor][j - 1] == 'p')
            {
                koniec->z[0] = (i); //bicie bialego w lewo
                koniec->z[1] = j;
                koniec->d[0] = (i + kolor);
                koniec->d[1] = j - 1;
                koniec->next = pamiec();
                if (i + kolor == 7)
                {
                    koniec->promocja = 'W';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j - 1;
                    koniec->promocja = 'S';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j - 1;
                    koniec->promocja = 'G';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j - 1;
                    koniec->promocja = 'H';
                    koniec = koniec->next;
                    koniec->next = pamiec();
                    koniec->z[0] = (i);
                    koniec->z[1] = j;
                    koniec->d[0] = (i + kolor);
                    koniec->d[1] = j - 1;
                    koniec->promocja = 'K';
                }
                koniec = koniec->next;
                //printf("essa?\n");
            }
        }
    }
    if (baza->enpassant[0] != 100 && baza->enpassant[1] != 100)
    {
        if (i == baza->enpassant[0] && j + 1 == baza->enpassant[1])
        {
            //printf("bicie w loceiw prawo\n");
            koniec->z[0] = (i); //bicie w locie w prawo
            koniec->z[1] = j;
            koniec->d[0] = i + kolor;
            koniec->d[1] = j + 1;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    if (baza->enpassant[0] != 100 && baza->enpassant[1] != 100)
    {
        //printf("zrobilem sie2 %d %d\n", i, j - 1);
        if (i == baza->enpassant[0] && j - 1 == baza->enpassant[1])
        {
            //printf("zrobilem sie\n");
            koniec->z[0] = (i); //bicie w locie w lewo
            koniec->z[1] = j;
            koniec->d[0] = i + kolor;
            koniec->d[1] = j - 1;
            koniec->next = pamiec();
            koniec = koniec->next;
        }
    }
    return koniec;
}