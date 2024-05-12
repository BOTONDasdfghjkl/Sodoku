#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "graphics.hpp"
#include "widgetcsoport.hpp"
#include <functional>
using namespace genv;

Gomb::Gomb(int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin):OsWidget(x,y,xmeret,ymeret,hatterszin,widgetszin){};
Gomb::Gomb(int x, int y, int xmeret, int ymeret, Szin widgetszin):Gomb(x,y,xmeret,ymeret,Szin(255,255,255),widgetszin){};
Gomb::Gomb(int x, int y, int xmeret, int ymeret):Gomb(x,y,xmeret,ymeret,Szin(0,0,0)){};

Gomb::Gomb(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin):OsWidget(ablak,x,y,xmeret,ymeret,hatterszin,widgetszin){};
Gomb::Gomb(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin widgetszin):Gomb(ablak,x,y,xmeret,ymeret,Szin(255,255,255),widgetszin){};
Gomb::Gomb(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret):Gomb(ablak,x,y,xmeret,ymeret,Szin(0,0,0)){};

void Gomb::Rajzol() const{
    HatterRajzol();
}
bool Gomb::Handle(genv::event ev){
    if(ev.type==ev_mouse){
        if(ev.button==btn_left && Hover(ev)){
                _gombnyomas();
            return true;
        }
    }
    return false;
};


void Gomb::SetGombNyomas(std::function<void()> gombnyomas){
    _gombnyomas=gombnyomas;
}
