#ifndef STAN_GRY
#define STAN_GRY

typedef struct szachownica
{
    char plansza[8][8];
    short int enpassant;
    int ruch;
    int roszada[2][3];

} szachownica;
#endif