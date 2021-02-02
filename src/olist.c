#ifndef _OLIST_
#define _OLIST_
#include "list.h"
#include <stdlib.h>

/**
 * @brief
 * Liste doublement chaînée ordonnée
 */

/**
 * @brief
 * Un élément d'une liste doublement chaînée ordonnée contient :
 * (+) une clé (key),
 * (+) une donnée (data),
 * (+) une référence (suc) à l'élément suivant, et
 * (+) une référence (pred) à l'élément précédent.
 */
typedef struct OrderedListNode {
    void * key;
    void * data;
    struct OrderedListNode * succ, * pred;
} OLNode;

/**
 * @brief
 * La liste doublement chaînée ordonnée est une structure contenant
 * (+) une référence (head) sur son premier élément,
 * (+) une référence (tail) sur son dernier élément,
 * (+) le nombre d'éléments,
 * (+) un pointeur de fonction pour comparer ses clés,
 * (+) un pointeur de fonction pour afficher ses clés,
 * (+) un pointeur de fonction pour afficher ses données,
 * (+) un pointeur de fonction pour libérer la mémoire de ses clés, et
 * (+) un pointeur de fonction pour libérer la mémoire de ses données.
 */
typedef struct OrderedList {
    OLNode * head, * tail;
    int numelm;
    int (*preceed)(const void* a, const void* b);
    void (*viewKey)(const void* key);
    void (*viewData)(const void* data);
    void (*freeKey)(void* key);
    void (*freeData)(void* data);
} OList;
/**
 * Construire et initialiser un nouveau nœud d’une liste ordonnée.
 */
static OLNode * newOLNode (void* key , void* data ){
    OLNode* nouveau = calloc(1,sizeof(nouveau));
    nouveau->key = key;
    nouveau->data = data;
    return nouveau;
}

/**
 * @brief
 * Construire une liste doublement chaînée ordonnée vide
 */
OList * newOList(int (*preceed)(const void*, const void*),
                 void (*viewKey)(const void*), void (*viewData)(const void*),
                 void (*freeKey)(void*), void (*freeData)(void*)){
    OList* nouveau = calloc(1,sizeof(nouveau));
    nouveau->preceed = preceed;
    nouveau->viewKey = viewKey;
    nouveau->viewData = viewData;
    nouveau->freeKey = freeKey;
    nouveau->freeData = freeData;
    return nouveau;
}

/**
 * @brief
 * Plusieurs possibilités de supprimer la liste ordonnée L :
 * (+) Si le paramètre deleteKey vaut 0
 *     Alors les clés (key) des éléments de la liste L ne sont pas supprimées ;
 * (+) Si le paramètre deleteData vaut 1
 *     Alors le pointeur de fonction freeKey de la structure OrderedList
 *     va servir à supprimer les clés (key) des éléments de la liste L.
 * 
 * (+) Si le paramètre deleteData vaut 0
 *     Alors les données (data) référencées par les éléments
 *     de la liste L ne sont pas supprimées ;
 * (+) Si le paramètre deleteData vaut 1
 *     Alors le pointeur de fonction freeData de la structure OrderedList
 *     va servir à supprimer les données (data) référencées par
 *     les éléments de la liste L.
 */
void freeOList(OList * L, int deleteKey, int deleteData){
    OLNode* aSauver = NULL;
    while(L->head != NULL){
        aSauver = L->head->succ;
        if(deleteData == 1){
            void (*ptrFreeKey)(void*) = L->freeKey;
            void (*ptrFreeData)(void*) = L->freeData;
            (L->freeKey)(L->head->key);
            (L->freeData)(L->head->data);
        }
        free(L->head);
        L->head = aSauver;
    }
    free(L);
}

/**
 * @brief
 * Afficher les éléments de la liste ordonnée.
 * Chaque élément est affiché grâce aux pointeurs de fonction
 * de la structure OrderedList :
 * (+) viewKey pour la clé
 * (+) viewData pour les données
 */
void viewOList(const OList * L){
    for(OLNode* aAfficher = L->head; aAfficher != NULL; aAfficher = aAfficher->succ){
        (L->viewKey)(aAfficher->key);
        (L->viewData)(aAfficher->data);
    }
}

/**
 * @brief
 * Ajouter dans la liste ordonnée L un élément de clé key et de donnée data.
 */
void OListInsert(OList * L, void * key, void * data){
    OLNode* nouveau = calloc(1,sizeof(nouveau));
    nouveau->key = key;
    nouveau->data = data;
    L->numelm++;
    if(L->numelm == 0){
        L->head = nouveau;
        L->tail = nouveau;
    }
    else{
        OLNode* actuel = L->head;
        while(actuel->succ != NULL || (L->preceed)(nouveau->key,actuel->succ->key)){
            actuel = actuel->succ;
        }
        nouveau->succ = actuel->succ;
        nouveau->pred = actuel;
        actuel->succ;


    }
}

/**
 * @brief
 * Transformer la liste doublement chaînée ordonnée L
 * à une liste doublement chaînée classique (non-ordonnée).
 */
List* OListToList(const OList* L)
{
    List * nL = newList(L->viewData, L->freeData);

    nL -> freeData = L -> freeData;
    nL -> viewData = L -> viewData;
    nL -> numelm = L -> numelm;

    for (LNode * iterator = L -> head; iterator != NULL; iterator = iterator -> succ)
    {
        listInsertFirst(nL, iterator -> data);
    }

    freeOList(L, L -> freeKey, 1);

    return nL;
}

#endif // _OLIST_