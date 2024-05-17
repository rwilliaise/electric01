
#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stddef.h>
#include "vec2d.h"

struct particle {
    double charge; // q
    double mass;
    vec2d pos, vel;
};

void particles_update(struct particle *particles, size_t count);
void particle_integrate(struct particle *P, float dt);
void particle_draw(struct particle *P);

#endif // PARTICLE_H_
