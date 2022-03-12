
#ifndef COLORICIOUS_OUTPUT_H
#define COLORICIOUS_OUTPUT_H

#include "colors.h"

// Set color in 8-bit mode (xterm-256color)
void color8bit(struct color);

// Set color in 24-bit mode (most modern terminals)
void color24bit(struct color);

// Remove color formatting
void uncolor(void);

#endif

