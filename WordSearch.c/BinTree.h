// Header compilado apenas uma vez
#pragma once

// Definição do Booleano (com o nome abool para evitar erros de compilação)
typedef int abool;
#define true 1
#define false 0

// Nó da árvore binária
typedef struct BinTree_Node{
    char text[50];       // Palavra do nó
    int count;           // Quantidade de vezes que a palavra aparece 
    int address[1000];   // Quais linhas a palavra aparece
    struct BinTree_Node *left;  // Nó à esquerda
    struct BinTree_Node *right; // Nó à direita
} BinTree_Node;

// Árvore Binária
typedef struct tree{
    BinTree_Node *root; // Raiz da árvore
} tree;

// Criação da Árvore Binária
tree *createBinTree();

// Inserção de um nó na Árvore Binária
abool BinTree_insertNode(tree *BinTree, char *text);

// Impressão da Árvore Binária
void BinTree_print(tree *BinTree);

// Impressão de um nó da Árvore Binária
void BinTree_printNode(BinTree_Node *node);

// Busca de um nó com uma palavra na Árvore Binária
BinTree_Node *BinTree_searchNode(tree *BinTree, char *text);

// Contador de vezes que um nó com uma palavra aparece na Árvore Binária
int BinTree_searchTimes(tree *BinTree, char *text);

// Liberação de memória da Árvore Binária
void BinTree_free(tree *BinTree);

// Liberação de memória de um nó da Árvore Binária (auxiliar para BinTree_free)
void BinTree_freeNode(BinTree_Node *node);