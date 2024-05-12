#ifndef WIDGETCSOPORT_HPP_INCLUDED
#define WIDGETCSOPORT_HPP_INCLUDED

#include "graphics.hpp"
#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "gombszoveggel.hpp"
#include "szamosWidget.hpp"
#include "kivalasztoWidget.hpp"
#include <vector>

struct OsWidget;

struct WidgetCsoport:public OsWidget{
    protected:
    OsWidget* kivalasztott;
    std::vector<OsWidget*> widgetek;
    public:
    WidgetCsoport(int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin);
    WidgetCsoport(int x, int y, int xmeret, int ymeret, Szin widgetszin);
    WidgetCsoport(int x, int y, int xmeret, int ymeret);

    WidgetCsoport(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin);
    WidgetCsoport(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin widgetszin);
    WidgetCsoport(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret);


    void AddWidget(OsWidget* wid);
    void RemoveWidget(int ind);
    virtual void Rajzol() const;
    virtual bool Handle(genv::event ev);

};

#endif // WIDGETCSOPORT_HPP_INCLUDED
