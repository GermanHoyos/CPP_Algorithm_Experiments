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
    RectangleClass myRect2(myGreen, 100.0f, 100.0f, 100.0f, 500.0f);



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
        myRect2.drawRectMthd();
        
        //[obj.animate](function, time in seconds)
        myRect.animate(applyEaseIn, 20.0f);
        myRect2.use(keyFrames, 20.0f);        

 
        EndDrawing();
    }


    return 0;
}