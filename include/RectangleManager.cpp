#include "MasterHeader.h"

void RectangleClass::drawRectMthd(){
    // If this object exists, the draw
    DrawRectangleV({x,y},{height,width},color);
};

void RectangleClass::use(void (*func)(float& x, float& y, vector<Vector2> positions, float usrDefDuration), float timeChosen){
    vector<Vector2> listOfPoints = {{300, 400}, {700, 100}, {100, 400}, {200, 100}};
    func(x, y, listOfPoints, timeChosen);
    x = this->x;
    y = this->y;
}