#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "window.hpp"

struct JatekMester{
private:
    Window* _MenuSzerkezet;
    Window* _SodokuJatek;
    //Menu elemek
    SzovegesLenyomhatoWidget* _SodokuFelirat;
    SzovegesLenyomhatoWidget* _StartGomb;
    SzovegesLenyomhatoWidget* _Kilepes;
    bool _menjenajatek;

    //Játék elemek
    LenyomhatoWidget* _HatterElemek;

    SzovegesLenyomhatoWidget* _MenuGomb;
    SzovegesLenyomhatoWidget* _SodokuPalya;
    SzovegesLenyomhatoWidget** _ErtekKivalasztok;
    SzovegesLenyomhatoWidget* _HibakszamaFelirat;
    int _elkovetetthibak;
    std::string _HibakSzamaszovege();
    int _gombnyomaserteke;
    void _GombErtekValtGombnyomashoz(SzovegesLenyomhatoWidget* lenyomottgomb);

    public:
    JatekMester();
    void Start();
};

#endif // JATEKMESTER_HPP_INCLUDED
