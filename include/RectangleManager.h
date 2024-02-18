#include "MasterHeader.h"
#pragma once

class RectangleClass {

    // Made these public for ease of animation, no getters or setters needed
    public:
    Color color; 
    float x, y, height, width;
    bool animState_1, animState_2, animState_3;

    // Constructor
    RectangleClass (Color c, float h, float w, float xPos, float yPos)
    : color(c), height(h), width(w), x(xPos), y(yPos),
    animState_1(false), animState_2(false), animState_3(false) {}

    // Draw rectangle
    void drawRectMthd();

    // Apply tween controls to this objects position
    void use(void (*func)(float& xStart, float& yStart, vector<Vector2> positions, float usrDefDuration), float timeChosen);

};
