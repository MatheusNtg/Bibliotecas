#include <stdio.h>
#include "arvore.h"

int main (){
    int qtd;
    node * Tree = NULL;
    
    scanf("%d",&qtd);

    for(int i = 0; i < qtd;i++){
        int conteudo;
        scanf("%d",&conteudo);
        addNode(&Tree,conteudo);
    }

    
    // printf("%d ",Tree->left->data);
    preOrd(&Tree);
    printf("\n");
    inOrd(&Tree);
    printf("\n");
    posOrd(&Tree);
    printf("\n");

    return 0;
}