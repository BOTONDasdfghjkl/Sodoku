#include "egyebstructok.hpp"
#include "graphics.hpp"
#include "oswidget.hpp"
#include "widgetcsoport.hpp"
using namespace genv;

OsWidget::OsWidget(int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin){
    _x=x;
    _y=y;
    _xmeret=xmeret;
    _ymeret=ymeret;
    _hatterszin=hatterszin;
    _widgetszin=widgetszin;
}
OsWidget::OsWidget(int x, int y, int xmeret, int ymeret, Szin widgetszin):OsWidget(x,y,xmeret,ymeret,Szin(0,0,0),widgetszin){}
OsWidget::OsWidget(int x, int y, int xmeret, int ymeret):OsWidget(x,y,xmeret,ymeret,Szin(0,0,0),Szin(255,255,255)){}


OsWidget::OsWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin):OsWidget(x,y,xmeret,ymeret,hatterszin,widgetszin){
    ablak->AddWidget(this);
}
OsWidget::OsWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin widgetszin):OsWidget(ablak,x,y,xmeret,ymeret,Szin(0,0,0),widgetszin){}
OsWidget::OsWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret):OsWidget(ablak,x,y,xmeret,ymeret,Szin(0,0,0),Szin(255,255,255)){}

void OsWidget::HatterRajzol() const{
    _hatterszin.szinrevalt();
    gout<<move_to(_x,_y)<<box(_xmeret,_ymeret);
}
void OsWidget::HatterSzinValt(Szin hatterszin){
    _hatterszin=hatterszin;
}
void OsWidget::EloSzinValt(Szin widgetszin){
    _widgetszin=widgetszin;
}

bool OsWidget::Hover(genv::event ev){
    return (ev.pos_x>_x && ev.pos_x<_x+_xmeret)&&(ev.pos_y>_y && ev.pos_y<_y+_ymeret);
}
