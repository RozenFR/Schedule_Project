#include <stdlib.h>
#include <stdio.h>
#include "../include/utilities.h"
#include "../include/list.h"
#include "../include/olist.h"
#include "../include/bstree.h"
#include "../include/instance.h"
#include "../include/schedule.h"


Schedule * newSchedule( DataStructure structtype, int backfilling ) {
    Schedule * sched = (Schedule *) calloc( 1, sizeof( Schedule ) );

    sched -> structtype = structtype;
    sched -> backfilling = backfilling;

    switch ( structtype ) {
        case OL:
            sched -> scheduledTasks = newOList( compareInt, viewInt, viewTask, freeInt, freeTask );
            break;
        case BST:
            sched -> scheduledTasks = newBSTree( compareInt, viewInt, viewTask, freeInt, freeTask );
            break;
        case EBST:
            sched -> scheduledTasks = newEBSTree( compareInt, viewInt, viewTask, freeInt, freeTask );
            break;
        default:
            error( "Schedule:newSchedule : invalid data structure." );
            break;
    }

    return sched;
}

void viewSchedule( Schedule * sched ) {
    switch ( sched -> structtype ) {
        case OL:
            viewOList( sched -> scheduledTasks );
            break;
        case BST:
            viewBSTree( sched -> scheduledTasks );
            break;
        case EBST:
            viewBSTree( sched -> scheduledTasks );
            break;
        default:
            error( "Schedule:viewSchedule : invalid data structure." );
            break;
    }
}

void freeSchedule( Schedule * sched) {
    switch ( sched -> structtype ) {
        case OL:
            freeOList( sched -> scheduledTasks, 1, 0 );
            break;
        case BST:
            freeBSTree( sched -> scheduledTasks, 1, 0 );
            break;
        case EBST:
            freeBSTree( sched -> scheduledTasks, 1, 0 );
            break;
        default:
            error( "Schedule:freeSchedule : invalid data structure." );
            break;
    }
    free( sched );
}

void addTaskToSchedule( Schedule * sched, int startingTime, Task * task ) {
    int * stime = malloc( sizeof( int ) );
    *stime = startingTime;
    switch ( sched -> structtype ) {
        case OL:
            OListInsert( sched -> scheduledTasks, stime, task );
            break;
        case BST:
            BSTreeInsert( sched -> scheduledTasks, stime, task );
            break;
        case EBST:
            EBSTreeInsert( sched -> scheduledTasks, stime, task );
            break;
        default:
            error( "Schedule:addTaskToSchedule : invalid data structure." );
            break;
    }
}

/*****************************************************************************
 * Compute schedule
 *****************************************************************************/

/** FAIT
 * @brief
 * Vérifier si on peut faire du backfilling avec la tâche task dans l'ordonnancement
 * représenté par la liste ordonnée scheduledTasks.
 * Si le backfilling est possible, renvoie la date de début la plus petite.
 * Sinon (on ne peut pas faire du backfilling), renvoie -1.
 * NB : fonction itérative.
 */
static int OLFindBackfillingPosition( const OList * scheduledTasks, const Task * task ) {
    if ( scheduledTasks -> head == NULL ) {
        return -1;
    } else {
        int debutTacheAInserer = task->releaseTime;
        int debutDeLaTachePrecedente = 0;
        int processingTimeTachePrecedente = 0;
        for ( OLNode * actuel = scheduledTasks->head; actuel != NULL; actuel = actuel->succ ) {
            debutTacheAInserer = intmax( debutDeLaTachePrecedente + processingTimeTachePrecedente, debutTacheAInserer );
            if ( debutTacheAInserer + task->processingTime <= *(int *)actuel->key ) {
                return debutTacheAInserer;
            }
            debutDeLaTachePrecedente = *(int *)actuel->key;
            processingTimeTachePrecedente = ((Task *)actuel->data)->processingTime;
        }
        return -1;
    }

}

/** FAIT
 * @brief
 * Trouver la date de début de la tâche task si on l'ajoute
 * dans la structure scheduledTasks de type liste ordonnée.
 * La date de début dépend de l'application du backfilling (backfilling=1) ou pas (backfilling=0).
 * NB : La fonction n'ajoute pas la tâche dans l'ordonnancement !
 */
static int OLFindStartingTime( const OList * scheduledTasks, const Task * task, int backfilling ) {
    if ( scheduledTasks -> head == NULL ) {
        return task -> releaseTime;
    } else if ( ! backfilling ) {
        return intmax( *(int *)(scheduledTasks->tail->key) + ((Task *)scheduledTasks->tail->data)->processingTime, task->releaseTime );
    } else {
        int backfillingStartingTime = OLFindBackfillingPosition( scheduledTasks, task );
        if ( backfillingStartingTime == -1 ) {
            return intmax( *(int *)(scheduledTasks->tail->key) + ((Task *)scheduledTasks->tail->data)->processingTime, task->releaseTime );
        } else {
            return backfillingStartingTime;
        }
    }
}

