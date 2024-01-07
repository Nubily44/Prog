#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <strings.h>

#include "BinTree.h"

tree *createBinTree(){
    tree *BinTree = (tree *)malloc(sizeof(tree));
    BinTree->root = NULL;
    return BinTree;
}

abool BinTree_insertNode(tree *BinTree, char *text){

    BinTree_Node *newNode = (BinTree_Node *)malloc(sizeof(BinTree_Node));
    strcpy(newNode->text, text);
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->count = 0;


    if(BinTree->root == NULL){
        BinTree->root = newNode;
    }else{
        BinTree_Node *current = BinTree->root;
        while(current != NULL){
            if(strcasecmp(current->text, text) > 0){
                if(current->left == NULL){
                    current->left = newNode;
                    break;
                }else{
                    current = current->left;
                }
            }else{
                if(current->right == NULL){
                    current->right = newNode;
                    break;
                }else{
                    current = current->right;
                }
            }
        }
    }
    return true;
}

BinTree_Node *BinTree_searchNode(tree *BinTree, char *text){
    BinTree_Node *current = BinTree->root;
    while(current != NULL){
        if(strcasecmp(current->text, text) == 0){
            return current;
        }
        if(strcasecmp(current->text, text) > 0){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    return NULL;
}

void BinTree_print(tree *BinTree){
    BinTree_printNode(BinTree->root);
}

void BinTree_printNode(BinTree_Node *node){
    if(node == NULL){
        return;
    }
    BinTree_printNode(node->left);

    printf("%s\n", node->text);
    printf("%d\n", node->count);
    for(int i = 0; i < node->count; i++){
        printf("%d ", node->address[i]);
    }
    printf("\n");

    BinTree_printNode(node->right);
}

int BinTree_searchTimes(tree *BinTree, char *text){
    BinTree_Node *current = BinTree->root;
    int t = 0;
    while(current != NULL){
        if(strcasecmp(current->text, text) == 0){
            t++;
        }
        if(strcasecmp(current->text, text) > 0){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    return t;
}

void BinTree_free(tree *BinTree) {

    BinTree_freeNode(BinTree->root);

}

void BinTree_freeNodeHelper(BinTree_Node *node) {
    if (node == NULL) {
        return; 
    }

    BinTree_freeNodeHelper(node->left);
    BinTree_freeNodeHelper(node->right);

    free(node);
}

void BinTree_freeNode(BinTree_Node *node) {
    free(node);
}