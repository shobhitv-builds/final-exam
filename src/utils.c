#include "utils.h"

int* getLetterFrequencies(const char* fileName){
    FILE* file = fopen(fileName, "r");
    if(file == NULL){
        printf("Error opening file %s\n", fileName);
        exit(1);
    }

    int* frequencies = malloc(ALPHABET_SIZE * sizeof(int));
    for(int i = 0; i < ALPHABET_SIZE; i++) frequencies[i] = 0;
    
    char c;
    while( (c = fgetc(file)) != EOF){
        frequencies[(int)c]++;
    }
    fclose(file);
    return frequencies;
}

char** generateEncodingFromFile(const char* fileName){
    TreeNode** data = populateData(fileName);
    Heap* heap = newHeap(ALPHABET_SIZE, data);
    TreeNode* prefixTree = getPrefixTree(heap);

    char** encodings = malloc(ALPHABET_SIZE * sizeof(char*));
    for(int i = 0; i < ALPHABET_SIZE; i++){
        encodings[i] = NULL;
    }
    char* buffer = malloc(ALPHABET_SIZE * sizeof(char));
    getEncoding(prefixTree, buffer, 0, encodings);
    free(buffer);

    destroyHeap(heap);
    destroyTree(prefixTree);
    free(data);
    return encodings;
}