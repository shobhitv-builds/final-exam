#include "binary_tree.h"
#include "utils.h"

TreeNode* newTreeNode(char letter, int frequency){
    TreeNode* node = malloc(sizeof(TreeNode));
    node->letterAscii = (int) letter;
    node->frequency = frequency;
    node->leftSubtree = NULL;
    node->rightSubtree = NULL;

    return node;
}

TreeNode* mergeTreeNodes(TreeNode* node_0, TreeNode* node_1){
    TreeNode *leftChild, *rightChild;

    if(node_0->frequency > node_1->frequency){
        leftChild = node_1;
        rightChild = node_0;
    }
    else{
        leftChild = node_0;
        rightChild = node_1;
    }

    TreeNode* node = malloc(sizeof(TreeNode));
    node->letterAscii = -1; // indicates that this node holds multiple letters
    node->leftSubtree = leftChild;
    node->rightSubtree = rightChild;
    node->frequency = leftChild->frequency + rightChild->frequency;

    return node;
}

TreeNode** populateData(const char* fileName, int* numChars){
    int* letterCounts = getLetterFrequencies(fileName);

    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(letterCounts[i] > 0) (*numChars)++;
    }

    TreeNode** arr = malloc((*numChars) * sizeof(TreeNode*));
    int idx = 0;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(letterCounts[i] <= 0) continue;
        arr[idx++] = newTreeNode((char) i, letterCounts[i]);
    }

    return arr;
}

void destroyTreeNode(TreeNode* node){
    if(node == NULL) return;
    destroyTreeNode(node->leftSubtree);
    destroyTreeNode(node->rightSubtree);
    free(node);
}

void printTree(TreeNode* root){
    if(root == NULL) return;

    printTree(root->leftSubtree);
    printTree(root->rightSubtree);

    if(root->letterAscii >= 0){
        printf("%c has frequency %d\n", root->letterAscii, root->frequency);
    }
    else{
        printf("Parent node, cumulative frequency %d\n", root->frequency);
    }
}