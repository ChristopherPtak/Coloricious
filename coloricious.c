
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

static void color8bit(struct color);
static void color24bit(struct color);
static void uncolor(void);

int main(void)
{
    struct color rgb;
    int c;

    srand(time(NULL));

    while ((c = getchar()) != -1) {
        color24bit(randomcolor());
        putchar(c);
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

