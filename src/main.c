#include "../include/olist.h"
#include "../include/list.h"
#include "../include/bstree.h"
#include "../include/utilities.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../include/instance.h"
#include <string.h>
#include "../include/schedule.h"


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

/***********************************************
 * Declaration
 ***********************************************/
void testListesDoublementChaineesNonOrdonnees();

void testListesDoublementChaineesOrdonnees();

void testArbres();

void testInstances();

void testInstances500();
void testInstances1000();
void testInstances1500();
void testInstances2000();
void testInstances2500();
void testInstances3000();
void testInstances3500();
void testInstances4000();
void testInstances4500();
void testInstances5000();
void testInstances5500();
void testInstances6000();
void testInstances6500();
void testInstances7000();

/***********************************************
 * Main
 ***********************************************/

int main(void) {

    int choix = 1;

    printf("-Choix 1 : Listes Non Ordonnées\n"
           "-Choix 2 : Listes Ordonnées\n"
           "-Choix 3 : Arbres Binaires de Recherche\n"
           "-Choix 4 : Instances\n");
    scanf("%d", &choix );

    switch ( choix ) {
        case 1 : {
            testListesDoublementChaineesNonOrdonnees();
            break;
        }
        case 2 : {
            testListesDoublementChaineesOrdonnees();
            break;
        }
        case 3 : {
            testArbres();
            break;
        }
        case 4 : {
            testInstances();
            break;
        }
        default : {
            printf("Choix invalide...\n" );
            exit( EXIT_FAILURE );
        }
    }
}

/***********************************************
 * Fonctions
 ***********************************************/

