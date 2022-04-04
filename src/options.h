
#ifndef COLORICIOUS_OPTIONS_H
#define COLORICIOUS_OPTIONS_H

#include <stdbool.h>

struct options
{
    float period;
    float saturation;
    float value;

    bool escaped;
};

// Parse command-line options
void parse_options(struct options *, int, char **);

#endif

