#include "priority_queue.h"
#include "binary_tree.h"
#include "utils.h"

Heap* newHeap(int size, TreeNode** nodes){
    Heap* heap = malloc(sizeof(Heap));
    heap->heapSize = size;
    heap->data = nodes;
    heap->capacity = ALPHABET_SIZE;

    buildMinHeap(heap);

    return heap;
}

void destroyHeap(Heap* heap){
    for(int i = 0; i < heap->heapSize; i++){
        destroyTree(heap->data[i]);
    }
    free(heap);
}

void heapify(Heap* heap, int idx){
    if(idx >= heap->heapSize){
        printf("ERROR: Errant use of heapify\n");
        exit(1);
    }

    int leftIdx = leftChild(idx);
    int rightIdx = rightChild(idx);
    int smallestIdx = idx;

    int smallestKey = key(heap->data[idx]);

    // if left_child is smaller
    if(leftIdx < heap->heapSize && smallestKey > key(heap->data[leftIdx])){
        smallestIdx = leftIdx;
        smallestKey = key(heap->data[leftIdx]);
    } 

    // if right child is smaller
    if(rightIdx < heap->heapSize && smallestKey > key(heap->data[rightIdx])){
        smallestIdx = rightIdx;
        smallestKey = key(heap->data[rightIdx]);
    }

    if(smallestIdx != idx){
        // swap heap[smallestIdx] and heap[idx]
        swap(heap, idx, smallestIdx);

        // heapify on smallestIdx
        heapify(heap, smallestIdx);
    }
}

void buildMinHeap(Heap* heap){
    int lastIdx = heap->heapSize - 1;
    for(int idx = parent(lastIdx); idx >= 0; idx--){
        heapify(heap, idx);
    }
}

TreeNode* extractMin(Heap* heap){
    if(heap->heapSize == 0){
        printf("Error: Heap underflow");
        exit(1);
    }
    TreeNode* minNode = heap->data[0];
    swap(heap, 0, heap->heapSize - 1);
    heap->data[heap->heapSize - 1] = NULL;
    heap->heapSize -= 1;
    if(heap->heapSize > 0) heapify(heap, 0);

    return minNode;
}

void insert(Heap* heap, TreeNode* node){
    if(heap->heapSize >= heap->capacity){
        printf("Error: Heap overflow");
        exit(1);
    }
    heap->heapSize += 1;
    int idx = heap->heapSize - 1;
    heap->data[idx] = node;

    int parentIdx = parent(idx);
    while(idx > 0 && key(heap->data[parentIdx]) > key(heap->data[idx])){
        swap(heap, idx, parentIdx);
        idx = parentIdx;
        parentIdx = parent(parentIdx);
    }
}

TreeNode* getPrefixTree(Heap* heap){
    if(heap->heapSize < 1){
        printf("Error: Heap empty\n");
        exit(1);
    }
    while(heap->heapSize > 1){
        TreeNode* node1 = extractMin(heap);
        TreeNode* node2 = extractMin(heap);
        TreeNode* newNode = mergeTreeNodes(node1, node2);
        insert(heap, newNode);
    }
    TreeNode* root = extractMin(heap);
    return root;
}

void swap(Heap* heap, int idx1, int idx2){
    TreeNode* tempPtr = heap->data[idx1];
    heap->data[idx1] = heap->data[idx2];
    heap->data[idx2] = tempPtr;
}