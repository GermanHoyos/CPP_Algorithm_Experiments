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

    // Animate Rectangle
    void animate(void (*func)(float& x_or_y));    
    void animate(void (*func)(float& x, float& y));
    void animate(void (*func)(float& x, float& y, float& h, float& w));
    void animate(void (*func)(float& x, float& y, float& h, float& w, Color& c));

    void animate(void (*func)(Vector2& start));
    void animate(void (*func)(Vector2& start, Vector2& height_width));
    void animate(void (*func)(Vector2& start, Vector2& height_width, Color& c));
};