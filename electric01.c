
#include "electric01.h"
#include <raylib.h>
#include <stdlib.h>

#include "field.h"
#include "particle.h"
#include "vec2d.h"

#define PARTICLES_COUNT 32

double randf(double min, double max) {
    double r = rand() / (double) RAND_MAX;
    return r * (max - min) + min;
}

double clamp(double x, double min, double max) {
    if (x < min)
        return min;
    if (x > max)
        return max;
    return x;
}

int main(void) {
    InitWindow(640, 480, "electric01");

    struct particle particles[PARTICLES_COUNT];

    double bounds = BOX_BOUNDS / (double) RENDER_SCALE;
    for (int i = 0; i < PARTICLES_COUNT; i++) {
        struct particle *P = &particles[i];
        double scale = randf(-4, 4);
        P->charge = scale * ELEMENTARY_CHARGE;
        P->mass = scale * ELECTRON_MASS;
        P->pos = (vec2d) {
            randf(0, bounds),
            randf(0, bounds),
        };
        P->vel = (vec2d) {
            randf(0, 2000),
            randf(0, 2000),
        };
        P->acc = VEC2D_ZERO;
    }

    SetTargetFPS(60);

    struct map magnetic_field_map = map_create(map_type_magnetic);

    while (!WindowShouldClose()) {
        float box_x = (WINDOW_WIDTH - BOX_BOUNDS) / 2.0f;
        float box_y = (WINDOW_HEIGHT - BOX_BOUNDS) / 2.0f;

        particles_update(particles, PARTICLES_COUNT);

        BeginDrawing();
            ClearBackground(WHITE);

            float dt = GetFrameTime();
            for (int i = 0; i < PARTICLES_COUNT; i++) {
                struct particle *P = &particles[i];
                particle_integrate(P, dt * TIME_SCALE);
                particle_draw(P);
            }

            map_update(&magnetic_field_map, particles, PARTICLES_COUNT);
            map_draw(&magnetic_field_map);

            DrawRectangleLinesEx(
                (Rectangle) {
                    box_x,
                    box_y,
                    BOX_BOUNDS,
                    BOX_BOUNDS,
                },
                3,
                BLACK
            );
        EndDrawing();
    }

    return 0;
}
