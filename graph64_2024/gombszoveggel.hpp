#ifndef GOMBSZOVEGGEL_HPP_INCLUDED
#define GOMBSZOVEGGEL_HPP_INCLUDED


#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "graphics.hpp"

struct GombSzoveggel:public Gomb{
    protected:
        int _szovegmeret;
        std::string _szoveg;
    public:
        GombSzoveggel(int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin,std::string szoveg,int szovegmeret);
        GombSzoveggel(int x, int y, int xmeret, int ymeret, Szin widgetszin,std::string szoveg,int szovegmeret);
        GombSzoveggel(int x, int y, int xmeret, int ymeret,std::string szoveg,int szovegmeret);
        GombSzoveggel(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin hatterszin, Szin widgetszin,std::string szoveg,int szovegmeret);
        GombSzoveggel(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin widgetszin,std::string szoveg,int szovegmeret);
        GombSzoveggel(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret,std::string szoveg,int szovegmeret);
        GombSzoveggel();
        virtual void Rajzol() const;
        void ErtekValt(std::string szoveg);
        std::string Ertekvisszaad() const;
};

#endif // GOMBSZOVEGGEL_HPP_INCLUDED
