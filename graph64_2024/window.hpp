#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "gombszoveggel.hpp"
#include "szamosWidget.hpp"
#include "kivalasztoWidget.hpp"
#include "widgetcsoport.hpp"

class Window:WidgetCsoport{
    GombSzoveggel* gombinennoda;
    GombSzoveggel* gombonnanide;
    KivalasztoWidget* itt;
    KivalasztoWidget* ott;

public:
    Window(int x, int y);
    void Nyomtat();
    void EventLoop();
    void Innenoda();
    void Onnanide();
};


#endif // WINDOW_HPP_INCLUDED
