#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "gombszoveggel.hpp"
#include "graphics.hpp"

#include <iostream>
using namespace genv;

 GombSzoveggel::GombSzoveggel(int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin,std::string szoveg,int szovegmeret):Gomb(x,y,xmeret,ymeret,hatterszin,widgetszin){
    _szoveg=szoveg;
    _szovegmeret=szovegmeret;
 };
 GombSzoveggel::GombSzoveggel(int x, int y, int xmeret, int ymeret, Szin widgetszin,std::string szoveg,int szovegmeret):GombSzoveggel(x,y,xmeret,ymeret,Szin(255,255,255),widgetszin,szoveg,szovegmeret){}
 GombSzoveggel::GombSzoveggel(int x, int y, int xmeret, int ymeret,std::string szoveg,int szovegmeret):GombSzoveggel(x,y,xmeret,ymeret,Szin(0,0,0),szoveg,szovegmeret){}
 GombSzoveggel::GombSzoveggel():GombSzoveggel(0,0,0,0,"",0){}

GombSzoveggel::GombSzoveggel(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin,std::string szoveg,int szovegmeret):Gomb(ablak,x,y,xmeret,ymeret,hatterszin,widgetszin){
        _szoveg=szoveg;
    _szovegmeret=szovegmeret;
}
 GombSzoveggel::GombSzoveggel(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin widgetszin,std::string szoveg,int szovegmeret):GombSzoveggel(ablak,x,y,xmeret,ymeret,Szin(255,255,255),widgetszin,szoveg,szovegmeret){}
 GombSzoveggel::GombSzoveggel(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret,std::string szoveg,int szovegmeret):GombSzoveggel(ablak,x,y,xmeret,ymeret,Szin(0,0,0),szoveg,szovegmeret){}

 void GombSzoveggel::Rajzol() const{
     Gomb::Rajzol();
     SzovegTipusValt(_szovegmeret);
     _widgetszin.szinrevalt();
     gout<<move_to(_x,_y)<<text(_szoveg);
 }

void GombSzoveggel::ErtekValt(std::string szoveg){
    _szoveg=szoveg;
};

std::string GombSzoveggel::Ertekvisszaad() const{
    return _szoveg;
}
