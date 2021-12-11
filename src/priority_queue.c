#include "priority_queue.h"

HeapNode* newHeapNode(){
    HeapNode* node = malloc(sizeof(HeapNode));
    node->key = 0;
    node->letter = 0;
    node->isCoarseNode = False;
    node->leftSubtree = NULL;
    node->rightSubtree = NULL;

    return node;
}