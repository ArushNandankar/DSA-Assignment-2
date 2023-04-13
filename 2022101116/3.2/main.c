#include "functions.h"

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);

        int inOrder[N];
        int preOrder[N];

        for (int j = 0; j < N; j++)
            scanf("%d", &inOrder[j]);

        for (int j = 0; j < N; j++)
            scanf("%d", &preOrder[j]);

        Tree T = constructTree(inOrder, preOrder, N);

        LvlOrderTraversal(T);
        printf("\n");
    }
}
