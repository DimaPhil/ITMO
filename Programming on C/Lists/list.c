#include "list.h"
 
int addToBegin(Node **begin, int newData)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {        
        return 0;
    }
    newNode->data = newData;
    newNode->next = *begin;
    *begin = newNode;
    return 1;
}
 
void deleteFromBegin(Node **begin, int *oldData)
{
    if (*begin != NULL)
    {
        Node *oldElement = *begin;
        if (oldData != NULL)
            *oldData = (*begin)->data;
        *begin = (*begin)->next;
        free(oldElement);
    }
}
 
void deleteFromEnd(Node **begin, int *oldData)
{
    if (*begin != NULL)
    {
        Node *lastElement = NULL;
        Node *nowBegin = *begin;
        while (nowBegin->next != NULL)
        {
            lastElement = nowBegin;
            nowBegin = nowBegin->next;    
        }
        if (oldData != NULL)
            *oldData = nowBegin->data;
 
        if (lastElement != NULL)
        {
            lastElement->next = NULL;
        }
        else
        {
            *begin = NULL;
        }
        free(nowBegin);
    }
}
 
int addToEnd(Node **begin, int newData)
{
   Node *newElement = malloc(sizeof(Node));
   if (newElement == NULL)
       return 0;
   newElement->next = NULL;
   newElement->data = newData;
 
   if (*begin == NULL)
   {
       *begin = newElement;
   }
   else
   {
       Node *nowBegin = *begin;
       while (nowBegin->next != NULL)
           nowBegin = nowBegin->next;
       nowBegin->next = newElement;
   }
   return 1;
}

void deleteByIndex(Node **begin, int k, int *oldData)
{
    if (*begin == NULL)
        return;
    Node *lastElement = NULL;
    Node *nowBegin = *begin;
    Node *nextElement = nowBegin->next;
    int i;
    for (i = 0; i < k; i++)
    {
        lastElement = nowBegin;
        if (nowBegin != NULL)
            nowBegin = nowBegin->next;
        if (nextElement != NULL)
            nextElement = nextElement->next;
    }
    if (nowBegin == NULL)
        return;
    if (oldData != NULL)
        *oldData = nowBegin->data;

    if (lastElement == NULL)
    {
        *begin = (*begin)->next;
    }
    else
    {
        lastElement->next = nextElement;
    }
    free(nowBegin);
}
 
void printList(Node *begin)
{
    /*if (begin == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d->", begin->data);
    printList(begin->next);*/
    printf("List: ");
    if (begin == NULL)
    {
        printf("Empty list\n");
        return;
    }
    while (begin != NULL)
    {
        printf("%d->", begin->data);
        begin = begin->next;  
    }
    printf("NULL\n");
}

void freeList(Node *begin)
{
}