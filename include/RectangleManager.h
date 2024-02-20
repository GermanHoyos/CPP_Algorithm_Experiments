#include "MasterHeader.h"
#pragma once

class RectangleClass {
public:

    // Member variables
    AnimObj animObj;                // By user
    Color color;                    // By user
    float h;                        // By user
    float w;                        // 
    float x;                        //
    float y;                        //
    bool printDebugs    = true;     // By user   
    bool tweenAlpha     = false;    // By user
    bool tweenColors    = false;    // By user
    int r, g, b, a;                 // infer
    bool amAlive        = true;     // infer

    // Constructor
    RectangleClass
    (
        Color color,
        float h,
        float w,
        float x,
        float y,
        bool printDebugs,
        bool tweenAlpha,
        bool tweenColors
    ) :
        color(color),
        h(h),
        w(w),
        x(x),
        y(y),
        printDebugs(printDebugs),
        tweenAlpha(tweenAlpha),
        tweenColors(tweenColors)
    { /* Additional init logic here */ }

    // Destructor
    ~RectangleClass() {
        // No specific cleanup tasks required for this class
    }

    // Draw rectangle
    void drawRectMthd() {
        // If this object exists, then draw it
        DrawRectangleV({ x, y }, { w, h }, color);
    }

    // Apply tween controls to this object's position
    void use
    (
        AnimObj& obj,
        float timeChosen,
        std::vector<Vector2> listOfPoints,
        std::string tweenType
    ) 
    {
        obj.keyFrames(
            color,
            x,
            y,
            h,
            w,
            r,g,b,a,
            listOfPoints,
            timeChosen,
            tweenType,
            printDebugs,
            amAlive,
            tweenAlpha,
            tweenColors
        );
    }
};