// Test Liste
void testListesDoublementChaineesNonOrdonnees() {
    void ( *ptrViewInt )(const void *i);
    void ( *ptrFreeInt )(void *i);
    ptrViewInt = &viewInt;
    ptrFreeInt = &freeInt;
    List *L = newList(ptrViewInt, ptrFreeInt);
    int choix = 0;
    printf("-Choix 1 : test listInsertFirst()\n"
           "-Choix 2 : test listInsertLast()\n"
           "-Choix 3 : test listRemoveFirst()\n"
           "-Choix 4 : test listRemoveLast()\n"
           "-Choix 5 : test listInsertAfter()\n"
           "-Choix 6 : test listRemoveNode()\n");
    scanf("%d", &choix);
    int *x;
    switch (choix) {
        case 1 : {
            printf("Test de la fonction : listInsertFirst()\n\n");
            srand(time(NULL));
            for (int i = 0; i < 10; i++) {
                x = (int *) calloc(1, sizeof(int));
                *x = rand() % 51;
                listInsertFirst(L, x);
            }
            viewList(L);
            freeList(L, 1);
        }
            break;
        case 2 : {
            printf("Test de la fonction : listInsertLast()\n\n");
            srand(time(NULL));
            for (int i = 0; i < 10; i++) {
                x = (int *) calloc(1, sizeof(int));
                *x = rand() % 51;
                listInsertLast(L, x);
            }
            viewList(L);
            freeList(L, 1);
        }
            break;
        case 3 : {
            printf("Test de la fonction : listRemoveFirst()\n\n");
            srand(time(NULL));
            for (int i = 0; i < 10; i++) {
                x = (int *) calloc(1, sizeof(int));
                *x = rand() % 51;
                listInsertFirst(L, x);
            }
            viewList(L);
            printf("Génération d'une liste de 10 éléments\nOn va maintenant pop les \"Node\" une par une et les libérer à la main par la gauche\n");
            LNode *aEffacer;
            for (int i = 0; i < 10; i++) {
                aEffacer = listRemoveFirst(L);
                printf("Le \"Node\" qui sera pop : ");
                L->viewData(aEffacer->data);
                printf("\n");
                L->freeData(aEffacer->data);
                free(aEffacer);
            }
            free(L);

        }
            break;
        case 4 : {
            printf("Test de la fonction : listRemoveLast()\n\n");
            srand(time(NULL));
            for (int i = 0; i < 10; i++) {
                x = (int *) calloc(1, sizeof(int));
                *x = rand() % 51;
                listInsertLast(L, x);
            }
            viewList(L);
            printf("Génération d'une liste de 10 éléments\nOn va maintenant pop les \"Node\" une par une et les libérer à la main par la droite\n");
            LNode *aEffacer;
            for (int i = 0; i < 10; i++) {
                aEffacer = listRemoveLast(L);
                printf("Le \"Node\" qui sera pop : ");
                L->viewData(aEffacer->data);
                printf("\n");
                L->freeData(aEffacer->data);
                free(aEffacer);
            }
            free(L);

        }
            break;
        case 5 : {
            printf("Test de la fonction : listInsertAfter()\n\n");
            srand(time(NULL));
            for (int i = 0; i < 10; i++) {
                x = (int *) calloc(1, sizeof(int));
                *x = rand() % 51;
                listInsertFirst(L, x);
            }
            printf("La liste générée :\n");
            viewList(L);
            printf("\n\n");


            x = (int *) calloc(1, sizeof(int));
            *x = -10;
            printf("Le \"Node\" -10 sera rajouté APRES la TETE de la liste :\n");
            listInsertAfter(L, x, L->head);
            viewList(L);
            printf("\n\n");


            x = (int *) calloc(1, sizeof(int));
            *x = -10;
            printf("Le \"Node\" -10 sera rajouté APRES la QUEUE de la liste :\n");
            listInsertAfter(L, x, L->tail);
            viewList(L);
            printf("\n\n");


            x = (int *) calloc(1, sizeof(int));
            *x = -10;
            printf("Le \"Node\" -10 sera rajouté APRES le 4e élément de la liste :\n");
            listInsertAfter(L, x, L->head->succ->succ->succ);
            viewList(L);


            freeList(L, 1);

        }
            break;
        case 6 : {
            printf("Test de la fonction : listRemoveNode()\n\n");
            srand(time(NULL));
            int idRemove = rand() % 10 + 1;
            printf("Le %dème \"Node\" sera enlèvé de la liste :\n", idRemove);
            for (int i = 0; i < 10; i++) {
                x = (int *) calloc(1, sizeof(int));
                *x = rand() % 51;
                listInsertFirst(L, x);
            }
            viewList(L);
            printf("\n\n");
            int i = 1;
            LNode *nodePosition = L->head;
            while (i < idRemove) {
                nodePosition = nodePosition->succ;
                i++;
            }
            listRemoveNode(L, nodePosition);
            printf("Le \"Node\" qui sera pop : ");
            (L->viewData)(nodePosition->data);
            printf("\n");
            (L->freeData)(nodePosition->data);
            free(nodePosition);
            viewList(L);
            freeList(L, 1);

        }
            break;
        default : {
            freeList(L, 0);
        }
            break;
    }
}

void testListesDoublementChaineesOrdonnees() {
    void (*ptrViewInt)(const void *i);
    int (*ptrCmp)(const void *a, const void *b);
    void (*ptrFreeInt)(void *i);
    ptrViewInt = &viewInt;
    ptrFreeInt = &freeInt;
    ptrCmp = &compareInt;
    OList *L = newOList(ptrCmp, ptrViewInt, ptrViewInt, ptrFreeInt, ptrFreeInt);
    List *M = newList(ptrViewInt, ptrFreeInt);
    int choix = 0;
    printf("Choix 1 : test OListInsert()\nChoix 2 : test OListToList()\n");
    scanf("%d", &choix);
    int *key, *data;

    switch (choix) {
        case 1 : {
            printf("Test de la fonction : OListInsert()\n");
            for (int i = 0; i < 1000; i++) {
                printf("Saississez un entier pour la key N°%d\n", i + 1);
                key = (int *) calloc(1, sizeof(int));
                key = &i;
                scanf("%d", key);
                printf("Saississez un entier pour la data N°%d\n", i + 1);
                data = (int *) calloc(1, sizeof(int));
                scanf("%d", data);
                listInsertLast(M, key);
                OListInsert(L, key, data);
            }
            printf("Les 10 \"key\" étaient générées dans cet ordre :\n");
            viewList(M);
            printf("Voici une liste triée suivant les 10 \"key\" :\n");
            viewOList(L);
            freeOList(L, 1, 1);
            freeList(M, 0);


        }
            break;
        case 2 : {
            printf("Test de la fonction : OListToList() : \n");
            for (int i = 0; i < 10; i++) {
                printf("Saississez un entier pour la key N°%d\n", i + 1);
                key = (int *) calloc(1, sizeof(int));
                scanf("%d", key);
                printf("Saississez un entier pour la data N°%d\n", i + 1);
                data = (int *) calloc(1, sizeof(int));
                scanf("%d", data);
                listInsertLast(M, key);
                OListInsert(L, key, data);
            }
            printf("On crée une liste ordonnée de 10 \"Node\" et nous allons la transformer en une liste doublement chainnée normale");
            viewOList(L);
            List *N = OListToList(L);
            printf("Voici la liste renvoyée par OListToList() :\n");
            viewList(N);
            freeOList(L, 1, 1);
            freeList(N, 0);
            freeList(M, 0);
        }
            break;
        default : {
            freeOList(L, 0, 0);
            freeList(M, 0);
        }
            break;
    }
}

