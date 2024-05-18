
#ifndef ELECTRIC01_H_
#define ELECTRIC01_H_

#define C_INV_SQ 1.112560e-17
#define K_CONSTANT 1.419257e12
#define ELECTRON_MASS 9.109384e-31
#define ELEMENTARY_CHARGE 1.602176e-19
#define VACUUM_PERMEABILITY 1.256637e-6

#define RENDER_SCALE 1e3
#define TIME_SCALE 5e-5

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define BOX_BOUNDS 512

#define PARTICLES_COUNT 32

#define dbgd(x) printf(#x ": %f\n", x)
#define dbgb(x) printf(#x ": %s\n", x ? "true" : "false")

double clamp(double x, double min, double max);

#endif // ELECTRIC00_H_
