#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"
#include "binary_tree.h"
#include "utils.h"
#include "trie.h"

char** importRoutine(){
    char* fileName = malloc(sizeof(char) * 100);
    scanf("%s", fileName);
    char** encodings = generateEncodingFromFile(fileName);
    free(fileName);
    return encodings;
}

void encodeRoutine(char** encodings){
    if(encodings == NULL){
        printf("Error: No encodings imported\n");
        return;
    }
    char* fileName = malloc(sizeof(char) * 100);
    scanf("%s", fileName);
    printEncodedFile(fileName, encodings);
    free(fileName);
}

void decodeRoutine(char** encodings){
    if(encodings == NULL){
        printf("Error: No encodings imported\n");
        return;
    }
    Trie* decodeTrie = generateDecodeTrie(encodings);
    char* fileName = malloc(sizeof(char) * 100);
    scanf("%s", fileName);
    printDecodedFile(fileName, decodeTrie);
    free(fileName);
    destroyTrie(decodeTrie);
}

void dumpRoutine(char** encodings){
    if(encodings == NULL){
        printf("Error: No encodings imported\n");
        return;
    }
    for(int i = 32; i < 127; i++){
        printf("%c; %s\n", i, encodings[i]);
    }
}

int main(const int argc, const char* argv[]){
    char** encodings = NULL;

    char* prompt = malloc(sizeof(char) * 10);
    while(1){
        printf("\n$ ");
        scanf("%s", prompt);

        if(strcmp(prompt, "import") == 0){
            destroyEncodings(encodings);
            encodings = importRoutine(encodings);
        }

        else if(strcmp(prompt, "encode") == 0){
            encodeRoutine(encodings);
        }
        
        else if(strcmp(prompt, "decode") == 0){
            decodeRoutine(encodings);
        }
        
        else if(strcmp(prompt, "dump") == 0){
            dumpRoutine(encodings);
        }
        else if(strcmp(prompt, "quit") == 0){
            break;
        }
    }

    destroyEncodings(encodings);
    free(prompt);
    return 0;
}