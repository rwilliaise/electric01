
#include <math.h>
#include <raylib.h>
#include <stdio.h>

#include "electric01.h"
#include "particle.h"
#include "vec2d.h"
#include "field.h"

void particles_update(struct particle *particles, size_t count) {
    for (int i = 0; i < count; i++) {
        struct particle *A = &particles[i];
        struct field field = field_query(particles, count, A->pos);

        // F = qE + qv x B
        vec2d F = vec2d_scale(vec2d_add(field.E_field, vec2d_scale(A->vel, field.B_field)), A->charge);
        A->acc = vec2d_shrink(F, A->mass);
    }
}

void particle_integrate(struct particle *P, float dt) {
    vec2d dpos = vec2d_add(vec2d_scale(P->vel, dt), vec2d_scale(P->acc, 0.5 * dt * dt));
    P->pos = vec2d_add(P->pos, dpos);
    P->vel = vec2d_add(P->vel, vec2d_scale(P->acc, dt));

    double bounds = BOX_BOUNDS / (double) RENDER_SCALE;

    if (P->pos.x <= 0 || P->pos.x >= bounds) {
        P->pos.x = clamp(P->pos.x, 0, bounds);
        P->vel.x = -P->vel.x * 0.8;
    }
    if (P->pos.y <= 0 || P->pos.y >= bounds) {
        P->pos.y = clamp(P->pos.y, 0, bounds);
        P->vel.y = -P->vel.y * 0.8;   
    }
}

void particle_draw(struct particle *P) {
    float box_x = (WINDOW_WIDTH - BOX_BOUNDS) / 2.0f;
    float box_y = (WINDOW_HEIGHT - BOX_BOUNDS) / 2.0f;

    double radius = clamp(fabs(P->charge / ELEMENTARY_CHARGE), 1, 4);

    DrawCircle(box_x + P->pos.x * RENDER_SCALE, box_y + P->pos.y * RENDER_SCALE, radius, P->charge < 0 ? BLUE : RED);
}

