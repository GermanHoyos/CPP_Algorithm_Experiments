// To run: call runme.bat
// @echo off
// cd ..
// call runme.bat

#include <raylib-cpp.hpp>
#include <string>
#include <iostream>
using namespace std;

int main() {
    
    // Initialization
    int screenWidth = 800;
    int screenHeight = 450;
    string test = "test";
    
    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");
    
    SetTargetFPS(60);

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // TODO: Update your variables here

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        textColor.DrawText("2", 190, 200, 20);
        EndDrawing();
    }

    return 0;
}