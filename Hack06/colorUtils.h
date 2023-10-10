/**
 * Author: Dade Lenox
 * Date: 2023-05-10
 *
 * This program is a library that can convert
 * rgb to cmyk and vice versa
*/

#ifndef ERROR_H
#define ERROR_H

typedef enum {
    NO_ERROR,
    OUT_OF_BOUNDS,
    _NULL,
} ErrorCodes;

#endif /* ERROR_H */

/**
 * This function is to take the largest
 * of three values
*/
double max(double r, double g, double b);

/**
 * This function is to round off to the
 * nearest 100th
*/
double roundCenti(double a);


/**
 * This function is to convert an RGB value into a CMYK value.
*/
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

/**
 * This function is to convert from a CMYK value into a RGB value.
*/
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);