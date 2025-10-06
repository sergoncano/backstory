#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

struct step {
    char * text;
    int next;
};

typedef struct step step_t ;

#endif
