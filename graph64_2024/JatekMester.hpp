#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include "window.hpp"
#include <vector>

const int SODOKUMERET=3;

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
    LenyomhatoWidget** _HatterElemek;

    SzovegesLenyomhatoWidget* _MenuGomb;
    SzovegesLenyomhatoWidget** _SodokuPalya;
    SzovegesLenyomhatoWidget** _ErtekKivalasztok;
    SzovegesLenyomhatoWidget* _HibakszamaFelirat;
    int _elkovetetthibak;
    std::string _HibakSzamaszovege();
    int _gombnyomaserteke;
    void _GombErtekValtGombnyomashoz(SzovegesLenyomhatoWidget* lenyomottgomb);

    bool _isValidROWCOLOUM(int dY,int dX,int dy,int dx,int ertek);
    bool _fillBoard();

    int _intmatrix[SODOKUMERET][SODOKUMERET][SODOKUMERET][SODOKUMERET];
    bool _felulirhatoe[SODOKUMERET][SODOKUMERET][SODOKUMERET][SODOKUMERET];
    void _GenerateIntMatrix();
    void _GenerateBoolMatrix();
    void _GenerateMap();

    public:
    JatekMester();
    void Start();
};

#endif // JATEKMESTER_HPP_INCLUDED
