#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "window.hpp"

struct JatekMester{
private:
    Window* _MenuSzerkezet;
    //Menu elemek
    GombSzoveggel* _SodokuFelirat;
    GombSzoveggel* _StartGomb;

    //Játék elemek
    GombSzoveggel* _MenuGomb;
    GombSzoveggel* _SodokuPalya;
    GombSzoveggel* _ErtekKivalasztok;
    GombSzoveggel* _HibakszamaFelirat;

    public:
    JatekMester();
    void Start();
};

#endif // JATEKMESTER_HPP_INCLUDED
