#include "window.hpp"
#include <functional>
#include "iostream"

using namespace genv;

const int XX=600;
const int YY=400;

//fdhgs
int main()
{

    gout.open(XX,YY);
    Window w(XX,YY);
    w.EventLoop();
    return 0;
}
