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


int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);

        int inOrder[N];
        int preOrder[N];

        for (int j = 0; j < N; j++)
            scanf("%d", &inOrder[j]);

        for (int j = 0; j < N; j++)
            scanf("%d", &preOrder[j]);

        Tree T = constructTree(inOrder, preOrder, N);

        LvlOrderTraversal(T);
        printf("\n");
    }
}


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

Tree constructTree(int inOrder[], int preOrder[], int N)
{
    if(N == 0)
    return NULL;
    
    int k = preOrder[0];

    Tree T = CreateNode(k);

    int count1 = 0;

    for (int i = 0; i < N; i++)
    {
        if(inOrder[i] == k)
        break;

        else
        count1++;
    }

    int* leftIn = malloc(sizeof(int) * count1);
    int* leftPr = malloc(sizeof(int) * count1);

    for (int i = 0; i < count1; i++)
    {
        leftIn[i] = inOrder[i];
        leftPr[i] = preOrder[i+1];
    }
    
    int count2 = N - count1 - 1;

    int* rightIn = malloc(sizeof(int) * count2);
    int* rightPr = malloc(sizeof(int) * count2);

    for (int i = 0; i < count2; i++)
    {
        rightIn[i] = inOrder[count1 + 1 + i];
        rightPr[i] = preOrder[count1 + 1 + i];
    }
    
    T->Left = constructTree(leftIn, leftPr, count1);
    T->Right = constructTree(rightIn, rightPr, count2);

    free(leftIn);
    free(leftPr);
    free(rightIn);
    free(rightPr);

    return T;   
}

void LvlOrderTraversalRecursive(Tree T, int lvl)
{
    if(T == NULL)
        return;

    if(lvl == 0) 
    {
        printf("%d ", T->key);
        return;
    }
          
    LvlOrderTraversalRecursive(T->Left, lvl - 1);
    LvlOrderTraversalRecursive(T->Right, lvl - 1);
}

void LvlOrderTraversal(Tree T)
{
    int lvls = GetHeight(T) + 1;

    for (int i = 0; i < lvls; i++)
    {
        LvlOrderTraversalRecursive(T, i);
    }   
}

int GetHeight(Tree T)
{
    if(T == NULL)
    return -1;

    else
    return Max(GetHeight(T->Left) + 1, GetHeight(T->Right) + 1);
}

int Max(int a, int b)
{
    if(a > b)
    return a;

    else
    return b;
}
