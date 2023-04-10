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
void BeautifulTraversalRecursive(Tree T, int DirectionFlag, int lvl);
void BeautifulTraversal(Tree T);

int GetHeight(Tree T);
int Max(int a, int b);
