#include "graphics.hpp"                                                                                                                                                                                                                                                                                                                             //M�zsik Botond k�dja a3. beadandohoz
#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "gombszoveggel.hpp"
#include "szamosWidget.hpp"
#include "kivalasztoWidget.hpp"
#include "widgetcsoport.hpp"
#include "window.hpp"
#include "JatekMester.hpp"

#include "iostream"
#include <vector>
#include <ctime>
using namespace genv;

const int XXkepernyomeret=500;
const int YYkepernyomeret=700;
const int MAXHIBAK=10;
const int SZAMOSGOMBOKMERETE=20;
const int KICSINEGYZET=SODOKUMERET*SODOKUMERET;
const int NAGYNEGYZET=KICSINEGYZET*KICSINEGYZET;
const Szin kekszin(51,51,255);
const Szin fekete(0,0,0);
const Szin szurke(64,64,64);
const Szin feher(255,255,255);
const Szin piros(153,0,0);



JatekMester::JatekMester(){
    gout.open(XXkepernyomeret,YYkepernyomeret);
        std::srand(std::time(0));

    //Menu elk�sz�t�se
    _menjenajatek=true;
    _MenuSzerkezet=new Window(XXkepernyomeret,YYkepernyomeret);
    _SodokuFelirat=new SzovegesLenyomhatoWidget(_MenuSzerkezet,20,20,0,0,fekete,"Sodoku",130);
    _StartGomb=new SzovegesLenyomhatoWidget(_MenuSzerkezet, 200,300,100,50,"Start",40);
    _StartGomb->SetGombNyomas([&](){_MenuSzerkezet->Eventvege();_menjenajatek=true;});
    _Kilepes=new SzovegesLenyomhatoWidget(_MenuSzerkezet, 200,400,100,50,"Quit",40);
    _Kilepes->SetGombNyomas([&](){_MenuSzerkezet->Eventvege();_menjenajatek=false;});

    //Jatek elkeszitese


    _elkovetetthibak=0;

    _SodokuJatek=new Window(XXkepernyomeret,YYkepernyomeret);
    _HatterElemek=new LenyomhatoWidget*[4];
    const int vonalmeret=3*SODOKUMERET*(SZAMOSGOMBOKMERETE+10)-10;

    _HatterElemek[1]=new LenyomhatoWidget(_SodokuJatek,100+3*(SZAMOSGOMBOKMERETE+10)-10,200,10,vonalmeret,kekszin,fekete);
    _HatterElemek[2]=new LenyomhatoWidget(_SodokuJatek,100+6*(SZAMOSGOMBOKMERETE+10)-10,200,10,vonalmeret,kekszin,fekete);
    _HatterElemek[3]=new LenyomhatoWidget(_SodokuJatek,100,200+3*(SZAMOSGOMBOKMERETE+10)-10,vonalmeret,10,kekszin,fekete);
    _HatterElemek[4]=new LenyomhatoWidget(_SodokuJatek,100,200+6*(SZAMOSGOMBOKMERETE+10)-10,vonalmeret,10,kekszin,fekete);

    _MenuGomb=new SzovegesLenyomhatoWidget(_SodokuJatek,10,10,140,20,"To the main menu",16);
    _MenuGomb->SetGombNyomas([&](){_SodokuJatek->Eventvege();});
    _RetryGomb=new SzovegesLenyomhatoWidget(_SodokuJatek,200,10,50,20,"Retry",16);
    _RetryGomb->SetGombNyomas([&](){_GenerateMap();});
    _HibakszamaFelirat=new SzovegesLenyomhatoWidget(_SodokuJatek,450,10,0,0,_HibakSzamaszovege(),16);
    _Uzenet=new SzovegesLenyomhatoWidget(_SodokuJatek,180,500,0,0,"",16);

    _ErtekKivalasztok=new SzovegesLenyomhatoWidget*[KICSINEGYZET];
    for (int i=0;i<KICSINEGYZET;i++){
        _ErtekKivalasztok[i]=new SzovegesLenyomhatoWidget(_SodokuJatek,100+i*(SZAMOSGOMBOKMERETE+10),600,SZAMOSGOMBOKMERETE,SZAMOSGOMBOKMERETE,std::to_string(i+1),SZAMOSGOMBOKMERETE);
        _ErtekKivalasztok[i]->SetGombNyomas([i,this](){_ChangeErtek(i+1);});
    }
    _SodokuPalya=new SzovegesLenyomhatoWidget*[NAGYNEGYZET];
    int ind=0;
    for(int Y=0;Y<SODOKUMERET;Y++){
        for(int X=0;X<SODOKUMERET;X++){
            for(int y=0;y<SODOKUMERET;y++){
                for(int x=0;x<SODOKUMERET;x++){
                        _SodokuPalya[ind]=new SzovegesLenyomhatoWidget(_SodokuJatek,100+(x+SODOKUMERET*X)*(SZAMOSGOMBOKMERETE+10),200+(y+SODOKUMERET*Y)*(SZAMOSGOMBOKMERETE+10),SZAMOSGOMBOKMERETE,SZAMOSGOMBOKMERETE,"",SZAMOSGOMBOKMERETE);
                        _SodokuPalya[ind]->SetGombNyomas([Y,X,y,x,ind,this](){_Step(Y,X,y,x,ind);});
                        ind++;
                }
            }
        }
    }
    _gombnyomaserteke=1;
    _ChangeErtek(1);
}

