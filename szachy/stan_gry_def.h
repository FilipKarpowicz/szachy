#ifndef STAN_GRY
#define STAN_GRY

typedef struct szachownica
{
    char plansza[8][8]; //biale duze ;male czarne
    int enpassant[2];   //miejsce w ktorym stoi pionek ktory "mozna zbic tym sposobem"
    int ruch;           //czyj ruch 1 -> biale , -1 -> czarne
    int roszada[2][3];  //pierwsza liczba oznacza kolor 0- bialy 1-czarny druga liczba to
    //roszada 0 to lewa 1 to prawa patrzac od gory wartosc 1 to znaczy ze moze byc 0 to nie moze
    int ile_ruchow;
    int x, y; //zaznaczone pole

} szachownica;

typedef struct _glowalisty
{
    struct _ruchy *glowa;
} glowalisty;

typedef struct _ruchy
{
    int z[2];
    int d[2];
    char promocja;
    char roszada;
    struct _ruchy *next;
} ruchy;

ruchy *ruchypiona(int i, int j, ruchy *koniec, szachownica *baza, int kolor); //tryb 1->biale -1->czarne
ruchy *ruchywiezy(int i, int j, ruchy *koniec, szachownica *baza, int tryb);
ruchy *ruchygonca(int i, int j, ruchy *koniec, szachownica *baza, int tryb);
ruchy *ruchyhetmana(int i, int j, ruchy *koniec, szachownica *baza, int tryb);
ruchy *ruchykrola(int i, int j, ruchy *koniec, szachownica *baza, int tryb);
ruchy *ruchyskoczka(int i, int j, ruchy *koniec, szachownica *baza, int tryb);
ruchy *pamiec();
ruchy *listaruchow(szachownica *plansza, int kolor);
struct szachownica wykonajruch(struct szachownica gra, ruchy *lr);
int negmax(struct szachownica *sz, int glebokosc, int alfa, int beta);
int ocena(struct szachownica gra);
void zwolnienie_listy(ruchy *glowa);
void wypisanie(struct szachownica plansza);
void wypiszliste(ruchy *glowa);
int sumabierek(struct szachownica *gra);

#include <stdlib.h>
#include <stdio.h>

#endif