/** FAIT
 * @brief
 * Vérifier si on peut faire du backfilling avec la tâche task dans l'ordonnancement
 * représenté par le sous-arbre raciné à curr de l'arbre binaire de recherche scheduledTasks.
 * Si le backfilling est possible, renvoie la date de début la plus petite.
 * Sinon (on ne peut pas faire du backfilling), renvoie -1.
 * NB : fonction récursive, l'ordre infixe est conseillé.
 */
static int BSTFindBackfillingPosition( const BSTree * scheduledTasks, const BSTNode * curr, const Task * task ) {
    if ( scheduledTasks->root == NULL || curr == NULL ) {
        return -1;
    } else {
        BSTNode * currPredecessor = findPredecessor( scheduledTasks, curr );
        int debutTacheAInserer = task->releaseTime;
        int debutTachePrecedente = *(int *)currPredecessor->key;
        int processingTimeTachePrecedente = ((Task *)currPredecessor->data)->processingTime;
        if ( curr == currPredecessor ) {
            debutTachePrecedente = 0;
            processingTimeTachePrecedente = 0;
        }
        debutTacheAInserer = intmax( debutTachePrecedente + processingTimeTachePrecedente, debutTacheAInserer );
        if ( debutTacheAInserer + task->processingTime <= *(int *)curr->key ) {
            return debutTacheAInserer;
        } else {
            BSTNode * currSucessor = findSuccessor( scheduledTasks, curr );
            return BSTFindBackfillingPosition( scheduledTasks, curr == currSucessor ? NULL : currSucessor, task );
        }

    }
}

/** FAIT
 * @brief
 * Trouver la date de début de la tâche task si on l'ajoute
 * dans la structure scheduledTasks de type arbre binaire de recherche.
 * La date de début dépend de l'application du backfilling (backfilling=1) ou pas (backfilling=0).
 * NB : La fonction n'ajoute pas la tâche dans l'ordonnancement !
 *      Utiliser la fonction récursive findBackfillingPosition.
 */
static int BSTFindStartingTime( const BSTree * scheduledTasks, const Task * task, int backfilling ) {
    if ( scheduledTasks->root == NULL ) {
        return task->releaseTime;
    } else {
        if ( ! backfilling ) {
            BSTNode * maxNode = BSTMax( scheduledTasks->root );
            return intmax( *(int *)maxNode->key + ((Task *)maxNode->data)->processingTime, task->releaseTime );
        } else {
            int resultatFindBackfilling = BSTFindBackfillingPosition( scheduledTasks, BSTMin( scheduledTasks->root ), task );
            if ( resultatFindBackfilling != -1 ) {
                return resultatFindBackfilling;
            } else {
                BSTNode * maxNode = BSTMax( scheduledTasks->root );
                return intmax( *(int *)maxNode->key + ((Task *)maxNode->data)->processingTime, task->releaseTime );
            }
        }
    }
}

int findStartingTime( const Schedule * sched, const Task * task ) {
    switch ( sched -> structtype ) {
        case OL:
            return OLFindStartingTime( sched -> scheduledTasks, task, sched -> backfilling );
        case BST:
            return BSTFindStartingTime( sched -> scheduledTasks, task, sched -> backfilling );
        case EBST:
            return BSTFindStartingTime( sched -> scheduledTasks, task, sched -> backfilling );
        default:
            error( "Schedule:findStartingTime : invalid data structure." );
            return -1;
    }
}

void computeSchedule( Schedule * sched, const Instance I ) {
    for ( LNode * curr = I -> head; curr; curr = curr -> succ ) {
        addTaskToSchedule( sched, findStartingTime( sched, curr -> data ), curr -> data );
    }
}

/*****************************************************************************
 * Save schedule
 *****************************************************************************/

/** FAIT
 * @brief
 * Sauvegarder l'ordonnancement représenté par la liste ordonnée scheduledTasks
 * dans le ficher indiqué par le descripteur fd.
 * NB : Procédure itérative
 */
static void OLSaveSchedule( const OList * scheduledTasks, FILE * fd ) {
    if ( fd != NULL ) {
        if ( scheduledTasks != NULL) {
            for ( OLNode * aAfficher = scheduledTasks -> head; aAfficher != NULL; aAfficher = aAfficher -> succ ) {
                fprintf( fd,"%s ", ((Task *)aAfficher->data)->id );
                fprintf( fd, "%d ", ((Task *)aAfficher->data)->processingTime );
                fprintf( fd, "%d ", ((Task *)aAfficher->data)->releaseTime );
                fprintf( fd, "%d ", ((Task *)aAfficher->data)->deadline );
                fprintf( fd, "%d ", ((Task *)aAfficher->data)->weight );
                fprintf( fd, "%d", *(int *)aAfficher->key );
                fprintf( fd, "\n" );
            }
        }
    }
}

