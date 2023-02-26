#include "Graph.h"

void createDiMgraph( MGraph &G )
{// create Directed MGraph
    cout << " Input Directed Graph's vertexNum and edgeNum : " << endl;
    cin >> G.vertexNum >> G.edgeNum;
    for ( int i = 0; i < G.vertexNum; ++i) G.Vex[i] = i;
    for ( int i = 0; i < G.vertexNum; ++i)
        for ( int j = 0; j < G.vertexNum; ++j)
            G.Edges[i][j] = 0;
    cout << "input " << G.edgeNum << " Edges' info (<start, end>)" << endl;
    int start, end;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        cin >> start >> end;
        G.Edges[start][end] = 1;
    }
}

void createUnDiMgraph( MGraph &G )
{// create UnDirected MGraph
    cout << " Input UnDirected Graph's vertexNum and edgeNum : " << endl;
    cin >> G.vertexNum >> G.edgeNum;
    for ( int i = 0; i < G.vertexNum; ++i) G.Vex[i] = i;
    for ( int i = 0; i < G.vertexNum; ++i)
        for ( int j = 0; j < G.vertexNum; ++j)
            G.Edges[i][j] = 0;
    cout << "input " << G.edgeNum << " Edges' info: (<start, end>)" << endl;
    int start, end;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        cin >> start >> end;
        G.Edges[start][end] = G.Edges[end][start] = 1;
    }

}

void createWiDiMgraph( MGraph &G )
{// create Wighted Directed MGraph
    cout << " Input Wighted Directed Graph vertexNum and edgeNum : " << endl;
    cin >> G.vertexNum >> G.edgeNum;
    for ( int i = 0; i < G.vertexNum; ++i ) G.Vex[i] = i;
    for ( int i = 0; i < G.vertexNum; ++i )
        for ( int j = 0; j < G.vertexNum; ++j )
            G.Edges[i][j] = INT_MAX; // 
    cout << " Input " << G.edgeNum << " Edges' info: (<start, end, Weight>)" << endl;
    int start, end;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        cin >> start >> end; 
        cin >> G.Edges[start][end];
    }
}

void createWiUnDiMgraph( MGraph &G )
{// create Wighted UnDirected MGraph
    cout << " Input Wighted UnDirected Graph vertexNum and edgeNum : " << endl;
    cin >> G.vertexNum >> G.edgeNum;
    for ( int i = 0; i < G.vertexNum; ++i ) G.Vex[i] = i;
    for ( int i = 0; i < G.vertexNum; ++i )
        for ( int j = 0; j < G.vertexNum; ++j )
            G.Edges[i][j] = INT_MAX; // 
    cout << " Input " << G.edgeNum << " Edges' info: (<start, end, Weight>)" << endl;
    int start, end;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        cin >> start >> end; 
        cin >> G.Edges[start][end]; 
        G.Edges[end][start] = G.Edges[start][end];
    }

}

void createDiALgraph( ALGraph &G )
{// create Directed ALGraph
    cout << " Input Directed ALGraph vertexNum and edgeNum :" << endl;
    cin >> G.vertexNum >> G.edgeNum;
    for ( int i = 0; i < G.vertexNum; ++i ) 
    {
        G.aList[i].vex = i;
        G.aList[i].firstArc = NULL;
    }
    cout << " Input " << G.vertexNum << " Edges' info (<start, end>)" << endl;
    int start, end;
    ArcNode *p;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        cin >> start >> end;
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->weight = 0; p->adjvex = end;
        p->nextArc = G.aList[start].firstArc;
        G.aList[start].firstArc = p;
    }
}

void createUnDiALgraph( ALGraph &G )
{// create UnDirected ALGraph
    cout << " Input UnDirected ALGraph vertexNum and edgeNum :" << endl;
    cin >> G.vertexNum >> G.edgeNum;
    for ( int i = 0; i < G.vertexNum; ++i ) 
    {
        G.aList[i].vex = i;
        G.aList[i].firstArc = NULL;
    }
    cout << " Input " << G.vertexNum << " Edges' info (<start, end>)" << endl;
    int start, end;
    ArcNode *p;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        cin >> start >> end;
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->weight = 0; p->adjvex = end;
        p->nextArc = G.aList[start].firstArc;
        G.aList[start].firstArc = p;
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->weight = 0; p->adjvex = start;
        p->nextArc = G.aList[end].firstArc;
        G.aList[end].firstArc = p;
    }
}

