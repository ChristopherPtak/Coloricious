
#ifndef COLORICIOUS_COLORS_H
#define COLORICIOUS_COLORS_H

// Keep a value between 0 and 1
float truncate(float);

struct color
{
    float r;
    float g;
    float b;
};

// Ways of obtaining color values
struct color randomcolor(void);
struct color fromhsv(float, float, float);

#endif

