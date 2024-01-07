#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <strings.h>

#include "LinkList.h"

list *createLinkList(){
    list *LinkList = (list *)malloc(sizeof(list));
    LinkList->head = NULL;
    LinkList->tail = NULL;
    return LinkList;
}

abool LinkList_insertNode(list *LinkList, char *text){

    LinkList_Node *newNode = (LinkList_Node *)malloc(sizeof(LinkList_Node));
    strcpy(newNode->text, text);
    newNode->next = NULL;
    newNode->count = 0;

    if(LinkList->head == NULL){
        LinkList->head = newNode;
        LinkList->tail = newNode;
    }else{
        LinkList->tail->next = newNode;
        LinkList->tail = newNode;
    }
    return true;
}

void LinkList_printNode(LinkList_Node *node){
    printf("%s\n", node->text);
    printf("%d\n", node->count);
    for(int i = 0; i < node->count; i++){
        printf("%d ", node->address[i]);
    }
    printf("\n");
}

void LinkList_print(list *LinkList){
    LinkList_Node *current = LinkList->head;
    while(current != NULL){
        LinkList_printNode(current);
        current = current->next;
    }
}

LinkList_Node *LinkList_searchNode(list *LinkList, char *text){
    LinkList_Node *current = LinkList->head;
    while(current != NULL){
        if(strcasecmp(current->text, text) == 0){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int LinkList_searchTimes(list *LinkList, char *text){
    LinkList_Node *current = LinkList->head;
    int t = 0;
    while(current != NULL){
        if(strcasecmp(current->text, text) == 0){
            t++;
        }
        current = current->next;
    }
    return t;
}

void LinkList_free(list *LinkList){
    LinkList_Node *current = LinkList->head;
    LinkList_Node *next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    free(LinkList);
}