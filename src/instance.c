#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "utilities.h"
#include "list.h"
#include "olist.h"
#include "bstree.h"
#include "instance.h"

/***********************************************
 * TASK
 ***********************************************/

Task * newTask(char* id, int proctime, int reltime, int deadline, int weight) {
    assert(proctime > 0);
    assert(reltime >= 0);
    assert((deadline >= reltime + proctime));
    Task *nouvelle= (Task*)calloc(1, sizeof(Task));
    nouvelle->id=id;
    nouvelle->processingTime=proctime;
    nouvelle->releaseTime=reltime;
    nouvelle->deadline=deadline;
    nouvelle->weight=weight;
    return nouvelle;
}

void freeTask(void* task) {
    free(task);
}

void viewTask(const void *task) {
    printf("ID : %s\n",((Task*)task)->id);
    printf("PROCESSING TIME : %d\n",((Task*)task)->processingTime);
    printf("RELEASE TIME : %d\n",((Task*)task)->releaseTime);
    printf("DEADLINE : %d\n",((Task*)task)->deadline);
    printf("WEIGHT : %d\n",((Task*)task)->weight);
}

/************************************************
 * INSTANCE
 ************************************************/

Instance readInstance(char * filename) {
    FILE* ptrFichier;
    if((ptrFichier=fopen(filename,"r"))==NULL);
        error("readInstance() : echec d'ouverture du fichier");
    Instance I= newList(&viewTask,&freeTask);
    char buffId[255];
    int buffProcTime=0,buffReleaseTime=0,buffDeadlineTime=0,buffWeight=0;
    while(fscanf(ptrFichier,"%s\t%d\t%d\t%d\t%d\n",buffId,&buffProcTime,&buffReleaseTime,&buffDeadlineTime,&buffWeight)!=EOF){
        Task *task= newTask(buffId,buffProcTime,buffReleaseTime,buffDeadlineTime,buffWeight);
        listInsertFirst(I,(void*)task);
    }
    return I;
}

void viewInstance(Instance I) {
    viewList(I);
}

void freeInstance(Instance I, int deleteData) {
    freeList(I,deleteData);
}

/*****************************************************************************
 * Ordonner l'instance
 *****************************************************************************/

/**
 * @brief
 * Comparer les tâches a et b par rapport à l'ordre SPT :
 * (+) Renvoie 1, si a précède b
 * (+) Renvoie 0, si b précède a
 * Ordre SPT : a précède b si
 * (+) durée de a < durée de b
 * (+) durée de a = durée de b ET date de libération de a < date de libération de b
 */
static int spt(const void* a, const void* b) {
    /* A FAIRE */
}

/**
 * @brief
 * Comparer les tâches a et b par rapport à l'ordre LPT :
 * (+) Renvoie 1, si a précède b
 * (+) Renvoie 0, si b précède a
 * Ordre LPT : a précède b si
 * (+) durée de a > durée de b
 * (+) durée de a = durée de b ET date de libération de a < date de libération de b
 */
static int lpt(const void* a, const void* b) {
    /* A FAIRE */
}

/**
 * @brief
 * Comparer les tâches a et b par rapport à l'ordre WSPT :
 * (+) Renvoie 1, si a précède b
 * (+) Renvoie 0, si b précède a
 * Ordre WSPT : a précède b si
 * (+) poids / durée de a > poids / durée de b
 * (+) poids / durée de a = poids / durée de b
 *     ET durée de a < durée de b
 * (+) poids / durée de a = poids / durée de b
 *     ET durée de a = durée de b
 *     ET date de libération de a < date de libération de b
 */
static int wspt(const void* a, const void* b) {
    /* A FAIRE */
}

/**
 * @brief
 * Comparer les tâches a et b par rapport à l'ordre FCFS :
 * (+) Renvoie 1, si a précède b
 * (+) Renvoie 0, si b précède a
 * Ordre FCFS : a précède b si
 * (+) date de libération de a < date de libération de b
 * (+) date de libération de a = date de libération de b
 *     ET durée de a > durée de b
 */
static int fcfs(const void* a, const void* b) {
    /* A FAIRE */
}

void reorderInstance(Instance I,  DataStructure structtype, Order order) {
    /* A FAIRE */
}