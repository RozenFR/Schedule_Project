#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../include/utilities.h"
#include "../include/list.h"
#include "../include/olist.h"
#include "../include/bstree.h"
#include "../include/instance.h"


/***********************************************
 * TASK
 ***********************************************/

Task * newTask( char* id, int proctime, int reltime, int deadline, int weight ) {
    assert( proctime > 0 );
    assert( reltime >= 0 );
    assert( ( deadline >= reltime + proctime ) );
    Task * nouvelle = ( Task * ) calloc ( 1, sizeof( Task ) );
    nouvelle -> id = ( char * ) calloc ( strlen( id ) + 1, sizeof ( char ) );
    strcpy( nouvelle -> id, id );
    nouvelle -> processingTime = proctime;
    nouvelle -> releaseTime = reltime;
    nouvelle -> deadline = deadline;
    nouvelle -> weight = weight;
    return nouvelle;
}

void freeTask( void * task ) {
    Task * aSupprimer = ( Task * ) task;
    free( aSupprimer -> id );
    free( task );
}

void viewTask( const void * task ) {
    printf("{ ID : %s\t", ( ( Task * ) task ) -> id );
    printf("PROC TIME : %d\t", ( ( Task * ) task ) -> processingTime );
    printf("REL TIME : %d\t", ( ( Task * ) task ) -> releaseTime );
    printf("DEADLINE : %d\t", ( ( Task * ) task ) -> deadline );
    printf("WEIGHT : %d }\n", ( ( Task * ) task ) -> weight );
}

/************************************************
 * INSTANCE
 ************************************************/

Instance readInstance( char * filename ) {
    FILE * ptrFichier = fopen( filename,"r" ) ;
    if( ! ptrFichier )
        error("readInstance() : echec d'ouverture du fichier" );
    Instance I = newList( &viewTask, &freeTask );
    char buffId [10];
    int buffProcTime = 0;
    int buffReleaseTime = 0;
    int buffDeadlineTime = 0;
    int buffWeight = 0;
    while( fscanf ( ptrFichier,"%s %d %d %d %d", buffId, &buffProcTime, &buffReleaseTime, &buffDeadlineTime, &buffWeight ) != EOF ) {
        Task * task = newTask( buffId, buffProcTime, buffReleaseTime, buffDeadlineTime, buffWeight );
        listInsertFirst( I, ( void * ) task );
    }
    fclose( ptrFichier );
    return I;
}

void viewInstance( Instance I ) {
    viewList( I );
}

