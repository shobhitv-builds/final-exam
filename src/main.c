#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"
#include "binary_tree.h"
#include "utils.h"
#include "trie.h"


int main(const int argc, const char* argv[]){
    char** encodings = NULL;

    char* prompt = malloc(sizeof(char) * 10);
    while(1){
        printf("\n$ ");
        scanf("%s", prompt);

        if(strcmp(prompt, "import") == 0){
            char* fileName = malloc(sizeof(char) * 100);
            scanf("%s", fileName);
            destroyEncodings(encodings);
            encodings = generateEncodingFromFile(fileName);
            free(fileName);
        }

        else if(strcmp(prompt, "encode") == 0){
            if(encodings == NULL){
                printf("Error: No encodings imported\n");
                continue;
            }
            char* fileName = malloc(sizeof(char) * 100);
            scanf("%s", fileName);
            printEncodedFile(fileName, encodings);
            free(fileName);
        }
        
        else if(strcmp(prompt, "decode") == 0){
            if(encodings == NULL){
                printf("Error: No encodings imported\n");
                continue;
            }
            Trie* decodeTrie = generateDecodeTrie(encodings);
            char* fileName = malloc(sizeof(char) * 100);
            scanf("%s", fileName);
            printDecodedFile(fileName, decodeTrie);
            free(fileName);
            destroyTrie(decodeTrie);
        }
        
        else if(strcmp(prompt, "dump") == 0){
            if(encodings == NULL){
                printf("Error: No encodings imported\n");
                continue;
            }
            for(int i = 32; i < 127; i++){
                printf("%c; %s\n", i, encodings[i]);
            }
        }
        else if(strcmp(prompt, "quit") == 0){
            break;
        }
    }

    destroyEncodings(encodings);
    free(prompt);
    return 0;
}