void createWiDiALgraph( ALGraph &G )
{// create Weighted Directed ALGraph
    cout << " Input Weighted Directed ALGraph vertexNum and edgeNum :" << endl;
    cin >> G.vertexNum >> G.edgeNum;
    for ( int i = 0; i < G.vertexNum; ++i ) 
    {
        G.aList[i].vex = i;
        G.aList[i].firstArc = NULL;
    }
    cout << " Input " << G.vertexNum << " Edges' info (<start, end, weight>)" << endl;
    int start, end;
    ArcNode *p;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        cin >> start >> end;
        p = (ArcNode *)malloc(sizeof(ArcNode));
        cin >> p->weight; p->adjvex = end;
        p->nextArc = G.aList[start].firstArc;
        G.aList[start].firstArc = p;
    }
}

void createWiUnDiALgraph( ALGraph &G )
{// create Weighted UnDirected ALGraph
    cout << " Input Weighted UnDirected ALGraph vertexNum and edgeNum :" << endl;
    cin >> G.vertexNum >> G.edgeNum;
    for ( int i = 0; i < G.vertexNum; ++i ) 
    {
        G.aList[i].vex = i;
        G.aList[i].firstArc = NULL;
    }
    cout << " Input " << G.vertexNum << " Edges' info (<start, end, weigt>)" << endl;
    int start, end, weight;
    ArcNode *p;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        cin >> start >> end >> weight;
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->weight = weight; p->adjvex = end;
        p->nextArc = G.aList[start].firstArc;
        G.aList[start].firstArc = p;
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->weight = weight; p->adjvex = start;
        p->nextArc = G.aList[end].firstArc;
        G.aList[end].firstArc = p;
    }
}

void ArrayInitDiMgraph( MGraph &G, int arr[][2], int v, int e )
{// Array initialize Directed MGraph
    G.vertexNum = v; G.edgeNum = e;
    for ( int i = 0; i < G.vertexNum; ++i ) G.Vex[i] = i;
    for ( int i = 0; i < G.vertexNum; ++i )
        for ( int j = 0; j < G.vertexNum; ++j )
            G.Edges[i][j] = 0;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        G.Edges[arr[i][0]][arr[i][1]] = 1;
    }
}

void ArrayInitUnDiMgraph( MGraph &G, int arr[][2], int v, int e )
{// Array initialize UnDirected MGraph
    G.vertexNum = v; G.edgeNum = e;
    for ( int i = 0; i < G.vertexNum; ++i ) G.Vex[i] = i;
    for ( int i = 0; i < G.vertexNum; ++i )
        for ( int j = 0; j < G.vertexNum; ++j )
            G.Edges[i][j] = 0;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        G.Edges[arr[i][0]][arr[i][1]] = 1;
        G.Edges[arr[i][1]][arr[i][0]] = 1;
    }
}

void ArrayInitWiDiMgraph( MGraph &G, int arr[][3], int v, int e )
{// Array initialize Weighted Directed MGraph
    G.vertexNum = v; G.edgeNum = e;
    for ( int i = 0; i < G.vertexNum; ++i ) G.Vex[i] = i;
    for ( int i = 0; i < G.vertexNum; ++i )
        for ( int j = 0; j < G.vertexNum; ++j )
            G.Edges[i][j] = INT_MAX;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        G.Edges[arr[i][0]][arr[i][1]] = arr[i][2];
    }
}

void ArrayInitWiUnDiMgraph( MGraph &G, int arr[][3], int v, int e )
{// Array initialize Weighted UnDirected MGraph
    G.vertexNum = v; G.edgeNum = e;
    for ( int i = 0; i < G.vertexNum; ++i ) G.Vex[i] = i;
    for ( int i = 0; i < G.vertexNum; ++i )
        for ( int j = 0; j < G.vertexNum; ++j )
            G.Edges[i][j] = INT_MAX;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        G.Edges[arr[i][0]][arr[i][1]] = arr[i][2];
        G.Edges[arr[i][1]][arr[i][0]] = arr[i][2];
    }
}

