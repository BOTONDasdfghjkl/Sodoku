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

#include "iostream"
using namespace genv;

const int XXkepernyomeret=500;
const int YYkepernyomeret=700;
const int MAXHIBAK=10;
const int SODOKUMERET=3; //3*3 kicsi négyzet (3*3)*(3*3) az egész pálya
const int SZAMOSGOMBOKMERETE=20;
const int ERTEKBEALLITASHOZ=SODOKUMERET*SODOKUMERET;
const int SZAMOK[9]={1,2,3,4,5,6,7,8,9};

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
    _elkovetetthibak=0;
    _gombnyomaserteke=1;
    _SodokuJatek=new Window(XXkepernyomeret,YYkepernyomeret);
    _MenuGomb=new SzovegesLenyomhatoWidget(_SodokuJatek,10,10,140,20,"To the main menu",16);
    _MenuGomb->SetGombNyomas([&](){_SodokuJatek->Eventvege();});
    _HibakszamaFelirat=new SzovegesLenyomhatoWidget(_SodokuJatek,450,10,0,0,_HibakSzamaszovege(),16);

    _ErtekKivalasztok=new SzovegesLenyomhatoWidget*[ERTEKBEALLITASHOZ];
    for (int i=0;i<ERTEKBEALLITASHOZ;i++){
        _ErtekKivalasztok[i]=new SzovegesLenyomhatoWidget(_SodokuJatek,100+i*(SZAMOSGOMBOKMERETE+10),600,SZAMOSGOMBOKMERETE,SZAMOSGOMBOKMERETE,std::to_string(i+1),SZAMOSGOMBOKMERETE);
        _ErtekKivalasztok[i]->SetGombNyomas([i,this](){_gombnyomaserteke=(i+1);});
    }


}

void JatekMester::Start(){
    _MenuSzerkezet->EventLoop();
    while(_menjenajatek){
        _elkovetetthibak=0;
        _SodokuJatek->EventLoop();
        _menjenajatek=false;
        _MenuSzerkezet->EventLoop();
    }
}

std::string JatekMester::_HibakSzamaszovege(){
    return std::to_string(_elkovetetthibak)+"/"+std::to_string(MAXHIBAK);
}
