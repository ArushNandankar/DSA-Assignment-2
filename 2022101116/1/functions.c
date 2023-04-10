#include "functions.h"

stack createStack()
{
    stack S = malloc(sizeof(struct stack_struct));
    S->top_index = -1;
    S->arr_size = 10000;
    return S;
}

int isEmpty(stack S)
{
    if (S->top_index == -1)
        return 1;

    return 0;
}

int isFull(stack S)
{
    if (S->top_index == 10000 - 1)
        return 1;

    return 0;
}

void push(stack S, char e)
{
    if (!isFull(S))
    {
        S->top_index++;
        S->arr[S->top_index] = e;
    }
}

char pop(stack S)
{
    if (isEmpty(S))
    return '\0';
    
    
    S->top_index--;
    return S->arr[S->top_index + 1];
}

char peek(const stack S)
{
    return S->arr[S->top_index];
}

int isAleftBracket (char c)
{
    if (c == 40 || c == 91 || c == 123)
    return 1;

    else 
    return 0;
}

int isArightBracket (char c)
{
    if (c == 41 || c == 93 || c == 125)
    return 1;

    else
    return 0;
}

int isMatching (char c, char d)
{
    if ((c == 40 && d == 41) || (c == 91 && d == 93) || (c == 123 && d == 125))
    return 1;

    return 0;
}
