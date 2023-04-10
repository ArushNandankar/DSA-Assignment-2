#include <stdio.h>
#include <stdlib.h>

typedef struct que_node *node_ptr;
typedef struct circular_deque *Queue;

struct que_node
{
    int key;
    node_ptr next;
};

struct circular_deque
{
    node_ptr front;
    node_ptr rear;
    int size;
};

node_ptr createNode(int key);
Queue createQueue();
int isEmpty(Queue Q);

void Push(Queue head, int val);   // done
int Pop(Queue head);              // done
void Inject(Queue head, int val); // done
int popRear(Queue head);          // done
void Print(Queue head);           // done
void PrintReverse(Queue head);    // done
int findElem(Queue head, int pos);
void removeKElems(Queue head, int k);

void PrintReverse_Recursive(Queue head, node_ptr ptr);