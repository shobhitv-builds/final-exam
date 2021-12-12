#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "binary_tree.h"
#include "utils.h"
#include "trie.h"

const char* defaultFile = "../res/sample_text.txt";
const char* encodedFile = "../res/sample_text_encoded.txt";

TreeNode* importFile(const char* fileName){
    TreeNode** data = populateData(fileName);
    Heap* heap = newHeap(ALPHABET_SIZE, data);
    TreeNode* tree = getPrefixTree(heap);
    destroyHeap(heap);
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
    FILE* inFile = fopen(defaultFile, "r");
    FILE* outFile = fopen(encodedFile, "w+");
    if(inFile == NULL || outFile == NULL){
        printf("Error opening files");
        exit(1);
    }
    char c;
    while( (c = fgetc(inFile)) != EOF ){
        fprintf(outFile, "%s", encodings[(int)c]);
    }
    fclose(inFile);
}

void generateDecodeTree(char** encodings){
    Trie* trie = newTrieNode();
    for(int i = 0; i < ALPHABET_SIZE; i++){
        int letterAscii = i;
        char* encoding = encodings[i];
        insertTrie(trie, encoding, letterAscii);
    }
}

int main(const int argc, const char* argv[]){
    TreeNode* prefixTree = importFile(defaultFile);
    // printTree(prefixTree);

    char** encodings = generateEncoding(prefixTree);
    // printEncodings(encodings);

    printEncodedFile(defaultFile, encodings);

    generateDecodeTree(encodings);

    for(int i = 0; i < ALPHABET_SIZE; i++) free(encodings[i]);
    destroyTree(prefixTree);
    return 0;
}