
#ifndef COLORICIOUS_OPTIONS_H
#define COLORICIOUS_OPTIONS_H

#include <stdbool.h>

struct options
{
    float period;
    float saturation;
    float value;

    bool escaped;

    int num_files;
    const char **files;
};

// Parse command-line options
void parse_options(struct options *, int, char **);

// Free memory associated with options
void clear_options(struct options *);

#endif

