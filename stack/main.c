#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main (){
    int size;
    node * stack = NULL;
    node * teste = NULL;
    scanf("%d\n",&size);
    for(int i = 0; i < size;i++){
        int elemento;
        scanf("%d",&elemento);
        push(&stack,elemento);
    }
    printStack(&stack);
    printf("Tamanho: %d\n",stackSize(&stack));
    printf("Vazia ? ");
    
    if(isEmpty(&stack)){
        printf("Sim\n");
    }else{
        printf("Não\n");
    }
    teste = pop(&stack);
    printf ("Stack:\n");
    printStack(&stack);
    printf("\n");
    
    printf("Teste:\n");
    printStack(&teste);
    printf("\n");
    return 0;
}