// TestInsert
void testInsertOL() {

}

void testInsertBST() {

}

void testInsertEBST() {

}

// Test Arbre
void testArbres() {
    void ( *ptrViewInt )(const void *i);
    int ( *ptrCmp )(const void *a, const void *b);
    void ( *ptrFreeInt )(void *i);
    ptrViewInt = &viewInt;
    ptrFreeInt = &freeInt;
    ptrCmp = &compareInt;
    BSTree *T = newEBSTree(compareInt, ptrViewInt, ptrViewInt, ptrFreeInt, ptrFreeInt);
    int choix = 0;
    printf("-Choix 1 : test BSTreeInsert()\n-Choix 2 : test EBSTreeInsert()\n-Choix 3 : test findPredecessor() & findSuccessor()\n");
    scanf("%d", &choix);
    int *x;
    switch (choix) {
        case 1 : {
            printf("Test de la fonction : BSTreeInsert()\n\n");
            for (int i = 0; i < 10; i++) {
                x = (int *) calloc(1, sizeof(int));
                printf("Saisissez le noeud N°%d à insérer : ", i + 1);
                scanf("%d", x);
                BSTreeInsert(T, x, x);
            }
            printf("Voici l'affichage infixé de l'arbre :\n");
            viewBSTree(T);
            if (isBSTree(T->root, ptrCmp)) {
                printf("\nL'arbre crée est un arbre binaire de recherche\n");
            } else {
                printf("\nL'arbre généré n'est pas un arbre binaire de recherche\n");

            }
            freeBSTree(T, 1, 0);
        }
            break;
        case 2 : {
            printf("Test de la fonction : EBSTreeInsert()\n\n");
            for (int i = 0; i < 10; i++) {
                x = (int *) calloc(1, sizeof(int));
                printf("Saisissez le noeud N°%d à insérer : ", i + 1);
                scanf("%d", x);
                EBSTreeInsert(T, x, x);
            }
            printf("Voici l'affichage infixé de l'arbre :\n");
            viewBSTree(T);
            printf("\n");
            printf("\n");
            printf("Root : %d\n", *((int *) T->root->key));
            printf("Bfactor du Root : %d\n", T->root->bfactor);
            printf("\n");
            printf("Fils Gauche : %d\n", *((int *) T->root->left->key));
            printf("Bfactor du Fils Gauche : %d\n", T->root->left->bfactor);
            printf("\n");
            printf("Fils Droit : %d\n", *((int *) T->root->right->key));
            printf("Bfactor du Fils Droit : %d\n", T->root->right->bfactor);
            if (isBalanced(T->root, ptrCmp)) {
                printf("\nL'arbre est équilibré\n");
            } else {
                printf("\nL'arbre généré n'est pas un arbre équilibré");
            }
            freeBSTree(T, 1, 0);
        }
            break;
        case 3 : {
            printf("Test de la fonction : findPredecessor()\n\n");
            for (int i = 1; i < 1000; i++) {
                x = (int *) calloc(1, sizeof(int));
                *x = i;
                EBSTreeInsert(T, x, x);
            }
            printf("Voici l'affichage infixé de l'arbre :\n");
            viewBSTree(T);
            printf("\n");
            printf("\n");
            printf("Root : %d\n", *((int *) T->root->key));
            printf("Bfactor du Root : %d\n", T->root->bfactor);
            printf("\n");
            printf("Fils Gauche : %d\n", *((int *) T->root->left->key));
            printf("Bfactor du Fils Gauche : %d\n", T->root->left->bfactor);
            printf("\n");
            printf("Fils Droit : %d\n", *((int *) T->root->right->key));
            printf("Bfactor du Fils Droit : %d\n", T->root->right->bfactor);
            BSTNode *node1 = findPredecessor(T, T->root);
            BSTNode *node2 = findSuccessor(T, T->root);
            printf("Le prédecesseur de %d est %d\n", *((int *) T->root->key), *((int *) node1->key));
            printf("Le successeur de %d est %d\n", *((int *) T->root->key), *((int *) node2->key));
            freeBSTree(T, 1, 0);
        }
            break;
        default : {
            freeBSTree(T, 0, 0);
        }
            break;
    }
}

