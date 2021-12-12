#ifndef UTILS_INC

#define UTILS_INC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"
#include "binary_tree.h"
#include "trie.h"

#define ALPHABET_SIZE 128

int* getLetterFrequencies(const char* fileName);
char** generateEncodingFromFile(const char* fileName);
void printEncodings(char** encodings);
void printEncodedFile(const char* fileName, char** encodings);
void printDecodedFile(const char* encodedFile, Trie* decodeTrie);
void destroyEncodings(char** encodings);

#endif