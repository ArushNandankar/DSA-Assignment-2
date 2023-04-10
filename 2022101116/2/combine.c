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

int main()
{
    int T;
    scanf("%d", &T);

    Queue head = createQueue();

    for (int i = 0; i < T; i++)
    {
        char Operation[6];
        scanf("%s", Operation);

        int scase = Operation[4] - '0';

        switch (scase)
        {
        case 1:
        {
            int n;
            scanf("%d", &n);
            Push(head, n);
            break;
        }

        case 2:
        {
            int k = Pop(head);
            printf("%d\n", k);
            break;
        }

        case 3:
        {
            int n;
            scanf("%d", &n);
            Inject(head, n);
            break;
        }

        case 4:
        {
            int k = popRear(head);
            printf("%d\n", k);
            break;
        }

        case 5:
        {
            Print(head);
            break;
        }

        case 6:
        {
            PrintReverse(head);
            break;
        }

        case 7:
        {
            int n;
            scanf("%d", &n);
            int k = findElem(head, n);
            printf("%d\n", k);
            break;
        }

        case 8:
        {
            int n;
            scanf("%d", &n);
            removeKElems(head, n);
            break;
        }

        default:
            break;
        }
    }
}

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
        node_ptr temp = head->front;

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