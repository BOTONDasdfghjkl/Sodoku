#ifndef EGYEBSTRUCTOK_HPP_INCLUDED
#define EGYEBSTRUCTOK_HPP_INCLUDED

#include "graphics.hpp"

struct Szin{
    int r, g, b;
    //Constructorok
    Szin(int dr, int dg, int db);
    //feketere allit
    Szin();

    //be�ll�tja a gout sz�n�t
    void szinrevalt() const;
    //�t�ll�tja a struct szineit
    void szintvaltoztaterre(int dr, int dg, int db);
};

void SzovegTipusValt(int meret);

#endif // EGYEBSTRUCTOK_HPP_INCLUDED