/** FAIT
 * @brief
 * Sauvegarder l'ordonnancement représenté par le sous-arbre raciné au nœud curr
 * dans le ficher indiqué par le descripteur fd.
 * NB : procédure récursive
 *      Pensez à un parcours infixe.
 */
static void BSTSaveSchedule( const BSTNode * curr, FILE * fd ) {
    if ( fd != NULL ) {
        if ( curr != NULL ) {
            LNode * topOfStack = NULL;
            List * stack = newList( viewInt, NULL );
            while ( 1 ) {
                if ( curr != NULL ) {
                    listInsertFirst( stack, ( void * ) curr );
                    curr = curr -> left;
                } else {
                    if ( stack -> numelm == 0 ) {
                        break;
                    } else {
                        topOfStack = listRemoveFirst( stack );
                        curr = ( BSTNode * ) topOfStack -> data;
                        free( topOfStack );//Attention! listRemoveFirst() laisse des fuites de mémoire
                        fprintf( fd,"%s ", ((Task *)curr->data)->id );
                        fprintf( fd, "%d ", ((Task *)curr->data)->processingTime );
                        fprintf( fd, "%d ", ((Task *)curr->data)->releaseTime );
                        fprintf( fd, "%d ", ((Task *)curr->data)->deadline );
                        fprintf( fd, "%d ", ((Task *)curr->data)->weight );
                        fprintf( fd, "%d ", *(int *)curr->key );
                        fprintf( fd, "\n" );//quand le maillon qu'on a "pop" n'est pas utilisé par une autre liste
                        curr = curr -> right;
                    }
                }
            }
            freeList( stack, 0 );
        }
    }
}

void saveSchedule( const Schedule * sched, char * filename ) {
    FILE * fd;
    if ( ( fd = fopen( filename, "w" ) ) == NULL )
        error( "schedule:saveSchedule : Error while opening the file" );

    switch ( sched->structtype ) {
        case OL:
            OLSaveSchedule( sched->scheduledTasks, fd );
            break;
        case BST:
            BSTSaveSchedule( ( ( BSTree * ) sched->scheduledTasks )->root, fd );
            break;
        case EBST:
            BSTSaveSchedule( ( ( BSTree * ) sched->scheduledTasks )->root, fd );
            break;
        default:
            error( "Schedule:saveSchedule : invalid data structure." );
            break;
    }
    fclose( fd );
}

/*****************************************************************************
 * OBJECTIFS
 *****************************************************************************/

/////////////////////// makespan ///////////////////////

long Makespan( const Schedule * sched ) {
    switch(sched -> structtype) {
        case OL : {
            OList *L = sched->scheduledTasks;
            return *(int *)L->tail->key + ((Task *)L->tail->data)->processingTime;
        }
        case BST : {
            BSTree * T = sched->scheduledTasks;
            BSTNode * node = BSTMax(T -> root);
            return *(int *)node->key + ((Task* )node->data)->processingTime;
        }
        case EBST : {
            BSTree * T = sched->scheduledTasks;
            BSTNode * node = BSTMax(T -> root);
            return *(int *)node->key + ((Task* )node->data)->processingTime;
        }
        default :
            error("Schedule.c <makespan> : invalid data structure type.");
            return -1;
    }
}

/////////////////////// SumWjCj ///////////////////////

/** FAIT
 * @brief
 * Calculer la "somme pondérée de temps de fin" de l'ordonnancement
 * représenté par la liste ordonnée scheduledTasks.
 */
static long OLSumWjCj( const OList * scheduledTasks ) {
   long somme = 0;
   int cj, wj, temp;
   for(OLNode * actuel = scheduledTasks->head; actuel != NULL; actuel = actuel->succ){
       cj = *(int *)actuel->key + ((Task *)actuel->data)->processingTime;
       wj = ((Task *)actuel->data)->weight;
       temp = cj * wj;
       somme = temp + somme;
   }
    return somme;
}

/** FAIT
 * @brief
 * Calculer la "somme pondérée de temps de fin" de l'ordonnancement
 * représenté par l'arbre binaire de recherche raciné au nœud curr.
 * NB : fonction récursive
 */