void ArrayInitDiALgraph( ALGraph &G, int arr[][2], int v, int e )
{// Array initialize Directed ALGraph
    G.vertexNum = v; G.edgeNum = e;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        G.aList[i].vex = i;
        G.aList[i].firstArc = NULL;
    }
    ArcNode *p;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = arr[i][1];
        p->weight = 0;
        p->nextArc = G.aList[arr[i][0]].firstArc;
        G.aList[arr[i][0]].firstArc = p;
    }
}

void ArrayInitUnDiALgraph( ALGraph &G, int arr[][2], int v, int e )
{// Array initialize UnDirected ALGraph
    G.vertexNum = v; G.edgeNum = e;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        G.aList[i].vex = i;
        G.aList[i].firstArc = NULL;
    }
    ArcNode *p;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = arr[i][1]; p->weight = 0;
        p->nextArc = G.aList[arr[i][0]].firstArc;
        G.aList[arr[i][0]].firstArc = p;
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = arr[i][0]; p->weight = 0;
        p->nextArc = G.aList[arr[i][1]].firstArc;
        G.aList[arr[i][1]].firstArc = p;
    }
}

void ArrayInitWiDiALgraph( ALGraph &G, int arr[][3], int v, int e )
{// Array initialize Weighted Directed ALGraph
    G.vertexNum = v; G.edgeNum = e;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        G.aList[i].vex = i;
        G.aList[i].firstArc = NULL;
    }
    ArcNode *p;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = arr[i][1];
        p->weight = arr[i][2];
        p->nextArc = G.aList[arr[i][0]].firstArc;
        G.aList[arr[i][0]].firstArc = p;
    }
}

void ArrayInitWiUnDiALgraph( ALGraph &G, int arr[][3], int v, int e )
{// Array initialize Weighted UnDirected ALGraph
    G.vertexNum = v; G.edgeNum = e;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        G.aList[i].vex = i;
        G.aList[i].firstArc = NULL;
    }
    ArcNode *p;
    for ( int i = 0; i < G.edgeNum; ++i )
    {
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = arr[i][1]; p->weight = arr[i][2];
        p->nextArc = G.aList[arr[i][0]].firstArc;
        G.aList[arr[i][0]].firstArc = p;
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = arr[i][0]; p->weight = arr[i][2];
        p->nextArc = G.aList[arr[i][1]].firstArc;
        G.aList[arr[i][1]].firstArc = p;
    }
}

void    deleteArcDiALGraph( ALGraph &G, int u, int v )
{
    ArcNode *p, *pre;
    for ( p = G.aList[u].firstArc; p; p = p->nextArc )
    {
        int w = p->adjvex;
        if ( w == v )
        {
            if (p == G.aList[u].firstArc)
            {
                G.aList[u].firstArc = p->nextArc;
            }
            else 
            {
                pre->nextArc = p->nextArc;
            }
            free( p );
            --G.edgeNum;
            return;
        }
        pre = p;
    }
}

void    deleteArcUnDiALGraph( ALGraph &G, int u, int v)
{
    deleteArcDiALGraph( G, u, v );
    deleteArcDiALGraph( G, v, u );
}

void freeALGrpah( ALGraph &G )
{// free all ArcNode
    ArcNode *p;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        p = G.aList[i].firstArc;
        while ( p )
        {
            G.aList[i].firstArc = p->nextArc;
            free( p );
            p = G.aList[i].firstArc;
        }
    }

}

void destoryALGraph( ALGraph &G )
{
    freeALGrpah( G );
    G.vertexNum = G.edgeNum = 0;
}

void destoryMGraph( ALGraph &G )
{
    G.vertexNum = G.edgeNum = 0;
}

