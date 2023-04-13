#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode* PtrToNode;
typedef PtrToNode Tree;

struct TreeNode
{
    long long int key;
    PtrToNode Left;
    PtrToNode Right;
};

PtrToNode CreateNode(long long int val); //correct definitely
PtrToNode Insert(Tree T, long long int val); //correct definitely

int GetHeight(Tree T); //correct definitely
long long int Max(long long int a, long long int b); //correct definitely
void LvlOrderTraversalRecursive(Tree T, int lvl, long long int *totalSum); //done
void LvlOrderTraversal(Tree T, long long int *totalSum); //done

void superInorder(Tree T, long long int *carrySum); //done
