
#include "output.h"

#include <math.h>
#include <stdio.h>

#include "colors.h"

void color8bit(struct color rgb)
{
    int rc = round(6 * truncate(rgb.r));
    int gc = round(6 * truncate(rgb.g));
    int bc = round(6 * truncate(rgb.b));
    int cc = (36 * rc) + (6 * gc) + bc + 16;
    printf("\e[38;5;%dm", cc);
}

void color24bit(struct color rgb)
{
    int rc = round(255 * truncate(rgb.r));
    int gc = round(255 * truncate(rgb.g));
    int bc = round(255 * truncate(rgb.b));
    printf("\e[38;2;%d;%d;%dm", rc, gc, bc);
}

void uncolor(void)
{
    printf("\e[0m");
}

