
#ifndef FIELD_H_
#define FIELD_H_

#include <raylib.h>

#include "particle.h"
#include "vec2d.h"

#define MAP_RESOLUTION 128

struct field {
    vec2d E_field;
    double B_field;
};

enum map_type {
    map_type_magnetic,
    map_type_electric,
    map_type_electromagnetic,
};

struct map {
    Image img;
    Texture2D txt;
    enum map_type type;
};

struct field field_query(struct particle *particles, size_t count, vec2d pos);

struct map map_create(enum map_type type);
void map_update(struct map *M, struct particle *particles, size_t count);
void map_draw(struct map *M);

#endif // FIELD_H_
