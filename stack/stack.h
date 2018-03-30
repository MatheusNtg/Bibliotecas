#ifndef STACK
#define STACK

#include <stdlib.h>
#include <stdio.h>
#include "../arvores/arvore.h"

/*
=========================
DEFINIÇÃO DO TIPO DE DADO
=========================
*/

struct stackNode{
    node * data;
    struct stackNode * down;
};

typedef struct stackNode stackNode;
typedef struct stackNode ** head;
/*
=====================
DEFINIÇÃO DAS FUNÇÕES
=====================
*/


/* 
    Função : Cria um nó da pilha.

    Retorno: Retorna um ponteiro para um nó da pilha.
*/
stackNode * createstackNode();

/*
    Função       : Adciona um nó na pilha.

    Parâmetros(s):
        Stack: Pilha cujo o nó será adicionado.
        data : Contéudo do nó a ser adicionado.

    Retorno      : Retorna 1 caso adicione o nó com sucesso e 0 caso contrário. 
*/
int push(head Stack,node * data);

/*
    Função       : Exclui um nó da pilha.

    Parâmetros(s):
        Stack: Pilha a ser removido o nó.

    Retorno      : Retorna um ponteiro para o nó excluido da pilha. 
*/
stackNode * pop(head Stack);

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

stackNode * createstackNode(){
    
    stackNode * newStackNode = (stackNode*) malloc(sizeof(stackNode));
    
    if(newStackNode != NULL){
        newStackNode->data = NULL;
        newStackNode->down = NULL;
        return newStackNode;
    }
    
    // Daqui para baixo so ocorre caso um erro aconteca.
    printf("Erro ao criar o nó da pilha\n");

    return NULL;
}

int push(head Stack,node * data){ 
    if(*Stack == NULL){
        (*Stack) = createstackNode();
        (*Stack)->data = data;
        return 1;
    }else{
        stackNode * temp;
        temp = createstackNode();
        temp->data = data;
        temp->down = (*Stack);
        (*Stack) = temp;
        return 1;
    }
    return 0;
}

int printStack(head Stack){
    stackNode * temp;
    temp = (*Stack);
    if (temp == NULL){
        return 0;
    }
    while(temp != NULL){
        printf("%p\n",temp->data);
        temp = temp->down;
    }
    return 1;
}

int stackSize(head Stack){
    int i;
    if((*Stack) == NULL) return 0; 
    for(stackNode * temp = (*Stack); temp != NULL; temp=temp->down)i++;
    return i;
}   

int isEmpty(head Stack){
    if(!stackSize(Stack)){
        return 1;
    }else{
        return 0;
    }
}

stackNode * pop(head Stack){
    if(!isEmpty(Stack)){
        stackNode * temp;
        temp = (*Stack);
        (*Stack) = (*Stack)->down;
        temp->down = NULL;
        return temp;
    }

    return NULL;
}

#endif