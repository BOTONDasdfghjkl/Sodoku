#include "egyebstructok.hpp"
#include "graphics.hpp"
using namespace genv;

Szin::Szin(int dr, int dg, int db){
    szintvaltoztaterre(dr,dg,db);
}
Szin::Szin(){
    szintvaltoztaterre(0,0,0);
}
void Szin::szinrevalt() const{
    gout<<color(r,g,b);
}
void Szin::szintvaltoztaterre(int dr, int dg, int db){
    r=dr;
    g=dg;
    b=db;
}

void SzovegTipusValt(int meret){
        gout.load_font("LiberationSans-Regular.ttf", meret);
}
