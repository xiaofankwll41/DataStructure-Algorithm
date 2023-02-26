#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define MAXSIZE 100

// Binary Tree Chain Structure define
typedef struct BitNode
{
    int data;
    struct BitNode* lchild;
    struct BitNode* rchild;

}BitNode;

// function

BitNode*    makeBitreeEmpty( BitNode* tree );
BitNode*    find( BitNode* tree, int elem );// return value is found node
BitNode*    createBitree( char pre[], char in[], int pL, int pR, int iL, int iR);
void        destoryTree( BitNode ** tree );
void        copyBitree( BitNode * Atree, BitNode * &Btree);

// no-return find, use parameter to return found node
void    search_preOrder( BitNode* tree, BitNode* &found, int elem );
void    search_inOrder( BitNode* tree, BitNode* &found, int elem );
void    search_postOrder( BitNode* tree, BitNode* &found, int elem );

int     getDepth( BitNode *tree );
int     getDepthNon_Recur( BitNode *tree );
int     getWidth( BitNode *tree );
//void    getMinDepth( BitNode *tree, int &MinDepth );
int     getMinDepth( BitNode *tree );
int     countNum( BitNode *tree );
int     countLeafNum( BitNode *tree );
void    visit( BitNode* node );
void    printKthNode( BitNode * tree, int k);
int     getElemLevel( BitNode *tree, int elem );
void    getElemLevelRecur( BitNode *tree, int elem, int &elemLevel );
// about Full Binary Tree
void    FullBitreePreToPost( char pre[], char post[], int pL, int pR, int L, int R);
bool    judgeFullBitree( BitNode * tree );

//Tree's traversal: preorder, inorder, postorder, level
void    preOrderRecur( BitNode* tree );
void    inOrderRecur( BitNode* tree );
void    postOrderRecur( BitNode* tree );

void    preOrder( BitNode* tree );
void    inOrder( BitNode* tree );
void    postOrder( BitNode* tree );

void    linkLeafNodeToList_preOrder( BitNode *tree, BitNode *&head, BitNode *&tail );
void    linkLeafNodeToList_inOrder( BitNode *tree, BitNode *&head, BitNode *&tail );
void    linkLeafNodeToList_postOrder( BitNode *tree, BitNode *&head, BitNode *&tail );

void    levelTraversal( BitNode *tree );
void    biOrderTraversalRecur( BitNode *tree );
void    printAllPath( BitNode *tree );

bool    judgeEqual( BitNode * Atree, BitNode * Btree );
bool    judgeSimilar( BitNode * Atree, BitNode * Btree );

void    ZigzagPrintBitree( BitNode* tree );
