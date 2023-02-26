#pragma once
#include <bits/stdc++.h>
using namespace std;

typedef struct BitNode
{
    int data;
    struct BitNode* lchild;
    struct BitNode* rchild;

}BiSTNode;

// function
BiSTNode*   CreateBiSearchTree( int Arr[] , int n );
BiSTNode*   CreateBiSearchTree_test( int Arr[] , int n );

BiSTNode*   BiSTSearch( BiSTNode * tree, int elem );
BiSTNode*   rBiSTSearch( BiSTNode * tree, int elem );

bool        BiSTInsert( BiSTNode *& tree, int elem );
bool        rBiSTInsert( BiSTNode *& tree, int elem );

bool        DeleteElem( BiSTNode *& tree, int elem );
bool        DeleteMinNode( BiSTNode *&tree );

bool        JudgeBiSTree( BiSTNode * tree );
bool        InsertNode(BiSTNode *&tree, BiSTNode *node);
bool        DeleteRoot( BiSTNode *&tree );
BiSTNode*   MergeBiSTree( BiSTNode *&Atree, BiSTNode *&Btree );
void        visit( BiSTNode * node );
void        DestroyTree( BiSTNode *& tree );

void InOrderPrintBiSTree( BiSTNode * tree );
void rInOrderPrintBiSTree( BiSTNode * tree );