static long BSTSumWjCj( const BSTNode * curr ) {
    if (curr == NULL)
        return 0;
    else {
        long sumWjCjLeft = BSTSumWjCj(curr->left);
        long sumWjCjRight = BSTSumWjCj(curr->right);
        return (*(int *) curr->key + ((Task *) curr->data)->processingTime) * ((Task *) curr->data)->weight +
               sumWjCjLeft + sumWjCjRight;
    }
}


long SumWjCj( const Schedule * sched ) {
    switch ( sched->structtype ) {
        case OL:
            return OLSumWjCj( sched->scheduledTasks );
        case BST:
            return BSTSumWjCj( ( ( BSTree * ) sched->scheduledTasks )->root );
        case EBST:
            return BSTSumWjCj( ( ( BSTree * ) sched->scheduledTasks )->root );
        default:
            error( "Schedule:SumWjCj : invalid data structure." );
            return -1;
    }
}

/////////////////////// SumWjFj ///////////////////////

/** FAIT
 * @brief
 * Calculer la "somme pondérée de temps de réponse" de l'ordonnancement
 * représenté par la liste ordonnée scheduledTasks.
 */
static long OLSumWjFj( const OList * scheduledTasks ) {
    int temp, cj, rj, weight;
    long sum = 0;
    for(OLNode * actuel = scheduledTasks->head; actuel != NULL; actuel = actuel->succ){
        cj = *((int *)actuel->key) +  ((Task *)actuel->data)->processingTime;
        rj = ((Task *)actuel->data)->releaseTime;
        temp =  cj-rj;
        weight = ((Task*)actuel->data)->weight;
        sum += temp * weight;

    }

    return sum;
}

/** FAIT
 * @brief
 * Calculer la "somme pondérée de temps de réponse" de l'ordonnancement
 * représenté par l'arbre binaire de recherche raciné au nœud curr.
 * NB : fonction récursive
 */
static long BSTSumWjFj( const BSTNode * curr ) {
    if (curr == NULL)
        return 0;
    else {
        long sumWjFjLeft = BSTSumWjFj( curr->left );
        long sumWjFjRight = BSTSumWjFj( curr->right );
        return ( *(int *)curr->key + ((Task *)curr->data)->processingTime
                 - ((Task *)curr->data)->releaseTime )
               * ((Task *)curr->data)->weight + sumWjFjLeft + sumWjFjRight;
    }
}

long SumWjFj( const Schedule * sched ) {
    switch ( sched->structtype ) {
        case OL:
            return OLSumWjFj( sched->scheduledTasks );
        case BST:
            return BSTSumWjFj( ( ( BSTree * ) sched->scheduledTasks )->root );
        case EBST:
            return BSTSumWjFj( ( ( BSTree * ) sched->scheduledTasks )->root );
        default:
            error( "Schedule:SumWjFj : invalid data structure." );
            return -1;
    }
}

/////////////////////// SumWjTj ///////////////////////

/** FAIT
 * @brief
 * Calculer la "somme pondérée de temps de retard" de l'ordonnancement
 * représenté par la liste ordonnée scheduledTasks.
 */
static long OLSumWjTj( const OList * scheduledTasks ) {
    long somme = 0;
    int cj, wj, dj, max, temp;
    for(OLNode * actuel = scheduledTasks->head; actuel != NULL; actuel = actuel->succ){
        cj = *(int *)actuel->key + ((Task *)actuel->data)->processingTime;
        wj = ((Task *)actuel->data)->weight;
        dj = ((Task *)actuel->data)->deadline;
        max = intmax(cj - dj, 0);
        temp = max * wj;
        somme += temp;
    }
    return somme;
}

/** FAIT
 * @brief
 * Calculer la "somme pondérée de temps de retard" de l'ordonnancement
 * représenté par l'arbre binaire de recherche raciné au nœud curr.
 * NB : fonction récursive
 */
static long BSTSumWjTj( const BSTNode * curr ) {
    if (curr == NULL)
        return 0;
    else {
        long sumWjTjLeft = BSTSumWjTj( curr->left );
        long sumWjTjRight = BSTSumWjTj( curr->right );
        return intmax( *(int *)curr->key + ((Task *)curr->data)->processingTime - ((Task *)curr->data)->deadline, 0 ) * ((Task *)curr->data)->weight + sumWjTjLeft + sumWjTjRight;
    }
}

long SumWjTj( const Schedule * sched ) {
    switch ( sched->structtype ) {
        case OL:
            return OLSumWjTj( sched->scheduledTasks );
        case BST:
            return BSTSumWjTj( ( ( BSTree * ) sched->scheduledTasks )->root );
        case EBST:
            return BSTSumWjTj( ( ( BSTree * ) sched->scheduledTasks )->root );
        default:
            error( "Schedule:SumWjTj : invalid data structure." );
            return -1;
    }
}