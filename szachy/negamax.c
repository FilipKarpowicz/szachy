#include "stan_gry_def.h"

int negmax(struct szachownica *sz, int glebokosc, int alfa, int beta)
{
    //printf("start\n");
    struct szachownica dziecko;
    int nowaocena;
    if (glebokosc == 0)
        return ocena(*sz);
    int ocenawezla = -1000;
    for (ruchy *lr = listaruchow(sz, sz->ruch), *ptr = lr; lr; lr = lr->next, free(ptr), ptr = lr)
    {
        //printf("%d%d %d%d %c \n", lr->z[0], lr->z[1], lr->d[0], lr->d[1], lr->promocja);
        dziecko = wykonajruch(*sz, lr);
        //wypisanie(dziecko);
        nowaocena = -negmax(&dziecko, glebokosc - 1, -beta, -alfa);
        if (nowaocena > ocenawezla)
            ocenawezla = nowaocena;
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
    //wypisanie(dziecko);
    return ocenawezla;
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