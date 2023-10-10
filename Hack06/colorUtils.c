#include <stdlib.h>
#include <math.h>

#include "colorUtils.h"


double max(double a, double b, double c) {
    return (a > b) ? (a > c ? a : c) : (b > c ? b: c);
}

double roundCenti(double a) {
    return round(a * 100) / 100.0;
}

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {

    if (c == NULL || m == NULL || y == NULL || k == NULL) {
        return _NULL;
    } if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0) {
        return OUT_OF_BOUNDS;
    }


    double rPrime = (r / 255.0);
    double gPrime = (g / 255.0);
    double bPrime = (b / 255.0);


    *k = 1 - max(rPrime, gPrime, bPrime);

    if (*k != 1) {

        *c = (1 - rPrime - *k) / (1 - *k);
        *m = (1 - gPrime - *k) / (1 - *k);
        *y = (1 - bPrime - *k) / (1 - *k);

    } else {
        *c = *m = *y = 0;
    }


    return NO_ERROR;
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {

    if (r == NULL || g == NULL || b == NULL) {
        return _NULL;
    } if (c > 1.0 || m > 1.0 || y > 1.0 || k > 1.0 || c < 0.0 || m < 0.0 || y < 0.0 || k < 0.0) {
        return OUT_OF_BOUNDS;
    }

    *r = round(255 * (1 - c) * (1 - k));
    *g = round(255 * (1 - m) * (1 - k));
    *b = round(255 * (1 - y) * (1 - k));

    return NO_ERROR;
}