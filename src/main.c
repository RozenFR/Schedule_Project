#include "olist.h"
#include "list.h"
#include "bstree.h"
#include "utilities.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "instance.h"
#include <string.h>
//#include "schedule.h"
/**
⢕⢕⢕⢑⠁⢁⣼⣿⣻⢿⣟⢿⡻⡙⡏⡏⣟⡽⡹⣹⢪⡻⢽⡫⠯⣻⢛⢿⣻⣿⣿⡿⣧⢍⠝⡍⡏⡎⡕⢵
⢕⢕⠸⡐⣠⣿⣗⢯⡺⡽⡸⡅⠕⢕⢐⠑⢕⠸⢙⢕⢱⢸⠸⢜⠴⡈⡜⡔⢅⢟⢞⣿⣿⣧⠨⡊⣜⢜⢜⡵
⢕⢌⢂⢀⣿⡷⡧⣯⡣⡹⡎⠪⣈⡂⣦⣁⣱⡱⣱⣡⢑⣘⡨⢮⢝⢞⣎⣖⣵⢳⣸⣯⣿⣿⣇⢣⢪⡪⣣⣻
⢕⢐⠄⣸⣿⣿⡝⣮⡪⡪⣊⢎⡔⣗⢳⢪⢻⠾⡻⡿⡻⣗⢾⢗⡿⢿⢻⡻⡾⣟⣶⣯⣿⣿⡇⡎⢆⢇⢇⢿
⢕⠐⠄⣿⣿⣿⡽⢜⡲⣇⣷⡛⢗⢙⠹⠘⠔⠑⠉⠘⠜⠑⠔⠑⢘⠈⠂⠊⠘⠈⠈⠘⠹⢿⡧⡣⡣⡣⡳⡽
⢅⠅⠄⣿⣿⣿⢝⢷⣻⡻⠁⠄⠄⠄⠄⢀⠄⠄⠄⠄⠂⠬⡀⡄⠄⠄⠄⡀⠄⠄⠄⠄⠁⠂⢻⣕⢧⢳⢕⣿
⠅⠂⠄⢻⣿⣯⠧⢟⣿⣔⠄⠁⡀⡀⠄⠄⠄⣀⠄⠄⡀⠩⠳⠵⠁⠄⡀⠄⢰⣁⠄⠠⠄⠄⠈⢿⣪⡺⡜⣾
⢵⣷⠶⣼⠏⣿⠹⡙⠄⠁⠄⠖⠂⠄⡀⠄⠄⠹⣾⠄⠄⢔⣻⣿⡳⠄⠄⠄⠈⡷⠠⠄⠄⠄⠄⣼⡟⠵⡭⣻
⡪⡂⡕⡄⢠⣿⣏⢌⢠⠰⡌⡢⠄⠄⠅⠠⠄⠐⠄⠄⡔⣵⢾⣟⣯⢧⢂⢠⢀⠄⠄⠄⣀⢤⢾⢦⣿⣇⢗⣿
⠜⣔⠄⠈⢘⣿⣯⡖⠔⠑⢜⢐⠁⢂⠄⠢⢐⠐⢀⢕⢝⡚⡟⠿⡿⣿⣪⡢⠳⣭⣊⢆⠣⠣⠣⠓⡯⢷⡣⣿
⠝⣾⠄⠄⢸⣹⣷⣆⢀⢑⢐⠰⢈⢐⠨⠨⠠⠐⡎⠫⠑⢌⠌⡈⡈⠪⠚⠷⠈⠰⢕⢟⢎⢎⠂⠌⣾⣿⢸⣺
⢅⠱⢷⢄⡀⢽⣿⣟⡀⠑⡐⢅⢃⠢⠑⠅⢅⢢⠈⠄⠄⠄⠁⠐⠈⢀⢀⢬⢤⢠⢌⠪⠲⢈⠸⡠⣿⢾⠱⣽
⡅⠄⠳⣝⠄⢸⣿⣻⡜⠆⠌⣐⡂⢅⠅⡍⡆⢧⢑⢦⠕⠔⠤⠤⠤⠳⢯⣯⢿⢵⠥⡧⣑⢄⠃⣆⣿⠃⢑⢵
⢆⠕⡠⡉⠃⠸⣿⣿⡸⠰⢁⢐⠄⡥⡪⠢⡸⡸⢊⠁⠄⠡⠡⠨⠐⠄⠈⠈⠫⡇⠟⣜⣖⡔⠥⣢⣻⠄⠄⡸
⡣⡣⡱⡨⠢⡀⢹⡗⡳⡉⢐⠄⠕⡽⢐⠁⠄⠅⠐⠈⠄⠄⠄⢀⢀⣀⣀⣀⠄⠁⠄⠨⣾⣗⡘⣆⣿⠄⠐⡌
⡪⡪⡢⡣⡃⢆⠸⣿⡢⡸⠂⡘⡩⠼⡄⢄⠰⡐⢔⠑⢍⢚⢙⢊⠣⠓⠝⢚⢹⢕⢕⢡⠺⡒⠕⠅⡾⣤⣐⢜
⡕⢕⢸⢨⢊⠆⡂⡹⣯⣪⡀⡄⢜⡽⡀⢢⠊⡊⡢⢑⢀⠄⡀⠄⠄⡀⠄⡊⠮⡪⡊⢆⢆⠯⢨⢢⠁⠄⣿⣽
⢎⢕⢕⢅⢇⣣⡱⠒⢿⡜⣖⡂⢚⡺⣎⢐⠄⡊⡐⠰⡀⡅⣀⡢⣐⢔⡰⡨⡘⡄⡣⡡⣏⡓⠇⠁⠄⠄⣍⣿
⡣⡱⡡⡣⣳⠞⠄⠄⠸⣿⣝⢮⣶⢪⡗⡄⠠⢂⠌⠆⡅⠇⠇⡓⡘⡘⡪⣚⠪⡪⡘⡜⡂⢪⡃⠄⠄⢀⣽⢿
⡕⢕⢕⢽⠁⠄⠄⠄⠄⡑⠌⠹⢹⢹⢭⢻⡅⡆⡈⡠⠠⠁⡂⠄⠄⠠⢀⠂⠅⡃⠅⠁⡄⡣⡂⠄⢠⢙⢄⢾
⡕⡕⢵⠃⠄⢀⠄⠡⠄⢈⢂⢀⠄⠁⠌⠈⠪⠒⠢⠐⡐⠡⠐⠠⠡⠈⠄⠌⠄⠄⢀⠌⡀⠊⢐⡴⠩⡓⠔⢝
⢎⢪⢸⠄⠄⠘⠐⠄⠄⠄⠐⡀⠌⡀⠄⢂⠠⠄⠄⠁⠄⠁⠄⠄⠄⠄⠄⠄⠄⠄⡀⠄⡠⠔⠁⠐⠐⡭⡨⡘
⢕⠅⢝⣕⠄⠄⠄⠄⠄⠄⠄⠐⠄⠄⠄⠠⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡀⠅⠐⠁⠄⠄⠈⢀⠁⡒⡊⠌
⡕⣌⣄⣿⣾⣄⠄⠄⠄⠄⠄⠄⠂⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⠄⠄⠈⠄⠄⠄⠄⠄⠄⠈⠄⠄⠄⢂⠠⠠
 */


