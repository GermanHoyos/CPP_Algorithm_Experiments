#include "MasterHeader.h"


void RectangleClass::drawRectMthd(){
    // If this object exists, the draw
    DrawRectangleV({x,y},{height,width},color);
};

void RectangleClass::animate(void (*func)(float& x, float& y)){
    // Apply a specific animation to the properties of
    // this instantiated object, such as x y height width color
    func(x,y);

}