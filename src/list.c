#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "../include/utilities.h"
#include "../include/list.h"

/*
 * Construire et initialiser un nouveau nœud d'une liste doublement chaînée.
 * Renvoie le nouveau nœud créé.
 */
static LNode * newLNode(void * data) {
    LNode* nouveau = (LNode*) calloc (1,sizeof(LNode));
    assert(nouveau!=NULL);
    nouveau->succ = NULL;
    nouveau->pred = NULL;
    nouveau ->data = data;
    return nouveau;
}

List * newList(void (*viewData)(const void*), void (*freeData)(void*)) {
    List* L = (List*)calloc(1, sizeof(List));
    assert(L!=NULL);
    L->head = NULL;
    L->tail = NULL;
    L->numelm = 0;
    L->viewData = viewData;
    L->freeData = freeData;
    return L;
}

void freeList(List * L, int deleteData) {
    LNode* aSauver;
    while(L->head != NULL){
        aSauver = L->head->succ;
        if(deleteData == 1) {
            (L->freeData)(L->head->data);
        }
        free(L->head);
        L->head = aSauver;
    }
    free(L);
}

void viewList(const List * L) {
    if(L->numelm == 0)
        printf("Liste VIDE\n");
    else{
        for(LNode* aAfficher = L->head; aAfficher != NULL; aAfficher = aAfficher->succ){
            (L->viewData)(aAfficher->data);
        }
        printf("\n");
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
    LNode* nouveau;
    if(L->head==NULL)
        L->head=L->tail= newLNode(data);
    else{
        nouveau= newLNode(data);
        L->tail->succ=nouveau;
        nouveau->pred=L->tail;
        L->tail=nouveau;
    }
    L->numelm++;
}

void listInsertAfter(List * L, void * data, LNode * ptrelm) {
    if(ptrelm==NULL)
        error("listInsertAfter() : tentative d'insértion après le pointeur \"NULL\"");
    else if (L->head==NULL){
        L->head=L->tail= newLNode(data);
        L->numelm++;
    }
    else{
        LNode *nouveau= newLNode(data);
        nouveau->pred=ptrelm;
        nouveau->succ=ptrelm->succ;
        if(ptrelm->succ!=NULL)
            ptrelm->succ->pred=nouveau;
        else
            L->tail=nouveau;
        ptrelm->succ=nouveau;
        L->numelm++;
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
    else{
        LNode * queue = L->tail;
        L->tail = L->tail->pred;
        L->numelm--;
        if(L->numelm == 0)
            L->head = NULL;
        else
            L->tail->succ = NULL;
        queue->pred = NULL;
        return queue;
    }
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
