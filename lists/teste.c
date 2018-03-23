#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dado;
}teste1;

void funcao(int ** pont){
    int * k;
    k = malloc(sizeof(int));
    pont = &k;
}

int main (){
    int * a, **b;
    a = malloc(sizeof(int));
    b = &a;
    printf("%p\n",b);
    funcao(b);
    printf("%p\n",b);
}

