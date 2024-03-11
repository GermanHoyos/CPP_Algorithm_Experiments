#pragma once
#include "MasterHeader.h" // Include necessary headers to access GetTime() and other functions

class TimeClass
{
public:
   static int     seconds;
   static int     minutes;
   static int     gameTotalSeconds;
   static int     framesCounterResetable;
   static float   deltaTime;

   static float getDeltaTime()
   {
      return GetFrameTime();
   }

   static int getFPS()
   {
      return GetFPS(); // Assuming GetFPS() returns the frames per second
   }

   static void displayGameTime()
   {
      framesCounterResetable++; 
      deltaTime = GetFrameTime();

      int currentTime = GetTime();
      if (gameTotalSeconds != currentTime)
      {
         seconds++;
         if (seconds == 60)
         {
            seconds = 0;
            minutes++;
         }
         gameTotalSeconds = currentTime;
      }

      int FPS = GetFPS();
      string seconds_str = "Seconds: " + to_string(seconds);
      string minutes_str = "Minutes: " + to_string(minutes);
      string deltaTime_str = "Delta Time: " + to_string(deltaTime);
      string fps_str = "FPS: " + to_string(FPS);
      string framesCounterResetable_str = to_string(framesCounterResetable);

      DrawLine(210, 0, 210, 310, GREEN);
      DrawText(fps_str.c_str(), 2, 2, 20, GREEN);
      DrawText(seconds_str.c_str(), 2, 20, 20, GREEN);
      DrawText(minutes_str.c_str(), 2, 40, 20, GREEN);
      DrawText(deltaTime_str.c_str(), 2, 60, 20, GREEN);
      DrawText(framesCounterResetable_str.c_str(), 2, 90, 20, GREEN);

   }
};

// Define outside the class
int   TimeClass::seconds = 0;
int   TimeClass::minutes = 0;
int   TimeClass::framesCounterResetable = 0;
int   TimeClass::gameTotalSeconds = GetTime(); // Initialize gameTotalSeconds
float TimeClass::deltaTime = 0;

