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
int isAleftBracket (char c);
int isArightBracket (char c);
int isMatching (char c, char d);


int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        stack S = createStack();
        stack Q = createStack();
        char phrase[10000];
        scanf("%s", phrase);
        int j = 0;
        int isBalanced = 0;
        int isPalindromic = 1;
        while (phrase[j] != '\0')
        {
            push(S, phrase[j]);
            j++;
        }
        
        for (int k = 0; k < j; k++)
        {   
            int p = pop(S);
            if (p != phrase[k])
            {
                isPalindromic = 0;
                break;
            }
        }
        
        int count = 0;
        for (int k = 0; k < j; k++)
        {
            if(isAleftBracket(phrase[k]))
            count++;
        }
        
        if (count != 0)
        {
            isBalanced = 1;
            for (int k = 0; k < j; k++)
        {
            if (isAleftBracket(phrase[k]))
            push(Q, phrase[k]);

            else if (isArightBracket(phrase[k]))
            {
                if(isEmpty(Q))
                {
                    isBalanced = 0;
                    break;
                }

                char popped = pop(Q);

                if (!isMatching(popped, phrase[k]))
                {
                    isBalanced = 0;
                    break;
                }

            }
        }
        }
        
        if (!isEmpty(Q))
        {
            isBalanced = 0;
        }

        if (isBalanced && isPalindromic)
        printf("Balanced and Palindromic\n");

        else if (isBalanced)
        printf("Balanced\n");

        else if (isPalindromic)
        printf("Palindromic\n");

        else
        printf("-1\n"); 
    }
}

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
    if (c == 40 || c == 91 || c== 123)
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
