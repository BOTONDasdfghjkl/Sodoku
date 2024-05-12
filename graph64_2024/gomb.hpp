#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED

#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "graphics.hpp"
#include <functional>


struct LenyomhatoWidget:public OsWidget{
    private:
        std::function<void()> _gombnyomas;
    public:
        LenyomhatoWidget(int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin);
        LenyomhatoWidget(int x, int y, int xmeret, int ymeret, Szin widgetszin);
        LenyomhatoWidget(int x, int y, int xmeret, int ymeret);

        LenyomhatoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin);
        LenyomhatoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin widgetszin);
        LenyomhatoWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret);
        virtual void Rajzol() const;
        virtual bool Handle(genv::event ev);
        void SetGombNyomas(std::function<void()> gombnyomas);


};



#endif // GOMB_HPP_INCLUDED
