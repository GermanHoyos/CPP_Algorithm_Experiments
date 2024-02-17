#include "include/MasterHeader.h" 

int main() {
    
    // Initializations
    int screenWidth = 1600;
    int screenHeight = 1000;
    string test = "Commit Change Test";
    enum GameScreenStates 
    {
        STARTSCREEN,
        GAMEPLAY,
        ENDSCREEN
    };
    Color myGreen = {0, 255, 0, 255};


    // Create a RectangleClass object with appropriate arguments
    RectangleClass myRect(myGreen, 100.0f, 100.0f, 200.0f, 100.0f);


    // Window title / target FPS
    raylib::Window w(screenWidth, screenHeight, "C++ Algorithms Visualized");
    SetTargetFPS(60);


    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {


        // Drawing ctx loop:
        BeginDrawing();
        ClearBackground(BLACK);
        TimeClass::displayGameTime();
 
        myRect.drawRectMthd();
        
        //[obj.animate](function, time in seconds)
        myRect.animate(applyEaseOut, 20.0f);


 
        EndDrawing();
    }


    return 0;
}