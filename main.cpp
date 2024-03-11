#include "include/MasterHeader.h"

int main()
{

   // 2D - Initializations
   int screenWidth = 1600;
   int screenHeight = 1000;
   int N = 900;    // Use for rand()
   int minX = 210; // The debug vertical line is: x = 210;
   // RGBA
   Color myGreen = {0, 255, 0, 255};

   // Manual debugs / Testing only / Random values for tweens
   vector<Vector2> listOfPoints = {{300, 400}, {700, 100}, {100, 400}, {200, 100}};
   vector<Vector2> leftToRightDemo1 = {{1500, 25}, {410, 25}};
   vector<Vector2> leftToRightDemo2 = {{1500, 165}, {410, 165}};

   // Rand() lists
   vector<Vector2> randList_1;
   vector<Vector2> randList_2;
   vector<Vector2> randList_3;
   vector<Vector2> randList_4;
   vector<Vector2> randList_5;

   // Random val generation demo
   for (int i = 210; i < 310; i++)
   {
      int randomX = minX + rand() % (N - minX); // x must be >= than 210
      int randomY = rand() % N;
      float floatX = static_cast<float>(randomX);
      float floatY = static_cast<float>(randomY);
      randList_1.push_back({floatX, floatY});
   }

   // Constrain xy coord to left demo box
   // [x = 5][y = 340][width = 790, height = 650]
   int lbMinX = 5;
   int lbMaxX = 795;
   int lbMinY = 340;
   int lbMaxY = 990;
   for (int i = 0; i < 10; i++)
   {
      int randomX = lbMinX + rand() % (lbMaxX - lbMinX);
      int randomY = lbMinY + rand() % (lbMaxY - lbMinY);
      float floatX = static_cast<float>(randomX);
      float floatY = static_cast<float>(randomY);
      randList_2.push_back({floatX, floatY});
   }

   // Create a list of lists to  feed to multiple instantiations of rects various positions
   vector<vector<Vector2>> listOfLists;

   // Create 500 lists for 500 rects
   for (int i = 0; i < 100; i++)
   {
      // Create a llist that takes Vector2 class
      vector<Vector2> newList;
      // Populate new list with Vector2 random values
      for (int i = 0; i < 10; i++)
      {
         int randomX = lbMinX + rand() % (lbMaxX - lbMinX);
         int randomY = lbMinY + rand() % (lbMaxY - lbMinY);
         float floatX = static_cast<float>(randomX);
         float floatY = static_cast<float>(randomY);
         newList.push_back({floatX, floatY});
      }
      // Push new list into lists of lists
      listOfLists.push_back(newList);
   }

   // Create 100 rects and feed each one a different list
   // Create 100 AnimObjs and place in list of AnimObjs
   // Create a list that can take Rects from rect class
   vector<RectangleObj> rects;
   vector<AnimObj> objs;
   for (int i = 0; i < 100; i++)
   {
      // Get a reference for the lists inside of listOflists
      vector<Vector2> &currentList = listOfLists[i];
      // Instantiate
      rects.push_back(RectangleObj(myGreen, 5.0f, 5.0f, 400, 400, false, true, false, 5));
      // Create 100 obj's
      AnimObj obj;
      objs.push_back(obj);
   }

   // Boundaries
   DrawSectionsObj outlineSections;

   // Instantiate Objects
   // Arguments        (color, height, width, x, y, printDebugs, tweenAplha, tweenColors)
   RectangleObj rect1(myGreen, 100.0f, 100.0f, 410, 25, true, false, false, 5);  // Section 1 / demo easeIn
   RectangleObj rect2(myGreen, 100.0f, 100.0f, 410, 165, true, false, false, 5); // Section 1 / demo easeOut

   // Instantiate AnimObjs to be used with above objects
   AnimObj animObj_0; // Section 1 / demo easeIn
   AnimObj animObj_1; // Section 1 / demo easeOut
   AnimObj animObj_2; // Section 1 / demo easeOut

   // Window title / target FPS
   raylib::Window w(screenWidth, screenHeight, "C++ Easing Maths Visualized");
   SetTargetFPS(60);

   // use this for looping through objecs and lists
   int iterator = 0;

   // Test reasings.h
   int ballPositionX = 300;

   // Main game loop
   while (!w.ShouldClose()) // Detect window close button or ESC key
   {

      ballPositionX = (int)EaseElasticOut(TimeClass::framesCounterResetable, 300, 800, 120 );


      // Drawing ctx loop:
      BeginDrawing();
      ClearBackground(BLACK);
      TimeClass::displayGameTime();

      // Define section borders and descriptions
      outlineSections.draw();

      // Objects:
      rect1.drawRectMthd();
      rect2.drawRectMthd();
      // rect3.drawRectMthd();

      // use Arguments: (animObj, coordLists, typeofTween);
      rect1.use(animObj_0, leftToRightDemo1, "easeIn");
      rect2.use(animObj_1, leftToRightDemo2, "easeOut");

      // Draw all rects in list containing rects
      for (auto &rect : rects)
      {
         // Call draw in all rects
         rect.drawRectMthd();

         // Get an obj
         AnimObj &currentObj = objs[iterator];

         // Get an list
         vector<Vector2> &currentList = listOfLists[iterator];

         // Call easings on all rects
         rect.use(currentObj, currentList, "easeOut");

         iterator++;
         if (iterator >= objs.size())
         {
            // Reset iterateObjs if it exceeds the size of the objs vector
            iterator = 0;
         }
      }

      // Test reasings.h
       DrawCircle(ballPositionX, 700, 10.0f, RED);




      EndDrawing();
   }

   return 0;
}