
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static float truncate(float);

struct color
{
    float r;
    float g;
    float b;
};

struct color randomcolor(void);
struct color fromhsv(float, float, float);

static void color8bit(struct color);
static void color24bit(struct color);
static void uncolor(void);

int main(void)
{
    struct color rgb;
    float hue = 0.0;
    int c;

    srand(time(NULL));

    while ((c = getchar()) != -1) {

        color24bit(fromhsv(hue, 1, 1));
        putchar(c);

        if (hue < 1.0) {
            hue += 0.01;
        } else {
            hue = 0.0;
        }
    }

    uncolor();

    return EXIT_SUCCESS;
}

static float truncate(float f)
{
    return fmax(0.0, fmin(f, 1.0));
}

struct color randomcolor(void)
{
    struct color rgb;
    rgb.r = (float) rand() / INT_MAX;
    rgb.g = (float) rand() / INT_MAX;
    rgb.b = (float) rand() / INT_MAX;
    return rgb;
}

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

static void color8bit(struct color rgb)
{
    int rc = round(6 * truncate(rgb.r));
    int gc = round(6 * truncate(rgb.g));
    int bc = round(6 * truncate(rgb.b));
    int cc = (36 * rc) + (6 * gc) + bc + 16;
    printf("\e[38;5;%dm", cc);
}

static void color24bit(struct color rgb)
{
    int rc = round(255 * truncate(rgb.r));
    int gc = round(255 * truncate(rgb.g));
    int bc = round(255 * truncate(rgb.b));
    printf("\e[38;2;%d;%d;%dm", rc, gc, bc);
}

static void uncolor(void)
{
    printf("\e[0m");
}

