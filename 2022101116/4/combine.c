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

int main()
{
    int n;
    scanf("%d", &n);

    Tree T = NULL;

    for (int i = 0; i < n; i++)
    {
        long long int elem; 
        scanf("%lld", &elem);
        T = Insert(T, elem);
    }
    long long int carrySum = 0;
    long long int totalSum = 0;
    superInorder(T, &carrySum);
    LvlOrderTraversal(T, &totalSum);
    printf("\n");
    printf("%lld\n", totalSum);
}

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
