#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/utilities.h"
#include "../include/list.h"
#include "../include/bstree.h"
#include <stdbool.h>
/*********************************************************************
 * Arbre Binaire de Recherche (non-équilibré).
 *********************************************************************/

/** FAIT
 * @brief
 * Construire et initialiser un nouveau nœud d'un arbre binaire de recherche (non-équilibré).
 * Renvoie le nouveau nœud créé.
 */
static BSTNode * newBSTNode( void * key, void * data ) {
    BSTNode * bstNode = ( BSTNode * ) calloc ( 1, sizeof( BSTNode ) );
    assert( bstNode != NULL );
    bstNode -> key = key;
    bstNode -> data = data;
    return bstNode;
}

BSTree * newBSTree( int ( * preceed )( const void *, const void * ),
                    void ( * viewKey )( const void * ), void ( * viewData )( const void * ),
                    void ( * freeKey )( void * ), void ( * freeData )( void * ) ) {
    BSTree * E = ( BSTree * ) calloc (1, sizeof( BSTree ) );
    assert( E != NULL );
    E -> preceed = preceed;
    E -> viewKey = viewKey;
    E -> viewData = viewData;
    E -> freeKey = freeKey;
    E -> freeData = freeData;
    return E;
}

/** FAIT
 * @brief
 * Insérer un nouveau nœud de clé key et donnée data
 * au sous-arbre binaire de recherche (non-équilibré) raciné au nœud curr.
 * Les clés sont comparées en utilisant la fonction preceed.
 * NB : fonction récursive.
 */
static BSTNode * insertBSTNodeIterative( BSTNode * curr, void * key, void * data, int ( * preceed )( const void *, const void * ) ) {
    BSTNode * nouveau = newBSTNode( key, data );
    BSTNode * root = curr;
    if ( curr == NULL ) {
        return nouveau;
    }
    BSTNode * pere, * actuel = curr;
    while( curr != NULL ) {
        pere = curr;
        if ( preceed( curr->key, key ) == 1 ) {
            curr = curr -> right;
        } else if ( preceed( key, curr -> key ) == 1 ) {
            curr = curr -> left;
        } else {
            error("insertBSTNodeIterative() : tentative d'insétion d'un noeud avec une \"key\" déjà présente" );
        }
    }
    if ( preceed( pere -> data, data ) == 1 ) {
        pere -> right = nouveau;
    } else {
        pere -> left = nouveau;
    }
    return root;
}

static BSTNode * insertBSTNode( BSTNode * curr, void * key, void * data, int ( * preceed )( const void *, const void * ) ) {
    if ( curr == NULL ){
        return newBSTNode( key, data );
    } else {
        if ( preceed( curr -> key, key ) == 1 ) {
            curr -> right = insertBSTNode( curr -> right, key, data, preceed );
        } else if ( preceed( key, curr -> key ) == 1 ) {
            curr -> left = insertBSTNode( curr -> left, key, data, preceed );
        } else {
            error( "insertBSTNode() : tentative d'insétion d'un noeud avec une \"key\" déjà présente" );
        }
        return curr;
    }
}
/** FAIT
 * NB : Utiliser la fonction récursive insertBSTNode.
 */
void BSTreeInsert( BSTree * T, void * key, void * data ) {
    T -> root = insertBSTNode( T -> root, key, data, T -> preceed );
    T -> numelm++;
}

/*********************************************************************
 * Arbre Binaire de Recherche Équilibré
 *********************************************************************/

/** FAIT
 * @brief
 * Construire et initialiser un nouveau nœud d'un arbre binaire de recherche équilibré (EBST).
 * Renvoie le nouveau nœud créé.
 * N'oubliez pas à initialiser le facteur d'équilibre.
 */
static BSTNode * newEBSTNode( void * key, void * data ) {
    BSTNode * nouveau = ( BSTNode * ) calloc (1, sizeof( BSTNode ) );
    assert( nouveau != NULL );
    nouveau -> key = key;
    nouveau -> data = data;
    return nouveau;
}

BSTree * newEBSTree( int ( * preceed )( const void *, const void * ),
                     void ( * viewKey )( const void * ), void ( * viewData )( const void * ),
                     void ( * freeKey )( void * ), void ( * freeData )( void * ) ) {
    BSTree * nouveau = ( BSTree * ) calloc (1, sizeof( BSTree ) );
    assert( nouveau != NULL );
    nouveau -> preceed = preceed;
    nouveau -> viewKey = viewKey;
    nouveau -> viewData = viewData;
    nouveau -> freeKey = freeKey;
    nouveau -> freeData = freeData;
    nouveau -> balanced = 1;
    return nouveau;
}