void testListesDoublementChaineesNonOrdonnees();
void testListesDoublementChaineesOrdonnees();
void testArbres( void );
void testInstances( void );

int main( void ) {

    int choix = 1;

    printf("-Choix 1 : Listes Non Ordonnées\n-Choix 2 : Listes Ordonnées\n-Choix 3 : Arbres Binaires de Recherche\n-Choix 4 : Instances\n");
    scanf("%d", &choix );

    switch ( choix ) {
        case 1 : {
            testListesDoublementChaineesNonOrdonnees();
        } break;
        case 2 : {
            testListesDoublementChaineesOrdonnees();
        } break;
        case 3 : {
            testArbres();
        } break;
        case 4 : {
            testInstances();
        } break;
        default : {
            printf("Choix invalide...\n" );
            exit( EXIT_FAILURE );
        }
    }
    return EXIT_SUCCESS;
}

void testInstances( void ) {
    void ( * ptrViewTask )( const void * i );
    void ( * ptrFreeTask )( void * );

    ptrViewTask = &viewTask;
    ptrFreeTask = &freeTask;

    Instance  I1;
    int choix = 0;

    printf("-Choix 1 : test readInstace()\n-Choix 2 : test reorderInstance()\n" );
    scanf("%d",&choix );

    switch ( choix ) {
        case 1 : {
            I1 = readInstance( "./data/exemple" );
            viewInstance( I1 );
            freeInstance( I1, 1 );

        } break;
        case 2 : {
            I1 = readInstance( "./data/exemple" );
            char readBuffer[6];

            do {

                printf("Saisissez l'ordre suivant lequel trier les tâches parmi : SPT, LPT, WSPT, FCFS\n");
                scanf("%s", readBuffer );

            } while ( strcmp( readBuffer, "SPT" ) != 0 && strcmp( readBuffer, "LPT" ) != 0 && strcmp( readBuffer, "WSPT" ) != 0 &&
                      strcmp( readBuffer, "FCFS" ) != 0 );

            if ( strcmp( readBuffer, "SPT" ) == 0 ) {

                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure OL\n", readBuffer);
                reorderInstance( &I1, OL, SPT);
                viewInstance( I1 );

                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure BST\n", readBuffer);
                reorderInstance( &I1, BST, SPT);
                viewInstance( I1 );

                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure EBST\n", readBuffer);
                reorderInstance( &I1, EBST, SPT);
                viewInstance( I1 );

            } else if ( strcmp( readBuffer, "LPT") == 0 ) {


                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure OL\n", readBuffer);
                reorderInstance( &I1, OL, LPT);
                viewInstance( I1);


                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure BST\n", readBuffer);
                reorderInstance( &I1, BST, LPT);
                viewInstance( I1 );


                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure EBST\n", readBuffer);
                reorderInstance( &I1, EBST, LPT);
                viewInstance( I1 );

            } else if ( strcmp( readBuffer, "WSPT") == 0 ) {

                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure OL\n", readBuffer);
                reorderInstance( &I1, OL, WSPT);
                viewInstance( I1 );


                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure BST\n", readBuffer);
                reorderInstance( &I1, BST, WSPT);
                viewInstance( I1 );


                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure EBST\n", readBuffer);
                reorderInstance( &I1, EBST, WSPT);
                viewInstance( I1 );

            } else if ( strcmp( readBuffer, "FCFS") == 0 ) {

                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure OL\n", readBuffer);
                reorderInstance( &I1, OL, FCFS);
                viewInstance( I1 );


                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure BST\n", readBuffer);
                reorderInstance( &I1, BST, FCFS);
                viewInstance( I1 );


                printf("Les tâches ont été ordonnées suivant l'ordre %s en utilisant la structure EBST\n", readBuffer);
                reorderInstance( &I1, EBST, FCFS);
                viewInstance( I1 );

            } else {

                freeInstance( I1, 1 );
                I1 = NULL;
                error("testInstance() : un problème inattendu est apparu, l'utilisateur a réussi à contourner la saisie contrôlée et une chaîne de caractère autre que \"SPT\" \"LPT\" \"WSPT\" \"FCFS\" à été introduite");

            }

            freeInstance( I1, 1 );
        } break;
        default : {
            printf( "Choix invalide...\n" );
        }
    }
}