// Test Instance
void testInstances() {

    int choice;
    printf("\n-Choix 1 : Instance 500\n"
           "-Choix 2 : Instance 1000\n"
           "-Choix 3 : Instance 1500\n"
           "-Choix 4 : Instance 2000\n"
           "-Choix 5 : Instance 2500\n"
           "-Choix 6 : Instance 3000\n"
           "-Choix 7 : Instance 3500\n"
           "-Choix 8 : Instance 4000\n"
           "-Choix 9 : Instance 4500\n"
           "-Choix 10 : Instance 5000\n"
           "-Choix 11 : Instance 5500\n"
           "-Choix 12 : Instance 6000\n"
           "-Choix 13 : Instance 6500\n"
           "-Choix 14 : Instance 7000\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            testInstances500();
            break;
        }
        case 2: {
            testInstances1000();
            break;
        }
        case 3: {
            testInstances1500();
            break;
        }
        case 4: {
            testInstances2000();
            break;
        }
        case 5: {
            testInstances2500();
            break;
        }
        case 6: {
            testInstances3000();
            break;
        }
        case 7: {
            testInstances3500();
            break;
        }
        case 8: {
            testInstances4000();
            break;
        }
        case 9: {
            testInstances4500();
            break;
        }
        case 10: {
            testInstances5000();
            break;
        }
        case 11: {
            testInstances5500();
            break;
        }
        case 12: {
            testInstances6000();
            break;
        }
        case 13: {
            testInstances6500();
            break;
        }
        case 14: {
            testInstances7000();
            break;
        }
        default:
            error("Invalid Selection.");

    }

}
void testInstances500() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_0500_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();

    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 500===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances1000() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_1000_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 1000===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances1500() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_1500_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 1500===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances2000() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_2000_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 2000===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances2500() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_2500_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 2500===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances3000() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_3000_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 3000===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances3500() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_3500_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 3500===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances4000() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_4000_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 4000===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances4500() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_4500_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 4500===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances5000() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_5000_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 5000===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances5500() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_5500_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 5500===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances6000() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_6000_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 6000===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances6500() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_6500_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 6500===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}
