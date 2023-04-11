#include "functions.h"

PtrToNode CreateNode(int val)
{
    PtrToNode T = malloc(sizeof(struct TreeNode));
    T->key = val;
    T->Left = NULL;
    T->Right = NULL;
    return T;
}

PtrToNode Insert(Tree T, int val)
{
    if(T == NULL)
        T = CreateNode(val);
       
    else if (val < T->key)
        T->Left = Insert(T->Left, val);

    else if (val > T->key)
        T->Right = Insert(T->Right, val);

    return T;
}

void LevelOrderTraversal(Tree T)
{
    
}