#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

#include "constants.h"
#include "types.h"

void print_script(step_t *steps, int no_steps);
void print_progressively(char* string);

void print_script(step_t *steps, int no_steps) {
    int i = 0;
    while(i < no_steps) {
        print_progressively(steps[i].text);
        if(steps[i].next == -1) i++;
        else i = steps[i].next;
        if(i==-2) break;
        scanf("%*c");
    }
}

void print_progressively(char* string) {
    while(*string != '\0') {
        printf("%c", *string);
        fflush(stdout);
        string++;
        usleep(PRINT_DELAY_MS * 1000 * (*string == '\n' ? PRINT_DELAY_NEWLINE_MULTIPLIER : 1));
    }
}

