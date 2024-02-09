// Project to visualize common algorithms in C++:
// Created by: German Adrian Hoyos
// To run: call runme.bat from term [this will not work without raylib dll's]
// Use .zip package for full project files

#include "include/MasterHeader.h"       // commonly used headers
#include "include/TimeManager.h"
#include "include/RectangleManager.h"

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

    // Instantiate test objects here:
        RectangleClass myRect(myGreen, 100.0f, 100.0f, 100.0f, 100.0f);

    // Window title / target FPS
        raylib::Window w(screenWidth, screenHeight, "C++ Algorithms Visualized");
        SetTargetFPS(60);

    // Main game loop
        while (!w.ShouldClose()) // Detect window close button or ESC key
        {
            // Update / TODO: Update your variables here
                // loop var 1
                // loop var 2

            // Drawing ctx loop:
                BeginDrawing();
                ClearBackground(BLACK);
                TimeClass::displayGameTime();

                myRect.drawRectMthd();






                EndDrawing();
        }

    return 0;
}