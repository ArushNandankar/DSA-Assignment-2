#include "functions.h"

node_ptr createNode(int key)
{
    node_ptr Q = malloc(sizeof(struct que_node));
    Q->key = key;
    Q->next = NULL;
    return Q;
}

Queue createQueue()
{
    Queue Q = malloc(sizeof(struct circular_deque));
    Q->front = NULL;
    Q->rear = NULL;
    Q->size = 0;
    return Q;
}

int isEmpty(Queue Q)
{
    if (Q->size == 0)
        return 1;

    return 0;
}

void Push(Queue head, int val)
{
    node_ptr ptr = createNode(val);

    if (isEmpty(head))
    {
        head->front = ptr;
        head->rear = ptr;
        ptr->next = ptr;
    }

    else
    {
        node_ptr temp = head->rear->next;
        head->rear->next = ptr;
        head->rear = ptr;
        ptr->next = temp;
    }

    head->size++;
}

int Pop(Queue head)
{
    if (isEmpty(head))
        return -1;

    else if (head->front == head->rear)
    {
        int k = head->front->key;
        node_ptr Ptr = head->front;
        head->front = NULL;
        head->rear = NULL;
        free(Ptr);
        head->size--;
        return k;
    }

    else
    {
        int k = head->front->key;
        node_ptr Ptr = head->front;
        head->front = head->front->next;
        head->rear->next = head->front;
        free(Ptr);
        head->size--;
        return k;
    }
}

void Inject(Queue head, int val)
{
    node_ptr ptr = createNode(val);

    if (isEmpty(head))
    {
        head->front = ptr;
        head->rear = ptr;
        ptr->next = ptr;
    }

    else
    {
        ptr->next = head->front;
        head->front = ptr;
        head->rear->next = ptr;
    }

    head->size++;
}

int popRear(Queue head)
{
    if (isEmpty(head))
        return -1;

    else if (head->front == head->rear)
    {
        int k = head->front->key;
        node_ptr Ptr = head->front;
        head->front = NULL;
        head->rear = NULL;
        free(Ptr);
        head->size--;
        return k;
    }

    else
    {
        int k = head->rear->key;
        node_ptr Ptr = head->front;
        while (Ptr->next != head->rear)
            Ptr = Ptr->next;

        head->rear = Ptr;
        free(Ptr->next);
        Ptr->next = head->front;
        head->size--;
        return k;
    }
}

void Print(Queue head)
{
    if (isEmpty(head))
    {
        printf("-1\n");
        return;
    }

    node_ptr temp = head->front;
    printf("%d ", temp->key);
    temp = temp->next;
    while (temp != head->front)
    {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

void PrintReverse(Queue head)
{
    if (isEmpty(head))
    {
        printf("-1\n");
        return;
    }

    node_ptr ptr = head->front;
    PrintReverse_Recursive(head, ptr->next);
    printf("%d ", ptr->key);
    printf("\n");
}

int findElem(Queue head, int pos)
{
    if (pos > head->size)
        return -1;

    node_ptr Ptr = head->front;

    for (int i = 0; i < pos - 1; i++)
    {
        Ptr = Ptr->next;
    }

    return Ptr->key;
}

void removeKElems(Queue head, int k)
{
    if (k >= head->size)
    {
        while (!isEmpty(head))
            Pop(head);
    }

    else
    {
        for (int i = 0; i < k; i++)
            Pop(head);
    }
}

void PrintReverse_Recursive(Queue head, node_ptr ptr)
{
    if (ptr == head->front)
        return;

    PrintReverse_Recursive(head, ptr->next);
    printf("%d ", ptr->key);
}