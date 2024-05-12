#ifndef SZAMOSWIDGET_HPP_INCLUDED
#define SZAMOSWIDGET_HPP_INCLUDED

#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gombszoveggel.hpp"
#include "graphics.hpp"

struct OsWidget;

struct SzamosWidget:public OsWidget{
    protected:
        int _ertekszovegmeret;
        int _ertek;
        int _maxertek;
        int _minertek;
        GombSzoveggel _plusz;
        GombSzoveggel _minusz;
        void _SetErtekek(int maximum, int minimum);
        void _SetGombok();
        void _Noveles(int mennyivel);
        void _Csokkentes(int mennyivel);

    public:
        SzamosWidget(int x, int y, int xmeret, int ymeret,Szin hatter, Szin karakterszin, int maximum=INT_MAX, int minimum=INT_MIN);
        SzamosWidget(int x, int y, int xmeret, int ymeret, Szin karakterszin, int maximum=INT_MAX, int minimum=INT_MIN);
        SzamosWidget(int x, int y, int xmeret, int ymeret,int maximum=INT_MAX, int minimum=INT_MIN);

        SzamosWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret,Szin hatter, Szin karakterszin, int maximum=INT_MAX, int minimum=INT_MIN);
        SzamosWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret, Szin karakterszin, int maximum=INT_MAX, int minimum=INT_MIN);
        SzamosWidget(WidgetCsoport* ablak,int x, int y, int xmeret, int ymeret,int maximum=INT_MAX, int minimum=INT_MIN);

        virtual void Rajzol() const;
        virtual bool Handle(genv::event ev);

        std::string Ertekvisszaad() const;

        void GombokHatterSzine(Szin hatter);
        void GombokKarakterSzine(Szin szinre);
};

#endif // SZAMOSWIDGET_HPP_INCLUDED
