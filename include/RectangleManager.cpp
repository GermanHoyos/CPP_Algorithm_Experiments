#include "MasterHeader.h"
#include "RectangleManager.h"
#include "AnimationFunctions.h"

void RectangleClass::drawRectMthd(){
    // If this object exists, the draw
    DrawRectangleV({x,y},{height,width},color);
};

void RectangleClass::animate(){
    // If an animation sequance has been called then animate
    animation_1(x,y);
}