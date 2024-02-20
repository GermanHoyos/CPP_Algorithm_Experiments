#include "MasterHeader.h"

class DrawSections {
public:
    // All strings
    string eFormula = "Expression:";
    string eStringIn = "EASE IN:";
    string eInMath = "a = x^2{0<x<1}";
    string eStringOu = "EASE OUT:";
    string eOuMath = "a = 1-(x-1)^2{0<x<1}";
    string eStringOuExp = "EASE OUT APPLICATIONS:";
    string eStringInExp = "EASE IN APPLICATIONS:";
    string eOpacity = "Opacity + [x,y] plane:";
    string eColor = "std::rand() Color + [x,y] plane";
    string eShape = "Obj Shape / Width Height";

    void draw() {
        // Line Sections:
        DrawLine(210, 310, 1600, 310, GREEN);
        DrawLine(905, 310, 905, 1000, GREEN);  

        // Header ease outs
        DrawText(eStringIn.c_str(), 220, 25, 35, GREEN);
        DrawText(eFormula.c_str(), 220, 55, 20, GREEN);
        DrawText(eInMath.c_str(), 220, 75, 20, GREEN);

        // Header ease ins
        DrawText(eStringOu.c_str(), 220, 165, 35, GREEN);
        DrawText(eFormula.c_str(), 220, 195, 20, GREEN);
        DrawText(eOuMath.c_str(), 220, 215, 20, GREEN);

        // Titles
        DrawText(eStringInExp.c_str(), 355, 320, 35, GREEN);
        DrawText(eStringOuExp.c_str(), 1020, 320, 35, GREEN);
        
        //Left top
        DrawText(eOpacity.c_str(), 220, 400, 20, GREEN);
        DrawRectangleLines(250, 425, 610, 200, GREEN);
        //Left bottom
        DrawText(eColor.c_str(), 220, 700, 20, GREEN);
        DrawRectangleLines(250, 725, 610, 200, GREEN);

        //Right top
        DrawText(eOpacity.c_str(), 915, 400, 20, GREEN);
        DrawRectangleLines(945, 425, 610, 200, GREEN);  
        //Right bottom
        DrawText(eColor.c_str(), 915, 700, 20, GREEN);
        DrawRectangleLines(945, 725, 610, 200, GREEN);
    }
};
