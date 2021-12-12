#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "binary_tree.h"
#include "utils.h"

const char* fileName = "../res/sample_text.txt";

int main(const int argc, const char* argv[]){
    int numChars = 0;
    TreeNode** data = populateData(fileName, &numChars);
    printf("%d characters:\n", numChars);
    for(int i = 0; i < numChars; i++){
        printf("(%d) : %c has freq %d\n", i, data[i]->letterAscii, data[i]->frequency);
    }

    Heap* heap = newHeap(numChars, data);
    printf("Heap order:\n");
    for(int i = 0; i < numChars; i++){
        printf("(%d) : %c has freq %d\n", heap->data[i]->letterAscii, heap->data[i]->letterAscii, heap->data[i]->frequency);
    }
    return 0;
}