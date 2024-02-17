#include "MasterHeader.h"

float animationSpeed = 0.1f;
bool setValues = false;

float 
EASEIN_T,     EASEIN_ANIMATION_DURATION,
EASEOUT_T,    easout_animation_duration
= 0.0F;

/***********************
**                    **
**     EASE IN        **
**                    **
***********************/
float easeIn(float t) { // Blue line on desmos
	return t * t; //x^2 {0<x<1}
}
inline void applyEaseIn(float& x, float& y, float usrDefDuration) {
    
    // Initial values that should not change
    static float initPosOfX = x;
    static float finPosOfX = x + 30;

    // Values that should change
    int gameTotalSeconds = GetTime(); // Assuming GetTime() returns an int representing total seconds
    float timeInSeconds = static_cast<float>(gameTotalSeconds);
    float factor = easeIn(EASEIN_T);

    // Avoid the limitations of static inits
    if (setValues == false) {
        EASEIN_ANIMATION_DURATION = timeInSeconds + usrDefDuration;
        setValues = true;    
    }

    // Apply ease in function
    if (timeInSeconds < EASEIN_ANIMATION_DURATION) {
        EASEIN_T += animationSpeed * TimeClass::getDeltaTime();
   
            x = initPosOfX + (finPosOfX - initPosOfX) * factor;
    
        
    }  

    // Reset var
        //code here..

}

/***********************
**                    **
**     EASE OUT       **
**                    **
***********************/
float easeOut(float t) { // Green line on Desmos
    return 1 - (1 - t) * (1 - t); //1-(x-1)^2 {0<x<1}
}
inline void applyEaseOut(float& x, float & y, float usrDefDuration) {

    // Initial values that should not change
    static float initPosOfX = x;
    static float finPosOfX = x + 1000;
    static bool reachedThePeak = false;

    // Values that should change
    int gameTotalSeconds = GetTime(); // Assuming GetTime() returns an int representing total seconds
    float timeInSeconds = static_cast<float>(gameTotalSeconds);
    float factor = std::max(easeOut(EASEOUT_T), 0.0f);

    // Take snap shots of vars without the limitations of static vars
    if (setValues == false) {
        easout_animation_duration = timeInSeconds + usrDefDuration; // this goes from 0 to some usr defined time
        setValues = true;    
    }

    // Based on animation duration and objects position, apply easing math to object
    if (timeInSeconds < easout_animation_duration && reachedThePeak == false) {
        EASEOUT_T += animationSpeed * TimeClass::getDeltaTime();
        if (EASEOUT_T > 0) {
            x = initPosOfX + (finPosOfX - initPosOfX) * factor;
        }
    }  

    // Based on location, apply easing math to an object based on some control
    if (x > (finPosOfX - 1.5) ) {  // ?
        reachedThePeak = true;
    }

    std::string factor_str  = std::to_string(factor);
    std::string x_str  = std::to_string(x);
    DrawText(factor_str.c_str(), x, 200, 20, GREEN); //0.0 to 0.1
    DrawText(x_str.c_str(), x, 220, 20, GREEN); // init to end

   // Reset var
        //code here..

}


