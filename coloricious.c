
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static float truncate(float);

static void color8bit(float, float, float);
static void color24bit(float, float, float);
static void uncolor(void);

int main(void)
{
    int c;

    srand(time(NULL));

    while ((c = getchar()) != -1) {

        float r = (float) rand() / INT_MAX;
        float g = (float) rand() / INT_MAX;
        float b = (float) rand() / INT_MAX;

        color8bit(r, g, b);
        putchar(c);
    }

    uncolor();

    return EXIT_SUCCESS;
}

static float truncate(float f)
{
    return fmax(0.0, fmin(f, 1.0));
}

static void color8bit(float r, float g, float b)
{
    int rc = round(6 * truncate(r));
    int gc = round(6 * truncate(g));
    int bc = round(6 * truncate(b));
    int cc = (36 * rc) + (6 * gc) + bc + 16;
    printf("\e[38;5;%dm", cc);
}

static void color24bit(float r, float g, float b)
{
    int rc = round(255 * truncate(r));
    int gc = round(255 * truncate(g));
    int bc = round(255 * truncate(b));
    printf("\e[38;2;%d;%d;%dm", rc, gc, bc);
}

static void uncolor(void)
{
    printf("\e[0m");
}

