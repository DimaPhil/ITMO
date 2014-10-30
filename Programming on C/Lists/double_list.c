#include "double_list.h"
 
int addToBegin(Node **begin, int newData)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {        
        return 0;
    }
    newNode->next = *begin;
    newNode->prev = NULL;
    newNode->data = newData;
    *begin = newNode;
    Node *nextElement = (*begin)->next;
    if (nextElement != NULL)
        nextElement->prev = *begin;
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
        if (*begin != NULL)
            (*begin)->prev = NULL; 
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
   newElement->prev = NULL;
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
       newElement->prev = nowBegin;
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
        if (*begin != NULL)
            (*begin)->prev = NULL;
    }
    else
    {
        lastElement->next = nextElement;
        if (nextElement != NULL)
            nextElement->prev = lastElement;
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

void printListFromEnd(Node *begin)
{
    printf("Reversed list: ");
    if (begin == NULL)
    {
        printf("Empty list\n");
        return;
    }
    while (begin->next != NULL)
        begin = begin->next;

    while (begin != NULL)
    {
        printf("%d->", begin->data);
        begin = begin->prev;  
    }
    printf("NULL\n");
}
 
void freeList(Node *begin)
{
}