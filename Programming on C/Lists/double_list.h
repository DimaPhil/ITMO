#include <stdio.h>
#include <stdlib.h>
 
typedef struct tagNode Node;
typedef struct tagNode {
    int data;
    struct Node *next, *prev;
};
 
int addToBegin(Node **begin, int newData);
void deleteFromBegin(Node **begin, int *oldData);
int addToEnd(Node **begin, int newData);
void deleteFromEnd(Node **begin, int *oldData);
void printList(Node *begin);
void printListFromEnd(Node *begin);
void freeList(Node *begin);
void deleteByIndex(Node **begin, int k, int *oldData);