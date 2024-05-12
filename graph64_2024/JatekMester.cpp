#include "graphics.hpp"
#include "egyebstructok.hpp"
#include "oswidget.hpp"
#include "gomb.hpp"
#include "gombszoveggel.hpp"
#include "szamosWidget.hpp"
#include "kivalasztoWidget.hpp"
#include "widgetcsoport.hpp"
#include "window.hpp"
#include "JatekMester.hpp"

using namespace genv;

const int XXkepernyomeret=600;
const int YYkepernyomeret=400;

JatekMester::JatekMester():Window(XXkepernyomeret,YYkepernyomeret){
    gout.open(XXkepernyomeret,YYkepernyomeret);
}
