#pragma once

#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100

// Adjacency Matrix
typedef struct 
{
    int Vex[MAXSIZE];
    int Edges[MAXSIZE][MAXSIZE];
    int vertexNum, edgeNum;
}MGraph;

// Adjacency List of Graph
typedef struct ArcNode
{
    int adjvex;
    int weight;
    struct ArcNode *nextArc;
}ArcNode;

typedef struct 
{
    int vex;
    ArcNode *firstArc;
}ALHead;

typedef struct
{
    ALHead aList[MAXSIZE];
    int vertexNum, edgeNum;
}ALGraph;

// init function 
void    createDiMgraph( MGraph &G );
void    createUnDiMgraph( MGraph &G );
void    createWiDiMgraph( MGraph &G );
void    createWiUnDiMgraph( MGraph &G );

void    createDiALgraph( ALGraph &G );
void    createUnDiALgraph( ALGraph &G );
void    createWiDiALgraph( ALGraph &G );
void    createWiUnDiALgraph( ALGraph &G );

void    ArrayInitDiMgraph( MGraph &G, int arr[][2], int v, int e );
void    ArrayInitUnDiMgraph( MGraph &G, int arr[][2], int v, int e );
void    ArrayInitWiDiMgraph( MGraph &G, int arr[][3], int v, int e );
void    ArrayInitWiUnDiMgraph( MGraph &G, int arr[][3], int v, int e );

void    ArrayInitDiALgraph( ALGraph &G, int arr[][2], int v, int e );
void    ArrayInitUnDiALgraph( ALGraph &G, int arr[][2], int v, int e );
void    ArrayInitWiDiALgraph( ALGraph &G, int arr[][3], int v, int e );
void    ArrayInitWiUnDiALgraph( ALGraph &G, int arr[][3], int v, int e );

// destory function
void    deleteArcDiALGraph( ALGraph &G, int u, int v );
void    deleteArcUnDiALGraph( ALGraph &G, int u, int v);
void    freeALGrpah( ALGraph &G );
void    destoryALGraph( ALGraph &G );
void    destoryMGraph( ALGraph &G );

// traversal
void    bfsMGraph( MGraph &G, int start, bool reach[] );
void    dfsMGraph( MGraph &G, int start, bool reach[] );

void    bfsALGraph( ALGraph &G, int start, bool reach[] );
void    dfsALGraph( ALGraph &G, int start, bool reach[] );

void    BFSMGraph( MGraph &G );
void    DFSMGraph( MGraph &G );

void    BFSALGraph( ALGraph &G );
void    DFSALGraph( ALGraph &G );

// Recursive traversal
void    r_bfsMGraph( MGraph &G , int v, bool reach[] );
void    r_dfsMGraph( MGraph &G , int v, bool reach[] );

void    r_bfsALGraph( ALGraph &G, int v, bool reach[] );
void    r_dfsALGraph( ALGraph &G, int v, bool reach[] );

void    rBFSMGraph( MGraph &G );
void    rDFSMGraph( MGraph &G );

void    rBFSALGraph( ALGraph &G );
void    rDFSALGraph( ALGraph &G );

// ex7-1
int     retFarthestVex( ALGraph &G, int v );
// ex7-2
bool    isTreeOfUnDiALGraph_R( ALGraph &G ); 
// about path function
bool    isExitPath( ALGraph &G, int u, int v );
bool    rIsExitPath( ALGraph &G, int u, int v);

// exist a path that length = k from u to v in no-weight Graph
bool    ExistLenKPath( ALGraph &G, int u, int v, int k );

bool    ExistPathDFS( ALGraph &G, int u, int v );
bool    ExistPathBFS( ALGraph &G, int u, int v );
bool    ExistPathBFS_( ALGraph &G, int u, int v );

// print all path from u to v
void    printAllPath( ALGraph &G, int u, int v );

bool    TopSort( ALGraph &G );
int     countInDegreeDiALGraph( ALGraph &G, int v );
int     countOutDegreeDiALGraph( ALGraph &G, int v );
int     countDegreeUnDiALGraph( ALGraph &G, int v );


// judge loop though v in in directed Graph
bool    JudgeLoop( ALGraph &G, int v );

// Minimum cost spanning tree
int     PrimMST( MGraph &G, int start );
int     KruskalMST( int Arr[][3], int n, int e );

// Shortest path
void    Dijkstra( MGraph &G, int v );
void    Floyd( MGraph &G, int path[][MAXSIZE], int A[][MAXSIZE] );


//  print function
void    printMG( MGraph G );
void    printWiMG( MGraph G );

void    printALG( ALGraph G );
void    printWiALG( ALGraph G ); 

