#ifndef PQUEUE_INC
#define PQUEUE_INC

#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

typedef struct _heap{
    int heapSize;
    int capacity;
    TreeNode** data;
} Heap;

Heap* newHeap(int size, TreeNode** nodes);
void destroyHeap(Heap* heap);

void heapify(Heap* heap, int idx);
void buildMinHeap(Heap* heap);
TreeNode* extractMin(Heap* heap);
void insert(Heap* heap, TreeNode* node);
void swap(Heap* heap, int idx1, int idx2);

TreeNode* getPrefixTree(Heap* heap);


#define leftChild(idx) ((idx << 1) + 1)
#define rightChild(idx) ((idx << 1) + 2)
#define parent(idx) ((idx - 1) >> 1)

#endif