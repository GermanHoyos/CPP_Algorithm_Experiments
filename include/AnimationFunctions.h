#include "MasterHeader.h"

class AnimObj {
private:

    float animationSpeed = 0.01f;
    bool setValues = false;
    int i = 0;
    int previousI = -1;

    float   
    zeroToOneProgressEaseIn,
    easeIn_animation_duration,
    zeroToOneProgressEaseOut,
    easout_animation_duration = 0.0F;

    // Direction of tween must be explicitly determined since vector math is not integrated into the easing function.
    bool tweenLeft   = false;
    bool tweenRight  = false;
    bool tweenUp     = false;
    bool tweenDown   = false;
    float factor;
    float currentX;
    float deltaX;
    float previouX = 0;
    float derivedSpeed = 0;
    float normalizePos1;
    float normalizePos2;
    float absDistance;
    float alpha = 0;
    float halfwayPoint;
    float minSpeed;
    float maxSpeed;


    // Initial Tween direction check
    bool initTweenDirSwtch = false; 

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
    **     LERP           **
    **                    **
    ***********************/
    float lerp(float a, float b, float t){
        return a + t * (b - a);
    }

    /***********************
    **                    **
    ** NORMALIZED LERP    **
    **                    **
    ***********************/
    float normalizedLerp(float a, float b, float t, float minT, float maxT){
        //Normalize t to be within the range [0,1]
        float normalizedT = (t - minT) / (maxT - minT);
        return lerp(a, b, normalizedT);
    }

    /***********************
    **                    **
    ** NORMALIZED STANDARD**
    **                    **
    ***********************/
    float normalize(float value, float minValue, float maxValue) {
        return (value - minValue) / (maxValue - minValue);
    }


public:
    /***********************
    **                    **
    **     Apply Easings  **
    **                    **
    ***********************/
    // For the purposes of basic tweens on an x,y plane, the below func is sufficient, however
    // not recommended for game logic or interaction-based animations
    // Match of "use()"
    void keyFrames(
        Color& color,
        float& x,
        float& y,
        float& h,
        float& w,
        int& r, int& g, int& b, int& a,
        vector<Vector2> positions,
        string tweenType,
        bool& printDebugs,
        bool& amAlive,
        bool& tweenAlpha,
        bool& tweenColors,
        int timeToDie
    ) {

    // Check which tweens to call
    if (initTweenDirSwtch == false) {
        if ( positions[i].x > (x) ) { tweenRight = true; tweenLeft  = false; }
        if ( positions[i].x < (x) ) { tweenLeft  = true; tweenRight = false; }
        if ( positions[i].y > (y) ) { tweenDown  = true; tweenUp    = false; }
        if ( positions[i].y < (y) ) { tweenUp    = true; tweenDown  = false; }
        zeroToOneProgressEaseOut = 0.0;
        zeroToOneProgressEaseIn = 0.0;
        initTweenDirSwtch = true;
    }

    // Raylib functions and value conversions
    int gameTotalSeconds = GetTime(); 
    float timeInSeconds = static_cast<float>(gameTotalSeconds);

    // Set and use tween type chosen by user
    if (tweenType == "easeOut"){
        factor = std::max(easeOut(zeroToOneProgressEaseOut), 0.0f);
        zeroToOneProgressEaseOut += animationSpeed * TimeClass::getDeltaTime();
    }
    if (tweenType == "easeIn"){
        factor = std::max(easeIn(zeroToOneProgressEaseIn), 0.0f);
        zeroToOneProgressEaseIn += animationSpeed * TimeClass::getDeltaTime();
    }

    // Print Debug Vals
    if (printDebugs){
        std::string factor_str  = std::to_string(factor);
        std::string x_str  = std::to_string(x);
        DrawText(factor_str.c_str(), x, (y + 100), 20, GREEN); //0.0 to 0.1
        DrawText(x_str.c_str(), x, (y + 120), 20, GREEN); // init to end
    }


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

    // NOTES: for reference only:
    /***********************
    **                    **
    **     LERP           **
    **                    **
    ***********************/
    // float lerp(float a, float b, float t){
    //     return a + t * (b - a);
    // }

    /***********************
    **                    **
    ** NORMALIZED LERP    **
    **                    **
    ***********************/
    // float normalizedLerp(float a, float b, float t, float minT, float maxT){
    //     //Normalize t to be within the range [0,1]
    //     float normalizedT = (t - minT) / (maxT - minT);
    //     return lerp(a, b, normalizedT);
    // }


    if (amAlive) {

    }

if (tweenAlpha) {
    currentX = x;
    //DrawRectangleV({ x, y }, { 2, 2 }, RED);

    // Lerp alpha ***********************************************************************************
        // This technique gradualy increases the alpha as the factor increases
        // factor is based on tween progression
        // float alpha = normalizedLerp(0.0f,255.0f,factor,0.0f, 0.090f);
        // int alphaInt = static_cast<int>(alpha);
        // string alpha_str = to_string(alpha);
        // DrawText(alpha_str.c_str(), 10, 100, 20, GREEN);
        // color = {0,255,0,alphaInt};

    // Lerp distance / speed ************************************************************************
    // Check if it's the first index
    if (i > 0) {
        
        deltaX = currentX - previouX;
        derivedSpeed = deltaX / GetFrameTime(); // Calculate derived speed
        derivedSpeed = fabs(derivedSpeed);      // Absolute value of speed

        // Define range for brightness and speed
        // i = where im headed
        // i - 1 = where im coming from
        float distance = fabs(positions[i].x - positions[i-1].x); 
      
        float minSpeed = 0.0f;
        float maxSpeed = distance / 2;  // pixel distance to center of (i) - (i - 1)

        float minBrightness = 0.0f;
        float maxBrightness = 255.0f;

        // Normalize speed within the defined range
        // Clamping derived speed between min and max speeds
        float normalizedSpeed = clamp(derivedSpeed, minSpeed, maxSpeed) / maxSpeed;

        // Lerp normalized speed to brightness within the defined range
        float brightness = lerp(minBrightness, maxBrightness, normalizedSpeed);
 
        // Apply brightness
        color = {0, 255, 0, brightness};
    } else {
        // Handle the case when i is the first index
        // For example, you can set default brightness or skip the calculation
        // color = {0, 255, 0, 255}; // Default to maximum brightness
    }

    // First assignment of x on first call of this loop:
    previouX = x;
    
}

    if (tweenColors) {

    }

        // Dont exceed positions vector list
    if (i == positions.size()) {
        i = 0;
    }
    
    }
};
