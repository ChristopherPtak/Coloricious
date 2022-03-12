
#ifndef COLORICIOUS_COLORS_H
#define COLORICIOUS_COLORS_H

float truncate(float);

struct color
{
    float r;
    float g;
    float b;
};

struct color randomcolor(void);
struct color fromhsv(float, float, float);

#endif

