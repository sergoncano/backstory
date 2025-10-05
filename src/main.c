#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "constants.h"
#include "script.h"
#include "map.c"

void print_progressively(char* string);
void parse_script(char* script);
void parse_step(char** script);

char dialogue_steps[MAX_DIALOGUE_STEPS][MAX_DIALOGUE_LENGTH];
char dialogue_jump_to[MAX_DIALOGUE_STEPS][MAX_LABEL_LENGTH];
int no_dialogue_steps = 0;

int main(int argc, char *argv[]) {
    parse_script(SCRIPT);
    for(int i = 0; i < no_dialogue_steps; i++) {
        print_progressively(dialogue_steps[i]);
        scanf("%*c");
    }
}

void print_progressively(char* string) {
    while(*string != '\0') {
        printf("%c", *string);
        fflush(stdout);
        string++;
        usleep(PRINT_DELAY_MS * (*string == '\n' ? 10000 : 1000));
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
        while(*script != JUMP_CHARACTER) {
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
    *script_ptr = script ;
}
