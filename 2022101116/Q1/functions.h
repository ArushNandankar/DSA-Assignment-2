#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>

struct stack_struct
{
    char arr[10000];
    int top_index;
    int arr_size;
};

typedef struct stack_struct *stack;

stack createStack();
int isEmpty(stack S);
int isFull(stack S);
void push(stack S, char e);
char pop(stack S);
char peek(const stack S);
int isAleftBracket(char c);
int isArightBracket(char c);
int isMatching(char c, char d);

#endif