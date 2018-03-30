/*
ESTA ÁRVORE COLOCA OS MENORES NÚMEROS NA ESQUERDA E OS MAIORES NA DIREITA
*/

#ifndef ARVORE
#define ARVORE
#define DEBUG


#include <stdio.h>
#include <stdlib.h>

/*
=========================
DEFINIÇÃO DO TIPO DE DADO
=========================
*/

struct treeNode{
    int data;
    struct treeNode * esq;
    struct treeNode * dir;
};

typedef struct treeNode treeNode;
typedef struct treeNode ** root;

/*
===================
DEFINIÇÃO DA FUNÇÃO
===================
 */

/* 
    Função : Cria um Nó (Aloca a memória necessária para o nó).
    
    Retorno: Retorna um ponteiro para o nó da árvore criado.
*/
treeNode * createNode();

/*
    Função    : Adiciona um nó com um determinado dado em uma árvore existente.
    
    Parâmetros:
        Tree: Ponteiro para o ponteiro da raiz da árvore que se queira adicionar o nó.
        data: Dado que se deseja adicionar no nó a ser colocado na árvore.
 */
void addtreeNode(root Tree,int data);

/*
    Função    : Realiza o percuso de pré-ordem em uma árvore existente.

    Parâmetros:
        Tree: Ponteiro para o ponteiro que indica a raiz da árvore. 
 */
void preOrd(root Tree);

/*
    Função    : Realiza o percuso de pós-ordem em uma árvore existente.

    Parâmetros:
        Tree: Ponteiro para o ponteiro que indica a raiz da árvore. 
 */
void posOrd(root Tree);

/*
    Função    : Realiza o percuso de in-ordem em uma árvore existente.

    Parâmetros:
        Tree: Ponteiro para o ponteiro que indica a raiz da árvore. 
 */
void inOrd(root Tree);

/*
    Função    : Realiza o percuso de pré-ordem em uma árvore existente sem o uso de recursão.

    Parâmetros:
        Tree: Ponteiro para o ponteiro que indica a raiz da árvore. 
 */
void preOrd_Rec(root Tree);

/*
    Função    : Realiza o percuso de pós-ordem em uma árvore existente sem o uso de recursão.

    Parâmetros:
        Tree: Ponteiro para o ponteiro que indica a raiz da árvore. 
 */
void posOrd_Rec(root Tree);

/*
    Função    : Realiza o percuso de in-ordem em uma árvore existente sem o uso de recursão.

    Parâmetros:
        Tree: Ponteiro para o ponteiro que indica a raiz da árvore. 
 */
void inOrd_Rec(root Tree);

treeNode * pai(root Tree, int data);
treeNode * busca(root Tree,int data);
treeNode * maisDireita(root Tree);
void deleteNode(root Tree,int data);


/*
=========================
IMPLEMENTAÇÃO DAS FUNÇÕES
=========================
 */
treeNode * createtreeNode(){
    treeNode * newtreeNode;
    newtreeNode = (treeNode *) malloc(sizeof(treeNode));
    if (newtreeNode != NULL){
        newtreeNode->data = 0;
        newtreeNode->esq = NULL;
        newtreeNode->dir = NULL;

        return newtreeNode;
    }
    printf("Ouve um erro na criação de um novo nó\n");
    return NULL;
}

void addtreeNode(root Tree, int data){    
    if (*Tree == NULL){
        *Tree = createtreeNode();
        (*Tree)->data = data;
        
        return;
    }else{
        if(data < (*Tree)->data){
            addtreeNode(&((*Tree)->esq),data);
        }else if (data > (*Tree)->data){
            addtreeNode(&((*Tree)->dir),data);
        }
    }
}

void preOrd(root Tree){
    if(*Tree == NULL) return;

    printf("%d ",(*Tree)->data);
    preOrd(&((*Tree)->esq));
    preOrd(&((*Tree)->dir));
    
}

void posOrd(root Tree){
    if(*Tree == NULL) return;

    posOrd(&((*Tree)->esq));
    posOrd(&((*Tree)->dir));
    printf("%d ",(*Tree)->data);
    
}

void inOrd(root Tree){
    if(*Tree == NULL) return;

    inOrd(&((*Tree)->esq));
    printf("%d ",(*Tree)->data);
    inOrd(&((*Tree)->dir));
    
}

