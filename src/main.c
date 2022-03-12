
#include <stdio.h>
#include <stdlib.h>

#include "options.h"
#include "colors.h"
#include "output.h"

int main(int argc, char **argv)
{
    struct options opts;
    parse_options(&opts, argc, argv);

    int line = 0;
    int column = 0;
    int c;

    //
    // Colorize contents of stdin
    //

    // Get and print one char at a time
    while ((c = getchar()) != -1) {

        if (c == '\n') {

            line += 2;
            column = 0;

            // Remove formatting at the end of each line
            uncolor();

        } else {

            column += 1;

            // Print with an appropriate hue
            float hue = 0.02857 * ((column + line) % 35);
            color24bit(fromhsv(hue, opts.saturation, opts.value));

        }

        putchar(c);
    }

    // Remove formatting in case the input
    // did not end with a newline character
    uncolor();

    return EXIT_SUCCESS;
}

