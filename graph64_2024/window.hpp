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

class Window:public WidgetCsoport{
private:
    bool _eventvege;
public:
    Window(int x, int y);
    Window();
    void EventLoop();
    void Eventvege();

};


#endif // WINDOW_HPP_INCLUDED
