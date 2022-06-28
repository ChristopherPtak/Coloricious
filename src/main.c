
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "options.h"
#include "colors.h"
#include "output.h"

static void colorize_file(FILE *, struct options *);

int main(int argc, char **argv)
{
    struct options opts;
    parse_options(&opts, argc, argv);

    // Print a colorized version of stdin
    colorize_file(stdin, &opts);

    // Remove formatting in case the input
    // did not end with a newline character
    uncolor(opts.escaped);

    return EXIT_SUCCESS;
}

static void colorize_file(FILE *f, struct options *opts)
{
    int line = 0;
    int column = 0;
    int c;

    // Get and print one char at a time
    while ((c = fgetc(f)) != -1) {

        if (c == '\n') {

            line += 2;
            column = 0;

            // Remove formatting at the end of each line
            uncolor(opts->escaped);

        } else {

            column += 1;

            // Only if character is printable
            if (isprint(c) && (! isspace(c))) {
                // Print with an appropriate hue
                float distance = column + line;
                float hue = fmod(distance, opts->period) / opts->period;
                color24bit(fromhsv(hue, opts->saturation, opts->value),
                           opts->escaped);
            }

        }

        putchar(c);
    }
}

