/*
MM     MM AAAAAA DDDDD  EEEEEE
M M   M M AA  AA DD  DD EE
M  M M  M AAAAAA DD  DD EEEEEE
M   M   M AA  AA DD  DD EE
M       M AA  AA DDDDD  EEEEEE

BBBBB   YY    YY
B    B   YY  YY
BBBBB      YY
BB   B     YY
BBBBB      YY

MM     MM AAAAAA TTTTTT HH  HH EEEEEE UU  UU SSSSSS
M M   M M AA  AA   TT   HH  HH EE     UU  UU SS
M  M M  M AAAAAA   TT   HHHHHH EEEEEE UU  UU SSSSSS
M   M   M AA  AA   TT   HH  HH EE     UU  UU     SS
M       M AA   A   TT   HH  HH EEEEEE UUUUUU SSSSSS
*/

#ifndef LINKEDLIST
#define LINKEDLIST

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

// ================================
// Definition of the data structure
// ================================
struct Node{
    struct Node * next;
    // You can edit this element according to you needs
    int data;
};

typedef struct Node * node;

// ==========================
// Functions for this library
// ==========================

/*
    Function : createNode
        Cria um novo nó do tipo node.
    Parameters:
        void
    Returns:
        Retorna um novo nó do tipo node.
*/

node createNode();
int addNode(node *list, int data);
void printList(node * list);
int listSize(node * list);
int addNodePos(node * list, int data, int pos);

// ========================
// Functions implementation
// ========================
node createNode(){
    node newNode;
    newNode = (node) malloc(sizeof(node));
    if (newNode != NULL){
        newNode->data = 0;
        return newNode;
    }
    return NULL;
}

int addNode(node * list, int data){
    node newNode = createNode();
    if(newNode != NULL){
        newNode->data = data;
        // If the list is empty
        if (*list == NULL){
            *list = newNode;
            return TRUE;
        } 
        // If there is an element in the list
        else {
            node temp;
            temp = (*list);

            while(temp->next != NULL){
                temp = temp->next;  
            }

            temp->next = newNode;
            return TRUE;
        }
    }

    return FALSE;
}

void printList(node * list){
    node temp;
    temp = *list;
    if (temp == NULL) return;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Funcao que retorna o tamanho da lista
int listSize(node * list){
    if ((*list) == NULL) return 0;
    else{
        int i = 0;
        node temp;
        temp = (*list);
        while(temp != NULL){
            i++;
            temp = temp->next;
        }
        return i;
    }
}

int addNodePos(node * list, int data, int pos){
    if (pos >= listSize(list)){
        return FALSE;
    }else{
        int i = 0;
        node temp = (*list);
        while (i != pos){
            temp = temp->next;
            i++;
        }
        temp->data = data;
        return TRUE;
    }
}

#endif
