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
    int timeToDie;                  // By user

    // Based on tweens / other logic
    int r, g, b, a;                 // Infer
    bool amAlive        = true;     // Infer
    int timeAlive;                  // Infer

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
        bool tweenColors,
        int timeToDie
    ) :
        color(color),
        h(h),
        w(w),
        x(x),
        y(y),
        printDebugs(printDebugs),
        tweenAlpha(tweenAlpha),
        tweenColors(tweenColors),
        timeToDie(timeToDie)
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
        std::vector<Vector2> listOfPoints,
        std::string tweenType
    ) 
    {
        // Match of AnimationFunctions.h
        obj.keyFrames(
            color,
            x,
            y,
            h,
            w,
            r,g,b,a,
            listOfPoints,
            tweenType,
            printDebugs,
            amAlive,
            tweenAlpha,
            tweenColors,
            timeToDie
        );
    }
};