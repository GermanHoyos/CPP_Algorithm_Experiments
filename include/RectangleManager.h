#include "MasterHeader.h"
#pragma once

class RectangleClass {
    // Made these public for ease of animation, no getters or setters needed
        public:
            Color color; 
            int height;
            int width;
            float x;
            float y;
            bool animState_1;
            bool animState_2;
            bool animState_3;
        public:
    // Constructor method
        RectangleClass (Color c, int h, int w, float xPos, float yPos)
    // This.color = c, this.height = h, this.animState_1 = false
        : color(c), height(h), width(w), x(xPos), y(yPos),
        animState_1(false), animState_2(false), animState_3(false) {}
    // If the above vars were private, example of getters / setters

        // // Accessor methods
        // Color getColor() const { return color; }
        // int getHeight() const { return height; }
        // int getWidth() const { return width; }
        // float getX() const { return x; }
        // float getY() const { return y; }
        // bool getAnimState1() const { return animState_1; }
        // bool getAnimState2() const { return animState_2; }
        // bool getAnimState3() const { return animState_3; }

        // // Modifier methods
        // void setColor(Color c) { color = c; }
        // void setHeight(int h) { height = h; }
        // void setWidth(int w) { width = w; }
        // void setX(float xPos) { x = xPos; }
        // void setY(float yPos) { y = yPos; }
        // void setAnimState1(bool state) { animState_1 = state; }
        // void setAnimState2(bool state) { animState_2 = state; }
        // void setAnimState3(bool state) { animState_3 = state; }
    
    // Methods similar to my js proj game
        void drawRectMthd();
};