void bfsMGraph( MGraph &G, int start, bool reach[] )
{// breadth-first search for MGraph once
    int Queue[MAXSIZE], front = 0, rear = 0, v;
    Queue[++rear] = start;  reach[start] = true;
    while ( front != rear )
    {
        v = Queue[++front];
        cout << ' ' << G.Vex[v]; // visit the vertex
        for ( int i = 0; i < G.vertexNum; ++i )
        {
            if ( G.Edges[v][i] && G.Edges[v][i] != INT_MAX  && !reach[i] )
            {
                Queue[++rear] = i;
                reach[i] = true;
            }
        }
    }
}

void dfsMGraph( MGraph &G, int start, bool reach[] )
{// depth-first search for MGraph once
    int Stack[MAXSIZE], top = -1, v;
    Stack[++top] = start; reach[start] = true;
    cout << ' ' << G.Vex[start];
    while ( top != -1 )
    {
        v = Stack[top];
        int i = 0; while ( i < G.vertexNum && (!G.Edges[v][i] || G.Edges[v][i] == INT_MAX || reach[i] ) ) ++i;
        if ( i == G.vertexNum ) --top;
        else
        {
            cout << ' ' << G.Vex[i];
            reach[i] = true;
            Stack[++top] = i;
        }
        /*
        for ( int i = G.vertexNum - 1; i >= 0; --i ) // Reverse traversal
        {
            if ( G.Edges[v][i] && G.Edges[v][i] != INT_MAX && !reach[i] )
            {
                Stack[++top] = i;
                reach[i] = true;
            }
        }
        */
    }
}

void bfsALGraph( ALGraph &G, int start, bool reach[] )
{// breadth-first search for ALGraph once
    int Queue[MAXSIZE], front = 0, rear = 0, v;
    ArcNode *p;
    
    reach[start] = true;
    Queue[++rear] = start; 
    while ( front != rear )
    {
        v = Queue[++front];
        cout << ' ' << G.aList[v].vex;
        for ( p = G.aList[v].firstArc; p; p = p->nextArc )
        {
            if ( !reach[p->adjvex] )
            {
                Queue[++rear] = p->adjvex;
                reach[p->adjvex] = true;
            }
        }
    }
}

void dfsALGraph( ALGraph &G, int start, bool reach[] )
{// depth-first search for ALGraph once
    int Stack[MAXSIZE], top = -1, v, w;
    ArcNode *p;

    reach[start] = true;
    Stack[++top] = start; 
    cout << ' ' << G.aList[start].vex;
    while ( top != -1 )
    {
        v = Stack[top];
        p = G.aList[v].firstArc; 
        while ( p && reach[p->adjvex] ) p = p->nextArc;
        if ( !p ) --top;
        else
        {
            w = p->adjvex;
            cout << ' ' << G.aList[w].vex;
            Stack[++top] = w;
            reach[w] = true;
        }
        /*
        for ( p = G.aList[v].firstArc; p; p = p->nextArc)
        {
            if ( !reach[p->adjvex] )
            {
                Stack[++top] = p->adjvex;
                reach[p->adjvex] = true;
            }
        }
        */
    }

}

void BFSMGraph( MGraph &G )
{// Non-recursive BFS Unconnected Mgraph
    bool reach[MAXSIZE] = { false };
    for ( int i = 0; i < G.vertexNum; ++i )
        if ( !reach[i] )
            bfsMGraph( G, i, reach );
}

void DFSMGraph( MGraph &G )
{// Non-recursive DFS Unconnected Mgraph
    bool reach[MAXSIZE] = { false };
    for ( int i = 0; i < G.vertexNum; ++i )
        if ( !reach[i] )
            dfsMGraph( G, i, reach );
}

void BFSALGraph( ALGraph &G )
{// Non-recursive BFS Unconnected ALgraph
    bool reach[MAXSIZE] = { false };
    for ( int i = 0; i < G.vertexNum; ++i )
        if ( !reach[i] )
            bfsALGraph( G, i, reach );
}

void DFSALGraph( ALGraph &G )
{// Non-recursive DFS Unconnected ALgraph
    bool reach[MAXSIZE] = { false };
    for ( int i = 0; i < G.vertexNum; ++i )
        if ( !reach[i] )
            dfsALGraph( G, i, reach );
}

