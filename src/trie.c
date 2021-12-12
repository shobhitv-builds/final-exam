#include "trie.h"
#include "utils.h"

Trie* newTrieNode(){
    Trie* node = (Trie*) malloc(sizeof(Trie));
    node->isTerminal = 0;
    node->letterAscii = -1;
    node->children = malloc(2 * sizeof(Trie*));
    node->children[0] = node->children[1] = NULL;
    return node;
}

void destroyTrie(Trie* node){
    if(node == NULL) return;
    destroyTrie(node->children[0]);
    destroyTrie(node->children[1]);
    free(node->children);
    free(node);
}

void insertTrie(Trie* trie, char* binaryString, int letter){
    int idx = 0;
    Trie* root = trie;
    while(binaryString[idx] != '\0'){
        int childIdx = binaryString[idx] - '0';
        if(root->children[childIdx] == NULL){
            root->children[childIdx] = newTrieNode();
        }
        root = root->children[childIdx];
        idx++;
    }
    root->isTerminal = 1;
    root->letterAscii = letter;
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