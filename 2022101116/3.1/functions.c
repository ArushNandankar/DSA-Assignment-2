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
    {
        T = CreateNode(val);
        return T;
    }

    else
    {
        queue Q = initQueue();
        Enque(Q, T);

        while(!isEmpty(Q))
        {
            PtrToNode Temp = Q->arr[Q->q_front];
            Deque(Q);

            if(Temp->Left != NULL)
                Enque(Q, Temp->Left);

            else
            {
                Temp->Left = CreateNode(val);
                return T;
            }

             if(Temp->Right != NULL)
                Enque(Q, Temp->Right);

            else
            {
                Temp->Right = CreateNode(val);
                return T;
            }
        }
        return NULL;
    }
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

void Enque (queue Q, PtrToNode p)
{
    if(!isFull(Q))
    {
        Q->q_size++;
        Q->arr[Q->q_rear] = p;
        Q->q_rear = (Q->q_rear+1) % MAX_ELEMENTS;
    }
}

PtrToNode Deque (queue Q) 
{
    if(!isEmpty(Q))
    {
        Q->q_size--;
        PtrToNode k = Q->arr[Q->q_front];
        Q->q_front = (Q->q_front + 1) % MAX_ELEMENTS;
        return k;
    }

    else
    return NULL;
}
int isEmpty (queue Q)
{
    if(Q->q_size == 0)
    return 1;

    return 0;
}

int isFull (queue Q)
{
    if(Q->q_size == MAX_ELEMENTS)
    return 1;

    return 0;
}

queue initQueue ()
{
    queue Q = malloc(sizeof(struct queue));
    Q->q_size = 0;
    Q->q_front = 0;
    Q->q_rear = 0;
    return Q;
}

void destroyQueue (queue Q)
{
    free(Q);
}