void r_bfsMGraph( MGraph &G , int v, bool reach[] )
{// Recursive Breadth-first search for MGraph
    bool flag = 0; 
    if ( !reach[v] )
    {
        reach[v] = true;
        cout << ' ' << G.Vex[v];
    }
    for ( int i = 0; i < G.vertexNum; ++i )
        if ( G.Edges[v][i] && G.Edges[v][i] != INT_MAX && !reach[i] )
        {
            reach[i] = true;
            cout << ' ' << G.Vex[i];
            flag = 1;
        }
    if ( flag )
        for ( int i = 0; i < G.vertexNum; ++i )
            if ( G.Edges[v][i] && G.Edges[v][i] != INT_MAX )
                r_bfsMGraph( G, i , reach);
}

void r_dfsMGraph( MGraph &G , int v, bool reach[] )
{// Recursive Depth-first search for MGraph
    cout << ' ' << G.Vex[v];
    reach[v] = true;
    for ( int i = 0; i < G.vertexNum; ++i )
        if ( G.Edges[v][i] && G.Edges[v][i] != INT_MAX && !reach[i] )
            r_dfsMGraph( G, i, reach );
}

void r_bfsALGraph( ALGraph &G, int v, bool reach[] )
{// Recursive Breadth-first search for ALGraph
    if ( !reach[v] )
    {
        reach[v] = true;
        cout << ' ' << G.aList[v].vex;
    }
    for ( ArcNode * p = G.aList[v].firstArc; p; p = p->nextArc )
    {
        int w = p->adjvex;
        if ( !reach[w] )
        {
            reach[w] = true;
            cout << ' ' << G.aList[w].vex;
        }
    }
    for ( ArcNode * p = G.aList[v].firstArc; p; p = p->nextArc )
        r_bfsALGraph( G, p->adjvex, reach );
    
}

void r_dfsALGraph( ALGraph &G, int v, bool reach[] )
{// Recursive Depth-first search for ALGraph
    reach[v] = true; 
    cout << ' ' << G.aList[v].vex;
    for ( ArcNode * p = G.aList[v].firstArc; p; p = p->nextArc )
    {
        int w = p->adjvex;
        if ( !reach[w] )
            r_dfsALGraph( G, w, reach );
    }
}

void rBFSMGraph( MGraph &G )
{// Recursive BFS Unconnected Mgraph
    bool reach[MAXSIZE] = { false };
    for ( int i = 0; i < G.vertexNum; ++i )
        if ( !reach[i] )
            r_bfsMGraph( G, i, reach );
}

void rDFSMGraph( MGraph &G )
{// Recursive DFS Unconnected Mgraph
    bool reach[MAXSIZE] = { false };
    for ( int i = 0; i < G.vertexNum; ++i )
        if ( !reach[i] )
            r_dfsMGraph( G, i, reach );
}

void rBFSALGraph( ALGraph &G )
{// Recursive BFS Unconnected ALgraph
    bool reach[MAXSIZE] = { false };
    for ( int i = 0; i < G.vertexNum; ++i )
        if ( !reach[i] )
            r_bfsALGraph( G, i, reach );
}

void rDFSALGraph( ALGraph &G )
{// Recursive DFS Unconnected ALgraph
    bool reach[MAXSIZE] = { false };
    for ( int i = 0; i < G.vertexNum; ++i )
        if ( !reach[i] )
            r_dfsALGraph( G, i, reach );
}

// ex7-1
int  retFarthestVex( ALGraph &G, int v )
{// use once BFS
    bool reach[MAXSIZE] = { false };
    int Queue[MAXSIZE], front = 0, rear = 0, w;
    reach[v] = true; Queue[++rear] = v;
    while ( rear != front )
    {
        w = Queue[++front];
        for ( ArcNode *p = G.aList[w].firstArc; p; p = p->nextArc )
        {
            int u = p->adjvex;
            if ( !reach[u] )
            {
                reach[u] = true;
                Queue[++rear] = u;
            }
        }
    }
    return w;
}