void testArbres( void )
{
    void ( * ptrViewInt )( const void * i );
    int ( * ptrCmp )( const void * a, const void * b );
    void ( * ptrFreeInt )( void * i );
    ptrViewInt = &viewInt;
    ptrFreeInt = &freeInt;
    ptrCmp = &compareInt;
    BSTree * T = newEBSTree( compareInt, ptrViewInt, ptrViewInt, ptrFreeInt, ptrFreeInt );
    int choix = 0;
    printf("-Choix 1 : test BSTreeInsert()\n-Choix 2 : test EBSTreeInsert()\n-Choix 3 : test findPredecessor() & findSuccessor()\n" );
    scanf("%d", &choix );
    int * x;
    switch ( choix ) {
        case 1 : {
            printf("Test de la fonction : BSTreeInsert()\n\n" );
            for( int i = 0; i < 10; i++ ) {
                x = ( int * ) calloc(1, sizeof( int ) );
                printf("Saisissez le noeud N°%d à insérer : ", i+1 );
                scanf("%d", x );
                BSTreeInsert( T, x, x );
            }
            printf("Voici l'affichage infixé de l'arbre :\n");
            viewBSTree( T );
            if( isBSTree( T->root, ptrCmp ) ) {
                printf("\nL'arbre crée est un arbre binaire de recherche\n" );
            } else {
                printf("\nL'arbre généré n'est pas un arbre binaire de recherche\n" );

            }
            freeBSTree( T,1,0 );
        } break;
        case 2 : {
            printf("Test de la fonction : EBSTreeInsert()\n\n" );
            for ( int i = 0; i < 10; i++ ) {
                x = ( int * ) calloc (1, sizeof( int ) );
                printf("Saisissez le noeud N°%d à insérer : ", i + 1 );
                scanf("%d", x );
                EBSTreeInsert( T, x, x );
            }
            printf("Voici l'affichage infixé de l'arbre :\n");
            viewBSTree( T );
            printf("\n");
            printf("\n");
            printf("Root : %d\n",* ( ( int * ) T->root->key ) );
            printf("Bfactor du Root : %d\n", T->root->bfactor );
            printf("\n");
            printf("Fils Gauche : %d\n", * ( ( int * ) T->root->left->key ) );
            printf("Bfactor du Fils Gauche : %d\n", T->root->left->bfactor );
            printf("\n");
            printf("Fils Droit : %d\n", * ( ( int * ) T->root->right->key ) );
            printf("Bfactor du Fils Droit : %d\n", T->root->right->bfactor );
            if( isBalanced( T->root, ptrCmp ) ) {
                printf("\nL'arbre est équilibré\n");
            } else {
                printf("\nL'arbre généré n'est pas un arbre équilibré");
            }
            freeBSTree( T,1,0 );
        } break;
        case 3 : {
            printf("Test de la fonction : findPredecessor()\n\n");
            for ( int i = 0; i < 10; i++ ) {
                x = ( int * ) calloc (1, sizeof( int ) );
                printf("Saisissez le noeud N°%d à insérer : ", i+1 );
                scanf("%d", x );
                EBSTreeInsert( T, x, x );
            }
            printf("Voici l'affichage infixé de l'arbre :\n");
            viewBSTree( T );
            printf("\n");
            printf("\n");
            printf("Root : %d\n",* ( ( int * ) T->root->key ) );
            printf("Bfactor du Root : %d\n", T->root->bfactor );
            printf("\n");
            printf("Fils Gauche : %d\n", * ( ( int * ) T->root->left->key ) );
            printf("Bfactor du Fils Gauche : %d\n", T->root->left->bfactor );
            printf("\n");
            printf("Fils Droit : %d\n", * ( ( int * ) T->root->right->key ) );
            printf("Bfactor du Fils Droit : %d\n", T->root->right->bfactor );
            BSTNode * node1 = findPredecessor( T, T->root );
            BSTNode * node2 = findSuccessor( T, T->root );
            printf("Le prédecesseur de %d est %d\n", * ( ( int * ) T->root->right->key ), * ( ( int * ) node1->key ) );
            printf("Le successeur de %d est %d\n", * ( ( int * ) T->root->right->key ), * ( ( int * ) node2->key ) );
            freeBSTree( T,1,0 );
        } break;
        default : {
            freeBSTree( T,0,0 );
        } break;
    }
}

