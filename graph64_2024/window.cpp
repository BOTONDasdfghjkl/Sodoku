#include "graphics.hpp"
#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "gombszoveggel.hpp"
#include "szamosWidget.hpp"
#include "kivalasztoWidget.hpp"
#include "widgetcsoport.hpp"
#include "window.hpp"

#include "fstream"

using namespace genv;


Window::Window(int x, int y):WidgetCsoport(0,0,x,y,Szin(0,149,138),Szin(255,255,255)){
    gombinennoda=new GombSzoveggel(this,250,100,40,40,"->",25);
    gombonnanide=new GombSzoveggel(this,300,100,40,40,"<-",25);
    itt=new KivalasztoWidget(this,100,100,120,40,{"Sanyi","Jani","Ember","Urleny"},4);
    ott=new KivalasztoWidget(this,350,100,120,40,{"Lilla","Anna","Alma","Cucc"},4);
    gombinennoda->SetGombNyomas([&](){std::string st=itt->Ertekvisszaad(); if(st!=""){ott->ElemHozzaad(st);}itt->IndexTorol();});
    gombonnanide->SetGombNyomas([&](){std::string st=ott->Ertekvisszaad(); if(st!=""){itt->ElemHozzaad(st);}ott->IndexTorol();});
}


void Window::EventLoop(){
    Rajzol();
    gout << refresh;

    event ev;
    while(gin>>ev&&ev.keycode!=key_escape){
            if(ev.type==ev_mouse||ev.type==ev_key){
                    Handle(ev);
            }


            Rajzol();
        gout << refresh;
    }}

 void Window::Innenoda(){
    ott->ElemHozzaad(itt->Ertekvisszaad());
    itt->IndexTorol();
}
 void Window::Onnanide(){
    itt->ElemHozzaad(ott->Ertekvisszaad());
    ott->IndexTorol();
}