// ex7-2
void rdfs_7_2( ALGraph &G, int v, int &vNum, int &eNum, bool reach[] )
{
    reach[v] = true; ++vNum;
    for ( ArcNode * p = G.aList[v].firstArc; p; p = p->nextArc )
    {
        ++eNum;
        if ( !reach[p->adjvex] ) 
            rdfs_7_2( G, p->adjvex, vNum, eNum, reach );
    }
}

bool isTreeOfUnDiALGraph_R( ALGraph &G )
{
    bool reach[MAXSIZE] = { false };
    int vNum = 0, eNum = 0;
    rdfs_7_2( G, 0, vNum, eNum, reach );
    if ( G.vertexNum == vNum && G.vertexNum - 1 == eNum / 2 )
        return true;
    else return false;
}

bool isExitPath( ALGraph &G, int start, int end )
{// Non-Recursive BFS
    bool reach[MAXSIZE];
    int Queue[MAXSIZE], front = 0, rear = 0, v, w;
    Queue[++rear] = start;
    while ( front != rear )
    {
        v = Queue[++front];
        if ( G.aList[v].vex == G.aList[end].vex )
            return true;
        for ( ArcNode * p = G.aList[v].firstArc; p; p = p->nextArc )
        {
            w = p->adjvex;
            if ( !reach[w] )
            {
                reach[w] = true;
                Queue[++rear] = w;
            }
        }
    }
    return false;
}

void rdfs_1( ALGraph &G, int v, bool reach[] )
{
    reach[v] = true;
    for ( ArcNode * p = G.aList[v].firstArc; p; p = p->nextArc )
        if ( !reach[p->adjvex] )
            rdfs_1( G, p->adjvex, reach );
}

bool rIsExitPath( ALGraph &G, int u, int v)
{
    bool reach[MAXSIZE] = { false };
    rdfs_1( G, u, reach);
    if ( reach[v] ) return true;
    return false;
}

bool ExistLenKPath( ALGraph &G, int u, int v, int k )
{// exist a path that length = k from u to v in no-weight Graph
    static bool reach[MAXSIZE] = { false };
    reach[u] = true;
    if ( u == v && k == 0 )
        return true;
    else if ( k > 0 )
    {
        for ( ArcNode *p = G.aList[u].firstArc; p; p = p->nextArc )
        {
            if ( !reach[p->adjvex] 
                && ExistLenKPath( G, p->adjvex, v, k - 1 ) )
                return true;
            reach[p->adjvex] = false; // 
        }   
    }
    return false;
}

bool ExistPathDFS( ALGraph &G, int u, int v )
{
    static bool reach[MAXSIZE] = { false };
    reach[u] = true;
    if ( u == v )
        return true;
    for ( ArcNode *p = G.aList[u].firstArc; p; p = p->nextArc )
    {
        if ( !reach[p->adjvex] 
            && ExistPathDFS( G, p->adjvex, v ) )
            return true;
        reach[p->adjvex] = false; // 
    }   
    return false;
}

bool ExistPathBFS( ALGraph &G, int u, int v )
{
    bool reach[MAXSIZE] = {false};
    int Queue[MAXSIZE+1], front = 0, rear = 0;
    reach[u] = true; Queue[++rear] = u;
    while ( front != rear)
    {
        u = Queue[++front];
        if ( u == v ) // !!!
            return true;
        for ( ArcNode * p = G.aList[u].firstArc; p; p = p->nextArc )
        {
            if ( !reach[p->adjvex] )
            {
                reach[p->adjvex];
                Queue[++rear] = p->adjvex;
            }
        }
    }
    return false;
}

bool ExistPathBFS_( ALGraph &G, int u, int v )
{
        bool reach[MAXSIZE] = {false};
    int Queue[MAXSIZE+1], front = 0, rear = 0;
    reach[u] = true; Queue[++rear] = u;
    while ( front != rear)
    {
        u = Queue[++front];
        for ( ArcNode * p = G.aList[u].firstArc; p; p = p->nextArc )
        {
            if ( p->adjvex == v ) // !!!
                return true;
            if ( !reach[p->adjvex] )
            {
                reach[p->adjvex];
                Queue[++rear] = p->adjvex;
            }
        }
    }
    return false;
}

