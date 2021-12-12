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

void printEncodings(char** encodings){
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(encodings[i] == NULL) continue;
        printf("%c encoded to %s\n", i, encodings[i]);
    }
}

void printEncodedFile(const char* fileName, char** encodings){
    FILE* inFile = fopen(fileName, "r");
    if(inFile == NULL){
        printf("Error opening files");
        exit(1);
    }
    char c;
    int bitcount = 0;
    while( (c = fgetc(inFile)) != EOF ){
        printf("%s", encodings[(int)c]);
        bitcount += strlen(encodings[(int)c]);
    }
    printf("\nNumber of bits: %d\n", bitcount);
    fclose(inFile);
}

void printDecodedFile(const char* encodedFile, Trie* decodeTrie){
    FILE* inFile = fopen(encodedFile, "r");
    Trie* curNode = decodeTrie;

    char c;
    while( (c = fgetc(inFile)) != EOF){
        int nextIdx = c - '0';
        if(nextIdx < 0 || nextIdx > 1){
            printf("Warning: Decoded file is not binary: %c\n", c);
            continue;
        }
        curNode = curNode->children[nextIdx];
        if(curNode == NULL){
            printf("Error: Encoding invalid.\n");
            exit(1);
        }
        if(curNode->isTerminal > 0){
            printf("%c", (char)curNode->letterAscii);
            curNode = decodeTrie;
        }
    }

    fclose(inFile);
}

void destroyEncodings(char** encodings){
    if(encodings != NULL){
        for(int i = 0; i < ALPHABET_SIZE; i++) free(encodings[i]);
        free(encodings);
    }
}