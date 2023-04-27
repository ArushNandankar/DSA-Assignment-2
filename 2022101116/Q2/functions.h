#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

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

void Push(Queue head, int val);
int Pop(Queue head);
void Inject(Queue head, int val);
int popRear(Queue head);
void Print(Queue head);
void PrintReverse(Queue head);
int findElem(Queue head, int pos);
void removeKElems(Queue head, int k);

void PrintReverse_Recursive(Queue head, node_ptr ptr);

#endif