void testListesDoublementChaineesNonOrdonnees(){
    void ( * ptrViewInt )( const void * i );
    int ( * ptrCmp )( const void * a, const void * b );
    void ( * ptrFreeInt )( void * i );
    ptrViewInt = &viewInt;
    ptrFreeInt = &freeInt;
    ptrCmp = &compareInt;
    List * L= newList( ptrViewInt, ptrFreeInt );
    int choix = 0;
    printf("-Choix 1 : test listInsertFirst()\n-Choix 2 : test listInsertLast()\n-Choix 3 : test listRemoveFirst()\n-Choix 4 : test listRemoveLast()\n-Choix 5 : test listInsertAfter()\n-Choix 6 : test listRemoveNode()\n");
    scanf("%d", &choix );
    int * x;
    switch ( choix ) {
        case 1 : {
            printf("Test de la fonction : listInsertFirst()\n\n");
            srand(time(NULL));
            for( int i = 0; i<10; i++ ) {
                x = ( int * ) calloc (1, sizeof( int ) );
                * x = rand() % 51;
                listInsertFirst( L, x );
            }
            viewList( L );
            freeList( L,1 );
        } break;
        case 2 : {
            printf("Test de la fonction : listInsertLast()\n\n");
            srand(time(NULL));
            for( int i = 0; i<10; i++ ) {
                x = ( int * ) calloc (1, sizeof( int ) );
                * x = rand() % 51;
                listInsertLast( L, x );
            }
            viewList( L );
            freeList( L,1 );
        } break;
        case 3 : {
            printf("Test de la fonction : listRemoveFirst()\n\n");
            srand(time(NULL));
            for( int i = 0; i<10; i++ ) {
                x = ( int * ) calloc (1, sizeof( int ) );
                * x = rand() % 51;
                listInsertFirst( L, x );
            }
            viewList( L );
            printf("Génération d'une liste de 10 éléments\nOn va maintenant pop les \"Node\" une par une et les libérer à la main par la gauche\n");
            LNode * aEffacer;
            for( int i = 0; i<10; i++ ) {
                aEffacer = listRemoveFirst( L );
                printf("Le \"Node\" qui sera pop : ");
                L->viewData( aEffacer->data );
                printf("\n");
                L->freeData( aEffacer->data );
                free( aEffacer );
                viewList( L );
            }
            free( L );
        } break;
        case 4 : {
            printf("Test de la fonction : listRemoveLast()\n\n");
            srand(time(NULL));
            for( int i = 0; i<10; i++ ) {
                x = ( int * ) calloc (1, sizeof( int ) );
                * x = rand() % 51;
                listInsertLast( L, x );
            }
            viewList( L );
            printf("Génération d'une liste de 10 éléments\nOn va maintenant pop les \"Node\" une par une et les libérer à la main par la droite\n");
            LNode * aEffacer;
            for( int i = 0; i<10; i++ ) {
                aEffacer = listRemoveLast( L );
                printf("Le \"Node\" qui sera pop : ");
                L->viewData( aEffacer->data );
                printf("\n");
                L->freeData( aEffacer->data );
                free( aEffacer );
                viewList( L );
            }
            free( L );
        } break;
        case 5 : {
            printf("Test de la fonction : listInsertAfter()\n\n");
            srand(time(NULL));
            for(int i = 0; i<10; i++){
                x = (int*) calloc(1, sizeof(int));
                *x = rand()%51;
                listInsertFirst(L,x);
            }
            printf("La liste générée :\n");
            viewList(L);
            printf("\n\n");


            x = (int*) calloc(1, sizeof(int));
            *x = -10;
            printf("Le \"Node\" -10 sera rajouté APRES la TETE de la liste :\n");
            listInsertAfter(L,x,L->head);
            viewList(L);
            printf("\n\n");


            x = (int*) calloc(1, sizeof(int));
            *x = -10;
            printf("Le \"Node\" -10 sera rajouté APRES la QUEUE de la liste :\n");
            listInsertAfter(L,x,L->tail);
            viewList(L);
            printf("\n\n");


            x = (int*) calloc(1, sizeof(int));
            *x = -10;
            printf("Le \"Node\" -10 sera rajouté APRES le 4e élément de la liste :\n");
            listInsertAfter(L,x,L->head->succ->succ->succ);
            viewList(L);


            freeList(L,1);
        }break;
        case 6 : {
            printf("Test de la fonction : listRemoveNode()\n\n");
            srand(time(NULL));
            int idRemove = rand()%10 + 1;
            printf("Le %dème \"Node\" sera enlèvé de la liste :\n",idRemove);
            for(int i = 0; i<10; i++){
                x = (int*) calloc(1, sizeof(int ));
                *x = rand()%51;
                listInsertFirst(L,x);
            }
            viewList(L);
            printf("\n\n");
            int i = 1;
            LNode *nodePosition = L->head;
            while(i < idRemove){
                nodePosition = nodePosition->succ;
                i++;
            }
            listRemoveNode(L,nodePosition);
            printf("Le \"Node\" qui sera pop : ");
            (L->viewData)(nodePosition->data);
            printf("\n");
            (L->freeData)(nodePosition->data);
            free(nodePosition);
            viewList(L);
            freeList(L,1);
        }break;
        default : {
            freeList(L,0);
        }break;
    }
}