void freeInstance( Instance I, int deleteData ) {
    freeList( I, deleteData );
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
static int spt( const void * a, const void * b ) {
    Task * A = ( Task * ) a;
    Task * B = ( Task * ) b;
    if ( A -> processingTime < B -> processingTime || ( A -> processingTime == B -> processingTime && A -> releaseTime < B -> releaseTime ) ) {
        return 1;
    } else {
        return 0;
    }
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
static int lpt( const void * a, const void * b ) {
    Task * A = ( Task * ) a;
    Task * B = ( Task * ) b;
    if ( ( A -> processingTime > B -> processingTime ) || ( A -> processingTime == B -> processingTime && A -> releaseTime < B -> releaseTime ) ) {
        return 1;
    } else {
        return 0;
    }
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
static int wspt( const void * a, const void * b ) {
    Task * A = ( Task * ) a;
    Task * B = ( Task * ) b;
    if ( ( ( A -> weight / A -> processingTime ) > ( B -> weight / B -> processingTime ) ) || ( ( ( ( ( A -> weight / A -> processingTime ) == ( B -> weight / B -> processingTime ) ) && ( A -> processingTime < B -> processingTime || ( ( ( A -> weight / A -> processingTime ) == ( B -> weight / B -> processingTime ) ) && ( ( ( A -> processingTime == B -> processingTime ) && ( A -> releaseTime < B -> releaseTime ) ) ) ) ) ) ) ) ) {
        return 1;
    } else {
        return 0;
    }
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
static int fcfs( const void * a, const void * b ) {
    Task * A = ( Task * ) a;
    Task * B = ( Task * ) b;
    if ( A -> releaseTime < B -> releaseTime || ( ( A -> releaseTime == B -> releaseTime ) && ( A -> processingTime > B -> processingTime ) ) ) {
        return 1;
    } else {
        return 0;
    }
}


void reorderInstance( Instance * I,  DataStructure structtype, Order order ) {
    switch ( order ) {
        case SPT : {
            switch ( structtype ) {
                case OL : {
                    OList * orderedOList = newOList( &spt, &viewTask, &viewTask, &freeTask, &freeTask );
                    for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                        OListInsert( orderedOList, nodeActuel -> data, nodeActuel -> data );
                    freeList( * I, 0 );
                    * I = OListToList( orderedOList );
                } break;
                case BST : {
                    BSTree * resultBSTree = newBSTree( &spt, &viewTask, &viewTask, &freeTask, &freeTask );
                    for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                        BSTreeInsert( resultBSTree, nodeActuel -> data, nodeActuel -> data );
                    freeList( * I, 0 );
                    * I = BSTreeToList( resultBSTree );
                } break;
                case EBST : {
                    BSTree * resultEquilibreBSTree = newEBSTree( &spt, &viewTask, &viewTask, &freeTask, &freeTask );
                    for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                        EBSTreeInsert( resultEquilibreBSTree, nodeActuel -> data, nodeActuel -> data );
                    freeList( * I, 0 );
                    * I = BSTreeToList( resultEquilibreBSTree );
                } break;
                default:{
                    error("reorderInstance() : la structure de donnée utilisée dans les tris des tâches est différente de OL - BST - EBST\n");
                }
            } break;
            case LPT : {
                switch ( structtype ) {
                    case OL : {
                        OList * orderedOList = newOList( &lpt, &viewTask, &viewTask, &freeTask, &freeTask );
                        for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                            OListInsert( orderedOList, nodeActuel -> data, nodeActuel -> data );
                        freeList( * I, 0 );
                        * I = OListToList( orderedOList );
                    } break;
                    case BST : {
                        BSTree * resultBSTree = newBSTree( &lpt, &viewTask, &viewTask, &freeTask, &freeTask );
                        for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                            BSTreeInsert( resultBSTree, nodeActuel -> data, nodeActuel -> data );
                        freeList( * I, 0 );
                        * I = BSTreeToList( resultBSTree );
                    } break;
                    case EBST : {
                        BSTree * resultEquilibreBSTree = newEBSTree( &lpt, &viewTask, &viewTask, &freeTask, &freeTask );
                        for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                            EBSTreeInsert( resultEquilibreBSTree, nodeActuel -> data, nodeActuel -> data );
                        freeList( * I, 0 );
                        * I = BSTreeToList( resultEquilibreBSTree );
                    } break;
                    default:{
                        error("reorderInstance() : la structure de donnée utilisée dans les tris des tâches est différente de OL - BST - EBST\n");
                    }
                }
            } break;
            case WSPT : {
                switch ( structtype ) {
                    case OL : {
                        OList * orderedOList = newOList( &wspt, &viewTask, &viewTask, &freeTask, &freeTask );
                        for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                            OListInsert( orderedOList, nodeActuel -> data, nodeActuel -> data );
                        freeList( * I, 0 );
                        * I = OListToList( orderedOList );
                    } break;
                    case BST : {
                        BSTree * resultBSTree = newBSTree( &wspt, &viewTask, &viewTask, &freeTask, &freeTask );
                        for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                            BSTreeInsert( resultBSTree, nodeActuel -> data, nodeActuel -> data );
                        freeList( * I, 0 );
                        * I = BSTreeToList( resultBSTree );
                    } break;
                    case EBST : {
                        BSTree * resultEquilibreBSTree = newEBSTree( &wspt, &viewTask, &viewTask, &freeTask, &freeTask );
                        for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                            EBSTreeInsert( resultEquilibreBSTree, nodeActuel -> data, nodeActuel -> data );
                        freeList( * I, 0 );
                        * I = BSTreeToList( resultEquilibreBSTree );
                    } break;
                    default:{
                        error("reorderInstance() : la structure de donnée utilisée dans les tris des tâches est différente de OL - BST - EBST\n");
                    }
                }
            } break;
            case FCFS : {
                switch ( structtype ) {
                    case OL : {
                        OList * orderedOList = newOList( &fcfs, &viewTask, &viewTask, &freeTask, &freeTask );
                        for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                            OListInsert( orderedOList, nodeActuel -> data, nodeActuel -> data );
                        freeList( * I, 0 );
                        * I = OListToList( orderedOList );
                    } break;
                    case BST : {
                        BSTree * resultBSTree = newBSTree( &fcfs, &viewTask, &viewTask, &freeTask, &freeTask );
                        for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                            BSTreeInsert( resultBSTree, nodeActuel -> data, nodeActuel -> data );
                        freeList( * I, 0 );
                        * I = BSTreeToList( resultBSTree );
                    } break;
                    case EBST : {
                        BSTree * resultEquilibreBSTree = newEBSTree( &fcfs, &viewTask, &viewTask, &freeTask, &freeTask );
                        for ( LNode * nodeActuel = ( * I ) -> head ; nodeActuel != NULL ; nodeActuel = nodeActuel -> succ )
                            EBSTreeInsert( resultEquilibreBSTree, nodeActuel -> data, nodeActuel -> data );
                        freeList( * I, 0 );
                        * I = BSTreeToList( resultEquilibreBSTree );
                    } break;
                    default : {
                        error("reorderInstance() : la structure de donnée utilisée dans les tris des tâches est différente de OL - BST - EBST\n");
                    }
                }
            } break;
            default : {
                error("reorderInstance() : l'ordre de trie est différent de SPT - LPT - WSPT - FCFS\n");
            }

        }
    }
}
