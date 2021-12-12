#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "binary_tree.h"
#include "utils.h"

const char* defaultFile = "../res/sample_text.txt";

TreeNode* importFile(const char* fileName){
    int numChars = 0;
    TreeNode** data = populateData(fileName, &numChars);
    Heap* heap = newHeap(numChars, data);
    TreeNode* tree = getPrefixTree(heap);
    destroyHeap(heap);
    return tree;
}

int main(const int argc, const char* argv[]){
    TreeNode* prefixTree = importFile(defaultFile);
    printTree(prefixTree);
    destroyTree(prefixTree);

    return 0;
}