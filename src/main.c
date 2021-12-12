#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"
#include "binary_tree.h"
#include "utils.h"
#include "trie.h"

TreeNode* importFile(const char* fileName){
    TreeNode** data = populateData(fileName);
    Heap* heap = newHeap(ALPHABET_SIZE, data);
    TreeNode* tree = getPrefixTree(heap);
    destroyHeap(heap);
    free(data);
    return tree;
}

char** generateEncoding(TreeNode* prefixTree){
    char** encodings = malloc(ALPHABET_SIZE * sizeof(char*));
    for(int i = 0; i < ALPHABET_SIZE; i++){
        encodings[i] = NULL;
    }
    char* buffer = malloc(ALPHABET_SIZE * sizeof(char));
    getEncoding(prefixTree, buffer, 0, encodings);
    free(buffer);

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
    while( (c = fgetc(inFile)) != EOF ){
        printf("%s", encodings[(int)c]);
    }
    fclose(inFile);
}

Trie* generateDecodeTrie(char** encodings){
    Trie* trie = newTrieNode();
    for(int i = 0; i < ALPHABET_SIZE; i++){
        int letterAscii = i;
        char* encoding = encodings[i];
        insertTrie(trie, encoding, letterAscii);
    }

    return trie;
}

void printDecodedFile(const char* encodedFile, Trie* decodeTrie){
    FILE* inFile = fopen(encodedFile, "r");
    Trie* curNode = decodeTrie;

    char c;
    while( (c = fgetc(inFile)) != EOF){
        int nextIdx = c - '0';
        if(nextIdx < 0 || nextIdx > 1){
            printf("Error: Decoded file is not binary.\n");
            exit(1);
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

int main(const int argc, const char* argv[]){
    char** encodings = NULL;

    char* prompt = malloc(sizeof(char) * 10);
    while(1){
        printf("\n$ ");
        scanf("%s", prompt);

        if(strcmp(prompt, "import") == 0){
            char* fileName = malloc(sizeof(char) * 100);
            scanf("%s", fileName);
            TreeNode* prefixTree = importFile(fileName);
            free(fileName);
            
            destroyEncodings(encodings);

            encodings = generateEncoding(prefixTree);
            destroyTree(prefixTree);
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