
#include "options.h"

#include <stdlib.h>

void parse_options(struct options *opts)
{
    char *envstr;

    opts->saturation = 0.65;
    opts->value = 0.9;

    if ((envstr = getenv("COLORICIOUS_SATURATION")) != NULL) {
        opts->saturation = atof(envstr);
    }

    if ((envstr = getenv("COLORICIOUS_VALUE")) != NULL) {
        opts->value = atof(envstr);
    }
}

