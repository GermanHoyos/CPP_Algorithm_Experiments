#include "MasterHeader.h"

float animationSpeed = 1.0f;
bool setValues = false;
int i = 0;



float   
    zeroToOneProgressEaseIn,
    easeIn_animation_duration,
    zeroToOneProgressEaseOut,
    easout_animation_duration = 0.0F;

/***********************
**                    **
**     EASE IN        **
**                    **
***********************/
float easeIn(float zeroToOneProgressEaseIn) { // Blue line on desmos
	return zeroToOneProgressEaseIn * zeroToOneProgressEaseIn; //x^2 {0<x<1}
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

/***********************
**                    **
**     Apply Easings  **
**                    **
***********************/
// For the purposes of basic tweens on an x,y plane, the below func is sufficient, however
// not recommended for game logic or interaction-based animations
inline void keyFrames(float& x, float& y, vector<Vector2> positions, float usrDefDuration) {
        
    // Direction of tween must be explicitly determined since vector math is not integrated into the easing function.
    static bool tweenLeft   = false;
    static bool tweenRight  = false;
    static bool tweenUp     = false;
    static bool tweenDown   = false;
    static bool setValues   = false;

    // Initial Tween direction check
    static bool initTweenDirSwtch = false; 

    // Check which tweens to call
    if (initTweenDirSwtch == false) {
        if ( positions[i].x > (x) ) { tweenRight = true; tweenLeft  = false; }
        if ( positions[i].x < (x) ) { tweenLeft  = true; tweenRight = false; }
        if ( positions[i].y > (y) ) { tweenDown  = true; tweenUp    = false; }
        if ( positions[i].y < (y) ) { tweenUp    = true; tweenDown  = false; }
        zeroToOneProgressEaseOut = 0.0;
        initTweenDirSwtch = true;
    }

    // Raylib functions and value conversions
    int gameTotalSeconds = GetTime(); 
    float timeInSeconds = static_cast<float>(gameTotalSeconds);
    float factor = std::max(easeOut(zeroToOneProgressEaseOut), 0.0f);

    // Control the animations speed
    zeroToOneProgressEaseOut += animationSpeed * TimeClass::getDeltaTime();
    
    // Print Debug Vals
    std::string factor_str  = std::to_string(factor);
    std::string x_str  = std::to_string(x);
    DrawText(factor_str.c_str(), x, (y + 100), 20, GREEN); //0.0 to 0.1
    DrawText(x_str.c_str(), x, (y + 120), 20, GREEN); // init to end

    if (tweenRight) {
        // Apply tween / Detect when peak is reached / Determine new tween direction
        x = x + (positions[i].x - x) * factor;
        if (tweenUp) {
            y = y + (positions[i].y - y) * factor;
        }
        if (tweenDown) {
            y = y + (positions[i].y - y) * factor;
        }
        if (x >= (positions[i].x - 0.1f)) {
            if (positions[i + 1].x >= (x)) { 
                initTweenDirSwtch = false;
                i = i + 1;
            } else {
                initTweenDirSwtch = false;
                i = i + 1;
            }
        }
    }

    if (tweenLeft) {
        // Apply Tween / Detect when peak is reached / Determine new tween Direction
        x = x + (positions[i].x - x) * factor;
        if (tweenUp) {
            y = y + (positions[i].y - y) * factor;
        }
        if (tweenDown) {
            y = y + (positions[i].y - y) * factor;
        }
        if (x <= (positions[i].x + 0.1f)) { 
            if (positions[i + 1].x >= (x)) { 
                initTweenDirSwtch = false;
                i = i + 1;
            } else {
                initTweenDirSwtch = false;
                i = i + 1;
            }
        }
    }
   
   // Dont exceed list
    if (i == positions.size()) {
        i = 0;
    }
}