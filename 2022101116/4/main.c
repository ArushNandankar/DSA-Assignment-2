#include "functions.h"

int main()
{
    int n;
    scanf("%d", &n);

    Tree T = NULL;

    for (int i = 0; i < n; i++)
    {
        long long int elem; 
        scanf("%lld", &elem);
        T = Insert(T, elem);
    }
    long long int carrySum = 0;
    long long int totalSum = 0;
    superInorder(T, &carrySum);
    LvlOrderTraversal(T, &totalSum);
    printf("\n");
    printf("%lld\n", totalSum);
}
