#pragma once

typedef struct node{
    double value;
    int index;
} node;

typedef struct priorityList{
    node *A;
    int *positions;
    int size;
    int numNodes;
} priorityList;

priorityList *createPriorityList(int size);

void swapNodes(priorityList *list, int i, int j);

void heapifyUp(priorityList *list, int i);

void insertNode(priorityList *list, double value, int index);

void remakeHeap(priorityList *list, int i);

void removeNode(priorityList *list, int index);

void printList(priorityList *list);

void freeList(priorityList *list);

void buildHeap(priorityList *list);