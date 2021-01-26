#include "stan_gry_def.h"

int negmax(struct szachownica *sz, int glebokosc, int alfa, int beta)
{

    struct szachownica dziecko;
    int nowaocena;
    if (!glebokosc)
        return ocena(*sz);
    int ocenawezla = -1000;
    for (ruchy *lr = listaruchow(sz, sz->ruch), *ptr = lr; lr; lr = lr->next, free(ptr), ptr = lr)
    {
        //printf("%d%d %d%d %c \n", lr->z[0], lr->z[1], lr->d[0], lr->d[1], lr->promocja);
        dziecko = wykonajruch(*sz, lr);
        //wypisanie(dziecko);
        nowaocena = -negmax(&dziecko, glebokosc - 1, -beta, -alfa);
        if (nowaocena > ocenawezla)
        {
            // printf("czy ocena wezla sie zmienia na co? %d\n", nowaocena);
            ocenawezla = nowaocena;
        }
        if (ocenawezla > alfa)
            alfa = ocenawezla;
        if (alfa > beta)
        {
            zwolnienie_listy(lr);
            //zwolnienie calej listy
            break;
        }
    }
    //printf("lala ma kota %d ruch %d\n", ocenawezla, sz->ruch);
    //wypisanie(&dziecko, Bierki);
    return ocenawezla;
}

ruchy *jakiruch(struct szachownica *sz, int glebokosc, int alfa, int beta)
{
    ruchy *naj = malloc(sizeof(ruchy));
    int maxocena = -100000;
    int nowaocena;
    szachownica test;
    for (ruchy *lr = listaruchow(sz, sz->ruch), *ptr = lr; lr; lr = lr->next, free(ptr), ptr = lr)
    {
        test = wykonajruch(*sz, lr);
        nowaocena = -negmax(&test, glebokosc, alfa, beta);
        if (nowaocena > maxocena)
        {
            naj->z[0] = lr->z[0];
            naj->z[1] = lr->z[1];
            naj->d[0] = lr->d[0];
            naj->d[1] = lr->d[1];
            maxocena = nowaocena;
        }
    }
    return naj;
}

void zwolnienie_listy(ruchy *glowa)
{
    
    while (glowa->next)
    {
        ruchy *next = glowa->next;
        free(glowa);
        glowa = next;
    }
}