void testListesDoublementChaineesOrdonnees(){
    void (*ptrViewInt)(const void* i);
    int (*ptrCmp)(const void* a, const void* b);
    void (*ptrFreeInt)(void* i);
    ptrViewInt = &viewInt;
    ptrFreeInt = &freeInt;
    ptrCmp = &compareInt;
    OList * L = newOList(ptrCmp,ptrViewInt,ptrViewInt,ptrFreeInt,ptrFreeInt);
    List * M = newList(ptrViewInt,ptrFreeInt);
    int choix=0;
    printf("Choix 1 : test OListInsert()\nChoix 2 : test OListToList()\n");
    scanf("%d",&choix);
    int *key, *data;
    switch (choix) {
        case 1 : {
            printf("Test de la fonction : OListInsert()\n");
            for(int i = 0; i<10; i++){
                printf("Saississez un entier pour la key N°%d\n", i + 1 );
                key = (int*) calloc (1, sizeof(int));
                scanf("%d",key);
                printf("Saississez un entier pour la data N°%d\n", i + 1 );
                data = (int*) calloc (1, sizeof(int));
                scanf("%d",data);
                listInsertLast(M,key);
                OListInsert(L,key,data);
            }
            printf("Les 10 \"key\" étaient générées dans cet ordre :\n");
            viewList(M);
            printf("Voici une liste triée suivant les 10 \"key\" :\n");
            viewOList(L);
            freeOList(L,1,1);
            freeList(M,0);
        }break;
        case 2 : {
            printf("Test de la fonction : OListToList() : \n");
            for(int i = 0; i<10; i++){
                printf("Saississez un entier pour la key N°%d\n", i + 1 );
                key = (int*) calloc (1, sizeof(int));
                scanf("%d",key);
                printf("Saississez un entier pour la data N°%d\n", i + 1 );
                data = (int*) calloc (1, sizeof(int));
                scanf("%d",data);
                listInsertLast(M,key);
                OListInsert(L,key,data);
            }
            printf("On crée une liste ordonnée de 10 \"Node\" et nous allons la transformer en une liste doublement chainnée normale");
            viewOList(L);
            List * N = OListToList(L);
            printf("Voici la liste renvoyée par OListToList() :\n");
            viewList(N);
            freeOList(L,1,1);
            freeList(N,0);
            freeList(M,0);
        }break;
        default : {
            freeOList(L,0,0);
            freeList(M,0);
        }break;
    }
}