#include "stan_gry_def.h"

int czy_szachowane(szachownica *mapa, int y, int x)
{
    ruchy *glowa;
    printf("czy to dziala2\n");
    wypiszliste(glowa);
    ruchy *ptr = glowa;
    while (glowa)
    {
        if (glowa->d[0] == y && glowa->d[1] == x)
            return 1;
        glowa = glowa->next;
    }
    zwolnienie_listy(ptr);
    return 0;
}