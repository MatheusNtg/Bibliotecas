#include <stdio.h>
#include <stdlib.h>
#include "double.h"

int main (){
    node list;
    list = NULL;
    addNode(&list,1);
    addNode(&list,3);
    addNode(&list,6);
    printList(&list);
    ordPrintList(&list,2);
    return 0;
}