
#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stddef.h>
#include "vec2d.h"

#define PARTICLE_INTERACT_DEADZONE 1e-10

struct particle {
    double charge; // q
    double mass;
    vec2d pos, vel, acc;
};

void particles_update(struct particle *particles, size_t count);
void particle_integrate(struct particle *P, float dt);
void particle_draw(struct particle *P);

#endif // PARTICLE_H_
