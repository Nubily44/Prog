#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "priorityList.h"

priorityList *createPriorityList(int size) {
    priorityList *list = (priorityList *)malloc(sizeof(priorityList));
    list->A = (node *)malloc(size * sizeof(node));
    list->positions = (int *)malloc(size * sizeof(int));
    list->size = size;
    list->numNodes = 0;
    return list;
}

void swapNodes(priorityList *list, int i, int j) {
    node aux = list->A[i];
    list->A[i] = list->A[j];
    list->A[j] = aux;
    list->positions[list->A[i].index] = i;
    list->positions[list->A[j].index] = j;
}

void heapifyUp(priorityList *list, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (list->A[i].value >= list->A[parent].value) break;
        swapNodes(list, i, parent);
        i = parent;
    }
}

void heapifyDown(priorityList *list, int i) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < list->numNodes && list->A[left].value < list->A[smallest].value) {
            smallest = left;
        }
        if (right < list->numNodes && list->A[right].value < list->A[smallest].value) {
            smallest = right;
        }
        if (smallest == i) break;

        swapNodes(list, i, smallest);
        i = smallest;
    }
}

void insertNode(priorityList *list, double value, int index) {
    if (list->numNodes == list->size) {
        printf("Lista cheia\n");
        return;
    }
    list->A[list->numNodes].value = value;
    list->A[list->numNodes].index = index;
    list->positions[index] = list->numNodes;
    heapifyUp(list, list->numNodes);
    list->numNodes++;
}

void removeNode(priorityList *list, int index) {
    if (list->numNodes == 0) {
        printf("Lista vazia\n");
        return;
    }
    int pos = list->positions[index];
    list->numNodes--;
    if (pos != list->numNodes) {
        list->A[pos] = list->A[list->numNodes];
        list->positions[list->A[pos].index] = pos;
        heapifyDown(list, pos);
    }
}

void printList(priorityList *list) {
    printf("--------------------\nLista:\n");
    printf("Size: %d\nnumNodes: %d\n", list->size, list->numNodes);
    for (int i = 0; i < list->numNodes; i++) {
        printf("%d: %.2lf\n", list->A[i].index, list->A[i].value);
    }
    printf("--------------------\n");
}

void freeList(priorityList *list) {
    free(list->A);
    free(list->positions);
    free(list);
}