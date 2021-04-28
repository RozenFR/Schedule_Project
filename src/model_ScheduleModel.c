#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../include/utilities.h"
#include "../include/list.h"
#include "../include/olist.h"
#include "../include/bstree.h"
#include "../include/list.h"
#include "../include/instance.h"
#include "../include/schedule.h"
#include "../include/model_ScheduleModel.h"

JNIEXPORT void JNICALL Java_model_ScheduleModel_getSchedule
(JNIEnv * env, jobject obj, jstring s1, jstring s2, jint dt, jint ord, jint bf) {
    // Transformed String to char *
    const char * cs1 = (*env) -> GetStringUTFChars(env, s1, NULL);
    const char * cs2 = (*env) -> GetStringUTFChars(env, s2, NULL);
    char * csin = (char *) cs1;
    char * csout = (char *) cs2;

    // Read Input Stream
    Instance I = readInstance(csin);

    // Declare Schedule
    Schedule * sched;

    // Reorder Instance
    switch (dt) {
        case 0: // OL
            switch(ord) {
                case 0: // SPT
                    reorderInstance( &I, OL, SPT );
                    break;
                case 1: // LPT
                    reorderInstance( &I, OL, LPT );
                    break;
                case 2: // WSPT
                    reorderInstance( &I, OL, WSPT );
                    break;
                case 3: // FCFS
                    reorderInstance( &I, OL, FCFS );
                    break;
                default:
                    error( "Erreur <getSchedule()>: L'ordre doit être soit SPT, LPT, WSPT, FCFS. " );
                    break;
            }

            // New Schedule with Struct Type
            sched = newSchedule( OL, bf );
            break;
        case 1: // BST
            switch(ord) {
                case 0: // SPT
                    reorderInstance( &I, BST, SPT );
                    break;
                case 1: // LPT
                    reorderInstance( &I, BST, LPT );
                    break;
                case 2: // WSPT
                    reorderInstance( &I, BST, WSPT );
                    break;
                case 3: // FCFS
                    reorderInstance( &I, BST, FCFS );
                    break;
                default:
                    error( "Erreur <getSchedule()>: L'ordre doit être soit SPT, LPT, WSPT, FCFS. " );
                    break;
            }

            // New Schedule with Struct Type
            sched = newSchedule( BST, bf );
            break;
        case 2: // EBST
            switch(ord) {
                case 0: // SPT
                    reorderInstance( &I, EBST, SPT );
                    break;
                case 1: // LPT
                    reorderInstance( &I, EBST, LPT );
                    break;
                case 2: // WSPT
                    reorderInstance( &I, EBST, WSPT );
                    break;
                case 3: // FCFS
                    reorderInstance( &I, EBST, FCFS );
                    break;
                default:
                    error( "Erreur <getSchedule()>: L'ordre doit être soit SPT, LPT, WSPT, FCFS. " );
                    break;
            }

            // New Schedule with Struct Type
            sched = newSchedule( EBST, bf );
            break;
        default:
            error( "Erreur <getSchedule()>: La Structure doit être OL, BST ou EBST." );
            break;
    }

    // Compute Schedule
    computeSchedule(sched, &I);

    // Save Schedule
    saveSchedule(sched, csout);

    // Free
    freeList(I, 1);
    freeSchedule(sched);

}