#include "constants.h"
#include <stdio.h>
#include <string.h>

int size = 0; // Current number of elements in the map
char keys[MAX_DIALOGUE_STEPS][100]; // Array to store the keys
int values[MAX_DIALOGUE_STEPS]; // Array to store the values

// Function to get the index of a key in the keys array
int map_get_index(char key[])
{
    for (int i = 0; i < size; i++) {
        if (strcmp(keys[i], key) == 0) {
            return i;
        }
    }
    return -1; // Key not found
}

// Function to insert a key-value pair into the map
void map_insert(char key[], int value)
{
    int index = map_get_index(key);
    if (index == -1) { // Key not found
        strcpy(keys[size], key);
        values[size] = value;
        size++;
    }
    else { // Key found
        values[index] = value;
    }
}

// Function to get the value of a key in the map
int map_get(char key[])
{
    int index = map_get_index(key);
    if (index == -1) { // Key not found
        return -1;
    }
    else { // Key found
        return values[index];
    }
}

// Function to print the map
void print_map()
{
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", keys[i], values[i]);
    }
}
