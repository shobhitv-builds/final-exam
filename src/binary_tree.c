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

TreeNode** populateData(const char* fileName){
    int* letterCounts = getLetterFrequencies(fileName);

    TreeNode** arr = malloc(ALPHABET_SIZE * sizeof(TreeNode*));
    for(int i = 0; i < ALPHABET_SIZE; i++){
        arr[i] = newTreeNode((char) i, letterCounts[i]);
    }

    return arr;
}

void destroyTree(TreeNode* node){
    if(node == NULL) return;
    destroyTree(node->leftSubtree);
    destroyTree(node->rightSubtree);
    free(node);
}

void getEncoding(TreeNode* root, char* buffer, int codeLen, char** encodings){
    if(root == NULL) return;

    buffer[codeLen++] = '0';
    getEncoding(root->leftSubtree, buffer, codeLen, encodings);
    codeLen--;

    if(root->letterAscii >= 0){ // Node represents a character
        encodings[root->letterAscii] = malloc(ALPHABET_SIZE * sizeof(char));
        int i;
        for(i = 0; i < codeLen; i++){
            encodings[root->letterAscii][i] = buffer[i];
        }
        encodings[root->letterAscii][i] = '\0';
    }

    buffer[codeLen++] = '1';
    getEncoding(root->rightSubtree, buffer, codeLen, encodings);
    codeLen--;
}

void printTree(TreeNode* root){
    if(root == NULL) return;

    printTree(root->leftSubtree);
    printTree(root->rightSubtree);

    if(root->letterAscii >= 0){
        printf("%c has frequency %d\n", root->letterAscii, root->frequency);
    }
}