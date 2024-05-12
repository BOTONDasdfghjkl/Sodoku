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


Window::Window(int x, int y):WidgetCsoport(0,0,x,y,Szin(0,149,138),Szin(255,255,255)){

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
