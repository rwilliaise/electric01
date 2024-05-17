
#include "particle.h"

void particles_update(struct particle *particles, size_t count) {
    for (int i = 0; i < count; i++) {
        struct particle *A = &particles[i];
        for (int j = 0; j < count; j++) {
            struct particle *B = &particles[j];
            if (A == B) continue;
            vec2d r = vec2d_sub(A->pos, B->pos);

        }
    }
}

void particle_integrate(struct particle *P, float dt) {
    
}

