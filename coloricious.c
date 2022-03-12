
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//
// Color definitions
//

static float truncate(float);

struct color
{
    float r;
    float g;
    float b;
};

struct color randomcolor(void);
struct color fromhsv(float, float, float);

//
// Color printing functions
//

static void color8bit(struct color);
static void color24bit(struct color);
static void uncolor(void);

int main(void)
{
    struct color rgb;
    int c;

    int line = 0;
    int column = 0;

    // Get and print one char at a time
    while ((c = getchar()) != -1) {

        if (c == '\n') {

            line += 1;
            column = 0;

            // Print with an appropriate hue
            float hue = 0.01 * ((column + line) % 100);
            color24bit(fromhsv(hue, 1, 1));

        } else {

            // Remove formatting at the end of each line
            column += 1;
            uncolor();

        }

        putchar(c);
    }

    // Remove formatting in case the input
    // did not end with a newline character
    uncolor();

    return EXIT_SUCCESS;
}

// Keep a float within a certain range
static float truncate(float f)
{
    return fmax(0.0, fmin(f, 1.0));
}

// Get a random RGB color
struct color randomcolor(void)
{
    struct color rgb;
    rgb.r = (float) rand() / INT_MAX;
    rgb.g = (float) rand() / INT_MAX;
    rgb.b = (float) rand() / INT_MAX;
    return rgb;
}

// Convert from HSV to RGB
struct color fromhsv(float h, float s, float v)
{
    h = truncate(h);
    s = truncate(s);
    v = truncate(v);

    float chroma = v * s;
    float x = chroma * (1 - fabs(fmod(h * 6, 2) - 1));
    float m = v - chroma;

    float r1 = 0.0;
    float g1 = 0.0;
    float b1 = 0.0;

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

    struct color rgb;
    rgb.r = r1 + m;
    rgb.g = g1 + m;
    rgb.b = b1 + m;

    return rgb;
}

// Switch to a color in 8-bit mode (xterm-256color)
static void color8bit(struct color rgb)
{
    int rc = round(6 * truncate(rgb.r));
    int gc = round(6 * truncate(rgb.g));
    int bc = round(6 * truncate(rgb.b));
    int cc = (36 * rc) + (6 * gc) + bc + 16;
    printf("\e[38;5;%dm", cc);
}

// Switch to a color in 24-bit mode (most modern terminals)
static void color24bit(struct color rgb)
{
    int rc = round(255 * truncate(rgb.r));
    int gc = round(255 * truncate(rgb.g));
    int bc = round(255 * truncate(rgb.b));
    printf("\e[38;2;%d;%d;%dm", rc, gc, bc);
}

// Remove color formatting
static void uncolor(void)
{
    printf("\e[0m");
}

