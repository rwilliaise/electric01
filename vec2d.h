
#ifndef VEC2D_H_
#define VEC2D_H_

typedef struct {
    double x, y;
} vec2d;

double vec2d_dot(vec2d a, vec2d b);
double vec2d_len_sq(vec2d a);
double vec2d_len(vec2d a);
double vec2d_cross(vec2d a, vec2d b); // ""cross"" product: a.x * b.y - a.y * b.x

vec2d vec2d_scale(vec2d a, double scale);
vec2d vec2d_shrink(vec2d a, double scale);
vec2d vec2d_normalize(vec2d a);
vec2d vec2d_add(vec2d a, vec2d b);
vec2d vec2d_sub(vec2d a, vec2d b);

#endif // VEC2D_H_
