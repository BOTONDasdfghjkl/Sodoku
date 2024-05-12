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

    //Menu elkészítése
    _menjenajatek=true;
    _MenuSzerkezet=new Window(XXkepernyomeret,YYkepernyomeret);
    _SodokuFelirat=new SzovegesLenyomhatoWidget(_MenuSzerkezet,20,20,0,0,Szin(0,0,0),"Sodoku",130);
    _StartGomb=new SzovegesLenyomhatoWidget(_MenuSzerkezet, 200,300,100,50,"Start",40);
    _StartGomb->SetGombNyomas([&](){_MenuSzerkezet->Eventvege();_menjenajatek=true;});
    _Kilepes=new SzovegesLenyomhatoWidget(_MenuSzerkezet, 200,400,100,50,"Quit",40);
    _Kilepes->SetGombNyomas([&](){_MenuSzerkezet->Eventvege();_menjenajatek=false;});

    //Jatek elkeszitese
    _SodokuJatek=new Window(XXkepernyomeret,YYkepernyomeret);
    _MenuGomb=new SzovegesLenyomhatoWidget(_SodokuJatek,10,10,130,20,"To the main menu",16);
    _MenuGomb->SetGombNyomas([&](){_SodokuJatek->Eventvege();});


}

void JatekMester::Start(){
    _MenuSzerkezet->EventLoop();
    while(_menjenajatek){
        _SodokuJatek->EventLoop();
        _menjenajatek=false;
        _MenuSzerkezet->EventLoop();
    }
}
