#include "MasterHeader.h"
#pragma once

class RectangleObj
{
public:
   // Member variables
   AnimObj animObj;              // By user
   Color   color;                // By user
   float   h, w, x, y;           // By user
   bool    printDebugs = true;   // By user
   bool    tweenAlpha = false;   // By user
   bool    tweenColors = false;  // By user
   int     timeToDie;            // By user

   // Based on tweens / other logic
   int   r, g, b, a;       // Infer
   bool  amAlive = true;   // Infer
   int   timeAlive;        // Infer

   // Constructor
   // Example call: 
      //    rects.push_back(RectangleObj(myGreen, 5.0f, 5.0f, 400, 400, false, true, false, 5));
   RectangleObj(Color color,
                float h, float w, float x, float y,
                bool  printDebugs,
                bool  tweenAlpha,
                bool  tweenColors,
                int   timeToDie)
                : 
                color(color),
                h(h), w(w), x(x), y(y),
                printDebugs(printDebugs),
                tweenAlpha(tweenAlpha),
                tweenColors(tweenColors),
                timeToDie(timeToDie)
   {
      // Additional init logic here 
   }

   // Destructor
   ~RectangleObj()
   {
      // No specific cleanup tasks required for this class
   }

   // Draw rectangle
   void drawRectMthd()
   {
      // If this object exists, then draw it
      DrawRectangleV({x, y}, {w, h}, color);
   }

   // AnimObj is passed via reference called: &obj, to this Rectangle object
   // thus dependent on which tweenType is chosen, the &obj will tween various
   // aspects of this Rectangle obj called RectangleObj
   // Instantiate Objects
   // This "use" function is called via while loop in the main gaime loop
   void use(AnimObj &animObj, std::vector<Vector2> positions, std::string tweenType)
   {
      // Call the keyframes function from this AnimObj
      // Arguments              (color,   height, width,    x,  y, printDebugs, tweenAplha, tweenColors, timeToDie)
      // RectangleObj      rect1(myGreen, 100.0f, 100.0f, 410, 25, true, false, false, 5);  // Section 1 / demo easeIn
      // RectangleObj      rect2(myGreen, 100.0f, 100.0f, 410, 165, true, false, false, 5); // Section 1 / demo easeOut
      // AnimObj           obj0;
      // vector<Vector2>   leftToRightDemo1 = {{1500, 25}, {410, 25}};
      // rect1.use(obj0,   leftToRightDemo1, "easeIn");
      animObj.keyFrames(color, x, y, h, w,
                        r, g, b, a,
                        positions,
                        tweenType,
                        printDebugs,
                        amAlive,
                        tweenAlpha,
                        tweenColors,
                        timeToDie);
   }
};