void printAllPath( ALGraph &G, int u, int v )
{
    static int path[MAXSIZE];
    static int reach[MAXSIZE] = {false}, top = -1;
    reach[u] = true; path[++top] = u;

    if ( u == v )
    {
        for( int i = 0; i <= top; ++i )
            cout << ' ' << path[i];
        cout << endl;
    }
    for ( ArcNode *p = G.aList[u].firstArc; p; p = p->nextArc )
        if ( !reach[p->adjvex] )
            printAllPath( G, p->adjvex, v );
    reach[u] = false; --top;
}

bool TopSort( ALGraph &G )
{
    int indegree[MAXSIZE] = { 0 };
    for ( int i = 0; i < G.vertexNum; ++i )
        for ( ArcNode *p = G.aList[i].firstArc; p; p = p->nextArc )
            ++indegree[p->adjvex];
    int Stack[MAXSIZE], top = -1;
    for ( int i = 0; i < G.vertexNum; ++i )
        if ( indegree[i] == 0 )
            Stack[++top] = i;

    int res[MAXSIZE], n = 0;
    while ( top != -1 )
    {
        int v = Stack[top--]; 
        res[n++] = v;
        for ( ArcNode * p = G.aList[v].firstArc; p; p = p->nextArc )
        {
            int w = p->adjvex;
            if ( !(--indegree[w]) )
                Stack[++top] = w; 
        }
    }
    if ( n == G.vertexNum )
    {
        for ( int i = 0; i < n; ++i )
            cout << ' ' << G.aList[ res[i] ].vex;
        cout << endl;
        return true;
    }
    return false;
}

int     countInDegreeDiALGraph( ALGraph &G, int v )
{
    int n = 0;
    ArcNode *p;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        for ( p = G.aList[i].firstArc; p; p = p->nextArc )
        {
            if ( p->adjvex == v )
                ++n;
        }
    }
    return n;
}

int     countOutDegreeDiALGraph( ALGraph &G, int v )
{
    int n = 0; 
    for ( ArcNode *p = G.aList[v].firstArc; p; p = p->nextArc )
    {
        ++n;
    }
    return n;
}

int     countDegreeUnDiALGraph( ALGraph &G, int v )
{
    int n = 0;
    for ( ArcNode *p = G.aList[v].firstArc; p; p = p->nextArc )
    {
        ++n;
    }
    return n;

}

bool JudgeLoop( ALGraph &G, int v )
{
    static bool reach[MAXSIZE] = { false };
    reach[v] = true;
    for ( ArcNode *p = G.aList[v].firstArc; p; p = p->nextArc )
    {
        if ( reach[p->adjvex] || JudgeLoop(G, p->adjvex) )
            return true;
        reach[p->adjvex] = false;
    }
    return false;
}

int PrimMST( MGraph &G, int start )
{// Prim MST algorithm 
    int lowcost[MAXSIZE], vset[MAXSIZE], v, sum = 0;
    int k, min;  v = start;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        lowcost[i] = G.Edges[start][i];
        vset[i] = 0;
    }
    vset[v] = 1;
    for ( int i = 0; i < G.vertexNum - 1; ++i )
    {
        min = INT_MAX;
        for ( int j = 0; j < G.vertexNum; ++j )
        {// find min weight edge
            if ( vset[j] == 0 && lowcost[j] < min )
            {
                min = lowcost[j];
                k = j;
            }
        }

        vset[k] = 1; // select edge
        v = k; // next vertex
        sum += min; // sum weight
        for ( int j = 0; j < G.vertexNum; ++j )
        {// reset lowcost
            if( vset[j] == 0 && G.Edges[v][j] < lowcost[j] )
                lowcost[j] = G.Edges[v][j];
        }
    }
    return sum;
}

void Sort_Kruskal( int Arr[][3], int n )
{
    for ( int i = n - 1; i > 0; --i )
        for ( int j = 0; j < i; ++j )
            if ( Arr[j][2] > Arr[j + 1][2] )
                swap( Arr[j], Arr[j + 1] );
}

int findClass(int Set[], int elem)
{
    while( elem != Set[elem] ) elem = Set[elem];
    return elem;
}

