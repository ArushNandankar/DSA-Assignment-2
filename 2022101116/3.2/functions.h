#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode* PtrToNode;
typedef PtrToNode Tree;

struct TreeNode
{
    int key;
    PtrToNode Left;
    PtrToNode Right;
};

PtrToNode CreateNode(int val);
PtrToNode Insert(Tree T, int val);

Tree constructTree(int inOrder[], int preOrder[], int N);

void LvlOrderTraversalRecursive(Tree T, int lvl);
void LvlOrderTraversal(Tree T);
int GetHeight(Tree T);
int Max(int a, int b);

