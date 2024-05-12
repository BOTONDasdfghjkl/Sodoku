#include "graphics.hpp"
#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "gombszoveggel.hpp"
#include "szamosWidget.hpp"
#include "widgetcsoport.hpp"
#include <vector>



using namespace genv;

    WidgetCsoport::WidgetCsoport(int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin):OsWidget( x,  y,  xmeret,  ymeret,  hatterszin,  widgetszin){
        kivalasztott=nullptr;
    };
    WidgetCsoport::WidgetCsoport(int x, int y, int xmeret, int ymeret, Szin widgetszin):OsWidget( x,  y,  xmeret,  ymeret,  widgetszin){};
    WidgetCsoport::WidgetCsoport(int x, int y, int xmeret, int ymeret):OsWidget( x,  y,  xmeret,  ymeret){};

    WidgetCsoport::WidgetCsoport(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin):OsWidget(ablak, x,  y,  xmeret,  ymeret,  hatterszin,  widgetszin){
        kivalasztott=nullptr;
    };
    WidgetCsoport::WidgetCsoport(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin widgetszin):OsWidget(ablak, x,  y,  xmeret,  ymeret,  widgetszin){};
    WidgetCsoport::WidgetCsoport(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret):OsWidget(ablak, x,  y,  xmeret,  ymeret){};

void WidgetCsoport::AddWidget(OsWidget* wid){

    widgetek.push_back(wid);
}
void WidgetCsoport::RemoveWidget(int ind){
    delete widgetek[ind];
    widgetek.erase(widgetek.begin()+ind);
}

void WidgetCsoport::Rajzol() const{
    HatterRajzol();
    for (OsWidget * w : widgetek) {
        w->Rajzol();
    }
}

bool WidgetCsoport::Handle(event ev){
    if(ev.type==ev_mouse){
            for (OsWidget * w : widgetek) {
                if(w->Handle(ev)){
                    kivalasztott=w;
                    return true;
                }
        }
    }else if(ev.type==ev_key&&kivalasztott!=nullptr){
        kivalasztott->Handle(ev);
    }
    return false;
};