void testInstances7000() {
    clock_t beginRead = clock();
    Instance I = readInstance("./data/instance_7000_1");
    clock_t endRead = clock();

    clock_t beginView = clock();
    viewInstance(I);
    clock_t endView = clock();
    Schedule * sched;
    int choix = 0;
    printf("-Choix 1 : OL-SPT-BF\n"
           "-Choix 2 : OL-SPT-NBF\n"
           "-Choix 3 : OL-LPT-BF\n"
           "-Choix 4 : OL-LPT-NBF\n"
           "-Choix 5 : OL-WSPT-BF\n"
           "-Choix 6 : OL-WSPT-BF\n"
           "-Choix 7 : OL-FCFS-BF\n"
           "-Choix 8 : OL-FCFS-NBF\n"
           "-Choix 9 : BST-SPT-BF\n"
           "-Choix 10 : BST-SPT-NBF\n"
           "-Choix 11 : BST-LPT-BF\n"
           "-Choix 12 : BST-LPT-NBF\n"
           "-Choix 13 : BST- WSPT-BF\n"
           "-Choix 14 : BST- WSPT-NBF\n"
           "-Choix 15 : BST- FCFS-BF\n"
           "-Choix 16 : BST- FCFS-NBF\n"
           "-Choix 17 : EBST-SPT-BF\n"
           "-Choix 18 : EBST-SPT-NBF\n"
           "-Choix 19 : EBST-LPT-BF\n"
           "-Choix 20 : EBST-LPT-NBF\n"
           "-Choix 21 : EBST-WSPT-BF\n"
           "-Choix 22 : EBST-WSPT-NBF\n"
           "-Choix 23 : EBST-FCFS-BF\n"
           "-Choix 24 : EBST-FCFS-NBF\n");

    scanf("%d", &choix);
    clock_t beginReorder = clock();
    switch (choix) {
        case 1: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 2: {
            I = reorderInstance(I, OL, SPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 3:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 4:{
            I = reorderInstance(I, OL, LPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 5: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 1);
            break;
        }
        case 6: {
            I = reorderInstance(I, OL, WSPT);
            sched = newSchedule(OL, 0);
            break;
        }
        case 7:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 1);
            break;
        }
        case 8:{
            I = reorderInstance(I, OL, FCFS);
            sched = newSchedule(OL, 0);
            break;
        }
        case 9: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 10: {
            I = reorderInstance(I, BST, SPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 11:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 12:{
            I = reorderInstance(I, BST, LPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 13:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 1);
            break;
        }
        case 14:{
            I = reorderInstance(I, BST, WSPT);
            sched = newSchedule(BST, 0);
            break;
        }
        case 15:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 1);
            break;
        }
        case 16:{
            I = reorderInstance(I, BST, FCFS);
            sched = newSchedule(BST, 0);
            break;
        }
        case 17:{
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 18: {
            I = reorderInstance(I, EBST, SPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 19:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 20:{
            I = reorderInstance(I, EBST, LPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 21:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 22:{
            I = reorderInstance(I, EBST, WSPT);
            sched = newSchedule(EBST, 0);
            break;
        }
        case 23:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 1);
            break;
        }
        case 24:{
            I = reorderInstance(I, EBST, FCFS);
            sched = newSchedule(EBST, 0);
            break;
        }
        default:
            error("Invalid Choice ! You must pick 1 to 24.");
    }
    clock_t endReorder = clock();

    clock_t beginCompute = clock();
    computeSchedule(sched, I);
    clock_t endCompute = clock();

    clock_t beginSave = clock();
    saveSchedule(sched, "./data/output_BST");
    clock_t endSave = clock();

    clock_t beginSpan = clock();
    long makespan = Makespan(sched);
    clock_t endSpan = clock();

    clock_t beginWjCj = clock();
    long wjcj = SumWjCj(sched);
    clock_t endWjCj = clock();

    clock_t beginWjTj = clock();
    long wjtj = SumWjTj(sched);
    clock_t endWjTj = clock();

    clock_t beginWjFj = clock();
    long wjfj = SumWjFj(sched);
    clock_t endWjFj = clock();

    printf("\n=================Processing Time : Instance 7000===================\n");
    printf("Read Instance : %f\n", (double) (endRead - beginRead) / CLOCKS_PER_SEC);
    printf("View Instance : %f\n", (double) (endView - beginView) / CLOCKS_PER_SEC);
    printf("Reorder Instance : %f\n", (double) (endReorder - beginReorder) / CLOCKS_PER_SEC);
    printf("Compute Schedule : %f\n", (double) (endCompute - beginCompute) / CLOCKS_PER_SEC);
    printf("Save Schedule : %f\n", (double) (endSave - beginSave) / CLOCKS_PER_SEC);
    printf("Calculate MakeSpan (%ld) : %f\n", makespan, (double) (endSpan - beginSpan) / CLOCKS_PER_SEC);
    printf("Calculate WjCj (%ld) : %f\n", wjcj, (double) (endWjCj - beginWjCj) / CLOCKS_PER_SEC);
    printf("Calculate WjFj (%ld) : %f\n", wjfj, (double) (endWjFj - beginWjFj) / CLOCKS_PER_SEC);
    printf("Calculate WjTj (%ld) : %f\n", wjtj, (double) (endWjTj - beginWjTj) / CLOCKS_PER_SEC);

    freeSchedule(sched);

}