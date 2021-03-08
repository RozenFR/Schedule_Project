#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
/*
 * Construire et initialiser un nouveau nœud d'une liste doublement chaînée.
 * Renvoie le nouveau nœud créé.
 */
static LNode * newLNode(void * data) {
    LNode* nouveau = (LNode*) calloc(1,sizeof(LNode));
    nouveau ->data = data;
    return nouveau;
}

List * newList(void (*viewData)(const void*), void (*freeData)(void*)) {
    List* L = (List *) calloc(1, sizeof(List));
    L->viewData = viewData;
    L->freeData = freeData;
    return L;
}

void freeList(List * L, int deleteData) {
    LNode* aSauver;
    while (L->head != NULL) {
        aSauver = L->head->succ;

        if (deleteData == 1)
            (L->freeData)(L->head->data);

        free(L->head);
        L->head = aSauver;
    }
    free(L);
}

void viewList(const List * L) {
    if(L->numelm == 0)
        printf("[ ]\n");
    else{
        printf("[ ");
        for(LNode* aAfficher = L->head; aAfficher != NULL; aAfficher = aAfficher->succ){
            (L->viewData)(aAfficher->data);
        }
        printf("]\n");
    }
}

void listInsertFirst(List * L, void * data) {
    LNode* nouveau = newLNode(data);
    nouveau->succ = L->head;
    if(L->head != NULL)
        L->head->pred = nouveau;
    else
        L->tail = nouveau;
    L->head = nouveau;
    L->numelm++;
}

void listInsertLast(List * L, void * data) {
    LNode* nouveau = newLNode(data);
    nouveau->pred = L->tail;
    if(L->tail != NULL)
        L->tail->succ = nouveau;
    else
        L->head = nouveau;
    L->tail = nouveau;
    L->numelm++;
}

void listInsertAfter(List * L, void * data, LNode * ptrelm) {
    //Au cas où ptrelm == NULL et la liste L est vide
   if(L->numelm == 0)
       listInsertFirst(L,data);
   else{
       LNode* nouveau = newLNode(data);
       nouveau->succ = ptrelm->succ;
       nouveau->pred = ptrelm;
       ptrelm->succ = nouveau;
       L->numelm++;
       if(L->tail == ptrelm)
           L->tail = nouveau;
   }


}

LNode* listRemoveFirst(List * L) {
    if(L->numelm == 0)
        exit(EXIT_FAILURE);
    LNode* tete = L->head;
    L->head = L->head->succ;
    L->numelm--;
    if(L->numelm == 0)
        L->tail = NULL;
    tete->succ = NULL;
    return tete;
}

LNode* listRemoveLast(List * L) {
    if(L->numelm == 0)
        exit(EXIT_FAILURE);
    LNode* queue = L->tail;
    L->tail = L->tail->pred;
    L->numelm--;
    if(L->numelm == 0)
        L->head = NULL;
    queue->pred = NULL;
    return queue;
}

LNode* listRemoveNode(List * L, LNode * node) {
    if(L->numelm == 0)
        exit(EXIT_FAILURE);
    else if(node == L->head)
        return listRemoveFirst(L);
    else if(node == L->tail)
        return listRemoveLast(L);
    else{
        node->pred->succ = node->succ;
        node->succ->pred = node->pred;
        node->succ = NULL;
        node->pred = NULL;
        return node;
    }
}