#include "MasterHeader.h"

void RectangleClass::drawRectMthd(){
    // If this object exists, the draw
    DrawRectangleV({x,y},{height,width},color);
};

void RectangleClass::animate(void (*func)(float& x, float& y)){
    func(x,y);
};

void RectangleClass::animate(void (*func)(Vector2& start)) {
    Vector2 start = {x, y}; // Create a Vector2 from the x and y values
    func(start); 
    x = start.x;
    y = start.y;
};

void RectangleClass::animate(void (*func)(float& x, float& y, float time)) {
    int gameTotalSeconds = GetTime(); // Assuming GetTime() returns an int representing total seconds
    float timeInSeconds = static_cast<float>(gameTotalSeconds);
    func(x, y, timeInSeconds);
    x = this->x;
    y = this->y;

};