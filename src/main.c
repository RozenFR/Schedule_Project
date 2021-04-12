//
// Created by alex on 01/02/2021.
//
#include "olist.h"
#include "list.h"
#include "bstree.h"
#include "utilities.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

void testListes(void);
void testArbres(void);

int main(void) {
    //testListes();
    testArbres();
    return 0;
}

void testListes(void) {
    const void (*ptrViewInt)(const void* i);
    const int (*ptrCmp)(const void* a, const void* b);
    void (*ptrFreeInt)(void* i);
    ptrViewInt = &viewInt;
    ptrFreeInt = &freeInt;
    ptrCmp = &compareInt;
    OList* l1 = newOList(ptrCmp,viewInt,viewInt,ptrFreeInt,ptrFreeInt);
    int* x1;
    int* y1;
    srand(time(NULL));
    for(int i = 0; i<10; i++){
        x1 = (int*)calloc(1,sizeof(int));
        y1 = (int*)calloc(1, sizeof(int));
        assert(x1 != NULL && y1 != NULL);
        *x1 = rand()%51;
        *y1 = rand()%51;
        OListInsert(l1,x1,y1);
    }
    //viewOList(l1);
    List* l2 = OListToList(l1);
    /**for(int i = 0; i<10; i++){
        x1 = (int*)calloc(1,sizeof(int));
        assert(x1 != NULL);
        *x1 = rand()%51;
        listInsertFirst(l2,x1);
    }*/

    viewOList(l1);
    freeList(l2,1);//21 free
    freeOList(l1,1,0);

}

void testArbres(void){
    const void (*ptrViewInt)(const void* i);
    const int (*ptrCmp)(const void* a, const void* b);
    void (*ptrFreeInt)(void* i);
    ptrViewInt = &viewInt;
    ptrFreeInt = &freeInt;
    ptrCmp = &compareInt;
    BSTree* T = newEBSTree(compareInt,ptrViewInt,ptrViewInt,ptrFreeInt,ptrFreeInt);
    int* x1=calloc(1, sizeof(int));
    int* x2=calloc(1, sizeof(int));
    int* x3=calloc(1, sizeof(int));
    int* x4=calloc(1, sizeof(int));
    int* x5=calloc(1, sizeof(int));
    int* x6=calloc(1, sizeof(int));
    //int* x7=calloc(1, sizeof(int));
    *x1=1;
    *x2=5;
    *x3=4;
    *x4=3;
    //*x5=1;
    //*x6=5;
    //*x7=8;
    EBSTreeInsert(T,x1,x1);
    EBSTreeInsert(T,x2,x2);
    EBSTreeInsert(T,x3,x3);
    EBSTreeInsert(T,x4,x4);
    //EBSTreeInsert(T,x5,x5);
    //EBSTreeInsert(T,x6,x6);
    //BSTreeInsert(T,x7,x7);
    viewBSTree(T);
    freeBSTree(T,1,0);
}