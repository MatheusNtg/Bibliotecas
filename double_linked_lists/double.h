#ifndef DOUBLE_LINKED
#define DOUBLE_LINKED
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

// =================
// Struct definition
// =================
struct Node{
    struct Node * next; //Ponteiro do node que aponta para o próximo node
    struct Node * prev; //POnteiro do node que aponta para o node anterior
    // You can edit this item according to you needs
    int data;  //conteudo do node
};

typedef struct Node * node;

// ====================
// Function definitions
// ====================

/*
    Função:
        Cria um nó com todos os elemento nulos

    Return:
        Retorna um ponteiro para um nó caso o nó seja alocado com sucesso
        ou retorna 0 caso não seja possível alocar o nó.

*/
node createNode();

/*
    Função:
        Adiciona um nó com o dado <data> no final da lista <list>.

    Parâmetros:
        node * list: Lista a ser adicionada o novo nó.
        int data   : Dado a ser adicionado na lista.

    Return:
        Retorna 1(TRUE) caso adicione o nó com sucesso
        e retorna 0(FALSE) caso contrário.
*/
int addNode(node * list, int data);

/*
    Função:
        Adciona um nó na lista <list> na posição <pos> com o dado <data>
    
    Parâmetros:
        node * list: Ponteiro para a lista a ser adicionado o nó.
        int pos    : Posição na lista a ser adicionado o nó (é necessário que
        esta posição seja válida).
        int data   : Dado a ser adicionado na lista.
    
    Return:
        Retorna 1 caso obtenho sucesso e 0 caso contrário.

*/
int addNodePos(node * list, int pos, int data);

/*
    Função:
        Remove um nó na posição <pos> da lista <list>.
    
    Parâmetros:
        node * list: Ponteiro para a lista cujo o nó será removido.
        int pos    : Posição em que o nó se encontra.

    Return:
        Retorna 1 caso obtenha sucesso e 0 caso contrário.
*/
int removeNode(node * list, int pos);

/*
    Função:
        Procura o elemento <element> na lista <list>.

    Parâmetros:
        node * list: Ponteiro para a lista cujo o elemento será procurado.
        int element: Elemento que se deseja buscar.

    Return:
        Retorna a posição do elemento na lista caso o encontre ou retorna -1
        caso o elemento não exista na lista. 
*/
int searchData(node * list, int element);

/*
    Função:
        Imprime uma lista não vazia da esqueda para a direita.
   
    Parâmetro:
        node * list: Ponteiro para uma lista.
    
    Return:
        Retorna 1 caso imprima a lista com sucesso, ou 0 caso a
        lista esteja vazia, não exista, ou apresente algum erro
        na impressão.
*/
int printList(node * list);

int ordPrintList(node * list, int order);

// =======================
// Funtion Implementations
// =======================

node createNode(){
    node newNode;
    newNode = (node) malloc(sizeof(node));
    if (newNode != NULL){
        newNode->next = newNode->prev = NULL;
        newNode->data = 0;
        return newNode;
    }
    return FALSE;
}

int addNode(node * list, int data){
    node newNode = createNode();
    newNode->data = data;
    if((*list) == NULL){
        *list = newNode;
        return TRUE;
    } else {
        node temp;
        temp = *list;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return TRUE;
    }
    return FALSE;
}

int printList(node * list){
    node temp;
    temp = *list;
    if(temp != NULL){
        while(temp->next != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
        return TRUE;
    }
    return FALSE;    
}

int ordPrintList(node * list, int order){
    node temp = *list;
    // Caso a lista exista entra nesta condição
    if(temp != NULL){
        // Para imprimir da esquerda para direita
        if(order == 1){
            while(temp->next != NULL){
                printf("%d ",temp->data);
                temp = temp->next;
            }
            return TRUE;
        }
        // Para imprimri da direita para esquerda
        else if(order == 2){
            // Chega no final da lista
            while(temp->next != NULL){
                temp = temp->next;
            }
            // Imprime a lista em ordem inversa
            while(temp->prev != NULL){
                printf("%d ",temp->data);
                temp = temp->prev;
            }
            printf("%d\n",temp->data);
            return TRUE;
        }
    }
    return FALSE;
}

#endif
