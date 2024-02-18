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

void RectangleClass::use(void (*func)(float& x, float& y, vector<Vector2> positions, float usrDefDuration), float timeChosen){
    vector<Vector2> listOfPoints = {{400, 400}, {100, 100}, {600, 400}};
    func(x, y, listOfPoints, timeChosen);
    x = this->x;
    y = this->y;
}