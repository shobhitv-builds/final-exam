#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

const char* fileName = "../res/sample_text.txt";

int main(const int argc, const char* argv[]){
    int* letterCounts = getLetterFrequencies(fileName);
    for(int i = 0; i < ALPHABET_SIZE; i++){
        printf("%d : %c has count %d\n", i, i, letterCounts[i]);
    }
    free(letterCounts);
    return 0;
}