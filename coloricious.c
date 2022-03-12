
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

        color24bit(r, g, b);
        putchar(c);
    }

    uncolor();

    return EXIT_SUCCESS;
}

static void color24bit(float r, float g, float b)
{
    int rc = round(255 * fmax(0.0, fmin(r, 1.0)));
    int gc = round(255 * fmax(0.0, fmin(g, 1.0)));
    int bc = round(255 * fmax(0.0, fmin(b, 1.0)));
    printf("\e[38;2;%d;%d;%dm", rc, gc, bc);
}

static void uncolor(void)
{
    printf("\e[0m");
}