void JatekMester::Start(){
    _MenuSzerkezet->EventLoop();
    while(_menjenajatek){
        _GenerateMap();
        _SodokuJatek->EventLoop();
        _menjenajatek=false;
        _MenuSzerkezet->EventLoop();
    }
}

std::string JatekMester::_HibakSzamaszovege(){
    return std::to_string(_elkovetetthibak)+"/"+std::to_string(MAXHIBAK);
}



void JatekMester::_GenerateMap(){
    _elkovetetthibak=0;
    _HibakszamaFelirat->ErtekValt(_HibakSzamaszovege());
    _Uzenet->ErtekValt("");
    _GenerateIntMatrix();
    _GenerateBoolMatrix();

    int ind=0;
    for(int Y=0;Y<SODOKUMERET;Y++){
        for(int X=0;X<SODOKUMERET;X++){
            for(int y=0;y<SODOKUMERET;y++){
                for(int x=0;x<SODOKUMERET;x++){

                        if(_felulirhatoe[Y][X][y][x]){
                            _SodokuPalya[ind]->ErtekValt("");
                            _SodokuPalya[ind]->HatterSzinValt(feher);
                            _SodokuPalya[ind]->EloSzinValt(kekszin);
                            _intmatrix[Y][X][y][x]=0;
                        }else{
                        _SodokuPalya[ind]->ErtekValt(std::to_string(_intmatrix[Y][X][y][x]));
                        _SodokuPalya[ind]->HatterSzinValt(szurke);
                        _SodokuPalya[ind]->EloSzinValt(feher);
                        }
                        ind++;
                }
            }
        }
    }


}



bool JatekMester::_isValidROWCOLOUM(const int& dY,const int& dX,const int& dy,const int& dx,const int& ertek){

    for(int i=0;i<SODOKUMERET;i++){
        for(int j=0;j<SODOKUMERET;j++){

                    if(_intmatrix[dY][i][dy][j]==ertek||_intmatrix[i][dX][j][dx]==ertek){
                        return false;
                    }

        }
    }
    return true;
};

bool JatekMester::_isValidKicsiNegyzet(const int& dY,const int& dX,const int& dy,const int& dx,const int& ertek){
    for(int i=0;i<SODOKUMERET;i++){
        for(int j=0;j<SODOKUMERET;j++){
            if(_intmatrix[dY][dX][i][j]==ertek){
                return false;
            }
        }
    }
    return true;
}

bool JatekMester::_isValidStep(const int& dY,const int& dX,const int& dy,const int& dx,const int& ertek){

    return _isValidKicsiNegyzet(dY,dX,dy,dx,ertek) &&_isValidROWCOLOUM(dY,dX,dy,dx,ertek);
}

