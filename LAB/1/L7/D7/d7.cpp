#include <math.h>

double genRandom(double L) {
    static double r = 1;
    r = exp(-L * r) * L;
    return r;
}
