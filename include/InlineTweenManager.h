// #pragma once

// //EaseIn
// inline float easeIn(float t) {
//     return t * t; // x^2 {0<x<1}
// }

inline Vector2 easeInApply(Vector2 start, Vector2 end, float t, bool flip) {
    float factor = easeIn(t); // 0.0 -> 1.0
    Vector2 xy_returned;
    if (!flip) {
        float x = start.x + (end.x - start.x) * factor;
        float y = start.y + (end.y - start.y) * factor;
        xy_returned = { x, y };
    }
    if (flip) {
        float x = start.x - (start.x - end.x) * factor;
        float y = start.y + (end.y - start.y) * factor;
        xy_returned = { x, y };
    }
    return xy_returned;
}


// //EaseOut
// inline float easeOut(float t) { //GREEN
//     return 1 - (1 - t) * (1 - t); //1-(x-1)^2 {0<x<1}
// }

// inline Vector2 easeOutApply(Vector2 start, Vector2 end, float t, bool flip) {
//     float factor = easeOut(t);
//     Vector2 xy_returned;

//     if (!flip) //right
//     {
//         float x = start.x + (end.x - start.x) * factor;
//         float y = start.y + (end.y - start.y) * factor;
//         xy_returned = { x, y };
//     }
//     if (flip) //left
//     {
//         float x = start.x - (start.x - end.x) * factor;
//         float y = start.y + (end.y - start.y) * factor;
//         xy_returned = { x, y };
//     }
//     return xy_returned;
// }