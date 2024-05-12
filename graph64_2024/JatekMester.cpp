#include "graphics.hpp"
#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "gombszoveggel.hpp"
#include "szamosWidget.hpp"
#include "kivalasztoWidget.hpp"
#include "widgetcsoport.hpp"
#include "window.hpp"
#include "JatekMester.hpp"

using namespace genv;

const int XXkepernyomeret=500;
const int YYkepernyomeret=700;

JatekMester::JatekMester(){
    gout.open(XXkepernyomeret,YYkepernyomeret);
    _MenuSzerkezet=new Window(XXkepernyomeret,YYkepernyomeret);
    _SodokuFelirat=new GombSzoveggel(_MenuSzerkezet,20,20,0,0,Szin(0,0,0),"Sodoku",130);
    _StartGomb=new GombSzoveggel(_MenuSzerkezet, 200,300,100,50,"Start",40);
    _StartGomb->SetGombNyomas([&](){_MenuSzerkezet->Eventvege();});
}

void JatekMester::Start(){
    _MenuSzerkezet->EventLoop();
}
