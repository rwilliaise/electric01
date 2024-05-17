
#ifndef ELECTRIC01_H_
#define ELECTRIC01_H_

#define C_INV_SQ 1.112560e-17
#define K_CONSTANT 1.419257e12
#define ELECTRON_MASS 9.109384e-31
#define ELEMENTARY_CHARGE 1.602176e-19
#define VACUUM_PERMEABILITY 1.256637e-6

#define RENDER_SCALE 1e4
#define TIME_SCALE 1e-6

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BOX_BOUNDS 384

#define dbgd(x) printf(#x ": %f\n", x)
#define dbgb(x) printf(#x ": %s\n", x ? "true" : "false")

double clamp(double x, double min, double max);

#endif // ELECTRIC00_H_
