#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;
typedef PtrToNode ElementType;
typedef struct QueNode *QnodePtr;
typedef struct QueStruct *Queue;

struct TreeNode
{
    long long int key;
    PtrToNode Left;
    PtrToNode Right;
    long long int greaterThan;
    long long int lessThan;
};

struct QueNode
{
    ElementType e;
    QnodePtr next;
};

struct QueStruct
{
    QnodePtr Front;
    QnodePtr Rear;
    long long int size;
};

PtrToNode CreateNode(long long int val, long long int greaterThan, long long int lessThan); 
void superInsert(Tree T, long long int* lvlOrder, int n, Queue Q);
void LvlOrderWithQueue(Tree T, long long int *totalSum); 
void superInorder(Tree T, long long int *carrySum); 
Queue initQueue(); 
QnodePtr makeQNode(ElementType e); 
QnodePtr Dequeue(Queue Q); 
void Enqueue(Queue Q, ElementType e); 

int canItgoUnderIt(PtrToNode ptr, long long int key);

int main()
{
    int n;
    scanf("%d", &n);
    
    long long int lvlOrder[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &lvlOrder[i]);
    }

    Tree T = CreateNode(lvlOrder[0], -1, 10000001);
    Queue Q = initQueue();
    Enqueue(Q, T);
 
    superInsert(T, lvlOrder, n, Q);

    long long int carrySum = 0;
    long long int totalSum = 0;
    superInorder(T, &carrySum);
    LvlOrderWithQueue(T, &totalSum);
    printf("\n");
    printf("%lld\n", totalSum);
}

PtrToNode CreateNode(long long int val, long long int greaterThan, long long int lessThan)
{
    PtrToNode T = malloc(sizeof(struct TreeNode));
    T->key = val;
    T->Left = NULL;
    T->Right = NULL;
    T->greaterThan = greaterThan;
    T->lessThan = lessThan;
    return T;
}

void superInsert(Tree T, long long int* lvlOrder, int n, Queue Q)
{
    int index = 1;
    while(index != n)
    {
        if(canItgoUnderIt(Q->Front->e, lvlOrder[index]) == -1) // node has died (cannot have children)
            Dequeue(Q);
        
        else if (canItgoUnderIt(Q->Front->e, lvlOrder[index]) == 1) // can go left
        {
            PtrToNode ptr = CreateNode(lvlOrder[index], Q->Front->e->greaterThan, Q->Front->e->key);
            Q->Front->e->Left = ptr;
            Enqueue(Q, ptr);
            index++;
        }
        
        else if (canItgoUnderIt(Q->Front->e, lvlOrder[index]) == 2) // can go right
        {
            PtrToNode ptr = CreateNode(lvlOrder[index], Q->Front->e->key, Q->Front->e->lessThan);
            Q->Front->e->Right = ptr;
            Enqueue(Q, ptr);
            index++;
            Dequeue(Q);
        }
    }
}

void superInorder(Tree T, long long int *carrySum)
{
    if (T == NULL)
        return;

    superInorder(T->Left, carrySum);
    T->key = T->key + *carrySum;
    *carrySum = T->key;
    superInorder(T->Right, carrySum);
}

void LvlOrderWithQueue(Tree T, long long int *totalSum)
{
    Queue Q = initQueue();
    QnodePtr ptr = makeQNode(T);

    while (ptr)
    {
        printf("%lld ", ptr->e->key);
        *totalSum += ptr->e->key;

        if (ptr->e->Left != NULL)
            Enqueue(Q, ptr->e->Left);

        if (ptr->e->Right != NULL)
            Enqueue(Q, ptr->e->Right);

        ptr = Dequeue(Q);
    }
}

Queue initQueue()
{
    Queue Q = malloc(sizeof(struct QueStruct));
    Q->Front = NULL;
    Q->Rear = NULL;
    Q->size = 0;
    return Q;
}

QnodePtr makeQNode(ElementType e)
{
    QnodePtr ptr = malloc(sizeof(struct QueNode));
    ptr->e = e;
    ptr->next = NULL;
    return ptr;
}

QnodePtr Dequeue(Queue Q)
{
    if (Q->size == 0)
        return NULL;

    else if (Q->size == 1)
    {
        QnodePtr ptr = Q->Front;
        Q->Front = NULL;
        Q->Rear = NULL;
        Q->size = 0;
        return ptr;       
    }

    else
    {
        QnodePtr ptr = Q->Front;
        Q->Front = Q->Front->next;
        Q->size--;
        return ptr;
    }
}

void Enqueue(Queue Q, ElementType e)
{
    QnodePtr ptr = makeQNode(e);

    if (Q->size == 0)
    {
        Q->Front = ptr;
        Q->Rear = ptr;
    }

    else
    {
        Q->Rear->next = ptr;
        Q->Rear = ptr;
    }

    Q->size++;
}

int canItgoUnderIt(PtrToNode ptr, long long int key)
{
    if(key > ptr->greaterThan && key < ptr->lessThan)
    {
        if(key < ptr->key && ptr->Left == NULL)  // goes left
            return 1;   

        else if(key > ptr->key && ptr->Right == NULL)
            return 2;

        else return -1;
    }

    else
        return -1;
}