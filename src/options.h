
#ifndef COLORICIOUS_OPTIONS_H
#define COLORICIOUS_OPTIONS_H

struct options
{
    float period;
    float saturation;
    float value;
};

// Parse command-line options
void parse_options(struct options *, int, char **);

#endif