int KruskalMST( int Arr[][3], int n, int e )
{// Kruskal MST algorithm
    int Union[MAXSIZE];
    int Edges[MAXSIZE][3];
    int classA, classB, sum = 0;
    memcpy( Edges, Arr, sizeof(int) * e * 3);    
    for ( int i = 0; i < n; ++i )
        Union[i] = i; // n sets
    Sort_Kruskal( Edges, e );
    for ( int i = 0; i < e; ++i )
    {
        classA = findClass( Union, Edges[i][0] );
        classB = findClass( Union, Edges[i][1] );
        if ( classA != classB )
        {
            Union[ classA ] = classB;
            cout << i + 1 << ':' << Edges[i][2] << endl;
            sum += Edges[i][2];
        }
    }
    return sum;
}

void Dj_printAllPath( int path[], int elem )
{
    int Stack[MAXSIZE], top = -1;
    while ( path[elem] != -1 )
    {
        Stack[++top] = elem;
        elem = path[elem];
    }
    Stack[++top] = elem;
    while ( top != -1 )
        cout << ' ' << Stack[top--];
}

void Dijkstra( MGraph &G, int start )
{
    // initiation
    int set[MAXSIZE], dist[MAXSIZE], path[MAXSIZE], min, v = start;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        dist[i] = G.Edges[v][i];
        set[i] = 0;
        if ( G.Edges[v][i] != INT_MAX )
            path[i] = v;
        else path[i] = -1;
    }
    set[v] = 1;

    // key step
    for ( int i = 0; i < G.vertexNum - 1; ++i )
    {
        min = INT_MAX;
        for ( int j = 0; j < G.vertexNum; ++j )
            if ( set[j] == 0 && dist[j] < min )
            {
                min = dist[j];
                v = j;
            }
        set[v] = 1;
        for ( int j = 0; j < G.vertexNum; ++j )
            if ( set[j] == 0 && dist[v] + G.Edges[v][j] < dist[j] )
            {
                dist[j] = dist[v] + G.Edges[v][j];
                path[j] = v;
            }
    }
    // print all path
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        if ( i != start )
        {
            cout << ' ' << start << "->" << i << " :";
            Dj_printAllPath( path, i );
        }
        else continue;
        cout << endl;
    }
}

void Floyd( MGraph &G, int path[][MAXSIZE], int A[][MAXSIZE] )
{

}

void printMG( MGraph G )
{// print UnWeighted MGraph
    cout << '\t' << '~';
    for ( int i = 0; i < G.vertexNum; ++i ) cout << '\t' << G.Vex[i];
    cout << endl;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        cout << '\t' << G.Vex[i];
        for ( int j = 0; j < G.vertexNum; ++j )
        {
            cout << '\t' << G.Edges[i][j];
        }
        cout << endl;
    }
}

void printWiMG( MGraph G )
{// print Weighted MGraph
    cout << '\t' << '~';
    for ( int i = 0; i < G.vertexNum; ++i ) cout << '\t' << G.Vex[i];
    cout << endl;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        cout << '\t' << G.Vex[i];
        for ( int j = 0; j < G.vertexNum; ++j )
        {
            if ( G.Edges[i][j] != INT_MAX )
                cout << '\t' << G.Edges[i][j];
            else
                cout << '\t' << "oo";
        }
        cout << endl;
        }
}

void printALG( ALGraph G )
{// print UnWeighted ALGraph
    ArcNode *p;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        p = G.aList[i].firstArc;
        cout << G.aList[i].vex << "-->";
        while ( p )
        {
            cout << p->adjvex << "-->";
            p = p->nextArc;
        }
        cout << "NULL" << endl;
    }
}

void printWiALG( ALGraph G )
{// print Weighted ALGraph
    ArcNode *p;
    for ( int i = 0; i < G.vertexNum; ++i )
    {
        p = G.aList[i].firstArc;
        cout << G.aList[i].vex << "-->";
        while ( p )
        {
            cout << p->adjvex << '(' << p->weight << ')' << "-->";
            p = p->nextArc;
        }
        cout << "NULL" << endl;
    }
}