// Project to visualize common algorithms in C++:
// Created by: German Adrian Hoyos

// To run: call runme.bat [this will not work without raylib dll's]
// @echo off
// cd ..
// call runme.bat

#include <raylib-cpp.hpp>
#include <string>
#include <iostream>
#include "include/TimeManager.h"
using namespace std;

int main() {
    
    // Initialization
    int screenWidth = 1600;
    int screenHeight = 1000;
    string test = "Commit Change Test";
    
    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(screenWidth, screenHeight, "C++ Algorithms Visualized");
    
    SetTargetFPS(60);

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // TODO: Update your variables here



        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        TimeClass::displayGameTime();

        EndDrawing();
    }

    return 0;
}