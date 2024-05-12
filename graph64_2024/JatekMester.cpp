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
const int KICSINEGYZET=SODOKUMERET*SODOKUMERET;
const int NAGYNEGYZET=KICSINEGYZET*KICSINEGYZET;

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
    _HatterElemek=new LenyomhatoWidget*[4];
    const int vonalmeret=3*SODOKUMERET*(SZAMOSGOMBOKMERETE+10)-10;
    const Szin kekszin(51,51,255);
    _HatterElemek[1]=new LenyomhatoWidget(_SodokuJatek,100+3*(SZAMOSGOMBOKMERETE+10)-10,200,10,vonalmeret,kekszin,Szin(0,0,0));
    _HatterElemek[2]=new LenyomhatoWidget(_SodokuJatek,100+6*(SZAMOSGOMBOKMERETE+10)-10,200,10,vonalmeret,kekszin,Szin(0,0,0));
    _HatterElemek[3]=new LenyomhatoWidget(_SodokuJatek,100,200+3*(SZAMOSGOMBOKMERETE+10)-10,vonalmeret,10,kekszin,Szin(0,0,0));
    _HatterElemek[4]=new LenyomhatoWidget(_SodokuJatek,100,200+6*(SZAMOSGOMBOKMERETE+10)-10,vonalmeret,10,kekszin,Szin(0,0,0));

    _MenuGomb=new SzovegesLenyomhatoWidget(_SodokuJatek,10,10,140,20,"To the main menu",16);
    _MenuGomb->SetGombNyomas([&](){_SodokuJatek->Eventvege();});
    _HibakszamaFelirat=new SzovegesLenyomhatoWidget(_SodokuJatek,450,10,0,0,_HibakSzamaszovege(),16);

    _ErtekKivalasztok=new SzovegesLenyomhatoWidget*[KICSINEGYZET];
    for (int i=0;i<KICSINEGYZET;i++){
        _ErtekKivalasztok[i]=new SzovegesLenyomhatoWidget(_SodokuJatek,100+i*(SZAMOSGOMBOKMERETE+10),600,SZAMOSGOMBOKMERETE,SZAMOSGOMBOKMERETE,std::to_string(i+1),SZAMOSGOMBOKMERETE);
        _ErtekKivalasztok[i]->SetGombNyomas([i,this](){_gombnyomaserteke=(i+1);});
    }
    _SodokuPalya=new SzovegesLenyomhatoWidget*[NAGYNEGYZET];
    int ind=0;
    for(int Y=0;Y<SODOKUMERET;Y++){
        for(int X=0;X<SODOKUMERET;X++){
            for(int y=0;y<SODOKUMERET;y++){
                for(int x=0;x<SODOKUMERET;x++){
                        _SodokuPalya[ind]=new SzovegesLenyomhatoWidget(_SodokuJatek,100+(x+SODOKUMERET*X)*(SZAMOSGOMBOKMERETE+10),200+(y+SODOKUMERET*Y)*(SZAMOSGOMBOKMERETE+10),SZAMOSGOMBOKMERETE,SZAMOSGOMBOKMERETE,"",SZAMOSGOMBOKMERETE);
                        _SodokuPalya[ind]->SetGombNyomas([Y,X,y,x,ind,this](){std::cout<<std::to_string(ind);});
                        ind++;
                }
            }
        }
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
