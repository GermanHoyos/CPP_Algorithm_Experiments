#include "MasterHeader.h"

void RectangleClass::drawRectMthd(){
    // If this object exists, the draw
    DrawRectangleV({x,y},{height,width},color);
};

void RectangleClass::use(
    void (*func)(float& x, float& y, vector<Vector2> positions, float usrDefDuration, string tweenType),
    float timeChosen,
    vector<Vector2> listOfPoints,
    string tweenType
) 
{
    func(x, y, listOfPoints, timeChosen, tweenType);
    x = this->x;
    y = this->y;
}
