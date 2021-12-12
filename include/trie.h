#include <stdlib.h>
#include <stdio.h>

typedef struct _trieNode{
    int isTerminal;
    int letterAscii;
    struct _trieNode** children;
} Trie;

Trie* newTrieNode();
void destroyTrie(Trie* node);
void insertTrie(Trie* trie, char* binaryString, int letterAscii);