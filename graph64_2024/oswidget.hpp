#ifndef OSWIDGET_HPP_INCLUDED
#define OSWIDGET_HPP_INCLUDED

#include "egyebstructok.hpp"
#include "graphics.hpp"

struct WidgetCsoport;

struct OsWidget{
    protected:
    Szin _hatterszin;
    Szin _widgetszin;
    int _x,_y,_xmeret,_ymeret;
    void HatterRajzol() const;
    public:
        OsWidget(int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin);
        OsWidget(int x, int y, int xmeret, int ymeret, Szin widgetszin);
        OsWidget(int x, int y, int xmeret, int ymeret);

        OsWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin);
        OsWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin widgetszin);
        OsWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret);

        virtual void Rajzol() const=0;
        virtual bool Hover(genv::event ev);
        virtual bool Handle(genv::event ev)=0;

        virtual std::string Ertekvisszaad() const{ return "";};

        void HatterSzinValt(Szin hatterszin);
        void EloSzinValt(Szin widgetszin);

};

#endif // OSWIDGET_HPP_INCLUDED
