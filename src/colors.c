
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
    struct color rgb;
    rgb.r = 0.0;
    rgb.g = 0.0;
    rgb.b = 0.0;

    // Make sure H, S, and V are within the acceptable range
    h = truncate(h);
    s = truncate(s);
    v = truncate(v);

    // Calculate the chroma and minimum brightness values
    float chroma = v * s;
    float x = chroma * (1 - fabs(fmod(h * 6, 2) - 1));
    float m = v - chroma;

    // Assign RGB values based on hue
    if (h < 0.166666) {
        rgb.r = chroma;
        rgb.g = x;
    } else if (h < 0.333333) {
        rgb.r = x;
        rgb.g = chroma;
    } else if (h < 0.500000) {
        rgb.g = chroma;
        rgb.b = x;
    } else if (h < 0.666666) {
        rgb.g = x;
        rgb.b = chroma;
    } else if (h < 0.833334) {
        rgb.r = x;
        rgb.b = chroma;
    } else {
        rgb.r = chroma;
        rgb.b = x;
    }

    // Increase each value by the minimum
    rgb.r += m;
    rgb.g += m;
    rgb.b += m;

    return rgb;
}

