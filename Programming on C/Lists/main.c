#include "list.h"
 
void main(void)
{
    Node *begin = NULL;
   
    int flag = 1;
    while (flag) {
        printList(begin);
        printf("Enter type of operation:\n");
        int type;
        scanf("%i", &type);
        int x;
        int *y = malloc(sizeof(int));
        switch (type)
        {
            case 0:
                flag = 0;
                freeList(begin);
                break;
            case 1:
                scanf("%i", &x);
                if (!addToBegin(&begin, x))
                    printf("Not enough memory");
                break;
            case 2:
                scanf("%i", &x);
                if (!addToEnd(&begin, x))
                    printf("Not enough memory");
                break;
            case 3:
                deleteFromBegin(&begin, y);
                printf("Deleted element: %i\n", *y);
                break;
            case 4:
                deleteFromEnd(&begin, y);
                printf("Deleted element: %i\n", *y);
                break;
            case 5:
                scanf("%i", &x);
                deleteByIndex(&begin, x, y);
                printf("Deleted element: %i\n", *y);
                break;
            default:
                break;
        }
    }
}
