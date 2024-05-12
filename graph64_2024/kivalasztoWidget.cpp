#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "graphics.hpp"
#include "kivalasztoWidget.hpp"
using namespace genv;

KivalasztoWidget::KivalasztoWidget(int x, int y, int xmeret, int ymeret,Szin hatter, Szin karakterszin,std::vector<std::string> v,int mennyi):OsWidget(x,y,xmeret,ymeret,hatter,karakterszin){
          _Initialization(v,mennyi);
}
KivalasztoWidget::KivalasztoWidget(int x, int y, int xmeret, int ymeret, Szin karakterszin,std::vector<std::string> v,int mennyi):KivalasztoWidget(x,y,xmeret,ymeret,Szin(255,255,255),karakterszin,v,mennyi){}
KivalasztoWidget::KivalasztoWidget(int x, int y, int xmeret, int ymeret,std::vector<std::string> v,int mennyi):KivalasztoWidget(x,y,xmeret,ymeret,Szin(0,0,0),v,mennyi){}

KivalasztoWidget::KivalasztoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret,Szin hatter, Szin karakterszin,std::vector<std::string> v,int mennyi):OsWidget(ablak,x,y,xmeret,ymeret,hatter,karakterszin){
     _Initialization(v,mennyi);
}
KivalasztoWidget::KivalasztoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin karakterszin,std::vector<std::string> v,int mennyi):KivalasztoWidget(ablak,x,y,xmeret,ymeret,Szin(255,255,255),karakterszin,v,mennyi){}
KivalasztoWidget::KivalasztoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret,std::vector<std::string> v,int mennyi):KivalasztoWidget(ablak,x,y,xmeret,ymeret,Szin(0,0,0),v,mennyi){}


void KivalasztoWidget::_Initialization(std::vector<std::string> v, int& mennyi){
            _v=v;
    _mennyitnyitle=mennyi;
    _hatterszin2=_hatterszin;
    _widgetszin2=_widgetszin;
    _ind=0;
    _isHover=false;
    _holtartagorgo=0;
    _karaktermeret=_ymeret-2;

}
void KivalasztoWidget::LenyiloReszSzine(Szin szinhatter,Szin szineloter)
{
    _hatterszin2=szinhatter;
    _widgetszin2=szineloter;
}

int KivalasztoWidget::_HanyadikElemaLenyiloban(genv::event& ev){
    int meddig;
    if(_v.size()>_mennyitnyitle){
    meddig=_mennyitnyitle;
    }else{
        meddig=_v.size();
    }
    for(int i=0;i<meddig;i++){
        if((ev.pos_x>_x && ev.pos_x<_x+_xmeret)&&(ev.pos_y>_y+_ymeret*(i+1) && ev.pos_y<_y+_ymeret*(i+2))){
                return i;
        }
    }
    return -1;
}


void KivalasztoWidget::Rajzol()const{
    HatterRajzol();
    _widgetszin.szinrevalt();
    SzovegTipusValt(_karaktermeret);
    gout<<move_to(_x,_y);
    if(_v.size()>0){
    gout<<text(_v[_ind]);
    }
    else{
         gout<<text("-");
    }
    if(_isHover){
            _hatterszin.szinrevalt();
            gout<<move_to(_x,_y+_ymeret)<<box(_xmeret,_ymeret*_mennyitnyitle);
            if(_v.size()>0){
            _widgetszin.szinrevalt();
            int meddig=_mennyitnyitle+_holtartagorgo;
            for(int i=_holtartagorgo, j=1;i<meddig;i++,j++){
                gout<<move_to(_x,_y+(j)*_ymeret)<<text(_v[i]);
            }
            }
    }

}
bool KivalasztoWidget::Hover(event ev){
    if(!_isHover){
        _isHover=(ev.pos_x>_x && ev.pos_x<_x+_xmeret)&&(ev.pos_y>_y && ev.pos_y<_y+_ymeret);
    }else{
    _isHover=(ev.pos_x>_x && ev.pos_x<_x+_xmeret)&&(ev.pos_y>_y && ev.pos_y<_y+_ymeret*(_mennyitnyitle+1));
    }
    return _isHover;
}

bool KivalasztoWidget::Handle(event ev){
    if(ev.type==ev_mouse){
        Hover(ev);
        if(ev.button==btn_left){
            int ind=_HanyadikElemaLenyiloban(ev);
            if(ind!=-1){
                _ind=_holtartagorgo+ind;
            }
            _isHover=false;
        }else if(ev.button==btn_wheelup&&_holtartagorgo>0){
            _holtartagorgo--;
        }else if(ev.button==btn_wheeldown&&_holtartagorgo+_mennyitnyitle<_v.size()){
            _holtartagorgo++;
        }

    }

    return false;
}

std::string KivalasztoWidget::Ertekvisszaad()const {
    if(_v.size()>0){
    return _v[_ind];
    }else{
     return "";
    }
}


void KivalasztoWidget::IndexTorol(){
    if(_v.size()>0){
    _v.erase(_v.begin()+_ind);
    _ind=0;
    _holtartagorgo=0;
    }
};
void KivalasztoWidget::ElemHozzaad(std::string elem){
_v.push_back(elem);
};
