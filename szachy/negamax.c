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

int najlepszy_ruch1(struct szachownica *sz, int glebokosc, int alfa, int beta)
{
    //int najlepruch[4];
    int nowaocena[1024];
    int naj_ruch[4096];
    int i = -1;
    int j = 0;
    int maxocena;
    for (ruchy *lr = listaruchow(sz, sz->ruch); lr; lr = lr->next)
    {
        //printf("ruchy:%d%d %d%d\n",lr->z[0], lr->z[1], lr->d[0], lr->d[1]);
        i = i + 1;
        szachownica dziecko = wykonajruch(*sz, lr);
        nowaocena[i] = -negmax(&dziecko, glebokosc, alfa, beta);
        naj_ruch[i] = lr->z[0];
        naj_ruch[i + 1] = lr->z[1];
        naj_ruch[i + 2] = lr->d[0];
        naj_ruch[i + 3] = lr->d[1];
        //printf("naj_ruch[%d]=%d%d %d%d\n",i,naj_ruch[i],naj_ruch[i+1],naj_ruch[i+2],naj_ruch[i+3]);
    }
    //printf("\ni:%d\n",i);
    j = i;
    maxocena = nowaocena[i];
    for (i; i >= 0; i = i - 1)
    {
        printf("nowaocena[%d]=%d\n", i, nowaocena[i]);
        if (maxocena < nowaocena[i])
        {
            //printf("i=%d\n",i);
            printf("naj_ruch[%d]=%d\n", i, naj_ruch[i]);
            j = naj_ruch[i];
            maxocena = nowaocena[i + 1];
            printf("wieksze j: %d\n", j);
        }
    }

    return j;
}

int najlepszy_ruch2(struct szachownica *sz, int glebokosc, int alfa, int beta)
{
    //int najlepruch[4];
    int nowaocena[1024];
    int naj_ruch[4096];
    int i = -1;
    int k = 0;
    int maxocena;
    for (ruchy *lr = listaruchow(sz, sz->ruch); lr; lr = lr->next)
    {
        //printf("ruchy:%d%d %d%d\n",lr->z[0], lr->z[1], lr->d[0], lr->d[1]);
        i = i + 1;
        szachownica dziecko = wykonajruch(*sz, lr);
        nowaocena[i] = -negmax(&dziecko, glebokosc, alfa, beta);
        naj_ruch[i] = lr->z[0];
        naj_ruch[i + 1] = lr->z[1];
        naj_ruch[i + 2] = lr->d[0];
        naj_ruch[i + 3] = lr->d[1];
        //printf("naj_ruch[%d]=%d%d %d%d\n",i,naj_ruch[i],naj_ruch[i+1],naj_ruch[i+2],naj_ruch[i+3]);
    }
    //printf("\ni:%d\n",i);
    k = i;
    maxocena = nowaocena[i];
    for (i; i >= 0; i = i - 1)
    {
        printf("nowaocena[%d]=%d\n", i, nowaocena[i]);
        if (maxocena < nowaocena[i])
        {
            printf("i=%d\n", i);
            printf("naj_ruch[%d]=%d\n", i, naj_ruch[i]);
            k = naj_ruch[i + 1];
            maxocena = nowaocena[i + 1];
            printf("wieksze j: %d\n", k);
        }
    }

    return k;
}

int najlepszy_ruch3(struct szachownica *sz, int glebokosc, int alfa, int beta)
{
    //int najlepruch[4];
    int nowaocena[1024];
    int naj_ruch[4096];
    int i = -1;
    int l = 0;
    int maxocena;
    for (ruchy *lr = listaruchow(sz, sz->ruch); lr; lr = lr->next)
    {
        //printf("ruchy:%d%d %d%d\n",lr->z[0], lr->z[1], lr->d[0], lr->d[1]);
        i = i + 1;
        szachownica dziecko = wykonajruch(*sz, lr);
        nowaocena[i] = -negmax(&dziecko, glebokosc, alfa, beta);
        naj_ruch[i] = lr->z[0];
        naj_ruch[i + 1] = lr->z[1];
        naj_ruch[i + 2] = lr->d[0];
        naj_ruch[i + 3] = lr->d[1];
        //printf("naj_ruch[%d]=%d%d %d%d\n",i,naj_ruch[i],naj_ruch[i+1],naj_ruch[i+2],naj_ruch[i+3]);
    }
    printf("\ni:%d\n", i);
    l = i;
    maxocena = nowaocena[i];
    for (i; i >= 0; i = i - 1)
    {
        printf("nowaocena[%d]=%d\n", i, nowaocena[i]);
        if (maxocena < nowaocena[i])
        {
            printf("i=%d\n", i);
            printf("naj_ruch[%d]=%d\n", i, naj_ruch[i + 2]);
            l = naj_ruch[i + 2];
            maxocena = nowaocena[i + 1];
            printf("wieksze j: %d\n", l);
        }
    }

    return l;
}

int najlepszy_ruch4(struct szachownica *sz, int glebokosc, int alfa, int beta)
{
    //int najlepruch[4];
    int nowaocena[1024];
    int naj_ruch[4096];
    int i = -1;
    int m = 0;
    int maxocena;
    for (ruchy *lr = listaruchow(sz, sz->ruch); lr; lr = lr->next)
    {
        //printf("ruchy:%d%d %d%d\n",lr->z[0], lr->z[1], lr->d[0], lr->d[1]);
        i = i + 1;
        szachownica dziecko = wykonajruch(*sz, lr);
        nowaocena[i] = -negmax(&dziecko, glebokosc, alfa, beta);
        naj_ruch[i] = lr->z[0];
        naj_ruch[i + 1] = lr->z[1];
        naj_ruch[i + 2] = lr->d[0];
        naj_ruch[i + 3] = lr->d[1];
        //printf("naj_ruch[%d]=%d%d %d%d\n",i,naj_ruch[i],naj_ruch[i+1],naj_ruch[i+2],naj_ruch[i+3]);
    }
    //printf("\ni:%d\n",i);
    m = i;
    maxocena = nowaocena[i];
    for (i; i >= 0; i = i - 1)
    {
        printf("nowaocena[%d]=%d\n", i, nowaocena[i]);
        if (maxocena < nowaocena[i])
        {
            printf("i=%d\n", i);
            printf("naj_ruch[%d]=%d\n", i, naj_ruch[i + 3]);
            m = naj_ruch[i + 3];
            maxocena = nowaocena[i + 1];
            printf("wieksze j: %d\n", m);
        }
    }

    return m;
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