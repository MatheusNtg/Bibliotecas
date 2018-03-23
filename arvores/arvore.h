#ifndef ARVORE
#define ARVORE
#define DEBUG


#include <stdio.h>
#include <stdlib.h>

/*
ESTA ÁRVORE COLOCA OS MENORES NÚMEROS NA ESQUERDA E OS MAIORES NA DIREITA
*/

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

typedef struct Node node;
typedef struct Node ** Root;

node * createNode();
void addNode(Root Tree,int data);
void preOrd(Root Tree);
void posOrd(Root Tree);
void inOrd(Root Tree);

node * createNode(){
    node * newNode;
    newNode = malloc(sizeof(node));
    if (newNode != NULL){
        newNode->data = 0;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }
    printf("Ouve um erro na criação de um novo nó\n");
    return NULL;
}

void addNode(Root Tree, int data){    
    if (*Tree == NULL){
        *Tree = createNode();
        (*Tree)->data = data;
        
        return;
    }else{
        if(data < (*Tree)->data){
            addNode(&((*Tree)->left),data);
        }else if (data > (*Tree)->data){
            addNode(&((*Tree)->right),data);
        }
    }
}

void preOrd(Root Tree){
    if(*Tree == NULL) return;

    printf("%d ",(*Tree)->data);
    preOrd(&((*Tree)->left));
    preOrd(&((*Tree)->right));
    
}

void posOrd(Root Tree){
    if(*Tree == NULL) return;

    posOrd(&((*Tree)->left));
    posOrd(&((*Tree)->right));
    printf("%d ",(*Tree)->data);
    
}

void inOrd(Root Tree){
    if(*Tree == NULL) return;

    inOrd(&((*Tree)->left));
    printf("%d ",(*Tree)->data);
    inOrd(&((*Tree)->right));
    
}

#endif