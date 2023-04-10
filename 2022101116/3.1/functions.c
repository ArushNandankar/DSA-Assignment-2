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

int GetHeight(Tree T)
{
    if(T == NULL)
    return -1;

    else
    return Max(GetHeight(T->Left) + 1, GetHeight(T->Right) + 1);
}

void BeautifulTraversalRecursive(Tree T, int DirectionFlag, int lvl)
{
    if(T == NULL)
        return;

    if(lvl == 0)
        printf("%d ", T->key);
    
    else if(DirectionFlag == 1) {
        BeautifulTraversalRecursive(T->Right, DirectionFlag, lvl - 1);
        BeautifulTraversalRecursive(T->Left, DirectionFlag, lvl - 1);
    }

    else if(DirectionFlag == 0) {
        BeautifulTraversalRecursive(T->Left, DirectionFlag, lvl - 1);
        BeautifulTraversalRecursive(T->Right, DirectionFlag, lvl - 1);
    }  

}

void BeautifulTraversal(Tree T)
{
    int lvls = GetHeight(T) + 1;

    for (int i = 0; i < lvls; i++)
    {
        BeautifulTraversalRecursive(T, i%2, i);
    }
    
}

int Max(int a, int b)
{
    if(a > b)
    return a;

    else
    return b;
}