#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main (){
    node lista;
    lista = NULL;
    addNode(&lista,3);
    addNode(&lista,5);
    addNode(&lista,1);
    printList(&lista);
    addNodePos(&lista,10,3);
    printList(&lista);
    printf("%d\n",listSize(&lista));
    return 0;
}
