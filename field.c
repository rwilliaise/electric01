
#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "field.h"
#include "electric01.h"
#include "particle.h"

struct field field_query(struct particle *particles, size_t count, vec2d pos) {
    struct field out = (struct field) { VEC2D_ZERO, 0 };

    for (int j = 0; j < count; j++) {
        struct particle *B = &particles[j];
        vec2d r = vec2d_sub(pos, B->pos);
        double n = vec2d_len(r);
        vec2d rhat = vec2d_shrink(r, n);
        double n2 = n * n;

        if (n < PARTICLE_INTERACT_DEADZONE) continue;
        
        vec2d calc_field = vec2d_scale(rhat, (K_CONSTANT * B->charge) / n2);
        out.B_field += C_INV_SQ * vec2d_cross(B->vel, calc_field);
        out.E_field = vec2d_add(out.E_field, calc_field);
    }
    return out;
}

struct map map_create(enum map_type type) {
    Image img = GenImageColor(MAP_RESOLUTION, MAP_RESOLUTION, RED);
    Texture2D txt = LoadTextureFromImage(img);

    return (struct map) {
        img,
        txt,
        type,
    };
}

void map_update(struct map *M, struct particle *particles, size_t count) {
    double map_scale = BOX_BOUNDS / (double) (MAP_RESOLUTION * RENDER_SCALE);
    Color *pixels = M->img.data;

    for (int i = 0; i < MAP_RESOLUTION; i++) {
        for (int j = 0; j < MAP_RESOLUTION; j++) {
            vec2d pos = (vec2d) {
                map_scale * (i + 0.5),
                map_scale * (j + 0.5),
            };

            struct field field = field_query(particles, count, pos);

            if (M->type == map_type_magnetic) {
                uint8_t B = clamp(fabs(field.B_field * 1e16), 0, 255);
                Color *color = &pixels[j * MAP_RESOLUTION + i];
                color->r = field.B_field > 0 ? B : 0;
                color->g = 0;
                color->b = field.B_field < 0 ? B : 0;
                color->a = B;
            }
        }
    }
    UpdateTexture(M->txt, M->img.data);
}

void map_draw(struct map *M) {
    double map_scale = BOX_BOUNDS / (double) MAP_RESOLUTION;
    float box_x = (WINDOW_WIDTH - BOX_BOUNDS) / 2.0f;
    float box_y = (WINDOW_HEIGHT - BOX_BOUNDS) / 2.0f;

    DrawTextureEx(M->txt, (Vector2) { box_x, box_y }, 0, map_scale, (Color) { 255, 255, 255, 63 });
}
