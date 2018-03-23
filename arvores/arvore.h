/*
ESTA ÁRVORE COLOCA OS MENORES NÚMEROS NA ESQUERDA E OS MAIORES NA DIREITA
*/

#ifndef ARVORE
#define ARVORE
#define DEBUG


#include <stdio.h>
#include <stdlib.h>

/*
=========================
DEFINIÇÃO DO TIPO DE DADO
=========================
*/

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

typedef struct Node node;
typedef struct Node ** Root;

/*
===================
DEFINIÇÃO DA FUNÇÃO
===================
 */

/* 
    Função : Cria um Nó (Aloca a memória necessária para o nó).
    
    Retorno: Retorna um ponteiro para o nó da árvore criado.
*/
node * createNode();

/*
    Função    : Adiciona um nó com um determinado dado em uma árvore existente.
    
    Parâmetros:
        Tree: Ponteiro para o ponteiro da raiz da árvore que se queira adicionar o nó.
        data: Dado que se deseja adicionar no nó a ser colocado na árvore.
 */
void addNode(Root Tree,int data);

/*
    Função    : Realiza o percuso de pré-ordem em uma árvore existente.

    Parâmetros:
        Tree: Ponteiro para o ponteiro que indica a raiz da árvore. 
 */
void preOrd(Root Tree);

/*
    Função    : Realiza o percuso de pós-ordem em uma árvore existente.

    Parâmetros:
        Tree: Ponteiro para o ponteiro que indica a raiz da árvore. 
 */
void posOrd(Root Tree);

/*
    Função    : Realiza o percuso de in-ordem em uma árvore existente.

    Parâmetros:
        Tree: Ponteiro para o ponteiro que indica a raiz da árvore. 
 */
void inOrd(Root Tree);


/*
=========================
IMPLEMENTAÇÃO DAS FUNÇÕES
=========================
 */
node * createNode(){
    node * newNode;
    newNode = (node *) malloc(sizeof(node));
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