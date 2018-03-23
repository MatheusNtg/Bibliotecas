#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (){
    char phrase[100000],mesCripto[100000];
    int key;
    printf("Escreva a mensagem que deseja criptografar:\n");
    scanf("%[^\n]",phrase);
    printf("Escolha a chave da cifra de cesar (um número de 1 a 100)\n");
    scanf("%d",&key);
    for(int i = 0; i < strlen(phrase);i++){
        if((phrase[i] + key) > 'z'){
            mesCripto[i] = 'a' + (phrase[i] + ((key)/26) - 'z'); 
        }else{
            mesCripto[i] = phrase[i] + key;
        }
    }

    for(int i = 0; i < strlen(mesCripto);i++){
        printf("%c",mesCripto[i]);
    }
    printf("\n");

    return 0;
}
