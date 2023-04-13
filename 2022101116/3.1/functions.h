#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode* PtrToNode;
typedef PtrToNode Tree;

#define MAX_ELEMENTS 1000

struct queue
{
    PtrToNode arr[MAX_ELEMENTS];
    int q_size;
    int q_rear;
    int q_front;
};

typedef struct queue *queue;

void Enque (queue Q, PtrToNode p);
PtrToNode Deque (queue Q);
int isEmpty (queue Q);
int isFull (queue Q);
queue initQueue ();
void destroyQueue (queue Q);


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
