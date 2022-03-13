
#include "colors.h"

#include <limits.h>
#include <math.h>
#include <stdlib.h>

float truncate(float f)
{
    // Nearest value in the range [0, 1]
    return fmax(0.0, fmin(f, 1.0));
}

struct color randomcolor(void)
{
    struct color rgb;
    // Choose random values for R, G, and B
    rgb.r = (float) rand() / INT_MAX;
    rgb.g = (float) rand() / INT_MAX;
    rgb.b = (float) rand() / INT_MAX;
    return rgb;
}

struct color fromhsv(float h, float s, float v)
{
    // Make sure H, S, and V are within the acceptable range
    h = truncate(h);
    s = truncate(s);
    v = truncate(v);

    // Calculate the chroma and minimum brightness values
    float chroma = v * s;
    float x = chroma * (1 - fabs(fmod(h * 6, 2) - 1));
    float m = v - chroma;

    float r1 = 0.0;
    float g1 = 0.0;
    float b1 = 0.0;

    // Assign RGB values based on hue
    if (h < 0.166666) {
        r1 = chroma;
        g1 = x;
    } else if (h < 0.333333) {
        r1 = x;
        g1 = chroma;
    } else if (h < 0.500000) {
        g1 = chroma;
        b1 = x;
    } else if (h < 0.666666) {
        g1 = x;
        b1 = chroma;
    } else if (h < 0.833334) {
        r1 = x;
        b1 = chroma;
    } else {
        r1 = chroma;
        b1 = x;
    }

    // Increase each value by the minimum
    struct color rgb;
    rgb.r = r1 + m;
    rgb.g = g1 + m;
    rgb.b = b1 + m;

    return rgb;
}