/** FAIT
 * @brief
 * Effectuer une rotation gauche autour du nœud y.
 * N'oubliez pas à mettre à jour les facteurs d'équilibre (bfactor) des nœuds modifiés.
 * Il y a 5 cas à considérer :
 * (+) bfactor(y)=-2 et bfactor(y->right)=-1
 * (+) bfactor(y)=-1 et bfactor(y->right)=1
 * (+) bfactor(y)=-1 et bfactor(y->right)=-1
 * (+) bfactor(y)=-1 et bfactor(y->right)=0
 * (+) bfactor=-2 et bfactor(y->right)=-2
 * Assurez vous que le nœud y ainsi que son fils droit existent.
 */
static BSTNode * rotateLeft( BSTNode * x ) {
    assert( x );
    assert( x -> right );
    BSTNode * y = x -> right;
    BSTNode * T2 = y -> left;
    y -> left = x;
    x -> right = T2;
    x -> bfactor += -1 - max(y -> bfactor,0);
    y -> bfactor += -1 + min(x -> bfactor,0);
    return y;
}

/** FAIT
 * @brief
 * Effectuer une rotation droite autour du nœud x.
 * N'oubliez pas à mettre à jour les facteurs d'équilibre (bfactor) des nœuds modifiés.
 * Il y a 5 cas à considérer :
 * (+) bfactor(x)=2 et bfactor(x->left)=1
 * (+) bfactor(x)=1 et bfactor(x->left)=1
 * (+) bfactor(x)=1 et bfactor(x->left)=-1
 * (+) bfactor(x)=1 et bfactor(x->left)=0
 * (+) bfactor(x)=2 et bfactor(x->left)=2
 * Assurez vous que le nœud x ainsi que son fils gauche existent.
 */
static BSTNode * rotateRight( BSTNode * y ) {
    assert( y );
    assert( y -> left );
    BSTNode * x = y -> left;
    BSTNode * T2 = x -> right;
    x -> right = y;
    y -> left = T2;
    y -> bfactor += 1 - min( x -> bfactor ,0 );
    x -> bfactor += 1 + max( y -> bfactor ,0 );
    return x;
}

/** FAIT
* @brief
 * Insérer un nouveau nœud de clé key et donnée data
 * au sous-arbre binaire de recherche équilibré raciné au nœud curr.
 * Les clés sont comparées en utilisant la fonction preceed.
 * N'oubliez pas à mettre à jour la facteur d'équilibre du nœud curr.
 * N'oubliez pas à faire les rotations nécessaires (4 cas à considérer).
 * NB : fonction récursive.
 */
static BSTNode * insertEBSTNode( BSTNode * curr, void * key, void * data, int ( * preceed )( const void *, const void * ) ) {
    if ( curr == NULL ) {
        return newEBSTNode( key, data );
    } else if ( preceed( key, curr -> key ) == 1 ) {
        int oldBfactorLeftChild = curr -> left == NULL ? 0 : curr -> left -> bfactor;
        if ( curr -> left == NULL ) {
            curr -> bfactor -= 1;
        }
        curr -> left = insertEBSTNode( curr -> left, key, data, preceed );
        if ( (    abs( curr -> left -> bfactor ) == 1    &&    curr -> left -> bfactor != oldBfactorLeftChild    ) &&
             ( (    curr -> right == NULL ? 0 : curr -> right -> bfactor ) == 0    ||    abs( curr -> right == NULL ? 0 : curr -> right -> bfactor ) == 1 )    ) {

            curr -> bfactor -= 1;
        }
    } else if ( preceed( curr -> key, key ) == 1 ) {
        int oldBfactorRightChild = curr -> right == NULL ? 0 : curr -> right -> bfactor;
        if ( curr -> right == NULL ) {
            curr -> bfactor += 1;
        }
        curr -> right = insertEBSTNode( curr -> right, key, data, preceed );
        if ( (    abs( curr -> right -> bfactor ) == 1    &&    curr -> right -> bfactor != oldBfactorRightChild )    &&
             ( abs(    curr -> left == NULL ? 0 : curr -> left -> bfactor    ) == 1    ||    (    curr -> left == NULL ? 0 : curr -> left -> bfactor ) == 0    ) ) {

            curr -> bfactor += 1;
        }
    } else {
        error("Dans insertEBSTNode () : tentative d'insétion d'un noeud avec une \"key\" déjà présente" );
    }


    //Left-Left Disbalance :
    if ( curr -> bfactor < -1 && preceed( key, curr -> left -> key ) == 1 ) {
        return rotateRight( curr );
    }
    //Right-Right Disbalance :
    if ( curr -> bfactor > 1 && preceed( curr -> right -> key, key ) == 1 ) {
        return rotateLeft( curr );
    }
    //Left-Right Disbalance :
    if ( curr -> bfactor < -1 && preceed( curr -> left -> key, key ) == 1 ) {
        curr -> left = rotateLeft( curr -> left );
        return rotateRight( curr );
    }
    //Right-Left Disbalance :
    if ( curr -> bfactor > 1 && preceed( key, curr -> right -> key ) == 1 ) {
        curr -> right = rotateRight( curr -> right );
        return rotateLeft( curr );
    }
    return curr;
}

