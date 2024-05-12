#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "graphics.hpp"
#include "widgetcsoport.hpp"
#include <functional>
using namespace genv;

LenyomhatoWidget::LenyomhatoWidget(int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin):OsWidget(x,y,xmeret,ymeret,hatterszin,widgetszin){
    _gombnyomas=[](){};
};
LenyomhatoWidget::LenyomhatoWidget(int x, int y, int xmeret, int ymeret, Szin widgetszin):LenyomhatoWidget(x,y,xmeret,ymeret,Szin(255,255,255),widgetszin){};
LenyomhatoWidget::LenyomhatoWidget(int x, int y, int xmeret, int ymeret):LenyomhatoWidget(x,y,xmeret,ymeret,Szin(0,0,0)){};
 LenyomhatoWidget::LenyomhatoWidget():LenyomhatoWidget(0,0,0,0){}

LenyomhatoWidget::LenyomhatoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin):OsWidget(ablak,x,y,xmeret,ymeret,hatterszin,widgetszin){
        _gombnyomas=[](){};
};
LenyomhatoWidget::LenyomhatoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin widgetszin):LenyomhatoWidget(ablak,x,y,xmeret,ymeret,Szin(255,255,255),widgetszin){};
LenyomhatoWidget::LenyomhatoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret):LenyomhatoWidget(ablak,x,y,xmeret,ymeret,Szin(0,0,0)){};

void LenyomhatoWidget::Rajzol() const{
    HatterRajzol();
}
bool LenyomhatoWidget::Handle(genv::event ev){
    if(ev.type==ev_mouse){
        if(ev.button==btn_left && Hover(ev)){
                _gombnyomas();
            return true;
        }
    }
    return false;
};


void LenyomhatoWidget::SetGombNyomas(std::function<void()> gombnyomas){
    _gombnyomas=gombnyomas;
}
