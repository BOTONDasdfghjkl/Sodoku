#ifndef KIVALASZTOWIDGET_HPP_INCLUDED
#define KIVALASZTOWIDGET_HPP_INCLUDED

#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "graphics.hpp"
#include <vector>

struct KivalasztoWidget:public OsWidget{
protected:
    bool _isHover;
    std::vector<std::string> _v;
    int _ind;
    int _mennyitnyitle;
    int _holtartagorgo;
    int _karaktermeret;

    Szin _hatterszin2;
    Szin _widgetszin2;

    void _Initialization(std::vector<std::string> v, int& mennyi);
    int _HanyadikElemaLenyiloban(genv::event& ev);

public:
        KivalasztoWidget(int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin,std::vector<std::string> v,int mennyi);
        KivalasztoWidget(int x, int y, int xmeret, int ymeret, Szin widgetszin,std::vector<std::string> v,int mennyi);
        KivalasztoWidget(int x, int y, int xmeret, int ymeret,std::vector<std::string> v,int mennyi);

        KivalasztoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin,std::vector<std::string> v,int mennyi);
        KivalasztoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin widgetszin,std::vector<std::string> v,int mennyi);
        KivalasztoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret,std::vector<std::string> v,int mennyi);


        virtual void Rajzol() const;
        virtual bool Hover(genv::event ev);
        virtual bool Handle(genv::event ev);
        std::string Ertekvisszaad() const;

        void IndexTorol();
        void ElemHozzaad(std::string elem);

        void LenyiloReszSzine(Szin szinhatter,Szin szineloter);
};

#endif // KIVALASZTOWIDGET_HPP_INCLUDED
