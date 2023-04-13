#include "functions.h"


PtrToNode CreateNode(long long int val)
{
    PtrToNode T = malloc(sizeof(struct TreeNode));
    T->key = val;
    T->Left = NULL;
    T->Right = NULL;
    return T;
}

PtrToNode Insert(Tree T, long long int val)
{
    if(T == NULL)  
        T = CreateNode(val);

    else if (val < T->key)
        T->Left = Insert(T->Left, val);

    else
        T->Right = Insert(T->Right, val);

    return T;
}
int GetHeight(Tree T)
{
    if(T == NULL)
    return -1;

    else
    return Max(GetHeight(T->Left) + 1, GetHeight(T->Right) + 1);
}

long long int Max(long long int a, long long int b)
{
    if(a > b)
    return a;

    else
    return b;
}

void superInorder(Tree T, long long int *carrySum)
{
    if(T == NULL)
        return;
    
    superInorder(T->Left, carrySum);
    T->key = T->key + *carrySum;
    *carrySum = T->key;
    superInorder(T->Right, carrySum);
}

void LvlOrderTraversalRecursive(Tree T, int lvl, long long int *totalSum)
{
    if(T == NULL)
        return;

    if(lvl == 0) 
    {
        printf("%lld ", T->key);
        *totalSum += T->key;
        return;
    }
          
    LvlOrderTraversalRecursive(T->Left, lvl - 1, totalSum);
    LvlOrderTraversalRecursive(T->Right, lvl - 1, totalSum);
}

void LvlOrderTraversal(Tree T, long long int *totalSum)
{
    int lvls = GetHeight(T) + 1;

    for (int i = 0; i < lvls; i++)
    {
        LvlOrderTraversalRecursive(T, i, totalSum);
    }   
}
