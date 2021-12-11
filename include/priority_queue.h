#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

typedef struct _node {
    int             key;
    char            letter;
    bool            isCoarseNode;
    struct _node*   leftSubtree;
    struct _node*   rightSubtree;
} HeapNode;

HeapNode* newHeapNode();
void destroyNode(HeapNode* node);

typedef struct _heap{
    int heapSize;
    HeapNode* heap;
} Heap;

Heap* newHeap(int capacity, HeapNode* heap);
void destroyHeap(Heap* heap);

void heapify(Heap* heap, int idx);
void buildMinHeap(Heap* heap);
HeapNode* extractMin(Heap* heap);
void insert(Heap* heap, HeapNode* node);