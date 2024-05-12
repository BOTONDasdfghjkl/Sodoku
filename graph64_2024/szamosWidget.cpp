#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "gombszoveggel.hpp"
#include "graphics.hpp"
#include "szamosWidget.hpp"
#include "climits"
using namespace genv;

SzamosWidget::SzamosWidget(int x, int y, int xmeret, int ymeret,Szin hatter, Szin karakterszin, int maximum, int minimum):OsWidget(x,y,xmeret,ymeret,hatter,karakterszin){
    _SetErtekek(maximum,minimum);
    _SetGombok();
}
SzamosWidget::SzamosWidget(int x, int y, int xmeret, int ymeret, Szin karakterszin, int maximum, int minimum):SzamosWidget(x,y,xmeret,ymeret,Szin(0,0,0),karakterszin,maximum,minimum){}
SzamosWidget::SzamosWidget(int x, int y, int xmeret, int ymeret, int maximum, int minimum):SzamosWidget(x,y,xmeret,ymeret,Szin(255,255,255),maximum,minimum){}

SzamosWidget::SzamosWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret,Szin hatter, Szin karakterszin, int maximum, int minimum):OsWidget(ablak,x,y,xmeret,ymeret,hatter,karakterszin){
    _SetErtekek(maximum,minimum);
    _SetGombok();
}
SzamosWidget::SzamosWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin karakterszin, int maximum, int minimum):SzamosWidget(ablak,x,y,xmeret,ymeret,Szin(0,0,0),karakterszin,maximum,minimum){}
SzamosWidget::SzamosWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, int maximum, int minimum):SzamosWidget(ablak,x,y,xmeret,ymeret,Szin(255,255,255),maximum,minimum){}


void SzamosWidget::_SetErtekek(int maximum, int minimum){
    _ertekszovegmeret=_ymeret;
    if(maximum<0){
        _ertek=maximum;
    }else if(minimum>0){
        _ertek=minimum;
    }else{
        _ertek=0;
    }

    _maxertek=maximum;
    _minertek=minimum;
}

void SzamosWidget::_SetGombok(){
    int gombmeret=_ymeret/2;
    _plusz=SzovegesLenyomhatoWidget(_x+_xmeret-gombmeret,_y,gombmeret,gombmeret,"+",gombmeret-1);
    _minusz=SzovegesLenyomhatoWidget(_x+_xmeret-gombmeret,_y+gombmeret,gombmeret,gombmeret,"-",gombmeret-1);
}

void SzamosWidget::_Noveles(int mennyivel){
    if(_ertek+mennyivel>_maxertek){
            _ertek=_maxertek;
    }else {
        _ertek+=mennyivel;
    }
}
void SzamosWidget::_Csokkentes(int mennyivel){
    if(_ertek-mennyivel<_minertek){
        _ertek=_minertek;
    }else {
        _ertek-=mennyivel;

    }
}


void SzamosWidget::Rajzol() const{
    HatterRajzol();
    _plusz.Rajzol();
    _minusz.Rajzol();
    _widgetszin.szinrevalt();
    SzovegTipusValt(_ertekszovegmeret);
    gout<<move_to(_x,_y)<<text(std::to_string(_ertek));
};
bool SzamosWidget::Handle(genv::event ev){
    if(Hover(ev)){
        if(ev.type==ev_mouse && ev.button==btn_left){
            if(_plusz.Handle(ev)){
                _Noveles(1);
            }else if(_minusz.Handle(ev)){
                _Csokkentes(1);
            }
            return true;
        }

    }
        if(ev.type==ev_key){
                if(ev.keycode==key_up){
                    _Noveles(1);
                }else if(ev.keycode==key_pgup){
                    _Noveles(10);
                }else if(ev.keycode==key_down){
                    _Csokkentes(1);
                }else if(ev.keycode==key_pgdn){
                    _Csokkentes(10);
                }
        }


    return false;
};

std::string SzamosWidget::Ertekvisszaad() const{
return std::to_string(_ertek);
};


void SzamosWidget::GombokHatterSzine(Szin hatter){
    _plusz.HatterSzinValt(hatter);
    _minusz.HatterSzinValt(hatter);
}
void SzamosWidget::GombokKarakterSzine(Szin szinre){
    _plusz.EloSzinValt(szinre);
    _minusz.EloSzinValt(szinre);
}
