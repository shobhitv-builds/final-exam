#ifndef BINARY_TREE_INC
#define BINARY_TREE_INC

#include <stdio.h>
#include <stdlib.h>

typedef struct _treeNode{
    int letterAscii;
    int frequency;
    struct _treeNode* leftSubtree;
    struct _treeNode* rightSubtree;
} TreeNode;

TreeNode* newTreeNode(char letter, int frequency);
TreeNode* mergeTreeNodes(TreeNode* node_0, TreeNode* node_1);
TreeNode** populateData(const char* fileName, int* numChars);
void destroyTreeNode(TreeNode* root);
void printTree(TreeNode* root);

#define key(node) node->frequency

#endif