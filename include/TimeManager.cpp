#include "MasterHeader.h"
#include "TimeManager.h"

// Define static variables outside the class
int gameTotalSeconds = GetTime();
int TimeClass::seconds = 0;
int TimeClass::minutes = 0;
float TimeClass::deltaTime = 0;

float TimeClass::getDeltaTime() {
    return GetFrameTime();
}

int TimeClass::getFPS() {
    return getFPS();
}

// The below function called displaSystemTime()
// will be called from the main loop every tic
void TimeClass::displayGameTime() {
    // deltaTime is the time between tic's
    deltaTime = GetFrameTime();
    
    // Control statements display
    // seconds which are then used to calculate minutes
    int currentTime = GetTime();
    // gameTotalSeconds will be updated every frame
    if (gameTotalSeconds != currentTime) {
        seconds++;
        // Post the 60th second, revert back to 0
        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }
        gameTotalSeconds = currentTime;
    }

    // Stringify seconds and minutes
    int FPS = GetFPS();
    string seconds_str = "Seconds: " + to_string(seconds);
    string minutes_str = "Minutes: " + to_string(minutes);
    string deltaTime_str = "Delta Time: " + to_string(deltaTime);
    string fps_str = "Fps: " + to_string(FPS);

    // Vertical line for menu and debug
    DrawLine(210,0,210,1000,GREEN);

    // Debug outputs
    DrawText(fps_str.c_str(), 2, 2, 20, GREEN);
	DrawText(seconds_str.c_str(), 2, 20, 20, GREEN);
	DrawText(minutes_str.c_str(), 2, 40, 20, GREEN);
	DrawText(deltaTime_str.c_str(), 2, 60, 20, GREEN);

}