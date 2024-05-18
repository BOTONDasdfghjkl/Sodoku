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
    SzovegesLenyomhatoWidget* _RetryGomb;
    SzovegesLenyomhatoWidget* _Uzenet;
    int _elkovetetthibak;
    int _kitoltottmezok;
    std::string _HibakSzamaszovege();




    int _gombnyomaserteke;
    int _intmatrix[SODOKUMERET][SODOKUMERET][SODOKUMERET][SODOKUMERET];
    bool _felulirhatoe[SODOKUMERET][SODOKUMERET][SODOKUMERET][SODOKUMERET];
    void _GenerateMap();
    bool _isValidROWCOLOUM(const int& dY,const int& dX,const int& dy,const int& dx,const int& ertek);
    bool _isValidKicsiNegyzet(const int& dY,const int& dX,const int& dy,const int& dx,const int& ertek);
    bool _isValidStep(const int& dY,const int& dX,const int& dy,const int& dx,const int& ertek);
    bool _isLost();
    bool _isWin();
    void _Step(int Y,int X,int y, int x, int ind);
    void _ChangeErtek(int i);


    void GenerateSpecificMAP();


    //Szar cuccok
    void _GenerateIntMatrix();
    void _GenerateIntMatrixKicsiNegyzet(int Y, int X);
    void _GenerationErrorSolver(const int& Y,const int& X,const int&y,const int &x);
    void ElemekTorlese(std::vector<int>& v,const int& Y,const int& X,const int&y,const int &x);
    void _GenerateBoolMatrix();



    public:
    JatekMester();
    void Start();
};

#endif // JATEKMESTER_HPP_INCLUDED
