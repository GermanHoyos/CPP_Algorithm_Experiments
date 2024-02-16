#include "MasterHeader.h"

float animationDuration = 0.0f;
float animationSpeed = 0.5f;
bool snapShotBool = false;
float EASEIN_T, EASEOUT_T = 0.0f;


/***********************
**                    **
**     EASE IN        **
**                    **
***********************/
float easeIn(float t) { // Blue line on desmos
	return t * t; //x^2 {0<x<1}
}
inline void applyEaseIn(float& x, float& y, float usrDefDuration) {
    static float initPosOfX = x;
    static float finPosOfX = x + 30;
    int gameTotalSeconds = GetTime(); // Assuming GetTime() returns an int representing total seconds
    float timeInSeconds = static_cast<float>(gameTotalSeconds);
    float factor = easeIn(t);

    if (snapShotBool == false) {
        animationDuration = timeInSeconds + usrDefDuration;
        snapShotBool = true;    
    }

     if (timeInSeconds < animationDuration) {
        t += animationSpeed * TimeClass::getDeltaTime();
        x = initPosOfX + (finPosOfX - initPosOfX) * factor;
    }  
}




