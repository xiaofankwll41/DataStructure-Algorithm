#include "binarySearchTree.h"

BiSTNode* CreateBiSearchTree( int Arr[] , int n )
{
    BiSTNode *tree = NULL;
    for ( int i = 0; i < n; ++i )
        BiSTInsert( tree, Arr[i] );
        // rBiSTInsert( tree, A[i] );
    return tree;
}

BiSTNode* CreateBiSearchTree_test( int Arr[] , int n )
{
    BiSTNode *tree = NULL;
    for ( int i = 0; i < n; ++i )
        rBiSTInsert( tree, Arr[i] );
    return tree;
}

BiSTNode* BiSTSearch( BiSTNode * tree, int elem )
{
    while ( tree && tree->data != elem )
        if ( elem < tree->data )
            tree = tree->lchild;
        else tree = tree->rchild;
    return tree;
}

BiSTNode* rBiSTSearch( BiSTNode * tree, int elem )
{
    if ( tree )
        if ( tree->data == elem )
            return tree;
        else if ( elem < tree->data )
            return rBiSTSearch( tree->lchild, elem );
        else return rBiSTSearch( tree->rchild, elem );
    return NULL;
}

bool BiSTInsert( BiSTNode *& tree, int elem )
{
    BiSTNode * p = tree, *pp = p;    
    while ( p && p->data != elem )
    {
        pp = p;
        if ( elem < p->data )
            p = p->lchild;
        else 
            p = p->rchild;
    }
    if ( p ) return false;
    // create node
    p = new BiSTNode;
    p->data = elem;
    p->lchild = p->rchild = NULL;
    
    if ( pp )
    {
        if ( elem < pp->data )
            pp->lchild = p;
        else
            pp->rchild = p;
    }
    else
        tree = p;
    return true;
}

bool rBiSTInsert( BiSTNode *& tree, int elem )
{
    if ( !tree )
    {
        tree = new BiSTNode;
        tree->data = elem;
        tree->lchild = tree->rchild = NULL;
        return true;
    }
    else
    {
        if ( tree->data == elem )
            return false;
        else if ( elem < tree->data )
            return rBiSTInsert( tree->lchild, elem );
        else 
            return rBiSTInsert ( tree->rchild, elem );
    }
}

bool DeleteElem( BiSTNode *& tree, int elem )
{// only non-recur
    BiSTNode *p = tree, *pp;
    if ( !tree )
        return false;
    while ( p && p->data != elem )
    {
        pp = p;
        if ( elem < p->data )
            p = p->lchild;
        else if ( elem > p->data )
            p = p->rchild;
    }
    if ( !p ) return false;
    else if ( p->lchild && p->rchild )
    {
        BiSTNode *s = p->lchild, *ps = p;
        while ( s->rchild )
        {
            ps = s;
            s = s->rchild;
        }
        p->data = s->data;
        pp = ps;
        p = s;
    }
    
    BiSTNode *q;
    if ( p->lchild )
        q = p->lchild;
    else q = p->rchild;

    if ( p == tree )
        tree = q;
    else
    {
        if ( p == pp->lchild )
            pp->lchild = q;
        else pp->rchild = q;
    }
    free(p);
    return true;
}

bool DeleteMinNode( BiSTNode *&tree )
{
    BiSTNode *p = tree, *pp;
    if ( !tree )
        return false;
    while ( p->lchild )
    {
        pp = p;
        p = p->lchild;
    }
    if ( p == tree )
        tree = tree->rchild;
    else
    {
        if ( !p->rchild )
            pp->lchild = NULL;
        else
            pp->lchild = p->rchild;
    }
    free(p);
    return true;
}

bool JudgeBiSTree( BiSTNode * tree )
{
    static int pre = INT_MIN;
    
    if ( tree )
    {
        int l = JudgeBiSTree( tree->lchild );
        if ( !l || pre >= tree->data )
            return false;
        pre = tree->data;
        int r = JudgeBiSTree( tree->rchild );
        return r;
    }
    return true;

}

bool InsertNode(BiSTNode *&tree, BiSTNode *node)
{
    BiSTNode *p = tree, *pp;
	while( p )
	{
		pp = p; 
		if ( node->data < p->data )
			p = p->lchild;
		else if ( node->data > p->data )
			p = p->rchild;
		else return false;
    }
    if ( tree )
    {
	    if ( node->data < pp->data )
		    pp->lchild = node;
	    else
		    pp->rchild = node;
    }
    else tree = node;
    return true;
}
bool DeleteRoot( BiSTNode *&tree )
{
    BiSTNode *p = tree, *pp;
    if ( !tree ) { return false; }
    if ( p->lchild && p->rchild )
    {
        BiSTNode *s = p->lchild, *ps = p;
        while ( s->rchild )
        {
            ps = s;
            s = s->rchild;
        }
        p->data = s->data;
        p = s;
        pp = ps;
    }
    // find a node in front of tree in inOrder
    // delete the node
    BiSTNode *q;
    if ( p->lchild )
        q = p->lchild;
    else q = p->rchild; // p == tree

    if ( p == tree )
        tree = q;
    else 
    {
        if ( p == pp->lchild )
            pp->lchild = q;
        else pp->rchild = q;
    }
    free(p);
    return true;
}
BiSTNode * MergeBiSTree( BiSTNode *&Atree, BiSTNode *&Btree )
{
    BiSTNode *p = Btree, *q;
    while ( p )
    {
        q = new BiSTNode;
        q->data = p->data;
        q->lchild = q->rchild = NULL;
        DeleteRoot( Btree );
        // DeleteElem( Btree, Btree->data );
        p = Btree;
        InsertNode( Atree, q );
    }
    return Atree;
}

void visit( BiSTNode * node )
{
    if ( node )
        cout << ' ' << (char)node->data;
}

void DestroyTree( BiSTNode *& tree )
{
    if ( tree )
    {
        DestroyTree( tree->lchild );
        DestroyTree( tree->rchild );
        delete tree;
        tree = NULL;
    }
}

void InOrderPrintBiSTree( BiSTNode * tree )
{

}

void rInOrderPrintBiSTree( BiSTNode * tree )
{
    if ( tree )
    {
        rInOrderPrintBiSTree( tree->lchild );
        visit ( tree );
        rInOrderPrintBiSTree( tree->rchild );
    }
}