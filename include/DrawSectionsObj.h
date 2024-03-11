#include "MasterHeader.h"

class DrawSectionsObj
{
public:
   // All strings
   string eFormula = "Expression:";
   string eStringIn = "EASE IN:";
   string eInMath = "a = x^2{0<x<1}";
   string eStringOu = "EASE OUT:";
   string eOuMath = "a = 1-(x-1)^2{0<x<1}";
   string eStringOuExp = "EASE OUT APPLICATIONS:";
   string eStringInExp = "EASE IN APPLICATIONS:";
   string eOpacityIn = "UI Animations";
   string eOpacityOu = "Opacity + [x,y] plane Ease Out";

   string eColor = "std::rand() Color + [x,y] plane";
   string eShape = "Obj Shape / Width Height";

   void draw()
   {
      // Line Sections:
      DrawLine(0, 310, 1600, 310, GREEN);
      // DrawLine(800, 310, 800, 1600, GREEN);
      // DrawLine(905, 310, 905, 310, RED);

      // Header ease ins
      DrawText(eStringIn.c_str(), 220, 25, 35, GREEN);
      DrawText(eFormula.c_str(), 220, 55, 20, GREEN);
      DrawText(eInMath.c_str(), 220, 75, 20, GREEN);

      // Header ease outs
      DrawText(eStringOu.c_str(), 220, 165, 35, GREEN);
      DrawText(eFormula.c_str(), 220, 195, 20, GREEN);
      DrawText(eOuMath.c_str(), 220, 215, 20, GREEN);

      // Left box
      DrawText(eOpacityOu.c_str(), 5, 315, 20, GREEN);
      DrawRectangleLines(5, 340, 790, 650, GREEN);

      // Right box
      DrawText(eOpacityIn.c_str(), 805, 315, 20, GREEN);
      DrawRectangleLines(805, 340, 790, 650, GREEN);
   }
};
