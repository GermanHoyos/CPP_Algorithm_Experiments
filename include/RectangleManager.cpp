#include "MasterHeader.h"

void RectangleClass::drawRectMthd(){
    // If this object exists, the draw
    DrawRectangleV({x,y},{height,width},color);
};

void RectangleClass::animate(void (*func)(float& x, float& y, float duration), float timeChosen) {
    func(x, y, timeChosen);
    x = this->x;
    y = this->y;
};