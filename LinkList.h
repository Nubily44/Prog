// Header compilado apenas uma vez
#pragma once

// Definição do Booleano (com o nome abool para evitar erros de compilação)
typedef int abool;
#define true 1
#define false 0

// Nó da lista ligada
typedef struct LinkList_Node{
    char text[50];       // Palavra do nó
    int count;           // Quantidade de vezes que a palavra aparece  
    int address[1000];   // Quais linhas a palavra aparece
    struct LinkList_Node *next; // Próximo nó
} LinkList_Node;

// Lista ligada
typedef struct list{
    LinkList_Node *head; // Cabeça da lista
    LinkList_Node *tail; // Cauda da lista
} list;

// Criação da Lista Ligada
list *createLinkList();

// Inserção de um nó na lista ligada
abool LinkList_insertNode(list *LinkList, char *text);

// Impressão da Lista Ligada
void LinkList_print(list *LinkList);

// Impressão de um nó da Lista Ligada
void LinkList_printNode(LinkList_Node *node);

// Busca de um nó com uma palavra na Lista Ligada
LinkList_Node *LinkList_searchNode(list *LinkList, char *text);

// Contador de vezes que um nó com uma palavra aparece na Lista Ligada
int LinkList_searchTimes(list *LinkList, char *text);

// Liberação de memória da Lista Ligada
void LinkList_free(list *LinkList);