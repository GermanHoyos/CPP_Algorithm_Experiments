#include "MasterHeader.h"
#pragma once

class TimeClass {
    public:
        static int seconds;
        static int minutes;
        static float deltaTime;
        static float getDeltaTime();
        static getFPS();
        static void displayGameTime();
};