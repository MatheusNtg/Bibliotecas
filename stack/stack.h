#ifndef STACK
#define STACK

#include <stdlib.h>
#include <stdio.h>

/*
=========================
DEFINIÇÃO DO TIPO DE DADO
=========================
*/

struct Node{
    int data;
    struct Node * down;
};

typedef struct Node node;
typedef struct Node ** head;
/*
=====================
DEFINIÇÃO DAS FUNÇÕES
=====================
*/


/* 
    Função : Cria um nó da pilha.

    Retorno: Retorna um ponteiro para um nó da pilha.
*/
node * createStackNode();

/*
    Função       : Adciona um nó na pilha.

    Parâmetros(s):
        Stack: Pilha cujo o nó será adicionado.
        data : Contéudo do nó a ser adicionado.

    Retorno      : Retorna 1 caso adicione o nó com sucesso e 0 caso contrário. 
*/
int push(head Stack,int data);

/*
    Função       : Exclui um nó da pilha.

    Parâmetros(s):
        Stack: Pilha a ser removido o nó.

    Retorno      : Retorna um ponteiro para o nó excluido da pilha. 
*/
node * pop(head Stack);

/*
    Função      : Conta a quantidade de elementos presentes na pilha.

    Parâmetro(s):
        Stack: Pilha que será contado os elementos.

    Retorno     : Número de elementos da pilha.
*/
int stackSize(head Stack);

/*
    Função      : Diz se a pilha está vazia ou não.

    Parâmetro(s):
        Stack: Pilha que será analisada.

    Retorno     : Retorna 1 se a pilha estiver vazia, e 0 caso contrário.
*/
int isEmpty(head Stack);

/*
    Função       : Imprime uma pilha.

    Parâmetros(s):
        Stack: Pilha que será impressa.
    
    Retorno      : Retorna 1 caso seja realizada com sucesso e 0 caso contrário. 
*/
int printStack(head Stack);


/*
=========================
IMPLEMENTAÇÃO DAS FUNÇÕES
=========================
*/

node * createStackNode(){
    
    node * newNode = (node*) malloc(sizeof(node));
    
    if(newNode != NULL){
        newNode->data = 0;
        newNode->down = NULL;
        return newNode;
    }
    
    // Daqui para baixo so ocorre caso um erro aconteca.
    printf("Erro ao criar o nó da pilha\n");

    return NULL;
}

int push(head Stack,int data){ 
    if(*Stack == NULL){
        (*Stack) = createStackNode();
        (*Stack)->data = data;
        return 1;
    }else{
        node * temp;
        temp = (*Stack);
        (*Stack) = createStackNode();
        (*Stack)->down = temp;
        free(temp);
        return 1;
    }
    return 0;
}

int printStack(head Stack){
    node * temp;
    temp = (*Stack);
    if (temp == NULL){
        return 0;
    }
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->down;
    }
    return 1;
}

#endif