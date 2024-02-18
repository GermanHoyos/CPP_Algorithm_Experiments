#include "MasterHeader.h"

float animationSpeed = 0.1f;
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
inline void applyEaseIn(float& x, float& y, float usrDefDuration) {

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
    float factor = std::max(easeIn(zeroToOneProgressEaseIn), 0.0f);

    // Takes a snap shot of vars without the limitations of c++ static
    if (setValues == false) {
        // this goes from 0 to some usr defined time
        easeIn_animation_duration = timeInSeconds + usrDefDuration; 
        setValues = true;    
    }

    // RIGHT
    // Determine if final x position is greater or lesser than initial x position
    // Based on the animation duration and objects position, apply easing math to object
    if (timeInSeconds < easeIn_animation_duration && reachedThePeak == false && tweenRight == true) {
        zeroToOneProgressEaseIn += animationSpeed * TimeClass::getDeltaTime();
        x = initPosOfX + (finPosOfX - initPosOfX) * factor;
        if (x > (finPosOfX - 1.5)) {
            reachedThePeak = true;
        }
    }  

    // LEFT
    // Determine if final x position is greater or lesser than initial x position
    // Based on the animation duration and objects position, apply easing math to object
    if (timeInSeconds < easeIn_animation_duration && reachedThePeak == false && tweenLeft == true) {
        zeroToOneProgressEaseIn += animationSpeed * TimeClass::getDeltaTime();
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

// Apply Ease Out only in the X place
inline void applyEaseOut(float& x, float& y, float usrDefDuration) {

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

inline void keyFrames(float& x, float& y, vector<Vector2> positions, float usrDefDuration) {
    
    // Iterator for positions list


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
        initTweenDirSwtch = true;
    }

    // Raylib functions and value conversions
    int gameTotalSeconds = GetTime(); 
    float timeInSeconds = static_cast<float>(gameTotalSeconds);
    float factor = std::max(easeIn(zeroToOneProgressEaseOut), 0.0f);

    // Control the animations speed
    zeroToOneProgressEaseOut += animationSpeed * TimeClass::getDeltaTime();
    
    if (tweenRight) {
        // Apply tween / Detect when peak is reached / Determine new tween direction
        x = x + (positions[i].x - x) * factor;
        if (x >= (positions[i].x - 0.1f)) {
           zeroToOneProgressEaseOut = 0.0;
            if ( positions[i + 1].x >= (x) ) { 
                initTweenDirSwtch = false;
                i = i + 1;
            } else {
                initTweenDirSwtch = false;
                i = i + 1;
            }
        }
    }

    if (tweenLeft) {
        //Apply Tween / Detect when peak is reached / Determine new tween Direction
        x = x + (positions[i].x - x) * factor;
        if (x <= (positions[i].x + 0.1f)) {
            zeroToOneProgressEaseOut = 0.0;    
            if ( positions[i + 1].x >= (x) ) { 
                initTweenDirSwtch = false;
                i = i + 1;
            } else {
                initTweenDirSwtch = false;
                i = i + 1;
            }
        }
    }

    if (tweenUp) {
        
    }
    
    if (tweenDown) {
        //y++;
    }
   
   // Dont exceed list
    if (i == positions.size()) {
        i = 0;
    }


    std::string factor_str  = std::to_string(factor);
    std::string x_str  = std::to_string(x);
    DrawText(factor_str.c_str(), x, (y + 100), 20, GREEN); //0.0 to 0.1
    DrawText(x_str.c_str(), x, (y + 120), 20, GREEN); // init to end
}