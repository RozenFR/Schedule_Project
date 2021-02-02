//
// Created by alex on 01/02/2021.
//
#include "list.h"
#include "utilities.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    void (*ptrViewInt)(const void* i);
    void (*ptrFreeInt)(void* i);
    ptrViewInt = &viewInt;
    ptrFreeInt = &freeInt;
    List* l1 = newList(ptrViewInt,ptrFreeInt);
    int* v;
    for(int i = 0; i<10; i++){
        v = (int*)calloc(1,sizeof(int));
        *v = rand()%51;
        listInsertLast(l1,v);
    }
    viewList(l1);
    freeList(l1,1);
    return 0;
}

