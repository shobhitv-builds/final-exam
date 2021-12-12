#ifndef UTILS_INC

#define UTILS_INC

#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "binary_tree.h"

#define ALPHABET_SIZE 128

int* getLetterFrequencies(const char* fileName);
char** generateEncodingFromFile(const char* fileName);

#endif