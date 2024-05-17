
#include <math.h>

#include "vec2d.h"

double vec2d_dot(vec2d a, vec2d b) {
    return a.x * b.x + a.y * b.y;
}

double vec2d_len_sq(vec2d a) {
    return vec2d_dot(a, a);
}

double vec2d_len(vec2d a) {
    return sqrt(vec2d_len_sq(a));
}

double vec2d_cross(vec2d a, vec2d b) {
    return a.x * b.y - a.y * b.x;
}

vec2d vec2d_scale(vec2d a, double scale) {
    return (vec2d) {
        a.x * scale,
        a.y * scale,
    };
}

vec2d vec2d_shrink(vec2d a, double scale) {
    return (vec2d) {
        a.x / scale,
        a.y / scale,
    };
}

vec2d vec2d_normalize(vec2d a) {
    return vec2d_shrink(a, vec2d_len(a));
}

vec2d vec2d_add(vec2d a, vec2d b) {
    return (vec2d) {
        a.x + b.x,
        a.y + b.y,
    };
}

vec2d vec2d_sub(vec2d a, vec2d b) {
    return (vec2d) {
        a.x - b.x,
        a.y - b.y,
    };
}

