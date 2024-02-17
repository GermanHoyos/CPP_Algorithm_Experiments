#include "MasterHeader.h"

float animationSpeed = 0.1f;
bool setValues = false;

float 
EASEIN_T,     EASEIN_ANIMATION_DURATION,
zeroToOneProgressEaseOut,    easout_animation_duration
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
// zeroToOneProgressEaseOut 0.0f to 1.0f
float easeOut(float zeroToOneProgressEaseOut) { // Green line on Desmos
    return 1 - (1 - zeroToOneProgressEaseOut) * (1 - zeroToOneProgressEaseOut); //1-(x-1)^2 {0<x<1}
}

// Apply Ease Out only in the X place
inline void applyEaseOut(float& x, float & y, float usrDefDuration) {

    // Direction of tween must be explicitly determined since vector math is not integrated into the easing function.
    static bool tweenLeft = false;
    static bool tweenRight = false;

    // Initial values that should not change
    static float initPosOfX = x;
    // Final positions should be user defined
    static float finPosOfX = x - 200;

    // X Plane  <[-1]---[initPosOfX]---[+1]>
    if (finPosOfX > x) {
        // Tween towards the right
        tweenRight = true;
    }
    if (finPosOfX < x) {
        // Tween towards the left
        tweenLeft = true;
    }

    // Values that should change
    static bool reachedThePeak = false;
    // Assuming GetTime() returns an int representing total seconds
    int gameTotalSeconds = GetTime(); 
    float timeInSeconds = static_cast<float>(gameTotalSeconds);
    float factor = std::max(easeOut(zeroToOneProgressEaseOut), 0.0f);

    // Takes a snap shot of vars without the limitations of c++ static
    if (setValues == false) {
        // this goes from 0 to some usr defined time
        easout_animation_duration = timeInSeconds + usrDefDuration; 
        setValues = true;    
    }

    // RIGHT
    // Determine if final x position is greater or lesser than initial x position
    // Based on the animation duration and objects position, apply easing math to object
    if (timeInSeconds < easout_animation_duration && reachedThePeak == false && tweenRight == true) {
        zeroToOneProgressEaseOut += animationSpeed * TimeClass::getDeltaTime();
        x = initPosOfX + (finPosOfX - initPosOfX) * factor;
        if (x > (finPosOfX - 1.5)) {
            reachedThePeak = true;
        }
    }  

    // LEFT
    // Determine if final x position is greater or lesser than initial x position
    // Based on the animation duration and objects position, apply easing math to object
    if (timeInSeconds < easout_animation_duration && reachedThePeak == false && tweenLeft == true) {
        zeroToOneProgressEaseOut += animationSpeed * TimeClass::getDeltaTime();
        x = initPosOfX + (finPosOfX - initPosOfX) * factor;
        if (x < (finPosOfX + 1.5)) {
            reachedThePeak = true;
        }
    }  

    // Debug pertinent values
    std::string factor_str  = std::to_string(factor);
    std::string x_str  = std::to_string(x);
    DrawText(factor_str.c_str(), x, 200, 20, GREEN); //0.0 to 0.1
    DrawText(x_str.c_str(), x, 220, 20, GREEN); // init to end

   // Reset var
        //code here..
}


