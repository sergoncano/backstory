#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "constants.h"
#include "script.h"

void print_progressively(char* string);
char **parse_script(char* script);

int main(int argc, char *argv[]) {
    char **parsed_script = parse_script(SCRIPT);
    int i = 0;
    while(*parsed_script[i] != '\0') {
        print_progressively(parsed_script[i]);
        i++;
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

char **parse_script(char* script) {
    char **parsed_script = malloc(sizeof(char*));
    int i = 0;
    char buf[4096];
    int j = 0;
    do {
        if(*script == '\b' || *script == '\0') {
            buf[j] = '\0';
            parsed_script = realloc(parsed_script, sizeof(parsed_script) + sizeof(char*));
            parsed_script[i] = strdup(buf);
            i++;
            j = 0;
        } else {
            buf[j] = *script;
            j++;
        }
        script++;
    } while(*script != '\0');
    parsed_script[i] = "\0";
    return parsed_script;
}
