#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "gombszoveggel.hpp"
#include "graphics.hpp"

#include <iostream>
using namespace genv;

 SzovegesLenyomhatoWidget::SzovegesLenyomhatoWidget(int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin,std::string szoveg,int szovegmeret):LenyomhatoWidget(x,y,xmeret,ymeret,hatterszin,widgetszin){
    _szoveg=szoveg;
    _szovegmeret=szovegmeret;
 };
 SzovegesLenyomhatoWidget::SzovegesLenyomhatoWidget(int x, int y, int xmeret, int ymeret, Szin widgetszin,std::string szoveg,int szovegmeret):SzovegesLenyomhatoWidget(x,y,xmeret,ymeret,Szin(255,255,255),widgetszin,szoveg,szovegmeret){}
 SzovegesLenyomhatoWidget::SzovegesLenyomhatoWidget(int x, int y, int xmeret, int ymeret,std::string szoveg,int szovegmeret):SzovegesLenyomhatoWidget(x,y,xmeret,ymeret,Szin(0,0,0),szoveg,szovegmeret){}
 SzovegesLenyomhatoWidget::SzovegesLenyomhatoWidget():SzovegesLenyomhatoWidget(0,0,0,0,"",0){}

SzovegesLenyomhatoWidget::SzovegesLenyomhatoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin,std::string szoveg,int szovegmeret):LenyomhatoWidget(ablak,x,y,xmeret,ymeret,hatterszin,widgetszin){
        _szoveg=szoveg;
    _szovegmeret=szovegmeret;
}
 SzovegesLenyomhatoWidget::SzovegesLenyomhatoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin widgetszin,std::string szoveg,int szovegmeret):SzovegesLenyomhatoWidget(ablak,x,y,xmeret,ymeret,Szin(255,255,255),widgetszin,szoveg,szovegmeret){}
 SzovegesLenyomhatoWidget::SzovegesLenyomhatoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret,std::string szoveg,int szovegmeret):SzovegesLenyomhatoWidget(ablak,x,y,xmeret,ymeret,Szin(0,0,0),szoveg,szovegmeret){}

 void SzovegesLenyomhatoWidget::Rajzol() const{
     LenyomhatoWidget::Rajzol();
     SzovegTipusValt(_szovegmeret);
     _widgetszin.szinrevalt();
     gout<<move_to(_x,_y)<<text(_szoveg);
 }

void SzovegesLenyomhatoWidget::ErtekValt(std::string szoveg){
    _szoveg=szoveg;
};

std::string SzovegesLenyomhatoWidget::Ertekvisszaad() const{
    return _szoveg;
}
