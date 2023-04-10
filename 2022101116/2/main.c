#include "functions.h"

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
            int n;
            scanf("%d", &n);
            Push(head, n);
            break;

        case 2:
            int k = Pop(head);
            printf("%d\n", k);
            break;
        
        case 3:
            int n;
            scanf("%d", &n);
            Inject(head, n);
            break;

        case 4:
            int k = popRear(head);
            printf("%d\n", k);
            break;

        case 5:
            Print(head);
            break;

        case 6:
            PrintReverse(head);
            break;

        case 7:
            int n;
            scanf("%d", &n);
            int k = findElem(head, n);
            break;

        case 8:
            int n;
            scanf("%d", &n);
            removeKElems(head, n);
            break;

        default:
            break;
        }
    }  

}