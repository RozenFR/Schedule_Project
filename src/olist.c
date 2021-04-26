#include "../include/list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../include/utilities.h"

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
    int ( * preceed )( const void * a, const void * b );
    void ( * viewKey )( const void * key );
    void ( * viewData )( const void * data );
    void ( * freeKey )( void * key );
    void ( * freeData )( void * data );
} OList;
/**
 * Construire et initialiser un nouveau nœud d’une liste ordonnée.
 */
static OLNode * newOLNode ( void * key , void * data ) {
    OLNode * nouveau = ( OLNode * ) calloc (1, sizeof( OLNode ) );
    assert( nouveau != NULL );
    nouveau -> key = key;
    nouveau -> data = data;
    nouveau -> pred = NULL;
    nouveau -> succ = NULL;
    return nouveau;
}

/**
 * @brief
 * Construire une liste doublement chaînée ordonnée vide
 */
OList * newOList( int ( * preceed )( const void *, const void * ),
                  void ( * viewKey )( const void * ), void ( * viewData )( const void * ),
                  void ( * freeKey )( void * ), void ( * freeData )( void * ) ) {

    OList * nouveau = ( OList * ) calloc (1, sizeof( OList ) );
    assert( nouveau != NULL );
    nouveau -> preceed = preceed;
    nouveau -> viewKey = viewKey;
    nouveau -> viewData = viewData;
    nouveau -> freeKey = freeKey;
    nouveau -> freeData = freeData;
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
void freeOList( OList * L, int deleteKey, int deleteData ) {
    OLNode * aSauver = NULL;
    while ( L -> head != NULL ) {
        aSauver = L -> head -> succ;
        if ( deleteKey == 1 )
            L->freeKey( L -> head -> key );
        if ( deleteData == 1 )
            L->freeData( L -> head -> data );
        free( L -> head );
        L -> head = aSauver;
    }
    free( L );
}

/**
 * @brief
 * Afficher les éléments de la liste ordonnée.
 * Chaque élément est affiché grâce aux pointeurs de fonction
 * de la structure OrderedList :
 * (+) viewKey pour la clé
 * (+) viewData pour les données
 */
void viewOList( const OList * L ) {
    if ( L -> numelm == 0 ) {
        printf("Liste VIDE\n");
    }
    else {
        for ( OLNode * aAfficher = L -> head; aAfficher != NULL; aAfficher = aAfficher -> succ ) {
            L -> viewKey( aAfficher -> key );
        }
        printf("\n" );
        for ( OLNode * aAfficher = L -> head; aAfficher != NULL; aAfficher = aAfficher -> succ ) {
            L -> viewData( aAfficher -> data );
        }
    }
}

/**
 * @brief
 * Ajouter dans la liste ordonnée L un élément de clé key et de donnée data.
 */
void OListInsert( OList * L, void * key, void * data ) {
    OLNode * nouveau = newOLNode( key, data );
    assert( nouveau != NULL );
    //Le cas où la LISTE est VIDE
    if ( L -> numelm == 0 ) {
        L -> head = nouveau;
        L -> tail = nouveau;
        L -> numelm++;
    }
        //Le cas où l'élèment est à mettre AVANT L->HEAD
    else if ( L -> preceed( nouveau -> key, L -> head -> key ) == 1 ) {
        if ( ! L -> preceed( nouveau -> key, L -> head -> key ) && ! L -> preceed( L -> head -> key, nouveau -> key ) ) {
            error("OListInsert() : tentative d'insértion d'une \"key\" déjà présente" );
        }
        nouveau -> succ = L -> head;
        L -> head -> pred = nouveau;
        L -> head = nouveau;
        L -> numelm++;
    }
        //Recherche de la position pour ranger NOUVEAU
    else {
        OLNode * actuel = L -> head;
        while ( actuel -> succ != NULL && L -> preceed( nouveau -> key, actuel -> succ -> key ) == 0 ) {
            actuel = actuel -> succ;
        }
        if ( ! L -> preceed( nouveau -> key, actuel -> key ) && ! L -> preceed( actuel -> key, nouveau -> key ) ) {
            printf("Les éléments sont égaux d'après la politique d'ordonnancement choisie\n");
            L -> viewKey( actuel -> key );
            printf("\n est égal à\n" );
            L->viewKey(nouveau->key);
            error("\nOListInsert() : tentative d'insértion d'une \"key\" déjà présente" );
        }
        nouveau -> succ = actuel -> succ;
        //Cas général
        if ( actuel -> succ != NULL ) {
            nouveau -> succ -> pred = nouveau;
        }
            //Gestion du cas où l'élèment à insérer après TAIL
        else {
            L -> tail = nouveau;
        }
        actuel -> succ = nouveau;
        nouveau -> pred = actuel;
        L -> numelm++;
    }
}

/**
 * @brief
 * Transformer la liste doublement chaînée ordonnée L
 * à une liste doublement chaînée classique (non-ordonnée).
 */
List * OListToList( const OList * L ) {
    List * nL = newList( L -> viewData, L -> freeData );

    nL -> freeData = L -> freeData;
    nL -> viewData = L -> viewData;
    nL -> numelm = L -> numelm;

    for ( OLNode * iterator = L -> head; iterator != NULL; iterator = iterator -> succ )
    {
        listInsertLast( nL, iterator -> data );
    }


    return nL;

}
