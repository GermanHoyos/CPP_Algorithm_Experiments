#include "MasterHeader.h"

inline void animation_1(float& x, float& y) {
    x++;
    y++;
};

inline void animation_2(Vector2& start) {
    start.x++;
};

inline void animation_3(float& x, float& y, float time) {
    x++;
}


inline float easeIn(float t) {
    return t * t; // x^2 {0<x<1}
}
// inline void animation_3(float& x, float& y, float time) {

//     Vector2 end = {(x + 50.0f),y};
//     float factor = easeIn(t);

//     float tweenX = x + (end.x - x) * factor;

// }

