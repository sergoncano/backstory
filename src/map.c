#include <string.h>
#include <stdio.h>


int map_get_index(char key[], int size, char keys[][100])
{
    for (int i = 0; i < size; i++) {
        if (strcmp(keys[i], key) == 0) {
            return i;
        }
    }
    return -1;
}

void map_insert(char key[], int value, char keys[][100], int values[], int *size)
{
    int index = map_get_index(key, *size, keys);
    if (index == -1) {
        strcpy(keys[*size], key);
        values[*size] = value;
       (*size)++;
    }
    else { 
        values[index] = value;
    }
}

int map_get(char key[], char keys[][100], int values[], int size)
{
    int index = map_get_index(key, size, keys);
    if (index == -1) {
        return -1;
    }
    else {
        return values[index];
    }
}

void print_map(char keys[][100], int values[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", keys[i], values[i]);
    }
}
