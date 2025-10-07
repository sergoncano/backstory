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
        if(steps[i].next==-1*MAX_DIALOGUE_STEPS) break;
        if(steps[i].next == -1) i++;
        else if(steps[i].next < -1) {
            int choice = 0;
            while (choice <= 0 || choice > -1*steps[i].next) {
                for(int j = 1; j <= -1*steps[i].next; j++) {
                    char number = (char) ('0' + j);
                    char str[2] = { number, '\0' };
                    print_progressively(str);
                    print_progressively(COUNTER_TOKEN);
                    print_progressively(steps[i+j].text);
                }
                print_progressively(PROMPT_TOKEN);
                scanf(" %d", &choice);
                if(choice <= 0 || choice > -1*steps[i].next)
                    while ((getchar()) != '\n');
            }
            i = steps[i + choice].next;
        } else i = steps[i].next;
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