bool JatekMester::_isLost(){
    return _elkovetetthibak>=MAXHIBAK;
};
bool JatekMester::_isWin(){
    return _kitoltottmezok==NAGYNEGYZET;
};
void JatekMester::_Step(int Y,int X,int y, int x,int ind){
    if(_isLost()){
            _Uzenet->ErtekValt("Sajnos nincs tobb probalkozasod.");
            _Uzenet->EloSzinValt(piros);
    }else {
        if(_felulirhatoe[Y][X][y][x]&&!_isWin()){
                if(_isValidStep(Y,X,y,x,_gombnyomaserteke)){
                        if(_intmatrix[Y][X][y][x]==0){
                            _kitoltottmezok++;
                            if(_isWin()){
                                _Uzenet->ErtekValt("Gratula, megnyerted a jatekot.");
                                _Uzenet->EloSzinValt(kekszin);
                            }
                        }
                        _intmatrix[Y][X][y][x]=_gombnyomaserteke;
                        _SodokuPalya[ind]->ErtekValt(std::to_string(_gombnyomaserteke));
                }else{
                            _elkovetetthibak++;
                            _HibakszamaFelirat->ErtekValt(_HibakSzamaszovege());
                            _Uzenet->ErtekValt("Oda nem lehet "+std::to_string(_gombnyomaserteke)+" tenni.");
                            _Uzenet->EloSzinValt(piros);
                }
        }
    }

};
void JatekMester::_ChangeErtek(int i){
    _ErtekKivalasztok[_gombnyomaserteke-1]->EloSzinValt(fekete);
    _gombnyomaserteke=i;
    _ErtekKivalasztok[_gombnyomaserteke-1]->EloSzinValt(kekszin);
};



void RandomShuffleVector(std::vector<int>& v, int hanyszor){
    int cserelo,rand1,rand2;
    for(int i=0;i<hanyszor;i++){
        rand1=rand()%v.size();
        do{
            rand2=rand()%v.size();
        }while(rand1==rand2);
        cserelo=v[rand1];
        v[rand1]=v[rand2];
        v[rand2]=cserelo;
    }
}

void ShiftRightVector(std::vector<int>& v,int hanyszor){
    for(int j=0;j<hanyszor;j++){
        int cserelo=v[v.size()-1];
        for(int i=v.size()-1;i>0;i--){
            v[i]=v[i-1];
        }
        v[0]=cserelo;
    }
}



void JatekMester::_GenerateIntMatrix(){
    std::vector<int> lehetsegesszamok={1,2,3,4,5,6,7,8,9};
    RandomShuffleVector(lehetsegesszamok,15+rand()%10);
    int szamok[NAGYNEGYZET];
    for(int i=0;i<KICSINEGYZET;i++){
        if(i!=0&&i%SODOKUMERET==0){
            ShiftRightVector(lehetsegesszamok,1);
        }
        for(int j=0;j<KICSINEGYZET;j++){
            szamok[i*KICSINEGYZET+j]=lehetsegesszamok[j];
        }
        ShiftRightVector(lehetsegesszamok,3);

    }

    for(int Y=0;Y<SODOKUMERET;Y++){
        for(int X=0;X<SODOKUMERET;X++){
            for(int y=0;y<SODOKUMERET;y++){
                for(int x=0;x<SODOKUMERET;x++){
                        _intmatrix[Y][X][y][x]=szamok[Y*SODOKUMERET*SODOKUMERET*SODOKUMERET+y*SODOKUMERET*SODOKUMERET+X*SODOKUMERET+x];
                }
            }
        }
    }

};
void JatekMester::_GenerateBoolMatrix(){
    for(int Y=0;Y<SODOKUMERET;Y++){
        for(int X=0;X<SODOKUMERET;X++){
            for(int y=0;y<SODOKUMERET;y++){
                for(int x=0;x<SODOKUMERET;x++){
                        _felulirhatoe[Y][X][y][x]=false;
                }
            }
        }
    }
    int mennyiures=45+rand()%10;
    _kitoltottmezok=NAGYNEGYZET-mennyiures;
    int rand1,rand2,rand3,rand4;
    do{
            rand1=rand()%SODOKUMERET;
            rand2=rand()%SODOKUMERET;
            rand3=rand()%SODOKUMERET;
            rand4=rand()%SODOKUMERET;
            if(_felulirhatoe[rand1][rand2][rand3][rand4]==false){
                _felulirhatoe[rand1][rand2][rand3][rand4]=true;
                mennyiures--;
            }
    } while(mennyiures>0);

};