/** FAIT
 * NB : Utiliser la fonction récursive insertEBSTNode.
 */
void EBSTreeInsert( BSTree* T, void* key, void* data ) {
    T -> root = insertEBSTNode( T -> root, key, data, T -> preceed );
    T -> numelm++;
}

/*********************************************************************
 * Fonctions communes pour :
 * Arbre Binaire de Recherche (non-équilibré), et
 * Arbre Binaire de Recherche Équilibré.
 *********************************************************************/

/** FAIT
 * @brief
 * Libérer récursivement le sous-arbre raciné au nœud curr.
 * Dans le cas où le pointeur de fonction freeKey (resp. freeData) n'est pas NULL,
 * la mémoire de la clé (resp. de la donnée) du nœud actuel est aussi libérée.
 * NB : procédure récursive.
 */
static void freeBSTNode( BSTNode * curr, void ( * freeKey )( void * ), void ( * freeData )( void * ) ) {
    if ( curr != NULL ) {
        freeBSTNode( curr -> left, freeKey, freeData );
        freeBSTNode( curr -> right, freeKey, freeData );
        if ( freeKey != NULL ) {
            freeKey( curr->key );
        }
        if ( freeData != NULL ) {
            freeData( curr -> data );
        }
        free( curr );
    }
}

/** FAIT
 * NB : Utiliser la procédure récursive freeBSTNode.
 * Vous devez utiliser les bons paramètres freeKey et freeData
 * par rapport aux valeurs deleteKey et deleteData.
 */
void freeBSTree( BSTree * T, int deleteKey, int deleteData ) {
    assert( deleteKey == 0 || deleteKey == 1 );
    assert( deleteData == 0 || deleteData == 1 );
    freeBSTNode( T -> root, deleteKey == 1 ? T -> freeKey : NULL, deleteData == 1 ? T -> freeData : NULL );
    free( T );
}

/** FAIT
 * @brief
 * Afficher récursivement le sous-arbre raciné au nœud curr
 * en utilisant un ordre infixe.
 * NB : procédure récursive.
 */
static void inorderView( BSTNode * curr, void ( * viewKey )( const void * ), void ( * viewData )( const void * ) ) {
    LNode * topOfStack = NULL;
    if ( curr == NULL ) {
        printf( "Arbre VIDE\n" );
    }
    List * stack = newList( viewKey, NULL );
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
                viewData( curr -> data );//quand le maillon qu'on a "pop" n'est pas utilisé par une autre liste
                curr = curr -> right;
            }
        }
    }
    freeList( stack, 0 );
}

/** FAIT
 * NB : Utiliser la procédure récursive inorderView.
 */
void viewBSTree( const BSTree * T ) {
    inorderView( T -> root, T -> viewKey, T -> viewData );
}

/** FAIT
 * @brief
 * Transformer récursivement le sous-arbre raciné au nœud curr
 * à une liste doublement chaînée.
 * L'argument list est en entrée/sortie.
 * La liste va contenir les éléments de l'arbre dans l'ordre infixe.
 * NB : procédure récursive.
 */
static void treetolist( BSTNode * curr, List * list ) {
    if ( curr != NULL ) {
        treetolist( curr -> left, list );
        listInsertLast( list, curr -> data );
        treetolist( curr -> right, list );
    }
}

/** FAIT
 * NB : Utiliser la procédure récursive treetolist.
 */
