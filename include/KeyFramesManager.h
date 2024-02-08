#include "MasterHeader.h"
#pragma once

// Color myGreen = {0, 255, 0, 255};

class KeyFrameClass {
    // generic template for renaming c++ vector:
        //template<typename T>
        //using dynamicList = vector<T>;
    public:
        dynamicList<Vector2> positionMove;
        dynamicList<Color> colorShift;

    // When this object is instantiated it will
    // take in as a param another object, for example
    // an object created via the RectangleClass

    KeyFrameClass(dynamicList<Vector2>& moves, dynamicList<Color>& shifts)
        : positionMove(moves), colorShift(shifts) {}


    void animate();

}