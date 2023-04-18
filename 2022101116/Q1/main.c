#include "functions.h"

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
            if (isAleftBracket(phrase[k]))
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
                    if (isEmpty(Q))
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