List * BSTreeToList( const BSTree * T ) {
    List * l1 = newList( T -> viewData, T -> freeData );
    treetolist( T -> root, l1 );
    return l1;
}

BSTNode * BSTMin( BSTNode * node ) {
    assert( node != NULL );
    BSTNode * min = node;
    while ( min -> left != NULL ) {
        min = min -> left;
    }
    return min;
}

BSTNode * BSTMax( BSTNode * node ) {
    assert( node != NULL );
    BSTNode * max = node;
    while ( max -> right != NULL ) {
        max = max -> right;
    }
    return max;
}

/** FAIT
 * @brief
 * Chercher récursivement dans le sous-arbre raciné au nœud curr
 * et renvoyer le noeud qui contient la clé qui précède la clé key (prédécesseur).
 * Le pointeur de fonction preceed donne l'ordre entre deux clés.
 * NB : fonction récursive.
 */
static BSTNode * predecessor( BSTNode * curr, void * key, int ( * preceed )( const void *, const void * ) ) {
    assert( curr != NULL );
    if ( ! preceed( key, curr -> key ) && ! preceed( curr -> key, key ) ) {
        return curr -> left != NULL ? BSTMax( curr -> left ) : curr;
    } else if ( preceed( key, curr -> key ) ) {
        if ( curr -> left != NULL ) {
            return predecessor( curr -> left, key, preceed );
        } else {
            error( "findSuccessor() : Le noeud de clef \"key\", qui a été donné en paramètre n'est pas présent dans l'arbre\n" );
        }
    } else {
        if ( curr -> right != NULL ) {
            return predecessor( curr -> right, key, preceed );
        } else {
            error( "findSuccessor() : Le noeud de clef \"key\", qui a été donné en paramètre n'est pas présent dans l'arbre\n" );
        }
    }
}

/** FAIT
 * NB : Utiliser la fonction récursive predecessor.
 */
BSTNode * findPredecessor( const BSTree * T, const BSTNode * node ) {
    assert( T -> root != NULL );
    assert( node != NULL );
    return predecessor( T -> root, node -> key, T -> preceed );
}

/** FAIT
 * @brief
 * Chercher récursivement dans le sous-arbre raciné au nœud curr
 * et renvoyer le noeud qui contient la clé qui succède la clé key (successeur).
 * Le pointeur de fonction preceed donne l'ordre entre deux clés.
 * NB : fonction récursive.
 */
static BSTNode * successor( BSTNode * curr, void * key, int ( * preceed )( const void *, const void * ) ) {
    assert( curr != NULL );
    if ( ! preceed( key, curr -> key ) && ! preceed( curr -> key ,key ) ) {
        return curr -> right != NULL ? BSTMin( curr -> right ) : curr;
    } else if ( preceed( key, curr -> key ) ) {
        if ( curr -> left != NULL ) {
            return successor( curr -> left, key, preceed );
        } else {
            error( "findSuccessor() : Le noeud de clef \"key\", qui a été donné en paramètre n'est pas présent dans l'arbre\n" );
        }
    } else {
        if ( curr -> right != NULL ) {
            return successor( curr -> right, key, preceed );
        } else {
            error( "findSuccessor() : Le noeud de clef \"key\", qui a été donné en paramètre n'est pas présent l'arbre\n" );
        }
    }
}

/** FAIT
 * NB : Utiliser la fonction récursive successor.
 */
BSTNode * findSuccessor( const BSTree * T, const BSTNode * node ) {
    assert( T -> root != NULL );
    assert( node != NULL );
    return successor( T -> root, node -> key, T -> preceed );
}

bool isBSTree( const BSTNode * curr, int ( * preceed )( const void * , const void * ) ) {
    if ( curr == NULL ) {
        return true;
    } else {
        return(
                curr -> left == NULL ? true : isBSTree( curr -> left, preceed ) && preceed( curr -> left -> key, curr -> key )
                                            && curr->right == NULL ? true : isBSTree( curr -> right, preceed ) && preceed( curr -> key, curr -> right -> key )

        );
    }
}
bool isBalanced( const BSTNode * curr, int ( * preceed )( const void * , const void * ) )
{
    if ( curr == NULL ) {
        return true;
    } else {
        return ( curr -> bfactor * curr -> bfactor <= 1 ) && isBalanced( curr -> left, preceed ) &&
               isBalanced( curr -> right, preceed );
    }
}