#include "graphics.hpp"
#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "gombszoveggel.hpp"
#include "szamosWidget.hpp"
#include "kivalasztoWidget.hpp"
#include "widgetcsoport.hpp"
#include "window.hpp"


using namespace genv;



Window::Window(int x, int y):WidgetCsoport(0,0,x,y,Szin(192,192,192),Szin(255,255,255)){
    _eventvege=false;
}
Window::Window():Window(0,0){}


void Window::EventLoop(){
    _eventvege=false;
    Rajzol();
    gout << refresh;

    event ev;
    while(gin>>ev&&ev.keycode!=key_escape&&!_eventvege){
            if(ev.type==ev_mouse||ev.type==ev_key){
                    Handle(ev);
            }
            Rajzol();
        gout << refresh;
    }}
void Window::Eventvege(){
    _eventvege=true;
}
