#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 256

typedef enum{
    False,
    True
} bool;

int* getLetterFrequencies(const char* fileName);