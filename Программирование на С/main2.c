#include "double_list.h"
 
void main(void)
{
    Node *begin = NULL;
   
    int flag = 1;
    while (flag) {
        printList(begin);
        printListFromEnd(begin);
        printf("Enter type of operation:\n");
        int type;
        scanf("%i", &type);
        int x, k, tmp;
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
                    printf("Not enough memory\n");
                break;
            case 2:
                scanf("%i", &x);
                if (!addToEnd(&begin, x))
                    printf("Not enough memory\n");
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
            case 6:
                scanf("%i%i", &k, &x);
                tmp = addByIndex(&begin, k, x);
                if (tmp == 0)
                    printf("Not enough memory\n");
                if (tmp == 2)
                    printf("lalala\n");         
                break;
            case 7:
                deleteFromEnd(&begin, y);
                addToBegin(&begin, *y);
                break;
            case 8:
                deleteFromBegin(&begin, y);
                addToEnd(&begin, *y);
                break;
            default:
                break;
        }
    }
}
