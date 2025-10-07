#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "constants.h"
#include "script.h"
#include "types.h"

#include "map.c"
#include "front.c"

void parse_script(char* script);
void parse_step(char** script);
step_t link_script(int index);
void format_steps();
void free_step_memory();

char dialogue_steps[MAX_DIALOGUE_STEPS][MAX_DIALOGUE_LENGTH];
char dialogue_jump_to[MAX_DIALOGUE_STEPS][MAX_LABEL_LENGTH];
int no_dialogue_steps = 0;

step_t steps[MAX_DIALOGUE_STEPS];

int main(int argc, char *argv[]) {
    parse_script(SCRIPT);
    map_insert(END_KEYWORD, -1 * MAX_DIALOGUE_STEPS);
    format_steps();
    print_script(steps, no_dialogue_steps);
    free_step_memory();
}

void format_steps() {
    for(int i = 0; i < no_dialogue_steps; i++) {
        steps[i].next = map_get(dialogue_jump_to[i]);
        steps[i].text = malloc(sizeof(dialogue_steps[i]));
        strcpy(steps[i].text, dialogue_steps[i]);
    }
}

void free_step_memory() {
    for(int i = 0; i < no_dialogue_steps; i++) {
        free(steps[i].text);
    }
}

void parse_script(char* script) {
    while(*script != '\0') {
        parse_step(&script);
        no_dialogue_steps++;
    }
}

void parse_step(char** script_ptr) {
    char* script = *script_ptr;
    if(*script == JUMP_CHARACTER) {
        script++;
        char label_buf[MAX_LABEL_LENGTH];
        int i = 0;
        while(*script != JUMP_CHARACTER) {
            label_buf[i] = *script;
            script++;
            i++;
        }
        label_buf[i] = '\0';
        script++;
        map_insert(label_buf, no_dialogue_steps);
    }
    char buf[MAX_DIALOGUE_LENGTH];
    int i = 0;
    while(*script != BREAK_CHARACTER) {
        buf[i] = *script;
        script++;
        i++;
    }
    buf[i] = '\0';
    strcpy(dialogue_steps[no_dialogue_steps], buf);
    if(*(script+1) != BREAK_CHARACTER) {
        char label_buf[MAX_LABEL_LENGTH];
        int j = 0;
        script++;
        while(*script != BREAK_CHARACTER) {
            label_buf[j] = *script;
            j++;
            script++;
        }
        script++;
        label_buf[j] = '\0';
        strcpy(dialogue_jump_to[no_dialogue_steps], label_buf);
    } else {
        script += 2;
    }
    *script_ptr = script;
}