void deleteNode(root Tree,int data){
    /*****************************************
    * Temos três casos para se deletar um nó:*
    *    1 - Se o nó é uma folha.            *
    *    2 - Se o nó tem somente um filho.   *
    *    3 - Se o nó tem dois filhos.        *
    *                                        *
    *****************************************/

    //Antes de qualquer caso verificamos se a árvore não é nula.
    if((*Tree) == NULL)
        return;
    
    // Procuramos o nó que queremos remover.
    treeNode * temp;
    temp = busca(Tree,data);
    
    /*
    Caso 1:
        Neste caso, para se remover um nó k, fazemos com que o pai de k, p(k) aponte para NULL e excluimos
        o próprio nó. 
    */
    if(temp->esq == NULL && temp->dir == NULL){
        treeNode * paiNode;
        // Acha o pai do nó que queremos remover
        paiNode = pai(Tree,data);
        // Vê se o nó que queremos remover é o da esquerda ou o da direita
        // Esquerda
        printf("%d\n",paiNode->data);
        if (paiNode->esq != NULL){
            if (paiNode->esq->data == data){
                free(paiNode->esq);
                paiNode->esq = NULL;
                return;
            }
        }
        // Direita
        if (paiNode->dir != NULL){
            if(paiNode->dir->data == data){
                free(paiNode->dir);
                paiNode->dir = NULL;
                return;
            }
        }

    }

    /*
    Caso 2:
        Neste caso o nó tem apenas um filho, basicamente fazemos o pai de k apontar para o filho de k
    */
    
    // Ele tem somente um filho a direita
    if(temp->esq == NULL && temp->dir != NULL){
        treeNode * paiNode = pai(Tree,data);
        // Faz com que o filho da direita do pai de temp se torne o filho de temp
        paiNode->dir = temp->dir;
        // Libera o nó que queremos remover
        free(temp);
        return;
    }

    // Tendo somente um filho a esquerda
    if(temp->esq != NULL && temp->dir == NULL){
        treeNode * paiNode = pai(Tree,data);
        // Faz com que o filho da direita do pai de temp se torne o filho de temp
        paiNode->esq = temp->esq;
        // Libera o nó que queremos remover
        free(temp);
        return;
    }

    /*
    Caso 3:
        Neste caso o nó tem dois filhos, procuramos o filho mais a direita da sub-árvore a esquerda e
        substituimos os dados dele e liberamos esta folha
    */
    if (temp->esq != NULL && temp->dir != NULL){
        int aux;
        // Acho o nó mais a direita da sub-árvore a esquerda
        treeNode * direita = maisDireita(&(temp->esq));
        // Salva o dado do ponteiro direita em um inteiro auxiliar 
        aux = direita->data;
        // Deleta o nó mais a direita
        deleteNode(Tree,direita->data);
        // Transfere o dado para a o nó que deveria ser "removido"
        temp->data = aux;
    }

}
treeNode * pai(root Tree, int data){
    // So realizamos operações se a árvore não for nula
    if(*Tree != NULL){
        treeNode * temp;
        temp = *Tree;
        // Verifica se o nó a direita ou a esquerda é igual ao nó que desejamos procurar, caso seja
        // retorna ele
        if (temp->esq != NULL)
            if (temp->esq->data == data)
                return temp;
        if (temp->dir != NULL)
            if (temp->dir->data == data)
                return temp;
        // Procura na sub-árvore a esquerda caso o dado seja menor do que o que está no nó.
        if (data < temp->data)
            pai(&(temp->esq),data);
        // Procura na sub-árvore a direita caso o dado seja maior do que o que está no nó.
        else if (data > temp->data)
            pai(&(temp->dir),data);
    }
}

treeNode * busca(root Tree,int data){
    // Verifica se a árvore não é vazia
    if (*Tree == NULL)
        return NULL;
    // Checa se o dado do nó é o dado que estamos procurando
    if ((*Tree)->data == data)
        return (*Tree);
    // Caso não seja:
    // Se o dado for menor do que o dado atual, vai para a árvore da esquerda
    if (data < (*Tree)->data)
        busca(&((*Tree)->esq),data);
    // Caso contrário vai para a árvore da direita
    else
        busca(&((*Tree)->dir),data);
}

treeNode * maisDireita(root Tree){
    // Verificamos se a árvore não é vazia
    if(*Tree != NULL){
        treeNode * temp = (*Tree);
        // Caminha até o filho mais a direita
        while(temp->dir != NULL){
            temp = temp->dir;
        }
        return temp;
    }
}

#endif