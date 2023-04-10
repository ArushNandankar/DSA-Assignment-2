#include "functions.h"

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        Tree T = NULL;
        
        int N;
        scanf("%d", &N);

        for (int j = 0; j < N; j++)
        {
            int elem;
            scanf("%d", &elem);
            T = Insert(T, elem);
        }

        BeautifulTraversal(T);
        printf("\n");       
    }
    
}